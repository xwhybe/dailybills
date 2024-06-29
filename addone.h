#ifndef ADDONE_H
#define ADDONE_H

#include <QDialog>
#include <QButtonGroup>


namespace Ui {
class addone;
}

class addone : public QDialog
{
    Q_OBJECT

public:
    explicit addone(QWidget *parent = nullptr);
    ~addone();

private slots:
    void oninComeSaveButtonClicked();
private slots:
    void onoutComeSaveButtonClicked();
private slots:
    void on_pushButton_cancel_outcome_clicked();

    void on_pushButton_cancel_income_clicked();


private:
    Ui::addone *ui;
    QButtonGroup *incomeButtonGroup;
    QButtonGroup *outcomeButtonGroup;


};

#endif // ADDONE_H


