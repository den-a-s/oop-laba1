#include "cat.h"

Cat::Cat()
{}

Cat::Cat(const QString &name,  int breed, int disease)
    :m_name(name), m_breed(breed), m_disease(disease)
{}

Cat::Cat(const Cat &cat)
{
    m_name = cat.m_name;
    m_breed = cat.m_breed;
    m_disease = cat.m_disease;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this != &cat) {
        m_name = cat.m_name;
        m_breed = cat.m_breed;
        m_disease = cat.m_disease;
    }
    return *this;
}

Cat::~Cat()
{}

void Cat::read(const QJsonObject &json)
{
    if (json.contains("name") && json["name"].isString()) {
        m_name = json["name"].toString();
    }
    if (json.contains("breed") && json["breed"].isString()) {
        QString tmpBreed = json["name"].toString();
        m_breed = findIdx(tmpBreed, catsBreeds, CATS_BREEDS_SIZE);
    }
    if (json.contains("disease") && json["disease"].isString()) {
        QString tmpDisease = json["disease"].toString();
        m_disease = findIdx(tmpDisease, catsDisease, CATS_DISEASE_SIZE);
    }
}

void Cat::setName(const QString &newName)
{
    m_name = newName;
}

void Cat::setBreed(int newBreed)
{
    m_breed = newBreed;
}

void Cat::setDisease(int newDisease)
{
    m_disease = newDisease;
}

void Cat::print() const
{
    QTextStream out(stdout);

    out << m_name << ":" << m_breed << ":" << m_disease;
}


