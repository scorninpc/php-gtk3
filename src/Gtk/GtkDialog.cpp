
#include "GtkDialog.h"

/**
 * Constructor
 */
GtkDialog_::GtkDialog_() = default;

/**
 * Destructor
 */
GtkDialog_::~GtkDialog_() = default;


void GtkDialog_::__construct()
{
    instance = (gpointer *)gtk_dialog_new ();

}


Php::Value GtkDialog_::new_with_buttons(Php::Parameters &parameters)
{
    std::string s_title = parameters[0];
    gchar *title = (gchar *)s_title.c_str();

    Php::Value object_parent = parameters[1];
    GtkWindow *parent = NULL;
    if (object_parent.instanceOf("GtkWindow")) {
        GtkWindow_ *phpgtk_parent = (GtkWindow_ *)object_parent.implementation();
        parent = GTK_WINDOW(phpgtk_parent->get_instance());
    }

    int int_flags = (int)parameters[2];
    GtkDialogFlags flags = (GtkDialogFlags)int_flags;

    Php::Value arr = parameters[3];
    if(arr.size() < 2) {
         throw Php::Exception("parameters expect one button with response");
    }

    GtkWidget *instance_dialog = gtk_dialog_new_with_buttons(title, parent, flags, arr[0], (int)arr[1], NULL);

    // Add buttons
    for(int index=2; index < (int)arr.size(); index+=2) {
        gtk_dialog_add_button(GTK_DIALOG(instance_dialog), arr[index], (int)arr[index+1]);
        
    }

    // Create object
    GtkDialog_ *dialog = new GtkDialog_();
    dialog->set_instance((gpointer *)instance_dialog);
    return Php::Object("GtkDialog", dialog);
}

Php::Value GtkDialog_::run()
{
    gint ret = gtk_dialog_run (GTK_DIALOG(instance));

    return ret;
}

void GtkDialog_::response(Php::Parameters &parameters)
{
    gint response_id = (gint)parameters[0];

    gtk_dialog_response (GTK_DIALOG(instance), response_id);

}

void GtkDialog_::add_button(Php::Parameters &parameters)
{
    std::string s_button_text = parameters[0];
    gchar *button_text = (gchar *)s_button_text.c_str();

    gint response_id = (gint)parameters[1];

    gtk_dialog_add_button (GTK_DIALOG(instance), button_text, response_id);

}

void GtkDialog_::add_buttons(Php::Parameters &parameters)
{

    Php::Value arr = parameters[0];
    
    // Add buttons
    for(int index=0; index<(int)arr.size(); index+=2) {
        gtk_dialog_add_button(GTK_DIALOG(instance), arr[index], arr[index+1]);
        
    }

}

void GtkDialog_::add_action_widget(Php::Parameters &parameters)
{
    GtkWidget *child;
    if(parameters.size() > 0) {
        Php::Value object_child = parameters[0];
        GtkWidget_ *phpgtk_child = (GtkWidget_ *)object_child.implementation();
        child = GTK_WIDGET(phpgtk_child->get_instance());
    }

    gint response_id = (gint)parameters[1];

    gtk_dialog_add_action_widget (GTK_DIALOG(instance), child, response_id);

}

void GtkDialog_::set_default_response(Php::Parameters &parameters)
{
    gint response_id = (gint)parameters[0];

    gtk_dialog_set_default_response (GTK_DIALOG(instance), response_id);

}

void GtkDialog_::set_response_sensitive(Php::Parameters &parameters)
{
    gint response_id = (gint)parameters[0];

    gboolean setting = (gboolean)parameters[1];

    gtk_dialog_set_response_sensitive (GTK_DIALOG(instance), response_id, setting);

}

void GtkDialog_::get_response_for_widget(Php::Parameters &parameters)
{
    GtkWidget *widget;
    if(parameters.size() > 0) {
        Php::Value object_widget = parameters[0];
        GtkWidget_ *phpgtk_widget = (GtkWidget_ *)object_widget.implementation();
        widget = GTK_WIDGET(phpgtk_widget->get_instance());
    }

    gtk_dialog_get_response_for_widget (GTK_DIALOG(instance), widget);

}

Php::Value GtkDialog_::get_widget_for_response(Php::Parameters &parameters)
{
    gint response_id = (gint)parameters[0];

    gpointer *ret = (gpointer *)gtk_dialog_get_widget_for_response (GTK_DIALOG(instance), response_id);

    // GtkWidget_ *return_parsed = new GtkWidget_();
    // return_parsed->set_instance((gpointer *)ret);
    // return Php::Object("GtkWidget", return_parsed);

    return cobject_to_phpobject(ret);
}

Php::Value GtkDialog_::get_content_area()
{
    gpointer *ret = (gpointer *)gtk_dialog_get_content_area (GTK_DIALOG(instance));

    // GtkBox_ *return_parsed = new GtkBox_();
    // return_parsed->set_instance((gpointer *)ret);
    // return Php::Object("GtkBox", return_parsed);

    return cobject_to_phpobject(ret);
}

Php::Value GtkDialog_::get_header_bar()
{
    gpointer *ret = (gpointer *)gtk_dialog_get_header_bar (GTK_DIALOG(instance));

    return cobject_to_phpobject(ret);

    // GtkWidget_ *return_parsed = new GtkWidget_();
    // return_parsed->set_instance((gpointer *)ret);
    // return Php::Object("GtkWidget", return_parsed);
}

