#ifndef WINDOW_ADDTACHECOMPOSITE_H
#define WINDOW_ADDTACHECOMPOSITE_H

#include <QWidget>

namespace Ui {
class window_addtachecomposite;
}

class window_addtachecomposite : public QWidget
{
    Q_OBJECT

public:
    explicit window_addtachecomposite(QWidget *parent = 0);
    ~window_addtachecomposite();

private:
    Ui::window_addtachecomposite *ui;
};

#endif // WINDOW_ADDTACHECOMPOSITE_H
