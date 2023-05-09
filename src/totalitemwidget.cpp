
#include "totalitemwidget.h"

#include "bootstrap.h"
#include "inlinestyle.h"

#include <sstream>
#include <iomanip>


#include <Wt/WText.h>
#include <Wt/WLength.h>


using namespace Wt;


TotalItemWidget::TotalItemWidget(const std::string &imgUrl,
                                 const std::string &Name,
                                 const std::string &barColor)
{
    if( Name == "Muharrem İNCE" || Name == "Sinan OĞAN" ){
        setAttributeValue(Style::style,Style::background::color::rgba(175,175,175));
    }else{
        setAttributeValue(Style::style,Style::background::color::rgba(200,200,200));
    }
    setHeight(200);

    auto textAName = this->addWidget(cpp14::make_unique<WText>("<b>"+Name+"</b>"));
    textAName->addStyleClass(Bootstrap::Grid::col_full_12);
    textAName->setHeight(30);

    auto imgContainer = this->addNew<WContainerWidget>();
    imgContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                Bootstrap::Grid::Medium::col_md_6+
                                Bootstrap::Grid::Small::col_sm_6+
                                Bootstrap::Grid::ExtraSmall::col_xs_6);
    imgContainer->setHeight(170);
    imgContainer->setAttributeValue(Style::style,Style::background::url(imgUrl)+
                                                      Style::background::repeat::norepeat+
                                                      Style::background::position::center_center+
                                                      Style::background::size::contain);

    auto container = addNew<WContainerWidget>();
    container->addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                             Bootstrap::Grid::Medium::col_md_6+
                             Bootstrap::Grid::Small::col_sm_6+
                             Bootstrap::Grid::ExtraSmall::col_xs_6);
    container->setPositionScheme(PositionScheme::Relative);
    container->setHeight(170);

    mPercentBar = container->addNew<WContainerWidget>();

    mPercentBar->setPositionScheme(PositionScheme::Absolute);
    mPercentBar->setHeight(50);
    mPercentBar->setOffsets(0,Side::Bottom);
    mPercentBar->setWidth(75);
    mPercentBar->setAttributeValue(Style::style,Style::background::color::color(barColor));

    mPercentText = mPercentBar->addNew<WText>();
    mPercentText->setPositionScheme(PositionScheme::Absolute);
    mPercentText->setOffsets(10,Side::Left);
    mPercentText->setOffsets(0,Side::Bottom);
//    mPercentText->setZIndex(5);
}

void TotalItemWidget::setPercent(const double &barPercent)
{
    mPercentBar->setHeight(WLength(WString("{1}%").arg(barPercent).toUTF8()));

    std::ostringstream streamObj3;
    // Set Fixed -Point Notation
    streamObj3 << std::fixed;
    // Set precision to 2 digits
    streamObj3 << std::setprecision(2);
    //Add double to stream
    streamObj3 << barPercent;
    // Get string from output string stream
    std::string strObj3 = streamObj3.str();

    mPercentText->setText(WString("<h4><b>{1}%</b></h4>").arg(strObj3));
}

