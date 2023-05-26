
#include "widget.h"

#include "inlinestyle.h"
#include "bootstrap.h"

#include "src/db.h"

#include <Wt/WText.h>
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WLineEdit.h>
#include <Wt/WSpinBox.h>
#include <Wt/WGridLayout.h>
#include <Wt/WBreak.h>

#include <algorithm>



using namespace Wt;

namespace Sandik {

Sandik::Sandik()
    :MongoCore::Item(Key::SandikCollection)
{

}

Sandik::Sandik(const Sandik &other)
    :MongoCore::Item(other)
{
    this->setDocumentView(other.view());
}

Sandik &Sandik::setSandikNo( const int32_t &sandikNo )
{
    this->append(Key::sandikno,sandikNo);
    return *this;
}

Sandik &Sandik::setMahalle( const std::string &mahalle )
{
    this->append(Key::mahalle,mahalle);
    return *this;
}

Sandik &Sandik::setSandikAlanAdi(const std::string &sandikAlanAdi)
{
    this->append(Key::sandikAlanadi,sandikAlanAdi);
    return *this;
}

Sandik &Sandik::setrte(const int32_t &vote)
{

    this->append(Key::rte,vote);
    return *this;
}

Sandik &Sandik::setmi(const int32_t &vote)
{
    this->append(Key::mi,vote);
    return *this;
}

Sandik &Sandik::setkk(const int32_t &vote)
{
    this->append(Key::kk,vote);
    return *this;
}

Sandik &Sandik::setso(const int32_t &vote)
{
    this->append(Key::so,vote);
    return *this;
}

Sandik &Sandik::setDiger(const int32_t &vote)
{
    this->append(Key::diger,vote);
    return *this;
}

Sandik &Sandik::setTelefon(const std::string &telefonNo)
{
    this->append(Key::telefon,telefonNo);
    return *this;
}

int32_t Sandik::getSandikNo() const
{
    auto val = this->element(Key::sandikno);
    if( val ){
        return val.value().view().get_int32().value;
    }
    return -1;
}

std::string Sandik::getMahalle() const
{
    auto val = this->element(Key::mahalle);
    if( val ){
        return val.value().view().get_string().value.data();
    }
    return "";
}

std::string Sandik::getSandikAlanAdi() const
{
    auto val = this->element(Key::sandikAlanadi);
    if( val ){
        return val.value().view().get_string().value.data();
    }
    return "";
}

int32_t Sandik::getRTE() const
{
    auto val = this->element(Key::rte);
    if( val ){
        return val.value().view().get_int32().value;
    }
    return 0;
}

int32_t Sandik::getMI() const
{
    auto val = this->element(Key::mi);
    if( val ){
        return val.value().view().get_int32().value;
    }
    return 0;
}

int32_t Sandik::getKK() const
{
    auto val = this->element(Key::kk);
    if( val ){
        return val.value().view().get_int32().value;
    }
    return 0;
}

int32_t Sandik::getSO() const
{
    auto val = this->element(Key::so);
    if( val ){
        return val.value().view().get_int32().value;
    }
    return 0;
}

int32_t Sandik::getDiger() const
{
    auto val = this->element(Key::diger);
    if( val ){
        return val.value().view().get_int32().value;
    }
    return 0;
}

std::string Sandik::getTelefon() const
{
    auto val = this->element(Key::telefon);
    if( val ){
        return val.value().view().get_string().value.data();
    }
    return "";
}



Widget::Widget(const Sandik &sandik)
    :Sandik(sandik)
{


    addStyleClass(Bootstrap::Grid::Large::col_lg_3);
    auto container = this->addNew<WContainerWidget>();
    container->setPadding(10,Side::Top|Side::Bottom);


    auto totalOy = this->getDiger() + this->getKK() + this->getMI() + this->getRTE() + this->getSO();

    if( totalOy > 0 ){
        container->setAttributeValue(Style::style,Style::background::color::color("lightgray")+Style::color::color(Style::color::Grey::Black));
    }else{
        container->setAttributeValue(Style::style,Style::background::color::color("darkred")+Style::color::color(Style::color::White::AliceBlue));
    }
    container->setMargin(2,Side::Bottom);

    container->addNew<WText>(std::to_string(this->getSandikNo()) + " ");

    container->addNew<WText>(" <b>RTE: "+std::to_string(this->getRTE()) + "</b>");

//    container->addNew<WText>(" <b>MI: "+std::to_string(this->getMI()) + "</b>");

    container->addNew<WText>(" <b>KK: "+std::to_string(this->getKK()) + "</b>");

//    container->addNew<WText>(" <b>SO: "+std::to_string(this->getSO()) + "</b>");

    container->addNew<WText>(" <b>Diger: "+std::to_string(this->getDiger()) + "</b>");


    this->decorationStyle().setCursor(Cursor::PointingHand);

}

ListItemWidget::ListItemWidget(const bool &listByMahalle)
    :MongoCore::ListItem<Sandik>(Global::DB::instance())
{
    mListByMahalle = listByMahalle;
    this->addStyleClass(Bootstrap::Grid::col_full_12);

    mContent = addWidget(cpp14::make_unique<WContainerWidget>());
    mContent->addStyleClass(Bootstrap::Grid::col_full_12);

}

void ListItemWidget::setSandikValue(const Widget *oldItem)
{

    auto mDialog = createFlatDialog("Sandık :" + std::to_string(oldItem->getSandikNo()));

    auto container = mDialog->Content()->addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::container_fluid);
    container->setAttributeValue(Style::dataoid,oldItem->oid()->to_string());

