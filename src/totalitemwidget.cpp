
#include "totalitemwidget.h"

#include "bootstrap.h"
#include "inlinestyle.h"


#include <Wt/WText.h>
#include <Wt/WLength.h>


using namespace Wt;


TotalItemWidget::TotalItemWidget(const std::string &imgUrl,
                                 const std::string &Name,
                                 const std::string &barColor)
{
    setAttributeValue(Style::style,Style::background::color::rgba(200,200,200));
    setHeight(50);

    this->setPositionScheme(PositionScheme::Relative);

    auto imgContainer = this->addNew<WContainerWidget>();
    imgContainer->setHeight(50);
    imgContainer->setWidth(50);
    imgContainer->setAttributeValue(Style::style,Style::background::url(imgUrl)+
                                                      Style::background::repeat::norepeat+
                                                      Style::background::position::center_center+
                                                      Style::background::size::contain);
    imgContainer->setPositionScheme(PositionScheme::Absolute);
    imgContainer->setOffsets(0,Side::Left|Side::Top);

    mPercentBar = addNew<WContainerWidget>();
    mPercentBar->setPositionScheme(PositionScheme::Absolute);
    mPercentBar->setHeight(25);
    mPercentBar->setOffsets(50,Side::Left);
    mPercentBar->setOffsets(0,Side::Bottom);
    mPercentBar->setAttributeValue(Style::style,Style::background::color::color(barColor));

    mPercentText = mPercentBar->addNew<WText>();
    mPercentText->setAttributeValue(Style::style,Style::color::color(Style::color::White::AliceBlue));
    mPercentText->setPositionScheme(PositionScheme::Absolute);
    mPercentText->setOffsets(0,Side::Right);
    mPercentText->setOffsets(-7,Side::Top);



    this->setPercent(5);
    this->addWidget(cpp14::make_unique<WText>("<b>"+Name+"</b>"));

}

void TotalItemWidget::setPercent(const double &barPercent)
{
    mPercentBar->setWidth(WLength(WString("{1}%").arg(barPercent).toUTF8()));
    mPercentText->setText(WString("<h4>{1}%</h4>").arg(barPercent));
    if( barPercent < 7 ){
        mPercentText->setAttributeValue(Style::style,Style::color::color(Style::color::Grey::Black));
        mPercentText->setOffsets(-30,Side::Right);
    }else{
        mPercentText->setOffsets(0,Side::Right);
        mPercentText->setAttributeValue(Style::style,Style::color::color(Style::color::White::AliceBlue));
    }


}

