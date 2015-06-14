#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "window_addproject.h"
#include "window_addtacheunaire.h"
#include "window_deleteproject.h"
#include "window_arbo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textAgenda->setPlainText("Affichage de l'agenda");
    connect(ui->b_aprojet, SIGNAL(clicked()), this, SLOT(click_aprojet()));
    connect(ui->b_atache_simple, SIGNAL(clicked()), this, SLOT(click_atache_simple()));
    connect(ui->b_arbo, SIGNAL(clicked()), this, SLOT(click_arbo()));
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
