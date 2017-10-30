
#include "mainwindow.h"
#include "ui_mainwindow.h"

// таймер
QTimer * p = NULL;
// объект для управления игрой
GameManager * gameManager = NULL;
// идёт ли сейчас игра или нет
bool game = false;

// переменные для контроля жвижения персонажа
bool w,a,d;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // говорим, что игра НЕ началась
    game = false;

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
    if(game == true) {
        if(gameManager != NULL) gameManager->gameProcess(w, a, d);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_b1_clicked()
{
    // начало игры
    qDebug() << "Запуск игры";
    // говорим, что игра началась
    game = true;
    // говорим, что персонаж никуда не двигается
    w = false;
    a = false;
    d = false;

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
    gameManager->startGame(ui->graphicsView);
}

void MainWindow::on_b4_clicked()
{
    // выход из приложения
    close();
}

void MainWindow::on_b5_clicked()
{
    // пауза
}

void MainWindow::on_b6_clicked()
{
    // конец игры
    qDebug() << "Конец игры";
    // завершаем игры
    gameManager->stopGame();
    // говорим, что игра завершена
    game = false;
    // удаляем объект контроля игры
    delete gameManager;

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


// событие нажатия на клавишу
void MainWindow::keyDownEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W) w = true;
    if(event->key() == Qt::Key_A) a = true;
    if(event->key() == Qt::Key_D) d = true;
}

// событие отпускания клавиши
void MainWindow::keyUpEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W) w = false;
    if(event->key() == Qt::Key_A) a = false;
    if(event->key() == Qt::Key_D) d = false;
}
