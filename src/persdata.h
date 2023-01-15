#ifndef PERSDATA_H
#define PERSDATA_H

#include <QObject>

class PersData
{
public:
	explicit PersData();

signals:

public:
	void setName(const QString &name) { mName = name; }
	void setColor(const QString &color) { mColor = color; }
	void setVisible(bool visible) { mVisible = visible; }

	QString name() const { return mName; }
	QString color() const { return mColor; }
	bool visible() const { return mVisible; }

private:
	QString mName;
	QString mColor;
	bool mVisible;

};

#endif // PERSDATA_H
