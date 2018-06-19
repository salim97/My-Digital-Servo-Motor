#ifndef MYNETWORK_H
#define MYNETWORK_H

#include <QObject>
#include <QUdpSocket>

class MyNetwork : public QObject
{
    Q_OBJECT
public:
    explicit MyNetwork(QObject *parent = nullptr);

signals:

public slots:
    void sendUDP(QString msg);
private:
    int udpPort = 45455 ;
    QUdpSocket *m_udpSocket = nullptr;
};

#endif // MYNETWORK_H
