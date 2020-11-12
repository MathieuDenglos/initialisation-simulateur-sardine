/*
Ce fichier contient la boite de choix (Gtk::ComboBox) suivant le modèle de destination_columns.h
Aucune information n'est à modifier ici :
    → Pour rajouter des éléments, aller dans destination_columns.h et de suivre les instructions qui s'y trouvent
    → Pour rajouter des donnés au sein de de la combobox, aller dans destination_combobox.c++ et modifier le constructeur
*/

#ifndef DESTINATION_COMBOBOX_H
#define DESTINATION_BOMBOBOX_H

#include "destination_columns.h"

#include <gtkmm.h>
#include <vector>

class Origin_combobox;

class Destination_combobox : public Gtk::ComboBox
{
private:
    //Colomnes pour définir définir les éléments de la combobox
    Destination_columns destination_columns;

    //Méthode pour rajouter des destinations aux listes d'origines
    void create_destination_list(Origin_combobox &origin_list,
                                 std::string origin_searched,
                                 std::vector<std::string> destination_list);

public:
    //constructeur
    Destination_combobox(Origin_combobox &origin_list);

    //méthode pour changer les destinations de la combobox selon l'origine
    void change_destination_model(Glib::RefPtr<Gtk::ListStore> destination_model);

    //getters
    Destination_columns &get_destination_columns() { return destination_columns; };
};

#endif //PRESET_COMBOBOX_H