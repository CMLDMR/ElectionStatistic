
#ifndef TOTALITEMWIDGET_H
#define TOTALITEMWIDGET_H


#include <Wt/WContainerWidget.h>

namespace Wt {
class WText;
}


class TotalItemWidget : public Wt::WContainerWidget
{
public:
    TotalItemWidget(const std::string &imgUrl,
                    const std::string &Name,
                    const std::string &barColor);


    void setPercent( const double &barPercent );
private:

    Wt::WContainerWidget* mPercentBar{nullptr};
    Wt::WText* mPercentText{nullptr};
};

#endif // TOTALITEMWIDGET_H
