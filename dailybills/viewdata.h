#ifndef VIEWDATA_H
#define VIEWDATA_H

#include <QDialog>

namespace Ui {
class viewdata;
}

class viewdata : public QDialog
{
    Q_OBJECT

public:
    explicit viewdata(QWidget *parent = nullptr);
    ~viewdata();

private slots:
    void on_cancel_pushButton_clicked();

    void on_OK_pushButton_clicked();

    void on_view_dateEdit_dateChanged(const QDate &date);

public slots:
    void set_date_from_calendar(const QDate &initialDate);

private:
    Ui::viewdata *ui;
};

#endif // VIEWDATA_H
