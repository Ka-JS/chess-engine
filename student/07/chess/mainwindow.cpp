#include "mainwindow.hh"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent)
{
    ChessBoard();
    update_board();
}

MainWindow::~MainWindow()
{
}

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

    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            int index = row * BOARD_SIZE + col;
            squares_[index] = new QPushButton(this);
            squares_[index]->setFixedSize(60, 60);
            squares_[index]->setStyleSheet("QPushButton { margin: 0; padding: 0; }");
            board_layout->addWidget(squares_[index], row, col);
        }
    }

    main_layout->addWidget(info_label_);
    main_layout->addWidget(chessboard_widget);
}

void MainWindow::update_board() {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            int index = row * BOARD_SIZE + col;
            Coord coord = {row, col};
            QString icon_path = get_piece_icon(coord);
            if (icon_path.isEmpty()) continue;
            QPixmap pixmap(icon_path);
            if (pixmap.isNull()) continue;
            pixmap = pixmap.scaled(60, 60);

            squares_[index]->setIcon(QIcon(pixmap));
            squares_[index]->setIconSize(QSize(60, 60));
            squares_[index]->setFlat(true);
            squares_[index]->setStyleSheet("QPushButton { margin: 0; padding: 0; }");
        }
    }
}

QString MainWindow::get_piece_icon(Coord coord) {
    auto piece = game_.get_board().get_piece_at(coord);
    QString square_color;
    if ((coord.row + coord.col) % 2 == 0) {
        square_color = "wt";
    } else {
        square_color = "bl";
    }
    if (!piece) {
        return QString(":pieces/empty-%1.png").arg(square_color);
    }
    QString piece_color = (piece->get_color() == WHITE) ? "wt" : "bl";
    QString piece_name = QString::fromStdString(piece->get_name());
    return QString(":pieces/%1-%2-on-%3.png").arg(piece_color).arg(piece_name).arg(square_color);
}
