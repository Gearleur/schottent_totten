#include "boardwindow.h"
#include "ui_boardwindow.h"
#include "secondwindow.h"

BoardWindow::BoardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoardWindow)
{
    ui->setupUi(this);
}

BoardWindow::~BoardWindow()
{
    delete ui;
}


void BoardWindow::closeMainWindow()
{
    SecondWindow* secondWindow = qobject_cast<SecondWindow*>(parent());
    if (secondWindow) {
        secondWindow->show();
    }

    close(); // Ferme la deuxième fenêtre
}


void BoardWindow::on_Board_1_clicked()
{

}

void BoardWindow::on_Board_2_clicked()
{

}

void BoardWindow::on_Board_3_clicked()
{

}

void BoardWindow::on_Board_4_clicked()
{

}

void BoardWindow::on_Board_5_clicked()
{

}

void BoardWindow::on_Board_6_clicked()
{

}

void BoardWindow::on_Board_7_clicked()
{

}
