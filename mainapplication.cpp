
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
#include "src/widget.h"

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


        mSandikManagerWidget->_MahalleClicked.connect([=](const std::string &mahalle){


            auto mDialog = Wt::WApplication::instance()->root()->addNew<DialogContainerWidget>(mahalle);
            mDialog->setId("flatDialog");
            mDialog->setPositionScheme(PositionScheme::Fixed);
            mDialog->setWidth(WLength("100%"));
            mDialog->setHeight(WLength("100%"));
            mDialog->addStyleClass("newDialog");
            mDialog->setContentAlignment(AlignmentFlag::Center);

            mDialog->Rejected().connect([=](){
                    Wt::WApplication::instance()->root()->removeWidget(mDialog);
                });

                auto content = mDialog->Content()->addWidget(cpp14::make_unique<WContainerWidget>());
                content->addStyleClass(Bootstrap::Grid::col_full_12);
                Sandik::Sandik filter;
                filter.setMahalle(mahalle);

                MongoCore::FindOptions options;
                options.setLimit(400);

                auto list = mSandikManagerWidget->List(filter,options);

                auto gLayout = content->setLayout(cpp14::make_unique<WGridLayout>());

                gLayout->addWidget(cpp14::make_unique<WText>("<b>Sandık</b>"),0,0,AlignmentFlag::Left);
                gLayout->addWidget(cpp14::make_unique<WText>("<b>Recep Tayyip ERDOĞAN</b>"),0,1,AlignmentFlag::Center);
//                gLayout->addWidget(cpp14::make_unique<WText>("<b>Muharren İNCE</b>"),0,2,AlignmentFlag::Center);
                gLayout->addWidget(cpp14::make_unique<WText>("<b>Kemal KILIÇDAROĞLU</b>"),0,3,AlignmentFlag::Center);
//                gLayout->addWidget(cpp14::make_unique<WText>("<b>Sinan OĞAN</b>"),0,4,AlignmentFlag::Center);
                gLayout->addWidget(cpp14::make_unique<WText>("<b>Diğer</b>"),0,5,AlignmentFlag::Center);

                    int RTE{0};
//                    int MI{0};
                    int KK{0};
//                    int SO{0};
                    int DIGER{0};

                int i = 1 ;
                for( const auto &mahalleItem : list ){
                    gLayout->addWidget(cpp14::make_unique<WText>(std::to_string(mahalleItem.getSandikNo())),i,0,AlignmentFlag::Left);
                    gLayout->addWidget(cpp14::make_unique<WText>(std::to_string(mahalleItem.getRTE())),i,1,AlignmentFlag::Center);
//                    gLayout->addWidget(cpp14::make_unique<WText>(std::to_string(mahalleItem.getMI())),i,2,AlignmentFlag::Center);
                    gLayout->addWidget(cpp14::make_unique<WText>(std::to_string(mahalleItem.getKK())),i,3,AlignmentFlag::Center);
//                    gLayout->addWidget(cpp14::make_unique<WText>(std::to_string(mahalleItem.getSO())),i,4,AlignmentFlag::Center);
                    gLayout->addWidget(cpp14::make_unique<WText>(std::to_string(mahalleItem.getDiger())),i,5,AlignmentFlag::Center);
                    i++;

                    RTE += mahalleItem.getRTE();
//                    MI += mahalleItem.getMI();
                    KK += mahalleItem.getKK();
//                    SO += mahalleItem.getSO();
                    DIGER += mahalleItem.getDiger();
                }


                gLayout->addWidget(cpp14::make_unique<WText>("<b>Toplam</b>"),i,0,AlignmentFlag::Left);
                gLayout->addWidget(cpp14::make_unique<WText>("<b>"+std::to_string(RTE)+"</b>"),i,1,AlignmentFlag::Center);
//                gLayout->addWidget(cpp14::make_unique<WText>("<b>"+std::to_string(MI)+"</b>"),i,2,AlignmentFlag::Center);
                gLayout->addWidget(cpp14::make_unique<WText>("<b>"+std::to_string(KK)+"</b>"),i,3,AlignmentFlag::Center);
//                gLayout->addWidget(cpp14::make_unique<WText>("<b>"+std::to_string(SO)+"</b>"),i,4,AlignmentFlag::Center);
                gLayout->addWidget(cpp14::make_unique<WText>("<b>"+std::to_string(DIGER)+"</b>"),i,5,AlignmentFlag::Center);



                mDialog->Rejected().connect([=](){
                    if( mDialog == NULL ){
                        std::cout << "Dialog Does Not Exist\n";
                    }else{
                        std::cout << "Dilod \n";
//                        removeDialog(mDialog);
                        Wt::WApplication::instance()->root()->removeWidget(mDialog);
//                        mAutoChange = true;
                    }

                });

                mDialog->show();

        });



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
                if( mSandikManagerWidget->mSkip >= mSandikManagerWidget->mMahalleler.size() ) mSandikManagerWidget->mSkip = 0;

                if( mSandikManagerWidget->mTelefonNumarasi.size() ){

                }else{
                    mSandikManagerWidget->UpdateList();
                }

            }

            mTotalVoteWidget->updatePercent();

        });
        mTimer->start();





    }







}
