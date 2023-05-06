
#include "widget.h"

#include "inlinestyle.h"
#include "bootstrap.h"

#include "src/db.h"

#include <Wt/WText.h>




using namespace Wt;

namespace Sandik {

Sandik::Sandik()
    :MongoCore::Item(magic_enum::enum_name(Key::SandikCollection).data())
{
    setrte(0);
    setmi(0);
    setkk(0);
    setso(0);
}

Sandik::Sandik(const Sandik &other)
    :MongoCore::Item(other)
{
    this->setDocumentView(other.view());
}

Sandik &Sandik::setSandikNo( const int32_t &sandikNo )
{
    return setValue(Key::sandikno,sandikNo);
}

Sandik &Sandik::setMahalle( const std::string &mahalle )
{
    return setValue(Key::mahalle,mahalle);
}

Sandik &Sandik::setSandikAlanAdi(const std::string &sandikAlanAdi)
{
    return setValue( Key::sandikAlanadi,sandikAlanAdi);
}

Sandik &Sandik::setrte(const int64_t &vote)
{
    return this->setValue(Key::rte,vote);
}

Sandik &Sandik::setmi(const int64_t &vote)
{
    return this->setValue(Key::mi,vote);
}

Sandik &Sandik::setkk(const int64_t &vote)
{
    return this->setValue(Key::kk,vote);
}

Sandik &Sandik::setso(const int64_t &vote)
{
    return this->setValue(Key::so,vote);
}

Sandik &Sandik::setTelefon(const std::string &telefonNo)
{
    return this->setValue(Key::telefon,telefonNo);
}

int32_t Sandik::getSandikNo() const
{
    auto val = this->value(Key::Key::sandikno);
    if( val ){
        return val.value().view().get_int32().value;
    }
    return -1;
}

std::string Sandik::getMahalle() const
{
    auto val = this->value(Key::Key::mahalle);
    if( val ){
        return val.value().view().get_string().value.data();
    }
    return "";
}

std::string Sandik::getSandikAlanAdi() const
{
    auto val = this->value(Key::Key::sandikAlanadi);
    if( val ){
        return val.value().view().get_string().value.data();
    }
    return "";
}

int64_t Sandik::getRTE() const
{
    auto val = this->value(Key::Key::rte);
    if( val ){
        return val.value().view().get_int32().value;
    }
    return -1;
}

int64_t Sandik::getMI() const
{
    auto val = this->value(Key::Key::mi);
    if( val ){
        return val.value().view().get_int32().value;
    }
    return -1;
}

int64_t Sandik::getKK() const
{
    auto val = this->value(Key::Key::kk);
    if( val ){
        return val.value().view().get_int32().value;
    }
    return -1;
}

int64_t Sandik::getSO() const
{
    auto val = this->value(Key::Key::so);
    if( val ){
        return val.value().view().get_int32().value;
    }
    return -1;
}

std::string Sandik::getTelefon() const
{
    auto val = this->value(Key::Key::telefon);
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
    container->setHeight(50);
    container->setAttributeValue(Style::style,Style::background::color::color("lightgray"));
    container->setMargin(2,Side::Bottom);
    container->addNew<WText>(this->getMahalle()+" ");
    container->addNew<WText>(std::to_string(this->getSandikNo()) + " ");
    container->addNew<WText>(this->getSandikAlanAdi() + " ");
    container->addNew<WText>(this->getTelefon());

}

ListItemWidget::ListItemWidget()
    :MongoCore::ListItem<Sandik>(Global::DB::instance())
{
    this->addStyleClass(Bootstrap::Grid::col_full_12);
    this->addWidget(cpp14::make_unique<WText>("List Item"));
}

} // namespace Sandik



void Sandik::ListItemWidget::errorOccured(const std::string &errorText)
{

}

void Sandik::ListItemWidget::onList(const std::vector<Sandik> &mlist)
{
    this->clear();
    for( const auto &item : mlist ){
        this->addWidget(cpp14::make_unique<Widget>(item));
    }
}
