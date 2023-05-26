
#ifndef TOTALVOTEWIDGET_H
#define TOTALVOTEWIDGET_H


#include <Wt/WContainerWidget.h>

namespace MongoCore {
class DB;
}

class TotalItemWidget;

class TotalVoteWidget : public Wt::WContainerWidget
{
public:
    TotalVoteWidget(MongoCore::DB* _db);

    TotalItemWidget* mRTEWidget;
    TotalItemWidget* mMIWidget;
    TotalItemWidget* mKKWidget;
    TotalItemWidget* mSOWidget;

    Wt::WContainerWidget* mPercentWidget;
    Wt::WText* mPercentText;

    TotalItemWidget* addVoteWidget( const std::string &imgUrl , const std::string &name , const std::string &barColor );

    void updatePercent();

    MongoCore::DB* mDB;

};




#endif // TOTALVOTEWIDGET_H
