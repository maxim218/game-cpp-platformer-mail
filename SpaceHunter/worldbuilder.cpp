#include "worldbuilder.h"

// конструктор для инициализации свойств карты и объекта для рисования
WorldBuilder::WorldBuilder(Render * renderObjectParam, int kvXXX, int kvYYY) {
    // инициализируем объект для рисования
    renderObject = renderObjectParam;
    // инициализируем размер карты в клетках
    kvX = kvXXX;
    kvY = kvYYY;
    m = new MatrixWorker(kvX, kvY);
    // задаём размер клетки в пикселях
    size = 20;
    // пробегаемся во всей матрице и говорим, что каждая клетка изначально проходимая
    for(int i = 0; i < kvY; i++){
        for(int j = 0; j < kvX; j++){
            m->setValue(i, j, 0);
        }
    }
}

// деструктор для удаления матрицы
WorldBuilder::~WorldBuilder() {
    // удаляем матрицу
    delete m;
}

// метод для вывода карты на экран
void WorldBuilder::printMap(){
    // очищаем содержимое холста
    renderObject->clearAll();
    // пробегаемся по все карте
    for(int i = 0; i < kvY; i++){
        for(int j = 0; j < kvX; j++){
            // если данная клетка является стеной
            if(m->getValue(i, j) == 1){
                // рисуем стену
                renderObject->drawRectange(j * size, i * size, size, size, 3, 2);
            }            
        }
    }
}

// метод для создания стены
void WorldBuilder::createWall(int i, int j) {
    // говорим, что клетка с данным положением является стеной
    m->setValue(i, j, 1);
}

// метод для передачи данных о карте объекту, отвечающему за движение
void WorldBuilder::copyMap(MovementController * movementController) {
    // пробегаемся по всей матрице
    for(int i = 0; i < kvY; i++){
        for(int j = 0; j < kvX; j++){
            // копируем информацию о клетке в другой объект
            int value = m->getValue(i, j);
            movementController->m->setValue(i, j, value);
        }
    }
}


