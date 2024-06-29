#include "addone.h"
#include <QButtonGroup>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "data.h"
#include "ui_addone.h"
//注意：0.00情况未完成,要提示无法进行！；
addone::addone(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addone)
{
    ui->setupUi(this);
    QButtonGroup *incomeButtonGroup = new QButtonGroup(this);
    incomeButtonGroup->addButton(ui->lottery, 0);
    incomeButtonGroup->addButton(ui->salary, 1);
    incomeButtonGroup->addButton(ui->parttimejob, 2);
    incomeButtonGroup->addButton(ui->borrowedfund, 3);
    incomeButtonGroup->addButton(ui->bonus, 4);
    incomeButtonGroup->addButton(ui->subsidy, 5);
    incomeButtonGroup->addButton(ui->income, 6);
    ui->lottery->setChecked(true);
    connect(ui->pushButton_save_income, &QPushButton::clicked, this, &addone::oninComeSaveButtonClicked);
    QButtonGroup *outcomeButtonGroup = new QButtonGroup(this);
    outcomeButtonGroup->addButton(ui->radioButton, 0);
    outcomeButtonGroup->addButton(ui->eating, 1);
    outcomeButtonGroup->addButton(ui->goout, 2);
    outcomeButtonGroup->addButton(ui->fun, 3);
    outcomeButtonGroup->addButton(ui->care, 4);
    outcomeButtonGroup->addButton(ui->education, 5);
    outcomeButtonGroup->addButton(ui->outcome, 6);
    ui->radioButton->setChecked(true);
    connect(ui->pushButton_save_outcome, &QPushButton::clicked, this, &addone::onoutComeSaveButtonClicked);

    QIcon icon1=QIcon(":/new/myimage/new_icon/res/lottery.png");
    QPixmap pic1=icon1.pixmap(icon1.actualSize((QSize(24,24))));
    ui->icon_1->setPixmap(pic1);

    QIcon icon2=QIcon(":/new/myimage/new_icon/image/salary.png");
    QPixmap pic2=icon2.pixmap(icon2.actualSize((QSize(24,24))));
    ui->icon_2->setPixmap(pic2);

    QIcon icon3=QIcon(":/new/myimage/new_icon/res/part-time-job.png");
    QPixmap pic3=icon3.pixmap(icon3.actualSize((QSize(24,24))));
    ui->icon_3->setPixmap(pic3);

    QIcon icon4=QIcon(":/new/myimage/new_icon/res/borrowfund.png");
    QPixmap pic4=icon4.pixmap(icon4.actualSize((QSize(24,24))));
    ui->icon_4->setPixmap(pic4);

    QIcon icon5=QIcon(":/new/myimage/new_icon/res/bonus.png");
    QPixmap pic5=icon5.pixmap(icon5.actualSize((QSize(24,24))));
    ui->icon_5->setPixmap(pic5);

    QIcon icon6=QIcon(":/new/myimage/new_icon/res/subsidy.png");
    QPixmap pic6=icon6.pixmap(icon6.actualSize((QSize(24,24))));
    ui->icon_6->setPixmap(pic6);

    QIcon icon7=QIcon(":/new/myimage/new_icon/image/else.png");
    QPixmap pic7=icon7.pixmap(icon7.actualSize((QSize(24,24))));
    ui->icon_7->setPixmap(pic7);

    QIcon icon8=QIcon(":/new/myimage/new_icon/res/shopping.png");
    QPixmap pic8=icon8.pixmap(icon8.actualSize((QSize(24,24))));
    ui->icon_8->setPixmap(pic8);

    QIcon icon9=QIcon(":/new/myimage/new_icon/res/food.png");
    QPixmap pic9=icon9.pixmap(icon9.actualSize((QSize(24,24))));
    ui->icon_9->setPixmap(pic9);

    QIcon icon10=QIcon(":/new/myimage/new_icon/image/go out.png");
    QPixmap pic10=icon10.pixmap(icon10.actualSize((QSize(24,24))));
    ui->icon_10->setPixmap(pic10);

    QIcon icon11=QIcon(":/new/myimage/new_icon/res/game.png");
    QPixmap pic11=icon11.pixmap(icon11.actualSize((QSize(24,24))));
    ui->icon_11->setPixmap(pic11);

    QIcon icon12=QIcon(":/new/myimage/new_icon/res/medical.png");
    QPixmap pic12=icon12.pixmap(icon12.actualSize((QSize(24,24))));
    ui->icon_12->setPixmap(pic12);

    QIcon icon13=QIcon(":/new/myimage/new_icon/education.jpg");
    QPixmap pic13=icon13.pixmap(icon13.actualSize((QSize(24,24))));
    ui->icon_13->setPixmap(pic13);

    QIcon icon14=QIcon(":/new/myimage/new_icon/image/else.png");
    QPixmap pic14=icon14.pixmap(icon14.actualSize((QSize(24,24))));
    ui->icon_14->setPixmap(pic14);



    ui->dateEdit_outcome->setDate((QDate::currentDate()));
    ui->dateEdi_income->setDate((QDate::currentDate()));
}

