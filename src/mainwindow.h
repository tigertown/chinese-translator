#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>




#include "translate.h"


class QSettings;
class QAction;
class QMessageBox;

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
    void on_swap_clicked();
    void on_translate_clicked();
    void translationComplete( QString text );




private:
    Ui::MainWindow *ui;
    void setUpActions();

       Translate *Tr;


        QAction *settingsAction;
        QStringList* langs;
        QSettings settings;

        };

#endif // MAINWINDOW_H
