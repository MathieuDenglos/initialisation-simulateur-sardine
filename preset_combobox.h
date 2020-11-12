/*
Ce fichier contient la boite de choix (Gtk::ComboBox) suivant le modèle de preset_columns.h
Aucune information n'est à modifier ici :
    → Pour rajouter des éléments, aller dans preset_columns.h et de suivre les instructions qui s'y trouvent
    → Pour rajouter des donnés au sein de de la combobox, aller dans preset_combobox.c++ et modifier le constructeur
*/

#ifndef PRESET_COMBOBOX_H
#define PRESET_BOMBOBOX_H

#include "preset_columns.h"

#include <gtkmm.h>
#include <string>

class Preset_combobox : public Gtk::ComboBox
{
private:
    //Colomnes pour définir définir les éléments et modèle pour définir la forme de la combobox
    Preset_columns preset_columns;
    Glib::RefPtr<Gtk::ListStore> preset_model;

    //Méthode pour rajouter un preset
    void create_preset(std::string preset_name,
                       bool editable,
                       int valueA);

public:
    //constructeur
    Preset_combobox();

    //getters
    Preset_columns &get_preset_columns() { return preset_columns; };
};

#endif //PRESET_COMBOBOX_H