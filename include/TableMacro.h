#ifndef TABLEMACRO_H
#define TABLEMACRO_H

#define DECLARATE_FIELD(type, member, name) Database::Data::TableField<type> member = {#name, this};

#define DECLARATE_TABLE(member, name, fields)                   \
    class member : public Database::Data::TableLine             \
    {                                                           \
        public:                                                 \
        fields;                                                 \
                                                                \
        member()                                                \
            : Database::Data::TableLine(#name)                  \
        {}                                                      \
                                                                \
        static member & fields()                                \
        {                                                       \
            static member line;                                 \
            return line;                                        \
        }                                                       \
    }                   

#endif