#include "pseudojoueur.h"
#include "ui_pseudojoueur.h"

#include "mainwindow.h"
#include "secondwindow.h"
/*
Pseudojoueur::Pseudojoueur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Pseudojoueur)
{
    ui->setupUi(this);

    QPixmap background("C:/Users/Elève/Documents/GI02/LO21/QT/Schotten_Totten/images/schotten-teaseur.jpg");
        background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    connect(ui->suivant, &QPushButton::clicked, this, &Pseudojoueur::on_suivant_clicked);
    connect(ui->Back, &QPushButton::clicked, this, &Pseudojoueur::on_Back_clicked);

}

Pseudojoueur::~Pseudojoueur()
{
    delete ui;
}



void Pseudojoueur::closeSecondWindow()
{
    SecondWindow* secondwindow = qobject_cast<SecondWindow*>(parent());
    if (secondwindow) {
        secondwindow->show();
    }

    //close(); // Ferme la deuxième fenêtre
}



void Pseudojoueur::on_suivant_clicked()
{
    QApplication::quit();
}

void Pseudojoueur::on_Back_clicked()
{
    QApplication::quit();
}
*/
