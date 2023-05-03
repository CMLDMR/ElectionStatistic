
#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include <Wt/WTheme.h>
#include <Wt/WBootstrap3Theme.h>
#include <mongocxx/database.hpp>
#include <mongocxx/client.hpp>



class MainApplication : public Wt::WApplication
{
public:
    MainApplication(const Wt::WEnvironment &env);



private:
    std::shared_ptr<Wt::WBootstrap3Theme> mTheme;

    mongocxx::client* mClient;
    mongocxx::database mDB;
};

#endif // MAINAPPLICATION_H
