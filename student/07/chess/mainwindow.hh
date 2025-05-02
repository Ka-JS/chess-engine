#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QPushButton>
#include <QPixmap>
#include <QGridLayout>
#include <QLabel>
#include <vector>
#include "chess.hh"

#define BOARD_SIZE 8

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    QWidget* central_widget_;
    QLabel* info_label_;
    std::vector<QPushButton*> squares_;
    Coord coordinates_;
    Chess game_;

    void ChessBoard();             // Builds the visual board
    void update_board();           // Displays pieces on board
    QString get_piece_icon(Coord); // Returns icon path
};

#endif // MAINWINDOW_HH
