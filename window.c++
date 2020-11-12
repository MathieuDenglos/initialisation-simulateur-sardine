#include "window.h"

#include <string>
#include <sstream>

Window::Window() : main_application_box(Gtk::ORIENTATION_VERTICAL, 12),
                   preset_frame("Choix du preset"),
                   preset_combo_spacer_box(Gtk::ORIENTATION_HORIZONTAL, 0),
                   preset_spacer(""),
                   first_preset_box(Gtk::ORIENTATION_HORIZONTAL, 24),
                   first_preset_spacer(""),
                   entry_test_frame("test value"),
                   route_box(Gtk::ORIENTATION_HORIZONTAL, 24),
                   origin_frame("Origine"),
                   origin_combo(),
                   destination_frame("Destination"),
                   destination_combo(origin_combo),
                   route_spacer(""),
                   window_spacer(""),
                   button_box(Gtk::ORIENTATION_HORIZONTAL, 12),
                   button_spacer(""),
                   enter_button("confirmer"),
                   close_button("annuler")
{

    //Définition de la partie pour le combobox du preset
    preset_combo.set_active(0);
    this->on_preset_changed();
    preset_combo_spacer_box.pack_start(preset_combo, Gtk::PACK_SHRINK);
    preset_combo_spacer_box.pack_start(preset_spacer, Gtk::PACK_EXPAND_WIDGET);
    preset_frame.set_label_align(Gtk::ALIGN_START, Gtk::ALIGN_END);
    preset_frame.set_shadow_type(Gtk::SHADOW_NONE);
    preset_frame.add(preset_combo_spacer_box);
    main_application_box.pack_start(preset_frame, Gtk::PACK_SHRINK);

    //définition de la première ligne d'informations du preset
    entry_test.set_max_length(12);
    entry_test_frame.set_label_align(Gtk::ALIGN_START, Gtk::ALIGN_END);
    entry_test_frame.set_shadow_type(Gtk::SHADOW_NONE);
    entry_test_frame.add(entry_test);
    first_preset_box.pack_start(entry_test_frame, Gtk::PACK_SHRINK);
    first_preset_box.pack_start(first_preset_spacer, Gtk::PACK_SHRINK);
    main_application_box.pack_start(first_preset_box, Gtk::PACK_SHRINK);

    //Définition de la partie pour les trajets
    origin_combo.set_active(0);
    this->on_origin_changed();
    origin_frame.set_label_align(Gtk::ALIGN_START, Gtk::ALIGN_END);
    origin_frame.set_shadow_type(Gtk::SHADOW_NONE);
    origin_frame.add(origin_combo);
    destination_frame.set_label_align(Gtk::ALIGN_START, Gtk::ALIGN_END);
    destination_frame.set_shadow_type(Gtk::SHADOW_NONE);
    destination_frame.add(destination_combo);
    route_box.pack_start(origin_frame, Gtk::PACK_SHRINK);
    route_box.pack_start(destination_frame, Gtk::PACK_SHRINK);
    route_box.pack_start(route_spacer);
    main_application_box.pack_start(route_box, Gtk::PACK_SHRINK);

    //Définition des boutons ok et close
    main_application_box.pack_start(window_spacer, Gtk::PACK_EXPAND_WIDGET);
    button_box.pack_start(button_spacer, Gtk::PACK_EXPAND_WIDGET);
    button_box.pack_start(enter_button, Gtk::PACK_SHRINK);
    button_box.pack_start(close_button, Gtk::PACK_SHRINK);
    main_application_box.pack_start(button_box, Gtk::PACK_SHRINK);

    //signals handlers
    preset_combo.signal_changed().connect(sigc::mem_fun(*this, &Window::on_preset_changed));
    origin_combo.signal_changed().connect(sigc::mem_fun(*this, &Window::on_origin_changed));
    enter_button.signal_clicked().connect(sigc::mem_fun(*this, &Window::on_enter));
    close_button.signal_clicked().connect(sigc::mem_fun(*this, &Window::on_close));

    //Ajoute des indications pour la fenètre
    set_border_width(12);
    set_title("Initialisation simulateur sardine");

    //ajouter la boite principale à la fenêtre et la montre
    add(main_application_box);
    show_all();
}

void Window::on_preset_changed()
{
    Gtk::TreeModel::Row preset_row = *preset_combo.get_active();

    //Change toutes les valeurs des éléments
    entry_test.set_text(std::to_string(preset_row[preset_combo.get_preset_columns().valueA]));

    //récupère l'éditabilité du preset et change l'éditabilité des différents éléments
    bool editable = preset_row[preset_combo.get_preset_columns().preset_editable];

    //Change toutes l'éditabilité de tous les éléments
    entry_test_frame.set_sensitive(editable);
}

void Window::on_origin_changed()
{
    Gtk::TreeModel::Row origin_row = *origin_combo.get_active();

    //Change les valeurs à changer dans la boite des destinations
    destination_combo.change_destination_model(origin_row[origin_combo.get_origin_columns().possible_destinations]);
}

namespace Launch
{
    void launch_simulator(Window &win, std::stringstream &system_stream)
    {
        win.hide();
        const char *system_launch = system_stream.str().c_str();
        system(system_launch);
    }
    //TODO : find the solution to make this work
    template <typename arg, typename... args>
    void launch_simulator(Window &win,
                          std::stringstream &system_stream,
                          std::pair<const char *, arg> argument,
                          std::pair<const char *, args>... argument_list)
    {
        system_stream << " --" << argument.first
                      << "=\"" << argument.second
                      << "\"";
        Launch::launch_simulator(system_stream, argument_list...);
    }
} // namespace Launch

//Modifier si on veut rajouter des informations à envoyer au simulateur
void Window::on_enter()
{
    //Crée un stringstream avec le chemin vers l'application à lancer
    std::stringstream system_string("test.exe");

    //Lance le simulateur avec l'application et les arguments donnés
    Launch::launch_simulator(*this, system_string,
                             std::make_pair("preset", preset_combo.get_active()->get_value(preset_combo.get_preset_columns().preset_name)),
                             std::make_pair("valueA", preset_combo.get_active()->get_value(preset_combo.get_preset_columns().valueA)),
                             std::make_pair("origine", origin_combo.get_active()->get_value(origin_combo.get_origin_columns().origin_name)),
                             std::make_pair("destination", destination_combo.get_active()->get_value(destination_combo.get_destination_columns().destination_name)));
}

void Window::on_close()
{
    this->hide();
}
