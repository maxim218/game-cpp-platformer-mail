#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>

#include "render.h"
#include "worldbuilder.h"
#include "objectscreator.h"
#include "movementcontroller.h"
#include "physicalobject.h"
#include "gamemanager.h"
#include "styleworker.h"
#include "positionmanager.h"
#include <QInputDialog>
#include "QKeyEvent"
#include <QMouseEvent>
#include "fileloader.h"
#include "factoryoffileloaders.h"
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    void mousePressEvent(QMouseEvent *event);
    void gameOverFunction();
    void startGameFunction(int level);

public slots:
     void repeatingFunction();

private slots:
     void on_b1_clicked();

     void on_b4_clicked();

     void on_b5_clicked();

     void on_b6_clicked();

     void on_b2_clicked();

     void on_b3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
