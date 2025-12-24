#include "View.hpp"
#include "../Translate.hpp"

View::View(QMenuBar *menubar, QFont *font)
    : viewMenu(menubar->addMenu(Translate::get("View"))),
      zoomIn(viewMenu->addAction(Translate::get("Zoom In"))),
      zoomOut(viewMenu->addAction(Translate::get("Zoom Out"))),
      zoomReset(viewMenu->addAction(Translate::get("Reset Zoom")))
{
  viewMenu->setFont(*font);
  QList<QKeySequence> ZoomInShortcutKey;
  ZoomInShortcutKey << QKeySequence::fromString("Ctrl++")
                    << QKeySequence::fromString("Ctrl+;");
  zoomIn->setShortcuts(ZoomInShortcutKey);
  zoomOut->setShortcut(QKeySequence::fromString("Ctrl+-"));
  zoomReset->setShortcut(QKeySequence::fromString("Ctrl+0"));
}

QAction *View::zoomInAction() const { return zoomIn; }
QAction *View::zoomOutAction() const { return zoomOut; }
QAction *View::zoomResetAction() const { return zoomReset; }
