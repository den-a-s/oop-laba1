#include "patientdata.h"

PatientData::PatientData()
{}

PatientData::~PatientData()
{
    for (const auto &item: m_patients) {
        delete item;
    }
}

PatientData &PatientData::instance()
{
    static PatientData inst;
    return inst;
}

void PatientData::addPatient()
{
    // Поток ввода Qt
    QTextStream in(stdin);
    QTextStream (stdout) << QString::fromLocal8Bit("Выберите животное: (кот/собака)");
    QString who;
    in >> who;
    // Выясняем какое животное
    PatientData::Animal animal = getAnimalEnum(who);
    // Получаем конкретное животное
    AbstractAnimal *abstractAnimal = getAnimal(animal);
    if (abstractAnimal == nullptr) throw "Animal error";
    // Установка имени
    QTextStream (stdout) << QString::fromLocal8Bit("Введите имя: ") << Qt::endl;
    QString name;
    in >> name;
    abstractAnimal->setName(name);
    // Выбор породы, установка породы
    QTextStream (stdout) << QString::fromLocal8Bit("Выберите породу: ") << Qt::endl;
    int idx_breed = chooseBreeds(animal);
    abstractAnimal->setBreed(idx_breed);
    // Выбор болезни, установка болезни
    QTextStream (stdout) << QString::fromLocal8Bit("Выберите болезнь: ") << Qt::endl;
    int idx_disease = chooseDisease(animal);
    abstractAnimal->setDisease(idx_disease);
    // Добавление нового пациента к остальным
    m_patients.push_back(abstractAnimal);
    QTextStream (stdout) << name << QString::fromLocal8Bit(" добавлен.") << Qt::endl;
}

void PatientData::print() const
{
    for (const auto &item: m_patients) {
        item->print();
        QTextStream(stdout) << '\n';
    }
}

void PatientData::load()
{
    // Получение относительного пути к домашней директории (в линукс ~/<Имя пользователя>/. )
    QString path = QStandardPaths::locate(QStandardPaths::HomeLocation, "patients_data.json");
    // Файл по этому пути
    QFile loadFile(path);
    // Проверка на существование файла
    if (!loadFile.exists()) throw "Bruh";
    // Проверка на открытие файла с модификатором "только чтение"
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
        throw "Bruh";
    }
    // Чтение файла в битовый массив
    QByteArray saveData = loadFile.readAll();
    // Чтение json документа из битового массива
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    // Чтение полей json
    readPatients(loadDoc.object());
}

void PatientData::save()
{
    // Получение относительного пути к домашней директории (в линукс ~/<Имя пользователя>/. )
    QString path = QStandardPaths::locate(QStandardPaths::HomeLocation, "patients_data.json");
    // Файл по этому пути
    QFile saveFile(path);
    // Проверка на существование файла
    if (!saveFile.exists()) throw "Bruh";
    // Проверка на открытие файла с модификатором "только запись"
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open file.");
        throw "Bruh";
    }
    QJsonObject patientsObject;
    // Запись данных пациентов в json
    writePatients(patientsObject);
    // запись json в файл
    saveFile.write(QJsonDocument(patientsObject).toJson());
}

PatientData::Animal PatientData::getAnimalEnum(const QString &animal) const
{
    bool isCat = animal == QString::fromLocal8Bit("кот");
    bool isDog = animal == QString::fromLocal8Bit("собака");
    Q_ASSERT(isCat || isDog);
    if (isCat) return PatientData::Animal::Cat;
    return PatientData::Animal::Dog;
}

void PatientData::readPatients(const QJsonObject &json)
{
    // чтение массива пациентов из json
    if (json.contains("patients") && json["patients"].isArray()) {
        QJsonArray patients = json["patients"].toArray();
        m_patients.clear();
        m_patients.reserve(patients.size());
        for (const auto &item: patients) {
            AbstractAnimal* animal = getAnimal(item.toObject());
            m_patients.push_back(animal);
        }
    }
}

void PatientData::writePatients(QJsonObject &json)
{
    // Сохраниение массива пациентов в json
    QJsonArray patients;
    for (const auto &item : m_patients) {
        QJsonObject patient;
        item->write(patient);
        patients.append(patient);
    }
    json["patients"] = patients;
}

AbstractAnimal *PatientData::getAnimal(const QJsonObject &json)
{
    AbstractAnimal *tmp = nullptr;
    if (json.contains("who") && json["who"] == "cat")
        tmp = new class Cat();
    else if (json.contains("who") && json["who"] == "dog")
        tmp = new class Dog();
    if (tmp != nullptr) tmp->read(json);
    return tmp;
}

AbstractAnimal *PatientData::getAnimal(Animal animal)
{
    AbstractAnimal *tmp = nullptr;
    switch(animal) {
    case PatientData::Animal::Cat:
        tmp = new class Cat();
        break;
    case PatientData::Animal::Dog:
        tmp = new class Dog();
        break;
    }
    return tmp;
}

int PatientData::chooseBreeds(Animal animal)
{
    if (animal == PatientData::Cat)
        Cat::printBreeds();
    if (animal == PatientData::Dog)
        Dog::printBreeds();
    int idx_breed = -1;
    QTextStream(stdin) >> idx_breed;
    return idx_breed - 1;
}

int PatientData::chooseDisease(Animal animal)
{
    if (animal == PatientData::Cat)
        Cat::printDisease();
    if (animal == PatientData::Dog)
        Dog::printDisease();
    int idx_breed = -1;
    QTextStream(stdin) >> idx_breed;
    return idx_breed - 1;
}
