
#include "totalvotewidget.h"

#include <Wt/WText.h>

#include "totalitemwidget.h"
#include "bootstrap.h"

using namespace Wt;

TotalVoteWidget::TotalVoteWidget()
{
    auto title = this->addWidget(cpp14::make_unique<WText>("<b>Serik Akparti İlçe Teşkilatı</b>"));
    title->addStyleClass(Bootstrap::Grid::col_full_12);
    this->setContentAlignment(AlignmentFlag::Center);
    mRTEWidget = addVoteWidget("rte.jpg","Recep Tayyip ERDOĞAN","orange");
    mMIWidget = addVoteWidget("mi.jpg","Muharrem İNCE","lightblue");
    mKKWidget = addVoteWidget("kk.jpg","Kemal KILIÇDAROĞLU","red");
    mSOWidget = addVoteWidget("so.jpg","Sinan OĞAN","CornflowerBlue");

}

TotalItemWidget *TotalVoteWidget::addVoteWidget(const std::string &imgUrl , const std::string &name, const std::string &barColor)
{
    auto container = this->addWidget(cpp14::make_unique<TotalItemWidget>(imgUrl,name,barColor));

    container->addStyleClass(Bootstrap::Grid::ExtraSmall::col_xs_12+
                             Bootstrap::Grid::Small::col_sm_6+
                             Bootstrap::Grid::Medium::col_md_6+
                             Bootstrap::Grid::Large::col_lg_3);



    return container;
}

