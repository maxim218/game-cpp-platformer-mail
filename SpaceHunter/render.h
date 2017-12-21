#ifndef RENDER_H
#define RENDER_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPen>

// класс для отображения объектов на холсте
class Render
{
    private:
        // указательн на сцену для рисования
        QGraphicsScene * my_s;
        // перо для рисования
        QPen pen;
        // метод для задания свойств пера (толщины и цвета)
        void setPenProperties(int penWidth, int penColorNumber);
        // метод для рисования линии по координатам двух точек
        void drawLine(int x1, int y1, int x2, int y2);
        // сдвиги по двум осям
        int dx, dy;

    public:
        // конструктор, в котором инициализируются свойства холста
        Render(QGraphicsView * graphicsView, int elementWidth, int elementHeight);
        // деструктор, в котором удаляется динамическая сцена
        ~Render();
        // метод для рисования прямоугольника по его опорной точке, ширине и высоте
        void drawRectange(int xx, int yy, int ww, int hh, int penWidth, int penColorNumber);
        // метод для очистки содержимого холста
        void clearAll();
        // задать сдвиги по осям
        void setDelta(int dxx, int dyy);
        // метод для рисования героя
        void drawHero(int x_param, int y_param);
        // методы для рисования монстров
        void drawMonsterTwo(int x_param, int y_param);
        void drawMonsterThree(int x_param, int y_param);
        void drawMonsterFour(int x_param, int y_param);
        // метод для рисования клетки
        void drawKletka(int x_param, int y_param);
        // рисование конечной точки игры
        void drawFinish(int x_param, int y_param);
};

#endif // RENDER_H
