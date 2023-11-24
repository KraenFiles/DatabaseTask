#include "Condition.h"

namespace Database{ namespace Query {

Condition::Condition(const QString &condition)
    :m_condition(condition)
{
}

Condition::Condition(const QString &condition, const QString &field, const QVariant &value)
    :m_condition( QString{"(%1 %2 %3)"}.arg(field, condition, value.toString()) )
{
}

Condition Condition::operator&&(const Condition &right) const
{
    return { this->condition() + QString(" AND ") + right.condition() };
}

Condition Condition::operator||(const Condition &right) const
{
    return { this->condition() + QString(" OR ") + right.condition() };
}

}} // namespace Database::Query