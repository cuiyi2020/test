import QtQuick 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Rectangle {
    width: 152
    height: 52
    color: "#FF232F43"
    radius: 80
        Image {
            source: "qrc:/升降按钮.png"
        }
    ButtonGroup {
         buttons: rows.children
    }

    RowLayout{
        id:rows
        anchors.fill: parent;
        spacing: 0;

        Button {
            id:enBtn;
            checkable: true;
            Layout.preferredWidth: 76;
            Layout.fillHeight: true;
            Text {
                id: up
                x: 23
                y: 12
                text: "升起"
                font.pixelSize: 20
                color: enBtn.checked ? "#FF232F43" : "white"
            }
            checked: true;
            background: Rectangle{
            width: parent.width
            height: parent.height-6
            x:3
            y:3
            radius: 80;
            Rectangle {
                id:rightRect;
                anchors.right: parent.right;
                width: 25;
                height: parent.height;
                color: enBtn.checked ? "white" : "transparent";
            }
            color: enBtn.checked ? "white" : "transparent";
            }
            onClicked: changeColor(true)
        }
        Button {
            id:chBtn;
            checkable: true;
            Layout.preferredWidth: 76;
            Layout.fillHeight: true;
//                            font.pointSize: 26;
            font.bold: true;
//            text: "降下"
            Text {
                id: down
                x: 17
                y:12
                text: qsTr("放下")
                font.pixelSize: 20
                color: chBtn.checked ? "#FF232F43" : "white"
            }
            background: Rectangle{
                width: parent.width
                height: parent.height-6
                x: -3
                y:3
                radius: 80;
                Rectangle {
                    id:leftRect;
                    anchors.left: parent.left;
                    width: 25;
                    height: parent.height;
                    color: chBtn.checked ? "white" : "transparent";
                }
                color: chBtn.checked ? "white" : "transparent";
            }
            onClicked: changeColor(false)
        }
    }
    function changeColor(state){
        if(state){
            up.color = "#FF232F43"
            down.color = "white"
        } else{
            up.color = "white"
            down.color = "#FF232F43"
        }
    }
}
