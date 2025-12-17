
#include "GtkComboBox.h"

/**
 * Constructor
 */
GtkComboBox_::GtkComboBox_() = default;

/**
 * Destructor
 */
GtkComboBox_::~GtkComboBox_() = default;

void GtkComboBox_::__construct()
{
	instance = (gpointer *)gtk_combo_box_new ();
	liststore_type = false;
}

Php::Value GtkComboBox_::new_with_entry()
{
	GtkWidget *combobox = gtk_combo_box_new_with_entry();

	GtkComboBox_ *phpgtk_combobox = new GtkComboBox_();
	phpgtk_combobox->set_instance((gpointer *)combobox);
	return Php::Object("GtkComboBox", phpgtk_combobox);

}

Php::Value GtkComboBox_::new_with_model(Php::Parameters &parameters)
{
	Php::Value object_model = parameters[0];
	GtkTreeModel_ *phpgtk_model = (GtkTreeModel_ *)object_model.implementation();
	GtkTreeModel *model = phpgtk_model->get_model();

	GtkWidget *combobox = gtk_combo_box_new_with_model(GTK_TREE_MODEL(model));

	GtkComboBox_ *phpgtk_combobox = new GtkComboBox_();
	phpgtk_combobox->set_instance((gpointer *)combobox);

	// Store the Model type
	phpgtk_combobox->liststore_type = false;
	if(object_model.instanceOf("GtkListStore")) {
		phpgtk_combobox->liststore_type = true;
	}

	return Php::Object("GtkComboBox", phpgtk_combobox);

}

Php::Value GtkComboBox_::new_with_model_and_entry(Php::Parameters &parameters)
{
	GtkTreeModel *model;
	Php::Value object_model;
	if(parameters.size() > 0) {
		object_model = parameters[0];
		GtkTreeModel_ *phpgtk_model = (GtkTreeModel_ *)object_model.implementation();
		model = phpgtk_model->get_model();
	}

	GtkWidget *combobox = gtk_combo_box_new_with_model_and_entry (model);

	GtkComboBox_ *phpgtk_combobox = new GtkComboBox_();
	phpgtk_combobox->set_instance((gpointer *)combobox);

	// Store the Model type
	phpgtk_combobox->liststore_type = false;
	if(object_model.instanceOf("GtkListStore")) {
		phpgtk_combobox->liststore_type = true;
	}
	
	return Php::Object("GtkComboBox", phpgtk_combobox);
}

Php::Value GtkComboBox_::new_with_area(Php::Parameters &parameters)
{
	// GtkCellArea *area;
	// if(parameters.size() > 0) {
	// 	Php::Value object_area = parameters[0];
	// 	GtkCellArea_ *phpgtk_area = (GtkCellArea_ *)object_area.implementation();
	// 	area = GTK_CELL_AREA(phpgtk_area->get_instance());
	// }

	// instance = (gpointer *)gtk_combo_box_new_with_area (area);

	throw Php::Exception("GtkComboBox_::new_with_area not implemented");

}

Php::Value GtkComboBox_::new_with_area_and_entry(Php::Parameters &parameters)
{
	// GtkCellArea *area;
	// if(parameters.size() > 0) {
	// 	Php::Value object_area = parameters[0];
	// 	GtkCellArea_ *phpgtk_area = (GtkCellArea_ *)object_area.implementation();
	// 	area = GTK_CELL_AREA(phpgtk_area->get_instance());
	// }

	// instance = (gpointer *)gtk_combo_box_new_with_area_and_entry (area);

	throw Php::Exception("GtkComboBox_::new_with_area_and_entry not implemented");

}

Php::Value GtkComboBox_::get_wrap_width()
{
	gint ret = gtk_combo_box_get_wrap_width (GTK_COMBO_BOX(instance));

	return ret;
}

void GtkComboBox_::set_wrap_width(Php::Parameters &parameters)
{
	gint width = (gint)parameters[0];

	gtk_combo_box_set_wrap_width (GTK_COMBO_BOX(instance), width);

}

Php::Value GtkComboBox_::get_row_span_column()
{
	gint ret = gtk_combo_box_get_row_span_column (GTK_COMBO_BOX(instance));

	return ret;
}

void GtkComboBox_::set_row_span_column(Php::Parameters &parameters)
{
	gint row_span = (gint)parameters[0];

	gtk_combo_box_set_row_span_column (GTK_COMBO_BOX(instance), row_span);

}

Php::Value GtkComboBox_::get_column_span_column()
{
	gint ret = gtk_combo_box_get_column_span_column (GTK_COMBO_BOX(instance));

	return ret;
}

