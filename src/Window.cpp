#include "Window.hpp"
#include "Editor.hpp"
#include "Menubar/Menubar.hpp"
#include "Config.hpp"

#include <QIcon>

Window::Window(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Lunarko");
    setWindowIcon(QIcon(":/icons/favicon.png"));
    Menubar menubar(this);
    Editor *editor = new Editor(this);
    setCentralWidget(editor);

    connect(menubar.zoomInAction(),
            &QAction::triggered,
            editor,
            &Editor::zoomIn);

    connect(menubar.zoomOutAction(),
            &QAction::triggered,
            editor,
            &Editor::zoomOut);

    connect(menubar.zoomResetAction(),
            &QAction::triggered,
            editor,
            &Editor::zoomReset);

    resize(Config::intValue("window.width"), Config::intValue("window.height"));
}

Window::~Window()
{
    Config::save();
}
