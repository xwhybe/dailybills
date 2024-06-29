#ifndef SHOWONEDATA_H
#define SHOWONEDATA_H

#include <QDialog>
#include <data.h>
#include<QWidget>
#include<QListWidgetItem>
#include<detail_of_data.h>

namespace Ui {
class showonedata;
}

class showonedata : public QDialog
{
    Q_OBJECT

public:
    explicit showonedata(QListWidgetItem* pitem, QWidget *parent = nullptr, bill_one* bill_to_show=nullptr);
    ~showonedata();

signals:
    void emit_del(QListWidgetItem* pitem);

private slots:
    void on_detail_pushButton_clicked();

private:
    Ui::showonedata *ui;
    bill_one* bill_to_show;
    QListWidgetItem* item;
    detail_of_data* dod;
};

#endif // SHOWONEDATA_H
