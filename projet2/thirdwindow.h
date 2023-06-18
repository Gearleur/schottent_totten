#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QWidget>

namespace Ui {
class Thirdwindow;
}

class Thirdwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Thirdwindow(QWidget *parent = nullptr);
    ~Thirdwindow();

    void closeSecondWindow();

private slots:
    void on_Suivant_clicked();
    void on_Joueur1_TextChanged();
    void on_Back_clicked();
    void clearWindow(QWidget *window);

private:
    Ui::Thirdwindow *ui;
};

#endif // THIRDWINDOW_H
