#ifndef FACTORYOFFILELOADERS
#define FACTORYOFFILELOADERS

#include <objectscreator.h>
#include "QFile"
#include "QTextStream"
#include "physicalobject.h"
#include "worldbuilder.h"
#include "QDebug"
#include "fileloader.h"
#include "maploader.h"
#include "thingloader.h"

// класс для создания экземпляров объектов загрузчиков из файла (фабрика)
class FactoryOfFileLoaders {
    public:
        // метод для получения экземпляра класса загрузчика карты
        FileLoader * getMapLoader() {
            FileLoader * loader = new MapLoader();
            return loader;
        }

        // метод для получения экземпляра класса загрузчика персонажей игры
        FileLoader * getThingLoader() {
            FileLoader * loader = new ThingLoader();
            return loader;
        }
};

#endif // FACTORYOFFILELOADERS

