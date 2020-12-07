import QtQuick 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

Rectangle{
    id: mapListArea
    width:1280
    height:800
    color: "#00000000"

    property variant $current_date_time: new Date()
    ListView{
        id:listview
        highlight: Image {
            id: border_
            source: "qrc:/矩形 961 拷贝 3.png"
        }
//        highlightFollowsCurrentItem: true
        highlightMoveVelocity: 100000
        focus: true
        model:dataModel
        anchors.fill:parent
        orientation: ListView.Horizontal
        delegate:Component{
            id: item
            Rectangle{
                color:"transparent"
                width:332
                height:332
                Text {text:modelData;font.pointSize:25; color: "#FFFFFF";x: 130; y:81;font.pixelSize: 16;}
                MouseArea{
                    anchors.fill:parent
                    onClicked:{
                        var new_date_time = new Date()
                        var time_diff = new_date_time - mapListArea.$current_date_time
                        if(time_diff < 600){
                            new_date_time=new_date_time.setDate(new_date_time.getDate()-1);
                            mapListArea.$current_date_time=new Date(new_date_time);
                            mapList.callMapIndex(index);
                        } else {
                            mapListArea.$current_date_time=new Date(new_date_time);
                            listview.currentIndex = index
//                            mapList.callMapChoose()
//                            console.log("current_date_time2 "+bigRectangle.$current_date_time);
                        }
//                        listview.currentIndex = index
//                        mapList.callMapChoose()
                    }

//                    onDoubleClicked: {
//                        console.log(index)
//                        mapList.callMapIndex(index)
//                    }
                }
            }
        }
    }
}
