/**
 * @file mainwindow.hh
 * @brief Header file for the MainWindow file
 * @author Kalle Salminen
 * @date 2025-04-30
 */

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QPushButton>
#include <QPixmap>
#include <QApplication>
#include <QGridLayout>
#include <QPainter>
#include <QLabel>
#include <vector>
#include <set>
#include "chess.hh"
#define BOARD_SIZE 8

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void square_click(int index); // Handles clicks on squares
    void restart_game_button();   // Restarts the game
    void quit_game_button();      // Quits the game

private:
    QWidget* central_widget_;           // Central widget for the main window
    QGridLayout* layout_;               // Grid layout for the board and widgets
    QLabel* info_label_;                // Label to show whose turn it is
    QPushButton* restart_button_;       // Restart button
    QPushButton* quit_button_;          // Quit button
    vector<QPushButton*> squares_; // Vector of square buttons (8x8 = 64)
    set<Coord> available_moves_;   // Available moves for the selected piece
    Coord coordinates_;                 // Selected piece coordinates
    Chess game_;                        // Game logic

    void ChessBoard();           // Creates the chessboard
    bool is_marked(Coord coord);        // Checks if a square is marked (selected)
    void update_board();                // Updates the board visuals
    QString get_piece_icon(Coord coord); // Gets the icon path for a piece
};

#endif // MAINWINDOW_HH
