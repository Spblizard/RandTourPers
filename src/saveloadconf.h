#ifndef SAVELOADCONF_H
#define SAVELOADCONF_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

class SaveLoadConf : public QObject
{
	Q_OBJECT
public:
	explicit SaveLoadConf(QObject *parent = nullptr);
	QStringList getConfPers();

signals:

private:
	QString mConf;

};

#endif // SAVELOADCONF_H
