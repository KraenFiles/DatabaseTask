#ifndef TABLEFIELD_H
#define TABLEFIELD_H

#include "ITableField.h"
#include "Table.h"

namespace DataBase { namespace Data {

template<typename T>
class TableField : public ITableField
{
public:
    TableField(const QString & name, TableLine * table);
    TableField(const TableField & other) = delete;
    TableField(const TableField & other, TableLine * table);
    ~TableField() override = default;

    inline T get() const { return m_value.value<T>(); }
    inline void set(const T & value) { m_value = QVariant::fromValue<T>(value); }

    inline QVariant value() const override { return m_value; };
    inline void setValue(const QVariant & value) override { m_value = value; }
    
private:
    QVariant m_value;
};

template <typename T>
inline TableField<T>::TableField(const QString &name, TableLine * table)
    : ITableField(name)
    , m_value()
{
    table->registrField(this);
}

template<typename T>
inline TableField<T>::TableField(const TableField & other, TableLine * table)
    : ITableField(other)
    , m_value()
{
    table->registrField(this);
}

}} // namespace DataBase::Data

#endif