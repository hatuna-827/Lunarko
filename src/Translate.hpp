#pragma once

#include <QString>
#include <QJsonObject>

class Translate
{
public:
  static void setLang();
  static QString get(const QString &key);

private:
  static QString lang;
  static QJsonObject language;
  static QJsonObject translate;
};
