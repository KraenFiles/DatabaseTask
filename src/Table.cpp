#include "Table.h"

namespace DataBase { namespace Data {

TableLine::TableLine(const QString & tableName)
    :m_tableName(tableName)
{

}

void TableLine::registrField(ITableField *field)
{
    m_fields.insert(field->name(), field);
}

}} // namespace DataBase::Data