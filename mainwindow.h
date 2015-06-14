#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVBoxLayout* vl[7];
    void actualiserAgenda(const QDate &date);
    static void remove(QLayout* layout);

private slots:
    void click_aprojet();
    void click_atache_simple();
    void click_arbo();
<<<<<<< HEAD
    void click_aprog();
=======
    void on_calendarWidget_activated(const QDate &date);
    void on_calendarWidget_clicked(const QDate &date);
>>>>>>> origin/master
};

#endif // MAINWINDOW_H