    auto gLayout = container->setLayout(std::make_unique<WGridLayout>());

    gLayout->addWidget(cpp14::make_unique<WText>("Recep Tayyip ERDOĞAN"),0,0,AlignmentFlag::Center);
    auto rteVote = gLayout->addWidget(cpp14::make_unique<WSpinBox>(),0,1,AlignmentFlag::Center);
    rteVote->setValue(oldItem->getRTE());


//    gLayout->addWidget(cpp14::make_unique<WText>("Muharrem INCE"),1,0,AlignmentFlag::Center);
//    auto miVote = gLayout->addWidget(cpp14::make_unique<WSpinBox>(),1,1,AlignmentFlag::Center);
//    miVote->setValue(oldItem->getMI());

    gLayout->addWidget(cpp14::make_unique<WText>("Kemal KILIÇDAROĞLU"),2,0,AlignmentFlag::Center);
    auto kkVote = gLayout->addWidget(cpp14::make_unique<WSpinBox>(),2,1,AlignmentFlag::Center);
    kkVote->setValue(oldItem->getKK());

//    gLayout->addWidget(cpp14::make_unique<WText>("Sinan OĞAN"),3,0,AlignmentFlag::Center);
//    auto soVote = gLayout->addWidget(cpp14::make_unique<WSpinBox>(),3,1,AlignmentFlag::Center);
//    soVote->setValue(oldItem->getSO());

    gLayout->addWidget(cpp14::make_unique<WText>("Diğer"),4,0,AlignmentFlag::Center);
    auto digerVote = gLayout->addWidget(cpp14::make_unique<WSpinBox>(),4,1,AlignmentFlag::Center);
    digerVote->setValue(oldItem->getDiger());

    mDialog->Accepted().connect([=](){

        Sandik item;
        item.setOid(container->attributeValue(Style::dataoid).toUTF8());

        item.setkk(kkVote->value());
        item.setrte(rteVote->value());
//        item.setmi(miVote->value());
//        item.setso(soVote->value());
        item.setDiger(digerVote->value());

        if( this->UpdateItem(item) ){
            Sandik filter;
            filter.setTelefon(mTelefonNumarasi);
            this->UpdateList(filter);
            this->removeDialog(mDialog);
            _Changed.emit(NoClass());
        }else{

        }

    });

    mDialog->Rejected().connect([=](){

        this->removeDialog(mDialog);

    });
    mDialog->show();
}

void ListItemWidget::ListByMahalle(const std::vector<Sandik> &mlist)
{

    mContent->clear();
    if( !mMahalleler.size() ){
        for( const auto &item : mlist ){
            mMahalleler.insert(item.getMahalle());
        }
    }

    int i = 0;
    for( const auto &item : mMahalleler ){

        if( i >= mSkip && i < mSkip + 20 ){
            auto mahalleWidget = mContent->addNew<MahalleWidget>(item);
            long int rte{0},mi{0},kk{0},so{0},diger{0};

            for( const auto &_item : mlist ){
                if( _item.getMahalle() == item ){
                    rte += (_item.getRTE());
//                    mi += (_item.getMI());
                    kk += (_item.getKK());
//                    so += (_item.getSO());
                    diger += (_item.getDiger());
                }
            }
            mahalleWidget->setVoteRate(rte,mi,kk,so,diger);
//            mahalleWidget->setVoteRate(getRandom(),getRandom(),getRandom(),getRandom(),getRandom());

            mahalleWidget->clicked().connect([=](){

                _MahalleClicked.emit(mahalleWidget->mMahalleName);


            });
        }
        i++;
    }
}




