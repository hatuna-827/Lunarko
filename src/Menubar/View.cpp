#include "View.hpp"

View::View(QMenuBar *menubar, QFont *font)
    : viewMenu(menubar->addMenu("View")),
      zoomIn(viewMenu->addAction("Zoom In")),
      zoomOut(viewMenu->addAction("Zoom Out")),
      zoomReset(viewMenu->addAction("Reset Zoom"))
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
