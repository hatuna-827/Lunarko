#include "Editor.hpp"
#include "Config.hpp"

#include <QVBoxLayout>
#include <QPlainTextEdit>

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

    QPalette color = editor->palette();
    color.setColor(QPalette::Base, QColor(Config::stringValue("editor.background")));
    color.setColor(QPalette::Text, QColor(Config::stringValue("editor.foreground")));
    color.setColor(QPalette::Highlight, QColor((Config::stringValue("editor.selectionBackground"))));
    color.setColor(QPalette::HighlightedText, QColor((Config::stringValue("editor.selectionForeground"))));
    editor->setPalette(color);

    editor->setTabStopDistance(
        QFontMetrics(font).horizontalAdvance(' ') * Config::intValue("editor.tabWidth"));
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
