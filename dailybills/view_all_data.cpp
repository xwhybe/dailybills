#include "view_all_data.h"
#include "ui_view_all_data.h"
#include "data.h"
#include<QScrollArea>
#include<showonedata.h>
#include<QMessageBox>
#include<algorithm>

view_all_data::view_all_data(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::view_all_data)
{
    ui->setupUi(this);
}

void view_all_data::renew(){
    std::sort(bill_all.begin(),bill_all.end());
    bool flag=0;
    ui->all_data_listWidget->clear();
    for(std::vector<bill_one>::reverse_iterator i=bill_all.rbegin();i!=bill_all.rend();i++){
        flag=1;
        QListWidgetItem* item=new QListWidgetItem();
        showonedata* tmp=new showonedata(item,this,&(*i));
        ui->all_data_listWidget->addItem(item);
        ui->all_data_listWidget->setItemWidget(item,tmp);
        ui->all_data_listWidget->setCurrentItem(item);
        connect(tmp,&showonedata::emit_del,this,[&](QListWidgetItem* item){
            ui->all_data_listWidget->removeItemWidget(item);
            delete item;
            item=nullptr;
        });
    }
    if(flag==0){
        QString type=QString("无历史收支");
        QListWidgetItem* tmp=new QListWidgetItem(type);
        ui->all_data_listWidget->addItem(tmp);
    }
}

view_all_data::~view_all_data()
{
    delete ui;
}
