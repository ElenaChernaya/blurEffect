#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create a QLabel object
    ui->lbl->setGeometry(20, 20, 500, 500);


    //set initial image to label
    pix = QPixmap(":/image/frog.png");
    ui->lbl->setPixmap(pix);


    // create a QSlider object and move it to fit the label's height + 30 px
    sld = new QSlider();
    ui->sld->setSliderPosition(0);
    ui->sld->resize(ui->lbl->width(), 30);
    ui->sld->move(20, ui->lbl->height() + 20);
    ui->sld->setMinimum(0);
    ui->sld->setMaximum(10);


    // create a QPushButton object (button)
    button = new QPushButton("OPEN");
    ui->button->resize(ui->lbl->width(), 30);
    ui->button->move(20, ui->lbl->height() + 60);


    //fill the button's borders with green
    QPalette pall;
    pall.setColor(ui->button->backgroundRole(), Qt::green);
    ui->button->setPalette(pall);
    ui->button->setAutoFillBackground(true);


    connect(button, &QPushButton::clicked, this, &MainWindow::on_button_clicked);
    connect(ui->sld, &QSlider::valueChanged, this, &MainWindow::on_sld_valueChanged);
}


//slot for opening file dialog
void MainWindow::on_button_clicked()
{
    QString filePath;

    filePath = QFileDialog::getOpenFileName(nullptr, "Open Images",
        ":/image/", "images (*.png *.jpg);;");
    pix = QPixmap(filePath);

    width = ui->lbl->width();
    height = ui->lbl->height();

    ui->lbl->setPixmap(pix.scaled(width, height, Qt::KeepAspectRatio));
    ui->sld->setValue(0);
}


void MainWindow::on_sld_valueChanged(int value)
{
    blur.setBlurRadius(value);
    ui->lbl->setGraphicsEffect(&blur);
}


MainWindow::~MainWindow()
{
    delete ui;
}

