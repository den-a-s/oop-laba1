#include "commandhandler.h"

CommandHandler::CommandHandler()
{
    PatientData::instance().load();
}

void CommandHandler::handle()
{
    help();
    int cmd = -1;
    QTextStream(stdin) >> cmd;
    switch (cmd) {
    case CommandHandler::Command::Print:
        PatientData::instance().print();
        break;
    default:
        QTextStream(stdout) << QString::fromLocal8Bit("Такой комманды нет.");
    }
}

void CommandHandler::help()
{
    QTextStream(stdout) <<
            QString::fromLocal8Bit("Комманды: \n") <<
            QString::fromLocal8Bit("1: Распечатать данные о пациентах. \n");
}
