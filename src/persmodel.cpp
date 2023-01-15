#include "persmodel.h"

PersModel::PersModel(QObject *parent)
	: QAbstractListModel{parent}, mCountVisible(0)
{
}

void PersModel::setData(const QStringList &data)
{
	for (int i = 0; i < data.size(); i++) {
		PersData tmp;
		tmp.setName(data.at(i));
		tmp.setColor(color (i));
		mData.append(tmp);
	}
}

QString PersModel::color(int index)
{
	if (index < 2)
		return "red";
	else if (index < 4)
		return "green";
	else if (index < 6)
		return "blue";
	else if (index < 8)
		return "yellow";
	else
		return "black";
}

int PersModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid())
		return 0;

	return mData.size();
}

QVariant PersModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
		return QVariant();

	switch (role) {
		case NameRole:
			return mData.at(index.row()).name();
		case ColorRole:
			return mData.at(index.row()).color();
		case VisibleRole:
			return mData.at(index.row()).visible();
		case CountRole:
			return mData.size();
		default:
			return QVariant();
	}
}

QHash<int, QByteArray> PersModel::roleNames() const
{
	QHash<int, QByteArray> roles = QAbstractItemModel::roleNames();
	roles[NameRole] = "name";
	roles[ColorRole] = "color";
	roles[VisibleRole] = "visible";
	roles[CountRole] = "count";

	return roles;
}

void PersModel::setVisibleCell(int index)
{
	int trueIndex = 0;
	if (index % 2)
		trueIndex = index - 1;
	else
		trueIndex = index + 1;
	mData[trueIndex].setVisible(false);
	mCountVisible++;
	if (mCountVisible < (mData.size() / 2)) {
		QModelIndex i = createIndex(trueIndex, 0);
		emit dataChanged(i, i);
	} else {
		mCountVisible = 0;
		nextRound();
	}
}

void PersModel::nextRound()
{
	QList<PersData> tmp;
	for (auto data : mData ) {
		if (data.visible())
			tmp.append(data);
	}
	//mData = tmp;
	int index = mData.size() - 1;
	beginRemoveRows(QModelIndex(), 0, index);
	endRemoveRows();
	mData = tmp;
	qDebug() << mData.size();
	index = mData.size() - 1;
	beginInsertRows(QModelIndex(), 0, index);
	endInsertRows();
	//emit dataChanged(i, i);
}
