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
            pen.setColor(Qt::white);
            break;
        case 2:
            pen.setColor(Qt::red);
            break;
        case 3:
            pen.setColor(Qt::green);
            break;
        case 4:
            pen.setColor(Qt::darkGreen);
            break;
        case 5:
            pen.setColor(Qt::blue);
            break;
        case 6:
            pen.setColor(Qt::darkBlue);
            break;
        case 7:
            pen.setColor(Qt::darkCyan);
            break;
        case 8:
            pen.setColor(Qt::magenta);
            break;
        case 9:
            pen.setColor(Qt::gray);
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
    // рисуем фон - картинку
    my_s->addPixmap( QPixmap(":/fonPixel.jpg") );
}

// задать сдвиги по осям
void Render::setDelta(int dxx, int dyy) {
    dx = dxx;
    dy = dyy;
}

void Render::drawKletka(int x_param, int y_param) {
    float xx = x_param - 10;
    float yy = y_param - 20;

    QColor color;
    color.setNamedColor("#000000");
    QPen pen(Qt::black);
    pen.setWidth(1);
    QBrush brush(color);

    color.setNamedColor("#ffffff");
    brush.setColor(color);
    my_s->addRect(xx + 2.75 - dx, yy + 2.7 - dy,14.35,14.2,pen,brush);
}

void Render::drawFinish(int x_param, int y_param) {
    float xx = x_param - 20;
    float yy = y_param - 40;

    QColor color;
    color.setNamedColor("#000000");
    QPen pen(Qt::black);
    pen.setWidth(1);
    QBrush brush(color);

    color.setNamedColor("#f50a43");
    brush.setColor(color);
    my_s->addRect(xx + 12.8 - dx, yy + 0.7 - dy,13.3,3.8,pen,brush);
    color.setNamedColor("#f50a43");
    brush.setColor(color);
    my_s->addRect(xx + 13.2 - dx, yy + 3.9 - dy,12.2,3.6,pen,brush);
    color.setNamedColor("#f50a43");
    brush.setColor(color);
    my_s->addRect(xx + 14.1 - dx, yy + 6.8 - dy,10.8,3,pen,brush);
    color.setNamedColor("#f50a43");
    brush.setColor(color);
    my_s->addRect(xx + 14.6 - dx, yy + 9.3 - dy,9.5,2.7,pen,brush);
    color.setNamedColor("#f50a43");
    brush.setColor(color);
    my_s->addRect(xx + 16.2 - dx, yy + 11.1 - dy,5.6,19.4,pen,brush);
    color.setNamedColor("#f50a43");
    brush.setColor(color);
    my_s->addRect(xx + 13.6 - dx, yy + 29.1 - dy,10.5,4.2,pen,brush);
    color.setNamedColor("#f50a43");
    brush.setColor(color);
    my_s->addRect(xx + 14.7 - dx, yy + 31.9 - dy,5.5,4.9,pen,brush);
    color.setNamedColor("#f50a43");
    brush.setColor(color);
    my_s->addRect(xx + 17.9 - dx, yy + 31.8 - dy,4.6,4.8,pen,brush);
    color.setNamedColor("#f50a43");
    brush.setColor(color);
    my_s->addRect(xx + 16.8 - dx, yy + 35 - dy,4,3.3,pen,brush);
    color.setNamedColor("#f50a43");
    brush.setColor(color);
    my_s->addRect(xx + 8.1 - dx, yy + 25.2 - dy,20.8,4.7,pen,brush);
    color.setNamedColor("#f50a43");
    brush.setColor(color);
    my_s->addRect(xx + 4.7 - dx, yy + 22.1 - dy,27.4,4.9,pen,brush);
    color.setNamedColor("#f50a43");
    brush.setColor(color);
    my_s->addRect(xx + 1.3 - dx, yy + 19.7 - dy,35.4,4.5,pen,brush);
}

