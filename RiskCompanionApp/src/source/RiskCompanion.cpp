#include "../header/RiskCompanion.h"

RiskCompanion::RiskCompanion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RiskCompanion){

    ui->setupUi(this);

    m_signalMapper = new QSignalMapper(this);
    connect(m_signalMapper, SIGNAL(mapped(QString)),this, SLOT(signalSorter(QString)));

    connectButtons();

    m_logger = new Logger("../text.txt");
}

RiskCompanion::~RiskCompanion(){
    delete ui;
}

void RiskCompanion::signalSorter(QString button){
    if (button == "menuNewGameButton"){
        qDebug() << "New Game button hit";
        m_logger->write2File("New Game button hit");
    }
    else if (button == "menuSettingsButton"){
        qDebug() << "settings";
        QString data =  m_logger->viewLog();
        qDebug() << data;
    }
    else if (button == "menuLoadGameButton"){
        m_logger->write2File("load");
        qDebug() << "load";
    }
    else if (button == "menuExitButton"){
        qDebug() << "exiting";
        m_logger->write2File("exiting now...");
        m_logger->close();
    }
    else{
        qDebug() << "never here! whoops";
        m_logger->write2File("error");
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
                ui->menuSettingsButton, "menuSettingsButton");
    connect(ui->menuSettingsButton, SIGNAL(clicked()),
            m_signalMapper, SLOT(map()));
    //-----------------------------------------------
    m_signalMapper->setMapping(
                ui->menuExitButton, "menuExitButton");
    connect(ui->menuExitButton, SIGNAL(clicked()),
            m_signalMapper, SLOT(map()));
    //-----------------------------------------------
}
