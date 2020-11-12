#ifndef WINDOW_H
#define WINDOW_H

#include "preset_combobox.h"
#include "destination_combobox.h"
#include "origin_combobox.h"

#include <gtkmm.h>

class Window : public Gtk::Window
{
private:
    Gtk::Box main_application_box;

    //see to add images of the project

    //Toutes les informations sur le preset du simulateur
    Gtk::Frame preset_frame;
    Gtk::Box preset_combo_spacer_box;
    Preset_combobox preset_combo;
    Gtk::Label preset_spacer;
    void on_preset_changed();
    //Rajouter tous les éléments nécessaires à envoyer au programme
    Gtk::Box first_preset_box;
    Gtk::Label first_preset_spacer;
    Gtk::Frame entry_test_frame;
    Gtk::Entry entry_test;

    //Toutes les informations sur le trajet
    Gtk::Box route_box;
    Gtk::Frame origin_frame;
    Origin_combobox origin_combo;
    void on_origin_changed();
    Gtk::Frame destination_frame;
    Destination_combobox destination_combo;
    Gtk::Label route_spacer;

    //Pied de page avec les boutons pour accepter et continuer
    Gtk::Label window_spacer;
    Gtk::Box button_box;
    Gtk::Label button_spacer;
    Gtk::Button enter_button;
    void on_enter();
    void on_close();
    Gtk::Button close_button;

public:
    Window();
};

#endif //WINDOW_H
