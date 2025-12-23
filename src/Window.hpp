#pragma once

#include <QMainWindow>

class Editor;
class Menubar;

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private:
    Editor *editor;
    Menubar *menubar;
};
