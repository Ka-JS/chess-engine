/**
 * @file mainwindow.cc
 * @brief This is the code for the chess game window
 * @author Kalle Salminen
 * @date 2025-4-30
 *
 * This code makes the chess board window visually and functionally.
 * The chess logic is taken from other files and this just updates everything to make the game.
 */
#include "mainwindow.hh"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent)
{
    ChessBoard();
    game_.start_game();
    update_board();
}

/**
 * @brief Destructor
 */
MainWindow::~MainWindow()
{
}

/**
 * @brief When you click a square on the board
 * @param n the location of the clicked square.
 */
void MainWindow::square_click(int n)
{
    // If the game is over, do nothing
    if (game_.get_game_state() != IN_PROGRESS) {
        return;
    }

    int row = n/BOARD_SIZE;
    int col = n%BOARD_SIZE;
    Coord click = {row, col};
    auto piece = game_.get_board().get_piece_at(click);

    if (piece and piece->get_color() == game_.get_current_turn()) {
        coordinates_ = click;
        available_moves_ = piece->get_allowed_moves(game_.get_board());
        update_board();
    }else if (is_marked(click)){
        coordinates_ = NULL_COORD;
        available_moves_.clear();
        update_board();
    }
    // If you click a place you can move to, move there
    else if (available_moves_.count(click) >0) {
        piece = game_.get_board().get_piece_at(coordinates_);
        game_.make_move(piece, click);
        coordinates_ = NULL_COORD;
        available_moves_.clear();
        update_board();
        // Show whose turn it is or who won
        if (game_.get_game_state() == IN_PROGRESS) {
            if (game_.get_current_turn() == WHITE) {
                info_label_->setText("White's turn");
            } else {
                info_label_->setText("Black's turn");
            }
        } else {
            if (game_.get_game_state() == WHITE_WIN) {
                info_label_->setText("White won!");
            } else {
                info_label_->setText("Black won!");
            }
        }
    }
}

/**
 * @brief Make the chessboard and buttons.
 */
void MainWindow::ChessBoard() {
    central_widget_ = new QWidget(this);
    QVBoxLayout* main_layout = new QVBoxLayout(central_widget_);
    info_label_ = new QLabel("White's turn", this);
    QWidget* chessboard_widget = new QWidget(this);
    QGridLayout* board_layout = new QGridLayout(chessboard_widget);
    board_layout->setSpacing(0);
    board_layout->setContentsMargins(0, 0, 0, 0);
    chessboard_widget->setFixedSize(480, 480);

    squares_ = vector<QPushButton*>(64, nullptr);
    coordinates_ = NULL_COORD;

    setCentralWidget(central_widget_);
    info_label_->setAlignment(Qt::AlignCenter);

    // Create squares
    for (int row =0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            int index = row * BOARD_SIZE +col;
            squares_[index] = new QPushButton(this);
            squares_[index]->setFixedSize(60, 60);
            squares_[index]->setStyleSheet("QPushButton { margin: 0; padding: 0; }");
            board_layout->addWidget(squares_[index], row, col);
            connect(squares_[index], &QPushButton::clicked, this, [this, index]() { square_click(index); });
        }
    }

    // Layout for buttons
    QHBoxLayout* button_layout = new QHBoxLayout();
    restart_button_ = new QPushButton("Restart", this);
    quit_button_ = new QPushButton("Quit", this);
    button_layout->addWidget(restart_button_);
    button_layout->addWidget(quit_button_);

    main_layout->addWidget(info_label_);
    main_layout->addWidget(chessboard_widget);
    main_layout->addLayout(button_layout);

    connect(restart_button_, &QPushButton::clicked, this, &MainWindow::restart_game_button);
    connect(quit_button_, &QPushButton::clicked, this, &MainWindow::quit_game_button);
}

/**
 * @brief Update the board by showing pieces and highlighting available moves
 */
void MainWindow::update_board() {
    for (int row =0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            int index = row * BOARD_SIZE +col;
            Coord coord = {row, col};
            QString icon_path = get_piece_icon(coord);
            if (icon_path.isEmpty()) continue;
            QPixmap pixmap(icon_path);
            if (pixmap.isNull()) continue;
            pixmap = pixmap.scaled(60, 60);

            // Highlight possible moves (with QPainter (outline didnt work))
            if (available_moves_.count(coord) > 0) {
                QPainter painter(&pixmap);
                painter.setOpacity(0.5);
                painter.setBrush(QColor(255, 0, 0));
                painter.setPen(Qt::NoPen);
                painter.drawRect(0, 0, 60, 60);
                painter.end();
            }

            squares_[index]->setIcon(QIcon(pixmap));
            squares_[index]->setIconSize(QSize(60, 60));
            squares_[index]->setFlat(true);
            squares_[index]->setStyleSheet("QPushButton { margin: 0; padding: 0; }");
        }
    }
}

/**
 * @brief Check if a square is picked
 */
bool MainWindow::is_marked(Coord coord) {
    if (coordinates_ == NULL_COORD) {
        return false;
    }
    if (coordinates_.row == coord.row and coordinates_.col == coord.col) {
        return true;
    }
    return false;
}

/**
 * @brief Get the icon path for a piece at a given square
 * @param coord Coordinates of the square
 * @return Path to the piece icon
 */
QString MainWindow::get_piece_icon(Coord coord) {
    auto piece = game_.get_board().get_piece_at(coord);
    QString square_color;
    if ((coord.row + coord.col) % 2 ==0) {
        square_color = "wt";
    } else {
        square_color = "bl";
    }
    if (!piece) {
        return QString(":pieces/empty-%1.png").arg(square_color);
    }
    QString piece_color;
    if (piece->get_color() == WHITE) {
        piece_color = "wt";
    } else {
        piece_color = "bl";
    }
    QString piece_name = QString::fromStdString(piece->get_name());
    return QString(":pieces/%1-%2-on-%3.png").arg(piece_color).arg(piece_name).arg(square_color);
}

/**
 * @brief Restart button
 */
void MainWindow::restart_game_button() {
    game_.start_game(WHITE);
    coordinates_ = NULL_COORD;
    available_moves_.clear();
    info_label_->setText("White's turn");
    update_board();
}

/**
 * @brief Quit button
 */
void MainWindow::quit_game_button() {
    QApplication::quit();
}

