#include "gamemanager.h"

// метод для начала игры
void GameManager::startGame(QGraphicsView * graphicsView, int levelNumber) {
    // задаём размеры холста
    const int sceneWidth = 800;
    const int sceneHeight = 600;

    // задаём размер игрового поля в клетках
    kvX = 400;
    kvY = 200;

    // создаём экземпляры объектов для работы с отображением, картой, созданием объектов и их движением
    renderObject = new Render(graphicsView, sceneWidth, sceneHeight);
    worldBuilder = new WorldBuilder(renderObject, kvX, kvY);
    objectsCreator = new ObjectsCreator(renderObject);
    movementController = new MovementController(objectsCreator->getPointerToList(), kvX, kvY);

    // создаём уровень под определённым номером
    buildLevel(levelNumber);

    // передаём карту объекту, отвечающему за движение
    worldBuilder->copyMap(movementController);
    worldBuilder->printMap(0, 0);
    objectsCreator->printAllObjects(0, 0);
}

// метод для добавления стены
void GameManager::addWall(int i, int j) {
    // добавляем стену
    worldBuilder->createWall(i, j);
}

// метод для создания физического объекта
physicalObject * GameManager::addObject(int xx, int yy, int ww, int hh, int acceleration, int speedX, int speedY, QString type) {
    // создаём физический объект и возвращаем указатель на него
    return objectsCreator->addPhysicalObject(xx, yy, ww, hh, acceleration, speedX, speedY, type);
}

// метод для проверки на столкновение двух объектов
bool GameManager::hitTest(physicalObject * a, physicalObject * b) {
    // получаем центр первого объекта
    int aXX = a->xx;
    int aYY = a->yy - (a->hh / 2);

    // получаем центр второго объекта
    int bXX = b->xx;
    int bYY = b->yy - (b->hh / 2);

    // получаем расстояние между центрами объектов
    int gipot = sqrt( (bXX - aXX) * (bXX - aXX) + (bYY - aYY) * (bYY - aYY) );

    // если объекты касаются друг друга
    if(  gipot <= ((a->ww + b->ww ) / 2)  ) {
        return true;
    }

    return false;
}

// игровой процесс (вызывается циклически)
int GameManager::gameProcess(bool &w, bool &a, bool &d){
    // инициализируем скорость героя
    const int speedHorizontal = 7;
    hero->speedX = 0;
    // в зависимости от действий пользователя меняем направление движения
    if(d == true) hero->speedX += speedHorizontal;
    if(a == true) hero->speedX -= speedHorizontal;
    // если пользователь нажал на W, то пытаемся прыгнуть
    if(w == true) movementController->jump(hero, -20);

    // вычисление сдвига отображения
    int dx = -400 + hero->xx;
    int dy = -320 + hero->yy;

    // реализация движения физических объектов
    movementController->moveAllObjects();
    // рисуем карту
    worldBuilder->printMap(dx, dy);
    // рисуем физические объекты
    objectsCreator->printAllObjects(dx, dy);

    // результат игры (0 - пока играем, 1 - уровень пройден, -1 - поражение)
    int gameResult = 0;

    physicalObject * v;
    v = hero;
    // пробегаемся по всем объектам
    while(v != NULL) {
        // если объект является монстром
        // если герой левее монстра, то монстр двигается влево, иначе монстр двигается вправо
        if(v->type == "thing2") {
            const int speed = 7;
            if(hero->xx < v->xx) {
                v->speedX = -speed;
            } else {
                v->speedX = speed;
            }
        }

        // если объект является монстром
        // если герой левее монстра, то монстр двигается влево, иначе монстр двигается вправо
        if(v->type == "thing3"){
            const int speed = 5;
            if(hero->xx < v->xx) {
                v->speedX = -speed;
            } else {
                v->speedX = speed;
            }
        }

        // если объект является монстром
        // если герой левее монстра, то монстр двигается влево, иначе монстр двигается вправо
        if(v->type == "thing4"){
            const int speed = 3;
            if(hero->xx < v->xx) {
                v->speedX = -speed;
            } else {
                v->speedX = speed;
            }
        }

        // если объект является монстром, то осуществляем его прыжок
        if(v->type == "thing2" || v->type == "thing3" || v->type == "thing4") {
            movementController->jump(v, -20);
        }

        // переход на следующий объект
        v = v->next;
    }

    physicalObject * p1, * p2;

    p1 = hero;
    // пробегаемся по всем объектам
    while(p1 != NULL){
        // если объект - пуля
        if(p1->type == "bullet") {
            p2 = hero;
            // пробегаемся по всем объектам
            while(p2 != NULL) {
                // если объект - монстр
                if(p2->type == "thing2" || p2->type == "thing3" || p2->type == "thing4") {
                    // если пуля касается монстра
                    if(hitTest(p1, p2) == true) {
                        // удаляем пулю
                        p1->deleted = true;
                        // уменбшаем количество жизней монстра
                        p2->nowLiveTime += 1;
                    }
                }
                // переход на следующий элемент
                p2 = p2->next;
            }
        }
        // переход на следующий элемент
        p1 = p1->next;
    }

    physicalObject * q = hero;
    // пробегаемся по всем объектам
    while(q != NULL) {
        // если объект - пуля
        if(q->type == "bullet") {
             // уменьшаем оставшееся время на существование
             q->nowLiveTime += 1;
             // если пуля исчерпала лимит жизни
             if(q->nowLiveTime >= q->maxLiveTime) {
                // удаляем пулю
                q->deleted = true;
             }
        }

        // если объект - финиш
        if(q->type == "thing7") {
            // если герой касается финиша
            if(hitTest(hero, q) == true) {
                // уровень пройден
                gameResult = 1;
            }
        }

        // если объект - монстр
        if(q->type == "thing2" || q->type == "thing3" || q->type == "thing4") {
            // если герой касается монстра
            if(hitTest(hero, q) == true) {
                // поражение
                gameResult = -1;
            }

            // если у монстра кончились жизни
            if(q->nowLiveTime >= q->maxLiveTime) {
               // удаляем монстра
               q->deleted = true;
            }
        }

        // переход на следующий элемент
        q = q->next;
    }

    // удаляем все объекты, отмеченные на удаление
    objectsCreator->deleteMarkedObjects();

    // возвращаем результат игры
    return gameResult;
}

