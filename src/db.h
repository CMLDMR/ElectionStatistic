
#ifndef GLOBAL_DB_H
#define GLOBAL_DB_H

#include <mongocore/db.h>


namespace Global {

class DB
{
public:

    static MongoCore::DB *instance();

    static void setDB( MongoCore::DB* __mDB );


private:
    DB();

    static DB* mDB;

    MongoCore::DB* _mDB;
};

} // namespace Global

#endif // GLOBAL_DB_H
