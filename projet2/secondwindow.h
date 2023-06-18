#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include "ui_secondwindow.h"
#include "mainwindow.h"
#include <QMainWindow>
#include <QDialog>

#include "thirdwindow.h"

namespace Ui {
class SecondWindow;
}


class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

    void closeMainWindow();

private slots:
    void on_IAButton_clicked();
    void on_joueurButton_clicked();
    void on_Back_clicked();
    void clearWindow(QWidget *window);

private:
    Ui::SecondWindow *ui;
    Thirdwindow *thirdwindow;
};

#endif // SECONDWINDOW_H
