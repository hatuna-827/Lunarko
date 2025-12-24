#include "Config.hpp"

#include <QFile>
#include <QJsonDocument>

QJsonObject Config::s_defaults;
QJsonObject Config::s_user;

QJsonObject Config::loadJson(const QString &path)
{
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly))
        return {};
    return QJsonDocument::fromJson(f.readAll()).object();
}

void Config::load()
{
    s_defaults = loadJson("config/default.json");
    s_user = loadJson("config/settings.json");
}

void Config::save()
{
    QFile f("config/settings.json");
    if (!f.open(QIODevice::WriteOnly))
        return;
    QJsonDocument doc(s_user);
    f.write(doc.toJson(QJsonDocument::Indented));
}

int Config::intValue(const QString &key)
{
    int fallback = 0;
    if (s_user.contains(key))
        return s_user[key].toInt(fallback);
    if (s_defaults.contains(key))
        return s_defaults[key].toInt(fallback);
    return fallback;
}

QString Config::stringValue(const QString &key)
{
    QString fallback = "";
    if (s_user.contains(key))
        return s_user[key].toString(fallback);
    if (s_defaults.contains(key))
        return s_defaults[key].toString(fallback);
    return fallback;
}

void Config::setValue(const QString &key, const QJsonValue &value)
{
    s_user[key] = value;
}
