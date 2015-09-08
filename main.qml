import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import Plot 1.0
ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

    Plot {
        id: plot
        anchors.fill: parent
    }

    Timer {
        id: timer
        interval: 16
        running: true
        repeat: true
        onTriggered: {
            plot.update()
        }
    }

}
