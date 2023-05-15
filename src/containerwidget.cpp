
#include "containerwidget.h"

#include "src/inlinestyle.h"
#include "src/bootstrap.h"

#include <random>


#include <Wt/WHBoxLayout.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WSignal.h>
#include <Wt/WApplication.h>

ContainerWidget::ContainerWidget()
{

}

DialogContainerWidget *ContainerWidget::createFlatDialog(const std::string &title, const bool &autoDel)
{
    auto container = Wt::WApplication::instance()->root()->addNew<DialogContainerWidget>(title);
    container->setId("flatDialog");
    container->setPositionScheme(PositionScheme::Fixed);
    container->setWidth(WLength("100%"));
    container->setHeight(WLength("100%"));
    container->addStyleClass("newDialog");
    container->setContentAlignment(AlignmentFlag::Center);

    if( autoDel ){
        container->Rejected().connect([=](){
            Wt::WApplication::instance()->root()->removeWidget(container);
        });
    }

    return container;
}


void ContainerWidget::removeDialog(DialogContainerWidget *removedContainer)
{
    WApplication::instance()->root()->removeWidget(removedContainer);

}

int ContainerWidget::getRandom(const int &min, const int &max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);
}











DialogContainerWidget::DialogContainerWidget(const std::string &title)
{

    contentContainer = this->addNew<WContainerWidget>();
    contentContainer->setMaximumSize(1024,WLength::Auto);
    contentContainer->setPositionScheme(PositionScheme::Relative);
    contentContainer->setHeight(WLength("100%"));
    contentContainer->setWidth(WLength("100%"));


    auto vLayout = contentContainer->setLayout(cpp14::make_unique<WVBoxLayout>());
    vLayout->addStretch(1);

    auto mTitleContainer = vLayout->addWidget(cpp14::make_unique<WContainerWidget>());
    mTitleContainer->addNew<WText>(title)->setMargin(0,Side::Bottom);
    mTitleContainer->addStyleClass(Bootstrap::ContextualBackGround::bg_primary);

    mContent = vLayout->addWidget(cpp14::make_unique<WContainerWidget>());
    mContent->setAttributeValue(Style::style,Style::background::color::color(Style::color::White::AliceBlue));
    mContent->setMaximumSize(WLength::Auto,WLength::Auto);
    mContent->addStyleClass(Bootstrap::Grid::row);
    mContent->setMargin(0,Side::Top);
    mContent->setPadding(15,Side::Top|Side::Bottom);
    mContent->setContentAlignment(AlignmentFlag::Center);


    auto footer = vLayout->addWidget(cpp14::make_unique<WContainerWidget>());
    footer->setMaximumSize(WLength::Auto,50);
    footer->setAttributeValue(Style::style,Style::background::color::rgba(255,255,255,0.75));

    auto hLayout = footer->setLayout(cpp14::make_unique<WHBoxLayout>());

    auto acceptContainer = hLayout->addWidget(cpp14::make_unique<WContainerWidget>());
    acceptContainer->addStyleClass(Bootstrap::Button::Primary);
    acceptContainer->setPadding(5,Side::Top|Side::Bottom);
    acceptContainer->addNew<WText>("<b>Kaydet</b>",TextFormat::UnsafeXHTML);
    acceptContainer->decorationStyle().setCursor(Cursor::PointingHand);

    acceptContainer->clicked().connect([=](){
        _Accepted.emit(NoClass());
    });

    auto closeContainer = hLayout->addWidget(cpp14::make_unique<WContainerWidget>());
    closeContainer->addStyleClass(Bootstrap::Button::Default);
    closeContainer->setPadding(5,Side::Top|Side::Bottom);
    closeContainer->addNew<WText>("<b>Kapat</b>",TextFormat::UnsafeXHTML);
    closeContainer->decorationStyle().setCursor(Cursor::PointingHand);
    closeContainer->clicked().connect([=](){
        _Rejected.emit(NoClass());
    });
    vLayout->addStretch(1);
}

WContainerWidget *DialogContainerWidget::Content()
{
    return mContent;
}

void DialogContainerWidget::setContentWidth(const WLength &value)
{
    contentContainer->setWidth(value);
}

Signal<NoClass> &DialogContainerWidget::Accepted()
{
    return _Accepted;
}

Signal<NoClass> &DialogContainerWidget::Rejected()
{
    return _Rejected;
}
