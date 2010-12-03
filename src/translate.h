#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <QObject>
#include <QtNetwork>

#include <QScriptEngine>
#include <QScriptValueIterator>

#include "jsonstreamreader.h"

class QHttp;

class Translate : public QObject
{
    Q_OBJECT
public:
    Translate();

    int setProxy( const QString & host, int port, const QString & username, const QString & password );
    int unsetProxy();

    QStringList translatesShort;
    QStringList translatesFull;

public slots:
    void textTranslated();
    void startTranslation( int from, int to, QString text );

signals:
    QString translationComplete( QString text );

private:
    QHttp *http;
    QHttpRequestHeader headers;

    void setTranslationArrays();

    QString *version;
};

#endif // TRANSLATE_H
