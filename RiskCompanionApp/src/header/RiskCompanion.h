#ifndef RISK_COMPANION_H
#define RISK_COMPANION_H
/*****************************************************************************
 *Class: RiskCompanion()
 *Creator: Suneil Mistry
 *Last Edit: 10-15-2013 11:36pm
 *====================================
 *Description: This class will control all gui related portions of the
 *      code. This code is what will be running and instantiating all other
 *      code (this is basically the "main" part of the program.
 *
 *      **Note: I know this is not exactly correct and I should/will
 *          eventually change the system to a consumer/producer-MVP
 *          type system.
 *Log:
 *      10-15-2013-Suneil Mistry-> Initial Class creation, ui edits,
 *          and added basic functionality (slot connector, etc).
 *
 ***************************************************************************/
//function template
/** -----------------------------------------------------------------
*   function()
*
*   -Description:
*   ------
*   -pre:
*   ------
*   -post:
-------------------------------------------------------------------*/


#include <QMainWindow>
#include <QSignalMapper>
#include <QDebug>
#include "ui_RiskCompanion.h"
#include "../header/Logger.h"

namespace Ui {
    class RiskCompanion;
}

class RiskCompanion : public QMainWindow
{
    Q_OBJECT

public:
    explicit RiskCompanion(QWidget *parent = 0); //constructor
    ~RiskCompanion();   //destructor

private slots:
/** -----------------------------------------------------------------
*   void signalSorter(const QString &)
*
*   -Description: Accepts a QString that indicates
*       a certian button/signal was pressed/sent. Takes that signal/
*       string and parses it such that the correction function
*       to handle that signal is called.
*   ------
*   -pre: Signal/Button pressed has sent a QString out
*   ------
*   -post: signal handled
-------------------------------------------------------------------*/
    void signalSorter(QString);

private:
    Ui::RiskCompanion *ui;
    QSignalMapper *m_signalMapper;

    //test remove when necessary!
    Logger *m_logger;
    //end test area!

    void connectButtons();
};

#endif // RISK_COMPANION_H
