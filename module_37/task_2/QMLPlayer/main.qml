import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


Window {
    width: 440
    height: 280
    visible: true
    title: qsTr("QMLPlayer")
    minimumHeight: 280
    minimumWidth: 440

    Rectangle {
        x: 2
        y: 2
        width: parent.width - 5
        height: parent.height - 70
        color: "#4A4A4A"

        Button {
            id: disp_play
            width: 50
            height: 30
            x: 51
            text: "▶️"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Rectangle{
        width: 255
        height: 30
        color: "white"
        y: parent.height - 60
        anchors.horizontalCenter: parent.horizontalCenter

        Button {
            id: rewind
            width: 50
            height: 30
            //y: parent.height - 60
            text: "⏪️"
        }

        Button {
            id: play
            width: 50
            height: 30
            x: 51
            text: "▶️"
        }
        Button {
            id: pause
            width: 50
            height: 30
            x: 102
            text: "||"
        }

        Button {
            id: stop
            width: 50
            height: 30
            x: 153
            text: "■"
        }

        Button {
            id: forward
            width: 50
            height: 30
            x: 204
            text: "⏩️"
        }
    }


    Slider {
        value: 0
        y: parent.height - 35
        width: parent.width
    }

}
