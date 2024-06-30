#include "detail_of_data.h"
#include "ui_detail_of_data.h"
#include<QMessageBox>
#include<iostream>

detail_of_data::detail_of_data(QWidget *parent, bill_one* bill_to_show)
    : QDialog(parent)
    , ui(new Ui::detail_of_data)
{
    ui->setupUi(this);
    this->bill_to_show=bill_to_show;
    ui->date_label->setText(QString::number(this->bill_to_show->bill_data.year)+QString("/")+QString::number(this->bill_to_show->bill_data.month)+QString("/")+QString::number(this->bill_to_show->bill_data.day));
    if(this->bill_to_show->isincome){
        switch(this->bill_to_show->label){
        case 0:ui->category_label->setText(QString("彩票"));break;
        case 1:ui->category_label->setText(QString("工资"));break;
        case 2:ui->category_label->setText(QString("兼职"));break;
        case 3:ui->category_label->setText(QString("借入"));break;
        case 4:ui->category_label->setText(QString("奖金"));break;
        case 5:ui->category_label->setText(QString("补贴"));break;
        case 6:ui->category_label->setText(QString("其他"));break;
        }
        ui->money_doubleSpinBox->setPrefix("+");
        ui->money_doubleSpinBox->setValue(this->bill_to_show->money);
    }else{
        switch(this->bill_to_show->label){
        case 0:ui->category_label->setText(QString("购物"));break;
        case 1:ui->category_label->setText(QString("餐饮"));break;
        case 2:ui->category_label->setText(QString("出行"));break;
        case 3:ui->category_label->setText(QString("娱乐"));break;
        case 4:ui->category_label->setText(QString("医疗"));break;
        case 5:ui->category_label->setText(QString("教育"));break;
        case 6:ui->category_label->setText(QString("其他"));break;
        }
        ui->money_doubleSpinBox->setPrefix("-");
        ui->money_doubleSpinBox->setValue(this->bill_to_show->money);
    }
    ui->remark_textEdit->setText(this->bill_to_show->remark);
}

detail_of_data::~detail_of_data()
{
    delete ui;
}

void detail_of_data::on_save_pushButton_clicked()
{
    if(this->bill_to_show->isincome){
        income_all-=this->bill_to_show->money;
    }else{
        outcome_all-=this->bill_to_show->money;
    }
    this->bill_to_show->money=ui->money_doubleSpinBox->value();
    this->bill_to_show->remark=ui->remark_textEdit->toPlainText();
    if(this->bill_to_show->isincome){
        income_all+=this->bill_to_show->money;
    }else{
        outcome_all+=this->bill_to_show->money;
    }
    close();
}


void detail_of_data::on_delete_pushButton_clicked()
{
    QMessageBox::StandardButton btn=QMessageBox::information(this,QStringLiteral("提示"),QStringLiteral("是否删除"),QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if(QMessageBox::No==btn){
        return;
    }
    if(this->bill_to_show->isincome){
        std::cout<<"income_all:"<<income_all<<" ";
        income_all-=this->bill_to_show->money;
        std::cout<<income_all<<std::endl;
        for(std::vector<bill_one>::iterator i=bill_all.begin();i!=bill_all.end();i++){
            std::cout<<i->name<<" "<<i->money<<" "<<i->bill_data.rank<<std::endl;
        }
    }else{
        std::cout<<"outcome_all:"<<outcome_all<<" ";
        outcome_all-=this->bill_to_show->money;
        std::cout<<outcome_all<<std::endl;
        for(std::vector<bill_one>::iterator i=bill_all.begin();i!=bill_all.end();i++){
            std::cout<<i->name<<" "<<i->money<<" "<<i->bill_data.rank<<std::endl;
        }
    }
    this->bill_to_show->money=-1;
    close();
}

