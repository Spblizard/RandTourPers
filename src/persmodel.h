#ifndef PERSMODEL_H
#define PERSMODEL_H

#include <QAbstractListModel>
#include <QModelIndex>
#include <QObject>
#include "persdata.h"

enum Roles {
	NameRole = Qt::UserRole + 1,
	ColorRole,
	VisibleRole,
	CountRole
};

class PersModel;

class PersModel : public QAbstractListModel
{
	Q_OBJECT
public:
	explicit PersModel(QObject *parent = nullptr);

	void setData(const QStringList &data);
	QString color(int index);

	virtual int rowCount(const QModelIndex &parent) const;
	virtual QVariant data(const QModelIndex &index, int role) const;
	virtual QHash<int, QByteArray> roleNames() const;

	void setVisibleCell(int index);

private:
	void nextRound();
	QList<PersData> mData;
	int mCountVisible;

};

#endif // PERSMODEL_H
