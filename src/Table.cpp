#include "Table.h"

namespace Database { namespace Data {

TableLine::TableLine(const QString & tableName)
    :m_tableName(tableName)
{
}

void TableLine::registrField(ITableField *field)
{
    m_fields.insert(field->name(), field);
}

}} // namespace Database::Data