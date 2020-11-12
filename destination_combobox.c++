#include "destination_combobox.h"
#include "origin_combobox.h"

#include <iostream>

Destination_combobox::Destination_combobox(Origin_combobox &origin_list)
{
    //Rend la colonne avec le nom des destinations visibles
    pack_start(destination_columns.destination_name);

    //Rajouter les différentes destinations pour chaque origines.
    //Envoyer la combobox avec les origines, le nom de l'origine pour laquelle on veut rajouter des destinations et une liste de destination
    //Attention si le nombre de  liste des destinations est différent que le nombre d'origines le programme va planter
    this->create_destination_list(origin_list, "Origine 1",
                                  {"O1D1",
                                   "O1D2"});
    this->create_destination_list(origin_list, "Origine 2",
                                  {"O2D1",
                                   "O2D2",
                                   "O2D3"});

    //Vérifie si chaque origine a au moins une destination
    origin_list.verify_destination_existence();
}

//Méthode à modifier uniquement si des donnés sont rajoutés à destination_columns.h :  il faut →
void Destination_combobox::create_destination_list(Origin_combobox &origin_list,
                                                   std::string origin_searched,
                                                   std::vector<std::string> destination_list)
{
    //→ vérifier aussi que chaque vecteurs a la même taille

    //vérifie si la liste des destinations n'est pas vide
    if (!destination_list.size())
        std::cerr << "empty destination list given\n";
    else
    {
        //vérifie si l'origine donné existe
        Gtk::TreeModel::iterator origin_iterator = origin_list.get_origin_model()->children().begin();
        while (origin_iterator != origin_list.get_model()->children().end() &&
               origin_iterator->get_value(origin_list.get_origin_columns().origin_name) != origin_searched)
            origin_iterator++;

        if (origin_iterator == origin_list.get_model()->children().end())
            std::cerr << "L'origine " << origin_searched << " n'existe pas";
        else
        {
            //Crée une rangée et un model qui contiendra la liste des destinations
            Gtk::TreeModel::Row destination_row;
            Glib::RefPtr<Gtk::ListStore> destination_model = Gtk::ListStore::create(origin_list.get_origin_columns());

            //rajouter une nouvelle ligne pour chaque élément donné et rajoute le string donné
            for (std::string destination : destination_list /*→ ; auto other_value : other_vector_value*/)
            {
                destination_row = *(destination_model->append());
                destination_row[destination_columns.destination_name] = destination;
                //→ Ajouter l'affectation de toutes les valeurs
            }
            origin_iterator->set_value(origin_list.get_origin_columns().possible_destinations, destination_model);
        }
    }
}

//Méthode à ne pas modifier
void Destination_combobox::change_destination_model(Glib::RefPtr<Gtk::ListStore> destination_model)
{
    //Change le modèle et définit le premier élément comme actif
    set_model(destination_model);
    set_active(0);
}