
#include "totalvotewidget.h"

#include <Wt/WText.h>

#include "totalitemwidget.h"
#include "bootstrap.h"
#include "widget.h"
#include "db.h"
#include "inlinestyle.h"


using namespace Wt;

TotalVoteWidget::TotalVoteWidget(MongoCore::DB *_db)
    :mDB(_db)
{

    auto logoContainer = this->addWidget(std::make_unique<WContainerWidget>());
    logoContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    logoContainer->setHeight(50);
    logoContainer->setAttributeValue(Style::style,Style::background::url("logo.png")+Style::background::position::center_center+Style::background::repeat::norepeat+Style::background::size::contain);


    auto title = this->addWidget(cpp14::make_unique<WText>("<b>Ak Parti Serik İlçe Teşkilatı(Cumhurbaşkanlığı 2. Tur Serik Sonuçları)</b>"));
    title->addStyleClass(Bootstrap::Grid::col_full_12);
    this->setContentAlignment(AlignmentFlag::Center);

    mRTEWidget = addVoteWidget("rte.jpg","Recep Tayyip ERDOĞAN","orange");
//    mMIWidget = addVoteWidget("mi.jpg","Muharrem İNCE","lightblue");
    mKKWidget = addVoteWidget("kk.jpg","Kemal KILIÇDAROĞLU","red");
//    mSOWidget = addVoteWidget("so.jpg","Sinan OĞAN","CornflowerBlue");

    auto girilenSandikContainer = this->addWidget(std::make_unique<WContainerWidget>());
    girilenSandikContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    girilenSandikContainer->setHeight(25);
    girilenSandikContainer->setPositionScheme(PositionScheme::Relative);
    girilenSandikContainer->setMargin(5,Side::Top|Side::Bottom);

    mPercentWidget = girilenSandikContainer->addWidget(std::make_unique<WContainerWidget>());
    mPercentWidget->setPositionScheme(PositionScheme::Absolute);
    mPercentWidget->setHeight(25);
    mPercentWidget->setWidth(WLength("0%"));
    mPercentWidget->setAttributeValue(Style::style,Style::background::color::color(Style::color::Orange::Coral));


    mPercentText = girilenSandikContainer->addWidget(std::make_unique<WText>("Açılan Sandık Oranı: 0"));
    mPercentText->setPositionScheme(PositionScheme::Absolute);
    mPercentText->setOffsets(0,Side::Top);
    mPercentText->setOffsets(25,Side::Left);


    this->updatePercent();

}

TotalItemWidget *TotalVoteWidget::addVoteWidget(const std::string &imgUrl , const std::string &name, const std::string &barColor)
{
    auto container = this->addWidget(cpp14::make_unique<TotalItemWidget>(imgUrl,name,barColor));

    container->addStyleClass(Bootstrap::Grid::ExtraSmall::col_xs_6+
                             Bootstrap::Grid::Small::col_sm_6+
                             Bootstrap::Grid::Medium::col_md_6+
                             Bootstrap::Grid::Large::col_lg_6);

    return container;
}

void TotalVoteWidget::updatePercent()
{


    if( !mDB ){
        std::cout << "\nMongo DB Error: NO DB\n";
    }
    Sandik::Sandik filter;

    auto list = mDB->find(filter,1000);

    double rte{0};
    double mi{0};
    double kk{0};
    double so{0};
    double diger{0};
    double total{0};

    double sandikSayisi{0};
    double acilansandikSayisi{0};



    if( list ){
        Sandik::Sandik item;
        for( const auto &_item : list.value() ){
            item.setDocumentView(_item);
            rte += item.getRTE();
            mi += item.getMI();
            kk += item.getKK();
            so += item.getSO();
            diger += item.getDiger();

            if( item.getRTE() > 0 || item.getDiger() > 0 || item.getKK() > 0 ){
                acilansandikSayisi++;
            }
            sandikSayisi++;
        }
        total = rte + mi + kk + so + diger;
        auto percent = acilansandikSayisi/sandikSayisi*100;
        mPercentWidget->setWidth(WLength(WString("{1}%").arg(acilansandikSayisi/sandikSayisi*100).toUTF8()));
        mPercentText->setText(WString("Açılan Sandık Oranı: %{1}  |  {2}/{3}").arg((int)(acilansandikSayisi/sandikSayisi*100.)).arg(acilansandikSayisi).arg(sandikSayisi));
        mPercentText->setOffsets(WLength(WString("{1}%").arg(percent < 25 ? percent : 25).toUTF8()),Side::Left);

    }
//    total = total <= 0 ?

    mRTEWidget->setPercent(rte/total*100);
//    mMIWidget->setPercent(mi/total*100);
    mKKWidget->setPercent(kk/total*100);
//    mSOWidget->setPercent(so/total*100);
}

