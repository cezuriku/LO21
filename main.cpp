#include "mainwindow.h"
#include <QApplication>
#include "model.h"
#include "manager.h"

int main(int argc, char *argv[])
{
    TacheUnitaire* t1 = new TacheUnitaire(QString("T1"),QDateTime::currentDateTime().addDays(1),QDateTime::currentDateTime().addDays(2), QTime::fromString("1", "h"));
    TacheUnitaire* t2 = new TacheUnitaire(QString("T2"),QDateTime::currentDateTime().addDays(1),QDateTime::currentDateTime().addDays(2), QTime::fromString("1", "h"));
    TacheComposite* t12 = new TacheComposite(QString("T12"),QDateTime::currentDateTime().addDays(1),QDateTime::currentDateTime().addDays(2));
    t12->addElement(t1);
    t12->addElement(t2);
    Model::ajouterTache(t1);
    Model::ajouterTache(t2);
    Model::ajouterTache(t12);
    TacheUnitaire* t3 = new TacheUnitaire(QString("T3"),QDateTime::currentDateTime().addDays(3),QDateTime::currentDateTime().addDays(4), QTime::fromString("3", "h"));
    TacheUnitaire* t4 = new TacheUnitaire(QString("T4"),QDateTime::currentDateTime().addDays(3),QDateTime::currentDateTime().addDays(4), QTime::fromString("3", "h"));
    TacheComposite* t34 = new TacheComposite(QString("T34"),QDateTime::currentDateTime().addDays(3),QDateTime::currentDateTime().addDays(4));
    t34->addElement(t3);
    t34->addElement(t4);
    Model::ajouterTache(t3);
    Model::ajouterTache(t4);
    Model::ajouterTache(t34);

    Projet* projet = new Projet("Projet 1 ", QDateTime::currentDateTime().addSecs(30), QDateTime::currentDateTime().addDays(5));
    Model::ajouterProjet(projet);
    Model::ajouterProgrammation(new Programmation(QDateTime::currentDateTime().addDays(1).addSecs(3600), "T1"));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}