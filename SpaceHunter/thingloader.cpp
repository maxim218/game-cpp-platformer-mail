#include "thingloader.h"

// конструктор для чтения положения объектов из файла и добавления их в игру
ThingLoader::ThingLoader(QString fileName, ObjectsCreator * objectsCreator) {
    // объект для работы с файлом
    QFile * f = new QFile(fileName);
    // открываем файл для чтения
    f->open(QFile::ReadOnly);
    // поток для чтения из файла
    QTextStream in1(f);
    // строка для чтения из файла
    QString s;
    // координаты объекта
    int i = -1;
    int j = -1;
    // тип объекта
    int n = -1;
    // счётчик
    int count = 0;
    // пока не дошли до конца файла
    while(in1.atEnd() == false) {
        // считываем строку из файла
        in1 >> s;
        // если строка не пустая
        if(s != "") {
            // получаем тип переменной с помощью остатка от деления
            const int ost = count % 3;
            // увеличиваем счётчик
            count++;
            // в зависимости от типа переменной получаем определённую переменную
            switch(ost) {
                case 0:
                    i = s.toInt();
                    break;
                case 1:
                    j = s.toInt();
                    break;
                case 2:
                    n = s.toInt();
                    // если все три позиции считаны, то добавляем объект в игру
                    objectsCreator->addPhysicalObject(j * 20 + 20, i * 20 + 40, 40, 40, 0, 0, 0);
                    break;
            }
        }
    }
    // закрывам файл
    f->close();
}
