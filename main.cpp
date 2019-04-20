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
            gtkwidget.method<&GtkWidget_::get_frame_clock>("get_frame_clock");
            gtkwidget.method<&GtkWidget_::get_scale_factor>("get_scale_factor");
            gtkwidget.method<&GtkWidget_::GtkTickCallback>("GtkTickCallback");
            gtkwidget.method<&GtkWidget_::add_tick_callback>("add_tick_callback");
            gtkwidget.method<&GtkWidget_::remove_tick_callback>("remove_tick_callback");
            gtkwidget.method<&GtkWidget_::size_request>("size_request");
        

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
            

        // Add
        extension.add(std::move(gtk));
        extension.add(std::move(gdkevent));
        extension.add(std::move(gtkwidget));
        extension.add(std::move(gtkcontainer));
        extension.add(std::move(gtkbox));
        extension.add(std::move(gtkhbox));
        extension.add(std::move(gtkvbox));
        extension.add(std::move(gtkbin));
        extension.add(std::move(gtkwindow));
        extension.add(std::move(gtkbutton));


        // return the extension
        return extension;
    }
}