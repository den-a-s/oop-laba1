#pragma once

#include <string>
#include <iostream>

#include <QJsonObject>

class AbstractAnimal {
public:
    virtual void read(const QJsonObject &json) = 0;

    virtual void setName(const QString &newName) = 0;

    virtual void setBreed(int newBreed) = 0;

    virtual void setDisease(int newDisease) = 0;

    virtual void print() = 0;

    virtual ~AbstractAnimal() = 0;
};
