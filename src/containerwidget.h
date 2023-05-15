
#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include <Wt/WContainerWidget.h>

using namespace Wt;

class DialogContainerWidget;


class ContainerWidget : public Wt::WContainerWidget
{
public:
    ContainerWidget();

    DialogContainerWidget *createFlatDialog(const std::string &title = "" , const bool &autoDel = true);

    void removeDialog(DialogContainerWidget *removedContainer );

    int getRandom( const int &min = 0, const int &max = 100 );
};






class DialogContainerWidget : public Wt::WContainerWidget
{
public:
    explicit DialogContainerWidget(const std::string &title);

    WContainerWidget* Content();

    void setContentWidth( const WLength &value );



    Signal<NoClass> &Accepted();
    Signal<NoClass> &Rejected();
private:
    WContainerWidget* mContent;
    WContainerWidget* contentContainer;


    Signal<NoClass> _Accepted;
    Signal<NoClass> _Rejected;
};

#endif // CONTAINERWIDGET_H
