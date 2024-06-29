#ifndef STATISTICS_H
#define STATISTICS_H

#include <QDialog>
#include"data.h"
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui {
class statistics;
}
QT_END_NAMESPACE

// QT_CHARTS_BEGIN_NAMESPACE
// class QChartView;
// class QChart;
// QT_CHARTS_END_NAMESPACE

// QT_CHARTS_USE_NAMESPACE

class statistics : public QDialog
{
    Q_OBJECT

public:
    explicit statistics(QWidget *parent = nullptr);
    ~statistics();
    QChart * createIncomePieChart(double*) const;
    QChart * createOutcomePieChart(double*) const;

private slots:

    void on_save_date_clicked();

    void on_go_back_clicked();

private:
    Ui::statistics *ui;
};

#endif // STATISTICS_H
