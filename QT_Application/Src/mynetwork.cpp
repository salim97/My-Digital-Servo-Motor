#include "mynetwork.h"

MyNetwork::MyNetwork(QObject *parent) : QObject(parent)
{
    m_udpSocket = new QUdpSocket(this);
    if(!m_udpSocket->bind(udpPort, QUdpSocket::ShareAddress))
        qDebug() << "m_udpSocket : " + m_udpSocket->errorString() ;
    else
        qDebug() << "UDP 127.0.0.1:" +QString::number(udpPort)+" LISTENING." ;

//    connect(m_udpSocket, SIGNAL(readyRead()), this, SLOT(readyReadUDP()));

}

void MyNetwork::sendUDP(QString msg)
{
    qDebug() << "msg: " << msg  ;
    QByteArray datagram = msg.toUtf8() ;
    m_udpSocket->writeDatagram(datagram.data(), datagram.size(),
                               //QHostAddress::Broadcast, udpPort);
                              QHostAddress("255.255.255.255"), udpPort);
}
