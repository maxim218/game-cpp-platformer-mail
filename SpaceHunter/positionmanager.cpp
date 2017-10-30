#include "positionmanager.h"

// метод для задания позиции виджету
void PositionManager::setPosition(QWidget * q, int xx, int yy) {
    // получаем свойства виджета
    QRect rect = q->geometry();
    // получаем ширину и высоту виджета
    float ww = rect.width();
    float hh = rect.height();
    // изменяем положение виджета
    q->setGeometry(xx, yy, ww, hh);
}

// метод для скрытия виджета за пределы экрана
void PositionManager::hideElement(QWidget * q) {
    // получаем свойства виджета
    QRect rect = q->geometry();
    // получаем ширину и высоту виджета
    float ww = rect.width();
    float hh = rect.height();
    // изменяем положение виджета
    q->setGeometry(-1000, -1000, ww, hh);
}

