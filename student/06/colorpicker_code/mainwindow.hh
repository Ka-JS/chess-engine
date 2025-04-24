#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QSlider>
#include <QSpinBox>
#include <QWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateRedValue(int value);
    void updateGreenValue(int value);
    void updateBlueValue(int value);
    void updateColorPreview();

private:
    QSlider *redSlider_;
    QSlider *greenSlider_;
    QSlider *blueSlider_;
    QSpinBox *redSpinBox_;
    QSpinBox *greenSpinBox_;
    QSpinBox *blueSpinBox_;
    QWidget *colorPreview_;
};

#endif // MAINWINDOW_HH
