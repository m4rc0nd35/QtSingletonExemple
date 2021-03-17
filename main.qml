import QtQuick 2.12
import QtQuick.Controls 2.12
import QtSingleton 1.12

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Singleton")

    Connections {
        target: Sinstance
        onChangedText: console.log("Connections", txt)
    }

    Component.onCompleted: {
        Sinstance.callme.connect(onCallme);
        Sinstance.changedText.connect(onCalltxt);

        console.log(Sinstance.getInfo());
        console.log(Sinstance.text)

        Sinstance.text = "Q_PROPRERTY QML >> C++"
    }

    /* Slot JS */
    function onCallme(){
        console.log("SLOT QML:", "onCallme")
    }
    /* Slot JS */
    function onCalltxt(txt){
        console.log("SLOT QML:", txt)
    }
}
