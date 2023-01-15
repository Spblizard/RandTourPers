#ifndef PERSBACK_H
#define PERSBACK_H

#include <QObject>
#include <QRandomGenerator>
#include "persmodel.h"
#include "saveloadconf.h"

class PersBack : public QObject
{
	Q_OBJECT
public:
	explicit PersBack(QObject *parent = nullptr);

public slots:
	PersModel *pers();

signals:

private:
	QStringList randomStrList(const QStringList &list);
	PersModel *mPers;

public slots:
	void setVisibleCell(int index);

};

#endif // PERSBACK_H
