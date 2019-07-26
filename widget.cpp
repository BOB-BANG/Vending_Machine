#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n){
    money += n;
    if (money < 0) money = 0;
    ui->lcdNumber->display(QString::number(money));
}
void Widget::on_PB10_clicked()
{
    changeMoney(10);
}
void Widget::on_PB50_clicked()
{
    changeMoney(50);
}
void Widget::on_PB500_clicked()
{
    changeMoney(500);
}
void Widget::on_PB100_clicked()
{
    changeMoney(100);
}
void Widget::on_PBCoffee_clicked()
{
    changeMoney(-100);
}
void Widget::on_PBMilk_clicked()
{
    changeMoney(-200);
}
void Widget::on_PBTea_clicked()
{
    changeMoney(-300);
}

int Widget::returnMoney(int n){
    int m;
    m = money / n;
    money = money % n;
    return m;
}

void Widget::on_PBReturn_clicked()
{
    QMessageBox msg;
    int a,b,c,d;
    a = returnMoney(500);
    b = returnMoney(100);
    c = returnMoney(50);
    d = returnMoney(10);
    msg.information(nullptr,"title",  QString("500 won %1 \n100 won %2 \n50 won %3 \n10 won %4")
                    .arg(a).arg(b).arg(c).arg(d));
    ui->lcdNumber->display(QString::number(money));
}
