#ifndef CONTROLLERWIDGET_H
#define CONTROLLERWIDGET_H

#include "src/containerwidget.h"

#include <Wt/Signals/signals.hpp>
#include <Wt/WHBoxLayout.h>
#include <Wt/WPushButton.h>

class ControllerWidget : public ContainerWidget
{
public:
    ControllerWidget();


    WPushButton* mStopAutoChangeButton;
    WPushButton* mNextButton;

private:
    WHBoxLayout* mLayout;


};

#endif // CONTROLLERWIDGET_H
