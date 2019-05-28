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
            gobject.method<&GObject_::connect>("connect");
            gobject.method<&GObject_::handler_disconnect>("handler_disconnect");
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
            gobject.constant("TYPE_PIXBUF", (int)GDK_TYPE_PIXBUF);
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
            // gdk.constant("TYPE_PIXBUF", GDK_TYPE_PIXBUF);


            gdk.constant("NOTHING",(int) GDK_NOTHING);
            gdk.constant("DELETE",(int) GDK_DELETE);
            gdk.constant("DESTROY",(int) GDK_DESTROY);
            gdk.constant("EXPOSE",(int) GDK_EXPOSE);
            gdk.constant("MOTION_NOTIFY",(int) GDK_MOTION_NOTIFY);
            gdk.constant("BUTTON_PRESS",(int) GDK_BUTTON_PRESS);
            gdk.constant("_2BUTTON_PRESS",(int) GDK_2BUTTON_PRESS);
            gdk.constant("DOUBLE_BUTTON_PRESS",(int) GDK_DOUBLE_BUTTON_PRESS);
            gdk.constant("_3BUTTON_PRESS",(int) GDK_3BUTTON_PRESS);
            gdk.constant("TRIPLE_BUTTON_PRESS",(int) GDK_TRIPLE_BUTTON_PRESS);
            gdk.constant("BUTTON_RELEASE",(int) GDK_BUTTON_RELEASE);
            gdk.constant("KEY_PRESS",(int) GDK_KEY_PRESS);
            gdk.constant("KEY_RELEASE",(int) GDK_KEY_RELEASE);
            gdk.constant("ENTER_NOTIFY",(int) GDK_ENTER_NOTIFY);
            gdk.constant("LEAVE_NOTIFY",(int) GDK_LEAVE_NOTIFY);
            gdk.constant("FOCUS_CHANGE",(int) GDK_FOCUS_CHANGE);
            gdk.constant("CONFIGURE",(int) GDK_CONFIGURE);
            gdk.constant("MAP",(int) GDK_MAP);
            gdk.constant("UNMAP",(int) GDK_UNMAP);
            gdk.constant("PROPERTY_NOTIFY",(int) GDK_PROPERTY_NOTIFY);
            gdk.constant("SELECTION_CLEAR",(int) GDK_SELECTION_CLEAR);
            gdk.constant("SELECTION_REQUEST",(int) GDK_SELECTION_REQUEST);
            gdk.constant("SELECTION_NOTIFY",(int) GDK_SELECTION_NOTIFY);
            gdk.constant("PROXIMITY_IN",(int) GDK_PROXIMITY_IN);
            gdk.constant("PROXIMITY_OUT",(int) GDK_PROXIMITY_OUT);
            gdk.constant("DRAG_ENTER",(int) GDK_DRAG_ENTER);
            gdk.constant("DRAG_LEAVE",(int) GDK_DRAG_LEAVE);
            gdk.constant("DRAG_MOTION",(int) GDK_DRAG_MOTION);
            gdk.constant("DRAG_STATUS",(int) GDK_DRAG_STATUS);
            gdk.constant("DROP_START",(int) GDK_DROP_START);
            gdk.constant("DROP_FINISHED",(int) GDK_DROP_FINISHED);
            gdk.constant("CLIENT_EVENT",(int) GDK_CLIENT_EVENT);
            gdk.constant("VISIBILITY_NOTIFY",(int) GDK_VISIBILITY_NOTIFY);
            gdk.constant("SCROLL",(int) GDK_SCROLL);
            gdk.constant("WINDOW_STATE",(int) GDK_WINDOW_STATE);
            gdk.constant("SETTING",(int) GDK_SETTING);
            gdk.constant("OWNER_CHANGE",(int) GDK_OWNER_CHANGE);
            gdk.constant("GRAB_BROKEN",(int) GDK_GRAB_BROKEN);
            gdk.constant("DAMAGE",(int) GDK_DAMAGE);
            gdk.constant("TOUCH_BEGIN",(int) GDK_TOUCH_BEGIN);
            gdk.constant("TOUCH_UPDATE",(int) GDK_TOUCH_UPDATE);
            gdk.constant("TOUCH_END",(int) GDK_TOUCH_END);
            gdk.constant("TOUCH_CANCEL",(int) GDK_TOUCH_CANCEL);
            gdk.constant("TOUCHPAD_SWIPE",(int) GDK_TOUCHPAD_SWIPE);
            gdk.constant("TOUCHPAD_PINCH",(int) GDK_TOUCHPAD_PINCH);
            gdk.constant("PAD_BUTTON_PRESS",(int) GDK_PAD_BUTTON_PRESS);
            gdk.constant("PAD_BUTTON_RELEASE",(int) GDK_PAD_BUTTON_RELEASE);
            gdk.constant("PAD_RING",(int) GDK_PAD_RING);
            gdk.constant("PAD_STRIP",(int) GDK_PAD_STRIP);
            gdk.constant("PAD_GROUP_MODE",(int) GDK_PAD_GROUP_MODE);
            gdk.constant("EVENT_LAST",(int) GDK_EVENT_LAST);
        

        // GdkEvent
        Php::Class<GdkEvent_> gdkevent("GdkEvent");
            // gdkevent.method<&GdkEvent_::__construct>("__construct");
            // gdkevent.property("type", 0);

        // GdkEventButton
        Php::Class<GdkEventButton_> gdkeventbutton("GdkEventButton");
            // gdkevent.method<&GdkEvent_::__construct>("__construct");
            // gdkevent.property("type", 0);
        

        // GdkPixbuf
        Php::Class<GdkPixbuf_> gdkpixbuf("GdkPixbuf");
            gdkpixbuf.method<&GdkPixbuf_::__construct>("__construct");
            gdkpixbuf.method<&GdkPixbuf_::new_from_file>("new_from_file");
            gdkpixbuf.method<&GdkPixbuf_::new_from_file_at_size>("new_from_file_at_size");
            gdkpixbuf.method<&GdkPixbuf_::new_from_file_at_scale>("new_from_file_at_scale");
            gdkpixbuf.method<&GdkPixbuf_::get_file_info>("get_file_info");
            gdkpixbuf.method<&GdkPixbuf_::get_colorspace>("get_colorspace");
            gdkpixbuf.method<&GdkPixbuf_::get_n_channels>("get_n_channels");
            gdkpixbuf.method<&GdkPixbuf_::get_has_alpha>("get_has_alpha");
            gdkpixbuf.method<&GdkPixbuf_::get_pixels>("get_pixels");
            gdkpixbuf.method<&GdkPixbuf_::get_width>("get_width");
            gdkpixbuf.method<&GdkPixbuf_::get_height>("get_height");
            gdkpixbuf.method<&GdkPixbuf_::get_rowstride>("get_rowstride");
            gdkpixbuf.method<&GdkPixbuf_::get_option>("get_option");
            gdkpixbuf.method<&GdkPixbuf_::save>("save");
        

        // GdkPixbufFormat
        Php::Class<GdkPixbufFormat_> gdkpixbufformat("GdkPixbufFormat");


        // GdkPixbufAlphaMode
        Php::Class<GdkPixbufAlphaMode_> gdkpixbufalphamode("GdkPixbufAlphaMode");
            gdkpixbufalphamode.constant("BILEVEL", (int)GDK_PIXBUF_ALPHA_BILEVEL);
            gdkpixbufalphamode.constant("FULL", (int)GDK_PIXBUF_ALPHA_FULL);


        // GdkColorspace
        Php::Class<GdkColorspace_> gdkcolorspace("GdkColorspace");
            gdkcolorspace.constant("RGB", (int)GDK_COLORSPACE_RGB);


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
            
            gtk.constant("WINDOW_TOPLEVEL", GTK_WINDOW_TOPLEVEL);
            gtk.constant("WINDOW_POPUP", GTK_WINDOW_POPUP);

            gtk.constant("WIN_POS_NONE", GTK_WIN_POS_NONE);
            gtk.constant("WIN_POS_CENTER", GTK_WIN_POS_CENTER);
            gtk.constant("WIN_POS_MOUSE", GTK_WIN_POS_MOUSE);
            gtk.constant("WIN_POS_CENTER_ALWAYS", GTK_WIN_POS_CENTER_ALWAYS);
            gtk.constant("WIN_POS_CENTER_ON_PARENT", GTK_WIN_POS_CENTER_ON_PARENT);
        
        
        // GtkOrientation
        Php::Class<GtkOrientation_> gtkorientation("GtkOrientation");
            gtkorientation.constant("HORIZONTAL", GTK_ORIENTATION_HORIZONTAL);
            gtkorientation.constant("VERTICAL", GTK_ORIENTATION_VERTICAL);
        

        // GtkPolicyType
        Php::Class<GtkPolicyType_> gtkpolicytype("GtkPolicyType");
            gtkpolicytype.constant("ALWAYS", GTK_POLICY_ALWAYS);
            gtkpolicytype.constant("AUTOMATIC", GTK_POLICY_AUTOMATIC);
            gtkpolicytype.constant("NEVER", GTK_POLICY_NEVER);
            gtkpolicytype.constant("EXTERNAL", GTK_POLICY_EXTERNAL);
        

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
            gtkwidget.method<&GtkWidget_::set_size_request>("set_size_request");
            gtkwidget.method<&GtkWidget_::get_size_request>("get_size_request");
        

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


        // GtkPaned
        Php::Class<GtkPaned_> gtkpaned("GtkPaned");
            gtkpaned.extends(gtkcontainer);
            gtkpaned.method<&GtkPaned_::__construct>("__construct");
            gtkpaned.method<&GtkPaned_::add1>("add1");
            gtkpaned.method<&GtkPaned_::add2>("add2");
            gtkpaned.method<&GtkPaned_::pack1>("pack1");
            gtkpaned.method<&GtkPaned_::pack2>("pack2");
            gtkpaned.method<&GtkPaned_::get_child1>("get_child1");
            gtkpaned.method<&GtkPaned_::get_child2>("get_child2");
            gtkpaned.method<&GtkPaned_::set_position>("set_position");
            gtkpaned.method<&GtkPaned_::get_position>("get_position");


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
            gtkwindow.method<&GtkWindow_::get_size>("get_size");
        

        // GtkDialog
        Php::Class<GtkDialog_> gtkdialog("GtkDialog");
            gtkdialog.extends(gtkwindow);
            gtkdialog.method<&GtkDialog_::__construct>("__construct");
            gtkdialog.method<&GtkDialog_::new_with_buttons>("new_with_buttons");
            gtkdialog.method<&GtkDialog_::run>("run");
            gtkdialog.method<&GtkDialog_::response>("response");
            gtkdialog.method<&GtkDialog_::add_button>("add_button");
            gtkdialog.method<&GtkDialog_::add_buttons>("add_buttons");
            gtkdialog.method<&GtkDialog_::add_action_widget>("add_action_widget");
            gtkdialog.method<&GtkDialog_::set_default_response>("set_default_response");
            gtkdialog.method<&GtkDialog_::set_response_sensitive>("set_response_sensitive");
            gtkdialog.method<&GtkDialog_::get_response_for_widget>("get_response_for_widget");
            gtkdialog.method<&GtkDialog_::get_widget_for_response>("get_widget_for_response");
            gtkdialog.method<&GtkDialog_::get_content_area>("get_content_area");
            gtkdialog.method<&GtkDialog_::get_header_bar>("get_header_bar");
        

        // GtkFileChooser
        // Php::Interface gtkfilechooser("GtkFileChooser");
            // gtkfilechooser.extends(gobject);
            // gtkfilechooser.method("get_filename");
        // extension.add(std::move(gtkfilechooser));

        // Php::Class<GtkFileChooser_> gtkfilechooser("GtkFileChooser");
        //     gtkfilechooser.extends(gobject);
        //     gtkfilechooser.method<&GtkFileChooser_::get_filename>("get_filename");


        // GtkButton
        Php::Class<GtkButton_> gtkbutton("GtkButton");
            gtkbutton.extends(gtkbin);
            gtkbutton.method<&GtkButton_::__construct>("__construct");
            gtkbutton.method<&GtkButton_::new_with_label>("new_with_label");
            gtkbutton.method<&GtkButton_::new_with_mnemonic>("new_with_mnemonic");
            gtkbutton.method<&GtkButton_::new_from_icon_name>("new_from_icon_name");
            gtkbutton.method<&GtkButton_::set_label>("set_label");
            gtkbutton.method<&GtkButton_::get_label>("get_label");
            gtkbutton.method<&GtkButton_::clicked>("clicked");
            gtkbutton.method<&GtkButton_::set_use_underline>("set_use_underline");
            gtkbutton.method<&GtkButton_::get_use_underline>("get_use_underline");
        

        // GtkToggleButton
        Php::Class<GtkToggleButton_> gtktogglebutton("GtkToggleButton");
            gtktogglebutton.extends(gtkbutton);
            gtktogglebutton.method<&GtkToggleButton_::__construct>("__construct");
            gtktogglebutton.method<&GtkToggleButton_::new_with_label>("new_with_label");
            gtktogglebutton.method<&GtkToggleButton_::new_with_mnemonic>("new_with_mnemonic");
            gtktogglebutton.method<&GtkToggleButton_::set_mode>("set_mode");
            gtktogglebutton.method<&GtkToggleButton_::get_mode>("get_mode");
            gtktogglebutton.method<&GtkToggleButton_::toggled>("toggled");
            gtktogglebutton.method<&GtkToggleButton_::get_active>("get_active");
            gtktogglebutton.method<&GtkToggleButton_::set_active>("set_active");
            gtktogglebutton.method<&GtkToggleButton_::get_inconsistent>("get_inconsistent");
            gtktogglebutton.method<&GtkToggleButton_::set_inconsistent>("set_inconsistent");


        // GtkCheckButton
        Php::Class<GtkCheckButton_> gtkcheckbutton("GtkCheckButton");
            gtkcheckbutton.extends(gtktogglebutton);
            gtkcheckbutton.method<&GtkCheckButton_::__construct>("__construct");
            gtkcheckbutton.method<&GtkCheckButton_::new_with_label>("new_with_label");
            gtkcheckbutton.method<&GtkCheckButton_::new_with_mnemonic>("new_with_mnemonic");


        // GtkAdjustment
        Php::Class<GtkAdjustment_> gtkadjustment("GtkAdjustment");
            gtkadjustment.extends(gobject);
            gtkadjustment.method<&GtkAdjustment_::__construct>("__construct");
        

        // GtkScrolledWindow
        Php::Class<GtkScrolledWindow_> gtkscrolledwindow("GtkScrolledWindow");
            gtkscrolledwindow.extends(gtkcontainer);
            gtkscrolledwindow.method<&GtkScrolledWindow_::__construct>("__construct");
            gtkscrolledwindow.method<&GtkScrolledWindow_::set_policy>("set_policy");
        
            

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
        

        // GtkSortType
        Php::Class<GtkSortType_> gtksorttype("GtkSortType");
            gtksorttype.constant("ASCENDING", (int)GTK_SORT_ASCENDING);
            gtksorttype.constant("DESCENDING", (int)GTK_SORT_DESCENDING);
        

        // GtkTreeView
        Php::Class<GtkTreeView_> gtktreeview("GtkTreeView");
            gtktreeview.extends(gtkcontainer);
            gtktreeview.method<&GtkTreeView_::__construct>("__construct");
            gtktreeview.method<&GtkTreeView_::append_column>("append_column");
            gtktreeview.method<&GtkTreeView_::set_model>("set_model");
            gtktreeview.method<&GtkTreeView_::get_selection>("get_selection");
            gtktreeview.method<&GtkTreeView_::get_model>("get_model");
            gtktreeview.method<&GtkTreeView_::expand_row>("expand_row");
            gtktreeview.method<&GtkTreeView_::set_level_indentation>("set_level_indentation");
            gtktreeview.method<&GtkTreeView_::set_show_expanders>("set_show_expanders");
            gtktreeview.method<&GtkTreeView_::set_enable_tree_lines>("set_enable_tree_lines");
            gtktreeview.method<&GtkTreeView_::row_expanded>("row_expanded");
            gtktreeview.method<&GtkTreeView_::collapse_row>("collapse_row");
        

        // GtkTreeViewColumn
        Php::Class<GtkTreeViewColumn_> gtktreeviewcolumn("GtkTreeViewColumn");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::__construct>("__construct");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::set_title>("set_title");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_title>("get_title");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::pack_start>("pack_start");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::set_resizable>("set_resizable");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_resizable>("get_resizable");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_width>("get_width");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_fixed_width>("get_fixed_width");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::set_fixed_width>("set_fixed_width");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_button>("get_button");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::set_alignment>("set_alignment");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_alignment>("get_alignment");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::set_reorderable>("set_reorderable");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_reorderable>("get_reorderable");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::set_widget>("set_widget");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_widget>("get_widget");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::set_sort_column_id>("set_sort_column_id");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_sort_column_id>("get_sort_column_id");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::set_sort_indicator>("set_sort_indicator");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_sort_indicator>("get_sort_indicator");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::set_sort_order>("set_sort_order");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_sort_order>("get_sort_order");
            gtktreeviewcolumn.method<&GtkTreeViewColumn_::get_tree_view>("get_tree_view");
        

        // GtkCellRenderer
        Php::Class<GtkCellRenderer_> gtkcellrenderer("GtkCellRenderer");
            gtkcellrenderer.extends(gobject);
            gtkcellrenderer.method<&GtkCellRenderer_::__construct>("__construct");
            gtkcellrenderer.method<&GtkCellRenderer_::set_alignment>("set_alignment");
            gtkcellrenderer.method<&GtkCellRenderer_::get_alignment>("get_alignment");
        


        // GtkCellRendererText
        Php::Class<GtkCellRendererText_> gtkcellrenderertext("GtkCellRendererText");
            gtkcellrenderertext.extends(gtkcellrenderer);
            gtkcellrenderertext.method<&GtkCellRendererText_::__construct>("__construct");
            gtkcellrenderertext.method<&GtkCellRendererText_::set_fixed_height_from_font>("set_fixed_height_from_font");
        


        // GtkCellRendererToggle
        Php::Class<GtkCellRendererToggle_> gtkcellrenderertoggle("GtkCellRendererToggle");
            gtkcellrenderertoggle.extends(gtkcellrenderer);
            gtkcellrenderertoggle.method<&GtkCellRendererToggle_::__construct>("__construct");
            gtkcellrenderertoggle.method<&GtkCellRendererToggle_::set_activatable>("set_activatable");
            gtkcellrenderertoggle.method<&GtkCellRendererToggle_::get_activatable>("get_activatable");
            gtkcellrenderertoggle.method<&GtkCellRendererToggle_::set_radio>("set_radio");
            gtkcellrenderertoggle.method<&GtkCellRendererToggle_::get_radio>("get_radio");
            gtkcellrenderertoggle.method<&GtkCellRendererToggle_::set_active>("set_active");
            gtkcellrenderertoggle.method<&GtkCellRendererToggle_::get_active>("get_active");


        // GtkCellRendererPixbuf
        Php::Class<GtkCellRendererPixbuf_> gtkcellrendererpixbuf("GtkCellRendererPixbuf");
            gtkcellrendererpixbuf.extends(gtkcellrenderer);
            gtkcellrendererpixbuf.method<&GtkCellRendererPixbuf_::__construct>("__construct");
        

        // GtkTreeModel
        Php::Class<GtkTreeModel_> gtktreemodel("GtkTreeModel");
            gtktreemodel.method<&GtkTreeModel_::__construct>("__construct");
            gtktreemodel.method<&GtkTreeModel_::get_iter>("get_iter");
            gtktreemodel.method<&GtkTreeModel_::get_value>("get_value");
            gtktreemodel.method<&GtkTreeModel_::get_path>("get_path");

        // GtkListStore
        Php::Class<GtkListStore_> gtkliststore("GtkListStore");
            gtkliststore.extends(gtktreemodel);
            gtkliststore.method<&GtkListStore_::__construct>("__construct");
            gtkliststore.method<&GtkListStore_::set_value>("set_value");
            gtkliststore.method<&GtkListStore_::append>("append");
        

        // GtkTreeModelFlags
        Php::Class<GtkTreeModelFlags_> gtktreemodelflags("GtkTreeModelFlags");
            gtktreemodelflags.constant("TREE_MODEL_ITERS_PERSIST", (int)GTK_TREE_MODEL_ITERS_PERSIST);
            gtktreemodelflags.constant("TREE_MODEL_LIST_ONLY", (int)GTK_TREE_MODEL_LIST_ONLY);
        

        // GtkTreeIter
        Php::Class<GtkTreeIter_> gtktreeiter("GtkTreeIter");
        

        // GtkLabel
        Php::Class<GtkLabel_> gtklabel("GtkLabel");
            gtklabel.extends(gtkwidget);
            gtklabel.method<&GtkLabel_::__construct>("__construct");
            gtklabel.method<&GtkLabel_::set_text>("set_text");
            gtklabel.method<&GtkLabel_::set_markup>("set_markup");
            gtklabel.method<&GtkLabel_::set_markup_with_mnemonic>("set_markup_with_mnemonic");
            gtklabel.method<&GtkLabel_::set_pattern>("set_pattern");
            gtklabel.method<&GtkLabel_::set_justify>("set_justify");
            gtklabel.method<&GtkLabel_::set_xalign>("set_xalign");
            gtklabel.method<&GtkLabel_::set_yalign>("set_yalign");
            gtklabel.method<&GtkLabel_::set_width_chars>("set_width_chars");
            gtklabel.method<&GtkLabel_::set_max_width_chars>("set_max_width_chars");
            gtklabel.method<&GtkLabel_::set_line_wrap>("set_line_wrap");
            gtklabel.method<&GtkLabel_::set_lines>("set_lines");
            gtklabel.method<&GtkLabel_::get_mnemonic_keyval>("get_mnemonic_keyval");
            gtklabel.method<&GtkLabel_::get_selectable>("get_selectable");
            gtklabel.method<&GtkLabel_::get_text>("get_text");
            gtklabel.method<&GtkLabel_::set_mnemonic_widget>("set_mnemonic_widget");
            gtklabel.method<&GtkLabel_::set_selectable>("set_selectable");
            gtklabel.method<&GtkLabel_::set_text_with_mnemonic>("set_text_with_mnemonic");
            gtklabel.method<&GtkLabel_::get_justify>("get_justify");
            gtklabel.method<&GtkLabel_::get_xalign>("get_xalign");
            gtklabel.method<&GtkLabel_::get_yalign>("get_yalign");
            gtklabel.method<&GtkLabel_::get_width_chars>("get_width_chars");
            gtklabel.method<&GtkLabel_::get_max_width_chars>("get_max_width_chars");
            gtklabel.method<&GtkLabel_::get_label>("get_label");
            gtklabel.method<&GtkLabel_::get_line_wrap>("get_line_wrap");
            gtklabel.method<&GtkLabel_::get_lines>("get_lines");
            gtklabel.method<&GtkLabel_::get_mnemonic_widget>("get_mnemonic_widget");
            gtklabel.method<&GtkLabel_::get_use_markup>("get_use_markup");
            gtklabel.method<&GtkLabel_::get_use_underline>("get_use_underline");
            gtklabel.method<&GtkLabel_::get_single_line_mode>("get_single_line_mode");
            gtklabel.method<&GtkLabel_::get_angle>("get_angle");
            gtklabel.method<&GtkLabel_::set_label>("set_label");
            gtklabel.method<&GtkLabel_::set_use_markup>("set_use_markup");
            gtklabel.method<&GtkLabel_::set_use_underline>("set_use_underline");
            gtklabel.method<&GtkLabel_::set_single_line_mode>("set_single_line_mode");
            gtklabel.method<&GtkLabel_::set_angle>("set_angle");
            gtklabel.method<&GtkLabel_::get_current_uri>("get_current_uri");
            gtklabel.method<&GtkLabel_::set_track_visited_links>("set_track_visited_links");
            gtklabel.method<&GtkLabel_::get_track_visited_links>("get_track_visited_links");
        
        
        // GtkNotebook
        Php::Class<GtkNotebook_> gtknotebook("GtkNotebook");
            gtknotebook.extends(gtkcontainer);
            gtknotebook.method<&GtkNotebook_::__construct>("__construct");
            gtknotebook.method<&GtkNotebook_::append_page>("append_page");
            gtknotebook.method<&GtkNotebook_::insert_page>("insert_page");
            gtknotebook.method<&GtkNotebook_::remove_page>("remove_page");
            gtknotebook.method<&GtkNotebook_::detach_tab>("detach_tab");
            gtknotebook.method<&GtkNotebook_::page_num>("page_num");
            gtknotebook.method<&GtkNotebook_::next_page>("next_page");
            gtknotebook.method<&GtkNotebook_::prev_page>("prev_page");
            gtknotebook.method<&GtkNotebook_::reorder_child>("reorder_child");
            gtknotebook.method<&GtkNotebook_::set_tab_pos>("set_tab_pos");
            gtknotebook.method<&GtkNotebook_::get_menu_label>("get_menu_label");
            gtknotebook.method<&GtkNotebook_::set_show_tabs>("set_show_tabs");
            gtknotebook.method<&GtkNotebook_::set_show_border>("set_show_border");
            gtknotebook.method<&GtkNotebook_::set_scrollable>("set_scrollable");
            gtknotebook.method<&GtkNotebook_::popup_enable>("popup_enable");
            gtknotebook.method<&GtkNotebook_::popup_disable>("popup_disable");
            gtknotebook.method<&GtkNotebook_::get_current_page>("get_current_page");
            gtknotebook.method<&GtkNotebook_::get_nth_page>("get_nth_page");
            gtknotebook.method<&GtkNotebook_::get_n_pages>("get_n_pages");
            gtknotebook.method<&GtkNotebook_::get_tab_label>("get_tab_label");
            gtknotebook.method<&GtkNotebook_::set_menu_label>("set_menu_label");
            gtknotebook.method<&GtkNotebook_::set_menu_label_text>("set_menu_label_text");
            gtknotebook.method<&GtkNotebook_::set_tab_label>("set_tab_label");
            gtknotebook.method<&GtkNotebook_::set_tab_label_text>("set_tab_label_text");
            gtknotebook.method<&GtkNotebook_::set_tab_reorderable>("set_tab_reorderable");
            gtknotebook.method<&GtkNotebook_::set_tab_detachable>("set_tab_detachable");
            gtknotebook.method<&GtkNotebook_::get_menu_label_text>("get_menu_label_text");
            gtknotebook.method<&GtkNotebook_::get_scrollable>("get_scrollable");
            gtknotebook.method<&GtkNotebook_::get_show_border>("get_show_border");
            gtknotebook.method<&GtkNotebook_::get_show_tabs>("get_show_tabs");
            gtknotebook.method<&GtkNotebook_::get_tab_label_text>("get_tab_label_text");
        

        // GtkPositionType
        Php::Class<GtkPositionType_> gtkpositiontype("GtkPositionType");
            gtkpositiontype.constant("LEFT", (int)GTK_POS_LEFT);
            gtkpositiontype.constant("RIGHT", (int)GTK_POS_RIGHT);
            gtkpositiontype.constant("TOP", (int)GTK_POS_TOP);
            gtkpositiontype.constant("BOTTOM", (int)GTK_POS_BOTTOM);
        

        // GtkPackType
        Php::Class<GtkPackType_> gtkpacktype("GtkPackType");
            gtkpacktype.constant("STARTY", (int)GTK_PACK_START);
            gtkpacktype.constant("END", (int)GTK_PACK_END);
        


        // GtkJustification
        Php::Class<GtkJustification_> gtkjustification("GtkJustification");
            gtkjustification.constant("LEFT", (int)GTK_JUSTIFY_LEFT);
            gtkjustification.constant("RIGHT", (int)GTK_JUSTIFY_RIGHT);
            gtkjustification.constant("CENTER", (int)GTK_JUSTIFY_CENTER);
            gtkjustification.constant("FILL", (int)GTK_JUSTIFY_FILL);
        
        

        // GtkFileChooserAction
        Php::Class<GtkFileChooserAction_> gtkfilechooseraction("GtkFileChooserAction");
            gtkfilechooseraction.constant("OPEN", (int)GTK_FILE_CHOOSER_ACTION_OPEN);
            gtkfilechooseraction.constant("SAVE", (int)GTK_FILE_CHOOSER_ACTION_SAVE);
            gtkfilechooseraction.constant("SELECT_FOLDER", (int)GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
            gtkfilechooseraction.constant("CREATE_FOLDER", (int)GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER);
        

        // GtkTextView
                // GtkTextView
        Php::Class<GtkTextView_> gtktextview("GtkTextView");
            gtktextview.extends(gtkcontainer);
            gtktextview.method<&GtkTextView_::__construct>("__construct");
            gtktextview.method<&GtkTextView_::new_with_buffer>("new_with_buffer");
            gtktextview.method<&GtkTextView_::set_buffer>("set_buffer");
            gtktextview.method<&GtkTextView_::get_buffer>("get_buffer");
            gtktextview.method<&GtkTextView_::scroll_to_mark>("scroll_to_mark");
            gtktextview.method<&GtkTextView_::scroll_to_iter>("scroll_to_iter");
            gtktextview.method<&GtkTextView_::scroll_mark_onscreen>("scroll_mark_onscreen");
            gtktextview.method<&GtkTextView_::move_mark_onscreen>("move_mark_onscreen");
            gtktextview.method<&GtkTextView_::place_cursor_onscreen>("place_cursor_onscreen");
            gtktextview.method<&GtkTextView_::get_line_at_y>("get_line_at_y");
            gtktextview.method<&GtkTextView_::get_line_yrange>("get_line_yrange");
            gtktextview.method<&GtkTextView_::get_iter_at_location>("get_iter_at_location");
            gtktextview.method<&GtkTextView_::get_iter_at_position>("get_iter_at_position");
            gtktextview.method<&GtkTextView_::buffer_to_window_coords>("buffer_to_window_coords");
            gtktextview.method<&GtkTextView_::window_to_buffer_coords>("window_to_buffer_coords");
            gtktextview.method<&GtkTextView_::get_window>("get_window");
            gtktextview.method<&GtkTextView_::get_window_type>("get_window_type");
            gtktextview.method<&GtkTextView_::set_border_window_size>("set_border_window_size");
            gtktextview.method<&GtkTextView_::get_border_window_size>("get_border_window_size");
            gtktextview.method<&GtkTextView_::forward_display_line>("forward_display_line");
            gtktextview.method<&GtkTextView_::backward_display_line>("backward_display_line");
            gtktextview.method<&GtkTextView_::forward_display_line_end>("forward_display_line_end");
            gtktextview.method<&GtkTextView_::backward_display_line_start>("backward_display_line_start");
            gtktextview.method<&GtkTextView_::starts_display_line>("starts_display_line");
            gtktextview.method<&GtkTextView_::move_visually>("move_visually");
            gtktextview.method<&GtkTextView_::add_child_in_window>("add_child_in_window");
            gtktextview.method<&GtkTextView_::move_child>("move_child");
            gtktextview.method<&GtkTextView_::set_wrap_mode>("set_wrap_mode");
            gtktextview.method<&GtkTextView_::get_wrap_mode>("get_wrap_mode");
            gtktextview.method<&GtkTextView_::set_editable>("set_editable");
            gtktextview.method<&GtkTextView_::get_editable>("get_editable");
            gtktextview.method<&GtkTextView_::set_cursor_visible>("set_cursor_visible");
            gtktextview.method<&GtkTextView_::get_cursor_visible>("get_cursor_visible");
            gtktextview.method<&GtkTextView_::overwrite>("overwrite");
            gtktextview.method<&GtkTextView_::get_overwrite>("get_overwrite");
            gtktextview.method<&GtkTextView_::set_pixels_above_lines>("set_pixels_above_lines");
            gtktextview.method<&GtkTextView_::get_pixels_above_lines>("get_pixels_above_lines");
            gtktextview.method<&GtkTextView_::set_pixels_below_lines>("set_pixels_below_lines");
            gtktextview.method<&GtkTextView_::get_pixels_below_lines>("get_pixels_below_lines");
            gtktextview.method<&GtkTextView_::set_pixels_inside_wrap>("set_pixels_inside_wrap");
            gtktextview.method<&GtkTextView_::get_pixels_inside_wrap>("get_pixels_inside_wrap");
            gtktextview.method<&GtkTextView_::set_justification>("set_justification");
            gtktextview.method<&GtkTextView_::get_justification>("get_justification");
            gtktextview.method<&GtkTextView_::set_left_margin>("set_left_margin");
            gtktextview.method<&GtkTextView_::get_left_margin>("get_left_margin");
            gtktextview.method<&GtkTextView_::set_right_margin>("set_right_margin");
            gtktextview.method<&GtkTextView_::get_right_margin>("get_right_margin");
            gtktextview.method<&GtkTextView_::set_top_margin>("set_top_margin");
            gtktextview.method<&GtkTextView_::get_top_margin>("get_top_margin");
            gtktextview.method<&GtkTextView_::set_bottom_margin>("set_bottom_margin");
            gtktextview.method<&GtkTextView_::get_bottom_margin>("get_bottom_margin");
            gtktextview.method<&GtkTextView_::set_indent>("set_indent");
            gtktextview.method<&GtkTextView_::get_indent>("get_indent");
            gtktextview.method<&GtkTextView_::set_accepts_tab>("set_accepts_tab");
            gtktextview.method<&GtkTextView_::get_accepts_tab>("get_accepts_tab");
            gtktextview.method<&GtkTextView_::im_context_filter_keypress>("im_context_filter_keypress");
            gtktextview.method<&GtkTextView_::reset_im_context>("reset_im_context");
            gtktextview.method<&GtkTextView_::set_input_purpose>("set_input_purpose");
            gtktextview.method<&GtkTextView_::get_input_purpose>("get_input_purpose");
            gtktextview.method<&GtkTextView_::set_input_hints>("set_input_hints");
            gtktextview.method<&GtkTextView_::get_input_hints>("get_input_hints");
            gtktextview.method<&GtkTextView_::set_monospace>("set_monospace");
            gtktextview.method<&GtkTextView_::get_monospace>("get_monospace");


        // GtkTextIter
        Php::Class<GtkTextIter_> gtktextiter("GtkTextIter");
            gtktextiter.method<&GtkTextIter_::get_buffer>("get_buffer");
            gtktextiter.method<&GtkTextIter_::copy>("copy");
            gtktextiter.method<&GtkTextIter_::assign>("assign");
            gtktextiter.method<&GtkTextIter_::free>("free");
            gtktextiter.method<&GtkTextIter_::get_offset>("get_offset");
            gtktextiter.method<&GtkTextIter_::get_line>("get_line");
            gtktextiter.method<&GtkTextIter_::get_line_offset>("get_line_offset");
            gtktextiter.method<&GtkTextIter_::get_line_index>("get_line_index");
            gtktextiter.method<&GtkTextIter_::get_visible_line_offset>("get_visible_line_offset");
            gtktextiter.method<&GtkTextIter_::get_char>("get_char");
            gtktextiter.method<&GtkTextIter_::get_slice>("get_slice");
            gtktextiter.method<&GtkTextIter_::get_text>("get_text");
            gtktextiter.method<&GtkTextIter_::get_visible_slice>("get_visible_slice");
            gtktextiter.method<&GtkTextIter_::get_visible_text>("get_visible_text");
            gtktextiter.method<&GtkTextIter_::get_marks>("get_marks");
            gtktextiter.method<&GtkTextIter_::get_toggled_tags>("get_toggled_tags");
            gtktextiter.method<&GtkTextIter_::starts_tag>("starts_tag");
            gtktextiter.method<&GtkTextIter_::ends_tag>("ends_tag");
            gtktextiter.method<&GtkTextIter_::toggles_tag>("toggles_tag");
            gtktextiter.method<&GtkTextIter_::has_tag>("has_tag");
            gtktextiter.method<&GtkTextIter_::get_tags>("get_tags");
            gtktextiter.method<&GtkTextIter_::editable>("editable");
            gtktextiter.method<&GtkTextIter_::can_insert>("can_insert");
            gtktextiter.method<&GtkTextIter_::starts_word>("starts_word");
            gtktextiter.method<&GtkTextIter_::ends_word>("ends_word");
            gtktextiter.method<&GtkTextIter_::inside_word>("inside_word");
            gtktextiter.method<&GtkTextIter_::starts_line>("starts_line");
            gtktextiter.method<&GtkTextIter_::ends_line>("ends_line");
            gtktextiter.method<&GtkTextIter_::starts_sentence>("starts_sentence");
            gtktextiter.method<&GtkTextIter_::ends_sentence>("ends_sentence");
            gtktextiter.method<&GtkTextIter_::inside_sentence>("inside_sentence");
            gtktextiter.method<&GtkTextIter_::is_cursor_position>("is_cursor_position");
            gtktextiter.method<&GtkTextIter_::get_chars_in_line>("get_chars_in_line");
            gtktextiter.method<&GtkTextIter_::get_bytes_in_line>("get_bytes_in_line");
            gtktextiter.method<&GtkTextIter_::is_end>("is_end");
            gtktextiter.method<&GtkTextIter_::is_start>("is_start");
            gtktextiter.method<&GtkTextIter_::forward_char>("forward_char");
            gtktextiter.method<&GtkTextIter_::backward_char>("backward_char");
            gtktextiter.method<&GtkTextIter_::forward_chars>("forward_chars");
            gtktextiter.method<&GtkTextIter_::backward_chars>("backward_chars");
            gtktextiter.method<&GtkTextIter_::forward_line>("forward_line");
            gtktextiter.method<&GtkTextIter_::backward_line>("backward_line");
            gtktextiter.method<&GtkTextIter_::forward_lines>("forward_lines");
            gtktextiter.method<&GtkTextIter_::backward_lines>("backward_lines");
            gtktextiter.method<&GtkTextIter_::forward_word_ends>("forward_word_ends");
            gtktextiter.method<&GtkTextIter_::backward_word_starts>("backward_word_starts");
            gtktextiter.method<&GtkTextIter_::forward_word_end>("forward_word_end");
            gtktextiter.method<&GtkTextIter_::backward_word_start>("backward_word_start");
            gtktextiter.method<&GtkTextIter_::forward_cursor_position>("forward_cursor_position");
            gtktextiter.method<&GtkTextIter_::backward_cursor_position>("backward_cursor_position");
            gtktextiter.method<&GtkTextIter_::forward_cursor_positions>("forward_cursor_positions");
            gtktextiter.method<&GtkTextIter_::backward_cursor_positions>("backward_cursor_positions");
            gtktextiter.method<&GtkTextIter_::backward_sentence_start>("backward_sentence_start");
            gtktextiter.method<&GtkTextIter_::backward_sentence_starts>("backward_sentence_starts");
            gtktextiter.method<&GtkTextIter_::forward_sentence_end>("forward_sentence_end");
            gtktextiter.method<&GtkTextIter_::forward_sentence_ends>("forward_sentence_ends");
            gtktextiter.method<&GtkTextIter_::forward_visible_word_ends>("forward_visible_word_ends");
            gtktextiter.method<&GtkTextIter_::backward_visible_word_starts>("backward_visible_word_starts");
            gtktextiter.method<&GtkTextIter_::forward_visible_word_end>("forward_visible_word_end");
            gtktextiter.method<&GtkTextIter_::backward_visible_word_start>("backward_visible_word_start");
            gtktextiter.method<&GtkTextIter_::forward_visible_cursor_position>("forward_visible_cursor_position");
            gtktextiter.method<&GtkTextIter_::backward_visible_cursor_position>("backward_visible_cursor_position");
            gtktextiter.method<&GtkTextIter_::forward_visible_cursor_positions>("forward_visible_cursor_positions");
            gtktextiter.method<&GtkTextIter_::backward_visible_cursor_positions>("backward_visible_cursor_positions");
            gtktextiter.method<&GtkTextIter_::forward_visible_line>("forward_visible_line");
            gtktextiter.method<&GtkTextIter_::backward_visible_line>("backward_visible_line");
            gtktextiter.method<&GtkTextIter_::forward_visible_lines>("forward_visible_lines");
            gtktextiter.method<&GtkTextIter_::backward_visible_lines>("backward_visible_lines");
            gtktextiter.method<&GtkTextIter_::set_offset>("set_offset");
            gtktextiter.method<&GtkTextIter_::set_line>("set_line");
            gtktextiter.method<&GtkTextIter_::set_line_offset>("set_line_offset");
            gtktextiter.method<&GtkTextIter_::set_line_index>("set_line_index");
            gtktextiter.method<&GtkTextIter_::set_visible_line_index>("set_visible_line_index");
            gtktextiter.method<&GtkTextIter_::set_visible_line_offset>("set_visible_line_offset");
            gtktextiter.method<&GtkTextIter_::forward_to_end>("forward_to_end");
            gtktextiter.method<&GtkTextIter_::forward_to_line_end>("forward_to_line_end");
            gtktextiter.method<&GtkTextIter_::forward_to_tag_toggle>("forward_to_tag_toggle");
            gtktextiter.method<&GtkTextIter_::backward_to_tag_toggle>("backward_to_tag_toggle");
            gtktextiter.method<&GtkTextIter_::iter_equal>("iter_equal");
            gtktextiter.method<&GtkTextIter_::iter_compare>("iter_compare");
            gtktextiter.method<&GtkTextIter_::in_range>("in_range");
            gtktextiter.method<&GtkTextIter_::order>("order");
        

        // GtkTextBuffer
        Php::Class<GtkTextBuffer_> gtktextbuffer("GtkTextBuffer");
            gtktextbuffer.extends(gobject);
            gtktextbuffer.method<&GtkTextBuffer_::__construct>("__construct");
            gtktextbuffer.method<&GtkTextBuffer_::get_line_count>("get_line_count");
            gtktextbuffer.method<&GtkTextBuffer_::get_char_count>("get_char_count");
            gtktextbuffer.method<&GtkTextBuffer_::get_tag_table>("get_tag_table");
            gtktextbuffer.method<&GtkTextBuffer_::insert>("insert");
            gtktextbuffer.method<&GtkTextBuffer_::insert_at_cursor>("insert_at_cursor");
            gtktextbuffer.method<&GtkTextBuffer_::insert_interactive>("insert_interactive");
            gtktextbuffer.method<&GtkTextBuffer_::insert_interactive_at_cursor>("insert_interactive_at_cursor");
            gtktextbuffer.method<&GtkTextBuffer_::insert_range>("insert_range");
            gtktextbuffer.method<&GtkTextBuffer_::insert_range_interactive>("insert_range_interactive");
            gtktextbuffer.method<&GtkTextBuffer_::insert_with_tags>("insert_with_tags");
            gtktextbuffer.method<&GtkTextBuffer_::insert_with_tags_by_name>("insert_with_tags_by_name");
            gtktextbuffer.method<&GtkTextBuffer_::insert_markup>("insert_markup");
            gtktextbuffer.method<&GtkTextBuffer_::delete_>("delete");
            gtktextbuffer.method<&GtkTextBuffer_::delete_interactive>("delete_interactive");
            gtktextbuffer.method<&GtkTextBuffer_::backspace>("backspace");
            gtktextbuffer.method<&GtkTextBuffer_::set_text>("set_text");
            gtktextbuffer.method<&GtkTextBuffer_::get_text>("get_text");
            gtktextbuffer.method<&GtkTextBuffer_::get_slice>("get_slice");
            gtktextbuffer.method<&GtkTextBuffer_::insert_pixbuf>("insert_pixbuf");
            gtktextbuffer.method<&GtkTextBuffer_::create_mark>("create_mark");
            gtktextbuffer.method<&GtkTextBuffer_::move_mark>("move_mark");
            gtktextbuffer.method<&GtkTextBuffer_::move_mark_by_name>("move_mark_by_name");
            gtktextbuffer.method<&GtkTextBuffer_::add_mark>("add_mark");
            gtktextbuffer.method<&GtkTextBuffer_::delete_mark>("delete_mark");
            gtktextbuffer.method<&GtkTextBuffer_::delete_mark_by_name>("delete_mark_by_name");
            gtktextbuffer.method<&GtkTextBuffer_::get_mark>("get_mark");
            gtktextbuffer.method<&GtkTextBuffer_::get_insert>("get_insert");
            gtktextbuffer.method<&GtkTextBuffer_::get_selection_bound>("get_selection_bound");
            gtktextbuffer.method<&GtkTextBuffer_::get_has_selection>("get_has_selection");
            gtktextbuffer.method<&GtkTextBuffer_::place_cursor>("place_cursor");
            gtktextbuffer.method<&GtkTextBuffer_::select_range>("select_range");
            gtktextbuffer.method<&GtkTextBuffer_::apply_tag>("apply_tag");
            gtktextbuffer.method<&GtkTextBuffer_::remove_tag>("remove_tag");
            gtktextbuffer.method<&GtkTextBuffer_::apply_tag_by_name>("apply_tag_by_name");
            gtktextbuffer.method<&GtkTextBuffer_::remove_tag_by_name>("remove_tag_by_name");
            gtktextbuffer.method<&GtkTextBuffer_::remove_all_tags>("remove_all_tags");
            gtktextbuffer.method<&GtkTextBuffer_::create_tag>("create_tag");
            gtktextbuffer.method<&GtkTextBuffer_::get_iter_at_line_offset>("get_iter_at_line_offset");
            gtktextbuffer.method<&GtkTextBuffer_::get_iter_at_offset>("get_iter_at_offset");
            gtktextbuffer.method<&GtkTextBuffer_::get_iter_at_line>("get_iter_at_line");
            gtktextbuffer.method<&GtkTextBuffer_::get_iter_at_line_index>("get_iter_at_line_index");
            gtktextbuffer.method<&GtkTextBuffer_::get_iter_at_mark>("get_iter_at_mark");
            gtktextbuffer.method<&GtkTextBuffer_::get_start_iter>("get_start_iter");
            gtktextbuffer.method<&GtkTextBuffer_::get_end_iter>("get_end_iter");
            gtktextbuffer.method<&GtkTextBuffer_::get_bounds>("get_bounds");
            gtktextbuffer.method<&GtkTextBuffer_::get_modified>("get_modified");
            gtktextbuffer.method<&GtkTextBuffer_::set_modified>("set_modified");
            gtktextbuffer.method<&GtkTextBuffer_::delete_selection>("delete_selection");
            gtktextbuffer.method<&GtkTextBuffer_::paste_clipboard>("paste_clipboard");
            gtktextbuffer.method<&GtkTextBuffer_::copy_clipboard>("copy_clipboard");
            gtktextbuffer.method<&GtkTextBuffer_::cut_clipboard>("cut_clipboard");
            gtktextbuffer.method<&GtkTextBuffer_::get_selection_bounds>("get_selection_bounds");
            gtktextbuffer.method<&GtkTextBuffer_::begin_user_action>("begin_user_action");
            gtktextbuffer.method<&GtkTextBuffer_::end_user_action>("end_user_action");
            gtktextbuffer.method<&GtkTextBuffer_::remove_selection_clipboard>("remove_selection_clipboard");
            gtktextbuffer.method<&GtkTextBuffer_::deserialize>("deserialize");
            gtktextbuffer.method<&GtkTextBuffer_::deserialize_get_can_create_tags>("deserialize_get_can_create_tags");
            gtktextbuffer.method<&GtkTextBuffer_::deserialize_set_can_create_tags>("deserialize_set_can_create_tags");
            gtktextbuffer.method<&GtkTextBuffer_::get_copy_target_list>("get_copy_target_list");
            gtktextbuffer.method<&GtkTextBuffer_::get_deserialize_formats>("get_deserialize_formats");
            gtktextbuffer.method<&GtkTextBuffer_::get_paste_target_list>("get_paste_target_list");
            gtktextbuffer.method<&GtkTextBuffer_::get_serialize_formats>("get_serialize_formats");
            gtktextbuffer.method<&GtkTextBuffer_::register_deserialize_format>("register_deserialize_format");
            gtktextbuffer.method<&GtkTextBuffer_::register_serialize_format>("register_serialize_format");
            gtktextbuffer.method<&GtkTextBuffer_::register_serialize_tagset>("register_serialize_tagset");
            gtktextbuffer.method<&GtkTextBuffer_::serialize>("serialize");
            gtktextbuffer.method<&GtkTextBuffer_::unregister_deserialize_format>("unregister_deserialize_format");
            gtktextbuffer.method<&GtkTextBuffer_::unregister_serialize_format>("unregister_serialize_format");
        

        // GtkTextTag
        Php::Class<GtkTextTag_> gtktexttag("GtkTextTag");
            gtktexttag.extends(gobject);
            gtktexttag.method<&GtkTextTag_::__construct>("__construct");
            gtktexttag.method<&GtkTextTag_::get_priority>("get_priority");
            gtktexttag.method<&GtkTextTag_::set_priority>("set_priority");
            gtktexttag.method<&GtkTextTag_::event>("event");
            gtktexttag.method<&GtkTextTag_::tag_changed>("tag_changed");
        

        // GtkTextWindowType
        Php::Class<GtkTextWindowType_> gtktextwindowtype("GtkTextWindowType");
            gtktextwindowtype.constant("PRIVATE", (int)GTK_TEXT_WINDOW_PRIVATE);
            gtktextwindowtype.constant("WIDGET", (int)GTK_TEXT_WINDOW_WIDGET);
            gtktextwindowtype.constant("TEXT", (int)GTK_TEXT_WINDOW_TEXT);
            gtktextwindowtype.constant("LEFT", (int)GTK_TEXT_WINDOW_LEFT);
            gtktextwindowtype.constant("RIGHT", (int)GTK_TEXT_WINDOW_RIGHT);
            gtktextwindowtype.constant("TOP", (int)GTK_TEXT_WINDOW_TOP);
            gtktextwindowtype.constant("BOTTOM", (int)GTK_TEXT_WINDOW_BOTTOM);


        // GtkWrapMode
        Php::Class<GtkWrapMode_> gtkwrapmode("GtkWrapMode");
            gtkwrapmode.constant("NONE", (int)GTK_WRAP_NONE);
            gtkwrapmode.constant("CHAR", (int)GTK_WRAP_CHAR);
            gtkwrapmode.constant("WORD", (int)GTK_WRAP_WORD);
            gtkwrapmode.constant("WORD_CHAR", (int)GTK_WRAP_WORD_CHAR);
        

        // GtkInputHints
        Php::Class<GtkInputHints_> gtkinputhints("GtkInputHints");
            gtkinputhints.constant("NONE", (int)GTK_INPUT_HINT_NONE);
            gtkinputhints.constant("SPELLCHECK", (int)GTK_INPUT_HINT_SPELLCHECK);
            gtkinputhints.constant("NO_SPELLCHECK", (int)GTK_INPUT_HINT_NO_SPELLCHECK);
            gtkinputhints.constant("WORD_COMPLETION", (int)GTK_INPUT_HINT_WORD_COMPLETION);
            gtkinputhints.constant("LOWERCASE", (int)GTK_INPUT_HINT_LOWERCASE);
            gtkinputhints.constant("UPPERCASE_CHARS", (int)GTK_INPUT_HINT_UPPERCASE_CHARS);
            gtkinputhints.constant("UPPERCASE_WORDS", (int)GTK_INPUT_HINT_UPPERCASE_WORDS);
            gtkinputhints.constant("UPPERCASE_SENTENCES", (int)GTK_INPUT_HINT_UPPERCASE_SENTENCES);
            gtkinputhints.constant("INHIBIT_OSK", (int)GTK_INPUT_HINT_INHIBIT_OSK);
            gtkinputhints.constant("VERTICAL_WRITING", (int)GTK_INPUT_HINT_VERTICAL_WRITING);
            // gtkinputhints.constant("EMOJI", (int)GTK_INPUT_HINT_EMOJI);
            // gtkinputhints.constant("NO_EMOJI", (int)GTK_INPUT_HINT_NO_EMOJI);


        // GtkInputPurpose
        Php::Class<GtkInputPurpose_> gtkinputpurpose("GtkInputPurpose");
            gtkinputhints.constant("FREE_FORM", (int)GTK_INPUT_PURPOSE_FREE_FORM);
            gtkinputhints.constant("ALPHA", (int)GTK_INPUT_PURPOSE_ALPHA);
            gtkinputhints.constant("DIGITS", (int)GTK_INPUT_PURPOSE_DIGITS);
            gtkinputhints.constant("NUMBER", (int)GTK_INPUT_PURPOSE_NUMBER);
            gtkinputhints.constant("PHONE", (int)GTK_INPUT_PURPOSE_PHONE);
            gtkinputhints.constant("URL", (int)GTK_INPUT_PURPOSE_URL);
            gtkinputhints.constant("EMAIL", (int)GTK_INPUT_PURPOSE_EMAIL);
            gtkinputhints.constant("NAME", (int)GTK_INPUT_PURPOSE_NAME);
            gtkinputhints.constant("PASSWORD", (int)GTK_INPUT_PURPOSE_PASSWORD);
            gtkinputhints.constant("PIN", (int)GTK_INPUT_PURPOSE_PIN);


        // GtkTextMark
        Php::Class<GtkTextMark_> gtktextmark("GtkTextMark");
            gtktextmark.extends(gobject);
            gtktextmark.method<&GtkTextMark_::__construct>("__construct");
            gtktextmark.method<&GtkTextMark_::set_visible>("set_visible");
            gtktextmark.method<&GtkTextMark_::set_buffer>("set_buffer");
            gtktextmark.method<&GtkTextMark_::get_deleted>("get_deleted");
            gtktextmark.method<&GtkTextMark_::get_name>("get_name");
            gtktextmark.method<&GtkTextMark_::get_buffer>("get_buffer");
            gtktextmark.method<&GtkTextMark_::get_left_gravity>("get_left_gravity");
        

        // GtkDialogFlags
        Php::Class<GtkDialogFlags_> gtkdialogflags("GtkDialogFlags");
            gtkdialogflags.constant("MODAL", (int)GTK_DIALOG_MODAL);
            gtkdialogflags.constant("DESTROY_WITH_PARENT", (int)GTK_DIALOG_DESTROY_WITH_PARENT);
            gtkdialogflags.constant("USE_HEADER_BAR", (int)GTK_DIALOG_USE_HEADER_BAR);
        

        // GtkResponseType
        Php::Class<GtkResponseType_> gtkresponsetype("GtkResponseType");
            gtkresponsetype.constant("REJECT", (int)GTK_RESPONSE_REJECT);
            gtkresponsetype.constant("ACCEPT", (int)GTK_RESPONSE_ACCEPT);
            gtkresponsetype.constant("DELETE_EVENT", (int)GTK_RESPONSE_DELETE_EVENT);
            gtkresponsetype.constant("OK", (int)GTK_RESPONSE_OK);
            gtkresponsetype.constant("CANCEL", (int)GTK_RESPONSE_CANCEL);
            gtkresponsetype.constant("CLOSE", (int)GTK_RESPONSE_CLOSE);
            gtkresponsetype.constant("YES", (int)GTK_RESPONSE_YES);
            gtkresponsetype.constant("NO", (int)GTK_RESPONSE_NO);
            gtkresponsetype.constant("APPLY", (int)GTK_RESPONSE_APPLY);
            gtkresponsetype.constant("HELP", (int)GTK_RESPONSE_HELP);
        

        // GtkFileFilterFlags
        Php::Class<GtkFileFilterFlags_> gtkfilefilterflags("GtkFileFilterFlags");
            gtkfilefilterflags.constant("FILENAME", (int)GTK_FILE_FILTER_FILENAME);
            gtkfilefilterflags.constant("URI", (int)GTK_FILE_FILTER_URI);
            gtkfilefilterflags.constant("DIPLAY_NAME", (int)GTK_FILE_FILTER_DISPLAY_NAME);
            gtkfilefilterflags.constant("MIME_TYPE", (int)GTK_FILE_FILTER_MIME_TYPE);
        

        // GtkFileFilter
        Php::Class<GtkFileFilter_> gtkfilefilter("GtkFileFilter");
            gtkfilefilter.extends(gobject);
            gtkfilefilter.method<&GtkFileFilter_::__construct>("__construct");
            gtkfilefilter.method<&GtkFileFilter_::set_name>("set_name");
            gtkfilefilter.method<&GtkFileFilter_::get_name>("get_name");
            gtkfilefilter.method<&GtkFileFilter_::add_mime_type>("add_mime_type");
            gtkfilefilter.method<&GtkFileFilter_::add_pattern>("add_pattern");
            gtkfilefilter.method<&GtkFileFilter_::add_pixbuf_formats>("add_pixbuf_formats");
            gtkfilefilter.method<&GtkFileFilter_::get_needed>("get_needed");
            gtkfilefilter.method<&GtkFileFilter_::filter>("filter");


        // GtkFileChooserDialog
        // gtkfilechooserdialog.implements(gtkfilechooser);
        Php::Class<GtkFileChooserDialog_> gtkfilechooserdialog("GtkFileChooserDialog");
            gtkfilechooserdialog.extends(gtkdialog);
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::__construct>("__construct");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_action>("set_action");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_action>("get_action");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_local_only>("set_local_only");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_local_only>("get_local_only");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_select_multiple>("set_select_multiple");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_select_multiple>("get_select_multiple");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_show_hidden>("set_show_hidden");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_show_hidden>("get_show_hidden");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_do_overwrite_confirmation>("set_do_overwrite_confirmation");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_do_overwrite_confirmation>("get_do_overwrite_confirmation");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_create_folders>("set_create_folders");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_create_folders>("get_create_folders");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_current_name>("set_current_name");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_current_name>("get_current_name");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_filename>("set_filename");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_filename>("get_filename");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::select_filename>("select_filename");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::unselect_filename>("unselect_filename");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::select_all>("select_all");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::unselect_all>("unselect_all");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_filenames>("get_filenames");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_current_folder>("set_current_folder");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_current_folder>("get_current_folder");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_uri>("get_uri");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_uri>("set_uri");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::select_uri>("select_uri");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::unselect_uri>("unselect_uri");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_uris>("get_uris");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_current_folder_uri>("set_current_folder_uri");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_preview_widget>("set_preview_widget");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_preview_widget>("get_preview_widget");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_preview_widget_active>("set_preview_widget_active");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_preview_widget_active>("get_preview_widget_active");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_use_preview_label>("set_use_preview_label");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_use_preview_label>("get_use_preview_label");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_preview_uri>("get_preview_uri");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_extra_widget>("set_extra_widget");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_extra_widget>("get_extra_widget");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::add_filter>("add_filter");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::remove_filter>("remove_filter");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::list_filters>("list_filters");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::set_filter>("set_filter");
            gtkfilechooserdialog.method<&GtkFileChooserDialog_::get_filter>("get_filter");


        // GtkFileFilterInfo
        Php::Class<GtkFileFilterInfo_> gtkfilefilterinfo("GtkFileFilterInfo");


        // GtkMessageType
        Php::Class<GtkMessageType_> gtkmessagetype("GtkMessageType");
            gtkmessagetype.constant("INFO", (int)GTK_MESSAGE_INFO);
            gtkmessagetype.constant("WARNING", (int)GTK_MESSAGE_WARNING);
            gtkmessagetype.constant("QUESTION", (int)GTK_MESSAGE_QUESTION);
            gtkmessagetype.constant("ERROR", (int)GTK_MESSAGE_ERROR);
            gtkmessagetype.constant("OTHER", (int)GTK_MESSAGE_OTHER);


        // GtkButtonsType
        Php::Class<GtkButtonsType_> gtkbuttonstype("GtkButtonsType");
            gtkbuttonstype.constant("NONE", (int)GTK_BUTTONS_NONE);
            gtkbuttonstype.constant("OK", (int)GTK_BUTTONS_OK);
            gtkbuttonstype.constant("CLOSE", (int)GTK_BUTTONS_CLOSE);
            gtkbuttonstype.constant("CANCEL", (int)GTK_BUTTONS_CANCEL);
            gtkbuttonstype.constant("YES_NO", (int)GTK_BUTTONS_YES_NO);
            gtkbuttonstype.constant("OK_CANCEL", (int)GTK_BUTTONS_OK_CANCEL);


        // GtkMessageDialog
        Php::Class<GtkMessageDialog_> gtkmessagedialog("GtkMessageDialog");
            gtkmessagedialog.extends(gtkdialog);
            gtkmessagedialog.method<&GtkMessageDialog_::__construct>("__construct");
            gtkmessagedialog.method<&GtkMessageDialog_::new_with_markup>("new_with_markup");
            gtkmessagedialog.method<&GtkMessageDialog_::set_markup>("set_markup");
            gtkmessagedialog.method<&GtkMessageDialog_::format_secondary_text>("format_secondary_text");
            gtkmessagedialog.method<&GtkMessageDialog_::format_secondary_markup>("format_secondary_markup");
            gtkmessagedialog.method<&GtkMessageDialog_::get_message_area>("get_message_area");
        

        // GtkIconSize
        Php::Class<GtkIconSize_> gtkiconsize("GtkIconSize");
            gtkiconsize.constant("INVALID", (int)GTK_ICON_SIZE_INVALID);
            gtkiconsize.constant("MENU", (int)GTK_ICON_SIZE_MENU);
            gtkiconsize.constant("SMALL_TOOLBAR", (int)GTK_ICON_SIZE_SMALL_TOOLBAR);
            gtkiconsize.constant("LARGE_TOOLBAR", (int)GTK_ICON_SIZE_LARGE_TOOLBAR);
            gtkiconsize.constant("BUTTON", (int)GTK_ICON_SIZE_BUTTON);
            gtkiconsize.constant("DND", (int)GTK_ICON_SIZE_DND);
            gtkiconsize.constant("DIALOG", (int)GTK_ICON_SIZE_DIALOG);
        

        // GtkSizeGroupMode
        Php::Class<GtkSizeGroupMode_> gtksizegroupmode("GtkSizeGroupMode");
            gtksizegroupmode.constant("NONE", (int)GTK_SIZE_GROUP_NONE);
            gtksizegroupmode.constant("HORIZONTAL", (int)GTK_SIZE_GROUP_HORIZONTAL);
            gtksizegroupmode.constant("VERTICAL", (int)GTK_SIZE_GROUP_VERTICAL);
            gtksizegroupmode.constant("BOTH", (int)GTK_SIZE_GROUP_BOTH);

        // GtkToolbarStyle
        Php::Class<GtkToolbarStyle_> gtktoolbarstyle("GtkToolbarStyle");
            gtktoolbarstyle.constant("ICONS", (int)GTK_TOOLBAR_ICONS);
            gtktoolbarstyle.constant("TEXT", (int)GTK_TOOLBAR_TEXT);
            gtktoolbarstyle.constant("BOTH", (int)GTK_TOOLBAR_BOTH);
            gtktoolbarstyle.constant("BOTH_HORIZ", (int)GTK_TOOLBAR_BOTH_HORIZ);


        // GtkReliefStyle
        Php::Class<GtkReliefStyle_> gtkreliefstyle("GtkReliefStyle");
            gtktoolbarstyle.constant("NORMAL", (int)GTK_RELIEF_NORMAL);
            gtktoolbarstyle.constant("HALF", (int)GTK_RELIEF_HALF);
            gtktoolbarstyle.constant("NONE", (int)GTK_RELIEF_NONE);


        // GtkSizeGroup
        Php::Class<GtkSizeGroup_> gtksizegroup("GtkSizeGroup");
            gtksizegroup.extends(gobject);
            gtksizegroup.method<&GtkSizeGroup_::__construct>("__construct");
            gtksizegroup.method<&GtkSizeGroup_::set_mode>("set_mode");
            gtksizegroup.method<&GtkSizeGroup_::get_mode>("get_mode");
            gtksizegroup.method<&GtkSizeGroup_::add_widget>("add_widget");
            gtksizegroup.method<&GtkSizeGroup_::remove_widget>("remove_widget");
            gtksizegroup.method<&GtkSizeGroup_::get_widgets>("get_widgets");


        // GtkToolItem
        Php::Class<GtkToolItem_> gtktoolitem("GtkToolItem");
            gtktoolitem.extends(gtkbin);
            gtktoolitem.method<&GtkToolItem_::__construct>("__construct");
            gtktoolitem.method<&GtkToolItem_::set_homogeneous>("set_homogeneous");
            gtktoolitem.method<&GtkToolItem_::get_homogeneous>("get_homogeneous");
            gtktoolitem.method<&GtkToolItem_::set_expand>("set_expand");
            gtktoolitem.method<&GtkToolItem_::get_expand>("get_expand");
            gtktoolitem.method<&GtkToolItem_::set_tooltip_text>("set_tooltip_text");
            gtktoolitem.method<&GtkToolItem_::set_tooltip_markup>("set_tooltip_markup");
            gtktoolitem.method<&GtkToolItem_::set_use_drag_window>("set_use_drag_window");
            gtktoolitem.method<&GtkToolItem_::get_use_drag_window>("get_use_drag_window");
            gtktoolitem.method<&GtkToolItem_::set_visible_horizontal>("set_visible_horizontal");
            gtktoolitem.method<&GtkToolItem_::get_visible_horizontal>("get_visible_horizontal");
            gtktoolitem.method<&GtkToolItem_::set_visible_vertical>("set_visible_vertical");
            gtktoolitem.method<&GtkToolItem_::get_visible_vertical>("get_visible_vertical");
            gtktoolitem.method<&GtkToolItem_::set_is_important>("set_is_important");
            gtktoolitem.method<&GtkToolItem_::get_is_important>("get_is_important");
            gtktoolitem.method<&GtkToolItem_::get_icon_size>("get_icon_size");
            gtktoolitem.method<&GtkToolItem_::get_orientation>("get_orientation");
            gtktoolitem.method<&GtkToolItem_::get_toolbar_style>("get_toolbar_style");
            gtktoolitem.method<&GtkToolItem_::get_relief_style>("get_relief_style");
            gtktoolitem.method<&GtkToolItem_::get_text_alignment>("get_text_alignment");
            gtktoolitem.method<&GtkToolItem_::get_text_orientation>("get_text_orientation");
            gtktoolitem.method<&GtkToolItem_::retrieve_proxy_menu_item>("retrieve_proxy_menu_item");
            gtktoolitem.method<&GtkToolItem_::set_proxy_menu_item>("set_proxy_menu_item");
            gtktoolitem.method<&GtkToolItem_::get_proxy_menu_item>("get_proxy_menu_item");
            gtktoolitem.method<&GtkToolItem_::rebuild_menu>("rebuild_menu");
            gtktoolitem.method<&GtkToolItem_::toolbar_reconfigured>("toolbar_reconfigured");
            gtktoolitem.method<&GtkToolItem_::get_text_size_group>("get_text_size_group");


        // GtkSeparatorToolItem
        Php::Class<GtkSeparatorToolItem_> gtkseparatortoolitem("GtkSeparatorToolItem");
            gtkseparatortoolitem.extends(gtktoolitem);
            gtkseparatortoolitem.method<&GtkSeparatorToolItem_::__construct>("__construct");
            gtkseparatortoolitem.method<&GtkSeparatorToolItem_::set_draw>("set_draw");
            gtkseparatortoolitem.method<&GtkSeparatorToolItem_::get_draw>("get_draw");


        // GtkToolbar
        Php::Class<GtkToolbar_> gtktoolbar("GtkToolbar");
            gtktoolbar.extends(gtkcontainer);
            gtktoolbar.method<&GtkToolbar_::__construct>("__construct");
            gtktoolbar.method<&GtkToolbar_::insert>("insert");
            gtktoolbar.method<&GtkToolbar_::get_item_index>("get_item_index");
            gtktoolbar.method<&GtkToolbar_::get_n_items>("get_n_items");
            gtktoolbar.method<&GtkToolbar_::get_nth_item>("get_nth_item");
            gtktoolbar.method<&GtkToolbar_::get_drop_index>("get_drop_index");
            gtktoolbar.method<&GtkToolbar_::set_drop_highlight_item>("set_drop_highlight_item");
            gtktoolbar.method<&GtkToolbar_::set_show_arrow>("set_show_arrow");
            gtktoolbar.method<&GtkToolbar_::unset_icon_size>("unset_icon_size");
            gtktoolbar.method<&GtkToolbar_::get_show_arrow>("get_show_arrow");
            gtktoolbar.method<&GtkToolbar_::get_style>("get_style");
            gtktoolbar.method<&GtkToolbar_::get_icon_size>("get_icon_size");
            gtktoolbar.method<&GtkToolbar_::get_relief_style>("get_relief_style");
            gtktoolbar.method<&GtkToolbar_::set_style>("set_style");
            gtktoolbar.method<&GtkToolbar_::set_icon_size>("set_icon_size");
            gtktoolbar.method<&GtkToolbar_::unset_style>("unset_style");


        // GtkToolButton
        Php::Class<GtkToolButton_> gtktoolbutton("GtkToolButton");
            gtktoolbutton.extends(gtktoolitem);
            gtktoolbutton.method<&GtkToolButton_::__construct>("__construct");
            gtktoolbutton.method<&GtkToolButton_::set_label>("set_label");
            gtktoolbutton.method<&GtkToolButton_::get_label>("get_label");
            gtktoolbutton.method<&GtkToolButton_::set_use_underline>("set_use_underline");
            gtktoolbutton.method<&GtkToolButton_::get_use_underline>("get_use_underline");
            gtktoolbutton.method<&GtkToolButton_::set_icon_name>("set_icon_name");
            gtktoolbutton.method<&GtkToolButton_::get_icon_name>("get_icon_name");
            gtktoolbutton.method<&GtkToolButton_::set_icon_widget>("set_icon_widget");
            gtktoolbutton.method<&GtkToolButton_::get_icon_widget>("get_icon_widget");
            gtktoolbutton.method<&GtkToolButton_::set_label_widget>("set_label_widget");
            gtktoolbutton.method<&GtkToolButton_::get_label_widget>("get_label_widget");
        

        // GtkTextTagTable
        Php::Class<GtkTextTagTable_> gtktexttagtable("GtkTextTagTable");
            gtktexttagtable.extends(gobject);
            gtktexttagtable.method<&GtkTextTagTable_::__construct>("__construct");
            gtktexttagtable.method<&GtkTextTagTable_::add>("add");
            gtktexttagtable.method<&GtkTextTagTable_::remove>("remove");
            gtktexttagtable.method<&GtkTextTagTable_::lookup>("lookup");
            gtktexttagtable.method<&GtkTextTagTable_::foreach>("foreach");
            gtktexttagtable.method<&GtkTextTagTable_::get_size>("get_size");
        

        // GdkSelection
        Php::Class<GdkSelection_> gdkselection("GdkSelection");
            gdkselection.constant("PRIMARY", 1);
            gdkselection.constant("SECONDARY", 2);
            gdkselection.constant("CLIPBOARD", 69);
            // gdkselection.constant("NORMAL", GDK_TARGET_BITMAP);
            // gdkselection.constant("NORMAL", GDK_TARGET_COLORMAP);
            // gdkselection.constant("NORMAL", GDK_TARGET_DRAWABLE);
            // gdkselection.constant("NORMAL", GDK_TARGET_PIXMAP);
            // gdkselection.constant("NORMAL", GDK_TARGET_STRING);
            gdkselection.constant("TYPE_ATOM", 4);
            gdkselection.constant("TYPE_BITMAP", 5);
            gdkselection.constant("TYPE_COLORMAP", 7);
            gdkselection.constant("TYPE_DRAWABLE", 17);
            gdkselection.constant("TYPE_INTEGER", 19);
            gdkselection.constant("TYPE_PIXMAP", 20);
            gdkselection.constant("TYPE_WINDOW", 33);
            gdkselection.constant("TYPE_STRING", 31);


        // GtkClipboard
        Php::Class<GtkClipboard_> gtkclipboard("GtkClipboard");
            gtkclipboard.extends(gobject);
            gtkclipboard.method<&GtkClipboard_::__construct>("__construct");
            gtkclipboard.method<&GtkClipboard_::get_for_display>("get_for_display");
            gtkclipboard.method<&GtkClipboard_::get_display>("get_display");
            gtkclipboard.method<&GtkClipboard_::set_with_data>("set_with_data");
            gtkclipboard.method<&GtkClipboard_::set_with_owner>("set_with_owner");
            gtkclipboard.method<&GtkClipboard_::get_owner>("get_owner");
            gtkclipboard.method<&GtkClipboard_::clear>("clear");
            gtkclipboard.method<&GtkClipboard_::set_text>("set_text");
            gtkclipboard.method<&GtkClipboard_::set_image>("set_image");
            gtkclipboard.method<&GtkClipboard_::request_contents>("request_contents");
            gtkclipboard.method<&GtkClipboard_::request_text>("request_text");
            gtkclipboard.method<&GtkClipboard_::request_image>("request_image");
            gtkclipboard.method<&GtkClipboard_::request_targets>("request_targets");
            gtkclipboard.method<&GtkClipboard_::request_rich_text>("request_rich_text");
            gtkclipboard.method<&GtkClipboard_::request_uris>("request_uris");
            gtkclipboard.method<&GtkClipboard_::wait_for_contents>("wait_for_contents");
            gtkclipboard.method<&GtkClipboard_::wait_for_text>("wait_for_text");
            gtkclipboard.method<&GtkClipboard_::wait_for_image>("wait_for_image");
            gtkclipboard.method<&GtkClipboard_::wait_for_rich_text>("wait_for_rich_text");
            gtkclipboard.method<&GtkClipboard_::wait_for_uris>("wait_for_uris");
            gtkclipboard.method<&GtkClipboard_::wait_is_text_available>("wait_is_text_available");
            gtkclipboard.method<&GtkClipboard_::wait_is_image_available>("wait_is_image_available");
            gtkclipboard.method<&GtkClipboard_::wait_is_uris_available>("wait_is_uris_available");
            gtkclipboard.method<&GtkClipboard_::wait_is_target_available>("wait_is_target_available");
            gtkclipboard.method<&GtkClipboard_::set_can_store>("set_can_store");
            gtkclipboard.method<&GtkClipboard_::get_selection>("get_selection");


        // GtkTreeStore
        Php::Class<GtkTreeStore_> gtktreestore("GtkTreeStore");
            gtktreestore.extends(gtktreemodel);
            gtktreestore.method<&GtkTreeStore_::__construct>("__construct");
            gtktreestore.method<&GtkTreeStore_::set_column_types>("set_column_types");
            gtktreestore.method<&GtkTreeStore_::set_value>("set_value");
            gtktreestore.method<&GtkTreeStore_::remove>("remove");
            gtktreestore.method<&GtkTreeStore_::insert>("insert");
            gtktreestore.method<&GtkTreeStore_::insert_before>("insert_before");
            gtktreestore.method<&GtkTreeStore_::insert_after>("insert_after");
            gtktreestore.method<&GtkTreeStore_::insert_with_values>("insert_with_values");
            gtktreestore.method<&GtkTreeStore_::prepend>("prepend");
            gtktreestore.method<&GtkTreeStore_::append>("append");
            gtktreestore.method<&GtkTreeStore_::is_ancestor>("is_ancestor");
            gtktreestore.method<&GtkTreeStore_::iter_depth>("iter_depth");
            gtktreestore.method<&GtkTreeStore_::clear>("clear");
            gtktreestore.method<&GtkTreeStore_::reorder>("reorder");
            gtktreestore.method<&GtkTreeStore_::swap>("swap");
            gtktreestore.method<&GtkTreeStore_::move_before>("move_before");
            gtktreestore.method<&GtkTreeStore_::move_after>("move_after");
        
        
        // GtkSelectionMode
        Php::Class<GtkSelectionMode_> gtkselectionmode("GtkSelectionMode");
            gtkselectionmode.constant("NONE", GTK_SELECTION_NONE);
            gtkselectionmode.constant("SINGLE", GTK_SELECTION_SINGLE);
            gtkselectionmode.constant("BROWSE", GTK_SELECTION_BROWSE);
            gtkselectionmode.constant("MULTIPLE", GTK_SELECTION_MULTIPLE);


        // GtkTreeSelection
        Php::Class<GtkTreeSelection_> gtktreeselection("GtkTreeSelection");
            gtktreeselection.extends(gobject);
            gtktreeselection.method<&GtkTreeSelection_::set_mode>("set_mode");
            gtktreeselection.method<&GtkTreeSelection_::get_mode>("get_mode");
            gtktreeselection.method<&GtkTreeSelection_::set_select_function>("set_select_function");
            gtktreeselection.method<&GtkTreeSelection_::get_select_function>("get_select_function");
            gtktreeselection.method<&GtkTreeSelection_::get_user_data>("get_user_data");
            gtktreeselection.method<&GtkTreeSelection_::get_tree_view>("get_tree_view");
            gtktreeselection.method<&GtkTreeSelection_::get_selected>("get_selected");
            gtktreeselection.method<&GtkTreeSelection_::selected_foreach>("selected_foreach");
            gtktreeselection.method<&GtkTreeSelection_::get_selected_rows>("get_selected_rows");
            gtktreeselection.method<&GtkTreeSelection_::count_selected_rows>("count_selected_rows");
            gtktreeselection.method<&GtkTreeSelection_::select_path>("select_path");
            gtktreeselection.method<&GtkTreeSelection_::unselect_path>("unselect_path");
            gtktreeselection.method<&GtkTreeSelection_::path_is_selected>("path_is_selected");
            gtktreeselection.method<&GtkTreeSelection_::select_iter>("select_iter");
            gtktreeselection.method<&GtkTreeSelection_::unselect_iter>("unselect_iter");
            gtktreeselection.method<&GtkTreeSelection_::iter_is_selected>("iter_is_selected");
            gtktreeselection.method<&GtkTreeSelection_::select_all>("select_all");
            gtktreeselection.method<&GtkTreeSelection_::unselect_all>("unselect_all");
            gtktreeselection.method<&GtkTreeSelection_::unselect_range>("unselect_range");


        // GtkMenuShell
        Php::Class<GtkMenuShell_> gtkmenushell("GtkMenuShell");
            gtkmenushell.extends(gtkcontainer);
            gtkmenushell.method<&GtkMenuShell_::append>("append");
            gtkmenushell.method<&GtkMenuShell_::prepend>("prepend");
            gtkmenushell.method<&GtkMenuShell_::insert>("insert");
            gtkmenushell.method<&GtkMenuShell_::deactivate>("deactivate");
            gtkmenushell.method<&GtkMenuShell_::select_item>("select_item");
            gtkmenushell.method<&GtkMenuShell_::select_first>("select_first");
            gtkmenushell.method<&GtkMenuShell_::deselect>("deselect");
            gtkmenushell.method<&GtkMenuShell_::activate_item>("activate_item");
            gtkmenushell.method<&GtkMenuShell_::cancel>("cancel");
            gtkmenushell.method<&GtkMenuShell_::set_take_focus>("set_take_focus");
            gtkmenushell.method<&GtkMenuShell_::get_take_focus>("get_take_focus");
            gtkmenushell.method<&GtkMenuShell_::get_selected_item>("get_selected_item");
            gtkmenushell.method<&GtkMenuShell_::get_parent_shell>("get_parent_shell");
            gtkmenushell.method<&GtkMenuShell_::bind_model>("bind_model");


        // GtkPackDirection
        Php::Class<GtkPackDirection_> gtkpackdirection("GtkPackDirection");
            gtkpackdirection.constant("LTR", GTK_PACK_DIRECTION_LTR);
            gtkpackdirection.constant("RTL", GTK_PACK_DIRECTION_RTL);
            gtkpackdirection.constant("TTB", GTK_PACK_DIRECTION_TTB);
            gtkpackdirection.constant("BTT", GTK_PACK_DIRECTION_BTT);


        // GtkMenuBar
        Php::Class<GtkMenuBar_> gtkmenubar("GtkMenuBar");
            gtkmenubar.extends(gtkmenushell);
            gtkmenubar.method<&GtkMenuBar_::__construct>("__construct");
            gtkmenubar.method<&GtkMenuBar_::new_from_model>("new_from_model");
            gtkmenubar.method<&GtkMenuBar_::set_pack_direction>("set_pack_direction");
            gtkmenubar.method<&GtkMenuBar_::get_pack_direction>("get_pack_direction");
            gtkmenubar.method<&GtkMenuBar_::set_child_pack_direction>("set_child_pack_direction");
            gtkmenubar.method<&GtkMenuBar_::child_pack_direction>("child_pack_direction");



        // GtkMenu
        Php::Class<GtkMenu_> gtkmenu("GtkMenu");
            gtkmenu.extends(gtkmenushell);
            gtkmenu.method<&GtkMenu_::__construct>("__construct");
            gtkmenu.method<&GtkMenu_::new_from_model>("new_from_model");
            gtkmenu.method<&GtkMenu_::set_screen>("set_screen");
            gtkmenu.method<&GtkMenu_::reorder_child>("reorder_child");
            gtkmenu.method<&GtkMenu_::attach>("attach");
            gtkmenu.method<&GtkMenu_::popup_at_rect>("popup_at_rect");
            gtkmenu.method<&GtkMenu_::popup_at_widget>("popup_at_widget");
            gtkmenu.method<&GtkMenu_::popup_at_pointer>("popup_at_pointer");
            gtkmenu.method<&GtkMenu_::set_accel_group>("set_accel_group");
            gtkmenu.method<&GtkMenu_::get_accel_group>("get_accel_group");
            gtkmenu.method<&GtkMenu_::set_accel_path>("set_accel_path");
            gtkmenu.method<&GtkMenu_::get_accel_path>("get_accel_path");
            gtkmenu.method<&GtkMenu_::set_monitor>("set_monitor");
            gtkmenu.method<&GtkMenu_::get_monitor>("get_monitor");
            gtkmenu.method<&GtkMenu_::place_on_monitor>("place_on_monitor");
            gtkmenu.method<&GtkMenu_::set_reserve_toggle_size>("set_reserve_toggle_size");
            gtkmenu.method<&GtkMenu_::get_reserve_toggle_size>("get_reserve_toggle_size");
            gtkmenu.method<&GtkMenu_::popdown>("popdown");
            gtkmenu.method<&GtkMenu_::reposition>("reposition");
            gtkmenu.method<&GtkMenu_::get_active>("get_active");
            gtkmenu.method<&GtkMenu_::set_active>("set_active");
            gtkmenu.method<&GtkMenu_::attach_to_widget>("attach_to_widget");
            gtkmenu.method<&GtkMenu_::detach>("detach");
            gtkmenu.method<&GtkMenu_::get_attach_widget>("get_attach_widget");
            gtkmenu.method<&GtkMenu_::get_for_attach_widget>("get_for_attach_widget");


            // GtkMenuItem
        Php::Class<GtkMenuItem_> gtkmenuitem("GtkMenuItem");
            gtkmenuitem.extends(gtkbin);
            gtkmenuitem.method<&GtkMenuItem_::__construct>("__construct");
            gtkmenuitem.method<&GtkMenuItem_::new_with_label>("new_with_label");
            gtkmenuitem.method<&GtkMenuItem_::new_with_mnemonic>("new_with_mnemonic");
            gtkmenuitem.method<&GtkMenuItem_::get_label>("get_label");
            gtkmenuitem.method<&GtkMenuItem_::set_label>("set_label");
            gtkmenuitem.method<&GtkMenuItem_::get_use_underline>("get_use_underline");
            gtkmenuitem.method<&GtkMenuItem_::set_use_underline>("set_use_underline");
            gtkmenuitem.method<&GtkMenuItem_::set_submenu>("set_submenu");
            gtkmenuitem.method<&GtkMenuItem_::get_submenu>("get_submenu");
            gtkmenuitem.method<&GtkMenuItem_::set_accel_path>("set_accel_path");
            gtkmenuitem.method<&GtkMenuItem_::get_accel_path>("get_accel_path");
            gtkmenuitem.method<&GtkMenuItem_::select>("select");
            gtkmenuitem.method<&GtkMenuItem_::deselect>("deselect");
            gtkmenuitem.method<&GtkMenuItem_::activate>("activate");
            gtkmenuitem.method<&GtkMenuItem_::toggle_size_request>("toggle_size_request");
            gtkmenuitem.method<&GtkMenuItem_::size_allocate>("size_allocate");
            gtkmenuitem.method<&GtkMenuItem_::get_reserve_indicator>("get_reserve_indicator");
            gtkmenuitem.method<&GtkMenuItem_::set_reserve_indicator>("set_reserve_indicator");


        // GtkSeparatorMenuItem
        Php::Class<GtkSeparatorMenuItem_> gtkseparatormenuitem("GtkSeparatorMenuItem");
            gtkseparatormenuitem.extends(gtkmenuitem);
            gtkseparatormenuitem.method<&GtkSeparatorMenuItem_::__construct>("__construct");


        // GtkCheckMenuItem
        Php::Class<GtkCheckMenuItem_> gtkcheckmenuitem("GtkCheckMenuItem");
            gtkcheckmenuitem.extends(gtkmenuitem);
            gtkcheckmenuitem.method<&GtkCheckMenuItem_::__construct>("__construct");
            gtkcheckmenuitem.method<&GtkCheckMenuItem_::new_with_label>("new_with_label");
            gtkcheckmenuitem.method<&GtkCheckMenuItem_::new_with_mnemonic>("new_with_mnemonic");
            gtkcheckmenuitem.method<&GtkCheckMenuItem_::get_active>("get_active");
            gtkcheckmenuitem.method<&GtkCheckMenuItem_::set_active>("set_active");
            gtkcheckmenuitem.method<&GtkCheckMenuItem_::toggled>("toggled");
            gtkcheckmenuitem.method<&GtkCheckMenuItem_::get_inconsistent>("get_inconsistent");
            gtkcheckmenuitem.method<&GtkCheckMenuItem_::set_inconsistent>("set_inconsistent");
            gtkcheckmenuitem.method<&GtkCheckMenuItem_::get_draw_as_radio>("get_draw_as_radio");
            gtkcheckmenuitem.method<&GtkCheckMenuItem_::set_draw_as_radio>("set_draw_as_radio");
        

        // Add classes to extension
        extension.add(std::move(gobject));
        extension.add(std::move(gdk));
        extension.add(std::move(gdkevent));
        extension.add(std::move(gdkeventbutton));
        extension.add(std::move(gdkpixbuf));
        
        extension.add(std::move(gdkpixbufformat));
        extension.add(std::move(gdkpixbufalphamode));
        extension.add(std::move(gdkcolorspace));

        extension.add(std::move(gtk));
        extension.add(std::move(gtkorientation));
        extension.add(std::move(gtkpolicytype));
        extension.add(std::move(gtkwidget));
        extension.add(std::move(gtkcontainer));
        extension.add(std::move(gtkbox));
        extension.add(std::move(gtkhbox));
        extension.add(std::move(gtkvbox));
        extension.add(std::move(gtkbin));
        extension.add(std::move(gtkpaned));
        extension.add(std::move(gtkwindow));
        extension.add(std::move(gtkdialog));
        extension.add(std::move(gtkfilechooserdialog));
        extension.add(std::move(gtkbutton));
        extension.add(std::move(gtktogglebutton));
        extension.add(std::move(gtkcheckbutton));
        extension.add(std::move(gtkadjustment));
        extension.add(std::move(gtkscrolledwindow));
        extension.add(std::move(gtkentrybuffer));
        extension.add(std::move(gtkentry));
        extension.add(std::move(gtksorttype));
        extension.add(std::move(gtktreeview));
        extension.add(std::move(gtktreeviewcolumn));
        extension.add(std::move(gtkcellrenderer));
        extension.add(std::move(gtkcellrenderertext));
        extension.add(std::move(gtkcellrenderertoggle));
        extension.add(std::move(gtkcellrendererpixbuf));
        extension.add(std::move(gtktreemodel));
        extension.add(std::move(gtkliststore));
        extension.add(std::move(gtktreemodelflags));
        extension.add(std::move(gtktreeiter));
        extension.add(std::move(gtklabel));
        extension.add(std::move(gtknotebook));
        extension.add(std::move(gtkpositiontype));
        extension.add(std::move(gtkpacktype));
        extension.add(std::move(gtkjustification));
        extension.add(std::move(gtkfilechooseraction));
        extension.add(std::move(gtktextview));
        extension.add(std::move(gtktextiter));
        extension.add(std::move(gtktextbuffer));
        extension.add(std::move(gtktexttag));
        extension.add(std::move(gtktextwindowtype));
        extension.add(std::move(gtkinputhints));
        extension.add(std::move(gtkinputpurpose));
        extension.add(std::move(gtkwrapmode));
        extension.add(std::move(gtktextmark));
        extension.add(std::move(gtkdialogflags));
        extension.add(std::move(gtkresponsetype));
        extension.add(std::move(gtkfilefilterflags));
        extension.add(std::move(gtkfilefilterinfo));
        extension.add(std::move(gtkfilefilter));
        extension.add(std::move(gtkmessagetype));
        extension.add(std::move(gtkbuttonstype));
        extension.add(std::move(gtkmessagedialog));
        extension.add(std::move(gtkiconsize));
        extension.add(std::move(gtksizegroupmode));
        extension.add(std::move(gtktoolbarstyle));
        extension.add(std::move(gtkreliefstyle));
        extension.add(std::move(gtksizegroup));
        extension.add(std::move(gtktoolitem));
        extension.add(std::move(gtkseparatortoolitem));
        extension.add(std::move(gtktoolbar));
        extension.add(std::move(gtktoolbutton));
        extension.add(std::move(gtktexttagtable));

        extension.add(std::move(gdkselection));

        extension.add(std::move(gtkclipboard));

        extension.add(std::move(gtktreestore));

        extension.add(std::move(gtkselectionmode));
        extension.add(std::move(gtktreeselection));

        extension.add(std::move(gtkmenushell));
        extension.add(std::move(gtkpackdirection));
        extension.add(std::move(gtkmenubar));
        extension.add(std::move(gtkmenu));
        extension.add(std::move(gtkmenuitem));
        extension.add(std::move(gtkseparatormenuitem));
        extension.add(std::move(gtkcheckmenuitem));

        // return the extension
        return extension;
    }
}



