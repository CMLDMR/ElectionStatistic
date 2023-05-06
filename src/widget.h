
#ifndef SANDIK_WIDGET_H
#define SANDIK_WIDGET_H


#include <Wt/WContainerWidget.h>
#include <mongocore/listitem.h>
#include <mongocore/item.h>
#include <type_traits>

#include "src/containerwidget.h"


#include "magic/magic_enum.hpp"


namespace Sandik {

namespace Key {
enum Key{
    SandikCollection = 0,
    sandikno,
    mahalle,
    sandikAlanadi,
    telefon,
    rte,
    mi,
    kk,
    so
};
}


class Sandik : public MongoCore::Item{
public:
    Sandik();
    Sandik( const Sandik &other );

    Sandik& setSandikNo( const std::int32_t &sandikNo );
    Sandik& setMahalle( const std::string &mahalle );
    Sandik& setSandikAlanAdi( const std::string &sandikAlanAdi );
    Sandik& setrte(const std::int64_t &vote );
    Sandik& setmi(const int64_t &vote );
    Sandik& setkk(const std::int64_t &vote );
    Sandik& setso(const int64_t &vote );
    Sandik& setTelefon( const std::string &telefonNo );


    std::int32_t getSandikNo() const;
    std::string getMahalle() const;
    std::string getSandikAlanAdi() const;
    std::int64_t getRTE() const;
    std::int64_t getMI() const;
    std::int64_t getKK() const;
    std::int64_t getSO() const;
    std::string getTelefon() const;

private:

    auto value( const Key::Key &key ) const{
        auto val = this->element(std::string(magic_enum::enum_name(key)));
        return val;
    }

    template < typename T >
    Sandik &setValue( const Key::Key &key, const T &value ){
        this->append(magic_enum::enum_name(key).data(),value);
        return *this;
    }

};



class Widget : public Wt::WContainerWidget, public Sandik
{
public:
    Widget(const Sandik &sandik);
};



class ListItemWidget : public MongoCore::ListItem<Sandik>, public ContainerWidget
{
public:
    ListItemWidget();

    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // ListItem interface
public:
    virtual void onList(const std::vector<Sandik> &mlist) override;
};

} // namespace Sandik

#endif // SANDIK_WIDGET_H
