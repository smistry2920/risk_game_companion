#include "../header/Logger.h"

Logger::Logger(QString filename){
    m_file = new QFile(filename);
    m_file->open(QIODevice::ReadWrite | QIODevice::Text);
    m_input = new QTextStream(m_file);
}

Logger::~Logger(){
    delete &m_file;
    delete &m_input;
}

void Logger::close(){
    m_input->flush();
    m_file->close();
}

bool Logger::writeList2File(QStringList datalist){
    for (int i = 0; i<datalist.size(); ++i){
        *m_input << datalist[i] << endl;
    }
    return true;
}

bool Logger::write2File(QString data){
    *m_input << data << endl;
    return true;
}

QString Logger::viewLog(){
    m_input->flush();
    QString data;
    while(!m_input->atEnd()){
        data +=m_input->readLine();
    }
    return m_input->readAll();
}
