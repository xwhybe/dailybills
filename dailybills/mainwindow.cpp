#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "data.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include<QCloseEvent>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dialog(new addone(this)),
    statis(new statistics(this)),
    view_dialog(new viewdata(this)),
    cald(new calendar(this)),
    view_all(new view_all_data(this))
{
    ui->setupUi(this);
    loadDataFromFile();
    updateLabels();


    QIcon icon=QIcon(":/new/myimage/new_icon/mymainlogo.jpg");
    QPixmap pic=icon.pixmap(icon.actualSize((QSize(360,120))));
    ui->Logo_image->setPixmap(pic);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dialog;
    delete statis;
    delete view_dialog;
    delete cald;
}

void MainWindow::closeEvent(QCloseEvent* e){
    QFile file("bills.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)){
        QTextStream out(&file);
        for(auto i=bill_all.begin();i!=bill_all.end();i++){
            QDate date(i->bill_data.year,i->bill_data.month,i->bill_data.day);
            out<<QString::fromStdString(i->name)<<Qt::endl<<i->money<<Qt::endl<<date.toString("yyyy MM dd")<<Qt::endl<<i->remark<<Qt::endl<<i->isincome<<Qt::endl;
        }
        file.close();
    }
    e->accept();
}

void MainWindow::on_pushButton_clicked()
{
    dialog->exec();
    updateLabels();
}

void MainWindow::loadDataFromFile()
{
    QFile file("bills.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading.";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString name = in.readLine();
        double money = in.readLine().toDouble();
        QString dateString = in.readLine();
        QStringList dateParts = dateString.split(' ');//日期
        QString rmk = in.readLine();
        int type=in.readLine().toInt();

        if (dateParts.size() != 3) {
            qDebug() << "Invalid date format in file.";
            continue;
        }//不符合格式的日期

        int year = dateParts[0].toInt();
        int month = dateParts[1].toInt();
        int day = dateParts[2].toInt();

        data_inf billData(year, month, day, rank_now); // rank_income_now 由1开始递增
        rank_now++;
        bill_one bill;
        bill.bill_data = billData;
        bill.name = name.toStdString();
        bill.money = money;
        if(type==1){
            bill.isincome=true;
        }else{
            bill.isincome=false;
        }
        bill.label = -1;
        bill.remark=rmk;
        if(bill.isincome){
            income_all+=money;
            for (int i = 0; i < 7; ++i) {
                if (income[i] == bill.name) {
                    bill.label = i;
                    break;
                }
            }
        }else{
            outcome_all+=money;
            for (int i = 0; i < 7; ++i) {
                if (outcome[i] == bill.name) {
                    bill.label = i;
                    break;
                }
            }
        }
        bill_all.push_back(bill);
    }
    file.close();
    qDebug() << "Data loaded successfully.";
}

void MainWindow::loadDataFromFile_income()
{
    QFile file("income.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading.";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString name = in.readLine();
        double money = in.readLine().toDouble();
        QString dateString = in.readLine();
        QStringList dateParts = dateString.split(' ');//日期
        QString rmk = in.readLine();

        if (dateParts.size() != 3) {
            qDebug() << "Invalid date format in file.";
            continue;
        }//不符合格式的日期

        int year = dateParts[0].toInt();
        int month = dateParts[1].toInt();
        int day = dateParts[2].toInt();

        data_inf billData(year, month, day, rank_now); // rank_income_now 由1开始递增
        rank_now++;
        bill_one bill;
        bill.bill_data = billData;
        bill.name = name.toStdString();
        bill.money = money;
        bill.isincome = true;
        bill.label = -1;
        bill.remark=rmk;
        income_all+=money;
        for (int i = 0; i < 7; ++i) {
            if (income[i] == bill.name) {
                bill.label = i;
                break;
            }
        }
        bill_all.push_back(bill);
    }
    file.close();
    qDebug() << "Data loaded successfully.";
}
void MainWindow::loadDataFromFile_outcome()
{
    QFile file("outcome.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for reading.";
        return;
    }

    QTextStream out(&file);
    while (!out.atEnd()) {
        QString name = out.readLine();
        double money = out.readLine().toDouble();
        QString dateString = out.readLine();
        QStringList dateParts = dateString.split(' ');//日期
        QString rmk=out.readLine();

        if (dateParts.size() != 3) {
            qDebug() << "Invalid date format in file.";
            continue;
        }//不符合格式的日期

        int year = dateParts[0].toInt();
        int month = dateParts[1].toInt();
        int day = dateParts[2].toInt();

        data_inf billData(year, month, day, rank_now); // rank_income_now 由1开始递增
        rank_now++;
        bill_one bill;
        bill.bill_data = billData;
        bill.name = name.toStdString();
        bill.money = money;
        bill.isincome = false;
        bill.label = -1;
        bill.remark=rmk;
        outcome_all+=money;
        for (int i = 0; i < 7; ++i) {
            if (outcome[i] == bill.name) {
                bill.label = i;
                break;
            }
        }
        bill_all.push_back(bill);
    }
    file.close();
    qDebug() << "Data loaded successfully.";
}

void MainWindow::updateLabels()
{

    // 格式化总收入和总支出为带两位小数的字符串
    QString incomeStr = QString("(%1)").arg(QString::number(income_all, 'f', 2));
    QString outcomeStr = QString("(%1)").arg(QString::number(outcome_all, 'f', 2));
    QString netcomeStr = QString("(%1)").arg(QString::number(income_all-outcome_all, 'f', 2));

    // 更新标签
    ui->income_count_all->setText(incomeStr);
    ui->outcome_count_all->setText(outcomeStr);
    ui->netcome_count_all->setText(netcomeStr);

}

void MainWindow::on_sta_clicked()
{
    statis->exec();
}

void MainWindow::on_to_view_data_clicked(){}



void MainWindow::on_to_calendar_clicked()
{
    cald->exec();
    QString incomeStr = QString("(%1)").arg(QString::number(income_all, 'f', 2));
    QString outcomeStr = QString("(%1)").arg(QString::number(outcome_all, 'f', 2));
    QString netcomeStr = QString("(%1)").arg(QString::number(income_all-outcome_all, 'f', 2));

    // 更新标签
    ui->income_count_all->setText(incomeStr);
    ui->outcome_count_all->setText(outcomeStr);
    ui->netcome_count_all->setText(netcomeStr);
}


void MainWindow::on_all_history_pushButton_clicked()
{
    view_all->renew();
    view_all->exec();
    QString incomeStr = QString("(%1)").arg(QString::number(income_all, 'f', 2));
    QString outcomeStr = QString("(%1)").arg(QString::number(outcome_all, 'f', 2));
    QString netcomeStr = QString("(%1)").arg(QString::number(income_all-outcome_all, 'f', 2));

    // 更新标签
    ui->income_count_all->setText(incomeStr);
    ui->outcome_count_all->setText(outcomeStr);
    ui->netcome_count_all->setText(netcomeStr);
}

