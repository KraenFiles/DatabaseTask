#ifndef DATABASEFACTORY_H
#define DATABASEFACTORY_H

#include <QSqlDatabase>
#include <QString>

namespace Database
{
    struct ConnectionParameters
    {
        QString driver;
        QString hostName;
        quint16 port;
        QString databaseName;
        QString userName;
        QString password;
        QString connectOptions;

        static ConnectionParameters fromSqlDatabase(const QSqlDatabase &database);

        bool isValid() const;

        QSqlDatabase createSqlDatabase(
            const QString &connectionName = QLatin1String(QSqlDatabase::defaultConnection)) const;
    };
} // namespace Database

#endif