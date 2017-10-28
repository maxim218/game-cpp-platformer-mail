#include "gamemanager.h"

void GameManager::startGame(QGraphicsView * graphicsView) {
    const int sceneWidth = 800;
    const int sceneHeight = 600;

    const int kvX = 40;
    const int kvY = 30;

    renderObject = new Render(graphicsView, sceneWidth, sceneHeight);
    worldBuilder = new WorldBuilder(renderObject, kvX, kvY);
    objectsCreator = new ObjectsCreator(renderObject);
    movementController = new MovementController(objectsCreator->getPointerToList(), kvX, kvY);
}

void GameManager::createDemoLevel() {
    for(int i = 2; i <= 9; i++){
        worldBuilder->createWall(7,i);
        worldBuilder->createWall(7,30 - i - 1);
        worldBuilder->createWall(12,i + 7);
    }

    for(int i = 7; i <= 12; i++){
        worldBuilder->createWall(i, 9);
    }

    for(int i = 0; i < 40; i++){
        worldBuilder->createWall(24,i);
        worldBuilder->createWall(0,i);
    }

    for(int i = 0; i < 25; i++){
        worldBuilder->createWall(i,0);
        worldBuilder->createWall(i, 39);
    }

    objectsCreator->addPhysicalObject(100,40,30,30,1,2,0);
    objectsCreator->addPhysicalObject(200,40,30,30,1,4,-5);
    objectsCreator->addPhysicalObject(500,40,30,30,1,-5,-2);

    worldBuilder->copyMap(movementController);
    worldBuilder->printMap();
    objectsCreator->printAllObjects();
}

void GameManager::gameProcess(){
    movementController->moveAllObjects();
    worldBuilder->printMap();
    objectsCreator->printAllObjects();
}

void GameManager::stopGame() {
    delete renderObject;
    delete worldBuilder;
    delete objectsCreator;
    delete movementController;
}

