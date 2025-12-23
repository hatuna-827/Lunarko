#include "Menubar.hpp"
#include "File.hpp"
#include "View.hpp"
#include "../Config.hpp"

#include <QMenuBar>

Menubar::Menubar(QMainWindow *window)
{
  QFont font(Config::stringValue("menubar.fontFamily"));
  font.setPointSize(Config::intValue("menubar.fontSize"));
  QMenuBar *menubar = window->menuBar();
  menubar->setFont(font);
  file = new File(menubar);
  view = new View(menubar);
}

QAction *Menubar::openAction() const { return file->openAction(); }
QAction *Menubar::saveAction() const { return file->saveAction(); }

QAction *Menubar::zoomInAction() const { return view->zoomInAction(); }
QAction *Menubar::zoomOutAction() const { return view->zoomOutAction(); }
QAction *Menubar::zoomResetAction() const { return view->zoomResetAction(); }
