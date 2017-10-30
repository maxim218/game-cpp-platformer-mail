#ifndef POSITIONMANAGER_H
#define POSITIONMANAGER_H

#include <QWidget>

// класс для изменения положения виджетов
class PositionManager
{
    public:
        // метод для задания позиции виджета
        void setPosition(QWidget * q, int xx, int yy);
        // метод для скрытия виджета за пределы экрана
        void hideElement(QWidget * q);
};

#endif // POSITIONMANAGER_H
