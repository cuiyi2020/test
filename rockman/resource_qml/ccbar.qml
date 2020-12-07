import QtQuick 2.2
import QtQuick.Controls 2.2

Rectangle {
    width: 1110
    height: 87
    radius: 44
    color: "#FF243043"
    ListView{
        id: cleanconfiglist
        anchors.fill: parent
        model: ccModel
        highlight: Image {
            id: cc_hightlight
            source: "qrc:/清扫配置高亮.png"
        }
        focus: true
        highlightMoveVelocity: 10000
        orientation: ListView.Horizontal
        delegate: Component{
            Rectangle{
                width: 220
                height: 87
//                color: "white"
                color: "transparent"
                Text {
                    text: modelData; color: "white"; anchors.centerIn: parent; font.pixelSize: 25;
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        cleanconfiglist.currentIndex = index
                        cc_title.trans_clean_config(index)
                    }
                }
            }
        }
    }
}