GValue phpgtk_get_gvalue(Php::Value phpgtk_value, GType type_column) 
{

    // Populate the column var with correct type
    GValue gtk_value = {0};
    switch(type_column) {
        case G_TYPE_INVALID:
        case G_TYPE_NONE:
            throw Php::Exception("G_TYPE_INVALID not implemented");
            break;
        case G_TYPE_INT:{
             // Cast
            int b = (int)phpgtk_value;

            g_value_init(&gtk_value, G_TYPE_INT);
            g_value_set_int(&gtk_value, b);

            break;
        }
        case G_TYPE_BOOLEAN:
        {
            // Cast
            bool b = (bool)phpgtk_value;

            g_value_init(&gtk_value, G_TYPE_BOOLEAN);
            g_value_set_boolean(&gtk_value, b);

            break;
        }
        case G_TYPE_DOUBLE:
        {
            // Cast
            double b = (double)phpgtk_value;

            g_value_init(&gtk_value, G_TYPE_DOUBLE);
            g_value_set_double(&gtk_value, b);

            break;
        }
        case G_TYPE_FLOAT:
        {
            // Cast
            double b = (double)phpgtk_value;

            g_value_init(&gtk_value, G_TYPE_FLOAT);
            g_value_set_float(&gtk_value, b);

            break;
        }
        case G_TYPE_STRING:
        {
            // Cast
            std::string b = phpgtk_value;

            g_value_init(&gtk_value, G_TYPE_STRING);
            g_value_set_string(&gtk_value, b.c_str());

            break;
        }
        case G_TYPE_CHAR:
        {
            throw Php::Exception("G_TYPE_CHAR not implemented");
            break;
        }
        case G_TYPE_LONG:
        {
            throw Php::Exception("G_TYPE_LONG not implemented");
            break;
        }
        case G_TYPE_ULONG:
        {
            throw Php::Exception("G_TYPE_ULONG not implemented");
            break;
        }
        case G_TYPE_UINT:
        {
            throw Php::Exception("G_TYPE_UINT not implemented");
            break;
        }
        case G_TYPE_UCHAR:
        {
            throw Php::Exception("G_TYPE_UCHAR not implemented");
            break;
        }
        case G_TYPE_OBJECT:
        {
            g_value_init(&gtk_value, G_TYPE_OBJECT);

            Php::Value a_object = phpgtk_value;
            GObject_ *o_object = (GObject_ *)a_object.implementation();
            g_value_set_object(&gtk_value, o_object->get_instance());
            
            break;
        }
        case G_TYPE_INTERFACE:
        {
            throw Php::Exception("G_TYPE_INTERFACE not implemented");
            break;
        }
        case G_TYPE_PARAM:
        {
            throw Php::Exception("G_TYPE_PARAM not implemented");
            break;
        }
        case G_TYPE_BOXED:
        {
            throw Php::Exception("G_TYPE_BOXED not implemented");
            break;
        }
        case G_TYPE_POINTER:
        {
            throw Php::Exception("G_TYPE_POINTER not implemented");
            break;
        }
        case G_TYPE_FLAGS:
        {
            throw Php::Exception("G_TYPE_FLAGS not implemented");
            break;
        }
        case G_TYPE_ENUM:
        {
            throw Php::Exception("G_TYPE_ENUM not implemented");
            break;
        }
        default:
            std::string s_error("could not create param spec for type ");
            s_error += g_type_name(type_column);
            throw Php::Exception(s_error);
    }

    return gtk_value;

}