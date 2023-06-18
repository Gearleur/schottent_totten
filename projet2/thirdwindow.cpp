#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include "secondwindow.h"
#include "fifthwindow.h"

Thirdwindow::Thirdwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Thirdwindow)
{
    ui->setupUi(this);

    setWindowTitle("pseudo");

    // Définir l'image de fond
    QPixmap background("C:/Users/Elève/Documents/GI02/LO21/QT/Schotten_Totten/images/schotten-teaseur.jpg");
        background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    connect(ui->lineEdit_4, &QLineEdit::textChanged, this, &Thirdwindow::on_Joueur1_TextChanged);
    connect(ui->Suivant, &QPushButton::clicked, this, &Thirdwindow::on_Suivant_clicked);
    connect(ui->Back, &QPushButton::clicked, this, &Thirdwindow::on_Back_clicked);

}

Thirdwindow::~Thirdwindow()
{
    delete ui;
}


void Thirdwindow::on_Back_clicked()
{

    QApplication::quit();
}

void Thirdwindow::on_Suivant_clicked()
{

    clearWindow(this);

    FifthWindow *fifthWindow = new FifthWindow(this);
    fifthWindow->setAttribute(Qt::WA_DeleteOnClose, false); // Empêche la suppression de la deuxième fenêtre lors de la fermeture
    fifthWindow->show();
}

void Thirdwindow::on_Joueur1_TextChanged()
{

    QApplication::quit();
}


void Thirdwindow::clearWindow(QWidget *window)
{
    // Récupérer tous les widgets enfants de la fenêtre
    QList<QWidget *> widgets = window->findChildren<QWidget *>();

    // Supprimer les widgets un par un
    foreach (QWidget *widget, widgets) {
        widget->deleteLater();
    }
}
