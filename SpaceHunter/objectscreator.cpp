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
    first = addPhysicalObject(0, 0, 0, 0, 0, 0, 0, "firstElementOfTheList");
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

// удаление объектов, помеченных на удаление
void ObjectsCreator::deleteMarkedObjects() {
    // получаем указатель на главного героя
    physicalObject * hero = first->next;
    // массив для хранения физических объектов
    physicalObject arr[1500];
    // длина массива
    int arrCount = 0;

    // указатель на физический объект после главного героя
    q = hero->next;

    // пока не дошли до конца списка
    while(q != NULL) {
        // если объект НЕ помечен на удаление
        if(q->deleted == false) {
            // создаём структуру
            physicalObject obj;

            // копируем в структуру свойства физического объекта
            obj.xx = q->xx;
            obj.yy = q->yy;
            obj.ww = q->ww;
            obj.hh = q->hh;
            obj.acceleration = q->acceleration;
            obj.speedX = q->speedX;
            obj.speedY = q->speedY;
            obj.type = q->type;
            obj.maxLiveTime = q->maxLiveTime;
            obj.nowLiveTime = q->nowLiveTime;
            obj.deleted = q->deleted;

            // добавляем физический объект в конец массива
            arr[arrCount] = obj;
            arrCount++;
        }
        // переходим на следующий элемент списка
        q = q->next;
    }

    // удаляем все объекты из списка кроме first и hero
    q = hero->next;
    while(q != NULL) {
        p = q;
        q = q->next;
        delete p;
    }

    // говорим, что hero - это последний элемент списка
    last = hero;
    last->next = NULL;

    // пробегаемся по массиву объектов
    for(int i = 0; i < arrCount; ++i) {
        // получаем i-ый элемент массива
        physicalObject obj = arr[i];
        // добавляем элемент в список
        physicalObject * element = addPhysicalObject(obj.xx, obj.yy, obj.ww, obj.hh, obj.acceleration, obj.speedX, obj.speedY, obj.type);
        // задаём дополнительные свойства элемента
        element->type = obj.type;
        element->maxLiveTime = obj.maxLiveTime;
        element->nowLiveTime = obj.nowLiveTime;
        element->deleted = obj.deleted;
    }

    // для хранения длины списка
    long listSize = 0;

    // считаем длину списка
    q = first;
    while(q != NULL) {
        ++listSize;
        q = q->next;
    }

    // выводим в консоль длину списка
    qDebug() << "List size: " << listSize;
}

// метод для добавления физических объектов в конец списка
physicalObject * ObjectsCreator::addPhysicalObject(int xx, int yy, int ww, int hh, int acceleration, int speedX, int speedY, QString type) {
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
    q->deleted = false;
    q->type = type;
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
void ObjectsCreator::printOneObject(physicalObject * q, int dx, int dy) {
    // задаём сдвиг
    renderObject->setDelta(dx, dy);
    // получаем свойства физического объекта
    int xx = q->xx;
    int yy = q->yy;
    int ww = q->ww;
    int hh = q->hh;
    // если объект не начальный (начальный объект не принимает участия в действиях на сцене)
    if(q != first){
        // выводим объект на экран

        // если объект - герой
        if(q->type == "hero") {
        renderObject->drawRectange(xx - ww/2, yy - hh, ww, hh, 2, 2);
        }

        // если объект - пуля
        if(q->type == "bullet") {
            renderObject->drawRectange(xx - ww/2, yy - hh, ww, hh, 2, 3);
        }

        // если объект - монстр 2
        if(q->type == "thing2") {
            renderObject->drawRectange(xx - ww/2, yy - hh, ww, hh, 2, 4);
        }

        // если объект - монстр 3
        if(q->type == "thing3") {
            renderObject->drawRectange(xx - ww/2, yy - hh, ww, hh, 2, 5);
        }

        // если объект - монстр 4
        if(q->type == "thing4") {
            renderObject->drawRectange(xx - ww/2, yy - hh, ww, hh, 2, 6);
        }

        // если объект - конец уровня
        if(q->type == "thing7") {
            renderObject->drawRectange(xx - ww/2, yy - hh, ww, hh, 2, 9);
        }
    }
}

// метод для вывода всех физических объектов в списке на экран
void ObjectsCreator::printAllObjects(int dx, int dy) {
    q = first;
    // пробегаемся по всем элементам списка
    while(q != NULL) {
        // выводим на экран физический объект
        printOneObject(q, dx, dy);
        // переходим на следующий элемент списка
        q = q->next;
    }
}

// метод для получения указателя на список, содержащий физические объекты
physicalObject * ObjectsCreator::getPointerToList() {
    // возвращаем указатель на начальный элемент списка
    return first;
}

