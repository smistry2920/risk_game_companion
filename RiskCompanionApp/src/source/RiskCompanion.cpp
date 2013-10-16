#include "../header/RiskCompanion.h"
#include "ui_RiskCompanion.h"

RiskCompanion::RiskCompanion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RiskCompanion){
    ui->setupUi(this);
}

RiskCompanion::~RiskCompanion(){
    delete ui;
}

void RiskCompanion::signalSorter(const QString &){

}