void Render::drawMonsterFour(int x_param, int y_param) {
    float xx = x_param - 20;
    float yy = y_param - 40;

    QColor color;
    color.setNamedColor("#000000");
    QPen pen(Qt::black);
    pen.setWidth(1);
    QBrush brush(color);

    color.setNamedColor("#71f011");
    brush.setColor(color);
    my_s->addEllipse(xx + 9.1 - dx, yy + 21 - dy,18.6,18.6,pen,brush);
    color.setNamedColor("#71f011");
    brush.setColor(color);
    my_s->addEllipse(xx + 13.1 - dx, yy + 9.5 - dy,11.4,11.4,pen,brush);
    color.setNamedColor("#71f011");
    brush.setColor(color);
    my_s->addEllipse(xx + 14.5 - dx, yy + 0.4 - dy,9.2,9.2,pen,brush);
    color.setNamedColor("#114bf0");
    brush.setColor(color);
    my_s->addEllipse(xx + 15.4 - dx, yy + 4.9 - dy,3.2,3.2,pen,brush);
    color.setNamedColor("#114bf0");
    brush.setColor(color);
    my_s->addEllipse(xx + 19.6 - dx, yy + 4.5 - dy,3.8,3.8,pen,brush);
    color.setNamedColor("#114bf0");
    brush.setColor(color);
    my_s->addEllipse(xx + 18 - dx, yy + 1.2 - dy,2.2,2.2,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 22.1 - dx, yy + 11.5 - dy,16.2,3.4,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 0.9 - dx, yy + 11.6 - dy,14.1,1.7,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 0.3 - dx, yy + 10.1 - dy,15.8,4.1,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addEllipse(xx + 13.8 - dx, yy + 8.1 - dy,6.8,6.8,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addEllipse(xx + 18 - dx, yy + 9.7 - dy,6,6,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addEllipse(xx + 14.8 - dx, yy + 13.1 - dy,6.6,6.6,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addEllipse(xx + 14.3 - dx, yy + 19.7 - dy,8,8,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addEllipse(xx + 15.4 - dx, yy + 18 - dy,6,6,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 0.4 - dx, yy + 14 - dy,3.5,6.2,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 33.2 - dx, yy + 14.7 - dy,4.8,7,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 0.4 - dx, yy + 19.3 - dy,1.3,6.1,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 2.8 - dx, yy + 18.9 - dy,1.1,6.5,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 33.1 - dx, yy + 19.8 - dy,1.7,6.2,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 36.2 - dx, yy + 19.3 - dy,2,6.3,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 23.6 - dx, yy + 33.9 - dy,4.9,2.6,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 25.1 - dx, yy + 30.4 - dy,3.8,2.3,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 25.4 - dx, yy + 27.4 - dy,4.1,1.4,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 6.5 - dx, yy + 34 - dy,6.5,1.6,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 5.9 - dx, yy + 29.7 - dy,5.4,2.5,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addRect(xx + 7.7 - dx, yy + 25.1 - dy,3.7,2.8,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addEllipse(xx + -0.2 - dx, yy + 12.2 - dy,4.2,4.2,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addEllipse(xx + 33.1 - dx, yy + 12.3 - dy,4.8,4.8,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addEllipse(xx + 24.7 - dx, yy + 9.7 - dy,7,7,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addEllipse(xx + 3.6 - dx, yy + 8 - dy,7.8,7.8,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addEllipse(xx + 13 - dx, yy + 31.1 - dy,5.6,5.6,pen,brush);
    color.setNamedColor("#4afb28");
    brush.setColor(color);
    my_s->addEllipse(xx + 16.8 - dx, yy + 29.5 - dy,8.2,8.2,pen,brush);
    color.setNamedColor("#374c33");
    brush.setColor(color);
    my_s->addRect(xx + 26.5 - dx, yy + 12 - dy,3.2,1.9,pen,brush);
    color.setNamedColor("#374c33");
    brush.setColor(color);
    my_s->addRect(xx + 5.2 - dx, yy + 10.6 - dy,3.6,2.5,pen,brush);
    color.setNamedColor("#374c33");
    brush.setColor(color);
    my_s->addRect(xx + 19.2 - dx, yy + 31.9 - dy,3.9,3.2,pen,brush);
    color.setNamedColor("#374c33");
    brush.setColor(color);
    my_s->addRect(xx + 34.8 - dx, yy + 13.7 - dy,2.3,1.5,pen,brush);
    color.setNamedColor("#374c33");
    brush.setColor(color);
    my_s->addRect(xx + 15.9 - dx, yy + 10 - dy,1.6,1.2,pen,brush);
    color.setNamedColor("#374c33");
    brush.setColor(color);
    my_s->addRect(xx + 16.4 - dx, yy + 14.9 - dy,2.9,1.3,pen,brush);
    color.setNamedColor("#374c33");
    brush.setColor(color);
    my_s->addRect(xx + 19.8 - dx, yy + 11 - dy,2.2,2,pen,brush);
    color.setNamedColor("#374c33");
    brush.setColor(color);
    my_s->addRect(xx + 17.9 - dx, yy + 21.1 - dy,2,1.5,pen,brush);
    color.setNamedColor("#374c33");
    brush.setColor(color);
    my_s->addRect(xx + 0.8 - dx, yy + 13.8 - dy,1.2,1,pen,brush);
}

void Render::drawMonsterThree(int x_param, int y_param) {
    float xx = x_param - 20;
    float yy = y_param - 40;

    QColor color;
    color.setNamedColor("#000000");
    QPen pen(Qt::black);
    pen.setWidth(1);
    QBrush brush(color);

    color.setNamedColor("#34f107");
    brush.setColor(color);
    my_s->addRect(xx + 15.4 - dx, yy + 7.8 - dy,8.4,23.1,pen,brush);
    color.setNamedColor("#34f107");
    brush.setColor(color);
    my_s->addEllipse(xx + 9.6 - dx, yy + 0.5 - dy,20,20,pen,brush);
    color.setNamedColor("#f16307");
    brush.setColor(color);
    my_s->addRect(xx + 13 - dx, yy + 4.2 - dy,5,3.3,pen,brush);
    color.setNamedColor("#f16307");
    brush.setColor(color);
    my_s->addRect(xx + 13.1 - dx, yy + 8.5 - dy,4.6,1.7,pen,brush);
    color.setNamedColor("#f16307");
    brush.setColor(color);
    my_s->addRect(xx + 13.4 - dx, yy + 14.3 - dy,13.1,1.4,pen,brush);
    color.setNamedColor("#f16307");
    brush.setColor(color);
    my_s->addEllipse(xx + 19.6 - dx, yy + 3.7 - dy,6.8,6.8,pen,brush);
    color.setNamedColor("#1007f1");
    brush.setColor(color);
    my_s->addEllipse(xx + 21.5 - dx, yy + 5.7 - dy,2.8,2.8,pen,brush);
    color.setNamedColor("#07f136");
    brush.setColor(color);
    my_s->addEllipse(xx + 20.4 - dx, yy + 20 - dy,6.8,6.8,pen,brush);
    color.setNamedColor("#07f136");
    brush.setColor(color);
    my_s->addEllipse(xx + 12.5 - dx, yy + 21.4 - dy,5.6,5.6,pen,brush);
    color.setNamedColor("#07f136");
    brush.setColor(color);
    my_s->addEllipse(xx + 4.1 - dx, yy + 22 - dy,10,10,pen,brush);
    color.setNamedColor("#07f136");
    brush.setColor(color);
    my_s->addEllipse(xx + 4.1 - dx, yy + 30.7 - dy,8,8,pen,brush);
    color.setNamedColor("#07f136");
    brush.setColor(color);
    my_s->addEllipse(xx + 25.2 - dx, yy + 20.4 - dy,12,12,pen,brush);
    color.setNamedColor("#07f136");
    brush.setColor(color);
    my_s->addEllipse(xx + 26.7 - dx, yy + 30.8 - dy,8,8,pen,brush);
    color.setNamedColor("#07f136");
    brush.setColor(color);
    my_s->addEllipse(xx + 1.6 - dx, yy + 0.1 - dy,9.4,9.4,pen,brush);
    color.setNamedColor("#07f136");
    brush.setColor(color);
    my_s->addEllipse(xx + 28.7 - dx, yy + 0.7 - dy,9.2,9.2,pen,brush);
    color.setNamedColor("#07f136");
    brush.setColor(color);
    my_s->addEllipse(xx + 17.2 - dx, yy + 27.3 - dy,4.4,4.4,pen,brush);
    color.setNamedColor("#f1073f");
    brush.setColor(color);
    my_s->addEllipse(xx + 27.8 - dx, yy + 22.9 - dy,6.8,6.8,pen,brush);
    color.setNamedColor("#f1073f");
    brush.setColor(color);
    my_s->addEllipse(xx + 6.6 - dx, yy + 24.5 - dy,4.2,4.2,pen,brush);
    color.setNamedColor("#1707f1");
    brush.setColor(color);
    my_s->addEllipse(xx + 30.8 - dx, yy + 2.7 - dy,5.2,5.2,pen,brush);
    color.setNamedColor("#1707f1");
    brush.setColor(color);
    my_s->addEllipse(xx + 3.8 - dx, yy + 2.2 - dy,5,5,pen,brush);
}

void Render::drawMonsterTwo(int x_param, int y_param) {
    float xx = x_param - 20;
    float yy = y_param - 40;

    QColor color;
    color.setNamedColor("#000000");
    QPen pen(Qt::black);
    pen.setWidth(1);
    QBrush brush(color);

    color.setNamedColor("#72f50f");
    brush.setColor(color);
    my_s->addRect(xx + 7.6 - dx, yy + 8.6 - dy,3.1,7.7,pen,brush);
    color.setNamedColor("#72f50f");
    brush.setColor(color);
    my_s->addRect(xx + 17.7 - dx, yy + 8.4 - dy,3.4,7.1,pen,brush);
    color.setNamedColor("#72f50f");
    brush.setColor(color);
    my_s->addRect(xx + 28.1 - dx, yy + 7.8 - dy,4,6.7,pen,brush);
    color.setNamedColor("#72f50f");
    brush.setColor(color);
    my_s->addEllipse(xx + 5.3 - dx, yy + 4 - dy,7.4,7.4,pen,brush);
    color.setNamedColor("#72f50f");
    brush.setColor(color);
    my_s->addEllipse(xx + 16.1 - dx, yy + 3.6 - dy,6.8,6.8,pen,brush);
    color.setNamedColor("#72f50f");
    brush.setColor(color);
    my_s->addEllipse(xx + 26.7 - dx, yy + 2 - dy,7,7,pen,brush);
    color.setNamedColor("#72f50f");
    brush.setColor(color);
    my_s->addRect(xx + 6.1 - dx, yy + 13.1 - dy,31.4,9.9,pen,brush);
    color.setNamedColor("#340ff5");
    brush.setColor(color);
    my_s->addRect(xx + 8.7 - dx, yy + 5.5 - dy,0,2.4,pen,brush);
    color.setNamedColor("#340ff5");
    brush.setColor(color);
    my_s->addRect(xx + 7.2 - dx, yy + 5.4 - dy,3.7,2.9,pen,brush);
    color.setNamedColor("#340ff5");
    brush.setColor(color);
    my_s->addRect(xx + 17.9 - dx, yy + 5.5 - dy,3.1,2.4,pen,brush);
    color.setNamedColor("#340ff5");
    brush.setColor(color);
    my_s->addRect(xx + 28.7 - dx, yy + 3.8 - dy,3,2.4,pen,brush);
    color.setNamedColor("#11f50f");
    brush.setColor(color);
    my_s->addEllipse(xx + 2.3 - dx, yy + 14.8 - dy,7.6,7.6,pen,brush);
    color.setNamedColor("#11f50f");
    brush.setColor(color);
    my_s->addEllipse(xx + 30.1 - dx, yy + 13.7 - dy,8.8,8.8,pen,brush);
    color.setNamedColor("#11f50f");
    brush.setColor(color);
    my_s->addEllipse(xx + 20.7 - dx, yy + 12.9 - dy,10.4,10.4,pen,brush);
    color.setNamedColor("#11f50f");
    brush.setColor(color);
    my_s->addEllipse(xx + 11.4 - dx, yy + 13.1 - dy,11,11,pen,brush);
    color.setNamedColor("#11f50f");
    brush.setColor(color);
    my_s->addEllipse(xx + 8.5 - dx, yy + 16.4 - dy,4.4,4.4,pen,brush);
    color.setNamedColor("#11f50f");
    brush.setColor(color);
    my_s->addRect(xx + 9.8 - dx, yy + 25.1 - dy,5.5,10.2,pen,brush);
    color.setNamedColor("#11f50f");
    brush.setColor(color);
    my_s->addRect(xx + 1.1 - dx, yy + 32.7 - dy,14.3,5.5,pen,brush);
    color.setNamedColor("#11f50f");
    brush.setColor(color);
    my_s->addRect(xx + 24.7 - dx, yy + 24.8 - dy,5.8,8.6,pen,brush);
    color.setNamedColor("#11f50f");
    brush.setColor(color);
    my_s->addRect(xx + 24.7 - dx, yy + 32.4 - dy,13.5,5.5,pen,brush);
    color.setNamedColor("#11f50f");
    brush.setColor(color);
    my_s->addEllipse(xx + 7.4 - dx, yy + 21.2 - dy,10,10,pen,brush);
    color.setNamedColor("#11f50f");
    brush.setColor(color);
    my_s->addEllipse(xx + 22.5 - dx, yy + 21.3 - dy,9.8,9.8,pen,brush);
    color.setNamedColor("#f5540f");
    brush.setColor(color);
    my_s->addEllipse(xx + 24 - dx, yy + 15.4 - dy,4.4,4.4,pen,brush);
    color.setNamedColor("#f5540f");
    brush.setColor(color);
    my_s->addEllipse(xx + 13.5 - dx, yy + 15.8 - dy,5,5,pen,brush);
    color.setNamedColor("#f5540f");
    brush.setColor(color);
    my_s->addEllipse(xx + 25.3 - dx, yy + 24.6 - dy,3.8,3.8,pen,brush);
    color.setNamedColor("#f5540f");
    brush.setColor(color);
    my_s->addEllipse(xx + 9.6 - dx, yy + 24 - dy,3.8,3.8,pen,brush);
    color.setNamedColor("#f5540f");
    brush.setColor(color);
    my_s->addEllipse(xx + 3.7 - dx, yy + 17 - dy,3.2,3.2,pen,brush);
    color.setNamedColor("#f5540f");
    brush.setColor(color);
    my_s->addEllipse(xx + 10.5 - dx, yy + 18.4 - dy,0.8,0.8,pen,brush);
    color.setNamedColor("#f5540f");
    brush.setColor(color);
    my_s->addEllipse(xx + 32.5 - dx, yy + 15.7 - dy,4.2,4.2,pen,brush);
}

void Render::drawHero(int x_param, int y_param) {
    float xx = x_param - 20;
    float yy = y_param - 40;

    QColor color;
    color.setNamedColor("#000000");
    QPen pen(Qt::black);
    pen.setWidth(1);
    QBrush brush(color);

    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addEllipse(xx + 10.1 - dx, yy + 9 - dy,19.6,19.6,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addEllipse(xx + 13.1 - dx, yy + 0.4 - dy,14.2,14.2,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addRect(xx + 0.6 - dx, yy + 14 - dy,8.2,10.5,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addRect(xx + 1.5 - dx, yy + 25.1 - dy,4.8,9.4,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addRect(xx + 6.6 - dx, yy + 14 - dy,7,3.4,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addRect(xx + 31.1 - dx, yy + 13.6 - dy,7.9,8.8,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addRect(xx + 32.8 - dx, yy + 23.3 - dy,4.4,9.8,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addRect(xx + 31.9 - dx, yy + 20 - dy,6,4.8,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addRect(xx + 1.2 - dx, yy + 21.1 - dy,6.4,4.9,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addRect(xx + 26.6 - dx, yy + 13.2 - dy,7.4,3,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addRect(xx + 11.5 - dx, yy + 22.3 - dy,6.4,8.7,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addRect(xx + 11.9 - dx, yy + 29.6 - dy,3.9,8.8,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addRect(xx + 21.2 - dx, yy + 22.2 - dy,5.7,8.2,pen,brush);
    color.setNamedColor("#12d651");
    brush.setColor(color);
    my_s->addRect(xx + 22.5 - dx, yy + 28.9 - dy,3.2,9.5,pen,brush);
    color.setNamedColor("#d62412");
    brush.setColor(color);
    my_s->addEllipse(xx + 15.1 - dx, yy + 2.2 - dy,4,4,pen,brush);
    color.setNamedColor("#d62412");
    brush.setColor(color);
    my_s->addEllipse(xx + 21.4 - dx, yy + 2.8 - dy,3.2,3.2,pen,brush);
    color.setNamedColor("#122ed6");
    brush.setColor(color);
    my_s->addEllipse(xx + 19.4 - dx, yy + 6.8 - dy,1.2,1.2,pen,brush);
    color.setNamedColor("#d6122a");
    brush.setColor(color);
    my_s->addRect(xx + 15.2 - dx, yy + 9.9 - dy,9.9,1.4,pen,brush);
    color.setNamedColor("#d6122a");
    brush.setColor(color);
    my_s->addRect(xx + 19.9 - dx, yy + 16.8 - dy,0,1.8,pen,brush);
    color.setNamedColor("#d6122a");
    brush.setColor(color);
    my_s->addEllipse(xx + 17.9 - dx, yy + 15.9 - dy,4,4,pen,brush);
}

