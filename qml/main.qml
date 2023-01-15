import QtQuick
import QtQuick.Controls

Window {
	width: 640
	height: 480
	visible: true
	title: qsTr("RandTourPers")
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
					print (index)
					back.setVisibleCell(index)
					enabled = false
				}
			}
		}
	}

}
