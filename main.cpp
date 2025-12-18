#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[])
{
	// window

	QApplication app(argc, argv);
	QMainWindow window;
	window.setWindowTitle("Lunarko");

	// editor

	int EditorDefaultFontSite = 14;

	auto *editor = new QTextEdit(&window);

	QFont font("MS Gothic");
	font.setPointSize(EditorDefaultFontSite);
	editor->setFont(font);

	window.setCentralWidget(editor);

	// menubar

	QFont menuFont;
	menuFont.setPointSize(14);
	window.menuBar()->setFont(menuFont);

	// menubar - file

	auto *fileMenu = window.menuBar()->addMenu("File");
	fileMenu->setFont(menuFont);

	auto *openAction = fileMenu->addAction("Open");
	QObject::connect(openAction, &QAction::triggered, [&]()
									 {
		QString fileName = QFileDialog::getOpenFileName(&window);
		if (fileName.isEmpty()) return;
		QFile file(fileName);
		if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			QTextStream in(&file);
			editor->setPlainText(in.readAll());
		} });

	auto *saveAction = fileMenu->addAction("Save");
	QObject::connect(saveAction, &QAction::triggered, [&]()
									 {
			QString fileName = QFileDialog::getSaveFileName(&window);
			if (fileName.isEmpty()) return;
			QFile file(fileName);
			if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
				QTextStream out(&file);
				out << editor->toPlainText();
			} });

	// menubar - view

	auto *viewMenu = window.menuBar()->addMenu("View");
	viewMenu->setFont(menuFont);

	// zoom in

	auto *zoomIn = viewMenu->addAction("Zoom In");
	QList<QKeySequence> ZoomInShortcutKey;
	ZoomInShortcutKey << QKeySequence::fromString("Ctrl++")
										<< QKeySequence::fromString("Ctrl+;");
	zoomIn->setShortcuts(ZoomInShortcutKey);
	QObject::connect(zoomIn, &QAction::triggered, [&]()
									 {
    QFont f = editor->font();
    f.setPointSize(f.pointSize() + 1);
    editor->setFont(f); });

	// zoom out

	auto *zoomOut = viewMenu->addAction("Zoom Out");
	zoomOut->setShortcut(QKeySequence::fromString("Ctrl+-"));
	QObject::connect(zoomOut, &QAction::triggered, [&]()
									 {
    QFont f = editor->font();
    f.setPointSize(std::max(1, f.pointSize() - 1));
    editor->setFont(f); });

	auto *zoomReset = viewMenu->addAction("Reset Zoom");
	zoomReset->setShortcut(QKeySequence::fromString("Ctrl+0"));
	QObject::connect(zoomReset, &QAction::triggered, [&]()
									 {
    QFont f = editor->font();
    f.setPointSize(EditorDefaultFontSite);
    editor->setFont(f); });

	// window

	window.resize(1200, 1000);
	window.show();
	return app.exec();
}
