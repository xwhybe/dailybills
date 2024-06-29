#ifndef DETAIL_OF_DATA_H
#define DETAIL_OF_DATA_H

#include <QDialog>
#include <data.h>

namespace Ui {
class detail_of_data;
}

class detail_of_data : public QDialog
{
    Q_OBJECT

public:
    explicit detail_of_data(QWidget *parent = nullptr, bill_one* bill_to_show = nullptr);
    ~detail_of_data();

private slots:
    void on_save_pushButton_clicked();

    void on_delete_pushButton_clicked();

private:
    Ui::detail_of_data *ui;
    bill_one* bill_to_show;
};

#endif // DETAIL_OF_DATA_H
