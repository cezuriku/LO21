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
    /**
     * @brief Constructeur par défaut
     * @param parent
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * @brief Destructeur par défaut
     */
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    /**
     * @brief Les Vertical Layout représentant les jours de la semaine
     */
    QVBoxLayout* vl[7];

    /**
     * @brief actualise l'agenda à l'affichage
     * @param date Une date de la semaine à afficher
     */
    void actualiserAgenda(const QDate &date);

    /**
     * @brief Vide le layout de tout les éléments internes
     * @param layout
     */
    static void remove(QLayout* layout);

private slots:
    void click_aprojet();
    void click_atache_simple();
    void click_arbo();
    void on_calendarWidget_activated(const QDate &date);
    void on_calendarWidget_clicked(const QDate &date);
};

#endif // MAINWINDOW_H
