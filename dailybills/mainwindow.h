#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"addone.h"
#include"statistics.h"
#include"viewdata.h"
#include"showonedata.h"
#include<QCloseEvent>
#include"calendar.h"
#include"view_all_data.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void closeEvent(QCloseEvent *);

private slots:
    void on_pushButton_clicked();
    void loadDataFromFile_income();
    void loadDataFromFile_outcome();
    void loadDataFromFile();
    void updateLabels();

    void on_sta_clicked();

    void on_to_view_data_clicked();

    void on_to_calendar_clicked();

    void on_all_history_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    addone *dialog;
    statistics *statis;
    viewdata *view_dialog;
    calendar *cald;
    view_all_data *view_all;
};
#endif // MAINWINDOW_H
