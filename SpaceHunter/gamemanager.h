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

class GameManager
{
    private:
        Render * renderObject;
        WorldBuilder * worldBuilder;
        ObjectsCreator * objectsCreator;
        MovementController * movementController;

        int kvX;
        int kvY;

        physicalObject * hero;

        void buildPerimetrWalls();

    public:
        void startGame(QGraphicsView * graphicsView);
        void stopGame();
        void createDemoLevel();
        void gameProcess(bool &w, bool &a, bool &d);
        void addWall(int i, int j);
        physicalObject * addObject(int xx, int yy, int ww, int hh, int acceleration, int speedX, int speedY);
        void buildFirstLevel();
        void fire(int xxx, int yyy);
};

#endif // GAMEMANAGER_H
