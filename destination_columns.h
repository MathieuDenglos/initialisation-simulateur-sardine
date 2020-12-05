/*
Ce fichier contient les structure de donnés pour les destinations. Celle-ci contient un élément principal :
    → destination_name      Store la liste des destinations. Sachant que celles-ci changent selon l'arbre stocké dans origin_columns.h

Normalement cette class ne doit pas être modifié, cependant si besoins est, il suffit de rajouter :
    → Gtk::TreeModelColumn<T> value_name    dans la liste d'arguments pour définir une nouvelle donné
    → add(value_name)                       dans le constructeur pour la rattacher à la boite de choix
L'ordre n'a pas d'importance cependant faites attention à donner une valeur à chaque donné pour éviter le crash
*/

#ifndef DESTINATION_COLUMNS_H
#define DESTINATION_COLUMNS_H

#include <gtkmm.h>
#include <string>

class Destination_columns : public Gtk::TreeModel::ColumnRecord
{
public:
    //Toutes les informations nécessaires pour les options
    Gtk::TreeModelColumn<std::string> destination_name;

    //Toutes les donnés cachés qui changent selon la destination

    //constructeur
    Destination_columns()
    {
        //Rajout des informations nécessaires pour les options
        add(destination_name);

        //Rajout des donnés cachés qui changent selon la destination
    }
};

#endif //DESTINATION_COLUMNS_H