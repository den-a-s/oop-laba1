#pragma once

#include "patientdata.h"

// Класс который обрабатывает команды.
class CommandHandler
{
public:
    // Конструктор
    CommandHandler();

    void handle();
private:
    bool choiseCommand();

    void help();

    // Перечисление для команд
    enum Command {
        Print = 1,
        Add = 2,
        Exit
    };
};
