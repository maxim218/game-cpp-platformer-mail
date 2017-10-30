#include "gamemanager.h"

void GameManager::startGame(QGraphicsView * graphicsView) {
    const int sceneWidth = 800;
    const int sceneHeight = 600;

    kvX = 400;
    kvY = 25;

    renderObject = new Render(graphicsView, sceneWidth, sceneHeight);
    worldBuilder = new WorldBuilder(renderObject, kvX, kvY);
    objectsCreator = new ObjectsCreator(renderObject);
    movementController = new MovementController(objectsCreator->getPointerToList(), kvX, kvY);

    buildFirstLevel();

    worldBuilder->copyMap(movementController);
    worldBuilder->printMap();
    objectsCreator->printAllObjects();
}

void GameManager::addWall(int i, int j) {
    worldBuilder->createWall(i, j);
}

physicalObject *  GameManager::addObject(int xx, int yy, int ww, int hh, int acceleration, int speedX, int speedY) {
    return objectsCreator->addPhysicalObject(xx, yy, ww, hh, acceleration, speedX, speedY);
}

void GameManager::gameProcess(bool w, bool a, bool d){
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

void GameManager::buildFirstLevel() {
    for(int i = 0; i < kvY; i++) {
        addWall(i,0);
        addWall(i, kvX - 1);
    }

    for(int i = 0; i < kvX; i++){
        addWall(0, i);
        addWall(kvY - 1, i);
    }

    hero = addObject(100,60, 40, 40, 1, 0, 0);
}

