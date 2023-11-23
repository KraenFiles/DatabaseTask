#ifndef CITIESTABLE_H
#define CITIESTABLE_H

#include "Table.h"

namespace Database{ namespace Tables {

DECLARATE_TABLE(Cities, cities,
                DECLARATE_FIELD(QString, prefix, prefix)
                DECLARATE_FIELD(QString, name, name)
                DECLARATE_FIELD(QString, mapPoint, map_point)
                DECLARATE_FIELD(int, population, population)
                DECLARATE_FIELD(QString, country, country)
                DECLARATE_FIELD(float, lat, lat)
                DECLARATE_FIELD(float, lon, lon)
);

}} // namespace DataBase::Tables

#endif