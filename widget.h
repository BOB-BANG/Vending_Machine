#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    int money=0;
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void changeMoney(int n);
    int returnMoney(int n);

private slots:
    void on_PB10_clicked();

    void on_PB50_clicked();

    void on_PB500_clicked();

    void on_PB100_clicked();

    void on_PBCoffee_clicked();

    void on_PBMilk_clicked();

    void on_PBTea_clicked();

    void on_PBReturn_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
