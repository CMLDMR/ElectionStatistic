
#include "mainapplication.h"


#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include "bootstrap.h"
#include "inlinestyle.h"

#include <mongocxx/uri.hpp>
#include <mongocxx/exception/exception.hpp>
#include "../url.h"

#include <mongocore/item.h>

MainApplication::MainApplication(const Wt::WEnvironment &env)
    :Wt::WApplication(env)
{


    try {
        mClient = new mongocxx::client(mongocxx::uri(_url));
    } catch (mongocxx::exception &e) {

        std::cout << e.what() <<"\n";
        return;
    }

    mDB = mClient->database(_db);

    auto cursor = mDB.collection("AltBirimler").find(bsoncxx::builder::basic::document{}.view());

    for( const auto &item : cursor ){
        std::cout << bsoncxx::to_json(item) << "\n";
    }

    mTheme = std::make_shared<Wt::WBootstrap3Theme>();
    mTheme.get()->setResponsive(true);


    wApp->setTheme(mTheme);


    auto container = root()->addNew<Wt::WContainerWidget>();
    container->addStyleClass(Bootstrap::ImageShape::img_rounded);
    container->setAttributeValue(Style::style,Style::background::color::color("red"));
    container->addNew<Wt::WText>("dfg");
}
