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
    void square_click(int index);
    void restart_game_button();
    void quit_game_button();

private:
    QWidget* central_widget_;           // Main window widget
    QGridLayout* layout_;               // Board layout
    QLabel* info_label_;                // Turn info label
    QPushButton* restart_button_;       // Restart button
    QPushButton* quit_button_;          // Quit button
    vector<QPushButton*> squares_;      // Square buttons
    set<Coord> available_moves_;        // Selected piece moves
    Coord coordinates_;                 // Selected piece position
    Chess game_;                        // Game logic

    void ChessBoard();                  // Set up the chessboard
    bool is_marked(Coord coord);        // Check if a square is selected
    void update_board();                // Refresh the board
    QString get_piece_icon(Coord coord);// Get piece icon path

};

#endif // MAINWINDOW_HH
