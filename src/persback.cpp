#include "persback.h"

PersBack::PersBack(QObject *parent)
	: QObject{parent}, mPers(new PersModel)
{
	SaveLoadConf conf;

	mPers->setData(randomStrList (conf.getConfPers()));
}

PersModel *PersBack::pers()
{
	return mPers;
}

QStringList PersBack::randomStrList(const QStringList &list)
{
	QList<int> a;
	int max = 0;
	while (max < 8) {
		int tmpI = QRandomGenerator::global()->bounded(0, 8);
		if (!a.contains (tmpI)) {
			a.append(tmpI);
			max++;
		}
	}

	QStringList tmp;
	for (int i = 0; i < 8; i++)
		tmp.append(list.at(a[i]));

	return tmp;
}

void PersBack::setVisibleCell(int index)
{
	mPers->setVisibleCell(index);
}
