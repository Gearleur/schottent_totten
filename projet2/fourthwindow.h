#ifndef FOURTHWINDOW_H
#define FOURTHWINDOW_H

#include <QWidget>

namespace Ui {
class FourthWindow;
}

class FourthWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FourthWindow(QWidget *parent = nullptr);
    ~FourthWindow();

    void closeSecondWindow();

private slots:
    void on_Suivant_clicked();
    void on_Joueur1_TextChanged();
    void on_Joueur2_TextChanged();
    void on_Back_clicked();
    void clearWindow(QWidget *window);



private:
    Ui::FourthWindow *ui;
};

#endif // FOURTHWINDOW_H
