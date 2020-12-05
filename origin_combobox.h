/*
Ce fichier contient la boite de choix (Gtk::ComboBox) suivant le modèle de origin_columns.h
Aucune information n'est à modifier ici :
    → Pour rajouter des éléments, aller dans origin_columns.h et de suivre les instructions qui s'y trouvent
    → Pour rajouter des donnés au sein de de la combobox, aller dans origin_combobox.c++ et modifier le constructeur
*/

#ifndef PRESET_COMBOBOX_H
#define PRESET_BOMBOBOX_H

#include "origin_columns.h"

#include <gtkmm.h>
#include <vector>

class Origin_combobox : public Gtk::ComboBox
{
private:
    //Colomnes pour définir définir les éléments et modèle pour définir la forme de la combobox
    Origin_columns origin_columns;
    Glib::RefPtr<Gtk::ListStore> origin_model;

    //Méthode pour le rajout des origines
    void create_origin_list(std::vector<std::string> origin_list);

public:
    //constructeur
    Origin_combobox();

    //méthode pour vérifier si chaque origine a au moins une destination
    void verify_destination_existence();

    //getters
    Origin_columns &get_origin_columns() { return origin_columns; };
    Glib::RefPtr<Gtk::ListStore> &get_origin_model() { return origin_model; };
};

#endif //PRESET_COMBOBOX_H