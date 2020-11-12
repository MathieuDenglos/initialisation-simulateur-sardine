#include "window.h"

#include <gtkmm/settings.h>
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
//Set the environment variable for Gtk to not show any window decoration
#ifdef _WIN32
    putenv("GTK_CSD=0");
#endif

    //Create the application
    Glib::RefPtr<Gtk::Application> app =
        Gtk::Application::create(argc, argv, "org.gtkmm.example");

    //Change the settings for the selected theme and font
    auto a = Gtk::Settings::get_default();
    a->property_gtk_theme_name() = "Windows10";
    a->property_gtk_font_name() = "Segoe UI 9";

    Window window;

    return app->run(window);
}