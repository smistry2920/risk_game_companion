#include "../header/RiskCompanion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RiskCompanion w;
    w.show();

    return a.exec();
}
