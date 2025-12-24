#pragma once

#include <QWidget>
#include <QFont>
#include <QPalette>

class QPlainTextEdit;

class Editor : public QWidget
{
    Q_OBJECT

public:
    explicit Editor(QWidget *parent = nullptr);
    void setFontPointSize(int pt);
    int fontPointSize() const;

public slots:
    void zoomIn();
    void zoomOut();
    void zoomReset();

private:
    QPlainTextEdit *editor;
    QFont font;
    QPalette color;
    int EditorDefaultFontSite;
};
