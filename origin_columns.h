/*
Ce fichier contient les structure de donnés pour les origines. Celle-ci contient deux éléments principaux :
    → origin_name               représentant le nom de l'origine, nom qui sera visible à l'utilisateur
    → possible_destination      Store l'arbre des destinations possible, lorsque selectionné celui-ci sera inclut dans la combobox des destinations

Normalement cette class ne doit pas être modifié, cependant si besoins est, il suffit de rajouter :
    → Gtk::TreeModelColumn<T> value_name    dans la liste d'arguments pour définir une nouvelle donné
    → add(value_name)                       dans le constructeur pour la rattacher à la boite de choix
L'ordre n'a pas d'importance cependant faites attention à donner une valeur à chaque donné pour éviter le crash
*/

#ifndef ORIGIN_COLUMNS_H
#define ORIGIN_COLUMNS_H

#include <gtkmm.h>
#include <string>

class Origin_columns : public Gtk::TreeModel::ColumnRecord
{
public:
    //Toutes les informations nécessaires pour les options
    Gtk::TreeModelColumn<std::string> origin_name;
    Gtk::TreeModelColumn<Glib::RefPtr<Gtk::ListStore>> possible_destinations;

    //Toutes les donnés cachés qui changent selon l'origine

    //constructeur
    Origin_columns()
    {
        //Rajout des informations nécessaires pour les options
        add(origin_name);
        add(possible_destinations);

        //Rajout des donnés cachés qui changent selon l'origine
    }
};

#endif //ORIGIN_COLUMNS_H