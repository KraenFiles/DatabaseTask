#ifndef TABLEMACRO_H
#define TABLEMACRO_H

#define DECLARATE_FIELD(type, member, name) DataBase::Data::TableField<type> member = {#name, this};

#define DECLARATE_TABLE(member, name, fields...)                \
    class member : public DataBase::Data::TableLine             \
    {                                                           \
        public:                                                 \
        fields;                                                 \
                                                                \
        member()                                                \
            : DataBase::Data::TableLine(#name)                  \
        {}                                                      \
                                                                \
        static member & Fields()                                \
        {                                                       \
            static member line;                                 \
            return line;                                        \
        }                                                       \
    }                   

#endif