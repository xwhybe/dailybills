#include "showonedata.h"
#include "ui_showonedata.h"
#include "data.h"
#include<iostream>

showonedata::showonedata(QListWidgetItem* pitem,QWidget *parent,bill_one* bill_to_show)
    : QDialog(parent)
    , ui(new Ui::showonedata)
    , item(pitem)
    , dod(new detail_of_data(this,bill_to_show))
{
    ui->setupUi(this);
    this->bill_to_show=bill_to_show;
    if(this->bill_to_show->isincome){
        switch(this->bill_to_show->label){
        case 0:ui->type_label->setText(QString("彩票"));break;
        case 1:ui->type_label->setText(QString("工资"));break;
        case 2:ui->type_label->setText(QString("兼职"));break;
        case 3:ui->type_label->setText(QString("借入"));break;
        case 4:ui->type_label->setText(QString("奖金"));break;
        case 5:ui->type_label->setText(QString("补贴"));break;
        case 6:ui->type_label->setText(QString("其他"));break;
        }
        ui->money_label->setText(QString("+")+QString("%1").arg(QString::number(this->bill_to_show->money, 'f', 2)));
    }else{
        switch(this->bill_to_show->label){
        case 0:ui->type_label->setText(QString("购物"));break;
        case 1:ui->type_label->setText(QString("餐饮"));break;
        case 2:ui->type_label->setText(QString("出行"));break;
        case 3:ui->type_label->setText(QString("娱乐"));break;
        case 4:ui->type_label->setText(QString("医疗"));break;
        case 5:ui->type_label->setText(QString("教育"));break;
        case 6:ui->type_label->setText(QString("其他"));break;
        }
        ui->money_label->setText(QString("-")+QString("%1").arg(QString::number(this->bill_to_show->money, 'f', 2)));
    }
}

showonedata::~showonedata()
{
    delete ui;
}

void showonedata::on_detail_pushButton_clicked()
{
    dod->exec();
    if(this->bill_to_show->money==-1){
        emit emit_del(item);
        int rank=this->bill_to_show->bill_data.rank;
        bool type=this->bill_to_show->isincome;
        for(auto i=bill_all.begin();i!=bill_all.end();i++){
            if(i->bill_data.rank==rank&&i->isincome==type){
                std::cout<<i->name<<" "<<i->money<<" "<<i->bill_data.rank<<std::endl;
                bill_all.erase(i);
                break;
            }
        }
    }else{
        if(this->bill_to_show->isincome){
            ui->money_label->setText(QString("+")+QString("%1").arg(QString::number(this->bill_to_show->money,'f',2)));
        }else{
            ui->money_label->setText(QString("-")+QString("%1").arg(QString::number(this->bill_to_show->money, 'f', 2)));
        }
    }
}

