import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1500
    height: 900
    title: qsTr("Hello World")
    Item{
        anchors.fill: parent

        Image {
            id: bacckground
            anchors.centerIn: parent
            source: "qrc:/motor.png"
            fillMode: Image.PreserveAspectFit
            //            width: 394 ; height: 1035
            scale: 0.4
            Component.onCompleted: {
                console.log("motor : "+width+" "+height)
            }
        }
        Image {
            id: head
            anchors.horizontalCenter: bacckground.horizontalCenter
            anchors.top: bacckground.top
            anchors.topMargin: 150
            source: "qrc:/motor_head.png"
            //            width: 25 ; height: 607
            scale: 0.4
            Component.onCompleted: {
                console.log("motor head: "+width+" "+height)
            }
            rotation: if (mouse_area1.angle < 0)
                          mouse_area1.angle * 180 / Math.PI + 360
                      else
                          mouse_area1.angle * 180 / Math.PI
            smooth: true
            onRotationChanged:
            {
                var r =    head.rotation;
                r = (r - 180  ) * -1
                myNetwork.sendUDP("<servo>"+r)
            }
        }

        MouseArea {
            id: mouse_area1
            anchors.fill: parent
            property real truex: mouseX-parent.width/2
            property real truey: parent.height/2-mouseY
            property real angle: Math.atan2(truex, truey)
        }
        Text {
            id: rotation
            text: "Rotation: " + head.rotation
            anchors {
                horizontalCenter: parent.horizontalCenter
                bottom: parent.bottom
                bottomMargin: 20
            }
        }



    }
}
