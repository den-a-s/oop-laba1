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

void PatientData::print() const
{
    for (const auto &item: m_patients) {
        item->print();
        QTextStream(stdout) << '\n';
    }
}

void PatientData::load()
{
    QString path = QStandardPaths::locate(QStandardPaths::HomeLocation, "patiens_data.json");
    QFile loadFile(path);
    if (!loadFile.exists()) throw "Bruh";
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
        throw "Bruh";
    }
    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    readPatients(loadDoc.object());
}

void PatientData::readPatients(const QJsonObject &json)
{
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

AbstractAnimal *PatientData::getAnimal(const QJsonObject &json)
{
    AbstractAnimal *animal = nullptr;
    if (json.contains("who") && json["who"] == "cat")
        animal = new Cat();
    else if (json.contains("who") && json["who"] == "dog")
        animal = new Dog();
    if (animal != nullptr) animal->read(json);
    return animal;
}
