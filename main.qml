import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.1
import bashscriptcall 1.0

Window {
    id: window
    width: 640
    height: 480
    visible: true

    ScriptCall {
        id: scriptC
    }

    Text {
        id: textField
        text: scriptC.display
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 15
        anchors.rightMargin: 308
        anchors.leftMargin: 308
        anchors.topMargin: 179

    }

    Button {
        id: button
        x: 270
        y: 376
        width: 200
        height: 50
        text: qsTr("Run Script")
        font.pointSize: 14
        anchors.horizontalCenter: parent.horizontalCenter

        Connections {
            target: button
            onClicked: {
                scriptC.run()
            }
        }
    }
}

/*##^##
Designer {
    D{i:3}
}
##^##*/
