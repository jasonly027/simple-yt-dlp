import QtQuick
import QtQuick.Controls
import YtDlp

Window {
    height: 480
    title: qsTr("Hello World")
    visible: true
    width: 640

    Button {
        anchors.centerIn: parent
        text: qsTr("Clickable")

        onClicked: YtDlp.checkExecutableExists()
    }
}
