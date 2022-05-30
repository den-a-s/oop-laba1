#pragma once

#include "abstractanimal.h"
#include "myalgorithm.h"

#include <algorithm>

#include <QTextStream>

#define DOGS_DISEASE_SIZE 4
#define DOGS_BREEDS_SIZE 9

const static QString dogsDisease[DOGS_DISEASE_SIZE] {
    QString::fromLocal8Bit("Бешенство"),
    QString::fromLocal8Bit("Лептоспироз"),
    QString::fromLocal8Bit("Вольерный кашель"),
    QString::fromLocal8Bit("Болезнь Карре")
};
const static QString dogsBreeds[DOGS_BREEDS_SIZE] {
    QString::fromLocal8Bit("Алабай"),
    QString::fromLocal8Bit("Хаски"),
    QString::fromLocal8Bit("Бульдог"),
    QString::fromLocal8Bit("Боксер"),
    QString::fromLocal8Bit("Корги"),
    QString::fromLocal8Bit("Мопс"),
    QString::fromLocal8Bit("Питбуль"),
    QString::fromLocal8Bit("Спаниель"),
    QString::fromLocal8Bit("Чихуахуа")
};

// Конкретная реализация абстрактного животного
class Dog: public AbstractAnimal {
public:
    // Конструктор по умолчанию
    Dog();

    // Конструктор с параметрами
    Dog(const QString &name, int breed, int disease);

    // Конструктор копирования
    Dog(const Dog &cat);

    // Оператор присваивания
    Dog &operator=(const Dog &cat);

    // Перегрузка конструктора абстрактного животного
    ~Dog() override;

    void read(const QJsonObject &json) override;

    void write(QJsonObject &json) const override;

    void setName(const QString &newName) override;

    void setBreed(int newBreed) override;

    void setDisease(int newDisease) override;

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
