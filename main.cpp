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

        // GObject
        Php::Class<GObject_> gobject("GObject");
            gobject.method<&GtkWidget_::connect>("connect");
            gobject.method<&GtkWidget_::handler_disconnect>("handler_disconnect");
            gobject.constant("TYPE_INVALID", (int)G_TYPE_INVALID);
            gobject.constant("TYPE_NONE", (int)G_TYPE_NONE);
            gobject.constant("TYPE_INTERFACE", (int)G_TYPE_INTERFACE);
            gobject.constant("TYPE_CHAR", (int)G_TYPE_CHAR);
            gobject.constant("TYPE_UCHAR", (int)G_TYPE_UCHAR);
            gobject.constant("TYPE_BOOLEAN", (int)G_TYPE_BOOLEAN);
            gobject.constant("TYPE_INT", (int)G_TYPE_INT);
            gobject.constant("TYPE_UINT", (int)G_TYPE_UINT);
            gobject.constant("TYPE_LONG", (int)G_TYPE_LONG);
            gobject.constant("TYPE_ULONG", (int)G_TYPE_ULONG);
            gobject.constant("TYPE_INT64", (int)G_TYPE_INT64);
            gobject.constant("TYPE_UINT64", (int)G_TYPE_UINT64);
            gobject.constant("TYPE_ENUM", (int)G_TYPE_ENUM);
            gobject.constant("TYPE_FLAGS", (int)G_TYPE_FLAGS);
            gobject.constant("TYPE_FLOAT", (int)G_TYPE_FLOAT);
            gobject.constant("TYPE_DOUBLE", (int)G_TYPE_DOUBLE);
            gobject.constant("TYPE_STRING", (int)G_TYPE_STRING);
            gobject.constant("TYPE_POINTER", (int)G_TYPE_POINTER);
            gobject.constant("TYPE_BOXED", (int)G_TYPE_BOXED);
            gobject.constant("TYPE_PARAM", (int)G_TYPE_PARAM);
            gobject.constant("TYPE_OBJECT", (int)G_TYPE_OBJECT);
            gobject.constant("TYPE_GTYPE", (int)G_TYPE_GTYPE);
            gobject.constant("TYPE_VARIANT", (int)G_TYPE_VARIANT);
            gobject.constant("TYPE_CHECKSUM", (int)G_TYPE_CHECKSUM);

        // Gdk
        Php::Class<Gdk_> gdk("Gdk");
            gdk.constant("SHIFT_MASK", GDK_SHIFT_MASK);
            gdk.constant("LOCK_MASK", GDK_LOCK_MASK);
            gdk.constant("CONTROL_MASK", GDK_CONTROL_MASK);
            gdk.constant("MOD1_MASK", GDK_MOD1_MASK);
            gdk.constant("MOD2_MASK", GDK_MOD2_MASK);
            gdk.constant("MOD3_MASK", GDK_MOD3_MASK);
            gdk.constant("MOD4_MASK", GDK_MOD4_MASK);
            gdk.constant("MOD5_MASK", GDK_MOD5_MASK);
            gdk.constant("BUTTON1_MASK", GDK_BUTTON1_MASK);
            gdk.constant("BUTTON2_MASK", GDK_BUTTON2_MASK);
            gdk.constant("BUTTON3_MASK", GDK_BUTTON3_MASK);
            gdk.constant("BUTTON4_MASK", GDK_BUTTON4_MASK);
            gdk.constant("BUTTON5_MASK", GDK_BUTTON5_MASK);
            gdk.constant("MODIFIER_RESERVED_13_MASK", GDK_MODIFIER_RESERVED_13_MASK);
            gdk.constant("MODIFIER_RESERVED_14_MASK", GDK_MODIFIER_RESERVED_14_MASK);
            gdk.constant("MODIFIER_RESERVED_15_MASK", GDK_MODIFIER_RESERVED_15_MASK);
            gdk.constant("MODIFIER_RESERVED_16_MASK", GDK_MODIFIER_RESERVED_16_MASK);
            gdk.constant("MODIFIER_RESERVED_17_MASK", GDK_MODIFIER_RESERVED_17_MASK);
            gdk.constant("MODIFIER_RESERVED_18_MASK", GDK_MODIFIER_RESERVED_18_MASK);
            gdk.constant("MODIFIER_RESERVED_19_MASK", GDK_MODIFIER_RESERVED_19_MASK);
            gdk.constant("MODIFIER_RESERVED_20_MASK", GDK_MODIFIER_RESERVED_20_MASK);
            gdk.constant("MODIFIER_RESERVED_21_MASK", GDK_MODIFIER_RESERVED_21_MASK);
            gdk.constant("MODIFIER_RESERVED_22_MASK", GDK_MODIFIER_RESERVED_22_MASK);
            gdk.constant("MODIFIER_RESERVED_23_MASK", GDK_MODIFIER_RESERVED_23_MASK);
            gdk.constant("MODIFIER_RESERVED_24_MASK", GDK_MODIFIER_RESERVED_24_MASK);
            gdk.constant("MODIFIER_RESERVED_25_MASK", GDK_MODIFIER_RESERVED_25_MASK);
            gdk.constant("SUPER_MASK", GDK_SUPER_MASK);
            gdk.constant("HYPER_MASK", GDK_HYPER_MASK);
            gdk.constant("META_MASK", GDK_META_MASK);
            gdk.constant("MODIFIER_RESERVED_29_MASK", GDK_MODIFIER_RESERVED_29_MASK);
            gdk.constant("RELEASE_MASK", GDK_RELEASE_MASK);
            gdk.constant("MODIFIER_MASK", GDK_MODIFIER_MASK);
            gdk.constant("WINDOW_TYPE_HINT_NORMAL", GDK_WINDOW_TYPE_HINT_NORMAL);
            gdk.constant("WINDOW_TYPE_HINT_DIALOG", GDK_WINDOW_TYPE_HINT_DIALOG);
            gdk.constant("WINDOW_TYPE_HINT_MENU", GDK_WINDOW_TYPE_HINT_MENU);
            gdk.constant("WINDOW_TYPE_HINT_TOOLBAR", GDK_WINDOW_TYPE_HINT_TOOLBAR);
            gdk.constant("WINDOW_TYPE_HINT_SPLASHSCREEN", GDK_WINDOW_TYPE_HINT_SPLASHSCREEN);
            gdk.constant("WINDOW_TYPE_HINT_UTILITY", GDK_WINDOW_TYPE_HINT_UTILITY);
            gdk.constant("WINDOW_TYPE_HINT_DOCK", GDK_WINDOW_TYPE_HINT_DOCK);
            gdk.constant("WINDOW_TYPE_HINT_DESKTOP", GDK_WINDOW_TYPE_HINT_DESKTOP);
            gdk.constant("WINDOW_TYPE_HINT_DROPDOWN_MENU", GDK_WINDOW_TYPE_HINT_DROPDOWN_MENU);
            gdk.constant("WINDOW_TYPE_HINT_POPUP_MENU", GDK_WINDOW_TYPE_HINT_POPUP_MENU);
            gdk.constant("WINDOW_TYPE_HINT_TOOLTIP", GDK_WINDOW_TYPE_HINT_TOOLTIP);
            gdk.constant("WINDOW_TYPE_HINT_NOTIFICATION", GDK_WINDOW_TYPE_HINT_NOTIFICATION);
            gdk.constant("WINDOW_TYPE_HINT_COMBO", GDK_WINDOW_TYPE_HINT_COMBO);
            gdk.constant("WINDOW_TYPE_HINT_DND", GDK_WINDOW_TYPE_HINT_DND);
            gdk.constant("TYPE_PIXBUF",(int) GDK_TYPE_PIXBUF);


        // GdkEvent
        Php::Class<GdkEvent_> gdkevent("GdkEvent");
            // gdkevent.method<&GdkEvent_::__construct>("__construct");
            // gdkevent.property("type", 0);

        // GdkPixbuf
        Php::Class<GdkPixbuf_> gdkpixbuf("GdkPixbuf");
            gdkpixbuf.method<&GdkPixbuf_::__construct>("__construct");
            gdkpixbuf.method<&GdkPixbuf_::new_from_file>("new_from_file");


        // Gtk
        Php::Class<Gtk_> gtk("Gtk");
            gtk.method<&Gtk_::main>("main");
            gtk.method<&Gtk_::main_quit>("main_quit");
            
            // gtk.constant("a", a);
            
            gtk.constant("ORIENTATION_HORIZONTAL", GTK_ORIENTATION_HORIZONTAL);
            gtk.constant("ORIENTATION_VERTICAL", GTK_ORIENTATION_VERTICAL);
            
            gtk.constant("ALIGN_FILL", GTK_ALIGN_FILL);
            gtk.constant("ALIGN_START", GTK_ALIGN_START);
            gtk.constant("ALIGN_END", GTK_ALIGN_END);
            gtk.constant("ALIGN_CENTER", GTK_ALIGN_CENTER);
            gtk.constant("ALIGN_BASELINE", GTK_ALIGN_BASELINE);
            
            gtk.constant("WINDOW_TOPLEVEL", GTK_WINDOW_TOPLEVEL);
            gtk.constant("WINDOW_POPUP", GTK_WINDOW_POPUP);

            gtk.constant("WIN_POS_NONE", GTK_WIN_POS_NONE);
            gtk.constant("WIN_POS_CENTER", GTK_WIN_POS_CENTER);
            gtk.constant("WIN_POS_MOUSE", GTK_WIN_POS_MOUSE);
            gtk.constant("WIN_POS_CENTER_ALWAYS", GTK_WIN_POS_CENTER_ALWAYS);
            gtk.constant("WIN_POS_CENTER_ON_PARENT", GTK_WIN_POS_CENTER_ON_PARENT);
        

        // GtkWidget
        Php::Class<GtkWidget_> gtkwidget("GtkWidget");
            gtkwidget.extends(gobject);
            gtkwidget.method<&GtkWidget_::show_all>("show_all");
            gtkwidget.method<&GtkWidget_::destroy>("destroy");
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
            gtkwindow.method<&GtkWindow_::get_title>("get_title");
            gtkwindow.method<&GtkWindow_::set_default_size>("set_default_size");
            gtkwindow.method<&GtkWindow_::get_default_size>("get_default_size");
            gtkwindow.method<&GtkWindow_::set_resizable>("set_resizable");
            gtkwindow.method<&GtkWindow_::get_resizable>("get_resizable");
            gtkwindow.method<&GtkWindow_::activate_focus>("activate_focus");
            gtkwindow.method<&GtkWindow_::activate_default>("activate_default");
            gtkwindow.method<&GtkWindow_::set_modal>("set_modal");
            gtkwindow.method<&GtkWindow_::get_modal>("get_modal");
            gtkwindow.method<&GtkWindow_::set_position>("set_position");
            gtkwindow.method<&GtkWindow_::get_position>("get_position");
            gtkwindow.method<&GtkWindow_::set_transient_for>("set_transient_for");
            gtkwindow.method<&GtkWindow_::get_transient_for>("get_transient_for");
            gtkwindow.method<&GtkWindow_::set_destroy_with_parent>("set_destroy_with_parent");
            gtkwindow.method<&GtkWindow_::get_destroy_with_parent>("get_destroy_with_parent");
            gtkwindow.method<&GtkWindow_::set_hide_titlebar_when_maximized>("set_hide_titlebar_when_maximized");
            gtkwindow.method<&GtkWindow_::get_hide_titlebar_when_maximized>("get_hide_titlebar_when_maximized");
            gtkwindow.method<&GtkWindow_::is_active>("is_active");
            gtkwindow.method<&GtkWindow_::is_maximized>("is_maximized");
            gtkwindow.method<&GtkWindow_::has_toplevel_focus>("has_toplevel_focus");
            gtkwindow.method<&GtkWindow_::add_mnemonic>("add_mnemonic");
            gtkwindow.method<&GtkWindow_::remove_mnemonic>("remove_mnemonic");
            gtkwindow.method<&GtkWindow_::mnemonic_activate>("mnemonic_activate");
            gtkwindow.method<&GtkWindow_::set_focus>("set_focus");
            gtkwindow.method<&GtkWindow_::get_focus>("get_focus");
            gtkwindow.method<&GtkWindow_::close>("close");
            gtkwindow.method<&GtkWindow_::iconify>("iconify");
            gtkwindow.method<&GtkWindow_::deiconify>("deiconify");
            gtkwindow.method<&GtkWindow_::stick>("stick");
            gtkwindow.method<&GtkWindow_::unstick>("unstick");
            gtkwindow.method<&GtkWindow_::maximize>("maximize");
            gtkwindow.method<&GtkWindow_::unmaximize>("unmaximize");
            gtkwindow.method<&GtkWindow_::fullscreen>("fullscreen");
            gtkwindow.method<&GtkWindow_::unfullscreen>("unfullscreen");
            gtkwindow.method<&GtkWindow_::set_keep_above>("set_keep_above");
            gtkwindow.method<&GtkWindow_::set_keep_below>("set_keep_below");
            gtkwindow.method<&GtkWindow_::set_decorated>("set_decorated");
            gtkwindow.method<&GtkWindow_::get_decorated>("get_decorated");
            gtkwindow.method<&GtkWindow_::set_deletable>("set_deletable");
            gtkwindow.method<&GtkWindow_::get_deletable>("get_deletable");
            gtkwindow.method<&GtkWindow_::set_mnemonic_modifier>("set_mnemonic_modifier");
            gtkwindow.method<&GtkWindow_::set_type_hint>("set_type_hint");
            gtkwindow.method<&GtkWindow_::get_type_hint>("get_type_hint");
            gtkwindow.method<&GtkWindow_::set_skip_taskbar_hint>("set_skip_taskbar_hint");
            gtkwindow.method<&GtkWindow_::get_skip_taskbar_hint>("get_skip_taskbar_hint");
            gtkwindow.method<&GtkWindow_::set_urgency_hint>("set_urgency_hint");
            gtkwindow.method<&GtkWindow_::get_urgency_hint>("get_urgency_hint");
            gtkwindow.method<&GtkWindow_::set_accept_focus>("set_accept_focus");
            gtkwindow.method<&GtkWindow_::get_accept_focus>("get_accept_focus");
            gtkwindow.method<&GtkWindow_::set_focus_on_map>("set_focus_on_map");
            gtkwindow.method<&GtkWindow_::get_focus_on_map>("get_focus_on_map");
            gtkwindow.method<&GtkWindow_::set_icon>("set_icon");
            gtkwindow.method<&GtkWindow_::get_icon>("get_icon");
            gtkwindow.method<&GtkWindow_::set_icon_from_file>("set_icon_from_file");
            gtkwindow.method<&GtkWindow_::set_icon_name>("set_icon_name");
            gtkwindow.method<&GtkWindow_::get_icon_name>("get_icon_name");
            gtkwindow.method<&GtkWindow_::present>("present");
            gtkwindow.method<&GtkWindow_::present_with_time>("present_with_time");
            gtkwindow.method<&GtkWindow_::get_window_type>("get_window_type");
            gtkwindow.method<&GtkWindow_::move>("move");
            gtkwindow.method<&GtkWindow_::resize>("resize");
            gtkwindow.method<&GtkWindow_::set_default_icon>("set_default_icon");
            gtkwindow.method<&GtkWindow_::set_default_icon_from_file>("set_default_icon_from_file");
            gtkwindow.method<&GtkWindow_::set_default_icon_name>("set_default_icon_name");
            gtkwindow.method<&GtkWindow_::set_auto_startup_notification>("set_auto_startup_notification");
            gtkwindow.method<&GtkWindow_::set_mnemonics_visible>("set_mnemonics_visible");
            gtkwindow.method<&GtkWindow_::get_mnemonics_visible>("get_mnemonics_visible");
            gtkwindow.method<&GtkWindow_::set_focus_visible>("set_focus_visible");
            gtkwindow.method<&GtkWindow_::get_focus_visible>("get_focus_visible");
            gtkwindow.method<&GtkWindow_::set_titlebar>("set_titlebar");
            gtkwindow.method<&GtkWindow_::get_titlebar>("get_titlebar");
            gtkwindow.method<&GtkWindow_::set_interactive_debugging>("set_interactive_debugging");


        // GtkButton
        Php::Class<GtkButton_> gtkbutton("GtkButton");
            gtkbutton.extends(gtkbin);
            gtkbutton.method<&GtkButton_::__construct>("__construct");
            gtkbutton.method<&GtkButton_::new_with_label>("new_with_label");
            gtkbutton.method<&GtkButton_::new_with_mnemonic>("new_with_mnemonic");
            gtkbutton.method<&GtkButton_::set_label>("set_label");
            gtkbutton.method<&GtkButton_::get_label>("get_label");
            gtkbutton.method<&GtkButton_::clicked>("clicked");
            gtkbutton.method<&GtkButton_::set_use_underline>("set_use_underline");
            gtkbutton.method<&GtkButton_::get_use_underline>("get_use_underline");


        // GtkRequisition
        // Php::Class<GtkRequisition_> gtkrequisition("GtkRequisition");
        //     gtkrequisition.method<&GtkRequisition_::__construct>("__construct");
        //     gtkrequisition.property("width", 0);
        //     gtkrequisition.property("height", 0);
        

        // GtkEntryBuffer
        Php::Class<GtkEntryBuffer_> gtkentrybuffer("GtkEntryBuffer");
            gtkentrybuffer.extends(gobject);
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
            gtkentry.method<&GtkEntry_::get_visibility>("get_visibility");
            gtkentry.method<&GtkEntry_::set_invisible_char>("set_invisible_char");
            gtkentry.method<&GtkEntry_::get_invisible_char>("get_invisible_char");
            gtkentry.method<&GtkEntry_::unset_invisible_char>("unset_invisible_char");
            gtkentry.method<&GtkEntry_::set_max_length>("set_max_length");
            gtkentry.method<&GtkEntry_::get_max_length>("get_max_length");
            gtkentry.method<&GtkEntry_::set_activates_default>("set_activates_default");
            gtkentry.method<&GtkEntry_::get_activates_default>("get_activates_default");
            gtkentry.method<&GtkEntry_::set_has_frame>("set_has_frame");
            gtkentry.method<&GtkEntry_::get_has_frame>("get_has_frame");
            gtkentry.method<&GtkEntry_::set_width_chars>("set_width_chars");
            gtkentry.method<&GtkEntry_::get_width_chars>("get_width_chars");
            gtkentry.method<&GtkEntry_::set_max_width_chars>("set_max_width_chars");
            gtkentry.method<&GtkEntry_::get_max_width_chars>("get_max_width_chars");
            gtkentry.method<&GtkEntry_::set_alignment>("set_alignment");
            gtkentry.method<&GtkEntry_::get_alignment>("get_alignment");
            gtkentry.method<&GtkEntry_::set_placeholder_text>("set_placeholder_text");
            gtkentry.method<&GtkEntry_::get_placeholder_text>("get_placeholder_text");
            gtkentry.method<&GtkEntry_::set_overwrite_mode>("set_overwrite_mode");
            gtkentry.method<&GtkEntry_::get_overwrite_mode>("get_overwrite_mode");
            gtkentry.method<&GtkEntry_::set_progress_fraction>("set_progress_fraction");
            gtkentry.method<&GtkEntry_::get_progress_fraction>("get_progress_fraction");
            gtkentry.method<&GtkEntry_::set_progress_pulse_step>("set_progress_pulse_step");
            gtkentry.method<&GtkEntry_::get_progress_pulse_step>("get_progress_pulse_step");
            // gtkentry.method<&GtkEntry_::progress_pulse>("progress_pulse");


        // GtkTreeView
        Php::Class<GtkTreeView_> gtktreeview("GtkTreeView");
            gtktreeview.extends(gtkcontainer);
            gtktreeview.method<&GtkTreeView_::__construct>("__construct");
            gtktreeview.method<&GtkTreeView_::append_column>("append_column");
            gtktreeview.method<&GtkTreeView_::set_model>("set_model");


        // GtkTreeViewColumn
        Php::Class<GtkTreeViewColumn_> gtktreeviewcolumn("GtkTreeViewColumn");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::__construct>("__construct");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::set_title>("set_title");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_title>("get_title");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::pack_start>("pack_start");

        // GtkCellRenderer
        Php::Class<GtkCellRenderer_> gtkcellrenderer("GtkCellRenderer");
            gtkcellrenderer.extends(gobject);
            gtkcellrenderer.method<&GtkCellRenderer_::__construct>("__construct");


        // GtkCellRendererText
        Php::Class<GtkCellRendererText_> gtkcellrenderertext("GtkCellRendererText");
            gtkcellrenderertext.extends(gtkcellrenderer);
            gtkcellrenderertext.method<&GtkCellRendererText_::__construct>("__construct");

        // GtkCellRendererToggle
        Php::Class<GtkCellRendererToggle_> gtkcellrenderertoggle("GtkCellRendererToggle");
            gtkcellrenderertoggle.extends(gtkcellrenderer);
            gtkcellrenderertoggle.method<&GtkCellRendererToggle_::__construct>("__construct");


        Php::Class<GtkListStore_> gtkliststore("GtkListStore");
            gtkliststore.method<&GtkListStore_::__construct>("__construct");
            gtkliststore.method<&GtkListStore_::set_value>("set_value");
            gtkliststore.method<&GtkListStore_::append>("append");



        Php::Class<GtkTreeModelFlags_> gtktreemodelflags("GtkTreeModelFlags");
            gtktreemodelflags.constant("TREE_MODEL_ITERS_PERSIST", (int)GTK_TREE_MODEL_ITERS_PERSIST);
            gtktreemodelflags.constant("TREE_MODEL_LIST_ONLY", (int)GTK_TREE_MODEL_LIST_ONLY);


        Php::Class<GtkTreeIter_> gtktreeiter("GtkTreeIter");

        // Add
        extension.add(std::move(gobject));

        extension.add(std::move(gdk));
        extension.add(std::move(gdkevent));
        extension.add(std::move(gdkpixbuf));

        extension.add(std::move(gtk));
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

        extension.add(std::move(gtktreeview));
        extension.add(std::move(gtktreeviewcolumn));
        extension.add(std::move(gtkliststore));
        extension.add(std::move(gtktreemodelflags));
        extension.add(std::move(gtktreeiter));

        extension.add(std::move(gtkcellrenderer));
        extension.add(std::move(gtkcellrenderertext));
        extension.add(std::move(gtkcellrenderertoggle));


        // return the extension
        return extension;
    }
}