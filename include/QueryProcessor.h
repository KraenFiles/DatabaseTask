#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSharedPointer>

#include "Query.h"

namespace Database{
class QueryProcessor
{
public:
    QueryProcessor(QSqlDatabase database);
    ~QueryProcessor() = default;

    template<typename Type>
    QList<QSharedPointer<Type>> select(Query::BaseQuery &&query);
    template<typename Type>
    int remove(Query::BaseQuery &&query);

private:
    QSqlDatabase m_database;
};

template <typename Type>
inline QList<QSharedPointer<Type>> QueryProcessor::select(Query::BaseQuery &&query)
{
    QList<QSharedPointer<Type>> result;
    QSqlQuery sqlQuery = query.query();
    QSqlRecord record = sqlQuery.record();
    while ( sqlQuery.next() ) {
        QSharedPointer<Type> newObject(new Type);
        for ( int i = 0; i < record.count(); ++i ) {
            QString fieldName = record.field( i ).name();
            Data::ITableField * field = newObject->field( fieldName );
            if(field != nullptr)
            {
                field->setValue(sqlQuery.value( i ));
            }
        }
        result.append(newObject);
    }
    return result;
}

template<typename Type>
inline int QueryProcessor::remove(Query::BaseQuery && query)
{
    QSqlQuery sqlQuery = query.query();
    if ( !sqlQuery.exec() ) {
        //FixMe: Set exeption
    }
    return sqlQuery.numRowsAffected();
}

} // namespace Database

#endif