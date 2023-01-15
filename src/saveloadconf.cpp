#include "saveloadconf.h"

SaveLoadConf::SaveLoadConf(QObject *parent)
	: QObject{parent}, mConf("config.json")
{

}

QStringList SaveLoadConf::getConfPers()
{
	QFile file(mConf);
	file.open(QIODevice::ReadOnly);
	QJsonObject jsonObj;
	QList<QJsonArray> arrays;
	QJsonDocument jsonDoc(QJsonDocument::fromJson (file.readAll()));
	if (jsonDoc.isObject()) {
		jsonObj = jsonDoc.object();
	}
	QStringList keys = jsonObj.keys();

	for (QString s : keys) {
		if (jsonObj[s].isArray())
			arrays.append(jsonObj[s].toArray());
	}

	QStringList pers;

	for (QJsonArray arr : arrays) {
		bool eight = false;
		qDebug() << arr.size();
		if (arr.size() == 8) {
			eight = true;
		}
		Q_ASSERT(eight);
		for (QVariant var : arr.toVariantList()) {
			pers.append(var.toString());
		}
	}
	qDebug() << pers;
	return pers;
}
