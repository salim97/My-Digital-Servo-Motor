import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0



//import QtQuick.Controls 2.1
//Window {
Item{

    visible: true
    width: 800
    height: 800
    Connections{
        target: myNetwork
        onServoUpdate : {

            console.log(angle)
            if(angle > 180) return
            if(angle < 0) return
            car.d3.rotationY = angle
        }
    }

    ServoMotor3D{
        id: car
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        height: parent.height - 200

    }

}
