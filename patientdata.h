#pragma once
#include <iostream>
#include <vector>
#include <string>

#include <QStandardPaths>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "cat.h"
#include "dog.h"

// Класс в котором хранятся все данные
// Сделан в виде синглтона
class PatientData
{
public:
    PatientData(const PatientData&) = delete;
    void operator=(const PatientData&) = delete;

    // функция через которую можно вызывать единственный экземпляр класса
    static PatientData& instance();

    void addPatient();

    // Печать всех пациентов
    void print() const;

    // сохраниение в файл
    void load();

    // удаление из файла
    void save();
private:
    enum Animal{
        Cat,
        Dog
    };
    // Валидация введённого животного
    Animal getAnimalEnum(const QString &animal) const;

    // Чтение пациентов из json
    void readPatients(const QJsonObject &json);

    // Запись пациентов в json
    void writePatients(QJsonObject &json);

    // Получение животного из json
    AbstractAnimal *getAnimal(const QJsonObject &json);

    // Получение животного из введённого животного
    AbstractAnimal *getAnimal(Animal animal);

    // Выбор породы животного
    int chooseBreeds(Animal animal);

    // Выбор болезни животного
    int chooseDisease(Animal animal);

    // Конструктор
    PatientData();

    // Деструктор
    ~PatientData();
    std::vector<AbstractAnimal*> m_patients;
};
