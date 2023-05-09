
#include "totalvotewidget.h"

#include <Wt/WText.h>

#include "totalitemwidget.h"
#include "bootstrap.h"
#include "widget.h"
#include "db.h"



using namespace Wt;

TotalVoteWidget::TotalVoteWidget()
{
    auto title = this->addWidget(cpp14::make_unique<WText>("<b>Ak Parti Serik İlçe Teşkilatı(Cumhurbaşkanlığı Serik Sonuçları)</b>"));
    title->addStyleClass(Bootstrap::Grid::col_full_12);
    this->setContentAlignment(AlignmentFlag::Center);

    mRTEWidget = addVoteWidget("rte.jpg","Recep Tayyip ERDOĞAN","orange");
    mMIWidget = addVoteWidget("mi.jpg","Muharrem İNCE","lightblue");
    mKKWidget = addVoteWidget("kk.jpg","Kemal KILIÇDAROĞLU","red");
    mSOWidget = addVoteWidget("so.jpg","Sinan OĞAN","CornflowerBlue");

    this->updatePercent();

}

TotalItemWidget *TotalVoteWidget::addVoteWidget(const std::string &imgUrl , const std::string &name, const std::string &barColor)
{
    auto container = this->addWidget(cpp14::make_unique<TotalItemWidget>(imgUrl,name,barColor));

    container->addStyleClass(Bootstrap::Grid::ExtraSmall::col_xs_6+
                             Bootstrap::Grid::Small::col_sm_6+
                             Bootstrap::Grid::Medium::col_md_3+
                             Bootstrap::Grid::Large::col_lg_3);

    return container;
}

void TotalVoteWidget::updatePercent()
{


    Sandik::Sandik filter;
    auto list = Global::DB::instance()->find(filter,1000);

    double rte{0};
    double mi{0};
    double kk{0};
    double so{0};
    double diger{0};
    double total{0};

    if( list ){
        Sandik::Sandik item;
        for( const auto &_item : list.value() ){
            item.setDocumentView(_item);
            rte += item.getRTE();
            mi += item.getMI();
            kk += item.getKK();
            so += item.getSO();
            diger += item.getDiger();
        }
        total = rte + mi + kk + so + diger;
    }

    mRTEWidget->setPercent(rte/total*100);
    mMIWidget->setPercent(mi/total*100);
    mKKWidget->setPercent(kk/total*100);
    mSOWidget->setPercent(so/total*100);
}

