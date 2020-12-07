import QtQuick 2.3
import QtQuick.Controls 2.2
Item{
    width: 972
    height: 800

Flickable{
    id:myflick;
    anchors.fill: parent;
    contentHeight: 1000;   contentWidth: parent.width;

    Rectangle {
        anchors.fill: parent;
        color: "#FF101b2b"
        //color: "#80243043"

        Rectangle{
            id: error_title
            width: parent.width
            height: 161
            color:  "#00000000"
//            Image {
//                x: 41
//                y: 31
//                source: "qrc:/关闭.png"
//                MouseArea{
//                    anchors.fill: parent
//                    onClicked: {errorMsg.closeErrorMsg()}
//                }
//            }
            Rectangle{
                color: parent.color
                height: 10
                width: parent.width
                anchors.bottom: parent.bottom
            }
            Text {
                id: total_area
                text: qsTr("清扫总面积")
                font.pointSize: 20
                color: "white"
                anchors.left: parent.left
                anchors.leftMargin: 132
                anchors.verticalCenter: parent.verticalCenter
            }
            Text {
                id: total_durantion
                text: qsTr("清扫总时长")
                color: "white"
                font.pointSize: 20
                anchors.left: parent.left
                anchors.leftMargin: 132+parent.width/3
                anchors.verticalCenter: parent.verticalCenter
            }
            Text {
                id: total_times
                text: qsTr("清扫总次数")
                color: "white"
                font.pointSize: 20
                anchors.left: parent.left
                anchors.leftMargin: 132+parent.width/3*2
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Rectangle{
            id: list_area
            width: parent.width
            height: parent.height - error_title.height
            y: error_title.height+1
            color: "#00000000"

            ListView{
                id: errorListView
                anchors.fill: parent
                focus: true
                model: errorModel
                displayMarginBeginning: -58
                displayMarginEnd: -58
                delegate: listDelegate
                //clip: true
                interactive: false
            }

            Component{
                id: listDelegate
                Rectangle{
                    id: error_warn_item
                    width: parent.width
                    height: 123
                    //color: "#00000000"
                    color: "#80243043"
                    //radius: 20

                    Text {
                        id: error_warn1
                        text: rrplace
                        color: "white"
                        //font.pointSize: 22
                        anchors.left: parent.left
                        anchors.leftMargin: 132
                        anchors.top: parent.top
                        anchors.topMargin: 17.5
                    }

                    Text {
                        id: error_warn2
                        text: rdate
                        color: "white"
                        //font.pointSize: 18
                        anchors.left: parent.left
                        anchors.leftMargin: 132
                        anchors.top: parent.top
                        anchors.topMargin: 37
                    }

                    Text {
                        id: error_warn3
                        text: rmodel
                        color: "white"
                        //font.pointSize: 18
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.horizontalCenterOffset: -15
                        anchors.top: parent.top
                        anchors.topMargin: 27
                    }

                    Text {
                        id: error_warn4
                        text: rarea
                        color: "white"
                        //font.pointSize: 18
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.horizontalCenterOffset: 48.5
                        anchors.top: parent.top
                        anchors.topMargin: 27
                    }

                    Text {
                        id: error_warn5
                        text: rduration
                        color: "white"
                        //font.pointSize: 18
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.horizontalCenterOffset: 112.5
                        anchors.top: parent.top
                        anchors.topMargin: 27
                    }

                    Rectangle{
                        width: 94
                        height: 40
                        anchors.right: parent.right
                        anchors.rightMargin: 132
    //                    anchors.top: parent.top
    //                    anchors.topMargin: 42
                        anchors.verticalCenter: parent.verticalCenter
                        border.color: "white"
                        border.width: 2
                        radius: 80

                        color: "#00000000"
                        Text {
                            text: qsTr("详情")
                            font.pixelSize: 21
                            anchors.centerIn: parent
                            color: "#FFFFFF"
                        }
    //                    Image {
    //                        source: "qrc:/恢复暂停.png"
    //                    }
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                //autotask.callStartClean()
                            }
                        }
                    }

                    MouseArea{
                        property  point clickPos: "0,0"
                        anchors.fill: parent
                        onPressed: {
                            clickPos = Qt.point(mouse.x, mouse.y);
                        }
                        onReleased: {
                            var delta = Qt.point(mouse.x - clickPos.x, mouse.y - clickPos.y)
                            if ((delta.x < 0)
                                && (itemMoveOut.running === false)
                                && (itemColorChange.running == false)
                                && (error_warn_item.x == 0)){
    //                            aBtnShow.start();
                                itemColorChange.start();
                                itemMoveOut.start();
                            }else if (itemMoveBack.running === false && itemColorBack.running == false && (error_warn_item.x < 0)){
    //                            aBtnHide.start();
                                itemColorBack.start();
                                itemMoveBack.start();
                            }
                        }
                    }
                   Rectangle{
                       color: "#FF101b2b"
                       height: 20
                       width: parent.width+119
                       anchors.bottom: parent.bottom
                   }
                   Rectangle{
                       id: delBtn
                       height: parent.height
                       width: 119
                       color: "#00000000"
                       anchors.left: error_warn_item.right
                       Text {
                           x:43
                           y:50
                           font.pointSize: 12
                           text: qsTr("删除")
                           color: "#ffffff"
                       }
                       MouseArea{
                           anchors.fill: parent
                           onClicked: {
                               errorMsg.relieve(index)
                               console.log(index)
                           }
                       }
                   }
                   PropertyAnimation{
                       id: itemColorChange
                       target: error_warn_item
                       property: "color"
                       duration: 100
                       to: "#80ffffFF"
                   }
                   PropertyAnimation{
                       id: itemColorBack
                       target: error_warn_item
                       property: "color"
                       duration: 100
                       from: 119
                       to: "#00000000"
                   }
                   NumberAnimation{
                       id: itemMoveOut
                       target: error_warn_item
                       property: "x"
                       duration: 100
    //                   from: 0
                       to: -119
                   }
                   NumberAnimation{
                       id: itemMoveBack
                       target: error_warn_item
                       property: "x"
                       duration: 100
    //                   from: -119
                       to: 0
                   }
                }
            }
        }
    }
}
}
