#pragma once

#include <QMenuBar>
#include <QMenu>
#include <QAction>

class View
{
public:
  explicit View(QMenuBar *menubar);

  QAction *zoomInAction() const;
  QAction *zoomOutAction() const;
  QAction *zoomResetAction() const;

private:
  QMenu *viewMenu;
  QAction *zoomIn;
  QAction *zoomOut;
  QAction *zoomReset;
};
