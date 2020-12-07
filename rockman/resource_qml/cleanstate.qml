import QtQuick 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Rectangle {
    width: 390
    height: 736
    color: "#FF232F43"
    radius: 9
    opacity: 0.5

    Rectangle{
        width: parent.width
        height: parent.height-580
        y:580
        color: "#FF232F43"

        Rectangle{
            width: 214
            height: 72
            color: "#00000000"
            x: 40
            y:40
            Image {
                source: "qrc:/恢复暂停.png"
            }
            Text {
                x:70
                y:15
                text: cleanState.clean_state
                color: "#FFFFFF"
                font.pixelSize: 30
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    cleanState.callAutoClean()
                }
            }
        }

        Rectangle{
            width: 73
            height: 72
            x: 278
            y: 40
            color: "#00000000"
            Image {
                source: "qrc:/结束按钮.png"
            }
            Text {
                x:20
                y:25
                text: qsTr("结束")
                color: "#FFFFFF"
                font.pixelSize: 18
            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    cleanState.callAutoExit()
                }
            }
        }
    }
}
