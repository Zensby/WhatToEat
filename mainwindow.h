#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<shoplist.h>
#include<ui_shoplist.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static int SIndex;
    static int Index;
    static int R[6];

private slots:


    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_btn_ItemsV_clicked();

    void on_btn_start_clicked();


private:
    Ui::MainWindow *ui;

    ShopList *shoplist= new ShopList;

};

#endif // MAINWINDOW_H
