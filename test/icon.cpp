
#include <QApplication>
#include <QMainWindow>
#include <QFile>
#include <QIcon>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QIcon icon(":/icons/favicon.png");
	qDebug() << "icon isNull:" << icon.isNull();

	QFile f(":/icons/favicon.png");
	qDebug() << "resource exists:" << f.exists();

	app.setWindowIcon(icon);

	qDebug() << "exe path:" << QCoreApplication::applicationFilePath();

	QDir dir(":/");
	qDebug() << dir.entryList(QDir::AllEntries);

	QMainWindow window;
	window.show();

	return app.exec();
}
