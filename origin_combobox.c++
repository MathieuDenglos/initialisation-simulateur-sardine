#include "origin_combobox.h"

#include <iostream>

Origin_combobox::Origin_combobox()
{
    //définit le model de la Gtk::ComboBox et rajoute la colomne origin_name comme visible
    origin_model = Gtk::ListStore::create(origin_columns);
    set_model(origin_model);
    pack_start(origin_columns.origin_name);

    //Appelle une fonction qui créera la liste d'origines en fonction des valeurs envoyé
    //cette méthode doit être appelé une unique fois
    this->create_origin_list({"Origine 1",
                              "Origine 2"});
}

//Cette méthode doit être modifiée que si des donnés sont rajouté à origin_columns.h : il faut →
void Origin_combobox::create_origin_list(std::vector<std::string> origin_list)
{
    //→ vérifier aussi que chaque vecteurs a la même taille

    //vérifie si la liste des destinations n'est pas vide
    if (!origin_list.size())
        std::cerr << "aucune origine envoyé, le combobox sera vide";
    else
    {
        Gtk::TreeModel::Row origin_row;
        for (std::string origin_name : origin_list /*→ ; auto other_value : other_vector_value*/)
        {
            origin_row = *(origin_model->append());
            origin_row[origin_columns.origin_name] = origin_name;
            //→ Ajouter l'affectation de toutes les valeurs
        }
    }
}

//Cette méthode ne doit pas être modifiée
void Origin_combobox::verify_destination_existence()
{
    //Cette méthode vérifie juste que chaque origine a au moins une destination
    Gtk::TreeModel::iterator origin_iterator = origin_model->children().begin();
    for (Gtk::TreeModel::iterator origin_iterator = origin_model->children().begin();
         origin_iterator != origin_model->children().end();
         ++origin_iterator)
        if (!origin_iterator->get_value(origin_columns.possible_destinations))
            std::cerr << "L'origine " << origin_iterator->get_value(origin_columns.origin_name) << " n'a pas de destinations\n";
}