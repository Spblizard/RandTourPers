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
	PersModel *persChamp();

signals:
	void champName(const QString &name);

private:
	QStringList randomStrList();
	void updatePers(int index);
	PersModel *mPers;
	PersModel *mPersChamp;
	int mMaxBound;
	QStringList mAllPers;
	bool mFinal;

public slots:
	void setWinner(int index);

};

#endif // PERSBACK_H
