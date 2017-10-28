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

    public:
        void startGame(QGraphicsView * graphicsView);
        void stopGame();
        void createDemoLevel();
        void gameProcess();
};

#endif // GAMEMANAGER_H
