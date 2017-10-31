#ifndef PHYSICALOBJECT
#define PHYSICALOBJECT

#include <QString>

// тип структура для хранения информации об объекте
struct physicalObject {
    // информационная часть
    // позиция
    int xx;
    int yy;
    // размер
    int ww;
    int hh;
    // ускорение по вертикали
    int acceleration;
    // скорость
    int speedX;
    int speedY;

    // тип объекта
    QString type;

    // максимальное время жизни
    int maxLiveTime;
    // текущее время жизни
    int nowLiveTime;

    // метка на удаление
    bool deleted;

    // адресная часть
    // указатель на следующий элемент списка
    physicalObject * next;
};

#endif // PHYSICALOBJECT

