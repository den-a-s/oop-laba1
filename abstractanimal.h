#pragma once

#include <string>
#include <iostream>

#include <QJsonObject>

// Абстрактный класс животного
class AbstractAnimal {
public:

    // Чтение животного из json
    virtual void read(const QJsonObject &json) = 0;

    // Чтение животного в json
    virtual void write(QJsonObject &json) const = 0;

    // Сеттер имени
    virtual void setName(const QString &newName) = 0;

    // Сеттер породы
    virtual void setBreed(int newBreed) = 0;

    // Сеттер болезни
    virtual void setDisease(int newDisease) = 0;

    // Печать животного
    virtual void print() const = 0;

    // Абстрактный деструктор
    virtual ~AbstractAnimal(){};
};
