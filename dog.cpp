#include "dog.h"

// По умолчанию ставятся такие параметры
Dog::Dog()
    :m_name("Dog"), m_breed(0), m_disease(0)
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

// Так как нет сырых указателей, не надо вручную очищать память
Dog::~Dog()
{}

void Dog::read(const QJsonObject &json)
{
    if (json.contains("name") && json["name"].isString()) {
        m_name = json["name"].toString();
    }
    // Так как внутри класса данные хранятся в виде индекса на массив
    // а в файле в виде строки идёт конвертация
    if (json.contains("breed") && json["breed"].isString()) {
        QString tmpBreed = json["breed"].toString();
        m_breed = findIdx(tmpBreed, dogsBreeds, DOGS_BREEDS_SIZE);
    }
    // Так как внутри класса данные хранятся в виде индекса на массив
    // а в файле в виде строки идёт конвертация
    if (json.contains("disease") && json["disease"].isString()) {
        QString tmpDisease = json["disease"].toString();
        m_disease = findIdx(tmpDisease, dogsDisease, DOGS_DISEASE_SIZE);
    }
}

void Dog::write(QJsonObject &json) const
{
    json["who"] = "dog";
    json["name"] = m_name;
    // Так как внутри класса данные хранятся в виде индекса на массив
    // а в файле в виде строки идёт конвертация
    json["breed"] = dogsBreeds[m_breed];
    // Так как внутри класса данные хранятся в виде индекса на массив
    // а в файле в виде строки идёт конвертация
    json["disease"] = dogsDisease[m_disease];
}

void Dog::setName(const QString &newName)
{
    m_name = newName;
}

// Установка породы с валидацией
void Dog::setBreed(int newBreed)
{
    validateBreed(newBreed);
    m_breed = newBreed;
}

// Установка болезни с валидацией
void Dog::setDisease(int newDisease)
{
    validateDisease(newDisease);
    m_disease = newDisease;
}

void Dog::print() const
{
    QTextStream out(stdout);

    out << m_name << " -- " << dogsBreeds[m_breed] << " -- " << dogsDisease[m_disease];
}

void Dog::printBreeds()
{
    QTextStream out(stdout);
    for (int i = 0; i < DOGS_BREEDS_SIZE; ++i){
        out << QString::number(i + 1) + ". "<< dogsBreeds[i] << Qt::endl;
    }
}

void Dog::printDisease()
{
    QTextStream out(stdout);
    for (int i = 0; i < DOGS_DISEASE_SIZE; ++i){
        out << QString::number(i + 1) + ". "<< dogsDisease[i] << Qt::endl;
    }
}

void Dog::validateBreed(int breed)
{
    Q_ASSERT(0 <= breed && breed < DOGS_BREEDS_SIZE);
}

void Dog::validateDisease(int disease)
{
    Q_ASSERT(0 <= disease && disease < DOGS_DISEASE_SIZE);
}

