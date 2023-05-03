
#include <Wt/WApplication.h>

#include <mongocxx/instance.hpp>

#include "mainapplication.h"


using namespace std;

int main(int argc, char *argv[])
{

    mongocxx::instance instance{};


    return Wt::WRun(argc,argv,[](const Wt::WEnvironment &env){
        return Wt::cpp14::make_unique<MainApplication>(env);
    });
}
