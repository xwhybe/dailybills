#ifndef VIEW_ALL_DATA_H
#define VIEW_ALL_DATA_H

#include <QDialog>

namespace Ui {
class view_all_data;
}

class view_all_data : public QDialog
{
    Q_OBJECT

public:
    explicit view_all_data(QWidget *parent = nullptr);
    ~view_all_data();

private:
    Ui::view_all_data *ui;

public slots:
    void renew();
};

#endif // VIEW_ALL_DATA_H
