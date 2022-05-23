#include "dog.h"

Dog::Dog()
{}

Dog::Dog(const QString &name,  int breed, int disease)
    :m_name(name), m_breed(breed), m_disease(disease)
{}

Dog::Dog(const Dog &cat)
{
    m_name = cat.m_name;
    m_breed = cat.m_breed;
    m_disease = cat.m_disease;
}

Dog &Dog::operator=(const Dog &cat)
{
    if (this != &cat) {
        m_name = cat.m_name;
        m_breed = cat.m_breed;
        m_disease = cat.m_disease;
    }
    return *this;
}

Dog::~Dog()
{}

void Dog::read(const QJsonObject &json)
{
    if (json.contains("name") && json["name"].isString()) {
        m_name = json["name"].toString();
    }
    if (json.contains("breed") && json["breed"].isString()) {
        QString tmpBreed = json["name"].toString();
        m_breed = findIdx(tmpBreed, dogsBreeds, DOGS_BREEDS_SIZE);
    }
    if (json.contains("disease") && json["disease"].isString()) {
        QString tmpDisease = json["disease"].toString();
        m_disease = findIdx(tmpDisease, dogsDisease, DOGS_DISEASE_SIZE);
    }
}

void Dog::setName(const QString &newName)
{
    m_name = newName;
}

void Dog::setBreed(int newBreed)
{
    m_breed = newBreed;
}

void Dog::setDisease(int newDisease)
{
    m_disease = newDisease;
}

void Dog::print() const
{
    QTextStream out(stdout);

    out << m_name << ":" << m_breed << ":" << m_disease;
}


