#include "window_addtachecomposite.h"
#include "ui_window_addtachecomposite.h"

window_addtachecomposite::window_addtachecomposite(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window_addtachecomposite)
{
    ui->setupUi(this);
}

window_addtachecomposite::~window_addtachecomposite()
{
    delete ui;
}
