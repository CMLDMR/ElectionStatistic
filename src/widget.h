
#ifndef SANDIK_WIDGET_H
#define SANDIK_WIDGET_H


#include <Wt/WContainerWidget.h>
#include <Wt/WTimer.h>
#include <mongocore/listitem.h>
#include <mongocore/item.h>
#include <type_traits>
#include <set>
#include "src/containerwidget.h"





namespace Sandik {

namespace Key {
inline const std::string SandikCollection{"ikiciTur"};
inline const std::string sandikno{"sandikno"};
inline const std::string mahalle{"mahalle"};
inline const std::string sandikAlanadi{"sandikAlanadi"};
inline const std::string telefon{"telefon"};
inline const std::string rte{"rte"};
inline const std::string mi{"mi"};
inline const std::string kk{"kk"};
inline const std::string so{"so"};
inline const std::string diger{"diger"};

}


class Sandik : public MongoCore::Item{
public:
    Sandik();
    Sandik( const Sandik &other );

    Sandik& setSandikNo( const std::int32_t &sandikNo );
    Sandik& setMahalle( const std::string &mahalle );
    Sandik& setSandikAlanAdi( const std::string &sandikAlanAdi );
    Sandik& setrte(const int32_t &vote );
    Sandik& setmi(const int32_t &vote );
    Sandik& setkk(const int32_t &vote );
    Sandik& setso(const int32_t &vote );
    Sandik& setDiger(const int32_t &vote );
    Sandik& setTelefon( const std::string &telefonNo );


    std::int32_t getSandikNo() const;
    std::string getMahalle() const;
    std::string getSandikAlanAdi() const;
    std::int32_t getRTE() const;
    std::int32_t getMI() const;
    std::int32_t getKK() const;
    std::int32_t getSO() const;
    std::int32_t getDiger() const;

    std::string getTelefon() const;

private:

};



class Widget : public Wt::WContainerWidget, public Sandik
{
public:
    Widget(const Sandik &sandik);
};


class MahalleWidget : public ContainerWidget
{
public:
    MahalleWidget(const std::string &mahalleName);

    WContainerWidget* mContent;
    std::tuple<WContainerWidget*,WText*> addBar( const std::string &color);

    void setVoteRate(const int &rte, const int &mi, const int &kk , const int &so , const int &diger);
    WContainerWidget* rteWidgetBar;
//    WContainerWidget* miWidgetBar;
    WContainerWidget* kkWidgetBar;
//    WContainerWidget* soWidgetBar;

    WText* rteText;
//    WText* miText;
    WText* kkText;
//    WText* soText;

    std::string mMahalleName{};

};



class ListItemWidget : public MongoCore::ListItem<Sandik>, public ContainerWidget
{
public:
    ListItemWidget(DB *db, const bool &listByMahalle = false);

    void setSandikValue(const Widget *oldItem);

    std::string mTelefonNumarasi{""};

    Signal<NoClass> _Changed;

    void ListByMahalle( const std::vector<Sandik> &mlist );

    bool mListByMahalle{false};

    std::set<std::string> mMahalleler;

    int mSkip = 0;

    bool mAutoChange{true};

    WContainerWidget* mContent;
    WContainerWidget* mHeader;

    Signal<std::string> _MahalleClicked;





    // DB interface
public:
    virtual void errorOccured(const std::string &errorText) override;

    // ListItem interface
public:
    virtual void onList(const std::vector<Sandik> &mlist) override;
};

} // namespace Sandik

#endif // SANDIK_WIDGET_H
