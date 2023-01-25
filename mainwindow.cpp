#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shoplist.h"
#include "ui_shoplist.h"
#include <time.h>
#include<string.h>
#include<cstring>
#include<QMessageBox>

int MainWindow::SIndex;
int MainWindow::R[6];
int MainWindow::Index;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

/*-----------------------隐藏并占位外卖相关控件-------------------------------*/

}

MainWindow::~MainWindow()
{
    delete ui;
}




/*----------------------地点选择判断---------------------*/
void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
      ui->checkBox_2_1->setEnabled(true);
      ui->checkBox_2_2->setEnabled(true);

    }
    if(arg1 == 0)
    {
      ui->checkBox_2_1->setEnabled(false);
      ui->checkBox_2_2->setEnabled(false);
      ui->checkBox_2_1->setChecked(false);
      ui->checkBox_2_2->setChecked(false);
    }
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
      ui->checkBox_3_1->setEnabled(true);
      ui->checkBox_3_2->setEnabled(true);
      ui->checkBox_3_3->setEnabled(true);
    }
    if(arg1 == 0)
    {
      ui->checkBox_3_1->setEnabled(false);
      ui->checkBox_3_2->setEnabled(false);
      ui->checkBox_3_3->setEnabled(false);
      ui->checkBox_3_1->setChecked(false);
      ui->checkBox_3_2->setChecked(false);
      ui->checkBox_3_3->setChecked(false);
    }
}

void MainWindow::on_btn_ItemsV_clicked()
{
    shoplist->show();
}

/*------------------------随机按钮-----------------------*/
void MainWindow::on_btn_start_clicked()
{
    int RIndex = 0;

    /*判断是否要去该地点就餐*/
    if(ui->checkBox_2_1->isChecked())
    {
        RIndex ++;
        R[RIndex]= {1};
    }
    if(ui->checkBox_2_2->isChecked())
    {
        RIndex ++;
        R[RIndex]= {2};
    }
    if(ui->checkBox_3_1->isChecked())
    {
        RIndex ++;
        R[RIndex]= {3};
    }
    if(ui->checkBox_3_2->isChecked())
    {
        RIndex ++;
        R[RIndex]= {4};
    }
    if(ui->checkBox_3_3->isChecked())
    {
        RIndex ++;
        R[RIndex]= {5};
    }
    if(ui->checkBox_WM->isChecked())
    {
        RIndex ++;
        R[RIndex]= {6};
    }


    if(RIndex == 0)
    {
         QMessageBox::warning(this,"喝西北风","搁哪吃呀小老弟");

    }

    /*随机选择前哪里就餐*/
    static unsigned int seq = 0;
    srand(time(0)+(seq++));
    int index = rand() % RIndex + 1;

    if(R[index] == 1){
        if(shoplist->ui->cmb_WM->count() == 0)
        {
          QMessageBox::warning(this,"?","先添加点二餐一楼的店铺吧");
        }
        else
        {
            int ItemsNum = shoplist->ui->cmb_R2F1->count();
            SIndex = rand() % ItemsNum;
            ui->lab_res->setText(shoplist->ui->cmb_R2F1->itemText(SIndex));
        }
    }else if(R[index] == 2){
        if(shoplist->ui->cmb_R2F2->count() == 0)
        {
          QMessageBox::warning(this,"?","先添加点二餐二楼的店铺吧");
        }
        else
        {
            int ItemsNum = shoplist->ui->cmb_R2F2->count();
            SIndex = rand() % ItemsNum;
            ui->lab_res->setText(shoplist->ui->cmb_R2F2->itemText(SIndex));
        }
    }else if(R[index] == 3){
        if(shoplist->ui->cmb_R3F1->count() == 0)
        {
          QMessageBox::warning(this,"?","先添加点三餐一楼的店铺吧");
        }
        else
        {
            int ItemsNum = shoplist->ui->cmb_R3F1->count();
            SIndex = rand() % ItemsNum;
            ui->lab_res->setText(shoplist->ui->cmb_R3F1->itemText(SIndex));
        }
    }else if(R[index] == 4){
        if(shoplist->ui->cmb_R3F2->count() == 0)
        {
          QMessageBox::warning(this,"?","先添加点三餐二楼的店铺吧");
        }
        else
        {
            int ItemsNum = shoplist->ui->cmb_R3F2->count();
            SIndex = rand() % ItemsNum;
            ui->lab_res->setText(shoplist->ui->cmb_R3F2->itemText(SIndex));
        }
    }else if(R[index] == 5){
        if(shoplist->ui->cmb_R3F3->count() == 0)
        {
          QMessageBox::warning(this,"?","先添加点三餐三楼的店铺吧");
        }
        else
        {
            int ItemsNum = shoplist->ui->cmb_R3F3->count();
            SIndex = rand() % ItemsNum;
            ui->lab_res->setText(shoplist->ui->cmb_R3F3->itemText(SIndex));
        }
    }else{
        if(shoplist->ui->cmb_WM->count() == 0)
        {
          QMessageBox::warning(this,"?","先添加点外卖店铺吧");
        }
        else
        {
            int ItemsNum = shoplist->ui->cmb_WM->count();
            SIndex = rand() % ItemsNum;
            ui->lab_res->setText(shoplist->ui->cmb_WM->itemText(SIndex));
        }
    }
}


