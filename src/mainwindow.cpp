#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>
#include <QtGui>

#include<QtDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   Tr = new Translate();
       connect(Tr, SIGNAL(translationComplete(QString)), this, SLOT(translationComplete(QString)) );
       // Setting up languages list
           QStringList
                   translates =Tr->translatesFull ,
                   list =Tr->translatesShort ;

           langs = new QStringList(list);

           // Connecting languages list to language selectors (ComboBoxes)
           ui->transfrom->addItem( "Auto" );
          ui->transfrom->setItemIcon( 0 ,QIcon(QString(":/image/images/image/en.png")));

           ui->transfrom->addItems(translates);
           ui->transto->addItems(translates);
           qDebug("Langs setted");

           // Setting up icons for ComboBoxes
           for(int i=0;i<ui->transto->count();i++)
           {
               QString path = QString(":/image/images/image/%1.png").arg(langs->at(i));
               ui->transfrom->setItemIcon( i+1 ,QIcon(path));
               ui->transto->setItemIcon(i,QIcon(path));
           }
           qDebug("Lang flags configured...");

           // Setting up last used languages
           // If application runs firs time on this computer by default setting up English2English
           ui->transfrom->setCurrentIndex(settings.value("lang/from",10).value<int>());
           ui->transto->setCurrentIndex(settings.value("lang/to",10).value<int>());
           qDebug("Last pair loaded");


           // Translated text must be readOnly
           ui->langto->setReadOnly(true);

           // Setuping actions
           setUpActions();




           //Windows



           //Debug output
           qDebug("All buttons are connected");


}

MainWindow::~MainWindow()

{

    // Saves current language pair
        settings.setValue("trans/from",ui->transfrom->currentIndex());
        settings.setValue("trans/to",ui->transto->currentIndex());
        qDebug("Last language pair saved");

        qDebug("Good bye.");
    delete ui;
}


void MainWindow::on_swap_clicked()
{
    // Swapping languages (e.g. English<->Russian)
    if( ui->transfrom->currentIndex() != 0 ){
        int tmp = ui->transto->currentIndex();
        ui->transto->setCurrentIndex( ui->transfrom->currentIndex()-1 );
        ui->transfrom->setCurrentIndex( tmp+1 );
    }
}
void MainWindow::on_translate_clicked()
{
    qDebug("Starting translation.");
    QString text;
   Tr->startTranslation( ui->transfrom->currentIndex()-1 , ui->transto->currentIndex(), ui->langfrom->toPlainText() );
}
void MainWindow::translationComplete( QString text)
{
    ui->langto->setText( text );
}

