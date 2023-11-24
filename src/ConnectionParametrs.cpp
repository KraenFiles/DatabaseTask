#include "ConnectionParametrs.h"

namespace Database
{
    ConnectionParameters ConnectionParameters::fromSqlDatabase(const QSqlDatabase &database)
    {
        return {database.driverName(), database.hostName(), (quint16)database.port(), database.databaseName(),
                database.userName(), database.password(), database.connectOptions()};
    }

    bool ConnectionParameters::isValid() const
    {
        return !driver.isEmpty() && !hostName.isEmpty() && !userName.isEmpty() && port != 0;
    }

    QSqlDatabase ConnectionParameters::createSqlDatabase(const QString &connectionName) const
    {
        QSqlDatabase db = QSqlDatabase::addDatabase(driver, connectionName);
        db.setHostName(hostName);
        db.setPort(port);
        db.setDatabaseName(databaseName);
        db.setUserName(userName);
        db.setPassword(password);
        db.setConnectOptions(connectOptions);
        return db;
    }
} // namespace Database