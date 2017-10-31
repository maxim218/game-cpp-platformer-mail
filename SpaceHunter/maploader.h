#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "QFile"
#include "QTextStream"
#include "worldbuilder.h"
#include "QDebug"

// класс для чтения карты игры из файла
class MapLoader
{
    public:
        // конструктор, в котором происходит чтение клеток из файла и добавление их в игру
        MapLoader(QString fileName, WorldBuilder * worldBuilder);
};

#endif // MAPLOADER_H
