#include "shoplist.h"
#include "ui_shoplist.h"
#include<QMessageBox>

ShopList::ShopList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopList)
{
    ui->setupUi(this);

    ui->cmb_R2F2->setVisible(false);
    ui->cmb_R3F1->setVisible(false);
    ui->cmb_R3F2->setVisible(false);
    ui->cmb_R3F3->setVisible(false);
    ui->cmb_WM->setVisible(false);
}

ShopList::~ShopList()
{
    delete ui;
}


void ShopList::on_btn_del_clicked()   //删除按钮
{
    if(ui->cmb_position->currentIndex() == 0){
    ui->cmb_R2F1->removeItem(ui->cmb_R2F1->currentIndex());
    }else if(ui->cmb_position->currentIndex() == 1){
    ui->cmb_R2F2->removeItem(ui->cmb_R2F2->currentIndex());
    }else if(ui->cmb_position->currentIndex() == 2){
    ui->cmb_R3F1->removeItem(ui->cmb_R3F1->currentIndex());
    }else if(ui->cmb_position->currentIndex() == 3){
    ui->cmb_R3F2->removeItem(ui->cmb_R3F2->currentIndex());
    }else if(ui->cmb_position->currentIndex() == 4){
    ui->cmb_R3F3->removeItem(ui->cmb_R3F3->currentIndex());
    }else if(ui->cmb_position->currentIndex() == 5){
    ui->cmb_WM->removeItem(ui->cmb_WM->currentIndex());
    }
}

/*----选择要编辑的店铺地点----*/
void ShopList::on_cmb_position_currentIndexChanged(int index)
{
    if(ui->cmb_position->currentIndex() == 0){
        ui->cmb_R2F1->setVisible(true);
        ui->cmb_R2F2->setVisible(false);
        ui->cmb_R3F1->setVisible(false);
        ui->cmb_R3F2->setVisible(false);
        ui->cmb_R3F3->setVisible(false);
        ui->cmb_WM->setVisible(false);
    }else if(ui->cmb_position->currentIndex() == 1){
        ui->cmb_R2F1->setVisible(false);
        ui->cmb_R2F2->setVisible(true);
        ui->cmb_R3F1->setVisible(false);
        ui->cmb_R3F2->setVisible(false);
        ui->cmb_R3F3->setVisible(false);
        ui->cmb_WM->setVisible(false);
    }else if(ui->cmb_position->currentIndex() == 2){
        ui->cmb_R2F1->setVisible(false);
        ui->cmb_R2F2->setVisible(false);
        ui->cmb_R3F1->setVisible(true);
        ui->cmb_R3F2->setVisible(false);
        ui->cmb_R3F3->setVisible(false);
        ui->cmb_WM->setVisible(false);
    }else if(ui->cmb_position->currentIndex() == 3){
        ui->cmb_R2F1->setVisible(false);
        ui->cmb_R2F2->setVisible(false);
        ui->cmb_R3F1->setVisible(false);
        ui->cmb_R3F2->setVisible(true);
        ui->cmb_R3F3->setVisible(false);
        ui->cmb_WM->setVisible(false);
    }else if(ui->cmb_position->currentIndex() == 4){
        ui->cmb_R2F1->setVisible(false);
        ui->cmb_R2F2->setVisible(false);
        ui->cmb_R3F1->setVisible(false);
        ui->cmb_R3F2->setVisible(false);
        ui->cmb_R3F3->setVisible(true);
        ui->cmb_WM->setVisible(false);
    }else if(ui->cmb_position->currentIndex() == 5){
        ui->cmb_R2F1->setVisible(false);
        ui->cmb_R2F2->setVisible(false);
        ui->cmb_R3F1->setVisible(false);
        ui->cmb_R3F2->setVisible(false);
        ui->cmb_R3F3->setVisible(false);
        ui->cmb_WM->setVisible(true);
    }
}


void ShopList::on_btn_AddI_released()    //添加按钮
{
    QString Item = ui->lineEdit_AddI->text();
    if (Item == "")
    {
        QMessageBox::warning(this,"?","无中生店？");
    }
    else if(ui->cmb_position->currentIndex() == 0){
        Item += "(二餐一楼)";
        ui->cmb_R2F1->addItem(Item);
        ui->lineEdit_AddI->setText("");
        QMessageBox::about(this,"成功","添加成功");
    }else if(ui->cmb_position->currentIndex() == 1){
        Item += "(二餐二楼)";
        ui->cmb_R2F2->addItem(Item);
        ui->lineEdit_AddI->setText("");
        QMessageBox::about(this,"成功","添加成功");
    }else if(ui->cmb_position->currentIndex() == 2){
        Item += "(三餐一楼)";
        ui->cmb_R3F1->addItem(Item);
        ui->lineEdit_AddI->setText("");
        QMessageBox::about(this,"成功","添加成功");
    }else if(ui->cmb_position->currentIndex() == 3){
        Item += "(三餐二楼)";
        ui->cmb_R3F2->addItem(Item);
        ui->lineEdit_AddI->setText("");
        QMessageBox::about(this,"成功","添加成功");
    }else if(ui->cmb_position->currentIndex() == 4){
        Item += "(三餐三楼)";
        ui->cmb_R3F3->addItem(Item);
        ui->lineEdit_AddI->setText("");
        QMessageBox::about(this,"成功","添加成功");
    }else if(ui->cmb_position->currentIndex() == 5){
        Item += "(外卖)";
        ui->cmb_WM->addItem(Item);
        ui->lineEdit_AddI->setText("");
        QMessageBox::about(this,"成功","添加成功");
    }
}

