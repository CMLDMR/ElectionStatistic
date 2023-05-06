
#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include <Wt/WTheme.h>
#include <Wt/WBootstrap3Theme.h>
#include <mongocxx/database.hpp>
#include <mongocxx/client.hpp>

#include <mongocore/db.h>

namespace Sandik {
class ListItemWidget;
}
class TotalVoteWidget;

class MainApplication : public Wt::WApplication
{
public:
    MainApplication(const Wt::WEnvironment &env);


    void addSandikDialog();


private:
    std::shared_ptr<Wt::WBootstrap3Theme> mTheme;

    mongocxx::client* mClient;
    mongocxx::database __mDB;
    MongoCore::DB* mDB;

    TotalVoteWidget* mTotalVoteWidget{nullptr};
    Sandik::ListItemWidget* mSandikManagerWidget{nullptr};

    std::map<std::string,std::string> mTelList{{"05079970925","YO"},
                                                {"05383537954","EE"},
                                                {"05304682318","TA"},
                                                {"05439603687","HEK"},
                                                {"05385675177","MÇ"},
                                                {"05426809750","TEŞ"},
                                                {"05453269464","KY"},
                                                {"05079343393","RGY"},
                                                {"05318279999","AB"},
                                                {"05063347123","ŞK"},
                                                };
};

#endif // MAINAPPLICATION_H
