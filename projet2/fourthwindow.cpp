#include "fourthwindow.h"
#include "ui_fourthwindow.h"

#include "secondwindow.h"
#include "fifthwindow.h"

FourthWindow::FourthWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FourthWindow)
{
    ui->setupUi(this);

    setWindowTitle("pseudo");

    // Définir l'image de fond
    QPixmap background("C:/Users/Elève/Documents/GI02/LO21/QT/Schotten_Totten/images/schotten-teaseur.jpg");
        background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    connect(ui->Joueur1, &QLineEdit::textChanged, this, &FourthWindow::on_Joueur1_TextChanged);
    connect(ui->Joueur2, &QLineEdit::textChanged, this, &FourthWindow::on_Joueur2_TextChanged);
    connect(ui->Suivant, &QPushButton::clicked, this, &FourthWindow::on_Suivant_clicked);
    connect(ui->Back, &QPushButton::clicked, this, &FourthWindow::on_Back_clicked);

}

FourthWindow::~FourthWindow()
{
    delete ui;
}


void FourthWindow::on_Back_clicked()
{

    QApplication::quit();
}

void FourthWindow::on_Suivant_clicked()
{
    clearWindow(this);

    FifthWindow *fifthWindow = new FifthWindow(this);
    fifthWindow->setAttribute(Qt::WA_DeleteOnClose, false); // Empêche la suppression de la deuxième fenêtre lors de la fermeture
    fifthWindow->show();

}

void FourthWindow::on_Joueur1_TextChanged()
{

    //QApplication::quit();
}

void FourthWindow::on_Joueur2_TextChanged()
{

    //QApplication::quit();
}


void FourthWindow::clearWindow(QWidget *window)
{
    // Récupérer tous les widgets enfants de la fenêtre
    QList<QWidget *> widgets = window->findChildren<QWidget *>();

    // Supprimer les widgets un par un
    foreach (QWidget *widget, widgets) {
        widget->deleteLater();
    }
}
