#ifndef WINDOW_ARBO_H
#define WINDOW_ARBO_H
#include <QStandardItemModel>
#include <QWidget>

namespace Ui {
class window_arbo;
}

class window_arbo : public QWidget
{
    Q_OBJECT

public:
    explicit window_arbo(QWidget *parent = 0);
    ~window_arbo();

private:
    Ui::window_arbo *ui;
    QStandardItemModel *modele;
};

#endif // WINDOW_ARBO_H
