#include "QueryProcessor.h"
namespace Database{
QueryProcessor::QueryProcessor(QSqlDatabase database)
    :m_database{database}
{
}
} // namespace Database