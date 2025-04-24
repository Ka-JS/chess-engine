#include "mainwindow.hh"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(350, 200);
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Punainen
    redSlider_ = new QSlider(Qt::Horizontal, centralWidget);
    redSlider_->setObjectName("horizontalSliderRed");
    redSlider_->setRange(0, 255);
    redSlider_->setGeometry(10, 10, 150, 20);

    redSpinBox_ = new QSpinBox(centralWidget);
    redSpinBox_->setObjectName("spinBoxRed");
    redSpinBox_->setRange(0, 255);
    redSpinBox_->setGeometry(170, 10, 60, 25);

    // Vihreä
    greenSlider_ = new QSlider(Qt::Horizontal, centralWidget);
    greenSlider_->setObjectName("horizontalSliderGreen");
    greenSlider_->setRange(0, 255);
    greenSlider_->setGeometry(10, 50, 150, 20);

    greenSpinBox_ = new QSpinBox(centralWidget);
    greenSpinBox_->setObjectName("spinBoxGreen");
    greenSpinBox_->setRange(0, 255);
    greenSpinBox_->setGeometry(170, 50, 60, 25);

    // Sininen
    blueSlider_ = new QSlider(Qt::Horizontal, centralWidget);
    blueSlider_->setObjectName("horizontalSliderBlue");
    blueSlider_->setRange(0, 255);
    blueSlider_->setGeometry(10, 90, 150, 20);

    blueSpinBox_ = new QSpinBox(centralWidget);
    blueSpinBox_->setObjectName("spinBoxBlue");
    blueSpinBox_->setRange(0, 255);
    blueSpinBox_->setGeometry(170, 90, 60, 25);

    // Värin esikatselu
    colorPreview_ = new QWidget(centralWidget);
    colorPreview_->setGeometry(250, 10, 100, 100);
    colorPreview_->setStyleSheet("background-color: rgb(0, 0, 0)");

    // Signaali–slotti-kytkennät
    connect(redSpinBox_, &QSpinBox::valueChanged, this, &MainWindow::updateRedValue);
    connect(redSlider_, &QSlider::valueChanged, this, &MainWindow::updateRedValue);
    connect(greenSpinBox_, &QSpinBox::valueChanged, this, &MainWindow::updateGreenValue);
    connect(greenSlider_, &QSlider::valueChanged, this, &MainWindow::updateGreenValue);
    connect(blueSpinBox_, &QSpinBox::valueChanged, this, &MainWindow::updateBlueValue);
    connect(blueSlider_, &QSlider::valueChanged, this, &MainWindow::updateBlueValue);

    // Värien päivitys
    connect(redSpinBox_, &QSpinBox::valueChanged, this, &MainWindow::updateColorPreview);
    connect(greenSpinBox_, &QSpinBox::valueChanged, this, &MainWindow::updateColorPreview);
    connect(blueSpinBox_, &QSpinBox::valueChanged, this, &MainWindow::updateColorPreview);
}

MainWindow::~MainWindow()
{
}

void MainWindow::updateRedValue(int value)
{
    redSpinBox_->setValue(value);
    redSlider_->setValue(value);
}

void MainWindow::updateGreenValue(int value)
{
    greenSpinBox_->setValue(value);
    greenSlider_->setValue(value);
}

void MainWindow::updateBlueValue(int value)
{
    blueSpinBox_->setValue(value);
    blueSlider_->setValue(value);
}

void MainWindow::updateColorPreview()
{
    int red = redSpinBox_->value();
    int green = greenSpinBox_->value();
    int blue = blueSpinBox_->value();

    colorPreview_->setStyleSheet(QString("background-color: rgb(%1, %2, %3)").arg(red).arg(green).arg(blue));
}
