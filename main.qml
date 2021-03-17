import QtQuick 2.12
import QtQuick.Controls 2.12
import QtSingleton 1.12

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Singleton")

    Component.onCompleted: {
        Sinstance.callme.connect(onCallme);
        console.log(Sinstance.getInfo());
        console.log(Sinstance.texto)
    }

    function onCallme(){
        console.log("SLOT: onCallme")
    }
}
