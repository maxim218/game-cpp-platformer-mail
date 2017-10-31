#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "render.h"
#include "worldbuilder.h"
#include "objectscreator.h"
#include "movementcontroller.h"
#include "physicalobject.h"
#include "QKeyEvent"
#include "maploader.h"
#include <math.h>
#include "thingloader.h"

// класс для управления процессом игры
class GameManager
{
    private:
        // объект для отображения элементов игры
        Render * renderObject;
        // объект для взаимодействия с картой
        WorldBuilder * worldBuilder;
        // объект для создания и удаления элементов игры
        ObjectsCreator * objectsCreator;
        // объект для работы с движением элементов игры
        MovementController * movementController;
        // размер игрового поля в клетках
        int kvX;
        int kvY;
        // указатель на героя игры
        physicalObject * hero;
        // метод для создания ограждений по периметру уровня
        void buildPerimetrWalls();

    public:
        // метод для начала игры
        void startGame(QGraphicsView * graphicsView, int levelNumber);
        // метод для окончания игры
        void stopGame();
        // метод (вызывается циклически) для реализация всех циклических действий в игре
        int gameProcess(bool &w, bool &a, bool &d);
        // метод для добавления стены
        void addWall(int i, int j);
        // метод для создания физического объекта в игре
        physicalObject * addObject(int xx, int yy, int ww, int hh, int acceleration, int speedX, int speedY, QString type);
        // построения уровня
        void buildLevel(int levelNumber);
        // реализация стрельбы героя
        void fire(int xxx, int yyy);
        // проверка на столкновение двух объектов
        bool hitTest(physicalObject * a, physicalObject * b);
};

#endif // GAMEMANAGER_H
