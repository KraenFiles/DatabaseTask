#ifndef TABLE_H
#define TABLE_H

#include "ITableField.h"

#include <QMap>
#include <QList>

#include "TableMacro.h"

namespace Database { namespace Data {

class TableLine
{
public:
    TableLine(const QString & tableName);

    inline const QString & tableName() const { return m_tableName; }

    inline QStringList fieldNames() const { return m_fields.keys(); }
    inline ITableField * field(const QString & name) { return m_fields[name]; }

    void registrField(ITableField * field);

private:
    QString m_tableName;
    QMap<QString, ITableField *> m_fields;
};

}} // namespace Database::Data

#endif