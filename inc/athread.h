#ifndef ATHREAD_H
#define ATHREAD_H

#include "androidreceiver.h"
#include "mainwindow.h"
#include <QThread>
#include <QTextEdit>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>


class aThread : public QThread
{
    Q_OBJECT
public:
    explicit aThread(qintptr ID, QObject *parent = 0, MainWindow *w = NULL);
    void run();

signals:
    void error(QTcpSocket::SocketError socketError);
    void valueChanged(QString);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
    MainWindow *window;
};

#endif // ATHREAD_H
