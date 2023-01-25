#ifndef SHOPLIST_H
#define SHOPLIST_H

#include <QWidget>

namespace Ui {
class ShopList;
}

class ShopList : public QWidget
{
    Q_OBJECT

public:
    explicit ShopList(QWidget *parent = nullptr);
    ~ShopList();

public:
    Ui::ShopList *ui;
private slots:
    void on_btn_del_clicked();
    void on_cmb_position_currentIndexChanged(int index);
    void on_btn_AddI_released();
};

#endif // SHOPLIST_H
