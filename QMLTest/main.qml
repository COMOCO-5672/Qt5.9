import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Window {
    id:root
    visible: true;
    width: 1920;
    height: 1080;
    title: qsTr("Hello World")
//    Image{
//        source: "image/1.jpg"
//        anchors.centerIn: parent;
//        width: 1920;
//        height: 1080;
//    }
    MouseArea {
            anchors.fill: parent
            property int mx: 0
            property int my: 0
            onPressed: {
                mx=mouseX
                my=mouseY
            }
            onPositionChanged: {
                root.x+=mouseX-mx
                root.y+=mouseY-my
            }
        }
//    Button {
//        id:btn1
//        text:"OK";
//        autoRepeat: true;
//        onPressed: console.log("OK button pressed");
//        onReleased: console.log("OK button Released");
//        ButtonStyle{
//            background: Rectangle{
//                implicitWidth: 70;
//                implicitHeight: 35; 
//                border.width: btn1.pressed?2:1;
//                border.color: (btn1.pressed || btn1.hovered) ? "#00A060" : "#888888";
//                radius: 6;
//            }
//        }
//    }
}
