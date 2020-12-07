import QtQuick 2.2
import QtQuick.Controls 2.2

Rectangle {
    width: 391
    height: 735
    color: "#FF232F43"
    radius: 10
    opacity: 0.5

    Rectangle{
        width: 391
        height: 575
        color: "#00000000"
        GridView{
            id: gridview
            model: planModel
            anchors.fill: parent
            cellWidth: (parent.width-1)/2
            cellHeight: 191

            highlight: Image {
                id: plan_border
                source: "qrc:/任务高亮边框.png"
            }

            highlightFollowsCurrentItem: true
    //        highlightMoveVelocity: 200

            delegate: Component{
                 Rectangle{
                       id: plan_item
                       width: 195
                       height: 191
                       color: "#66243043"
                       Text {width: 94; height: 13; text: modelData; color: "#FFFFFF"; x: 54; y: 41; font.pixelSize: 13; horizontalAlignment: Text.AlignHCenter}
                       MouseArea{
                           anchors.fill: parent
                           onClicked: {
                               gridview.currentIndex = index
                               planList.callCurrentPlan(gridview.currentIndex)
                           }
                       }
                 }
            }
        }
    }

    Rectangle{
        y:576
        width: 390
        height: 157
        color: "#66243043"
        Rectangle{
            x: 96
            y: 38
            width: 214
            height: 79
            color:  "#00000000"
            radius: 39
            Image {
                source: "qrc:/恢复暂停.png"
            }
            Text {text: qsTr("确定"); x: 75; y: 25; font.pixelSize: 25; color: "#FFFFFF"}
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    planList.callPlanIndex(gridview.currentIndex)
                }
            }
        }
    }
}