addone::~addone()
{
    delete ui;
}

void addone::oninComeSaveButtonClicked()
{
    // 获取选中的收入类型
    int selectedId = -1;
    if(ui->lottery->isChecked())selectedId=0;
    if(ui->salary->isChecked())selectedId=1;
    if(ui->parttimejob->isChecked())selectedId=2;
    if(ui->borrowedfund->isChecked())selectedId=3;
    if(ui->bonus->isChecked())selectedId=4;
    if(ui->subsidy->isChecked())selectedId=5;
    if(ui->income->isChecked())selectedId=6;

    if (selectedId == -1) {
        // 没有选中任何收入类型
        qDebug() << "No income type selected.";
        return;
    }

    // 获取金额
    double money = ui->moneybox_income->value();

    // 获取日期
    QDate date = ui->dateEdi_income->date();
    int year = date.year();
    int month = date.month();
    int day = date.day();

    QString rmk=ui->in_remark_textEdit->toPlainText();
    if(rmk.length()==0){
        rmk=QString("无");
    }

    // 创建数据结构并存储数据
    data_inf billData(year, month, day, rank_now); // rank暂定为1，留待修改
    rank_now++;
    bill_one bill;
    bill.bill_data = billData;
    bill.name = income[selectedId];
    bill.label = selectedId;
    bill.isincome = true;
    bill.money = money;
    bill.remark=rmk;
    bill_all.push_back(bill);
    income_all+=money;

    // 打印数据以检查
    qDebug() << "Saved Income: " << QString::fromStdString(bill.name) << ", Amount: " << bill.money << ", Date: " << date.toString();
    close();

}

void addone::onoutComeSaveButtonClicked()
{
    // 获取选中的收入类型
    int selectedId = -1;
    if(ui->radioButton->isChecked())selectedId=0;
    if(ui->eating->isChecked())selectedId=1;
    if(ui->goout->isChecked())selectedId=2;
    if(ui->fun->isChecked())selectedId=3;
    if(ui->care->isChecked())selectedId=4;
    if(ui->education->isChecked())selectedId=5;
    if(ui->outcome->isChecked())selectedId=6;

    if (selectedId == -1) {
        // 没有选中任何收入类型
        qDebug() << "No outcome type selected.";
        return;
    }

    // 获取金额
    double money = ui->moneybox_outcome->value();

    // 获取日期

    QDate date = ui->dateEdit_outcome->date();
    int year = date.year();
    int month = date.month();
    int day = date.day();

    QString rmk = ui->out_remark_textEdit->toPlainText();
    if(rmk.length()==0){
        rmk=QString("无");
    }

    // 创建数据结构并存储数据
    data_inf billData(year, month, day, rank_now);
    rank_now++;
    bill_one bill;
    bill.bill_data = billData;
    bill.name = outcome[selectedId];
    bill.label = selectedId;
    bill.isincome = false;
    bill.money = money;
    bill.remark=rmk;
    bill_all.push_back(bill);
    outcome_all+=money;

    // 打印数据以检查
    qDebug() << "Saved Income: " << QString::fromStdString(bill.name) << ", Amount: " << bill.money << ", Date: " << date.toString();
    close();
}

void addone::on_pushButton_cancel_outcome_clicked()
{
    close();
}


void addone::on_pushButton_cancel_income_clicked()
{
    close();
}

