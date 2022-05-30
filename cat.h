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

// Конкретная реализация абстрактного животного
class Cat: public AbstractAnimal {
public:
    // Конструктор по умолчанию
    Cat();

    // Конструктор с параметрами
    Cat(const QString &name, int breed, int disease);

    // Конструктор копирования
    Cat(const Cat &cat);

    // Оператор присваивания
    Cat &operator=(const Cat &cat);

    // Перегрузка конструктора абстрактного животного
    ~Cat() override;

    // Чтение животного из json
    void read(const QJsonObject &json) override;

    // Чтение животного в json
    void write(QJsonObject &json) const override;

    // Сеттер имени
    void setName(const QString &newName) override;

    // Сеттер породы
    void setBreed(int newBreed) override;

    // Сеттер болезни
    void setDisease(int newDisease) override;

    // Печать животного
    void print() const override;

    // Печать пронумерованного списка пород кошек
    static void printBreeds();

    // Печать пронумерованного списка пород собак
    static void printDisease();

private:

    // Валидация породы
    void validateBreed(int breed);

    // Валидация болезни
    void validateDisease(int disease);

    QString m_name;
    int m_breed;
    int m_disease;
};
