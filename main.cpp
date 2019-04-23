/**
 * PHP-CPP
 *
 * Sobre como extender classes 
 *      https://github.com/CopernicaMarketingSoftware/PHP-CPP/issues/211
 *
 * 
 */

#include "main.h"

// https://www.sitepoint.com/developing-php-extensions-c-php-cpp-advanced/


/**
 *  tell the compiler that the get_module is a pure C function
 */
extern "C"
{

    /**
     *  Function that is called by PHP right after the PHP process
     *  has started, and that returns an address of an internal PHP
     *  strucure with all the details and features of your extension
     *
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module() 
    {
        // static(!) Php::Extension object that should stay in memory
        // for the entire duration of the process (that's why it's static)
        static Php::Extension extension("php-gtk3", "1.0");

        // Initialize GTK
        gtk_init (0, NULL);

        // Gtk
        Php::Class<Gtk_> gtk("Gtk");
            gtk.method<&Gtk_::main>("main");
            gtk.method<&Gtk_::main_quit>("main_quit");
            gtk.constant("ORIENTATION_HORIZONTAL", GTK_ORIENTATION_HORIZONTAL);
            gtk.constant("ORIENTATION_VERTICAL", GTK_ORIENTATION_VERTICAL);
            gtk.constant("ALIGN_FILL", GTK_ALIGN_FILL);
            gtk.constant("ALIGN_START", GTK_ALIGN_START);
            gtk.constant("ALIGN_END", GTK_ALIGN_END);
            gtk.constant("ALIGN_CENTER", GTK_ALIGN_CENTER);
            gtk.constant("ALIGN_BASELINE", GTK_ALIGN_BASELINE);


        // GdkEvent
        Php::Class<GdkEvent_> gdkevent("GdkEvent");
            // gdkevent.method<&GdkEvent_::__construct>("__construct");
            // gdkevent.property("type", 0);
        

        // GtkWidget
        Php::Class<GtkWidget_> gtkwidget("GtkWidget");
            gtkwidget.method<&GtkWidget_::show_all>("show_all");
            gtkwidget.method<&GtkWidget_::connect>("connect");
            gtkwidget.method<&GtkWidget_::destroy>("destroy");
            gtkwidget.method<&GtkWidget_::handler_disconnect>("handler_disconnect");
            gtkwidget.method<&GtkWidget_::in_destruction>("in_destruction");
            gtkwidget.method<&GtkWidget_::destroyed>("destroyed");
            gtkwidget.method<&GtkWidget_::unparent>("unparent");
            gtkwidget.method<&GtkWidget_::show>("show");
            gtkwidget.method<&GtkWidget_::show_now>("show_now");
            gtkwidget.method<&GtkWidget_::hide>("hide");
            gtkwidget.method<&GtkWidget_::map>("map");
            gtkwidget.method<&GtkWidget_::unmap>("unmap");
            gtkwidget.method<&GtkWidget_::realize>("realize");
            gtkwidget.method<&GtkWidget_::unrealize>("unrealize");
            gtkwidget.method<&GtkWidget_::draw>("draw");
            gtkwidget.method<&GtkWidget_::queue_draw>("queue_draw");
            gtkwidget.method<&GtkWidget_::queue_resize>("queue_resize");
            gtkwidget.method<&GtkWidget_::queue_resize_no_redraw>("queue_resize_no_redraw");
            gtkwidget.method<&GtkWidget_::queue_allocate>("queue_allocate");
            gtkwidget.method<&GtkWidget_::get_scale_factor>("get_scale_factor");
            gtkwidget.method<&GtkWidget_::activate>("activate");
            gtkwidget.method<&GtkWidget_::is_focus>("is_focus");
            gtkwidget.method<&GtkWidget_::grab_focus>("grab_focus");
            gtkwidget.method<&GtkWidget_::has_focus>("has_focus");
            gtkwidget.method<&GtkWidget_::grab_default>("grab_default");
            gtkwidget.method<&GtkWidget_::set_name>("set_name");
            gtkwidget.method<&GtkWidget_::get_name>("get_name");
            gtkwidget.method<&GtkWidget_::set_sensitive>("set_sensitive");
            gtkwidget.method<&GtkWidget_::get_sensitive>("get_sensitive");
            gtkwidget.method<&GtkWidget_::is_sensitive>("is_sensitive");
            gtkwidget.method<&GtkWidget_::mnemonic_activate>("mnemonic_activate");
            gtkwidget.method<&GtkWidget_::get_parent>("get_parent");
            gtkwidget.method<&GtkWidget_::set_tooltip_text>("set_tooltip_text");
            gtkwidget.method<&GtkWidget_::get_tooltip_text>("get_tooltip_text");
            gtkwidget.method<&GtkWidget_::get_allocated_width>("get_allocated_width");
            gtkwidget.method<&GtkWidget_::get_allocated_height>("get_allocated_height");
            gtkwidget.method<&GtkWidget_::set_focus_on_click>("set_focus_on_click");
            gtkwidget.method<&GtkWidget_::set_visible>("set_visible");
            gtkwidget.method<&GtkWidget_::get_visible>("get_visible");
            gtkwidget.method<&GtkWidget_::set_opacity>("set_opacity");
            gtkwidget.method<&GtkWidget_::get_opacity>("get_opacity");
            gtkwidget.method<&GtkWidget_::set_valign>("set_valign");
            gtkwidget.method<&GtkWidget_::get_valign>("get_valign");
            gtkwidget.method<&GtkWidget_::set_halign>("set_halign");
            gtkwidget.method<&GtkWidget_::get_halign>("get_halign");
            gtkwidget.method<&GtkWidget_::set_margin_start>("set_margin_start");
            gtkwidget.method<&GtkWidget_::get_margin_start>("get_margin_start");
            gtkwidget.method<&GtkWidget_::set_margin_end>("set_margin_end");
            gtkwidget.method<&GtkWidget_::get_margin_end>("get_margin_end");
            gtkwidget.method<&GtkWidget_::set_margin_top>("set_margin_top");
            gtkwidget.method<&GtkWidget_::get_margin_top>("get_margin_top");
            gtkwidget.method<&GtkWidget_::set_margin_bottom>("set_margin_bottom");
            gtkwidget.method<&GtkWidget_::get_margin_bottom>("get_margin_bottom");
        

        // GtkContainer
        Php::Class<GtkContainer_> gtkcontainer("GtkContainer");
            gtkcontainer.extends(gtkwidget);
            gtkcontainer.method<&GtkContainer_::add>("add");
            gtkcontainer.method<&GtkContainer_::test2>("test2");


        // GtkBox
        Php::Class<GtkBox_> gtkbox("GtkBox");
            gtkbox.extends(gtkcontainer);
            gtkbox.method<&GtkBox_::__construct>("__construct");
            gtkbox.method<&GtkBox_::pack_start>("pack_start");
            gtkbox.method<&GtkBox_::pack_end>("pack_end");
            gtkbox.method<&GtkBox_::set_homogeneous>("set_homogeneous");
            gtkbox.method<&GtkBox_::set_spacing>("set_spacing");


        // GtkHBox
        Php::Class<GtkHBox_> gtkhbox("GtkHBox");
            gtkhbox.extends(gtkbox);
            gtkhbox.method<&GtkHBox_::__construct>("__construct");


        // GtkVBox
        Php::Class<GtkVBox_> gtkvbox("GtkVBox");
            gtkvbox.extends(gtkbox);
            gtkvbox.method<&GtkVBox_::__construct>("__construct");


        // GtkBin
        Php::Class<GtkBin_> gtkbin("GtkBin");
            gtkbin.extends(gtkcontainer);
            gtkbin.method<&GtkBin_::test3>("test3");


        // GtkWindow
        Php::Class<GtkWindow_> gtkwindow("GtkWindow");
            gtkwindow.extends(gtkbin);
            gtkwindow.method<&GtkWindow_::__construct>("__construct");
            gtkwindow.method<&GtkWindow_::set_title>("set_title");
            gtkwindow.method<&GtkWindow_::set_default_size>("set_default_size");
            gtkwindow.constant("TOPLEVEL", GTK_WINDOW_TOPLEVEL);
            gtkwindow.constant("POPUP", GTK_WINDOW_POPUP);


        // GtkButton
        Php::Class<GtkButton_> gtkbutton("GtkButton");
            gtkbutton.extends(gtkbin);
            gtkbutton.method<&GtkButton_::new_with_label>("new_with_label");
            gtkbutton.method<&GtkButton_::set_label>("set_label");


        // GtkRequisition
        // Php::Class<GtkRequisition_> gtkrequisition("GtkRequisition");
        //     gtkrequisition.method<&GtkRequisition_::__construct>("__construct");
        //     gtkrequisition.property("width", 0);
        //     gtkrequisition.property("height", 0);
            
        // GtkEntryBuffer
        Php::Class<GtkEntryBuffer_> gtkentrybuffer("GtkEntryBuffer");
            gtkentrybuffer.method<&GtkEntryBuffer_::__construct>("__construct");
            gtkentrybuffer.method<&GtkEntryBuffer_::get_text>("get_text");
            gtkentrybuffer.method<&GtkEntryBuffer_::set_text>("set_text");
            gtkentrybuffer.method<&GtkEntryBuffer_::get_bytes>("get_bytes");
            gtkentrybuffer.method<&GtkEntryBuffer_::get_length>("get_length");
            gtkentrybuffer.method<&GtkEntryBuffer_::get_max_length>("get_max_length");
            gtkentrybuffer.method<&GtkEntryBuffer_::insert_text>("insert_text");
            gtkentrybuffer.method<&GtkEntryBuffer_::delete_text>("delete_text");


        // GtkEntry
        Php::Class<GtkEntry_> gtkentry("GtkEntry");
            gtkentry.extends(gtkwidget);
            gtkentry.method<&GtkEntry_::__construct>("__construct");
            gtkentry.method<&GtkEntry_::new_with_buffer>("new_with_buffer");
            gtkentry.method<&GtkEntry_::get_buffer>("get_buffer");
            gtkentry.method<&GtkEntry_::set_buffer>("set_buffer");
            gtkentry.method<&GtkEntry_::get_text>("get_text");
            gtkentry.method<&GtkEntry_::set_text>("set_text");
            gtkentry.method<&GtkEntry_::get_text_length>("get_text_length");
            gtkentry.method<&GtkEntry_::set_visibility>("set_visibility");
            gtkentry.method<&GtkEntry_::set_invisible_char>("set_invisible_char");
            gtkentry.method<&GtkEntry_::unset_invisible_char>("unset_invisible_char");
            gtkentry.method<&GtkEntry_::set_max_length>("set_max_length");
            gtkentry.method<&GtkEntry_::set_activates_default>("set_activates_default");
            gtkentry.method<&GtkEntry_::get_activates_default>("get_activates_default");
            gtkentry.method<&GtkEntry_::set_has_frame>("set_has_frame");
            gtkentry.method<&GtkEntry_::get_has_frame>("get_has_frame");


        // Add
        extension.add(std::move(gtk));
        extension.add(std::move(gdkevent));
        extension.add(std::move(gtkwidget));
        extension.add(std::move(gtkentry));
        extension.add(std::move(gtkcontainer));
        extension.add(std::move(gtkbox));
        extension.add(std::move(gtkhbox));
        extension.add(std::move(gtkvbox));
        extension.add(std::move(gtkbin));
        extension.add(std::move(gtkwindow));
        extension.add(std::move(gtkbutton));
        extension.add(std::move(gtkentrybuffer));


        // return the extension
        return extension;
    }
}