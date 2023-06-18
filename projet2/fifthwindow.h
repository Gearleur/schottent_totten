#ifndef FIFTHWINDOW_H
#define FIFTHWINDOW_H

#include <QWidget>

namespace Ui {
class FifthWindow;
}

class FifthWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FifthWindow(QWidget *parent = nullptr);
    ~FifthWindow();

private slots:
    void on_classique_1_clicked();
    void on_classique_2_clicked();
    void on_tactique_1_clicked();
    void on_tactique_2_clicked();

    void on_Back_clicked();
    void clearWindow(QWidget *window);

private:
    Ui::FifthWindow *ui;
};

#endif // FIFTHWINDOW_H
