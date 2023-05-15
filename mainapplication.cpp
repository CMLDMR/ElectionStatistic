
#include "mainapplication.h"


#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WEvent.h>
#include <Wt/WGridLayout.h>
#include <Wt/WLineEdit.h>
#include <Wt/WSpinBox.h>

#include "src/bootstrap.h"

#include <mongocxx/uri.hpp>
#include <mongocxx/exception/exception.hpp>
#include "../url.h"

#include <mongocore/item.h>
#include "src/totalvotewidget.h"
#include "src/db.h"

#include "src/widget.h"
#include "src/totalvotewidget.h"

MainApplication::MainApplication(const Wt::WEnvironment &env)
    :Wt::WApplication(env)
{

    try {
        mClient = new mongocxx::client(mongocxx::uri(_url));
    } catch (mongocxx::exception &e) {
        std::cout << e.what() <<"\n";
        return;
    }

    __mDB = mClient->database(_db);
    mDB = new MongoCore::DB(&__mDB);
    Global::DB::setDB(mDB);

    mTheme = std::make_shared<Wt::WBootstrap3Theme>();
    mTheme.get()->setResponsive(true);

    wApp->setTheme(mTheme);

    WApplication::useStyleSheet(WLink("newDialog.css"));

    mTotalVoteWidget = root()->addNew<TotalVoteWidget>();
    mTotalVoteWidget->addStyleClass(Bootstrap::Grid::col_full_12);

    std::map<std::string,std::string> mapList;
    for (const auto &str : env.getParameterMap() ) {
        for( const auto &sec : str.second )
        {
            mapList[str.first.c_str ()] = sec;
        }
    }

    if( mapList.contains("telefon") ){

        mSandikManagerWidget = root()->addNew<Sandik::ListItemWidget>();
        mSandikManagerWidget->mTelefonNumarasi = mapList["telefon"];

        mSandikManagerWidget->addStyleClass(Bootstrap::Grid::col_full_12);
        mSandikManagerWidget->setMargin(10,Wt::Side::Top);
        mSandikManagerWidget->setLimit(500);

        mSandikManagerWidget->_Changed.connect(mTotalVoteWidget,&TotalVoteWidget::updatePercent);

        Sandik::Sandik filter;
        filter.setTelefon(mapList["telefon"]);

        mSandikManagerWidget->UpdateList(filter);

    }else{

        mSandikManagerWidget = root()->addNew<Sandik::ListItemWidget>(true);

        mSandikManagerWidget->addStyleClass(Bootstrap::Grid::col_full_12);
        mSandikManagerWidget->setMargin(10,Wt::Side::Top);
        mSandikManagerWidget->setLimit(500);
        mSandikManagerWidget->UpdateList();


        mSandikManagerWidget->_Changed.connect(mTotalVoteWidget,&TotalVoteWidget::updatePercent);

        auto controllerWidget = root()->addNew<ControllerWidget>();
        controllerWidget->addStyleClass(Bootstrap::Grid::col_full_12);
        controllerWidget->mStopAutoChangeButton->clicked().connect([=](){
            if( controllerWidget->mStopAutoChangeButton->text() == "Durdur" ){
                controllerWidget->mStopAutoChangeButton->setText("Kaydır");
                mSandikManagerWidget->mAutoChange = false;
                mTimer->stop();
            }else{
                controllerWidget->mStopAutoChangeButton->setText("Durdur");
                mSandikManagerWidget->mAutoChange = true;
                mTimer->start();
            }

        });

        controllerWidget->mBackButton->clicked().connect([=](){
            mSandikManagerWidget->Sayac = 0;
            mSandikManagerWidget->mSkip -= 20;
            if( mSandikManagerWidget->mSkip < 0 ){
                mSandikManagerWidget->mSkip = mSandikManagerWidget->mMahalleler.size()-20;
            }

            if( mSandikManagerWidget->mSkip > mSandikManagerWidget->mMahalleler.size() ) mSandikManagerWidget->mSkip = 0;
            mSandikManagerWidget->UpdateList();

        });

        controllerWidget->mNextButton->clicked().connect([=](){
            mSandikManagerWidget->Sayac = 0;
            mSandikManagerWidget->mSkip += 20;
            if( mSandikManagerWidget->mSkip > mSandikManagerWidget->mMahalleler.size() ) mSandikManagerWidget->mSkip = 0;
            mSandikManagerWidget->UpdateList();

        });

        mTimer = addChild(std::make_unique<Wt::WTimer>());
        mTimer->setInterval(std::chrono::seconds(1));
        mTimer->timeout().connect(this, [=](){

            mSandikManagerWidget->Sayac++;

            if( mSandikManagerWidget->Sayac >=3 && mSandikManagerWidget->mAutoChange ){
                mSandikManagerWidget->Sayac = 0;
                mSandikManagerWidget->mSkip += 20;
                std::cout << "New Pahe\n";
                if( mSandikManagerWidget->mSkip >= mSandikManagerWidget->mMahalleler.size() ) mSandikManagerWidget->mSkip = 0;

                if( mSandikManagerWidget->mTelefonNumarasi.size() ){

                }else{
                    mSandikManagerWidget->UpdateList();
                }

            }

        });
//        mTimer->start();





    }







}
