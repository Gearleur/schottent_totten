#include "secondwindow.h"
#include "ui_secondwindow.h"
//#include "pseudojoueur.h"

#include "thirdwindow.h"
#include "fourthwindow.h"
#include <QLayout>

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow),
    thirdwindow(nullptr)
{
    ui->setupUi(this);

    setWindowTitle("Schotten Totten");

    // Définir l'image de fond
    QPixmap background("C:/Users/Elève/Documents/GI02/LO21/QT/Schotten_Totten/images/schotten-teaseur.jpg");
        background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    connect(ui->IAButton, &QPushButton::clicked, this, &SecondWindow::on_IAButton_clicked);
    connect(ui->joueurButton, &QPushButton::clicked, this, &SecondWindow::on_joueurButton_clicked);
    connect(ui->Back, &QPushButton::clicked, this, &SecondWindow::on_Back_clicked);


}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::closeMainWindow()
{
    QMainWindow* mainWindow = qobject_cast<QMainWindow*>(parent());
    if (mainWindow) {
        mainWindow->show();
    }

    close(); // Ferme la deuxième fenêtre
}

void SecondWindow::on_IAButton_clicked()
{
    //if (thirdwindow) {
    //    delete thirdwindow; // Supprimer l'instance précédente si elle existe
    //}

    clearWindow(this);

    Thirdwindow *thirdwindow = new Thirdwindow(this);
    thirdwindow->setAttribute(Qt::WA_DeleteOnClose, false); // Empêche la suppression de la deuxième fenêtre lors de la fermeture
    thirdwindow->show();


    //hide(); // Cache la fenêtre principale

}

void SecondWindow::on_joueurButton_clicked()
{
    clearWindow(this);

    FourthWindow *fourthWindow = new FourthWindow(this);
    fourthWindow->setAttribute(Qt::WA_DeleteOnClose, false); // Empêche la suppression de la deuxième fenêtre lors de la fermeture
    fourthWindow->show();
}

void SecondWindow::on_Back_clicked()
{
    QApplication::quit();
}


void SecondWindow::clearWindow(QWidget *window)
{
    // Récupérer tous les widgets enfants de la fenêtre
    QList<QWidget *> widgets = window->findChildren<QWidget *>();

    // Supprimer les widgets un par un
    foreach (QWidget *widget, widgets) {
        widget->deleteLater();
    }
}

