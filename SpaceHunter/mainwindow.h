#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "render.h"
#include "worldbuilder.h"
#include "objectscreator.h"
#include "movementcontroller.h"
#include "physicalobject.h"
#include "gamemanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
     void repeatingFunction();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
