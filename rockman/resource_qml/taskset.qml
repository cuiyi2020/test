import QtQuick 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

Rectangle {
    id: teskset
    width: 390
    height: 730
//    color: "#801F2939"
    color: "#FF232F43"
    radius: 9
    opacity: 0.5

    ColumnLayout{
        spacing: 1

        Rectangle {
            id: title
            width: 390
            height: 144
            color: "#FF232F43"

            Text {
                id: task_setting
                text: qsTr("任务设置")
                color: "#FFFFFF"
                x: 40
                y: 43
                width: 123
                height: 28
    //            font.weight: normal
                font.pixelSize: 30
            }

            Text {
                id: cleaning_time
                text: qsTr("预计清扫: ")
                x: 41
                y:87
                color: "#FFFFFF"
                font.pixelSize: 18
            }
        }

        Rectangle {
            id: map_list
//            y:158
            width: 390
            height: 104
            color: "#FF232F43"

            Text {
                id: map_title
                text: qsTr("地图")
                x: 41
                y: 24
                color: "#FFFFFF"
                font.pixelSize: 22
            }

            Text {
                id: map_name
                text: autotask.get_map_name
                x: 41
                y: 62
                color: "#FFFFFF"
                font.pixelSize: 18
                opacity: 0.6
            }

            Image {
                id: arrow_map
                source: "qrc:/矢量智能对象 拷贝 10.png"
                x: 340
                y: 42
            }

            MouseArea{
                id: map_area
                anchors.fill: parent
                hoverEnabled: true
                onPressed: {
                    map_list.color = "#0cFFFFFF"
                    autotask.callMapList()
                }
                onReleased: {
                    map_list.color = "#FF232F43"
                }
            }
        }

        Rectangle {
            id: plan_list
//            y: 249
            width: 390
            height: 104
            color: "#FF232F43"

            Text {
                id: plan_title
                text: qsTr("任务")
                color: "#FFFFFF"
                font.pixelSize: 22
                x: 41
                y: 24
            }

            Text {
                id: plan_name
                text: autotask.get_plan_name
                color: "#FFFFFF"
                font.pixelSize: 18
                x: 42
                y: 61
                opacity: 0.6
            }

            Image {
                id: arrow_plan
                source: "qrc:/矢量智能对象 拷贝 10.png"
                x: 340
                y: 40
            }

            MouseArea{
                id: plan_area
                anchors.fill: parent
                hoverEnabled: true
                onPressed: {
                    console.log("我不是坏小孩")
                    plan_list.color = "#0cFFFFFF"
                    autotask.callPlanList()
                }
                onReleased: {
                    plan_list.color = "#FF232F43"
                }
            }
        }

        Rectangle {
            id: clean_num
            width: 390
            height: 104
            color: "#FF232F43"
//            y: 340

            Text {
                id: num_name
                text: qsTr("循环")
                color: "#FFFFFF"
                font.pixelSize: 22
                x: 41
                y: 43
            }

            Rectangle {
                id: spinBox
                x: 191
                y: 31
                width: 160
                height: 40
                color: "#00000000"
                border.width: 1
                border.color: "#FFFFFF"
                radius: 10

                Text {
                    id: num
                    text: autotask.clean_num
                    x: 71
                    y: 9
                    color: "#FFFFFF"
                    font.pixelSize: 18
                }

                Rectangle {
                    id: minus_rec
                    x: 16
                    width: 20
                    height: spinBox.height
                    color: "#00000000"

                    Image {
                        id: minus
                        source: "qrc:/形状 876 拷贝 3.png"
                        y: 7
                    }

                    MouseArea{
                        id: minus_area
                        anchors.fill: parent
                        hoverEnabled: true
                        onPressed: {
                            console.log(num.text)
                            autotask.clean_num=String(Number(num.text)-1);
                            if (autotask.clean_num <= 1) {
                                autotask.clean_num = 1
                            }
                        }
                    }
                }

                Rectangle {
                    id: plus_rec
                    x: 120
                    width: 20
                    height: spinBox.height
                    color: "#00000000"

                    Image {
                        id: plus
                        source: "qrc:/形状 876 拷贝 3(1).png"
                        y: 7
                    }

                    MouseArea{
                        id: plus_area
                        anchors.fill: parent
                        hoverEnabled: true
                        onPressed: {
                            console.log(num.text)
                            autotask.clean_num = String(Number(num.text)+1);
                            if(autotask.clean_num >= 2){
                                autotask.clean_num = 2
                            }
                        }
                    }
                }
            }
        }

        Rectangle{
            id: model_list
//            y: 431
            width: 390
            height: 104
            color: "#FF232F43"

            Text {
                id: model_title
                text: qsTr("模式")
                color: "#FFFFFF"
                font.pixelSize: 22
                x: 41
                y: 24
            }

            Text {
                id: model_name
                text: autotask.get_model_name
                color: "#FFFFFF"
                font.pixelSize: 18
                x: 41
                y: 62
                opacity: 0.6
            }

            Image {
                id: model_arrow
                source: "qrc:/矢量智能对象 拷贝 10.png"
                x: 340
                y: 42
            }

            MouseArea{
                id: model_area
                anchors.fill: parent
                hoverEnabled: true
                onPressed: {
                    console.log("我不是坏小孩")
                    model_list.color = "#0cFFFFFF"
                    autotask.callModelList()
                }
                onReleased: {
                    model_list.color = "#FF232F43"
                }
            }
        }

        Rectangle{
            width: 390
            height: 175
            color: "#FF232F43"

            Rectangle{
                width: 206
                height: 78
                x: 40
                y: 55
                color: "#00000000"
                Text {
                    x:47
                    y:20
                    text: qsTr("开始任务")
                    font.pixelSize: 30
                    color: "#FFFFFF"
                }
                Image {
                    source: "qrc:/恢复暂停.png"
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        autotask.callStartClean()
                    }
                }
            }

            Rectangle{
                width: 78
                height: 78
                x:271
                y: 55
                color: "#00000000"

                Image {
                    source: "qrc:/定时按钮.png"
                }
            }
        }
    }
}
