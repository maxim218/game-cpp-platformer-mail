#ifndef THINGLOADER_H
#define THINGLOADER_H

#include "fileloader.h"

// класс для загрузки положения монстров и других объектов из файла
class ThingLoader : public FileLoader
{
  public:
        // метод для чтения положения объектов из файла и добавления их в игру
        void makeLoadOfThings(QString fileName, ObjectsCreator * objectsCreator) {
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
                            QString type = "";
                            type.setNum(n);
                            type = "thing" + type;
                            physicalObject * thing = objectsCreator->addPhysicalObject(j * 20 + 20, i * 20 + 40, 40, 40, 1, 0, 0, type);
                            thing->nowLiveTime = 0;
                            thing->maxLiveTime = n;
                            break;
                    }
                }
            }
            // закрывам файл
            f->close();
        }
};

#endif // THINGLOADER_H
