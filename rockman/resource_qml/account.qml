import QtQuick 2.3
import QtQuick.Controls 2.2

Rectangle {
    width: 280
    height: 289
    //color: "#80243043"
    color: "#FF232F43"

    Rectangle{
        id: list_area
        width: parent.width
        height: parent.height
        //y: error_title.height+1
        color: "#00000000"

        ListView{
            id: errorListView
            anchors.fill: parent
            focus: true
            model: accountModel
            delegate: listDelegate
        }

        Component{
            id: listDelegate
            Rectangle{
                id: error_warn_item
                width: parent.width
                height: 70
                color: "#00000000"
                Text {
                    id: status
                    text: modelData
                    color: "white"
                    font.pointSize: 16
                    anchors.left: parent.left
                    anchors.leftMargin: 34
                    anchors.top: parent.top
                    anchors.topMargin: 29
                }

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        accountMsg.set_uname(index);
                        //console.log(index)
                    }
                }
               Rectangle{
                   color: "#AAAAAA"
                   height: 1
                   width: parent.width
                   anchors.bottom: parent.bottom
               }

            }
        }
    }
}
