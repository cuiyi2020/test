import QtQuick 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Rectangle{
    id: chooseModel
    width: 390
    height: 368
    color: "gray"
    visible: true

    Rectangle{
        width: 390
        height: 56
        color: "#FF232F43"
        Text {text: qsTr("选择模式"); x:151; y:16; font.pixelSize: 22; color: "#FFFFFF"}
    }

    Rectangle{
        y:57
        width: 390
        height: 239
        color: "#FF232F43"

        Tumbler{
            id: tumbler
            width: 390
            height: 239
            model: dataModel
            wrap: false
            delegate:Text {
                opacity: 1.0 - Math.abs(Tumbler.displacement) / (tumbler.visibleItemCount/2)
                    text: modelData
                    color: "#FFFFFF"
                    font.pixelSize: 30
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignHCenter
                }

            Rectangle{
                y:87
                width: 390
                height: 1
                color: "gray"
            }
            Rectangle{
                y:141
                width: 390
                height: 1
                color: "gray"
            }

        }
    }

    Rectangle{
        y:297
        width: 390
        height: 71
        color: "#FF232F43"
        Rectangle{
            width: parent.width/2
            height: parent.height
            color: "#00000000"
            Text {text: qsTr("取消"); color: "#FFFFFF"; x: 63; y:24; font.pixelSize: 22}
            MouseArea{anchors.fill: parent; onClicked: {clean_model.closeModel("cancel", tumbler.currentIndex)}}
        }
        Rectangle{
            x: parent.width/2
            width: parent.width/2
            height: parent.height
            color: "#00000000"
            Text {text: qsTr("确定"); color: "#FFFFFF"; x: 63; y:24; font.pixelSize: 22}
            MouseArea{anchors.fill: parent; onClicked: {clean_model.closeModel("true", tumbler.currentIndex)}}
        }
    }
}
