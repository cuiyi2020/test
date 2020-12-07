import QtQuick 2.2
import QtQuick.Controls 2.2
import QtQuick.Window 2.2

Window {
    visible: true
    width: 250
    height: 350
    title: qsTr("ListView")
    property bool refreshFlag: false

    Rectangle{
        width: parent.width
        height: -listView.contentY
        color: "#FF232F43"
        Label{
            anchors.centerIn: parent
            text:"刷新"
            color: "white"
            visible: listView.contentY
        }
    }

    BusyIndicator{
        id:busy
        z:4
        running: false
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: parent.height/3.

        Timer{
            interval: 200
            running: busy.running
            onTriggered: {
                busy.running = false
                console.log("fresh meat.")
            }
        }
    }


//    function funUpRefresh(){
//        console.debug(qsTr("启动上刷新..."))
//        listView.y = nPullHeight;

//        busyUpRefresh.running = false;
//        timerUpRefresh.start();
//    }

//    BusyIndicator {
//        id: busyUpRefresh
//        anchors.top: parent.top
//        anchors.topMargin: 6
//        anchors.horizontalCenter: parent.horizontalCenter
//        implicitWidth: 48
//        implicitHeight: 48
//        opacity: running ? 0.0 : 1.0
//        contentItem: QmlBusyIndicator{}
//    }

//    Timer{
//        id: timerUpRefresh
//        interval: 1000
//        repeat: false
//        running: false
//        onTriggered: {
//            busyUpRefresh.running = true;
//        }
//    }
    ListView{
        id:listView
        anchors.fill: parent
        model: 10
        onContentYChanged: {
            //console.log("movementEnded: originY:" + originY + ", contentY:" + contentY + ", refreshFlag:" + refreshFlag);
            if(-contentY > 20){
                refreshFlag = true
            }
        }
        onMovementEnded: {
            //console.log("movementEnded: originY:" + originY + ", contentY:" + contentY + ", refreshFlag:" + refreshFlag);
            if(refreshFlag){
                refreshFlag = false
                busy.running = true
                //funUpRefresh()
            }
        }

        onCurrentIndexChanged: {
            console.log("current index = ",currentIndex)
        }
        delegate: Rectangle{
              width: listView.width
              height: 60
              color: index%2 ? "red":"yellow"
              Label{
                  id:txt
                  anchors.centerIn: parent
                  font.pointSize: 20
                  text: index
              }
        }
    }
}