void GtkComboBox_::set_column_span_column(Php::Parameters &parameters)
{
	gint column_span = (gint)parameters[0];

	gtk_combo_box_set_column_span_column (GTK_COMBO_BOX(instance), column_span);

}

Php::Value GtkComboBox_::get_active()
{
	gint ret = gtk_combo_box_get_active (GTK_COMBO_BOX(instance));

	return ret;
}


void GtkComboBox_::set_active(Php::Parameters &parameters)
{
	gint index_ = (gint)parameters[0];

	gtk_combo_box_set_active (GTK_COMBO_BOX(instance), index_);

}

Php::Value GtkComboBox_::get_active_iter()
{
	GtkTreeIter iter;
	bool ret = gtk_combo_box_get_active_iter (GTK_COMBO_BOX(instance), &iter);
	if(!ret) 
		return (bool)ret;

	GtkTreeIter_ *return_parsed = new GtkTreeIter_();
	return_parsed->set_instance(iter);
	return Php::Object("GtkTreeIter", return_parsed);
}

void GtkComboBox_::set_active_iter(Php::Parameters &parameters)
{
	GtkTreeIter iter;
	if(parameters.size() > 0) {
		Php::Value object_iter = parameters[0];
		GtkTreeIter_ *phpgtk_iter = (GtkTreeIter_ *)object_iter.implementation();
		iter = phpgtk_iter->get_instance();
	}

	gtk_combo_box_set_active_iter (GTK_COMBO_BOX(instance), &iter);

}

Php::Value GtkComboBox_::get_id_column()
{
	gint ret = gtk_combo_box_get_id_column (GTK_COMBO_BOX(instance));

	return ret;
}

void GtkComboBox_::set_id_column(Php::Parameters &parameters)
{
	gint id_column = (gint)parameters[0];

	gtk_combo_box_set_id_column (GTK_COMBO_BOX(instance), id_column);

}

Php::Value GtkComboBox_::get_active_id()
{
	std::string ret = gtk_combo_box_get_active_id (GTK_COMBO_BOX(instance));

	return ret;
}

void GtkComboBox_::set_active_id(Php::Parameters &parameters)
{
	std::string s_active_id = parameters[0];
	gchar *active_id = (gchar *)s_active_id.c_str();

	gtk_combo_box_set_active_id (GTK_COMBO_BOX(instance), active_id);

}

Php::Value GtkComboBox_::get_model()
{
	GtkTreeModel *ret = gtk_combo_box_get_model (GTK_COMBO_BOX(instance));

	GtkTreeModel_ *return_parsed = new GtkTreeModel_();
	return_parsed->set_model(ret);

	if(liststore_type) {
		return Php::Object("GtkListStore", return_parsed);
	}
	
	return Php::Object("GtkTreeStore", return_parsed);
}

void GtkComboBox_::set_model(Php::Parameters &parameters)
{
	GtkTreeModel *model = NULL;
	Php::Value object_model;
	if(parameters.size() > 0) {
		object_model = parameters[0];
		// Allow NULL to clear the model
		if(!object_model.isNull()) {
			GtkTreeModel_ *phpgtk_model = (GtkTreeModel_ *)object_model.implementation();
			model = phpgtk_model->get_model();
			// Store the Model type
			liststore_type = false;
			if(object_model.instanceOf("GtkListStore")) {
				liststore_type = true;
			}
		} else {
			liststore_type = false;
		}
	}

	gtk_combo_box_set_model (GTK_COMBO_BOX(instance), model);

}

void GtkComboBox_::popup_for_device(Php::Parameters &parameters)
{
	// GdkDevice *device;
	// if(parameters.size() > 0) {
	// 	Php::Value object_device = parameters[0];
	// 	GdkDevice_ *phpgtk_device = (GdkDevice_ *)object_device.implementation();
	// 	device = GTK_WIDGET(phpgtk_device->get_instance());
	// }

	// gtk_combo_box_popup_for_device (GTK_COMBO_BOX(instance), device);

	throw Php::Exception("GtkComboBox_::popup_for_device not implemented");
}

void GtkComboBox_::popup()
{
	gtk_combo_box_popup (GTK_COMBO_BOX(instance));

}

void GtkComboBox_::popdown()
{
	gtk_combo_box_popdown (GTK_COMBO_BOX(instance));

}

