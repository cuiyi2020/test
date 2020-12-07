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
                color: (scrub_config.get_scrub_state == 1)  ? "#FF232F43" : "white"
            }
            checked: true;
            background: Rectangle{
                 id:left_bg
            width: parent.width
            height: parent.height-6
            x:3
            y:3
            radius: 80;
            Rectangle {
                id:leftRect;
                anchors.right: parent.right;
                width: 25;
                height: parent.height;
                color: (scrub_config.get_scrub_state == 1) ? "white" : "transparent";
            }
            color: (scrub_config.get_scrub_state == 1) ? "white" : "transparent";
            }
            onClicked: {
                if (scrub_config.is_modal())
                    return;
                if (scrub_config.scrub_up())
                    changeColor(true);
            }
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
                color: (scrub_config.get_scrub_state == 1) ? "white" : "#FF232F43";
            }
            background: Rectangle{
                id:right_bg
                width: parent.width
                height: parent.height-6
                x: -3
                y:3
                radius: 80;
                Rectangle {
                    id:rightRect
                    anchors.left: parent.left;
                    width: 25;
                    height: parent.height;
                    color: (scrub_config.get_scrub_state == 1) ? "transparent" : "white";
                }
                color: (scrub_config.get_scrub_state == 1) ? "transparent" : "white";
            }
            onClicked: {
                if (scrub_config.is_modal())
                    return;
                if (scrub_config.scrub_down())
                    changeColor(false);
            }
        }
    }
    function changeColor(state){
        if(state){
            up.color = "#FF232F43"
            leftRect.color = "white"
            left_bg.color = "white"

            down.color = "white"
            rightRect.color = "transparent"
            right_bg.color = "transparent"
        } else{
            up.color = "white"
            leftRect.color = "transparent"
            left_bg.color = "transparent"

            down.color = "#FF232F43"
            rightRect.color = "white"
            right_bg.color = "white"
        }
    }
}
