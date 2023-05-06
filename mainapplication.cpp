
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

    mTotalVoteWidget = root()->addNew<TotalVoteWidget>();
    mTotalVoteWidget->addStyleClass(Bootstrap::Grid::col_full_12);

    mSandikManagerWidget = root()->addNew<Sandik::ListItemWidget>();
    mSandikManagerWidget->addStyleClass(Bootstrap::Grid::col_full_12);
    mSandikManagerWidget->setMargin(10,Wt::Side::Top);

    mSandikManagerWidget->clicked().connect(this,&MainApplication::addSandikDialog);

    mSandikManagerWidget->UpdateList();

}

void MainApplication::addSandikDialog()
{
    auto mDialog = mSandikManagerWidget->createFlatDialog("Sandık Ekle");

    auto container = mDialog->Content()->addWidget(cpp14::make_unique<WContainerWidget>());
    container->addStyleClass(Bootstrap::Grid::container_fluid);

    auto gLayout = container->setLayout(cpp14::make_unique<WGridLayout>());

    gLayout->addWidget(cpp14::make_unique<WText>("Sandık Alanı"),0,0,AlignmentFlag::Center);
    auto alanAdiLineEdit = gLayout->addWidget(cpp14::make_unique<WLineEdit>(),0,1,AlignmentFlag::Center);

    gLayout->addWidget(cpp14::make_unique<WText>("Mahalle"),1,0,AlignmentFlag::Center);
    auto mahalleLineEdit = gLayout->addWidget(cpp14::make_unique<WLineEdit>(),1,1,AlignmentFlag::Center);

    gLayout->addWidget(cpp14::make_unique<WText>("Sandık No"),2,0,AlignmentFlag::Center);
    auto sandikNoSpinNox = gLayout->addWidget(cpp14::make_unique<WSpinBox>(),2,1,AlignmentFlag::Center);

    gLayout->addWidget(cpp14::make_unique<WText>("İlgili Telefon"),3,0,AlignmentFlag::Center);
    auto telefonNoEdit = gLayout->addWidget(cpp14::make_unique<WLineEdit>(),3,1,AlignmentFlag::Center);

    mDialog->Accepted().connect([=](){

//        Sandik::Sandik item;
//        item.setSandikAlanAdi(alanAdiLineEdit->text().toUTF8());
//        item.setMahalle(mahalleLineEdit->text().toUTF8());
//        item.setSandikNo(sandikNoSpinNox->value());
//        item.setTelefon(telefonNoEdit->text().toUTF8());

//        auto ins = mSandikManagerWidget->InsertItem(item);
//        if( ins.size() ){
//            mSandikManagerWidget->removeDialog(mDialog);
//            mSandikManagerWidget->UpdateList();
//        }else{

//        }

    });
    mDialog->show();



}
