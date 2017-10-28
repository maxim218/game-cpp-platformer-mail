#ifndef PHYSICALOBJECT
#define PHYSICALOBJECT

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

    // адресная часть
    // указатель на следующий элемент списка
    physicalObject * next;
};

#endif // PHYSICALOBJECT

