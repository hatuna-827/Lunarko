#include "app.hpp"
#include "Window.hpp"
#include "Config.hpp"
#include "Translate.hpp"

App::App(int &argc, char *argv[])
    : QApplication(argc, argv)
{
    setApplicationName("Lunarko");
    setOrganizationName("Lunarko");
    Config::load();
    Translate::setLang();
}

int App::run()
{
    Window w;
    w.show();
    return exec();
}
