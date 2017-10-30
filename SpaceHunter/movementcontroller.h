#ifndef MOVEMENTCONTROLLER_H
#define MOVEMENTCONTROLLER_H

#include "physicalobject.h"
#include <QDebug>
#include "matrixworker.h"

// класс для реализации движения объектов
class MovementController
{
    private:
        // указатель на список, содержащий физические объекты
        physicalObject * first;
        // размер карты в клетках
        int kvX, kvY;
        // размер одной клетки в пикселях
        int size;
        // метод для реализации движения одного физического объекта
        void moveOneObject(physicalObject * q);

    public:
        // конструктор для получения указателя на список физических объектов
        MovementController(physicalObject * pointerToFirstElement, int kvXXX, int kvYYY);
        // деструктор для удаления матрицы
        ~MovementController();
        // метод для реализации движения всех физических объектов
        void moveAllObjects();
        // матрица для хранения информации о карте
        MatrixWorker * m;
        // реализация прыжка
        void jump(physicalObject * q, int speedYYY);
};

#endif // MOVEMENTCONTROLLER_H
