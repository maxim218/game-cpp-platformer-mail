#include "maploader.h"

// конструктор, в котором происходит чтение клеток из файла и добавление их в игру
MapLoader::MapLoader(QString fileName, WorldBuilder * worldBuilder) {
    // создаём объект для работы с файлом
    QFile * f = new QFile(fileName);
    // открываем файл для чтения
    f->open(QFile::ReadOnly);
    // создаём поток для чтения из файла
    QTextStream in1(f);
    // создаём строку для чтения данных из файла
    QString s;
    // флаг
    bool flag = false;
    // координаты клетки
    int i = -1;
    int j = -1;
    // пока не дошли до конца файла
    while(in1.atEnd() == false) {
        // читаем строку из файла
        in1 >> s;
        // если строка не пустая
        if(s != "") {
            if(!flag) {
                i = s.toInt();
            } else {
                j = s.toInt();
                worldBuilder->createWall(i, j);
            }
        }
        flag = !flag;
    }
    // закрываем файл
    f->close();
}

