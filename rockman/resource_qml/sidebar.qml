import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.3
import QtQml.Models 2.1
import QtGraphicalEffects 1.0
//import QtQuick.Controls.Styles 1.2

Rectangle {
    id: side_bar
    width: 391
    height: 800
    color: "#80243043"

    Text {
        id: user_title
        text: qsTr("工程人员")
        x: 134
        y: 60
        color: "#FFFFFF"
        font.pixelSize: 18
    }

        Image {
            id: shutdown
            source: "qrc:/关闭.png"
            x:338
            y:26
            MouseArea{
                anchors.fill: shutdown
                onClicked: {
                    sideMenu.closeMenu()
                }
            }
        }

    Grid {
        y: 160
        columns: 2
        spacing: 1

        Repeater{
            model: dataModel
            delegate: Component{
                Rectangle{
                    width: 195
                    height: 120
                    color: "#66243043"
                    Text {text: modelData; x: 54; y:71; color: "#FFFFFF"; font.pixelSize: 18}
                    Image {source: "qrc:/"+modelData+".png"; x:78; y:25}
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            sideMenu.showWhichW(index)
                            console.log(index)
                        }
                    }
                }
            }
        }
    }

    Rectangle{
        y: 645
        width: 391
        height: 155
        color: "#66243043"
        Rectangle{
            width: 195
            height: 155
            color: "#00000000"
            Image {source: "qrc:/注销.png"; x:74; y:60}
            Text {text: qsTr("注销"); x:117; y:60; font.pixelSize: 24; color: "#FFFFFF"}
            MouseArea{anchors.fill: parent; onClicked: {console.log("注销")}}
        }
        Rectangle{
            x: 196
            width: 195
            height: 155
            color: "#00000000"
            Image {source: "qrc:/关机.png"; x:39; y:60}
            Text {text: qsTr("关机"); x: 82; y:60; font.pixelSize: 24; color: "#FFFFFF"}
            MouseArea{anchors.fill: parent; onClicked: {console.log("关机");sideMenu.clickShutDown();}}
        }
    }
}
