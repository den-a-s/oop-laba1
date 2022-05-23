#pragma once

#include "abstractanimal.h"
#include "myalgorithm.h"

#include <algorithm>

#include <QTextStream>

#define CATS_DISEASE_SIZE 4
#define CATS_BREEDS_SIZE 7

const static QString catsDisease[CATS_DISEASE_SIZE] {
    QString::fromLocal8Bit("Бешенство"),
    QString::fromLocal8Bit("Хламидиоз"),
    QString::fromLocal8Bit("Коронавирусная инфекция"),
    QString::fromLocal8Bit("Микоплазмоз")
};
const static QString catsBreeds[CATS_BREEDS_SIZE] {
    QString::fromLocal8Bit("Мейн-кун"),
    QString::fromLocal8Bit("Британская короткошерстная"),
    QString::fromLocal8Bit("Сиамская кошка"),
    QString::fromLocal8Bit("Русская голубая"),
    QString::fromLocal8Bit("Невская маскарадная"),
    QString::fromLocal8Bit("Сфинкс"),
    QString::fromLocal8Bit("Гималайская")
};

class Cat: public AbstractAnimal {
public:
    Cat();
    Cat(const QString &name, int breed, int disease);
    Cat(const Cat &cat);
    Cat &operator=(const Cat &cat);
    ~Cat();

    void read(const QJsonObject &json) override;

    void setName(const QString &newName) override;

    void setBreed(int newBreed) override;

    void setDisease(int newDisease) override;

    void print() const override;

private:
    QString m_name;
    int m_breed;
    int m_disease;
};
