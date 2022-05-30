#include "commandhandler.h"

CommandHandler::CommandHandler()
{
    // Загрузка данных из json-файла
    PatientData::instance().load();
}

void CommandHandler::handle()
{
    // В цикле крутится обработка команд
    while(choiseCommand());
    // В конце цикла сохраняются изменения в файл
    PatientData::instance().save();
}

bool CommandHandler::choiseCommand()
{
    help();
    QTextStream(stdout) << QString::fromLocal8Bit("Введите команду:") << Qt::endl;
    int cmd = 0;
    QTextStream(stdin) >> cmd;
    // Обработка введённой команды в соотвествии с перечислением
    switch (cmd) {
    case CommandHandler::Print:
        PatientData::instance().print();
        break;
    case CommandHandler::Add:
        PatientData::instance().addPatient();
        break;
    case CommandHandler::Exit:
        return false; // конец цикла
    default:
        QTextStream(stdout) << QString::fromLocal8Bit("Такой комманды нет.") << Qt::endl;
    }
    return true;
}

void CommandHandler::help()
{
    // Все команды
    QTextStream(stdout) <<
            QString::fromLocal8Bit("_____________________________________") << Qt::endl <<
            QString::fromLocal8Bit("Комманды: ")                            << Qt::endl <<
            QString::fromLocal8Bit("1: Распечатать данные о пациентах. ")   << Qt::endl <<
            QString::fromLocal8Bit("2: Добавить нового пациента. ")         << Qt::endl <<
            QString::fromLocal8Bit("3: Выход")                              << Qt::endl <<
            QString::fromLocal8Bit("_____________________________________") << Qt::endl;
}
