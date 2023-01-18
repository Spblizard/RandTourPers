import QtQuick
import QtQuick.Controls

Window {
	width: 640
	height: 480
	visible: true
	title: qsTr("RandTourPers")

	Connections {
		target: back

		function onChampName(name) {
			champName.text = "Ultimate Champion " + name
			champName.visible = true
		}
	}

	Label {
		id: champName
		visible: false
		anchors.centerIn: parent
		font.bold: true
		font.pixelSize: 30
		color: "blue"
	}

	ListView {
		id: listViewChamps
		width: parent.width
		height: parent.height / 4
		anchors {
			top: parent.top
			left: parent.left
		}
		orientation: Qt.Horizontal
		layoutDirection: Qt.LeftToRight
		model: PersModelChamps
		delegate: Rectangle {
			border.color: "black"
			border.width: 2
			width: listViewChamps.width / model.count
			height: listViewChamps.height
			Text {
				anchors.fill: parent
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				text: model.name
			}
		}
	}
	ListView {
		id: listView
		width: parent.width
		height: parent.height / 4
		anchors.centerIn: parent
		orientation: Qt.Horizontal
		layoutDirection: Qt.LeftToRight
		model: PersModel
		delegate: Rectangle {
			border.color: model.color
			border.width: 2
			width: listView.width / model.count
			height: listView.height
			visible: model.visible
			Text {
				anchors.fill: parent
				verticalAlignment: Text.AlignVCenter
				horizontalAlignment: Text.AlignHCenter
				text: model.name
			}
			MouseArea {
				anchors.fill: parent
				onClicked: {
					back.setWinner(index)
					enabled = false
				}
			}
		}
	}

}
