
#include "mainwindow.h"
#include "ui_mainwindow.h"

// таймер
QTimer * p = NULL;
// объект для управления игрой
GameManager * gameManager = NULL;
// идёт ли сейчас игра или нет
bool game = false;
// пауза в игре
bool pause = false;
// уровень игры
int gameLevel = 1;

// переменные для контроля жвижения персонажа
bool w,a,d;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // уровень игры
    gameLevel = 1;

    // ставим фокус на кнопке начала игры
    ui->b1->setFocus();

    // говорим, что игра НЕ началась
    game = false;

    // говорим, что паузы нет
    pause = false;

    // говорим, что персонаж никуда не двигается
    w = false;
    a = false;
    d = false;

    // задаём заголовок окна
    this->setWindowTitle("SpaceHunter");
    // ставим картинку с названием игры
    ui->titleLabel->setPixmap( QPixmap(":/titlePicture.png") );
    // задаём стиль центрального виджета
    ui->centralWidget->setStyleSheet(" background: url(:/space.jpg); ");
    // задаём стиль нижней части окна
    ui->statusBar->setStyleSheet(" background: #000000;");
    // говорим, что у картинки с названием игры нет фона
    ui->titleLabel->setStyleSheet("background: none;");

    // создаём объект для изменения стилей элементов
    StyleWorker styleWorker;
    // задаём стили кнопок главного меню
    styleWorker.setButtonStyle(ui->b1);
    styleWorker.setButtonStyle(ui->b2);
    styleWorker.setButtonStyle(ui->b3);
    styleWorker.setButtonStyle(ui->b4);
    // задать стиль кнопок режима игры
    styleWorker.setButtonStyle(ui->b5);
    styleWorker.setButtonStyle(ui->b6);

    // показываем на экране главное меню
    PositionManager positionManager;
    // показываем картинку
    positionManager.setPosition(ui->titleLabel, 30, 30);
    // показываем кнопки
    positionManager.setPosition(ui->b1, 60, 220);
    positionManager.setPosition(ui->b2, 60, 340);
    positionManager.setPosition(ui->b3, 60, 460);
    positionManager.setPosition(ui->b4, 60, 580);

    // создаём интервал
    p = new QTimer(this);
    // инициализируем интервал
    connect(p, SIGNAL(timeout()), SLOT(repeatingFunction()));
    // запускаем интервал
    p->start(50);
}

void MainWindow::repeatingFunction()
{
    // функция, которая вызывается в цикле

    // если идёт игра
    if(game == true) {
        // если нет паузы
        if(pause == false) {
            // если контроллер игры существует
            if(gameManager != NULL) {
                // выполняем очередной шаг игры
                int gameResult = gameManager->gameProcess(w, a, d);

                // если игра закончилась проигрышем
                if(gameResult == -1) {
                    // конец игры
                    gameOverFunction();
                    // уровень игры
                    gameLevel = 1;
                }

                // если игрок прошёл уровень
                if(gameResult == 1) {
                    // конец игры
                    gameOverFunction();
                    // уровень игры
                    gameLevel++;
                    // начало игры
                    startGameFunction(gameLevel);
                }
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGameFunction(int level) {
    // начало игры
    qDebug() << "Запуск игры";
    // говорим, что игра началась
    game = true;
    // говорим, что персонаж никуда не двигается
    w = false;
    a = false;
    d = false;
    // говорим, что паузы нет
    pause = false;

    // ставим фокус на элемент холст
    ui->graphicsView->setFocus();

    PositionManager positionManager;
    // прячем кнопки главного меню
    positionManager.hideElement(ui->b1);
    positionManager.hideElement(ui->b2);
    positionManager.hideElement(ui->b3);
    positionManager.hideElement(ui->b4);
    // прячем картинку главноог меню
    positionManager.hideElement(ui->titleLabel);

    // показываем холст
    positionManager.setPosition(ui->graphicsView, 30, 30);
    // показываем игровые кнопки
    positionManager.setPosition(ui->b5, 30, 650);
    positionManager.setPosition(ui->b6, 510, 650);

    gameManager = new GameManager();
    gameManager->startGame(ui->graphicsView, level);
}

void MainWindow::on_b1_clicked()
{
    // начало игры
    startGameFunction(1);
    // уровень игры
    gameLevel = 1;
}

void MainWindow::on_b4_clicked()
{
    // выход из приложения
    close();
}

void MainWindow::on_b5_clicked()
{
    // работа с паузой
    qDebug() << "Пауза";
    // меняем режим на противоположный
    pause = !pause;
}

void MainWindow::on_b6_clicked()
{
    // конец игры
    gameOverFunction();
    // уровень игры
    gameLevel = 1;
}

void MainWindow::gameOverFunction() {
    // конец игры
    qDebug() << "Конец игры";
    // завершаем игры
    gameManager->stopGame();
    // говорим, что игра завершена
    game = false;
    // удаляем объект контроля игры
    delete gameManager;
    // говорим, что паузы нет
    pause = false;

    // ставим фокус на кнопке начала игры
    ui->b1->setFocus();

    PositionManager positionManager;
    // прячем холст
    positionManager.hideElement(ui->graphicsView);
    // прячем игровые кнопки
    positionManager.hideElement(ui->b5);
    positionManager.hideElement(ui->b6);
    // показываем на экране главное меню
    // показываем картинку
    positionManager.setPosition(ui->titleLabel, 30, 30);
    // показываем кнопки
    positionManager.setPosition(ui->b1, 60, 220);
    positionManager.setPosition(ui->b2, 60, 340);
    positionManager.setPosition(ui->b3, 60, 460);
    positionManager.setPosition(ui->b4, 60, 580);
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // событие при нажатии клавиши

    // если игра идёт
    if(game == true) {
        // если нет паузы
        if(pause == false) {
            // говорим, что ни одна клавиша не нажата
            a = false;
            w = false;
            d = false;

            // ищем нажатую клавишу
            if(event->key() == Qt::Key_A) a = true;
            if(event->key() == Qt::Key_W) w = true;
            if(event->key() == Qt::Key_D) d = true;
        }
    }
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // событие щелчка мышкой

    // если игра идёт
    if(game == true) {
        // если нет паузы
        if(pause == false) {
            // получаем координаты миши относительно окна
            int xm = event->x();
            int ym = event->y();

            // если щелчок был сделан по холсту
            if(30 <= xm && xm <= 830) {
                if(30 <= ym && ym <= 630) {

                    // получаем координаты мыши относительно холста
                    xm -= 30;
                    ym -= 30;

                    // вызываем метод стрельбы
                    gameManager->fire(xm, ym + 20);
                }
            }
        }
    }
}
