#include "fifthwindow.h"
#include "ui_fifthwindow.h"

#include "boardwindow.h"

FifthWindow::FifthWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FifthWindow)
{
    ui->setupUi(this);
}

FifthWindow::~FifthWindow()
{
    delete ui;
}



void FifthWindow::on_Back_clicked()
{

    QApplication::quit();
}

void FifthWindow::on_classique_1_clicked()
{
    close();

    BoardWindow *boardWindow = new BoardWindow(this);
    boardWindow->setAttribute(Qt::WA_DeleteOnClose, false); // Empêche la suppression de la deuxième fenêtre lors de la fermeture
    boardWindow->show();



}

void FifthWindow::on_classique_2_clicked()
{
    close();

    BoardWindow *boardWindow = new BoardWindow(this);
    boardWindow->setAttribute(Qt::WA_DeleteOnClose, false); // Empêche la suppression de la deuxième fenêtre lors de la fermeture
    boardWindow->show();

}


void FifthWindow::on_tactique_1_clicked()
{
    clearWindow(this);

    BoardWindow *boardWindow = new BoardWindow(this);
    boardWindow->setAttribute(Qt::WA_DeleteOnClose, false); // Empêche la suppression de la deuxième fenêtre lors de la fermeture
    boardWindow->show();

}

void FifthWindow::on_tactique_2_clicked()
{
    clearWindow(this);

    BoardWindow *boardWindow = new BoardWindow(this);
    boardWindow->setAttribute(Qt::WA_DeleteOnClose, false); // Empêche la suppression de la deuxième fenêtre lors de la fermeture
    boardWindow->show();

}




void FifthWindow::clearWindow(QWidget *window)
{
    // Récupérer tous les widgets enfants de la fenêtre
    QList<QWidget *> widgets = window->findChildren<QWidget *>();

    // Supprimer les widgets un par un
    foreach (QWidget *widget, widgets) {
        widget->deleteLater();
    }
}
