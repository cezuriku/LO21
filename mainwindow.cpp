#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "window_addproject.h"
#include "window_addtacheunaire.h"
#include "window_deleteproject.h"
#include "window_arbo.h"
#include "window_addprog.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->b_aprojet, SIGNAL(clicked()), this, SLOT(click_aprojet()));
    connect(ui->b_atache_simple, SIGNAL(clicked()), this, SLOT(click_atache_simple()));
    connect(ui->b_arbo, SIGNAL(clicked()), this, SLOT(click_arbo()));
    connect(ui->b_aprog, SIGNAL(clicked()), this, SLOT(click_aprog()));
    vl[0] = ui->vl1;
    vl[1] = ui->vl2;
    vl[2] = ui->vl3;
    vl[3] = ui->vl4;
    vl[4] = ui->vl5;
    vl[5] = ui->vl6;
    vl[6] = ui->vl7;
    actualiserAgenda(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click_aprojet()
{
    window_addProject *fenetre = new window_addProject;
    fenetre->show();
}

void MainWindow::click_atache_simple()
{
    window_addtacheunaire *fenetre = new window_addtacheunaire;
    fenetre->show();
}

void MainWindow::click_arbo()
{
    window_arbo *fenetre = new window_arbo;
    fenetre->show();
}

void MainWindow::click_aprog()
{
    window_addprog *fenetre = new window_addprog;
    fenetre->show();
}

void MainWindow::on_calendarWidget_activated(const QDate &date)
{
    actualiserAgenda(date);
}

void MainWindow::actualiserAgenda(const QDate &date) {
    QDate date2(date);
    date2 = date2.addDays(-date.dayOfWeek() + 1);
    for (int i = 0; i < 7; i++) {
        remove(vl[i]);
        vl[i]->addWidget(new QLabel(date2.toString("dddd")));
        for (Programmation* p : ProgrammationManager::getProgrammationParDate(QDateTime(date2, QTime(0,0)),QDateTime(date2, QTime(23,59)))) {
            vl[i]->addWidget(new QLabel(p->getDate().time().toString()));
            vl[i]->addWidget(new QLabel(p->getTitre().toStdString().c_str()));
        }
        date2 = date2.addDays(1);
    }

}

void MainWindow::remove(QLayout* layout)
{
    QLayoutItem* child;
    while(layout->count()!=0)
    {
        child = layout->takeAt(0);
        if(child->layout() != 0)
        {
            remove(child->layout());
        }
        else if(child->widget() != 0)
        {
            delete child->widget();
        }

        delete child;
    }
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    actualiserAgenda(date);
}
