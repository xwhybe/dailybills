#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDialog>
#include"data.h"
#include"viewdata.h"
#include<QCloseEvent>

namespace Ui {
class calendar;
}

class calendar : public QDialog
{
    Q_OBJECT

public:
    explicit calendar(QWidget *parent = nullptr);
    ~calendar();

private slots:
    void on_goback_clicked();

    void on_calendarWidget_selectionChanged();

    void showSelectedData();

    void on_calendarWidget_activated(const QDate &date);

    void on_calendarWidget_clicked(const QDate &date);

    void closeEvent(QCloseEvent* e);

private:
    Ui::calendar *ui;
    viewdata *view_data;
};

#endif // CALENDAR_H
