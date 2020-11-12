#include "preset_combobox.h"

Preset_combobox::Preset_combobox()
{
    //définit le model de la Gtk::ComboBox et rajoute la colomne preset_name comme visible
    preset_model = Gtk::ListStore::create(preset_columns);
    set_model(preset_model);
    pack_start(preset_columns.preset_name);

    //Pour chaque nouvel élément à rajouter : ajouter un nouveau rang et définir un ses valeurs
    this->create_preset("Preset 1", false, 12);
    this->create_preset("Preset 2", false, 36);
    this->create_preset("Preset 3", true, 712);
}

//Modifier si des types de donnés ont été ajoutés à ^reset_colums.h
void Preset_combobox::create_preset(std::string preset_name,
                                    bool editable,
                                    int valueA)
{
    Gtk::TreeModel::Row preset_row = *(preset_model->append());
    preset_row[preset_columns.preset_name] = preset_name;
    preset_row[preset_columns.preset_editable] = editable;
    preset_row[preset_columns.valueA] = valueA;
}