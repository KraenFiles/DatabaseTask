#ifndef ITABLEFIELD_H
#define ITABLEFIELD_H

#include <QString>
#include <QVariant>

namespace Database { namespace Data {

class ITableField
{
public:
    explicit ITableField( const QString & name );
    virtual ~ITableField() = default;

    inline const QString & name() const { return m_name; }

    virtual void setValue( const QVariant & value ) = 0;
    virtual QVariant value() const = 0;

private:
    QString m_name;
};

}} // namespace Database::Data

#endif