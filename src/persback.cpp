#include "persback.h"

PersBack::PersBack(QObject *parent)
	: QObject{parent}, mPers(new PersModel), mPersChamp(new PersModel), mFinal(false)
{
	SaveLoadConf conf;

	mAllPers = conf.getConfPers();
	mMaxBound = mAllPers.size();
	mPers->setData(randomStrList());
}

PersModel *PersBack::pers()
{
	return mPers;
}

PersModel *PersBack::persChamp()
{
	return mPersChamp;
}

QStringList PersBack::randomStrList()
{
	QList<int> a;
	int max = 0;
	qDebug() << "randomStrList: " << mMaxBound;
	while (max < 8) {
		int tmpI = QRandomGenerator::global()->bounded(0, mMaxBound);
		if (!a.contains (tmpI)) {
			a.append(tmpI);
			max++;
		}
	}

	QStringList tmp;
	for (int i = 0; i < 8; i++)
		tmp.append(mAllPers.at(a[i]));

	return tmp;
}

void PersBack::updatePers(int index)
{
	mAllPers.remove(index);
	mMaxBound = mAllPers.size();
}

void PersBack::setWinner(int index)
{
	mPers->setWinner(index);
	int i = mAllPers.indexOf(mPers->getNameLose());
	if (i != -1)
		updatePers(i);
	qDebug() << "setWinner: " << mAllPers;
	if (mPers->getSize() == 1) {
		qDebug() << "winner 1";
		if (!mFinal) {
			QStringList champ = {mPers->getNameChamp()};
			i = mAllPers.indexOf(champ[0]);
			updatePers(i);
			if (mMaxBound != 0) {
				mPers->setData(randomStrList());
				mPers->refreshModel();
			}
			mPersChamp->setData(champ);
			mPersChamp->refreshModel();
			if (mMaxBound == 0) {
				mPers->setData(mPersChamp->getData());
				mPers->refreshModel();
				mPersChamp->cleanData();
				mFinal = true;
			}
		} else {
			emit champName(mPers->getNameChamp());
		}
	}
}
