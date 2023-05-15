#include "controllerwidget.h"

#include "src/inlinestyle.h"
#include "src/bootstrap.h"

ControllerWidget::ControllerWidget()
{
    addStyleClass(Bootstrap::Grid::col_full_12+Bootstrap::ContextualBackGround::bg_primary);
    setHeight(50);


    mLayout = setLayout(std::make_unique<WHBoxLayout>());

    mLayout->addStretch(1);

    mBackButton = mLayout->addWidget(cpp14::make_unique<WPushButton>("Geri"));

                  mLayout->addStretch(1);

    mStopAutoChangeButton = mLayout->addWidget(cpp14::make_unique<WPushButton>("Durdur"));
    mLayout->addStretch(1);

    mNextButton = mLayout->addWidget(cpp14::make_unique<WPushButton>("İleri"));

    mLayout->addStretch(1);

}
