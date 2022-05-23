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

class PatientData
{
public:
    PatientData(const PatientData&) = delete;
    void operator=(const PatientData&) = delete;
    static PatientData& instance();

    void print() const;
    void load();
private:
    void readPatients(const QJsonObject &json);
    AbstractAnimal *getAnimal(const QJsonObject &json);
    PatientData();
    ~PatientData();
    std::vector<AbstractAnimal*> m_patients;
};
