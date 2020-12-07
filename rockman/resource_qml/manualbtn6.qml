import QtQuick 2.2
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.3
import QtQml.Models 2.1
import QtGraphicalEffects 1.0
//import QtQuick.Controls.Styles 1.2

Rectangle {
    id: side_bar
    width: 530
    height: 220
    color: "#80243043"


    Grid {
        y: 0
        columns: 3
        spacing: 17

        Repeater{
            model: dataModel
            delegate: Component{
                Rectangle{
                    width: 165
                    height: 100
                    color: "#66243043"
                    radius: 10
                    Text {text: modelData; anchors.centerIn: parent; color: "#FFFFFF"; font.pixelSize: 28}
                    //Image {source: "qrc:/"+modelData+".png"; x:78; y:25}
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            sideMenu.show_whichw(index)
                            console.log(index)
                        }
                    }
                }
            }
        }
    }

}