MahalleWidget::MahalleWidget( const std::string &mahalleName )
    :mMahalleName{mahalleName}
{
    mContent = this->addWidget(std::make_unique<WContainerWidget>());

    mContent->addWidget(std::make_unique<WText>(mahalleName));
    mContent->setContentAlignment(AlignmentFlag::Center);
    mContent->setPositionScheme(PositionScheme::Relative);

    addStyleClass(Bootstrap::Grid::Large::col_lg_3+
                  Bootstrap::Grid::Medium::col_md_3+
                  Bootstrap::Grid::Small::col_sm_4+
                  Bootstrap::Grid::ExtraSmall::col_xs_6);

    mContent->setAttributeValue(Style::style,Style::background::color::rgb(240,240,240));
    mContent->setMargin(3,Side::Bottom);
    mContent->setHeight(60);

    {
        auto [container,text] = addBar("orange");
        rteWidgetBar = container;
        rteText = text;
        rteWidgetBar->setOffsets(20,Side::Top);
    }

//    {
//        auto [container,text] = addBar("lightblue");
//        miWidgetBar = container;
//        miText = text;
//        miWidgetBar->setOffsets(40,Side::Top);
//    }


    {
        auto [container,text] = addBar("red");
        kkWidgetBar = container;
        kkText = text;
        kkWidgetBar->setOffsets(40,Side::Top);
    }

//    {
//        auto [container,text] = addBar("CornflowerBlue");
//        soWidgetBar = container;
//        soText = text;
//        soWidgetBar->setOffsets(80,Side::Top);
//    }

}

std::tuple<WContainerWidget*,WText*> MahalleWidget::addBar(const std::string &color)
{
    auto container = mContent->addWidget(cpp14::make_unique<WContainerWidget>());
    container->setPositionScheme(PositionScheme::Absolute);
    container->setAttributeValue(Style::style,Style::background::color::color(color));
    container->setHeight(20);
    container->setContentAlignment(AlignmentFlag::Left);
    auto text = container->addNew<WText>(WString("<b>{1}</b>").arg("0"));
    return std::make_tuple(container,text);
}

void MahalleWidget::setVoteRate(const int &rte, const int &mi, const int &kk, const int &so, const int &diger)
{
    double total = static_cast<double>(rte+mi+kk+so+diger);

    auto rteP = static_cast<double>(rte)/total*100.;
    auto miP = static_cast<double>(mi)/total*100.;
    auto kkP = static_cast<double>(kk)/total*100.;
    auto soP = static_cast<double>(so)/total*100.;

    rteWidgetBar->setWidth(WLength(WString("{1}%").arg(rteP).toUTF8()));
//    miWidgetBar->setWidth(WLength(WString("{1}%").arg(miP).toUTF8()));
    kkWidgetBar->setWidth(WLength(WString("{1}%").arg(kkP).toUTF8()));
//    soWidgetBar->setWidth(WLength(WString("{1}%").arg(soP).toUTF8()));


    auto percent = []( const double percent ){
        std::string str;
        std::ostringstream streamObj3;
        streamObj3 << std::fixed;
        streamObj3 << std::setprecision(2);
        streamObj3 << percent;
        if( percent != percent ){
            return std::string("0");
        }else{
            std::string strObj3 = streamObj3.str();
            return strObj3;
        }

    };

    rteText->setText(WString("<b>{1}</b>").arg(percent(static_cast<double>(rte))));
//    miText->setText(WString("<b>{1}</b>").arg(percent(static_cast<double>(mi))));
    kkText->setText(WString("<b>{1}</b>").arg(percent(static_cast<double>(kk))));
//    soText->setText(WString("<b>{1}</b>").arg(percent(static_cast<double>(so))));

}

} // namespace Sandik



void Sandik::ListItemWidget::errorOccured(const std::string &errorText)
{
    std::cout << "Can Not Update: " << errorText <<"\n";

}

void Sandik::ListItemWidget::onList(const std::vector<Sandik> &mlist)
{
    if( mListByMahalle ){
        this->ListByMahalle(mlist);
    }else{
        mContent->clear();;
        for( const auto &item : mlist ){
            auto container = mContent->addWidget(cpp14::make_unique<Widget>(item));
            container->clicked().connect([=](){
                this->setSandikValue(container);
            });
        }
    }

}
