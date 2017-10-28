#include "mainwindow.h"
#include "ui_mainwindow.h"

QTimer * p;
GameManager * gameManager;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("SpaceHunter");

    gameManager = new GameManager();
    gameManager->startGame(ui->graphicsView);
    gameManager->createDemoLevel();

    p = new QTimer(this);
    connect(p, SIGNAL(timeout()), SLOT(repeatingFunction()));
    p->start(50);
}

void MainWindow::repeatingFunction()
{
    gameManager->gameProcess();
}

MainWindow::~MainWindow()
{
    gameManager->stopGame();
    delete ui;
}
