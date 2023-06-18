#ifndef BOARDWINDOW_H
#define BOARDWINDOW_H

#include <QMainWindow>

namespace Ui {
class BoardWindow;
}

class BoardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardWindow(QWidget *parent = nullptr);
    ~BoardWindow();

    void closeMainWindow();
    void on_Board_1_clicked();
    void on_Board_2_clicked();
    void on_Board_3_clicked();
    void on_Board_4_clicked();
    void on_Board_5_clicked();
    void on_Board_6_clicked();
    void on_Board_7_clicked();

private:
    Ui::BoardWindow *ui;
};

#endif // BOARDWINDOW_H
