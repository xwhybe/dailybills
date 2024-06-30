#include"data.h"
#include "viewdata.h"
#include "ui_viewdata.h"
#include<QScrollArea>
#include<showonedata.h>
#include<QMessageBox>
#include<iostream>
#include<algorithm>

viewdata::viewdata(QWidget *parent)  /*const QDate &initialDate = QDate::currentDate(),*/
    : QDialog(parent)
    , ui(new Ui::viewdata)
{
    ui->setupUi(this);
    ui->view_dateEdit->setDate(QDate::currentDate());
    //ui->OK_pushButton->click();

}

viewdata::~viewdata()
{
    delete ui;
}

void viewdata::on_cancel_pushButton_clicked()
{
    close();
}


void viewdata::on_OK_pushButton_clicked()
{
    QDate date=ui->view_dateEdit->date();
    int year=date.year();
    int month=date.month();
    int day=date.day();
    bool flag=0;
    ui->view_listWidget->clear();
    std::sort(bill_all.begin(),bill_all.end());
    for(std::vector<bill_one>::iterator i=bill_all.begin();i!=bill_all.end();i++){
        if(i->bill_data.year==year&&i->bill_data.month==month&&i->bill_data.day==day){
            flag=1;
            QListWidgetItem* item=new QListWidgetItem();
            showonedata* tmp=new showonedata(item,this,&(*i));
            ui->view_listWidget->addItem(item);
            ui->view_listWidget->setItemWidget(item,tmp);
            ui->view_listWidget->setCurrentItem(item);
            connect(tmp,&showonedata::emit_del,this,[&](QListWidgetItem* item){
                ui->view_listWidget->removeItemWidget(item);
                delete item;
                item=nullptr;
            });
            /*connect(tmp,&showonedata::emit_del,this,[&](QListWidgetItem* item){
                QMessageBox::StandardButton btn=QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("是否删除？"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
                if(QMessageBox::No==btn){
                    return;
                }
                ui->view_listWidget->removeItemWidget(item);
                delete item;
                item=nullptr;
            });*/
        }else if(flag==1){
            break;
        }
    }
    if(flag==0){
        QString type=QString("当日无收支");
        QListWidgetItem* tmp=new QListWidgetItem(type);
        ui->view_listWidget->addItem(tmp);
    }
}


void viewdata::on_view_dateEdit_dateChanged(const QDate &date)
{
    //ui->OK_pushButton->click();
}


void viewdata::set_date_from_calendar(const QDate &initialDate = QDate::currentDate()){

    ui->view_dateEdit->setDate(initialDate);
    ui->OK_pushButton->click();
}

