#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLabel>
#include <QSlider>
#include <QPushButton>

#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>
#include <QGraphicsBlurEffect>

#include <QFileDialog>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QLabel* lbl = nullptr;
    QSlider* sld = nullptr;
    QPushButton* button = nullptr;

    QPixmap pix;
    QGraphicsBlurEffect blur;
    QGraphicsColorizeEffect color;

    int width = 0;
    int height = 0;


private slots:
    void on_sld_valueChanged(int value);
    void on_button_clicked();
};
#endif // MAINWINDOW_H
