#ifndef OBJECTSCREATOR_H
#define OBJECTSCREATOR_H

#include "render.h"
#include "physicalobject.h"
#include <QDebug>

// класс для создания физических объектов
class ObjectsCreator
{
    private:
        // указатели на элементы списка, содержащего физические объекты
        physicalObject * first, * last, * q, * p;
        // указатель на объект для рисования
        Render * renderObject;
        // метод для отрисовки одного физического объекта
        void printOneObject(physicalObject * q, int dx, int dy);
        // режим отладки
        bool debugMode;

    public:
        // конструктор для инициализации объекта для рисования, инициализации указателей на физические объекты и создания начального элемента списка
        ObjectsCreator(Render * renderObjectParam);
        // деструктор для удаления динамического списка
        ~ObjectsCreator();
        // метод для добавления физического объекта в конец списка
        physicalObject * addPhysicalObject(int xx, int yy, int ww, int hh, int acceleration, int speedX, int speedY, QString type);
        // метод для вывода всех физических объектов на экран
        void printAllObjects(int dx, int dy);
        // метод для получения указателя на список, содержащий физические объекты
        physicalObject * getPointerToList();
        // удаление объектов, помеченных на удаление
        void deleteMarkedObjects();
};

#endif // OBJECTSCREATOR_H
