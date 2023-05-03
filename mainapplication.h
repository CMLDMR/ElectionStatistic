
#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <Wt/WApplication.h>
#include <Wt/WEnvironment.h>
#include <Wt/WTheme.h>
#include <Wt/WBootstrap3Theme.h>


class MainApplication : public Wt::WApplication
{
public:
    MainApplication(const Wt::WEnvironment &env);

    std::shared_ptr<Wt::WBootstrap3Theme> mTheme;
};

#endif // MAINAPPLICATION_H
