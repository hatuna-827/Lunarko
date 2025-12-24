#pragma once

#include <QMainWindow>

class Editor;
class Menubar;

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

private:
    Editor *editor;
    Menubar *menubar;
};