// реализация стрельбы
void GameManager::fire(int xxx, int yyy) {
    // получаем смещение
    int dx = -400 + hero->xx;
    int dy = -320 + hero->yy;

    // создаём экземпляр пули
    physicalObject * bullet = addObject(hero->xx, hero->yy - 20 + 5, 10, 10, 0, 0, 0, "bullet");

    // задаём тип объекта
    bullet->type = "bullet";

    // задаём начальное и конечное время жизни
    bullet->nowLiveTime = 0;
    bullet->maxLiveTime = 80;

    // считаем два катета
    float cat_1 = xxx + dx - hero->xx;
    float cat_2 = yyy + dy - hero->yy;
    // считаем гипотенузу
    float gipot = sqrt(cat_1 * cat_1 + cat_2 * cat_2);

    // модуль скорости пули
    int speedBullet = 10;
    // считаем проекции скорости пули на оси X и Y
    bullet->speedX = speedBullet * cat_1 / gipot;
    bullet->speedY = speedBullet * cat_2 / gipot;
}

// завершение игры
void GameManager::stopGame() {
    // удаляем экземпляры объектов
    delete renderObject;
    delete worldBuilder;
    delete objectsCreator;
    delete movementController;
}

// создание ограждений по периметру
void GameManager::buildPerimetrWalls() {
    for(int i = 0; i < kvY; i++) {
        addWall(i,0);
        addWall(i, kvX - 1);
    }

    for(int i = 0; i < kvX; i++){
        addWall(0, i);
        addWall(kvY - 1, i);
    }
}

// создания уровня под определёным номером
void GameManager::buildLevel(int levelNumber) {
    // фабрика для получения загрузчиков из файлов
    FactoryOfFileLoaders factory;

    // переводим номер уровня в строку
    QString numberString;
    numberString.setNum(levelNumber);

    // получаем имена файлов, хранящих карту уровня и положение героев
    QString mapString = "levels/map" + numberString;
    QString thingString = "levels/thing" + numberString;

    // строим стены по периметру
    buildPerimetrWalls();

    // загружаем карту из файла
    FileLoader * mapLoader = factory.getMapLoader();
    mapLoader->makeLoadOfMap(mapString, worldBuilder);

    // создаём главного героя
    hero = addObject(400, 320, 40, 40, 1, 0, 0, "hero");
    hero->type = "hero";

    // загружаем монстров и другие объекты из файла
    FileLoader * thingLoader = factory.getThingLoader();
    thingLoader->makeLoadOfThings(thingString, objectsCreator);
}

