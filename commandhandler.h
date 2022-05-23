#pragma once

#include "patientdata.h"

class CommandHandler
{
public:
    CommandHandler();
    void handle();
private:
    void help();

    enum Command {
        Print = 1
    };
};
