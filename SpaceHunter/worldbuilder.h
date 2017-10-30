#ifndef WORLDBUILDER_H
#define WORLDBUILDER_H

#include "render.h"
#include "movementcontroller.h"
#include "matrixworker.h"

// класс для создания игровой карты
class WorldBuilder
{
    private:
        // объект для вывода содержимого карты на экран
        Render * renderObject;
        // размер игрового поля в клетках
        int kvX, kvY;
        // матрица для хранения типов клеток
        MatrixWorker * m;
        // размер одной клетки в пикселях
        int size;

    public:
        // конструктор для инициализации свойств карты и объекта для рисования
        WorldBuilder(Render * renderObjectParam, int kvXXX, int kvYYY);
        // деструктор для удаления матрицы
        ~WorldBuilder();
        // метод для вывода карты на экран
        void printMap(int dx, int dy);
        // метод для создания непроходимой стены
        void createWall(int i, int j);
        // метод для передачи данных о карте объекту, отвечающему за движение
        void copyMap(MovementController * movementController);
};

#endif // WORLDBUILDER_H
