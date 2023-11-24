#ifndef QUERY_H
#define QUERY_H

#include "Condition.h"

namespace Database{ namespace Query {

    class BaseQuery
    {
    public:
        BaseQuery(const QString &query)
            : m_query(query)
            , m_where()
        {}
        virtual ~BaseQuery() = default;

        virtual inline QString query() const { return m_query+" "+m_where; }

        inline BaseQuery & where(const Condition & condition) { this->m_where = condition.condition(); return *this; }
    private:
        QString m_query;
        QString m_where;
    };

    template<typename Type>
    class Select : public BaseQuery
    {
    public:
        Select();
        ~Select() = default;

    private:
        QString constructionSelect();
    };

    /*template<typename Type>
    class Update
    {
    public:
        Update(const Type &line);
        ~Update() = default;

    private:
        QString constructionUpdate(const Type &line);
    };*/
    
    template<typename Type>
    class Delete
    {
    public:
        Delete();
        ~Delete() = default;

    private:
        QString constructionDelete();
    };

template <typename Type>
Select<Type>::Select()
    :BaseQuery(constructionSelect())
{

}

template <typename Type>
QString Select<Type>::constructionSelect()
{
    QString result = { "SELECT " };
    Type line = Type::fields();
    QStringList fields = line.fieldNames();
    for(const QString &field : fields)
    {
        result.append( field + QString{", "} );
    }
    result.chop(2);
    result.append( QString{" FROM "} + line.tableName() );

    return result;
}

template <typename Type>
Delete<Type>::Delete()
    :BaseQuery(constructionDelete())
{
}

template <typename Type>
QString Delete<Type>::constructionDelete()
{
    Type line = Type::fields();
    return QString("DELETE FROM " + line.tableName());
}
}} // namespace Database::Query

#endif