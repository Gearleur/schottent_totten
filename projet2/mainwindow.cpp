#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "secondwindow.h"
#include "ui_secondwindow.h"


#include <QMainWindow>
#include <QPushButton>
#include <QUiLoader>
#include <QFile>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui->setupUi(this);



    setWindowTitle("Schotten Totten");

    // Définir l'image de fond
    QPixmap background("C:/Users/Elève/Documents/GI02/LO21/QT/Schotten_Totten/images/schotten-teaseur.jpg");
        background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_pushButton_4_clicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);

    //msecondwindow.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_2_clicked()
{

    SecondWindow *secondWindow = new SecondWindow(this);
    secondWindow->setAttribute(Qt::WA_DeleteOnClose, false); // Empêche la suppression de la deuxième fenêtre lors de la fermeture
    secondWindow->show();

    hide(); // Cache la fenêtre principale


}




