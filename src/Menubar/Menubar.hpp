#pragma once

#include <QMainWindow>
#include <QFont>

class File;
class View;

class Menubar
{
public:
  explicit Menubar(QMainWindow *window);

  QAction *openAction() const;
  QAction *saveAction() const;

  QAction *zoomInAction() const;
  QAction *zoomOutAction() const;
  QAction *zoomResetAction() const;

private:
  QMenuBar *menubar;
  QFont font;
  File *file;
  View *view;
};
