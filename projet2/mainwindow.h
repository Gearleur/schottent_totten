#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QApplication>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include <QPalette>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>


#include "secondwindow.h"

namespace Ui {
class MainWindow;

}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    //SecondWindow msecondwindow;
};



#endif // MAINWINDOW_H
