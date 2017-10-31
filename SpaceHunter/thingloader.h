#ifndef THINGLOADER_H
#define THINGLOADER_H

#include <objectscreator.h>
#include "QFile"
#include "QTextStream"
#include "physicalobject.h"

// класс для загрузки положения монстров и других объектов из файла
class ThingLoader
{
    public:
        // конструктор для чтения положения объектов из файла и добавления их в игру
        ThingLoader(QString fileName, ObjectsCreator * objectsCreator);
};

#endif // THINGLOADER_H
