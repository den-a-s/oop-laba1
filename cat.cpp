#include "cat.h"

// По умолчанию ставится такие параметры
Cat::Cat()
    :m_name("Cat"), m_breed(0), m_disease(0)
{}

Cat::Cat(const QString &name,  int breed, int disease)
    // Список инициализации
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

// Так как нет сырых указателей, не надо вручную очищать память
Cat::~Cat()
{}

void Cat::read(const QJsonObject &json)
{
    if (json.contains("name") && json["name"].isString()) {
        m_name = json["name"].toString();
    }
    // Так как внутри класса данные хранятся в виде индекса на массив
    // а в файле в виде строки идёт конвертация
    if (json.contains("breed") && json["breed"].isString()) {
        QString tmpBreed = json["breed"].toString();
        m_breed = findIdx(tmpBreed, catsBreeds, CATS_BREEDS_SIZE);
    }
    // Так как внутри класса данные хранятся в виде индекса на массив
    // а в файле в виде строки идёт конвертация
    if (json.contains("disease") && json["disease"].isString()) {
        QString tmpDisease = json["disease"].toString();
        m_disease = findIdx(tmpDisease, catsDisease, CATS_DISEASE_SIZE);
    }
}

void Cat::write(QJsonObject &json) const
{
    json["who"] = "cat";
    json["name"] = m_name;
    // Так как внутри класса данные хранятся в виде индекса на массив
    // а в файле в виде строки идёт конвертация
    json["breed"] = catsBreeds[m_breed];
    // Так как внутри класса данные хранятся в виде индекса на массив
    // а в файле в виде строки идёт конвертация
    json["disease"] = catsDisease[m_disease];
}

void Cat::setName(const QString &newName)
{
    m_name = newName;
}

// Установка породы с валидацией
void Cat::setBreed(int newBreed)
{
    validateBreed(newBreed);
    m_breed = newBreed;
}

// Установка болезни с валидацией
void Cat::setDisease(int newDisease)
{
    validateDisease(newDisease);
    m_disease = newDisease;
}

void Cat::print() const
{
    // Поток вывода в Qt
    QTextStream (stdout) << m_name << " -- " << catsBreeds[m_breed] << " -- " << catsDisease[m_disease];
}

void Cat::printBreeds()
{
    // Поток вывода в Qt
    QTextStream out(stdout);
    for (int i = 0; i < CATS_BREEDS_SIZE; ++i){
        out << QString::number(i + 1) + ". "<< catsBreeds[i] << Qt::endl;
    }
}

void Cat::printDisease()
{
    QTextStream out(stdout);
    for (int i = 0; i < CATS_DISEASE_SIZE; ++i){
        out << QString::number(i + 1) + ". "<< catsDisease[i] << Qt::endl;
    }
}

void Cat::validateBreed(int breed)
{
    Q_ASSERT(0 <= breed && breed < CATS_BREEDS_SIZE);
}

void Cat::validateDisease(int disease)
{
    Q_ASSERT(0 <= disease && disease < CATS_DISEASE_SIZE);
}


