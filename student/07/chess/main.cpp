/**
 * @file main.cpp
 * @brief This is the main file that starts the chess game
 * @author Kalle Salminen 152225746
 * @date 2025-4-27
 *
 * This program is a simple two player chess game made with Qt.
 * The chess logic like piece movement and allowed moves is already implemented in other classes.
 * This project adds a graphical user interface where players can play using the mouse.
 * The board shows correct icons and highlights possible moves.
 * There is also info text that shows whose turn it is and who wins.
 * Players can restart the game or quit the program with buttons.
 */

#include "mainwindow.hh"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