Php::Value GtkComboBox_::get_popup_accessible()
{
	// AtkObject ret = gtk_combo_box_get_popup_accessible (GTK_COMBO_BOX(instance));

	// return ret;

	throw Php::Exception("GtkComboBox_::get_popup_accessible not implemented");
}

Php::Value GtkComboBox_::get_row_separator_func()
{
	// std::string ret = gtk_combo_box_get_row_separator_func (GTK_COMBO_BOX(instance));

	// return ret;

	throw Php::Exception("GtkComboBox_::get_row_separator_func not implemented");
}

void GtkComboBox_::set_row_separator_func(Php::Parameters &parameters)
{
	// std::string s_func = parameters[0];
	// gchar *func = (gchar *)s_func.c_str();

	// gpointer data = (gpointer)parameters[1];

	// std::string s_destroy = parameters[2];
	// gchar *destroy = (gchar *)s_destroy.c_str();

	// gtk_combo_box_set_row_separator_func (GTK_COMBO_BOX(instance), func, data, destroy);

	throw Php::Exception("GtkComboBox_::set_row_separator_func not implemented");
}

void GtkComboBox_::set_button_sensitivity(Php::Parameters &parameters)
{
	int int_sensitivity = (int)parameters[0];
	GtkSensitivityType sensitivity = (GtkSensitivityType)int_sensitivity;

	gtk_combo_box_set_button_sensitivity (GTK_COMBO_BOX(instance), sensitivity);

}

Php::Value GtkComboBox_::get_button_sensitivity()
{
	GtkSensitivityType ret = gtk_combo_box_get_button_sensitivity (GTK_COMBO_BOX(instance));

	return ret;
}

Php::Value GtkComboBox_::get_has_entry()
{
	bool ret = gtk_combo_box_get_has_entry (GTK_COMBO_BOX(instance));

	return ret;
}

Php::Value GtkComboBox_::get_entry_text_column()
{
	gint ret = gtk_combo_box_get_entry_text_column (GTK_COMBO_BOX(instance));

	return ret;
}

void GtkComboBox_::set_entry_text_column(Php::Parameters &parameters)
{
	gint text_column = (gint)parameters[0];

	gtk_combo_box_set_entry_text_column (GTK_COMBO_BOX(instance), text_column);

}

Php::Value GtkComboBox_::get_popup_fixed_width()
{
	bool ret = gtk_combo_box_get_popup_fixed_width (GTK_COMBO_BOX(instance));

	return ret;
}

void GtkComboBox_::set_popup_fixed_width(Php::Parameters &parameters)
{
	gboolean fixed = (gboolean)parameters[0];

	gtk_combo_box_set_popup_fixed_width (GTK_COMBO_BOX(instance), fixed);

}







// FROM INTERFACE
void GtkComboBox_::pack_start(Php::Parameters &parameters)
{
	Php::Value object = parameters[0];
	GtkCellRenderer_ *passedRenderer = (GtkCellRenderer_ *)object.implementation();

	gboolean expand = parameters[1];

	gtk_cell_layout_pack_start (GTK_CELL_LAYOUT(instance), GTK_CELL_RENDERER(passedRenderer->get_instance()), expand);

}

void GtkComboBox_::pack_end(Php::Parameters &parameters)
{
	Php::Value object = parameters[0];
	GtkCellRenderer_ *passedRenderer = (GtkCellRenderer_ *)object.implementation();

	gboolean expand = parameters[1];

	gtk_cell_layout_pack_end (GTK_CELL_LAYOUT(instance), GTK_CELL_RENDERER(passedRenderer->get_instance()), expand);

}

void GtkComboBox_::reorder(Php::Parameters &parameters)
{
	Php::Value object = parameters[0];
	GtkCellRenderer_ *passedRenderer = (GtkCellRenderer_ *)object.implementation();

	gint position = parameters[1];

	gtk_cell_layout_reorder (GTK_CELL_LAYOUT(instance), GTK_CELL_RENDERER(passedRenderer->get_instance()), position);
}

void GtkComboBox_::clear(Php::Parameters &parameters)
{
	gtk_cell_layout_clear (GTK_CELL_LAYOUT(instance));
}

void GtkComboBox_::add_attribute(Php::Parameters &parameters)
{
	Php::Value object = parameters[0];
	GtkCellRenderer_ *passedRenderer = (GtkCellRenderer_ *)object.implementation();

	std::string atribute = parameters[1];

	gint column = (int)parameters[2];

	gtk_cell_layout_add_attribute (GTK_CELL_LAYOUT(instance), GTK_CELL_RENDERER(passedRenderer->get_instance()), atribute.c_str(), column);
}