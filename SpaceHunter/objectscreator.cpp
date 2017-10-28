#include "objectscreator.h"

// конструктор для инициализации объекта для рисования, инициализации указателей на физические объекты и создания начального элемента списка
ObjectsCreator::ObjectsCreator(Render * renderObjectParam){
    // инициализуем объект для рисовния
    renderObject = renderObjectParam;
    // инициализируем указатели на физические объекты
    first = NULL;
    last = NULL;
    q = NULL;
    p = NULL;
    // создаём первый элемент списка (он не принимает участия в действиях на сцене)
    first = addPhysicalObject(0, 0, 0, 0, 0, 0, 0);
}

// деструктор для удаления динамического списка физических объектов
ObjectsCreator::~ObjectsCreator(){
    // указывем на первый элемент
    q = first;
    // пока мы не дошли до конца списка
    while(q != NULL){
        // сохраняем указатель на текущий элемент
        p = q;
        // переходим на следующий элемент
        q = q->next;
        // удаляем текущий элемент
        delete p;
    }
}

// метод для добавления физических объектов в конец списка
physicalObject * ObjectsCreator::addPhysicalObject(int xx, int yy, int ww, int hh, int acceleration, int speedX, int speedY) {
    // создаём новый физический объект
    q = new physicalObject;
    // задаём свойства физического объекта
    q->xx = xx;
    q->yy = yy;
    q->ww = ww;
    q->hh = hh;
    q->acceleration = acceleration;
    q->speedX = speedX;
    q->speedY = speedY;
    // если начального элемента списка не существует
    if(first == NULL){
        // создаём начальный элемент
        first = q;
        first->next = NULL;
        last = first;
    } else {
        // если же начальный элемент уже существует, то добавляем структуру к концу списка
        last->next = q;
        q->next = NULL;
        last = q;
    }

    return q;
}

// метод для вывода одного физического объекта на экран
void ObjectsCreator::printOneObject(physicalObject * q) {
    // получаем свойства физического объекта
    int xx = q->xx;
    int yy = q->yy;
    int ww = q->ww;
    int hh = q->hh;
    // если объект не начальный (начальный объект не принимает участия в действиях на сцене)
    if(q != first){
        // выводим объект на экран
        renderObject->drawRectange(xx - ww/2, yy - hh, ww, hh, 2, 3);
    }
}

// метод для вывода всех физических объектов в списке на экран
void ObjectsCreator::printAllObjects() {
    q = first;
    // пробегаемся по всем элементам списка
    while(q != NULL) {
        // выводим на экран физический объект
        printOneObject(q);
        // переходим на следующий элемент списка
        q = q->next;
    }
}

// метод для получения указателя на список, содержащий физические объекты
physicalObject * ObjectsCreator::getPointerToList() {
    // возвращаем указатель на начальный элемент списка
    return first;
}

