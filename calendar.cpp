#include "calendar.h"
#include "ui_calendar.h"
#include<QCloseEvent>

calendar::calendar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::calendar)
    , view_data(new viewdata(this))
{
    ui->setupUi(this);
    ui->calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    connect(ui->calendarWidget,SIGNAL(selectionChanged()),this,SLOT(showSelectedData()));
    //ui->show_date->setAlignment(Qt::AlignHCenter);
    ui->calendarWidget->setGridVisible(true);
    //ui->calendarWidget->clicked(QDate::currentDate());

}

calendar::~calendar()
{
    delete ui;
    delete view_data;
}

void calendar::on_goback_clicked()
{
    close();
}


void calendar::showSelectedData()
{
    ui->show_date->setText(ui->calendarWidget->selectedDate().toString("yyyy-MM-dd"));
}


void calendar::on_calendarWidget_selectionChanged()
{

}


void calendar::on_calendarWidget_activated(const QDate &date)
{
    view_data->set_date_from_calendar(date);
    view_data->exec();
    calendar::on_calendarWidget_clicked(date);
}


void calendar::on_calendarWidget_clicked(const QDate &date)
{
    double all_income=0,all_outcome=0;
    for(auto i=bill_all.begin();i!=bill_all.end();i++){
        if((i->bill_data.year)!=date.year()||(i->bill_data.month)!=date.month()||(i->bill_data.day)!=date.day()){continue;}

        if(i->isincome){
            all_income+=(i->money);
        }
        else{
            all_outcome+=(i->money);
        }
    }

    ui->income_label->setText(QString::number(all_income)+" ¥");
    ui->outcome_label->setText(QString::number(all_outcome)+" ¥");


}

void calendar::closeEvent(QCloseEvent* e){
    ui->income_label->setText(QString("* * *"));
    ui->outcome_label->setText(QString("* * *"));
}

