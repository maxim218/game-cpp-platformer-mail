#include "movementcontroller.h"

// конструктор для получения указателя на список физических объектов
MovementController::MovementController(physicalObject * pointerToFirstElement, int kvXXX, int kvYYY) {
    // получаем указатель на список физических объектов
    first = pointerToFirstElement;
    // задаём размер карты в клетках
    kvX = kvXXX;
    kvY = kvYYY;
    // задаём размер клетки в пикселях
    size = 20;
    // создаём объект для работы с матрицей
    m = new MatrixWorker(kvX, kvY);
}

// деструктор для удаления матрицы
MovementController::~MovementController() {
    delete m;
}

// метод для реализации движения одного физического объекта
void MovementController::moveOneObject(physicalObject * q) {
    // пока скорость падения не превысила определённое значение
    if(q->speedY <= size / 2) {
        // увеличиваем скорость падения
        q->speedY += q->acceleration;
    }

    // получаем позицию клетки, в котороый находится физический объект
    int xPosNow = int( q->xx / size );
    int yPosNow = int( q->yy / size );

    // если объект не за пределами игрового мира
    if(0 <= xPosNow && xPosNow < kvX) {
        if(0 <= yPosNow && yPosNow < kvY){

            // если опорная точка объекта находится внутри препятствия
            if(m->getValue(yPosNow, xPosNow) != 0){
                // обнуляем скорость падения объекта
                q->speedY = 0;
                // ставим объект ровно над препятствием
                q->yy = yPosNow * size;
            }

            // переменные для хранения позиции клетки, в которую попадёт объект после текущего шага
            int xPosFuture = 0;
            int yPosFuture = int( (q->yy + q->speedY) / size );

            if(q->speedX > 0){
                // если объект движентся по горизонтали вправо
                xPosFuture = int( (q->xx + q->speedX + q->ww / 2) / size );
            } else {
                // если объект движентся по горизонтали влево
                xPosFuture = int( (q->xx + q->speedX - q->ww / 2) / size );
            }

            if(m->getValue(yPosNow, xPosFuture) == 0) {
                q->xx += q->speedX;
            }

            if(m->getValue(yPosFuture, xPosNow) == 0) {
                q->yy += q->speedY;
            } else {
                q->speedY = 0;
                q->yy = yPosFuture * size - 1;
            }

            if(q->speedY < 0){
                int yPosFutureSecond = int( (q->yy + q->speedY - q->hh) / size );
                if(m->getValue(yPosFutureSecond, xPosNow) == 1) {
                    q->speedY = 0;
                    q->yy = yPosFutureSecond * size + size + q->hh;
                }
            }
        }
    }
}

// реализация прыжка
void MovementController::jump(physicalObject * q, int speedYYY) {
    // получаем координаты клетки под персонажем
    int xPos = int( q->xx / size );
    int yPos = int( (q->yy + 18) / size );
    // если под персонажем стена
    if(m->getValue(yPos, xPos) == 1){
        // делаем прыжок
        q->speedY = speedYYY;
        q->yy -= 4;
    }
}

// метод для реализации движения всех физических объектов
void MovementController::moveAllObjects() {
    physicalObject * q = first;
    // пробегаемся по списку физических объектов
    while(q != NULL){
        // если объект не начальный (начальный объект не принимает участия в действиях на сцене), то реализуем движение объекта
        if(q != first) moveOneObject(q);
        // переходим на следующий элемент списка
        q = q->next;
    }
}

