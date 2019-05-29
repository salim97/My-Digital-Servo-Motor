#include "mynetwork.h"

MyNetwork::MyNetwork(QObject *parent) : QObject(parent)
{
    m_udpSocket = new QUdpSocket(this);
    if(!m_udpSocket->bind(udpPort, QUdpSocket::ShareAddress))
        qDebug() << "m_udpSocket : " + m_udpSocket->errorString() ;
    else
        qDebug() << "UDP 127.0.0.1:" +QString::number(udpPort)+" LISTENING." ;

    connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(readyReadUDP()));

}

void MyNetwork::readyReadUDP()
{
    QByteArray datagram;
    while (m_udpSocket->hasPendingDatagrams()) {
        datagram.resize(int(m_udpSocket->pendingDatagramSize()));
        m_udpSocket->readDatagram(datagram.data(), datagram.size());
        emit servoUpdate(datagram.replace("<servo>", "").toDouble());
    }
}
