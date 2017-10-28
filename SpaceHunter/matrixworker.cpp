#include "matrixworker.h"

// конструктор для инициализации матрицы и её размеров
MatrixWorker::MatrixWorker(int kvXXX, int kvYYY) {
    // инициализируем размер матрицы
    kvX = kvXXX;
    kvY = kvYYY;
    // получаем общее количество ячеек в матрице
    const int allSize = kvX * kvY;
    // создаём массив для хранения матрицы
    mass = new int[allSize];
    // заполняем все ячейки массива нулями
    for(int i = 0; i < allSize; i++) mass[i] = 0;
}

// деструктор для удаления матрицы
MatrixWorker::~MatrixWorker() {
    // удаляем динамический массив
    delete [] mass;
}

// метод для задания значения ячейки матрицы
void MatrixWorker::setValue(int i, int j, int value) {
    // получаем номер ячейки в одномерном массиве
    const int position = kvX * i + j;
    // задаём значение ячейки
    mass[position] = value;
}

// метод для получения значения ячейки матрицы
int MatrixWorker::getValue(int i, int j) {
    // получаем номер ячейки в одномерном массиве
    const int position = kvX * i + j;
    // возвращаем значение ячейки
    return mass[position];
}

