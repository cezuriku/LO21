#ifndef CALENDAREXCEPTION_H
#define CALENDAREXCEPTION_H

#include <string>
#include <QString>

class CalendarException{
public:
    CalendarException(const QString& message):info(message){}
    QString getInfo() const { return QString("Erreur : ").append(info); }
private:
    QString info;
};

#endif // CALENDAREXCEPTION_H
