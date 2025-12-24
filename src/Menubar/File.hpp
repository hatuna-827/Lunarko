#pragma once

#include <QFont>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

class File
{
public:
  explicit File(QMenuBar *menubar, QFont *font);

  QAction *openAction() const;
  QAction *saveAction() const;

private:
  QMenu *fileMenu;
  QAction *open;
  QAction *save;
};
