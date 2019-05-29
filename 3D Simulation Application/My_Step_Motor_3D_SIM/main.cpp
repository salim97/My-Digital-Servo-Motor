#include "mynetwork.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QQmlContext>
#include <QQuickView>
#include <Qt3DQuickExtras/qt3dquickwindow.h>
#include <Qt3DQuick/QQmlAspectEngine>
#include <QtGui/QOpenGLContext>
#include <QtQuick/QQuickView>
#include <QtQuick/QQuickItem>
#include <QtQml/QQmlContext>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSurfaceFormat format;
    if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL) {
        format.setVersion(3, 2);
        format.setProfile(QSurfaceFormat::CoreProfile);
    }
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);

    QQuickView engine;
    MyNetwork myNetwork ;
    engine.rootContext()->setContextProperty("myNetwork", &myNetwork);

    engine.setFormat(format);
    engine.create();

    engine.rootContext()->setContextProperty("_window", &engine);
    engine.setSource(QUrl("qrc:/main.qml"));
    engine.setResizeMode(QQuickView::SizeRootObjectToView);
    engine.setMinimumSize(QSize(300, 150));
    engine.setX(30);
    engine.setY(30);

    engine.show();

    return app.exec();
}
