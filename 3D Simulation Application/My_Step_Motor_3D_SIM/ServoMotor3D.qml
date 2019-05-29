import QtQuick 2.7 as QQ2
import QtQuick.Controls 2.0
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import QtQuick.Scene3D 2.0


Scene3D {
    id: scene3d
    anchors.fill: parent

    property real windowX: 0.0
    property real windowY: -0.04
    property real windowZ: 0.0
    //property alias d1: d1
    property alias d3: d3
    property alias d2: d2
    focus: true
    aspects: ["input", "logic"]
    cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

//background: transparent;
Entity {

    // Render from the mainCamera
    components: [
        RenderSettings {
            activeFrameGraph: ForwardRenderer {
                id: renderer
                camera: mainCamera
                clearColor: "transparent"
            }
        },
        // Event Source will be set by the Qt3DQuickWindow
        InputSettings { }
    ]

    My3dBasicCamera {
        id: mainCamera
        position: Qt.vector3d( 15.0, 15.0, 15.0 )
        viewCenter: Qt.vector3d(0, 0, 0)
    }
    FirstPersonCameraController { camera: mainCamera }
//    Camera {
//        id: myCamera
//        projectionType: CameraLens.PerspectiveProjection
//        fieldOfView: 45
//        nearPlane : 0.1
//        farPlane : 1000.0
//        position: Qt.vector3d( 0.0, 0.0, 10.0 )
//        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
//        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
//    }
//    OrbitCameraController {
//        camera: myCamera
//    }
    WireframeMaterial {
        id: wireframeMaterial
        effect: WireframeEffect {}
        ambient: Qt.rgba( 0.2, 0.0, 0.0, 1.0 )
        diffuse: Qt.rgba( 0.8, 0.0, 0.0, 1.0 )

//        normal: "assets/houseplants/" + root.plantType + "_normal.webp"
//        shininess: 10.0

        QQ2.SequentialAnimation {
            loops: QQ2.Animation.Infinite
            running: false

            QQ2.NumberAnimation {
                target: wireframeMaterial;
                property: "lineWidth";
                duration: 1000;
                from: 0.8
                to: 1.8
            }

            QQ2.NumberAnimation {
                target: wireframeMaterial;
                property: "lineWidth";
                duration: 1000;
                from: 1.8
                to: 0.8
            }

            QQ2.PauseAnimation { duration: 1500 }
        }
    }
//    My3Dobj{
//        id: trefoilKnot1
//        material: wireframeMaterial
////        material: DiffuseMapMaterial {
////            id: material
////            diffuse: "wood.webp"
////            //specular: Qt.rgba( 0.2, 0.2, 0.2, 1.0 )
////            shininess: 10.0
////        }
//        rotationX: 90
//        rotationY: 0
//        rotationZ: 0
//        source: "qrc:/obj/loto.obj"

//        x: 0
//        y: 0
//        z: 0
//    }

//    My3Dobj{
//        id: trefoilKnot2
//        //material: wireframeMaterial
//        material: wireframeMaterial
//        rotationX: 90
//        rotationY: 0
//        rotationZ: 0
//        source: "qrc:///3D/e5_window.obj"

//        x: scene3d.windowX
//        y: scene3d.windowY
//        z: scene3d.windowZ
//    }

/*
        My3Dobj{
            id: d1
            //material: wireframeMaterial
            material: wireframeMaterial
            source: "qrc:///obj/BMW/loto.obj"


        }
        */
        My3Dobj{
            id: d3
            //material: wireframeMaterial
            material: wireframeMaterial
            source: "qrc:///obj/9G-Servo - Mini Servo clip-1.obj"
            //rotationY: -60

        }
        My3Dobj{
            id: d2
            //material: wireframeMaterial
            material: wireframeMaterial

            source: "qrc:///obj/9G-Servo - Mini Servo-1.obj"


        }


}

}




