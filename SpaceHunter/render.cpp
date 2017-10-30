#include "render.h"

// конструктор, в котором идёт инициализация свойств холста
Render::Render(QGraphicsView * graphicsView, int elementWidth, int elementHeight) {
    // отключаем полосы прокрутки у холста
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // создаём новую сцену
    my_s = new QGraphicsScene;
    // соединяем холст и сцену
    graphicsView->setScene(my_s);
    // задаём размер холста
    my_s->setSceneRect(0, 0, elementWidth, elementHeight);
    // инициализируем сдвиги
    dx = 0;
    dy = 0;
}

// деструктор, в котором удаляется динамическая сцена
Render::~Render(){
    // удаляем сцену
    delete my_s;
}

// метод для задания свойств пера
void Render::setPenProperties(int penWidth, int penColorNumber) {
    // задаём толщину пера
    pen.setWidth(penWidth);
    // в зависимости от номера цвета выбираем цвет пера
    switch(penColorNumber) {
        case 1:
            pen.setColor(Qt::red);
            break;
        case 2:
            pen.setColor(Qt::green);
            break;
        case 3:
            pen.setColor(Qt::blue);
            break;
    }
}

// метод для рисования линии по координатам двух точек
void Render::drawLine(int x1, int y1, int x2, int y2) {
    // рисуем линию
    my_s->addLine(x1 - dx, y1 - dy, x2 - dx, y2 - dy, pen);
}

// метод для рисования прямоугольника по его опорной точке, ширине и высоте
void Render::drawRectange(int xx, int yy, int ww, int hh, int penWidth, int penColorNumber) {
    // задаём свойства пера
    setPenProperties(penWidth, penColorNumber);
    // рисуем четыре отрезка, которые образуют прямоугольник
    drawLine(xx, yy, xx + ww, yy);
    drawLine(xx + ww, yy, xx + ww, yy + hh);
    drawLine(xx + ww, yy + hh, xx, yy + hh);
    drawLine(xx, yy + hh, xx, yy);
}

// метод для очистки содержимого сцены
void Render::clearAll() {
    // очищаем содержимое сцены
    my_s->clear();
    // рисуем прямоугольник
    QBrush brush(Qt::white);
    my_s->addRect(-100, -100, 1100, 1100, pen, brush);
}

// задать сдвиги по осям
void Render::setDelta(int dxx, int dyy) {
    dx = dxx;
    dy = dyy;
}

