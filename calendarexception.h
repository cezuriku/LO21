#ifndef CALENDAREXCEPTION_H
#define CALENDAREXCEPTION_H

#include <string>
#include <QString>

class CalendarException{
public:
    /**
     * @brief Exception levée lorsque notre programme tente de faire une action illégale
     * @param message le contenu de l'exception
     */
    CalendarException(const QString& message):info(message){}

    /**
     * @brief Recupere le message de l'exception
     * @return le contenu de l'exception
     */
    QString getInfo() const { return QString("Erreur : ").append(info); }

private:
    /// L'info de l'exception
    QString info;
};

#endif // CALENDAREXCEPTION_H
