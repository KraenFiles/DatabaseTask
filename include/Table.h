#ifndef TABLE_H
#define TABLE_H

#include "TableField.h"

#include <QMap>
#include <QList>

#include "TableMacro.h"

namespace DataBase { namespace Data {

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

using Table = QList<TableLine>;

}} // namespace DataBase::Data

#endif