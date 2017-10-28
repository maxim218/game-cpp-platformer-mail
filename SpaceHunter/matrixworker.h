#ifndef MATRIXWORKER_H
#define MATRIXWORKER_H

// класс для работы с матрицей
class MatrixWorker
{
    private:
        // динамический массив для хранения матрицы
        int * mass;
        // размер матрицы в клетках
        int kvX, kvY;

    public:
        // конструктор для инициализации матрицы и её размеров
        MatrixWorker(int kvXXX, int kvYYY);
        // деструктор для удаления динамического массива
        ~MatrixWorker();
        // метод для задания значения элемента матрицы
        void setValue(int i, int j, int value);
        // метод для получения значения элемента матрицы
        int getValue(int i, int j);
};

#endif // MATRIXWORKER_H
