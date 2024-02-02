import QtQuick
import QtQuick.Controls

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Button {
        anchors.centerIn: parent
        text: qsTr("Clickable")
        onClicked: console.log("Clicked!")
    }
}
