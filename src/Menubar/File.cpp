#include "File.hpp"
#include "../Translate.hpp"

File::File(QMenuBar *menubar, QFont *font)
    : fileMenu(menubar->addMenu(Translate::get("File"))),
      open(fileMenu->addAction(Translate::get("Open"))),
      save(fileMenu->addAction(Translate::get("Save")))
{
  fileMenu->setFont(*font);
  open->setShortcut(QKeySequence::fromString("Ctrl+s"));
  save->setShortcut(QKeySequence::fromString("Ctrl+o"));
}

QAction *File::openAction() const { return open; }
QAction *File::saveAction() const { return save; }
