#include "statistics.h"
#include "ui_statistics.h"
#include "data.h"
#include<algorithm>

statistics::statistics(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::statistics)
{
    ui->setupUi(this);
    ui->end_date->setDate((QDate::currentDate()));

}

statistics::~statistics()
{
    delete ui;
}

QChart *statistics::createIncomePieChart(double* sta_income)const
{
    QChart *income_chart = new QChart();
    income_chart->setTitle("收入情况");

    QPieSeries *series = new QPieSeries(income_chart);
    series->setName("hello");
    series->append("彩票",sta_income[0]);
    series->append("工资",sta_income[1]);
    series->append("兼职",sta_income[2]);
    series->append("借入",sta_income[3]);
    series->append("奖金",sta_income[4]);
    series->append("补贴",sta_income[5]);
    series->append("其他",sta_income[6]);
    series->setLabelsVisible();
    //饼图的大小
    series->setPieSize(0.6);


    QPieSlice *slice_1 =series->slices().at(0);
    QPieSlice *slice_2 =series->slices().at(1);
    QPieSlice *slice_3 =series->slices().at(2);
    QPieSlice *slice_4 =series->slices().at(3);
    QPieSlice *slice_5 =series->slices().at(4);
    QPieSlice *slice_6 =series->slices().at(5);
    QPieSlice *slice_7 =series->slices().at(6);

    QString temp;
    slice_1->setLabelVisible(sta_income[0]);// 是否显示指标文字
    temp="彩票 "+QString::number((sta_income[0]))+"¥";
    slice_1->setLabel(temp);
    slice_1->setExploded();//扇面区分
    slice_1->setExplodeDistanceFactor(0.01);// 扇面分开的距离指数
    slice_2->setLabelVisible(sta_income[1]);
    temp="工资 "+QString::number((sta_income[1]))+"¥";
    slice_2->setLabel(temp);
    slice_2->setExploded();
    slice_2->setExplodeDistanceFactor(0.01);
    slice_3->setLabelVisible(sta_income[2]);
    temp="兼职 "+QString::number((sta_income[2]))+"¥";
    slice_3->setLabel(temp);
    slice_3->setExploded();
    slice_3->setExplodeDistanceFactor(0.01);
    slice_4->setLabelVisible(sta_income[3]);
    temp="借入 "+QString::number((sta_income[3]))+"¥";
    slice_4->setLabel(temp);
    slice_4->setExploded();
    slice_4->setExplodeDistanceFactor(0.01);
    slice_5->setLabelVisible(sta_income[4]);
    temp="奖金 "+QString::number((sta_income[4]))+"¥";
    slice_5->setLabel(temp);
    slice_5->setExploded();
    slice_5->setExplodeDistanceFactor(0.01);
    slice_6->setLabelVisible(sta_income[5]);
    temp="补贴 "+QString::number((sta_income[5]))+"¥";
    slice_6->setLabel(temp);
    slice_6->setExploded();
    slice_6->setExplodeDistanceFactor(0.01);
    slice_7->setLabelVisible(sta_income[6]);
    temp="其他 "+QString::number((sta_income[6]))+"¥";
    slice_7->setLabel(temp);
    slice_7->setExploded();
    slice_7->setExplodeDistanceFactor(0.01);

    income_chart->setAnimationOptions(QChart::AllAnimations);//动画效果
    income_chart->legend()->setAlignment(Qt::AlignLeft);//图例

    income_chart->addSeries(series);
    income_chart->setTheme(QChart::ChartThemeBlueIcy); //主题
    return income_chart;
}


