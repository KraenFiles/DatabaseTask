#ifndef CONDITION_H
#define CONDITION_H

#include <QString>
#include <QVariant>

namespace Database{ namespace Query {

class Condition
{
public:
    Condition( const QString & condition );
    Condition( const QString & condition, const QString & field, const QVariant & value );

    Condition operator&&( const Condition & right ) const;
    Condition operator||( const Condition & right ) const;

    inline QString condition() const { return m_condition; }

private:
    QString m_condition;
};

}} // namespace Database::Query

#endif