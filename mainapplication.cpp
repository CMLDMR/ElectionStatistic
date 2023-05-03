
#include "mainapplication.h"


#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include "bootstrap.h"
#include "inlinestyle.h"


MainApplication::MainApplication(const Wt::WEnvironment &env)
    :Wt::WApplication(env)
{



    mTheme = std::make_shared<Wt::WBootstrap3Theme>();
    mTheme.get()->setResponsive(true);


    wApp->setTheme(mTheme);


    auto container = root()->addNew<Wt::WContainerWidget>();
    container->addStyleClass(Bootstrap::ImageShape::img_rounded);
    container->setAttributeValue(Style::style,Style::background::color::color("red"));
    container->addNew<Wt::WText>("dfg");
}
