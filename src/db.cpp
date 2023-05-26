
#include "db.h"
#include <mutex>



namespace Global {

std::once_flag mDBCallOnceFlag;

DB* DB::mDB{nullptr};

MongoCore::DB *DB::instance()
{
    return mDB->_mDB;
}

void DB::setDB(MongoCore::DB *__mDB)
{
    std::call_once(mDBCallOnceFlag,[=](){
        mDB = new DB();
        mDB->_mDB = __mDB;
    });
}

DB::DB()
{

}

} // namespace Global

