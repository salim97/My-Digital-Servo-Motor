import Qt3D.Core 2.0
import Qt3D.Render 2.0


Entity {
    id: root

    property real x: 0.0
    property real y: 0.0
    property real z: 0.0
    property real angle: 0.0
    property real scale: 1.0
    property real theta: 0.0
    property real phi: 0.0
    property Material material
    property real rotationX : 0
    property real rotationY : 0
    property real rotationZ : 0
    property real userAngle : 0
    property url source: ""
    property alias translation: transform.translation
    property alias matrix: transform.matrix
    property alias rotation: transform.rotation

    components: [ transform, mesh, root.material ]

    Transform {
        id: transform
        scale: 1
        translation: Qt.vector3d( 0, 0, 0 )
        rotation: fromEulerAngles( root.rotationX,
                                   root.rotationY,
                                   root.rotationZ )
    }

    Mesh {
        id: mesh
//        source: "assets/obj/trefoil.obj"
        source: root.source

    }
}
