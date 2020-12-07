import QtQuick 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Image {
    id: name
    source: "qrc:/状态条.png"
    width: 1280
    height: 56
//    color: "#00000000"

    Image {
        id:signal
        source: "qrc:/矢量智能对象(7).png"
        width: 35
        height: 23
        x: 82
        y: 18
    }

    Image {
            id: warnning
            source: "qrc:/警告.png"
            width: 30
            height: 28
            x: 148
            y: 16
    }

    Image {
        id: battery
        source: "qrc:/矢量智能对象(4).png"
        width: 36
        height: 18
        x: 1213
        y:18
    }
}
