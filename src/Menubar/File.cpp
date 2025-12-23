#include "File.hpp"

File::File(QMenuBar *menubar)
    : fileMenu(menubar->addMenu("File")),
      open(fileMenu->addAction("Open")),
      save(fileMenu->addAction("Save"))
{
  open->setShortcut(QKeySequence::fromString("Ctrl+s"));
  save->setShortcut(QKeySequence::fromString("Ctrl+o"));
}

QAction *File::openAction() const { return open; }
QAction *File::saveAction() const { return save; }
