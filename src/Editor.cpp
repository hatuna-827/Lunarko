#include "Editor.hpp"
#include "Config.hpp"

#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QFont>

Editor::Editor(QWidget *parent)
    : QWidget(parent),
      editor(new QPlainTextEdit(this)),
      EditorDefaultFontSite(Config::intValue("editor.fontSize"))
{
    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(editor);

    QFont font;
    font.setFamily(Config::stringValue("editor.fontFamily"));
    font.setPointSize(EditorDefaultFontSite);
    editor->setFont(font);

    editor->setTabStopDistance(
        QFontMetrics(font).horizontalAdvance(' ') * 4);
}

void Editor::setFontPointSize(int pt)
{
    EditorDefaultFontSite = pt;

    QFont font = editor->font();
    font.setPointSize(pt);
    editor->setFont(font);
}

int Editor::fontPointSize() const
{
    return EditorDefaultFontSite;
}

void Editor::zoomIn()
{
    editor->zoomIn(1);
}

void Editor::zoomOut()
{
    editor->zoomOut(1);
}

void Editor::zoomReset()
{
    setFontPointSize(EditorDefaultFontSite);
}
