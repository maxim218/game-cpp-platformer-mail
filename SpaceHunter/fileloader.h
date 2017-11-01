#ifndef FILELOADER
#define FILELOADER

#include "QFile"
#include "QTextStream"
#include "QDebug"

#include "objectscreator.h"
#include "physicalobject.h"
#include "worldbuilder.h"

// класс с виртуальными методами для загрузки данных из файла
class FileLoader
{
    public:
        // виртуальный метод для чтение клеток из файла и добавление их в игру
        void virtual makeLoadOfMap(QString fileName, WorldBuilder * worldBuilder) {}
        // виртуальный метод для чтения положения объектов из файла и добавления их в игру
        void virtual makeLoadOfThings(QString fileName, ObjectsCreator * objectsCreator) {}
};

#endif // FILELOADER

