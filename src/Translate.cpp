#include "Translate.hpp"
#include "Config.hpp"

QString Translate::lang;
QJsonObject Translate::language;
QJsonObject Translate::translate;

void Translate::setLang()
{
  lang = Config::stringValue("language");
  language = Config::loadJson("config/translate.json");
  if (language.contains(lang))
  {
    translate = language[lang].toObject();
  }
  else
  {
    translate = {};
  }
}

QString Translate::get(const QString &key)
{
  if (translate.contains(key))
    return translate[key].toString(key);
  return key;
}