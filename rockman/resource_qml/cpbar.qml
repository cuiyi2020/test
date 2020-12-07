import QtQuick 2.2
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0

Rectangle {
    id: back
    width: 120
    height: width
    radius: width / 2
    color: "transparent"
    border.width: 10
    border.color: percent === 100 ? "red" : "white"

    ConicalGradient {
        anchors.fill: back
        source: back
        enabled: percent != 100     //百分比不为100时有效
        visible: enabled            //百分比不为100时有效
        gradient: Gradient {
            GradientStop { position: 0.0; color: "white" }
            GradientStop { position: percent / 100 ; color: "red" }
            GradientStop { position: percent / 100 + 0.001; color: "white" }
            GradientStop { position: 1.0; color: "white" }
        }
    }
}
