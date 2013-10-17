#include "../header/RiskCompanion.h"
#include "ui_RiskCompanion.h"

RiskCompanion::RiskCompanion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RiskCompanion){

    ui->setupUi(this);

    m_signalMapper = new QSignalMapper(this);
    connect(m_signalMapper, SIGNAL(mapped(QString)),this, SLOT(signalSorter(QString)));

    connectButtons();
}

RiskCompanion::~RiskCompanion(){
    delete ui;
}

void RiskCompanion::signalSorter(QString button){
    if (button == "menuNewGame"){
        qDebug() << "New Game button hit";
    }

}

void RiskCompanion::connectButtons(){
    //-----------------------------------------------
    m_signalMapper->setMapping(
                ui->menuNewGameButton, "menuNewGameButton");
    connect(ui->menuNewGameButton, SIGNAL(clicked()),
            m_signalMapper, SLOT(map()));
    //-----------------------------------------------
    m_signalMapper->setMapping(
                ui->menuLoadGameButton, "menuLoadGameButton");
    connect(ui->menuLoadGameButton, SIGNAL(clicked()),
            m_signalMapper, SLOT(map()));
    //-----------------------------------------------
    m_signalMapper->setMapping(
                ui->menu, "menuSettingsButton");
    connect(ui->menuSettingsButton, SIGNAL(clicked()),
            m_signalMapper, SLOT(map()));
    //-----------------------------------------------
    m_signalMapper->setMapping(
                ui->menuExitButton, "menuExitButton");
    connect(ui->menuExitButton, SIGNAL(clicked()),
            m_signalMapper, SLOT(map()));
    //-----------------------------------------------
}
