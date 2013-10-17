#ifndef LOGGER_H
#define LOGGER_H
/*****************************************************************************
 *Class: Logger()
 *Creator: Suneil Mistry
 *Last Edit: 10-16-2013 10:36pm
 *====================================
 *Description: This class will log all data (movement, combat, etc). Used to
 *      keep track of all movement (including manual overloads).
 *
 *Log:
 *      10-16-2013-Suneil Mistry-> Initial Class creation.
 *      10-17-2013-Suneil Mistry-> More Log functionality added (reading
 *          file and writing to it)
 *
 ***************************************************************************/

#include <QFile>
#include <QTextStream>
#include <QStringList>

class Logger
{
public:
    Logger(QString);
    ~Logger();
    void setFileName(QString);
    bool write2File(QString);
    bool writeList2File(QStringList);
    QString viewLog();
    void close();
private:
    QFile *m_file;
    QTextStream *m_input;

};

#endif // LOGGER_H
