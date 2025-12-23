#include "app.hpp"
#include "Window.hpp"
#include "Config.hpp"

App::App(int &argc, char *argv[])
    : QApplication(argc, argv)
{
    setApplicationName("Lunarko");
    setOrganizationName("Lunarko");
    Config::load();
}

int App::run()
{
    Window w;
    w.show();
    return exec();
}
