/*
Ce fichier contient les structure de donnés pour les presets. Pour rajouter des informations il faut rajouter :
    → Gtk::TreeModelColumn<T> value_name    dans la liste d'arguments pour définir une nouvelle donné
    → add(value_name)                       dans le constructeur pour la rattacher à la boite de choix

L'ordre n'a pas d'importance cependant faites attention à donner une valeur à chaque donné pour éviter le crash
*/

#ifndef PRESET_COLUMNS_H
#define PRESET_COLUMNS_H

#include <gtkmm.h>
#include <string>

class Preset_columns : public Gtk::TreeModel::ColumnRecord
{
public:
    //Toutes les informations nécessaires pour les options
    Gtk::TreeModelColumn<std::string> preset_name;
    Gtk::TreeModelColumn<bool> preset_editable;

    //Toutes les donnés cachés qui changent selon le preset
    Gtk::TreeModelColumn<int> valueA;

    //constructeur
    Preset_columns()
    {
        //Rajout des informations nécessaires pour les options
        add(preset_name);
        add(preset_editable);

        //Rajout des donnés cachés qui changent selon le preset
        add(valueA);
    }
};

#endif //PRESET_COLUMNS_H