#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "render.h"
#include "worldbuilder.h"
#include "objectscreator.h"
#include "movementcontroller.h"
#include "physicalobject.h"

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

    public:
        void startGame(QGraphicsView * graphicsView);
        void stopGame();
        void createDemoLevel();
        void gameProcess(bool w, bool a, bool d);
        void addWall(int i, int j);
        physicalObject * addObject(int xx, int yy, int ww, int hh, int acceleration, int speedX, int speedY);
        void buildFirstLevel();
};

#endif // GAMEMANAGER_H
