#include "File.hpp"

File::File(QMenuBar *menubar, QFont *font)
    : fileMenu(menubar->addMenu("File")),
      open(fileMenu->addAction("Open")),
      save(fileMenu->addAction("Save"))
{
  fileMenu->setFont(*font);
  open->setShortcut(QKeySequence::fromString("Ctrl+s"));
  save->setShortcut(QKeySequence::fromString("Ctrl+o"));
}

QAction *File::openAction() const { return open; }
QAction *File::saveAction() const { return save; }