QChart *statistics::createOutcomePieChart(double* sta_outcome)const
{
    QChart *outcome_chart = new QChart();
    outcome_chart->setTitle("支出情况");

    QPieSeries *series = new QPieSeries(outcome_chart);
    series->setName("hello");
    series->append("购物",sta_outcome[0]);
    series->append("餐饮",sta_outcome[1]);
    series->append("出行",sta_outcome[2]);
    series->append("娱乐",sta_outcome[3]);
    series->append("医疗",sta_outcome[4]);
    series->append("教育",sta_outcome[5]);
    series->append("其他",sta_outcome[6]);
    series->setLabelsVisible();

    series->setPieSize(0.6);


    QPieSlice *slice_1 =series->slices().at(0);
    QPieSlice *slice_2 =series->slices().at(1);
    QPieSlice *slice_3 =series->slices().at(2);
    QPieSlice *slice_4 =series->slices().at(3);
    QPieSlice *slice_5 =series->slices().at(4);
    QPieSlice *slice_6 =series->slices().at(5);
    QPieSlice *slice_7 =series->slices().at(6);

    QString temp;
    slice_1->setLabelVisible(sta_outcome[0]);
    temp="购物 "+QString::number((sta_outcome[0]))+"¥";
    slice_1->setLabel(temp);
    slice_1->setExploded();
    slice_1->setExplodeDistanceFactor(0.01);
    slice_2->setLabelVisible(sta_outcome[1]);
    temp="餐饮 "+QString::number((sta_outcome[1]))+"¥";
    slice_2->setLabel(temp);
    slice_2->setExploded();
    slice_2->setExplodeDistanceFactor(0.01);
    slice_3->setLabelVisible(sta_outcome[2]);
    temp="出行 "+QString::number((sta_outcome[2]))+"¥";
    slice_3->setLabel(temp);
    slice_3->setExploded();
    slice_3->setExplodeDistanceFactor(0.01);
    slice_4->setLabelVisible(sta_outcome[3]);
    temp="娱乐 "+QString::number((sta_outcome[3]))+"¥";
    slice_4->setLabel(temp);
    slice_4->setExploded();
    slice_4->setExplodeDistanceFactor(0.01);
    slice_5->setLabelVisible(sta_outcome[4]);
    temp="医疗 "+QString::number((sta_outcome[4]))+"¥";
    slice_5->setLabel(temp);
    slice_5->setExploded();
    slice_5->setExplodeDistanceFactor(0.01);
    slice_6->setLabelVisible(sta_outcome[5]);
    temp="教育 "+QString::number((sta_outcome[5]))+"¥";
    slice_6->setLabel(temp);
    slice_6->setExploded();
    slice_6->setExplodeDistanceFactor(0.01);
    slice_7->setLabelVisible(sta_outcome[6]);
    temp="其他 "+QString::number((sta_outcome[6]))+"¥";
    slice_7->setLabel(temp);
    slice_7->setExploded();
    slice_7->setExplodeDistanceFactor(0.01);

    outcome_chart->setAnimationOptions(QChart::AllAnimations);
    outcome_chart->legend()->setAlignment(Qt::AlignRight);

    outcome_chart->addSeries(series);
    outcome_chart->setTheme(QChart::ChartThemeBrownSand);
    return outcome_chart;
}


QChartView *outcome_saver=nullptr;
QChartView *income_saver=nullptr;

void statistics::on_save_date_clicked()
{
    int start_year,start_month,start_day;
    int end_year,end_month,end_day;

    double sta_income[7]{0,0,0,0,0,0,0};
    double sta_outcome[7]{0,0,0,0,0,0,0};
    double all_income=0;
    double all_outcome=0;


    QDate date_start = ui->start_date->date();
    start_year = date_start.year();
    start_month = date_start.month();
    start_day = date_start.day();


    QDate date_end = ui->end_date->date();
    end_year = date_end.year();
    end_month = date_end.month();
    end_day = date_end.day();


    data_inf startdate(start_year,start_month,start_day,0);
    data_inf enddate(end_year,end_month,end_day,0x7fffffff);

    std::sort(bill_all.begin(),bill_all.end());
    for(auto i=bill_all.begin();i!=bill_all.end();i++){
        if(i->bill_data<startdate||enddate<i->bill_data){continue;}

        if(i->isincome){
            sta_income[i->label]+=(i->money);
        }
        else{
            sta_outcome[i->label]+=(i->money);
        }
    }

    for(int i=0;i<7;i++){
        all_income+=sta_income[i];
        all_outcome+=sta_outcome[i];
    }

    if(all_income==0){
        if(income_saver!=nullptr){
            ui->income_layout->removeWidget(income_saver);
            delete income_saver;
            income_saver=nullptr;
        }
        if(date_end>=date_start)
            ui->no_income->setText("此时间段内无收入！");
        else
            ui->no_income->setText("时间段非法：起始时间晚于结束时间！");
    }
    else{
        ui->no_income->setText("");
        {
            if(income_saver!=nullptr){
                ui->income_layout->removeWidget(income_saver);
                delete income_saver;
                income_saver=nullptr;
            }
            QChartView *income_chartView;
            income_chartView = new QChartView(createIncomePieChart(sta_income));
            ui->income_layout->insertWidget(0,income_chartView);
            income_saver=income_chartView;

        }


    }


    if(all_outcome==0){
        if(outcome_saver!=nullptr){
            ui->outcome_layout->removeWidget(outcome_saver);
            delete outcome_saver;
            outcome_saver=nullptr;
        }
        if(date_end>=date_start)
            ui->no_outcome->setText("此时间段内无支出！");
        else
            ui->no_outcome->setText("时间段非法：起始时间晚于结束时间！");
    }
    else{
        ui->no_outcome->setText("");
        {
            if(outcome_saver!=nullptr){
                ui->outcome_layout->removeWidget(outcome_saver);
                delete outcome_saver;
                outcome_saver=nullptr;
            }
            QChartView *outcome_chartView;
            outcome_chartView = new QChartView(createOutcomePieChart(sta_outcome));
            ui->outcome_layout->insertWidget(0,outcome_chartView);
            outcome_saver=outcome_chartView;
        }


    }

}



void statistics::on_go_back_clicked()
{
    close();
}

