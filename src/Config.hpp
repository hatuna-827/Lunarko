#pragma once

#include <QJsonObject>
#include <QString>

class Config
{
public:
    static void load();
    static void save();
    static QJsonObject loadJson(const QString &path);

    static int intValue(const QString &key);
    static QString stringValue(const QString &key);

    static void setValue(const QString &key, const QJsonValue &value);

private:
    static QJsonObject s_defaults;
    static QJsonObject s_user;
};
