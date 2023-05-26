
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
    TotalVoteWidget();

    TotalItemWidget* mRTEWidget;
    TotalItemWidget* mMIWidget;
    TotalItemWidget* mKKWidget;
    TotalItemWidget* mSOWidget;

    Wt::WContainerWidget* mPercentWidget;
    Wt::WText* mPercentText;

    TotalItemWidget* addVoteWidget( const std::string &imgUrl , const std::string &name , const std::string &barColor );

    void updatePercent();

};




#endif // TOTALVOTEWIDGET_H
