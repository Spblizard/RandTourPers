#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QSqlDatabase>
#include "persback.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	PersBack pers;

	qDebug() << QSqlDatabase::drivers();

	QQmlApplicationEngine engine;

	engine.rootContext()->setContextProperty("back", &pers);
	engine.rootContext()->setContextProperty("PersModel", pers.pers());
	engine.rootContext()->setContextProperty("PersModelChamps", pers.persChamp());

	const QUrl url(u"qrc:/res/qml/main.qml"_qs);
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
					 &app, [url](QObject *obj, const QUrl &objUrl) {
		if (!obj && url == objUrl)
			QCoreApplication::exit(-1);
	}, Qt::QueuedConnection);
	engine.load(url);

	return app.exec();
}
