import QtQuick
import QtQuick.Controls
import YtDlp

Window {
    height: 480
    title: qsTr("Simple YT-DLP")
    visible: true
    width: 640

    Button {
        anchors.centerIn: parent
        text: qsTr("Clickable")

        onClicked: YtDlp.checkExecutableExists()
    }
    ListView {
        anchors.right: parent.right
        anchors.top: parent.top
        height: 300
        model: YtDlp.notifications
        width: 300

        delegate: Text {
            text: model.title + model.description
        }
    }
}
