#include "styleworker.h"

// метод для добавления стиля к кнопке
void StyleWorker::setButtonStyle(QPushButton * www) {
     // создаём массив для хранения свойств кнопки
     QString arr[7];
     // инициализируем свойства кнопки
     arr[0] = "     outline: none;                     ";
     arr[1] = "     background: url(:/metal.jpeg);     ";
     arr[2] = "     font-size: 40px;                   ";
     arr[3] = "     color: #000000;                    ";
     arr[4] = "     border-width: 5px;                 ";
     arr[5] = "     border-style: solid;               ";
     arr[6] = "     border-radius: 10px;               ";
     // записываем свойства кнопки в одну строку
     QString buttonStyleString = "";
     for(int i = 0; i < 7; i++){
         buttonStyleString += arr[i];
     }
     // применяем свойства к кнопке
     www->setStyleSheet(buttonStyleString);
}

