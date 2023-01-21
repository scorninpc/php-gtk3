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
        // gtk_init (0, NULL);

        // GObject
        Php::Class<GObject_> gobject("GObject");
            gobject.method<&GObject_::connect>("connect");
            gobject.method<&GObject_::connect_after>("connect_after");
            gobject.method<&GObject_::handler_disconnect>("handler_disconnect");
            gobject.method<&GObject_::get_property>("get_property");
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
        
// ----- ENUMS 
        // GdkByteOrder
        Php::Class<Php::Base> gdkbyteorder("GdkByteOrder");
            gdkbyteorder.constant("LSB_FIRST", GDK_LSB_FIRST);
            gdkbyteorder.constant("MSB_FIRST", GDK_MSB_FIRST);

        // GdkVisualType
        Php::Class<Php::Base> gdkvisualtype("GdkVisualType");
            gdkvisualtype.constant("STATIC_GRAY", GDK_VISUAL_STATIC_GRAY);
            gdkvisualtype.constant("STATIC_GRAYSCALE", GDK_VISUAL_GRAYSCALE);
            gdkvisualtype.constant("STATIC_COLOR", GDK_VISUAL_STATIC_COLOR);
            gdkvisualtype.constant("PSEUDO_COLOR", GDK_VISUAL_PSEUDO_COLOR);
            gdkvisualtype.constant("TRUE_COLOR", GDK_VISUAL_TRUE_COLOR);
            gdkvisualtype.constant("DIRECT_COLOR", GDK_VISUAL_DIRECT_COLOR);
        
        // GdkWindowType
        Php::Class<Php::Base> gdkwindowtype("GdkWindowType");
            gdkwindowtype.constant("ROOT", GDK_WINDOW_ROOT);
            gdkwindowtype.constant("TOPLEVEL", GDK_WINDOW_TOPLEVEL);
            gdkwindowtype.constant("CHILD", GDK_WINDOW_CHILD);
            gdkwindowtype.constant("TEMP", GDK_WINDOW_TEMP);
            gdkwindowtype.constant("FOREIGN", GDK_WINDOW_FOREIGN);
            gdkwindowtype.constant("OFFSCREEN", GDK_WINDOW_OFFSCREEN);
            gdkwindowtype.constant("SUBSURFACE", GDK_WINDOW_SUBSURFACE);

        // GdkWindowWindowClass
        Php::Class<Php::Base> gdkwindowwindowclass("GdkWindowWindowClass");
            gdkwindowwindowclass.constant("INPUT_OUTPUT", GDK_INPUT_OUTPUT);
            gdkwindowwindowclass.constant("INPUT_ONLY", GDK_INPUT_ONLY);
        
        // GdkWindowHints
        Php::Class<Php::Base> gdkwindowhints("GdkWindowHints");
            gdkwindowhints.constant("POS", GDK_HINT_POS);
            gdkwindowhints.constant("MIN_SIZE", GDK_HINT_MIN_SIZE);
            gdkwindowhints.constant("MAX_SIZE", GDK_HINT_MAX_SIZE);
            gdkwindowhints.constant("BASE_SIZE", GDK_HINT_BASE_SIZE);
            gdkwindowhints.constant("ASPECT", GDK_HINT_ASPECT);
            gdkwindowhints.constant("RESIZE_INC", GDK_HINT_RESIZE_INC);
            gdkwindowhints.constant("WIN_GRAVITY", GDK_HINT_WIN_GRAVITY);
            gdkwindowhints.constant("USER_POS", GDK_HINT_USER_POS);
            gdkwindowhints.constant("USER_SIZE", GDK_HINT_USER_SIZE);
        
        // GdkGravity
        Php::Class<Php::Base> gdkgravity("GdkGravity");
            gdkgravity.constant("NORTH_WEST", GDK_GRAVITY_NORTH_WEST);
            gdkgravity.constant("NORTH", GDK_GRAVITY_NORTH);
            gdkgravity.constant("NORTH_EAST", GDK_GRAVITY_NORTH_EAST);
            gdkgravity.constant("WEST", GDK_GRAVITY_WEST);
            gdkgravity.constant("CENTER", GDK_GRAVITY_CENTER);
            gdkgravity.constant("EAST", GDK_GRAVITY_EAST);
            gdkgravity.constant("SOUTH_WEST", GDK_GRAVITY_SOUTH_WEST);
            gdkgravity.constant("SOUTH", GDK_GRAVITY_SOUTH);
            gdkgravity.constant("SOUTH_EAST", GDK_GRAVITY_SOUTH_EAST);
            gdkgravity.constant("STATIC", GDK_GRAVITY_STATIC);

        // GdkAnchorHints
        Php::Class<Php::Base> gdkanchorhints("GdkAnchorHints");
            gdkanchorhints.constant("FLIP_X", GDK_ANCHOR_FLIP_X);
            gdkanchorhints.constant("FLIP_Y", GDK_ANCHOR_FLIP_Y);
            gdkanchorhints.constant("SLIDE_X", GDK_ANCHOR_SLIDE_X);
            gdkanchorhints.constant("SLIDE_Y", GDK_ANCHOR_SLIDE_Y);
            gdkanchorhints.constant("RESIZE_X", GDK_ANCHOR_RESIZE_X);
            gdkanchorhints.constant("RESIZE_Y", GDK_ANCHOR_RESIZE_Y);
            gdkanchorhints.constant("FLIP", GDK_ANCHOR_FLIP);
            gdkanchorhints.constant("SLIDE", GDK_ANCHOR_SLIDE);
            gdkanchorhints.constant("RESIZE", GDK_ANCHOR_RESIZE);

        // GdkWindowEdge
        Php::Class<Php::Base> gdkwindowedge("GdkWindowEdge");
            gdkwindowedge.constant("NORTH_WEST", GDK_WINDOW_EDGE_NORTH_WEST);
            gdkwindowedge.constant("NORTH", GDK_WINDOW_EDGE_NORTH);
            gdkwindowedge.constant("NORTH_EAST", GDK_WINDOW_EDGE_NORTH_EAST);
            gdkwindowedge.constant("WEST", GDK_WINDOW_EDGE_WEST);
            gdkwindowedge.constant("EAST", GDK_WINDOW_EDGE_EAST);
            gdkwindowedge.constant("SOUTH_WEST", GDK_WINDOW_EDGE_SOUTH_WEST);
            gdkwindowedge.constant("SOUTH", GDK_WINDOW_EDGE_SOUTH);
            gdkwindowedge.constant("SOUTH_EAST", GDK_WINDOW_EDGE_SOUTH_EAST);

        // GdkWindowAttributesType
        Php::Class<Php::Base> gdkwindowattributestype("GdkWindowAttributesType");
            gdkwindowattributestype.constant("TITLE", GDK_WA_TITLE);
            gdkwindowattributestype.constant("X", GDK_WA_X);
            gdkwindowattributestype.constant("Y", GDK_WA_Y);
            gdkwindowattributestype.constant("CURSOR", GDK_WA_CURSOR);
            gdkwindowattributestype.constant("VISUAL", GDK_WA_VISUAL);
            gdkwindowattributestype.constant("WMCLASS", GDK_WA_WMCLASS);
            gdkwindowattributestype.constant("NOREDIR", GDK_WA_NOREDIR);
            gdkwindowattributestype.constant("TYPE_HINT", GDK_WA_TYPE_HINT);

        // GdkFullscreenMode
        Php::Class<Php::Base> gdkfullscreenmode("GdkFullscreenMode");
            gdkfullscreenmode.constant("ON_CURRENT_MONITOR", GDK_FULLSCREEN_ON_CURRENT_MONITOR);
            gdkfullscreenmode.constant("ON_ALL_MONITORS", GDK_FULLSCREEN_ON_ALL_MONITORS);

        // GdkFilterReturn
        Php::Class<Php::Base> gdkfilterreturn("GdkFilterReturn");
            gdkfilterreturn.constant("CONTINUE", GDK_FILTER_CONTINUE);
            gdkfilterreturn.constant("TRANSLATE", GDK_FILTER_TRANSLATE);
            gdkfilterreturn.constant("REMOVE", GDK_FILTER_REMOVE);
        
        // GdkModifierIntent
        Php::Class<Php::Base> gdkmodifierintent("GdkModifierIntent");
            gdkmodifierintent.constant("PRIMARY_ACCELERATOR", GDK_MODIFIER_INTENT_PRIMARY_ACCELERATOR);
            gdkmodifierintent.constant("CONTEXT_MENU", GDK_MODIFIER_INTENT_CONTEXT_MENU);
            gdkmodifierintent.constant("EXTEND_SELECTION", GDK_MODIFIER_INTENT_EXTEND_SELECTION);
            gdkmodifierintent.constant("MODIFY_SELECTION", GDK_MODIFIER_INTENT_MODIFY_SELECTION);
            gdkmodifierintent.constant("NO_TEXT_INPUT", GDK_MODIFIER_INTENT_NO_TEXT_INPUT);
            gdkmodifierintent.constant("SHIFT_GROUP", GDK_MODIFIER_INTENT_SHIFT_GROUP);
            gdkmodifierintent.constant("DEFAULT_MOD_MASK", GDK_MODIFIER_INTENT_DEFAULT_MOD_MASK);

        // GdkWMDecoration
        Php::Class<Php::Base> gdkwmdecoration("GdkWMDecoration");
            gdkwmdecoration.constant("ALL", GDK_DECOR_ALL);
            gdkwmdecoration.constant("BORDER", GDK_DECOR_BORDER);
            gdkwmdecoration.constant("RESIZEH", GDK_DECOR_RESIZEH);
            gdkwmdecoration.constant("TITLE", GDK_DECOR_TITLE);
            gdkwmdecoration.constant("MENU", GDK_DECOR_MENU);
            gdkwmdecoration.constant("MINIMIZE", GDK_DECOR_MINIMIZE);
            gdkwmdecoration.constant("MAXIMIZE", GDK_DECOR_MAXIMIZE);

        // GdkWMFunction
        Php::Class<Php::Base> gdkwmfunction("GdkWMFunction");
            gdkwmfunction.constant("ALL", GDK_FUNC_ALL);
            gdkwmfunction.constant("RESIZE", GDK_FUNC_RESIZE);
            gdkwmfunction.constant("MOVE", GDK_FUNC_MOVE);
            gdkwmfunction.constant("MINIMIZE", GDK_FUNC_MINIMIZE);
            gdkwmfunction.constant("MAXIMIZE", GDK_FUNC_MAXIMIZE);
            gdkwmfunction.constant("CLOSE", GDK_FUNC_CLOSE);
        
        // GdkWindow
        Php::Class<GdkWindow_> gdkwindow("GdkWindow");
            gdkwindow.extends(gobject);
            gdkwindow.method<&GdkWindow_::beep>("beep");
            gdkwindow.method<&GdkWindow_::maximize>("maximize");
            gdkwindow.method<&GdkWindow_::get_default_root_window>("get_default_root_window");
            gdkwindow.method<&GdkWindow_::get_window_type>("get_window_type");
            gdkwindow.method<&GdkWindow_::get_children>("get_children");
            gdkwindow.method<&GdkWindow_::get_width>("get_width");
            gdkwindow.method<&GdkWindow_::get_height>("get_height");
        
        // GtkApplication
        Php::Class<GtkApplication_> gtkapplication("GtkApplication");
            gtkapplication.extends(gobject);
            gtkapplication.method<&GtkApplication_::__construct>("__construct");
            gtkapplication.method<&GtkApplication_::add_window>("add_window");
            gtkapplication.method<&GtkApplication_::remove_window>("remove_window");
            gtkapplication.method<&GtkApplication_::get_windows>("get_windows");
            gtkapplication.method<&GtkApplication_::get_window_by_id>("get_window_by_id");
            gtkapplication.method<&GtkApplication_::get_active_window>("get_active_window");
            gtkapplication.method<&GtkApplication_::inhibit>("inhibit");
            gtkapplication.method<&GtkApplication_::uninhibit>("uninhibit");
            gtkapplication.method<&GtkApplication_::is_inhibited>("is_inhibited");
            gtkapplication.method<&GtkApplication_::prefers_app_menu>("prefers_app_menu");
            gtkapplication.method<&GtkApplication_::get_app_menu>("get_app_menu");
            gtkapplication.method<&GtkApplication_::set_app_menu>("set_app_menu");
            gtkapplication.method<&GtkApplication_::get_menubar>("get_menubar");
            gtkapplication.method<&GtkApplication_::set_menubar>("set_menubar");
            gtkapplication.method<&GtkApplication_::get_menu_by_id>("get_menu_by_id");
            gtkapplication.method<&GtkApplication_::add_accelerator>("add_accelerator");
            gtkapplication.method<&GtkApplication_::remove_accelerator>("remove_accelerator");
            gtkapplication.method<&GtkApplication_::list_action_descriptions>("list_action_descriptions");
            gtkapplication.method<&GtkApplication_::get_accels_for_action>("get_accels_for_action");
            gtkapplication.method<&GtkApplication_::set_accels_for_action>("set_accels_for_action");
            gtkapplication.method<&GtkApplication_::get_actions_for_accel>("get_actions_for_accel");
            gtkapplication.method<&GtkApplication_::window_new>("window_new");
        
        // GApplication
        Php::Class<GApplication_> gapplication("GApplication");
            gapplication.extends(gobject);
            gapplication.method<&GApplication_::id_is_valid>("id_is_valid");
            gapplication.method<&GApplication_::__construct>("__construct");
            gapplication.method<&GApplication_::get_application_id>("get_application_id");
            gapplication.method<&GApplication_::set_application_id>("set_application_id");
            gapplication.method<&GApplication_::get_inactivity_timeout>("get_inactivity_timeout");
            gapplication.method<&GApplication_::set_inactivity_timeout>("set_inactivity_timeout");
            gapplication.method<&GApplication_::get_flags>("get_flags");
            gapplication.method<&GApplication_::set_flags>("set_flags");
            gapplication.method<&GApplication_::get_resource_base_path>("get_resource_base_path");
            gapplication.method<&GApplication_::set_resource_base_path>("set_resource_base_path");
            gapplication.method<&GApplication_::get_dbus_connection>("get_dbus_connection");
            gapplication.method<&GApplication_::get_dbus_object_path>("get_dbus_object_path");
            gapplication.method<&GApplication_::set_action_group>("set_action_group");
            gapplication.method<&GApplication_::get_is_registered>("get_is_registered");
            gapplication.method<&GApplication_::get_is_remote>("get_is_remote");
            // gapplication.method<&GApplication_::register>("register");
            gapplication.method<&GApplication_::hold>("hold");
            gapplication.method<&GApplication_::release>("release");
            gapplication.method<&GApplication_::quit>("quit");
            gapplication.method<&GApplication_::activate>("activate");
            gapplication.method<&GApplication_::open>("open");
            gapplication.method<&GApplication_::send_notification>("send_notification");
            gapplication.method<&GApplication_::withdraw_notification>("withdraw_notification");
            gapplication.method<&GApplication_::run>("run");
            gapplication.method<&GApplication_::add_main_option_entries>("add_main_option_entries");
            gapplication.method<&GApplication_::add_main_option>("add_main_option");
            gapplication.method<&GApplication_::add_option_group>("add_option_group");
            gapplication.method<&GApplication_::set_option_context_parameter_string>("set_option_context_parameter_string");
            gapplication.method<&GApplication_::set_option_context_summary>("set_option_context_summary");
            gapplication.method<&GApplication_::set_option_context_description>("set_option_context_description");
            gapplication.method<&GApplication_::set_default>("set_default");
            gapplication.method<&GApplication_::get_default>("get_default");
            gapplication.method<&GApplication_::mark_busy>("mark_busy");
            gapplication.method<&GApplication_::unmark_busy>("unmark_busy");
            gapplication.method<&GApplication_::get_is_busy>("get_is_busy");
            gapplication.method<&GApplication_::bind_busy_property>("bind_busy_property");
            gapplication.method<&GApplication_::unbind_busy_property>("unbind_busy_property");
            gapplication.constant("FLAGS_NONE", G_APPLICATION_FLAGS_NONE);
            gapplication.constant("IS_SERVICE", G_APPLICATION_IS_SERVICE);
            gapplication.constant("IS_LAUNCHER", G_APPLICATION_IS_LAUNCHER);
            gapplication.constant("HANDLES_OPEN", G_APPLICATION_HANDLES_OPEN);
            gapplication.constant("HANDLES_COMMAND_LINE", G_APPLICATION_HANDLES_COMMAND_LINE);
            gapplication.constant("SEND_ENVIRONMENT", G_APPLICATION_SEND_ENVIRONMENT);
            gapplication.constant("NON_UNIQUE", G_APPLICATION_NON_UNIQUE);
            gapplication.constant("CAN_OVERRIDE_APP_ID", G_APPLICATION_CAN_OVERRIDE_APP_ID);
            // gapplication.constant("ALLOW_REPLACEMENT", G_APPLICATION_ALLOW_REPLACEMENT);
            // gapplication.constant("REPLACE", G_APPLICATION_REPLACE);
            
        // GtkApplicationInhibitFlags
        Php::Class<Php::Base> gtkapplicationinhibitflag("GtkApplicationInhibitFlags");
            gtkapplicationinhibitflag.constant("LOGOUT", GTK_APPLICATION_INHIBIT_LOGOUT);
            gtkapplicationinhibitflag.constant("SWITCH", GTK_APPLICATION_INHIBIT_SWITCH);
            gtkapplicationinhibitflag.constant("SUSPEND", GTK_APPLICATION_INHIBIT_SUSPEND);
            gtkapplicationinhibitflag.constant("IDLE", GTK_APPLICATION_INHIBIT_IDLE);

        // GtkWidgetHelpType
        Php::Class<Php::Base> gtkwidgethelptype("GtkWidgetHelpType");
            gtkwidgethelptype.constant("TOOLTIP", GTK_WIDGET_HELP_TOOLTIP);
            gtkwidgethelptype.constant("WHATS_THIS", GTK_WIDGET_HELP_WHATS_THIS);

        // GtkTextDirection
        Php::Class<Php::Base> gtktextdirection("GtkTextDirection");
            gtktextdirection.constant("NONE", GTK_TEXT_DIR_NONE);
            gtktextdirection.constant("LTR", GTK_TEXT_DIR_LTR);
            gtktextdirection.constant("RTL", GTK_TEXT_DIR_RTL);

        // GtkSizeRequestMode
        Php::Class<Php::Base> gtksizerequestmode("GtkSizeRequestMode");
            gtksizerequestmode.constant("HEIGHT_FOR_WIDTH", GTK_SIZE_REQUEST_HEIGHT_FOR_WIDTH);
            gtksizerequestmode.constant("WIDTH_FOR_HEIGHT", GTK_SIZE_REQUEST_WIDTH_FOR_HEIGHT);
            gtksizerequestmode.constant("CONSTANT_SIZE", GTK_SIZE_REQUEST_CONSTANT_SIZE);

        // GtkAlign
        Php::Class<Php::Base> gtkalign("GtkAlign");
            gtkalign.constant("FILL", GTK_ALIGN_FILL);
            gtkalign.constant("START", GTK_ALIGN_START);
            gtkalign.constant("END", GTK_ALIGN_END);
            gtkalign.constant("CENTER", GTK_ALIGN_CENTER);
            gtkalign.constant("BASELINE", GTK_ALIGN_BASELINE);

        // GtkBorderStyle
        Php::Class<Php::Base> gtkborderstyle("GtkBorderStyle");
            gtkborderstyle.constant("NONE", GTK_BORDER_STYLE_NONE);
            gtkborderstyle.constant("SOLID", GTK_BORDER_STYLE_SOLID);
            gtkborderstyle.constant("INSET", GTK_BORDER_STYLE_INSET);
            gtkborderstyle.constant("OUTSET", GTK_BORDER_STYLE_OUTSET);
            gtkborderstyle.constant("HIDDEN", GTK_BORDER_STYLE_HIDDEN);
            gtkborderstyle.constant("DOTTED", GTK_BORDER_STYLE_DOTTED);
            gtkborderstyle.constant("DASHED", GTK_BORDER_STYLE_DASHED);
            gtkborderstyle.constant("DOUBLE", GTK_BORDER_STYLE_DOUBLE);
            gtkborderstyle.constant("GROOVE", GTK_BORDER_STYLE_GROOVE);
            gtkborderstyle.constant("RIDGE", GTK_BORDER_STYLE_RIDGE);

        // GtkJunctionSides
        Php::Class<Php::Base> gtkjunctionsides("GtkJunctionSides");
            gtkjunctionsides.constant("NONE", GTK_JUNCTION_NONE);
            gtkjunctionsides.constant("CORNER_TOPLEFT", GTK_JUNCTION_CORNER_TOPLEFT);
            gtkjunctionsides.constant("CORNER_TOPRIGHT", GTK_JUNCTION_CORNER_TOPRIGHT);
            gtkjunctionsides.constant("CORNER_BOTTOMLEFT", GTK_JUNCTION_CORNER_BOTTOMLEFT);
            gtkjunctionsides.constant("CORNER_BOTTOMRIGHT", GTK_JUNCTION_CORNER_BOTTOMRIGHT);
            gtkjunctionsides.constant("TOP", GTK_JUNCTION_TOP);
            gtkjunctionsides.constant("BOTTOM", GTK_JUNCTION_BOTTOM);
            gtkjunctionsides.constant("LEFT", GTK_JUNCTION_LEFT);
            gtkjunctionsides.constant("RIGHT", GTK_JUNCTION_RIGHT);
        
        // GtkRegionFlags
        Php::Class<Php::Base> gtkregionflags("GtkRegionFlags");
            gtkregionflags.constant("EVEN", GTK_REGION_EVEN);
            gtkregionflags.constant("ODD", GTK_REGION_ODD);
            gtkregionflags.constant("FIRST", GTK_REGION_FIRST);
            gtkregionflags.constant("LAST", GTK_REGION_LAST);
            gtkregionflags.constant("ONLY", GTK_REGION_ONLY);
            gtkregionflags.constant("SORTED", GTK_REGION_SORTED);
        
        // GtkStyleContextPrintFlags
        Php::Class<Php::Base> gtkstylecontextprintflags("GtkStyleContextPrintFlags");
            gtkstylecontextprintflags.constant("NONE", GTK_STYLE_CONTEXT_PRINT_NONE);
            gtkstylecontextprintflags.constant("RECURSE", GTK_STYLE_CONTEXT_PRINT_RECURSE);
            gtkstylecontextprintflags.constant("SHOW_STYLE", GTK_STYLE_CONTEXT_PRINT_SHOW_STYLE);
        
// ----- ENUMS 
        extension.add(std::move(gtkwidgethelptype));
        extension.add(std::move(gtktextdirection));
        extension.add(std::move(gtksizerequestmode));
        extension.add(std::move(gtkalign));
        extension.add(std::move(gtkborderstyle));
        extension.add(std::move(gtkjunctionsides));
        extension.add(std::move(gtkregionflags));
        extension.add(std::move(gtkstylecontextprintflags));

// ----- GDK
        // Gdk
        Php::Class<Gdk_> gdk("Gdk");
            gdk.method<&Gdk_::test_simulate_button>("test_simulate_button");

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
        

        // GdkVisual
        Php::Class<GdkVisual_> gdkvisual("GdkVisual");
            gdkvisual.extends(gobject);
            gdkvisual.method<&GdkVisual_::get_blue_pixel_details>("get_blue_pixel_details");
            gdkvisual.method<&GdkVisual_::get_green_pixel_details>("get_green_pixel_details");
            gdkvisual.method<&GdkVisual_::get_red_pixel_details>("get_red_pixel_details");
            gdkvisual.method<&GdkVisual_::get_depth>("get_depth");
            gdkvisual.method<&GdkVisual_::get_visual_type>("get_visual_type");
            gdkvisual.method<&GdkVisual_::get_screen>("get_screen");
        

        // GdkEvent
        Php::Class<GdkEvent_> gdkevent("GdkEvent");
            // gdkevent.method<&GdkEvent_::__construct>("__construct");
            // gdkevent.method<&GdkEvent_::__get>("__get");
            // gdkevent.property("type", 0);

        // GdkEventButton
        Php::Class<GdkEventButton_> gdkeventbutton("GdkEventButton");
            // gdkevent.method<&GdkEvent_::__construct>("__construct");
            // gdkevent.property("type", 0);

        // GdkScreen
        Php::Class<GdkScreen_> gdkscreen("GdkScreen");
            // gdkevent.method<&GdkEvent_::__construct>("__construct");
            gdkscreen.method<&GdkScreen_::get_rgba_visual>("get_rgba_visual");
            gdkscreen.method<&GdkScreen_::get_window_stack>("get_window_stack");
            gdkscreen.method<&GdkScreen_::get_default>("get_default");

        // GdkDisplay
        Php::Class<GdkDisplay_> gdkdisplay("GdkDisplay");
            gdkdisplay.extends(gobject);
            gdkdisplay.method<&GdkDisplay_::get_default>("get_default");
            gdkdisplay.method<&GdkDisplay_::get_primary_monitor>("get_primary_monitor");
            gdkdisplay.method<&GdkDisplay_::get_default_screen>("get_default_screen");

        // GdkMonitor
        Php::Class<GdkMonitor_> gdkmonitor("GdkMonitor");
            gdkmonitor.extends(gobject);
            gdkmonitor.method<&GdkMonitor_::get_width_mm>("get_width_mm");
            gdkmonitor.method<&GdkMonitor_::get_height_mm>("get_height_mm");
            gdkmonitor.method<&GdkMonitor_::get_workarea>("get_workarea");

        // GdkEventKey
        Php::Class<GdkEventKey_> gdkeventkey("GdkEventKey");

        // GdkEventKey
        Php::Class<Php::Base> gdkeventtype("GdkEventType");
            gdkeventtype.constant("NOTHING",(int) GDK_NOTHING);
            gdkeventtype.constant("DELETE",(int) GDK_DELETE);
            gdkeventtype.constant("DESTROY",(int) GDK_DESTROY);
            gdkeventtype.constant("EXPOSE",(int) GDK_EXPOSE);
            gdkeventtype.constant("MOTION_NOTIFY",(int) GDK_MOTION_NOTIFY);
            gdkeventtype.constant("BUTTON_PRESS",(int) GDK_BUTTON_PRESS);
            gdkeventtype.constant("_2BUTTON_PRESS",(int) GDK_2BUTTON_PRESS);
            gdkeventtype.constant("DOUBLE_BUTTON_PRESS",(int) GDK_DOUBLE_BUTTON_PRESS);
            gdkeventtype.constant("_3BUTTON_PRESS",(int) GDK_3BUTTON_PRESS);
            gdkeventtype.constant("TRIPLE_BUTTON_PRESS",(int) GDK_TRIPLE_BUTTON_PRESS);
            gdkeventtype.constant("BUTTON_RELEASE",(int) GDK_BUTTON_RELEASE);
            gdkeventtype.constant("KEY_PRESS",(int) GDK_KEY_PRESS);
            gdkeventtype.constant("KEY_RELEASE",(int) GDK_KEY_RELEASE);
            gdkeventtype.constant("ENTER_NOTIFY",(int) GDK_ENTER_NOTIFY);
            gdkeventtype.constant("LEAVE_NOTIFY",(int) GDK_LEAVE_NOTIFY);
            gdkeventtype.constant("FOCUS_CHANGE",(int) GDK_FOCUS_CHANGE);
            gdkeventtype.constant("CONFIGURE",(int) GDK_CONFIGURE);
            gdkeventtype.constant("MAP",(int) GDK_MAP);
            gdkeventtype.constant("UNMAP",(int) GDK_UNMAP);
            gdkeventtype.constant("PROPERTY_NOTIFY",(int) GDK_PROPERTY_NOTIFY);
            gdkeventtype.constant("SELECTION_CLEAR",(int) GDK_SELECTION_CLEAR);
            gdkeventtype.constant("SELECTION_REQUEST",(int) GDK_SELECTION_REQUEST);
            gdkeventtype.constant("SELECTION_NOTIFY",(int) GDK_SELECTION_NOTIFY);
            gdkeventtype.constant("PROXIMITY_IN",(int) GDK_PROXIMITY_IN);
            gdkeventtype.constant("PROXIMITY_OUT",(int) GDK_PROXIMITY_OUT);
            gdkeventtype.constant("DRAG_ENTER",(int) GDK_DRAG_ENTER);
            gdkeventtype.constant("DRAG_LEAVE",(int) GDK_DRAG_LEAVE);
            gdkeventtype.constant("DRAG_MOTION",(int) GDK_DRAG_MOTION);
            gdkeventtype.constant("DRAG_STATUS",(int) GDK_DRAG_STATUS);
            gdkeventtype.constant("DROP_START",(int) GDK_DROP_START);
            gdkeventtype.constant("DROP_FINISHED",(int) GDK_DROP_FINISHED);
            gdkeventtype.constant("CLIENT_EVENT",(int) GDK_CLIENT_EVENT);
            gdkeventtype.constant("VISIBILITY_NOTIFY",(int) GDK_VISIBILITY_NOTIFY);
            gdkeventtype.constant("SCROLL",(int) GDK_SCROLL);
            gdkeventtype.constant("WINDOW_STATE",(int) GDK_WINDOW_STATE);
            gdkeventtype.constant("SETTING",(int) GDK_SETTING);
            gdkeventtype.constant("OWNER_CHANGE",(int) GDK_OWNER_CHANGE);
            gdkeventtype.constant("GRAB_BROKEN",(int) GDK_GRAB_BROKEN);
            gdkeventtype.constant("DAMAGE",(int) GDK_DAMAGE);
            gdkeventtype.constant("TOUCH_BEGIN",(int) GDK_TOUCH_BEGIN);
            gdkeventtype.constant("TOUCH_UPDATE",(int) GDK_TOUCH_UPDATE);
            gdkeventtype.constant("TOUCH_END",(int) GDK_TOUCH_END);
            gdkeventtype.constant("TOUCH_CANCEL",(int) GDK_TOUCH_CANCEL);
            gdkeventtype.constant("TOUCHPAD_SWIPE",(int) GDK_TOUCHPAD_SWIPE);
            gdkeventtype.constant("TOUCHPAD_PINCH",(int) GDK_TOUCHPAD_PINCH);
            gdkeventtype.constant("PAD_BUTTON_PRESS",(int) GDK_PAD_BUTTON_PRESS);
            gdkeventtype.constant("PAD_BUTTON_RELEASE",(int) GDK_PAD_BUTTON_RELEASE);
            gdkeventtype.constant("PAD_RING",(int) GDK_PAD_RING);
            gdkeventtype.constant("PAD_STRIP",(int) GDK_PAD_STRIP);
            gdkeventtype.constant("PAD_GROUP_MODE",(int) GDK_PAD_GROUP_MODE);
            gdkeventtype.constant("EVENT_LAST",(int) GDK_EVENT_LAST);
        

        // GdkPixbuf
        Php::Class<GdkPixbuf_> gdkpixbuf("GdkPixbuf");
            gdkpixbuf.method<&GdkPixbuf_::__construct>("__construct");
            gdkpixbuf.method<&GdkPixbuf_::new_from_file>("new_from_file");
            gdkpixbuf.method<&GdkPixbuf_::new_from_file_at_size>("new_from_file_at_size");
            gdkpixbuf.method<&GdkPixbuf_::new_from_file_at_scale>("new_from_file_at_scale");
            gdkpixbuf.method<&GdkPixbuf_::new_from_gd>("new_from_gd");
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
            gdkpixbuf.method<&GdkPixbuf_::get_from_drawable>("get_from_drawable");
            gdkpixbuf.method<&GdkPixbuf_::scale_simple>("scale_simple");
        
        // GdkEventKey
        Php::Class<Php::Base> gdkinterptype("GdkInterpType");
            gdkinterptype.constant("NEAREST",(int) GDK_INTERP_NEAREST);
            gdkinterptype.constant("TILES",(int) GDK_INTERP_TILES);
            gdkinterptype.constant("BILINEAR",(int) GDK_INTERP_BILINEAR);
            gdkinterptype.constant("HYPER",(int) GDK_INTERP_HYPER);

        // GdkDrawable
        Php::Class<GdkDrawable_> gdkdrawable("GdkDrawable");
            // gdkdrawable.method<&GdkDrawable_::parse>("parse");
            // gdkdrawable.method<&GdkDrawable_::to_string>("to_string");

        // GdkRGBA
        Php::Class<GdkRGBA_> gdkrgba("GdkRGBA");
            gdkrgba.method<&GdkRGBA_::parse>("parse");
            gdkrgba.method<&GdkRGBA_::to_string>("to_string");
            

        // GdkPixbufFormat
        Php::Class<GdkPixbufFormat_> gdkpixbufformat("GdkPixbufFormat");


        // GdkPixbufAlphaMode
        Php::Class<Php::Base> gdkpixbufalphamode("GdkPixbufAlphaMode");
            gdkpixbufalphamode.constant("BILEVEL", (int)GDK_PIXBUF_ALPHA_BILEVEL);
            gdkpixbufalphamode.constant("FULL", (int)GDK_PIXBUF_ALPHA_FULL);

        // GdkModifierType
        Php::Class<Php::Base> gdkmodifiertype("GdkModifierType");
            gdkmodifiertype.constant("SHIFT_MASK", GDK_SHIFT_MASK);
            gdkmodifiertype.constant("LOCK_MASK", GDK_LOCK_MASK);
            gdkmodifiertype.constant("CONTROL_MASK", GDK_CONTROL_MASK);
            gdkmodifiertype.constant("MOD1_MASK", GDK_MOD1_MASK);
            gdkmodifiertype.constant("MOD2_MASK", GDK_MOD2_MASK);
            gdkmodifiertype.constant("MOD3_MASK", GDK_MOD3_MASK);
            gdkmodifiertype.constant("MOD4_MASK", GDK_MOD4_MASK);
            gdkmodifiertype.constant("MOD5_MASK", GDK_MOD5_MASK);
            gdkmodifiertype.constant("BUTTON1_MASK", GDK_BUTTON1_MASK);
            gdkmodifiertype.constant("BUTTON2_MASK", GDK_BUTTON2_MASK);
            gdkmodifiertype.constant("BUTTON3_MASK", GDK_BUTTON3_MASK);
            gdkmodifiertype.constant("BUTTON4_MASK", GDK_BUTTON4_MASK);
            gdkmodifiertype.constant("BUTTON5_MASK", GDK_BUTTON5_MASK);
            gdkmodifiertype.constant("RESERVED_13_MASK", GDK_MODIFIER_RESERVED_13_MASK);
            gdkmodifiertype.constant("RESERVED_14_MASK", GDK_MODIFIER_RESERVED_14_MASK);
            gdkmodifiertype.constant("RESERVED_15_MASK", GDK_MODIFIER_RESERVED_15_MASK);
            gdkmodifiertype.constant("RESERVED_16_MASK", GDK_MODIFIER_RESERVED_16_MASK);
            gdkmodifiertype.constant("RESERVED_17_MASK", GDK_MODIFIER_RESERVED_17_MASK);
            gdkmodifiertype.constant("RESERVED_18_MASK", GDK_MODIFIER_RESERVED_18_MASK);
            gdkmodifiertype.constant("RESERVED_19_MASK", GDK_MODIFIER_RESERVED_19_MASK);
            gdkmodifiertype.constant("RESERVED_20_MASK", GDK_MODIFIER_RESERVED_20_MASK);
            gdkmodifiertype.constant("RESERVED_21_MASK", GDK_MODIFIER_RESERVED_21_MASK);
            gdkmodifiertype.constant("RESERVED_22_MASK", GDK_MODIFIER_RESERVED_22_MASK);
            gdkmodifiertype.constant("RESERVED_23_MASK", GDK_MODIFIER_RESERVED_23_MASK);
            gdkmodifiertype.constant("RESERVED_24_MASK", GDK_MODIFIER_RESERVED_24_MASK);
            gdkmodifiertype.constant("RESERVED_25_MASK", GDK_MODIFIER_RESERVED_25_MASK);
            gdkmodifiertype.constant("RESERVED_29_MASK", GDK_MODIFIER_RESERVED_29_MASK);
            gdkmodifiertype.constant("SUPER_MASK", GDK_SUPER_MASK);
            gdkmodifiertype.constant("HYPER_MASK", GDK_HYPER_MASK);
            gdkmodifiertype.constant("META_MASK", GDK_META_MASK);
            gdkmodifiertype.constant("RELEASE_MASK", GDK_RELEASE_MASK);
            gdkmodifiertype.constant("MODIFIER_MASK", GDK_MODIFIER_MASK);

        // GdkColorspace
        Php::Class<Php::Base> gdkcolorspace("GdkColorspace");
            gdkcolorspace.constant("RGB", (int)GDK_COLORSPACE_RGB);


        // Gtk
        Php::Class<Gtk_> gtk("Gtk");
            gtk.method<&Gtk_::init>("init");
            gtk.method<&Gtk_::main>("main");
            gtk.method<&Gtk_::main_quit>("main_quit");
            gtk.method<&Gtk_::timeout_add>("timeout_add");
            gtk.method<&Gtk_::events_pending>("events_pending");
            gtk.method<&Gtk_::main_iteration>("main_iteration");
            
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
        Php::Class<Php::Base> gtkorientation("GtkOrientation");
            gtkorientation.constant("HORIZONTAL", GTK_ORIENTATION_HORIZONTAL);
            gtkorientation.constant("VERTICAL", GTK_ORIENTATION_VERTICAL);
        

        // GtkPolicyType
        Php::Class<Php::Base> gtkpolicytype("GtkPolicyType");
            gtkpolicytype.constant("ALWAYS", GTK_POLICY_ALWAYS);
            gtkpolicytype.constant("AUTOMATIC", GTK_POLICY_AUTOMATIC);
            gtkpolicytype.constant("NEVER", GTK_POLICY_NEVER);
            gtkpolicytype.constant("EXTERNAL", GTK_POLICY_EXTERNAL);
        

        // GtkWidget
        Php::Class<GtkWidget_> gtkwidget("GtkWidget");
            gtkwidget.extends(gobject);
            gtkwidget.method<&GtkWidget_::__construct>("__construct");
            gtkwidget.method<&GtkWidget_::destroy>("destroy");
            gtkwidget.method<&GtkWidget_::in_destruction>("in_destruction");
            gtkwidget.method<&GtkWidget_::destroyed>("destroyed");
            gtkwidget.method<&GtkWidget_::unparent>("unparent");
            gtkwidget.method<&GtkWidget_::show>("show");
            gtkwidget.method<&GtkWidget_::show_now>("show_now");
            gtkwidget.method<&GtkWidget_::hide>("hide");
            gtkwidget.method<&GtkWidget_::show_all>("show_all");
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
            gtkwidget.method<&GtkWidget_::add_tick_callback>("add_tick_callback");
            gtkwidget.method<&GtkWidget_::remove_tick_callback>("remove_tick_callback");
            gtkwidget.method<&GtkWidget_::size_request>("size_request");
            gtkwidget.method<&GtkWidget_::get_child_requisition>("get_child_requisition");
            gtkwidget.method<&GtkWidget_::size_allocate>("size_allocate");
            gtkwidget.method<&GtkWidget_::size_allocate_with_baseline>("size_allocate_with_baseline");
            gtkwidget.method<&GtkWidget_::add_accelerator>("add_accelerator");
            gtkwidget.method<&GtkWidget_::remove_accelerator>("remove_accelerator");
            gtkwidget.method<&GtkWidget_::set_accel_path>("set_accel_path");
            gtkwidget.method<&GtkWidget_::list_accel_closures>("list_accel_closures");
            gtkwidget.method<&GtkWidget_::can_activate_accel>("can_activate_accel");
            gtkwidget.method<&GtkWidget_::event>("event");
            gtkwidget.method<&GtkWidget_::activate>("activate");
            gtkwidget.method<&GtkWidget_::reparent>("reparent");
            gtkwidget.method<&GtkWidget_::intersect>("intersect");
            gtkwidget.method<&GtkWidget_::is_focus>("is_focus");
            gtkwidget.method<&GtkWidget_::grab_focus>("grab_focus");
            gtkwidget.method<&GtkWidget_::grab_default>("grab_default");
            gtkwidget.method<&GtkWidget_::set_name>("set_name");
            gtkwidget.method<&GtkWidget_::get_name>("get_name");
            gtkwidget.method<&GtkWidget_::set_state>("set_state");
            gtkwidget.method<&GtkWidget_::set_sensitive>("set_sensitive");
            gtkwidget.method<&GtkWidget_::set_parent>("set_parent");
            gtkwidget.method<&GtkWidget_::set_parent_window>("set_parent_window");
            gtkwidget.method<&GtkWidget_::get_parent_window>("get_parent_window");
            gtkwidget.method<&GtkWidget_::set_events>("set_events");
            gtkwidget.method<&GtkWidget_::get_events>("get_events");
            gtkwidget.method<&GtkWidget_::add_events>("add_events");
            gtkwidget.method<&GtkWidget_::set_device_events>("set_device_events");
            gtkwidget.method<&GtkWidget_::get_device_events>("get_device_events");
            gtkwidget.method<&GtkWidget_::add_device_events>("add_device_events");
            gtkwidget.method<&GtkWidget_::set_device_enabled>("set_device_enabled");
            gtkwidget.method<&GtkWidget_::get_device_enabled>("get_device_enabled");
            gtkwidget.method<&GtkWidget_::get_toplevel>("get_toplevel");
            gtkwidget.method<&GtkWidget_::get_ancestor>("get_ancestor");
            gtkwidget.method<&GtkWidget_::get_visual>("get_visual");
            gtkwidget.method<&GtkWidget_::set_visual>("set_visual");
            gtkwidget.method<&GtkWidget_::get_pointer>("get_pointer");
            gtkwidget.method<&GtkWidget_::is_ancestor>("is_ancestor");
            gtkwidget.method<&GtkWidget_::translate_coordinates>("translate_coordinates");
            gtkwidget.method<&GtkWidget_::hide_on_delete>("hide_on_delete");
            gtkwidget.method<&GtkWidget_::set_style>("set_style");
            gtkwidget.method<&GtkWidget_::ensure_style>("ensure_style");
            gtkwidget.method<&GtkWidget_::get_style>("get_style");
            gtkwidget.method<&GtkWidget_::reset_rc_styles>("reset_rc_styles");
            gtkwidget.method<&GtkWidget_::get_default_style>("get_default_style");
            gtkwidget.method<&GtkWidget_::set_direction>("set_direction");
            gtkwidget.method<&GtkWidget_::get_direction>("get_direction");
            gtkwidget.method<&GtkWidget_::set_default_direction>("set_default_direction");
            gtkwidget.method<&GtkWidget_::get_default_direction>("get_default_direction");
            gtkwidget.method<&GtkWidget_::shape_combine_region>("shape_combine_region");
            gtkwidget.method<&GtkWidget_::input_shape_combine_region>("input_shape_combine_region");
            gtkwidget.method<&GtkWidget_::path>("path");
            gtkwidget.method<&GtkWidget_::class_path>("class_path");
            gtkwidget.method<&GtkWidget_::get_composite_name>("get_composite_name");
            gtkwidget.method<&GtkWidget_::override_background_color>("override_background_color");
            gtkwidget.method<&GtkWidget_::override_color>("override_color");
            gtkwidget.method<&GtkWidget_::override_font>("override_font");
            gtkwidget.method<&GtkWidget_::override_symbolic_color>("override_symbolic_color");
            gtkwidget.method<&GtkWidget_::override_cursor>("override_cursor");
            gtkwidget.method<&GtkWidget_::modify_style>("modify_style");
            gtkwidget.method<&GtkWidget_::get_modifier_style>("get_modifier_style");
            gtkwidget.method<&GtkWidget_::modify_fg>("modify_fg");
            gtkwidget.method<&GtkWidget_::modify_bg>("modify_bg");
            gtkwidget.method<&GtkWidget_::modify_text>("modify_text");
            gtkwidget.method<&GtkWidget_::modify_base>("modify_base");
            gtkwidget.method<&GtkWidget_::modify_font>("modify_font");
            gtkwidget.method<&GtkWidget_::modify_cursor>("modify_cursor");
            gtkwidget.method<&GtkWidget_::create_pango_context>("create_pango_context");
            gtkwidget.method<&GtkWidget_::get_pango_context>("get_pango_context");
            gtkwidget.method<&GtkWidget_::set_font_options>("set_font_options");
            gtkwidget.method<&GtkWidget_::set_font_map>("set_font_map");
            gtkwidget.method<&GtkWidget_::get_font_map>("get_font_map");
            gtkwidget.method<&GtkWidget_::create_pango_layout>("create_pango_layout");
            gtkwidget.method<&GtkWidget_::render_icon>("render_icon");
            gtkwidget.method<&GtkWidget_::render_icon_pixbuf>("render_icon_pixbuf");
            gtkwidget.method<&GtkWidget_::pop_composite_child>("pop_composite_child");
            gtkwidget.method<&GtkWidget_::push_composite_child>("push_composite_child");
            gtkwidget.method<&GtkWidget_::queue_draw_area>("queue_draw_area");
            gtkwidget.method<&GtkWidget_::queue_draw_region>("queue_draw_region");
            gtkwidget.method<&GtkWidget_::set_app_paintable>("set_app_paintable");
            gtkwidget.method<&GtkWidget_::set_double_buffered>("set_double_buffered");
            gtkwidget.method<&GtkWidget_::set_redraw_on_allocate>("set_redraw_on_allocate");
            gtkwidget.method<&GtkWidget_::set_composite_name>("set_composite_name");
            gtkwidget.method<&GtkWidget_::mnemonic_activate>("mnemonic_activate");
            gtkwidget.method<&GtkWidget_::class_install_style_property>("class_install_style_property");
            gtkwidget.method<&GtkWidget_::class_install_style_property_parser>("class_install_style_property_parser");
            gtkwidget.method<&GtkWidget_::class_find_style_property>("class_find_style_property");
            gtkwidget.method<&GtkWidget_::class_list_style_properties>("class_list_style_properties");
            gtkwidget.method<&GtkWidget_::send_expose>("send_expose");
            gtkwidget.method<&GtkWidget_::send_focus_change>("send_focus_change");
            gtkwidget.method<&GtkWidget_::style_get>("style_get");
            gtkwidget.method<&GtkWidget_::style_get_property>("style_get_property");
            gtkwidget.method<&GtkWidget_::style_get_valist>("style_get_valist");
            gtkwidget.method<&GtkWidget_::style_attach>("style_attach");
            gtkwidget.method<&GtkWidget_::class_set_accessible_type>("class_set_accessible_type");
            gtkwidget.method<&GtkWidget_::class_set_accessible_role>("class_set_accessible_role");
            gtkwidget.method<&GtkWidget_::get_accessible>("get_accessible");
            gtkwidget.method<&GtkWidget_::child_focus>("child_focus");
            gtkwidget.method<&GtkWidget_::child_notify>("child_notify");
            gtkwidget.method<&GtkWidget_::freeze_child_notify>("freeze_child_notify");
            gtkwidget.method<&GtkWidget_::get_child_visible>("get_child_visible");
            gtkwidget.method<&GtkWidget_::get_parent>("get_parent");
            gtkwidget.method<&GtkWidget_::get_settings>("get_settings");
            gtkwidget.method<&GtkWidget_::get_clipboard>("get_clipboard");
            gtkwidget.method<&GtkWidget_::get_display>("get_display");
            gtkwidget.method<&GtkWidget_::get_root_window>("get_root_window");
            gtkwidget.method<&GtkWidget_::get_screen>("get_screen");
            gtkwidget.method<&GtkWidget_::has_screen>("has_screen");
            gtkwidget.method<&GtkWidget_::get_size_request>("get_size_request");
            gtkwidget.method<&GtkWidget_::set_child_visible>("set_child_visible");
            gtkwidget.method<&GtkWidget_::set_size_request>("set_size_request");
            gtkwidget.method<&GtkWidget_::thaw_child_notify>("thaw_child_notify");
            gtkwidget.method<&GtkWidget_::set_no_show_all>("set_no_show_all");
            gtkwidget.method<&GtkWidget_::get_no_show_all>("get_no_show_all");
            gtkwidget.method<&GtkWidget_::list_mnemonic_labels>("list_mnemonic_labels");
            gtkwidget.method<&GtkWidget_::add_mnemonic_label>("add_mnemonic_label");
            gtkwidget.method<&GtkWidget_::remove_mnemonic_label>("remove_mnemonic_label");
            gtkwidget.method<&GtkWidget_::is_composited>("is_composited");
            gtkwidget.method<&GtkWidget_::error_bell>("error_bell");
            gtkwidget.method<&GtkWidget_::keynav_failed>("keynav_failed");
            gtkwidget.method<&GtkWidget_::get_tooltip_markup>("get_tooltip_markup");
            gtkwidget.method<&GtkWidget_::set_tooltip_markup>("set_tooltip_markup");
            gtkwidget.method<&GtkWidget_::get_tooltip_text>("get_tooltip_text");
            gtkwidget.method<&GtkWidget_::set_tooltip_text>("set_tooltip_text");
            gtkwidget.method<&GtkWidget_::get_tooltip_window>("get_tooltip_window");
            gtkwidget.method<&GtkWidget_::set_tooltip_window>("set_tooltip_window");
            gtkwidget.method<&GtkWidget_::get_has_tooltip>("get_has_tooltip");
            gtkwidget.method<&GtkWidget_::set_has_tooltip>("set_has_tooltip");
            gtkwidget.method<&GtkWidget_::trigger_tooltip_query>("trigger_tooltip_query");
            gtkwidget.method<&GtkWidget_::get_window>("get_window");
            gtkwidget.method<&GtkWidget_::register_window>("register_window");
            gtkwidget.method<&GtkWidget_::unregister_window>("unregister_window");
            gtkwidget.method<&GtkWidget_::gtk_cairo_should_draw_window>("gtk_cairo_should_draw_window");
            gtkwidget.method<&GtkWidget_::gtk_cairo_transform_to_window>("gtk_cairo_transform_to_window");
            gtkwidget.method<&GtkWidget_::get_allocated_width>("get_allocated_width");
            gtkwidget.method<&GtkWidget_::get_allocated_height>("get_allocated_height");
            gtkwidget.method<&GtkWidget_::get_allocation>("get_allocation");
            gtkwidget.method<&GtkWidget_::set_allocation>("set_allocation");
            gtkwidget.method<&GtkWidget_::get_allocated_baseline>("get_allocated_baseline");
            gtkwidget.method<&GtkWidget_::get_allocated_size>("get_allocated_size");
            gtkwidget.method<&GtkWidget_::get_clip>("get_clip");
            gtkwidget.method<&GtkWidget_::set_clip>("set_clip");
            gtkwidget.method<&GtkWidget_::get_app_paintable>("get_app_paintable");
            gtkwidget.method<&GtkWidget_::get_can_default>("get_can_default");
            gtkwidget.method<&GtkWidget_::set_can_default>("set_can_default");
            gtkwidget.method<&GtkWidget_::get_can_focus>("get_can_focus");
            gtkwidget.method<&GtkWidget_::set_can_focus>("set_can_focus");
            gtkwidget.method<&GtkWidget_::get_focus_on_click>("get_focus_on_click");
            gtkwidget.method<&GtkWidget_::set_focus_on_click>("set_focus_on_click");
            gtkwidget.method<&GtkWidget_::get_double_buffered>("get_double_buffered");
            gtkwidget.method<&GtkWidget_::get_has_window>("get_has_window");
            gtkwidget.method<&GtkWidget_::set_has_window>("set_has_window");
            gtkwidget.method<&GtkWidget_::get_sensitive>("get_sensitive");
            gtkwidget.method<&GtkWidget_::is_sensitive>("is_sensitive");
            gtkwidget.method<&GtkWidget_::get_state>("get_state");
            gtkwidget.method<&GtkWidget_::get_visible>("get_visible");
            gtkwidget.method<&GtkWidget_::is_visible>("is_visible");
            gtkwidget.method<&GtkWidget_::set_visible>("set_visible");
            gtkwidget.method<&GtkWidget_::set_state_flags>("set_state_flags");
            gtkwidget.method<&GtkWidget_::unset_state_flags>("unset_state_flags");
            gtkwidget.method<&GtkWidget_::get_state_flags>("get_state_flags");
            gtkwidget.method<&GtkWidget_::has_default>("has_default");
            gtkwidget.method<&GtkWidget_::has_focus>("has_focus");
            gtkwidget.method<&GtkWidget_::has_visible_focus>("has_visible_focus");
            gtkwidget.method<&GtkWidget_::has_grab>("has_grab");
            gtkwidget.method<&GtkWidget_::has_rc_style>("has_rc_style");
            gtkwidget.method<&GtkWidget_::is_drawable>("is_drawable");
            gtkwidget.method<&GtkWidget_::is_toplevel>("is_toplevel");
            gtkwidget.method<&GtkWidget_::set_window>("set_window");
            gtkwidget.method<&GtkWidget_::set_receives_default>("set_receives_default");
            gtkwidget.method<&GtkWidget_::get_receives_default>("get_receives_default");
            gtkwidget.method<&GtkWidget_::set_support_multidevice>("set_support_multidevice");
            gtkwidget.method<&GtkWidget_::get_support_multidevice>("get_support_multidevice");
            gtkwidget.method<&GtkWidget_::set_realized>("set_realized");
            gtkwidget.method<&GtkWidget_::get_realized>("get_realized");
            gtkwidget.method<&GtkWidget_::set_mapped>("set_mapped");
            gtkwidget.method<&GtkWidget_::get_mapped>("get_mapped");
            gtkwidget.method<&GtkWidget_::get_requisition>("get_requisition");
            gtkwidget.method<&GtkWidget_::device_is_shadowed>("device_is_shadowed");
            gtkwidget.method<&GtkWidget_::get_modifier_mask>("get_modifier_mask");
            gtkwidget.method<&GtkWidget_::insert_action_group>("insert_action_group");
            gtkwidget.method<&GtkWidget_::get_opacity>("get_opacity");
            gtkwidget.method<&GtkWidget_::set_opacity>("set_opacity");
            gtkwidget.method<&GtkWidget_::list_action_prefixes>("list_action_prefixes");
            gtkwidget.method<&GtkWidget_::get_action_group>("get_action_group");
            gtkwidget.method<&GtkWidget_::get_path>("get_path");
            gtkwidget.method<&GtkWidget_::get_style_context>("get_style_context");
            gtkwidget.method<&GtkWidget_::reset_style>("reset_style");
            gtkwidget.method<&GtkWidget_::class_get_css_name>("class_get_css_name");
            gtkwidget.method<&GtkWidget_::class_set_css_name>("class_set_css_name");
            gtkwidget.method<&GtkWidget_::gtk_requisition_new>("gtk_requisition_new");
            gtkwidget.method<&GtkWidget_::gtk_requisition_copy>("gtk_requisition_copy");
            gtkwidget.method<&GtkWidget_::gtk_requisition_free>("gtk_requisition_free");
            gtkwidget.method<&GtkWidget_::get_preferred_height>("get_preferred_height");
            gtkwidget.method<&GtkWidget_::get_preferred_width>("get_preferred_width");
            gtkwidget.method<&GtkWidget_::get_preferred_height_for_width>("get_preferred_height_for_width");
            gtkwidget.method<&GtkWidget_::get_preferred_width_for_height>("get_preferred_width_for_height");
            gtkwidget.method<&GtkWidget_::get_preferred_height_and_baseline_for_width>("get_preferred_height_and_baseline_for_width");
            gtkwidget.method<&GtkWidget_::get_request_mode>("get_request_mode");
            gtkwidget.method<&GtkWidget_::get_preferred_size>("get_preferred_size");
            gtkwidget.method<&GtkWidget_::gtk_distribute_natural_allocation>("gtk_distribute_natural_allocation");
            gtkwidget.method<&GtkWidget_::get_halign>("get_halign");
            gtkwidget.method<&GtkWidget_::set_halign>("set_halign");
            gtkwidget.method<&GtkWidget_::get_valign>("get_valign");
            gtkwidget.method<&GtkWidget_::get_valign_with_baseline>("get_valign_with_baseline");
            gtkwidget.method<&GtkWidget_::set_valign>("set_valign");
            gtkwidget.method<&GtkWidget_::get_margin_left>("get_margin_left");
            gtkwidget.method<&GtkWidget_::set_margin_left>("set_margin_left");
            gtkwidget.method<&GtkWidget_::get_margin_right>("get_margin_right");
            gtkwidget.method<&GtkWidget_::set_margin_right>("set_margin_right");
            gtkwidget.method<&GtkWidget_::get_margin_start>("get_margin_start");
            gtkwidget.method<&GtkWidget_::set_margin_start>("set_margin_start");
            gtkwidget.method<&GtkWidget_::get_margin_end>("get_margin_end");
            gtkwidget.method<&GtkWidget_::set_margin_end>("set_margin_end");
            gtkwidget.method<&GtkWidget_::get_margin_top>("get_margin_top");
            gtkwidget.method<&GtkWidget_::set_margin_top>("set_margin_top");
            gtkwidget.method<&GtkWidget_::get_margin_bottom>("get_margin_bottom");
            gtkwidget.method<&GtkWidget_::set_margin_bottom>("set_margin_bottom");
            gtkwidget.method<&GtkWidget_::get_hexpand>("get_hexpand");
            gtkwidget.method<&GtkWidget_::set_hexpand>("set_hexpand");
            gtkwidget.method<&GtkWidget_::get_hexpand_set>("get_hexpand_set");
            gtkwidget.method<&GtkWidget_::set_hexpand_set>("set_hexpand_set");
            gtkwidget.method<&GtkWidget_::get_vexpand>("get_vexpand");
            gtkwidget.method<&GtkWidget_::set_vexpand>("set_vexpand");
            gtkwidget.method<&GtkWidget_::get_vexpand_set>("get_vexpand_set");
            gtkwidget.method<&GtkWidget_::set_vexpand_set>("set_vexpand_set");
            gtkwidget.method<&GtkWidget_::queue_compute_expand>("queue_compute_expand");
            gtkwidget.method<&GtkWidget_::compute_expand>("compute_expand");
            gtkwidget.method<&GtkWidget_::init_template>("init_template");
            gtkwidget.method<&GtkWidget_::class_set_template>("class_set_template");
            gtkwidget.method<&GtkWidget_::class_set_template_from_resource>("class_set_template_from_resource");
            gtkwidget.method<&GtkWidget_::get_template_child>("get_template_child");
            gtkwidget.method<&GtkWidget_::class_bind_template_child_full>("class_bind_template_child_full");
            gtkwidget.method<&GtkWidget_::class_bind_template_callback_full>("class_bind_template_callback_full");
            gtkwidget.method<&GtkWidget_::class_set_connect_func>("class_set_connect_func");
        

        // GtkMisc
        Php::Class<GtkMisc_> gtkmisc("GtkMisc");
            gtkmisc.extends(gtkwidget);

        // GtkContainer
        Php::Class<GtkContainer_> gtkcontainer("GtkContainer");
            gtkcontainer.extends(gtkwidget);
            gtkcontainer.method<&GtkContainer_::add>("add");
            gtkcontainer.method<&GtkContainer_::remove>("remove");
            gtkcontainer.method<&GtkContainer_::add_with_properties>("add_with_properties");
            gtkcontainer.method<&GtkContainer_::get_resize_mode>("get_resize_mode");
            gtkcontainer.method<&GtkContainer_::set_resize_mode>("set_resize_mode");
            gtkcontainer.method<&GtkContainer_::check_resize>("check_resize");
            gtkcontainer.method<&GtkContainer_::foreach>("foreach");
            gtkcontainer.method<&GtkContainer_::get_children>("get_children");
            gtkcontainer.method<&GtkContainer_::get_path_for_child>("get_path_for_child");
            gtkcontainer.method<&GtkContainer_::set_reallocate_redraws>("set_reallocate_redraws");
            gtkcontainer.method<&GtkContainer_::get_focus_child>("get_focus_child");
            gtkcontainer.method<&GtkContainer_::set_focus_child>("set_focus_child");
            gtkcontainer.method<&GtkContainer_::get_focus_vadjustment>("get_focus_vadjustment");
            gtkcontainer.method<&GtkContainer_::set_focus_vadjustment>("set_focus_vadjustment");
            gtkcontainer.method<&GtkContainer_::get_focus_hadjustment>("get_focus_hadjustment");
            gtkcontainer.method<&GtkContainer_::set_focus_hadjustment>("set_focus_hadjustment");
            gtkcontainer.method<&GtkContainer_::resize_children>("resize_children");
            gtkcontainer.method<&GtkContainer_::child_type>("child_type");
            gtkcontainer.method<&GtkContainer_::child_get>("child_get");
            gtkcontainer.method<&GtkContainer_::child_set>("child_set");
            gtkcontainer.method<&GtkContainer_::child_get_property>("child_get_property");
            gtkcontainer.method<&GtkContainer_::child_set_property>("child_set_property");
            gtkcontainer.method<&GtkContainer_::child_get_valist>("child_get_valist");
            gtkcontainer.method<&GtkContainer_::child_set_valist>("child_set_valist");
            gtkcontainer.method<&GtkContainer_::child_notify>("child_notify");
            gtkcontainer.method<&GtkContainer_::child_notify_by_pspec>("child_notify_by_pspec");
            gtkcontainer.method<&GtkContainer_::forall>("forall");
            gtkcontainer.method<&GtkContainer_::get_border_width>("get_border_width");
            gtkcontainer.method<&GtkContainer_::set_border_width>("set_border_width");
            gtkcontainer.method<&GtkContainer_::propagate_draw>("propagate_draw");
            gtkcontainer.method<&GtkContainer_::get_focus_chain>("get_focus_chain");
            gtkcontainer.method<&GtkContainer_::set_focus_chain>("set_focus_chain");
            gtkcontainer.method<&GtkContainer_::unset_focus_chain>("unset_focus_chain");
            gtkcontainer.method<&GtkContainer_::class_find_child_property>("class_find_child_property");
            gtkcontainer.method<&GtkContainer_::class_install_child_property>("class_install_child_property");
            gtkcontainer.method<&GtkContainer_::class_install_child_properties>("class_install_child_properties");
            gtkcontainer.method<&GtkContainer_::class_list_child_properties>("class_list_child_properties");
            gtkcontainer.method<&GtkContainer_::class_handle_border_width>("class_handle_border_width");
        

        // GtkBox
        Php::Class<GtkBox_> gtkbox("GtkBox");
            gtkbox.extends(gtkcontainer);
            gtkbox.method<&GtkBox_::__construct>("__construct");
            gtkbox.method<&GtkBox_::pack_start>("pack_start");
            gtkbox.method<&GtkBox_::pack_end>("pack_end");
            gtkbox.method<&GtkBox_::get_homogeneous>("get_homogeneous");
            gtkbox.method<&GtkBox_::set_homogeneous>("set_homogeneous");
            gtkbox.method<&GtkBox_::get_spacing>("get_spacing");
            gtkbox.method<&GtkBox_::set_spacing>("set_spacing");
            gtkbox.method<&GtkBox_::reorder_child>("reorder_child");
            gtkbox.method<&GtkBox_::query_child_packing>("query_child_packing");
            gtkbox.method<&GtkBox_::set_child_packing>("set_child_packing");
            gtkbox.method<&GtkBox_::get_baseline_position>("get_baseline_position");
            gtkbox.method<&GtkBox_::set_baseline_position>("set_baseline_position");
            gtkbox.method<&GtkBox_::get_center_widget>("get_center_widget");
            gtkbox.method<&GtkBox_::set_center_widget>("set_center_widget");


        // GtkGrid
        Php::Class<GtkGrid_> gtkgrid("GtkGrid");
            gtkgrid.extends(gtkcontainer);
            gtkgrid.method<&GtkGrid_::__construct>("__construct");
            gtkgrid.method<&GtkGrid_::attach>("attach");
            gtkgrid.method<&GtkGrid_::attach_next_to>("attach_next_to");
            gtkgrid.method<&GtkGrid_::get_child_at>("get_child_at");
            gtkgrid.method<&GtkGrid_::insert_row>("insert_row");
            gtkgrid.method<&GtkGrid_::insert_column>("insert_column");
            gtkgrid.method<&GtkGrid_::remove_row>("remove_row");
            gtkgrid.method<&GtkGrid_::remove_column>("remove_column");
            gtkgrid.method<&GtkGrid_::insert_next_to>("insert_next_to");
            gtkgrid.method<&GtkGrid_::set_row_homogeneous>("set_row_homogeneous");
            gtkgrid.method<&GtkGrid_::get_row_homogeneous>("get_row_homogeneous");
            gtkgrid.method<&GtkGrid_::set_row_spacing>("set_row_spacing");
            gtkgrid.method<&GtkGrid_::get_row_spacing>("get_row_spacing");
            gtkgrid.method<&GtkGrid_::set_column_homogeneous>("set_column_homogeneous");
            gtkgrid.method<&GtkGrid_::get_column_homogeneous>("get_column_homogeneous");
            gtkgrid.method<&GtkGrid_::set_column_spacing>("set_column_spacing");
            gtkgrid.method<&GtkGrid_::get_column_spacing>("get_column_spacing");
            gtkgrid.method<&GtkGrid_::set_baseline_row>("set_baseline_row");
            gtkgrid.method<&GtkGrid_::get_baseline_row>("get_baseline_row");
            gtkgrid.method<&GtkGrid_::set_row_baseline_position>("set_row_baseline_position");
            gtkgrid.method<&GtkGrid_::get_row_baseline_position>("get_row_baseline_position");
        

        // GtkFixed
        Php::Class<GtkFixed_> gtkfixed("GtkFixed");
            gtkfixed.extends(gtkcontainer);
            gtkfixed.method<&GtkFixed_::__construct>("__construct");
            gtkfixed.method<&GtkFixed_::put>("put");
            gtkfixed.method<&GtkFixed_::move>("move");
        

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

        // GtkEventBox
        Php::Class<GtkEventBox_> gtkeventbox("GtkEventBox");
            gtkeventbox.extends(gtkbin);
            gtkeventbox.method<&GtkEventBox_::__construct>("__construct");
            gtkeventbox.method<&GtkEventBox_::get_visible_window>("get_visible_window");
            gtkeventbox.method<&GtkEventBox_::set_visible_window>("set_visible_window");
            gtkeventbox.method<&GtkEventBox_::get_above_child>("get_above_child");
            gtkeventbox.method<&GtkEventBox_::set_above_child>("set_above_child");

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
            gtkwindow.method<&GtkWindow_::get_screen>("get_screen");
            gtkwindow.method<&GtkWindow_::list_toplevels>("list_toplevels");
        

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
        
        
        // GtkAppChooserDialog
        Php::Class<GtkAppChooserDialog_> gtkappchooserdialog("GtkAppChooserDialog");
            gtkappchooserdialog.extends(gtkdialog);
            gtkappchooserdialog.method<&GtkAppChooserDialog_::__construc>("__construc");
            gtkappchooserdialog.method<&GtkAppChooserDialog_::new_for_content_type>("new_for_content_type");
            gtkappchooserdialog.method<&GtkAppChooserDialog_::get_widget>("get_widget");
            gtkappchooserdialog.method<&GtkAppChooserDialog_::set_heading>("set_heading");
            gtkappchooserdialog.method<&GtkAppChooserDialog_::get_heading>("get_heading");
            gtkappchooserdialog.method<&GtkAppChooserDialog_::get_app_info>("get_app_info");

        // GtkFileChooser
        // Php::Interface gtkfilechooser("GtkFileChooser");
            // gtkfilechooser.extends(gobject);
            // gtkfilechooser.method("get_filename");
        // extension.add(std::move(gtkfilechooser));

        // Php::Class<GtkFileChooser_> gtkfilechooser("GtkFileChooser");
        //     gtkfilechooser.extends(gobject);
        //     gtkfilechooser.method<&GtkFileChooser_::get_filename>("get_filename");

        // GtkColorChooserDialog
        Php::Class<GtkColorChooserDialog_> gtkcolorchooserdialog("GtkColorChooserDialog");
            gtkcolorchooserdialog.extends(gtkdialog);
            gtkcolorchooserdialog.method<&GtkColorChooserDialog_::__construct>("__construct");
            gtkcolorchooserdialog.method<&GtkColorChooserDialog_::get_rgba>("get_rgba");
            gtkcolorchooserdialog.method<&GtkColorChooserDialog_::set_rgba>("set_rgba");
            gtkcolorchooserdialog.method<&GtkColorChooserDialog_::get_use_alpha>("get_use_alpha");
            gtkcolorchooserdialog.method<&GtkColorChooserDialog_::set_use_alpha>("set_use_alpha");
            gtkcolorchooserdialog.method<&GtkColorChooserDialog_::add_palette>("add_palette");
        

        // GtkPrintSettings
        Php::Class<GtkPrintSettings_> gtkprintsettings("GtkPrintSettings");
            gtkprintsettings.extends(gobject);
            gtkprintsettings.method<&GtkPrintSettings_::__construct>("__construct");
            gtkprintsettings.method<&GtkPrintSettings_::copy>("copy");
            gtkprintsettings.method<&GtkPrintSettings_::has_key>("has_key");
            gtkprintsettings.method<&GtkPrintSettings_::get>("get");
            gtkprintsettings.method<&GtkPrintSettings_::set>("set");
            gtkprintsettings.method<&GtkPrintSettings_::unset>("unset");
            gtkprintsettings.method<&GtkPrintSettings_::foreach>("foreach");
            gtkprintsettings.method<&GtkPrintSettings_::get_bool>("get_bool");
            gtkprintsettings.method<&GtkPrintSettings_::set_bool>("set_bool");
            gtkprintsettings.method<&GtkPrintSettings_::get_double>("get_double");
            gtkprintsettings.method<&GtkPrintSettings_::get_double_with_default>("get_double_with_default");
            gtkprintsettings.method<&GtkPrintSettings_::set_double>("set_double");
            gtkprintsettings.method<&GtkPrintSettings_::get_length>("get_length");
            gtkprintsettings.method<&GtkPrintSettings_::set_length>("set_length");
            gtkprintsettings.method<&GtkPrintSettings_::get_int>("get_int");
            gtkprintsettings.method<&GtkPrintSettings_::get_int_with_default>("get_int_with_default");
            gtkprintsettings.method<&GtkPrintSettings_::set_int>("set_int");
            gtkprintsettings.method<&GtkPrintSettings_::get_printer>("get_printer");
            gtkprintsettings.method<&GtkPrintSettings_::set_printer>("set_printer");
            gtkprintsettings.method<&GtkPrintSettings_::get_orientation>("get_orientation");
            gtkprintsettings.method<&GtkPrintSettings_::set_orientation>("set_orientation");
            gtkprintsettings.method<&GtkPrintSettings_::get_paper_size>("get_paper_size");
            gtkprintsettings.method<&GtkPrintSettings_::set_paper_size>("set_paper_size");
            gtkprintsettings.method<&GtkPrintSettings_::get_paper_width>("get_paper_width");
            gtkprintsettings.method<&GtkPrintSettings_::set_paper_width>("set_paper_width");
            gtkprintsettings.method<&GtkPrintSettings_::get_paper_height>("get_paper_height");
            gtkprintsettings.method<&GtkPrintSettings_::set_paper_height>("set_paper_height");
            gtkprintsettings.method<&GtkPrintSettings_::get_use_color>("get_use_color");
            gtkprintsettings.method<&GtkPrintSettings_::set_use_color>("set_use_color");
            gtkprintsettings.method<&GtkPrintSettings_::get_collate>("get_collate");
            gtkprintsettings.method<&GtkPrintSettings_::set_collate>("set_collate");
            gtkprintsettings.method<&GtkPrintSettings_::get_reverse>("get_reverse");
            gtkprintsettings.method<&GtkPrintSettings_::set_reverse>("set_reverse");
            gtkprintsettings.method<&GtkPrintSettings_::get_duplex>("get_duplex");
            gtkprintsettings.method<&GtkPrintSettings_::set_duplex>("set_duplex");
            gtkprintsettings.method<&GtkPrintSettings_::get_quality>("get_quality");
            gtkprintsettings.method<&GtkPrintSettings_::set_quality>("set_quality");
            gtkprintsettings.method<&GtkPrintSettings_::get_n_copies>("get_n_copies");
            gtkprintsettings.method<&GtkPrintSettings_::set_n_copies>("set_n_copies");
            gtkprintsettings.method<&GtkPrintSettings_::get_number_up>("get_number_up");
            gtkprintsettings.method<&GtkPrintSettings_::set_number_up>("set_number_up");
            gtkprintsettings.method<&GtkPrintSettings_::get_number_up_layout>("get_number_up_layout");
            gtkprintsettings.method<&GtkPrintSettings_::set_number_up_layout>("set_number_up_layout");
            gtkprintsettings.method<&GtkPrintSettings_::get_resolution>("get_resolution");
            gtkprintsettings.method<&GtkPrintSettings_::set_resolution>("set_resolution");
            gtkprintsettings.method<&GtkPrintSettings_::set_resolution_xy>("set_resolution_xy");
            gtkprintsettings.method<&GtkPrintSettings_::get_resolution_x>("get_resolution_x");
            gtkprintsettings.method<&GtkPrintSettings_::get_resolution_y>("get_resolution_y");
            gtkprintsettings.method<&GtkPrintSettings_::get_printer_lpi>("get_printer_lpi");
            gtkprintsettings.method<&GtkPrintSettings_::set_printer_lpi>("set_printer_lpi");
            gtkprintsettings.method<&GtkPrintSettings_::get_scale>("get_scale");
            gtkprintsettings.method<&GtkPrintSettings_::set_scale>("set_scale");
            gtkprintsettings.method<&GtkPrintSettings_::get_print_pages>("get_print_pages");
            gtkprintsettings.method<&GtkPrintSettings_::set_print_pages>("set_print_pages");
            gtkprintsettings.method<&GtkPrintSettings_::get_page_ranges>("get_page_ranges");
            gtkprintsettings.method<&GtkPrintSettings_::set_page_ranges>("set_page_ranges");
            gtkprintsettings.method<&GtkPrintSettings_::get_page_set>("get_page_set");
            gtkprintsettings.method<&GtkPrintSettings_::set_page_set>("set_page_set");
            gtkprintsettings.method<&GtkPrintSettings_::get_default_source>("get_default_source");
            gtkprintsettings.method<&GtkPrintSettings_::set_default_source>("set_default_source");
            gtkprintsettings.method<&GtkPrintSettings_::get_media_type>("get_media_type");
            gtkprintsettings.method<&GtkPrintSettings_::set_media_type>("set_media_type");
            gtkprintsettings.method<&GtkPrintSettings_::get_dither>("get_dither");
            gtkprintsettings.method<&GtkPrintSettings_::set_dither>("set_dither");
            gtkprintsettings.method<&GtkPrintSettings_::get_finishings>("get_finishings");
            gtkprintsettings.method<&GtkPrintSettings_::set_finishings>("set_finishings");
            gtkprintsettings.method<&GtkPrintSettings_::get_output_bin>("get_output_bin");
            gtkprintsettings.method<&GtkPrintSettings_::set_output_bin>("set_output_bin");
            gtkprintsettings.method<&GtkPrintSettings_::new_from_file>("new_from_file");
            gtkprintsettings.method<&GtkPrintSettings_::new_from_key_file>("new_from_key_file");
            gtkprintsettings.method<&GtkPrintSettings_::load_file>("load_file");
            gtkprintsettings.method<&GtkPrintSettings_::load_key_file>("load_key_file");
            gtkprintsettings.method<&GtkPrintSettings_::to_file>("to_file");
            gtkprintsettings.method<&GtkPrintSettings_::to_key_file>("to_key_file");


        // // GtkPageSetupUnixDialog
        // Php::Class<GtkPageSetupUnixDialog_> gtkpagesetupunixdialog("GtkPageSetupUnixDialog");
        //     gtkpagesetupunixdialog.extends(gtkdialog);
        //     gtkpagesetupunixdialog.method<&GtkPageSetupUnixDialog_::__construct>("__construct");
        //     gtkpagesetupunixdialog.method<&GtkPageSetupUnixDialog_::set_page_setup>("set_page_setup");
        //     gtkpagesetupunixdialog.method<&GtkPageSetupUnixDialog_::get_page_setup>("get_page_setup");
        //     gtkpagesetupunixdialog.method<&GtkPageSetupUnixDialog_::set_print_settings>("set_print_settings");
        //     gtkpagesetupunixdialog.method<&GtkPageSetupUnixDialog_::get_print_settings>("get_print_settings");
        


        // GtkPageSetup
        Php::Class<GtkPageSetup_> gtkpagesetup("GtkPageSetup");
            gtkpagesetup.extends(gobject);
            gtkpagesetup.method<&GtkPageSetup_::__construct>("__construct");
            gtkpagesetup.method<&GtkPageSetup_::copy>("copy");
            gtkpagesetup.method<&GtkPageSetup_::get_orientation>("get_orientation");
            gtkpagesetup.method<&GtkPageSetup_::set_orientation>("set_orientation");
            gtkpagesetup.method<&GtkPageSetup_::get_paper_size>("get_paper_size");
            gtkpagesetup.method<&GtkPageSetup_::set_paper_size>("set_paper_size");
            gtkpagesetup.method<&GtkPageSetup_::get_top_margin>("get_top_margin");
            gtkpagesetup.method<&GtkPageSetup_::set_top_margin>("set_top_margin");
            gtkpagesetup.method<&GtkPageSetup_::get_bottom_margin>("get_bottom_margin");
            gtkpagesetup.method<&GtkPageSetup_::set_bottom_margin>("set_bottom_margin");
            gtkpagesetup.method<&GtkPageSetup_::get_left_margin>("get_left_margin");
            gtkpagesetup.method<&GtkPageSetup_::set_left_margin>("set_left_margin");
            gtkpagesetup.method<&GtkPageSetup_::get_right_margin>("get_right_margin");
            gtkpagesetup.method<&GtkPageSetup_::set_right_margin>("set_right_margin");
            gtkpagesetup.method<&GtkPageSetup_::set_paper_size_and_default_margins>("set_paper_size_and_default_margins");
            gtkpagesetup.method<&GtkPageSetup_::get_paper_width>("get_paper_width");
            gtkpagesetup.method<&GtkPageSetup_::get_paper_height>("get_paper_height");
            gtkpagesetup.method<&GtkPageSetup_::get_page_width>("get_page_width");
            gtkpagesetup.method<&GtkPageSetup_::get_page_height>("get_page_height");
            gtkpagesetup.method<&GtkPageSetup_::new_from_file>("new_from_file");
            gtkpagesetup.method<&GtkPageSetup_::new_from_key_file>("new_from_key_file");
            gtkpagesetup.method<&GtkPageSetup_::load_file>("load_file");
            gtkpagesetup.method<&GtkPageSetup_::load_key_file>("load_key_file");
            gtkpagesetup.method<&GtkPageSetup_::to_file>("to_file");
            gtkpagesetup.method<&GtkPageSetup_::to_key_file>("to_key_file");


        // GtkPaperSize
        Php::Class<GtkPaperSize_> gtkpapersize("GtkPaperSize");
            gtkpapersize.extends(gobject);
            gtkpapersize.method<&GtkPaperSize_::__construct>("__construct");
            gtkpapersize.method<&GtkPaperSize_::new_from_ppd>("new_from_ppd");
            gtkpapersize.method<&GtkPaperSize_::new_from_ipp>("new_from_ipp");
            gtkpapersize.method<&GtkPaperSize_::new_custom>("new_custom");
            gtkpapersize.method<&GtkPaperSize_::copy>("copy");
            gtkpapersize.method<&GtkPaperSize_::free>("free");
            gtkpapersize.method<&GtkPaperSize_::is_equal>("is_equal");
            gtkpapersize.method<&GtkPaperSize_::get_paper_sizes>("get_paper_sizes");
            gtkpapersize.method<&GtkPaperSize_::get_name>("get_name");
            gtkpapersize.method<&GtkPaperSize_::get_display_name>("get_display_name");
            gtkpapersize.method<&GtkPaperSize_::get_ppd_name>("get_ppd_name");
            gtkpapersize.method<&GtkPaperSize_::get_width>("get_width");
            gtkpapersize.method<&GtkPaperSize_::get_height>("get_height");
            gtkpapersize.method<&GtkPaperSize_::is_ipp>("is_ipp");
            gtkpapersize.method<&GtkPaperSize_::is_custom>("is_custom");
            gtkpapersize.method<&GtkPaperSize_::set_size>("set_size");
            gtkpapersize.method<&GtkPaperSize_::get_default_top_margin>("get_default_top_margin");
            gtkpapersize.method<&GtkPaperSize_::get_default_bottom_margin>("get_default_bottom_margin");
            gtkpapersize.method<&GtkPaperSize_::get_default_left_margin>("get_default_left_margin");
            gtkpapersize.method<&GtkPaperSize_::get_default_right_margin>("get_default_right_margin");
            gtkpapersize.method<&GtkPaperSize_::get_default>("get_default");
            gtkpapersize.method<&GtkPaperSize_::new_from_key_file>("new_from_key_file");
            gtkpapersize.method<&GtkPaperSize_::to_key_file>("to_key_file");


        // GtkUnit
        Php::Class<Php::Base> gtkunit("GtkUnit");
            gtkunit.constant("NONE", (int)GTK_UNIT_NONE);
            gtkunit.constant("POINTS", (int)GTK_UNIT_POINTS);
            gtkunit.constant("INCH", (int)GTK_UNIT_INCH);
            gtkunit.constant("MM", (int)GTK_UNIT_MM);


        // GtkButton
        Php::Class<GtkButton_> gtkbutton("GtkButton");
            gtkbutton.extends(gtkbin);
            gtkbutton.method<&GtkButton_::__construct>("__construct");
            gtkbutton.method<&GtkButton_::new_with_label>("new_with_label");
            gtkbutton.method<&GtkButton_::new_with_mnemonic>("new_with_mnemonic");
            gtkbutton.method<&GtkButton_::new_from_icon_name>("new_from_icon_name");
            gtkbutton.method<&GtkButton_::new_from_stock>("new_from_stock");
            gtkbutton.method<&GtkButton_::pressed>("pressed");
            gtkbutton.method<&GtkButton_::released>("released");
            gtkbutton.method<&GtkButton_::clicked>("clicked");
            gtkbutton.method<&GtkButton_::enter>("enter");
            gtkbutton.method<&GtkButton_::leave>("leave");
            gtkbutton.method<&GtkButton_::set_relief>("set_relief");
            gtkbutton.method<&GtkButton_::get_relief>("get_relief");
            gtkbutton.method<&GtkButton_::get_label>("get_label");
            gtkbutton.method<&GtkButton_::set_label>("set_label");
            gtkbutton.method<&GtkButton_::get_use_stock>("get_use_stock");
            gtkbutton.method<&GtkButton_::set_use_stock>("set_use_stock");
            gtkbutton.method<&GtkButton_::get_use_underline>("get_use_underline");
            gtkbutton.method<&GtkButton_::set_use_underline>("set_use_underline");
            gtkbutton.method<&GtkButton_::set_focus_on_click>("set_focus_on_click");
            gtkbutton.method<&GtkButton_::get_focus_on_click>("get_focus_on_click");
            gtkbutton.method<&GtkButton_::set_alignment>("set_alignment");
            gtkbutton.method<&GtkButton_::get_alignment>("get_alignment");
            gtkbutton.method<&GtkButton_::set_image>("set_image");
            gtkbutton.method<&GtkButton_::get_image>("get_image");
            gtkbutton.method<&GtkButton_::set_image_position>("set_image_position");
            gtkbutton.method<&GtkButton_::get_image_position>("get_image_position");
            gtkbutton.method<&GtkButton_::set_always_show_image>("set_always_show_image");
            gtkbutton.method<&GtkButton_::get_always_show_image>("get_always_show_image");
            gtkbutton.method<&GtkButton_::get_event_window>("get_event_window");
        
        // GtkColorButton
        Php::Class<GtkColorButton_> gtkcolorbutton("GtkColorButton");
            gtkcolorbutton.extends(gtkbutton);
            gtkcolorbutton.method<&GtkColorButton_::__construct>("__construct");
            gtkcolorbutton.method<&GtkColorButton_::new_with_color>("new_with_color");
            gtkcolorbutton.method<&GtkColorButton_::new_with_rgba>("new_with_rgba");
            gtkcolorbutton.method<&GtkColorButton_::set_color>("set_color");
            gtkcolorbutton.method<&GtkColorButton_::get_color>("get_color");
            gtkcolorbutton.method<&GtkColorButton_::set_alpha>("set_alpha");
            gtkcolorbutton.method<&GtkColorButton_::get_alpha>("get_alpha");
            gtkcolorbutton.method<&GtkColorButton_::set_rgba>("set_rgba");
            gtkcolorbutton.method<&GtkColorButton_::get_rgba>("get_rgba");
            gtkcolorbutton.method<&GtkColorButton_::set_use_alpha>("set_use_alpha");
            gtkcolorbutton.method<&GtkColorButton_::get_use_alpha>("get_use_alpha");
            gtkcolorbutton.method<&GtkColorButton_::set_title>("set_title");
            gtkcolorbutton.method<&GtkColorButton_::get_title>("get_title");

        // GtkFontButton
        Php::Class<GtkFontButton_> gtkfontbutton("GtkFontButton");
            gtkfontbutton.extends(gtkbutton);
            gtkfontbutton.method<&GtkFontButton_::__construct>("__construct");
            gtkfontbutton.method<&GtkFontButton_::new_with_font>("new_with_font");
            gtkfontbutton.method<&GtkFontButton_::set_font_name>("set_font_name");
            gtkfontbutton.method<&GtkFontButton_::set_font>("set_font");
            gtkfontbutton.method<&GtkFontButton_::get_font_name>("get_font_name");
            gtkfontbutton.method<&GtkFontButton_::get_font>("get_font");
            gtkfontbutton.method<&GtkFontButton_::set_show_style>("set_show_style");
            gtkfontbutton.method<&GtkFontButton_::get_show_style>("get_show_style");
            gtkfontbutton.method<&GtkFontButton_::set_show_size>("set_show_size");
            gtkfontbutton.method<&GtkFontButton_::get_show_size>("get_show_size");
            gtkfontbutton.method<&GtkFontButton_::set_use_font>("set_use_font");
            gtkfontbutton.method<&GtkFontButton_::get_use_font>("get_use_font");
            gtkfontbutton.method<&GtkFontButton_::set_use_size>("set_use_size");
            gtkfontbutton.method<&GtkFontButton_::get_use_size>("get_use_size");
            gtkfontbutton.method<&GtkFontButton_::set_title>("set_title");
            gtkfontbutton.method<&GtkFontButton_::get_title>("get_title");

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

        // GtkRadioButton
        Php::Class<GtkRadioButton_> gtkradiobutton("GtkRadioButton");
            gtkradiobutton.extends(gtkcheckbutton);
            gtkradiobutton.method<&GtkRadioButton_::__construct>("__construct");
            gtkradiobutton.method<&GtkRadioButton_::new_from_widget>("new_from_widget");
            gtkradiobutton.method<&GtkRadioButton_::new_with_label>("new_with_label");
            gtkradiobutton.method<&GtkRadioButton_::new_with_label_from_widget>("new_with_label_from_widget");
            gtkradiobutton.method<&GtkRadioButton_::new_with_mnemonic>("new_with_mnemonic");
            gtkradiobutton.method<&GtkRadioButton_::new_with_mnemonic_from_widget>("new_with_mnemonic_from_widget");
            gtkradiobutton.method<&GtkRadioButton_::set_group>("set_group");
            gtkradiobutton.method<&GtkRadioButton_::get_group>("get_group");
            gtkradiobutton.method<&GtkRadioButton_::join_group>("join_group");

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


        // GtkEntryCompletion
        Php::Class<GtkEntryCompletion_> gtkentrycompletion("GtkEntryCompletion");
            gtkentrycompletion.extends(gobject);
            gtkentrycompletion.method<&GtkEntryCompletion_::__construct>("__construct");
            gtkentrycompletion.method<&GtkEntryCompletion_::new_with_area>("new_with_area");
            gtkentrycompletion.method<&GtkEntryCompletion_::get_entry>("get_entry");
            gtkentrycompletion.method<&GtkEntryCompletion_::set_model>("set_model");
            gtkentrycompletion.method<&GtkEntryCompletion_::get_model>("get_model");
            gtkentrycompletion.method<&GtkEntryCompletion_::set_match_func>("set_match_func");
            gtkentrycompletion.method<&GtkEntryCompletion_::set_minimum_key_length>("set_minimum_key_length");
            gtkentrycompletion.method<&GtkEntryCompletion_::get_minimum_key_length>("get_minimum_key_length");
            gtkentrycompletion.method<&GtkEntryCompletion_::compute_prefix>("compute_prefix");
            gtkentrycompletion.method<&GtkEntryCompletion_::complete>("complete");
            gtkentrycompletion.method<&GtkEntryCompletion_::get_completion_prefix>("get_completion_prefix");
            gtkentrycompletion.method<&GtkEntryCompletion_::insert_prefix>("insert_prefix");
            gtkentrycompletion.method<&GtkEntryCompletion_::insert_action_text>("insert_action_text");
            gtkentrycompletion.method<&GtkEntryCompletion_::insert_action_markup>("insert_action_markup");
            gtkentrycompletion.method<&GtkEntryCompletion_::delete_action>("delete_action");
            gtkentrycompletion.method<&GtkEntryCompletion_::set_text_column>("set_text_column");
            gtkentrycompletion.method<&GtkEntryCompletion_::get_text_column>("get_text_column");
            gtkentrycompletion.method<&GtkEntryCompletion_::set_inline_completion>("set_inline_completion");
            gtkentrycompletion.method<&GtkEntryCompletion_::get_inline_completion>("get_inline_completion");
            gtkentrycompletion.method<&GtkEntryCompletion_::set_inline_selection>("set_inline_selection");
            gtkentrycompletion.method<&GtkEntryCompletion_::get_inline_selection>("get_inline_selection");
            gtkentrycompletion.method<&GtkEntryCompletion_::set_popup_completion>("set_popup_completion");
            gtkentrycompletion.method<&GtkEntryCompletion_::get_popup_completion>("get_popup_completion");
            gtkentrycompletion.method<&GtkEntryCompletion_::set_popup_set_width>("set_popup_set_width");
            gtkentrycompletion.method<&GtkEntryCompletion_::get_popup_set_width>("get_popup_set_width");
            gtkentrycompletion.method<&GtkEntryCompletion_::set_popup_single_match>("set_popup_single_match");
            gtkentrycompletion.method<&GtkEntryCompletion_::get_popup_single_match>("get_popup_single_match");
        

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
            gtkentry.method<&GtkEntry_::set_completion>("set_completion");
            gtkentry.method<&GtkEntry_::get_completion>("get_completion");
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
        Php::Class<Php::Base> gtksorttype("GtkSortType");
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
            gtktreeview.method<&GtkTreeView_::get_enable_tree_lines>("get_enable_tree_lines");
            gtktreeview.method<&GtkTreeView_::row_expanded>("row_expanded");
            gtktreeview.method<&GtkTreeView_::collapse_row>("collapse_row");
            gtktreeview.method<&GtkTreeView_::set_reorderable>("set_reorderable");
            gtktreeview.method<&GtkTreeView_::get_reorderable>("get_reorderable");
            gtktreeview.method<&GtkTreeView_::set_enable_search>("set_enable_search");
            gtktreeview.method<&GtkTreeView_::get_enable_search>("get_enable_search");
            gtktreeview.method<&GtkTreeView_::autosize>("autosize");
            gtktreeview.method<&GtkTreeView_::collapse_all>("collapse_all");
            gtktreeview.method<&GtkTreeView_::expand_all>("expand_all");
            gtktreeview.method<&GtkTreeView_::get_n_columns>("get_n_columns");
        

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
            gtktreemodel.extends(gobject);
            gtktreemodel.method<&GtkTreeModel_::__construct>("__construct");
            gtktreemodel.method<&GtkTreeModel_::get_iter>("get_iter");
            gtktreemodel.method<&GtkTreeModel_::get_value>("get_value");
            gtktreemodel.method<&GtkTreeModel_::get_path>("get_path");

        // GtkTreeModelFlags
        Php::Class<Php::Base> gtktreemodelflags("GtkTreeModelFlags");
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
            gtklabel.method<&GtkLabel_::set_ellipsize>("set_ellipsize");
            gtklabel.method<&GtkLabel_::get_ellipsize>("get_ellipsize");
        
        
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
            gtknotebook.method<&GtkNotebook_::get_tab_reorderable>("get_tab_reorderable");
            gtknotebook.method<&GtkNotebook_::get_tab_detachable>("get_tab_detachable");
            gtknotebook.method<&GtkNotebook_::set_current_page>("set_current_page");
            gtknotebook.method<&GtkNotebook_::set_group_name>("set_group_name");
            gtknotebook.method<&GtkNotebook_::get_group_name>("get_group_name");
            gtknotebook.method<&GtkNotebook_::set_action_widget>("set_action_widget");
            gtknotebook.method<&GtkNotebook_::get_action_widget>("get_action_widget");
        

        // GtkPositionType
        Php::Class<Php::Base> gtkpositiontype("GtkPositionType");
            gtkpositiontype.constant("LEFT", (int)GTK_POS_LEFT);
            gtkpositiontype.constant("RIGHT", (int)GTK_POS_RIGHT);
            gtkpositiontype.constant("TOP", (int)GTK_POS_TOP);
            gtkpositiontype.constant("BOTTOM", (int)GTK_POS_BOTTOM);
        

        // GtkPackType
        Php::Class<Php::Base> gtkpacktype("GtkPackType");
            gtkpacktype.constant("STARTY", (int)GTK_PACK_START);
            gtkpacktype.constant("END", (int)GTK_PACK_END);
        


        // GtkJustification
        Php::Class<Php::Base> gtkjustification("GtkJustification");
            gtkjustification.constant("LEFT", (int)GTK_JUSTIFY_LEFT);
            gtkjustification.constant("RIGHT", (int)GTK_JUSTIFY_RIGHT);
            gtkjustification.constant("CENTER", (int)GTK_JUSTIFY_CENTER);
            gtkjustification.constant("FILL", (int)GTK_JUSTIFY_FILL);
        
        

        // GtkFileChooserAction
        Php::Class<Php::Base> gtkfilechooseraction("GtkFileChooserAction");
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
        Php::Class<Php::Base> gtktextwindowtype("GtkTextWindowType");
            gtktextwindowtype.constant("PRIVATE", (int)GTK_TEXT_WINDOW_PRIVATE);
            gtktextwindowtype.constant("WIDGET", (int)GTK_TEXT_WINDOW_WIDGET);
            gtktextwindowtype.constant("TEXT", (int)GTK_TEXT_WINDOW_TEXT);
            gtktextwindowtype.constant("LEFT", (int)GTK_TEXT_WINDOW_LEFT);
            gtktextwindowtype.constant("RIGHT", (int)GTK_TEXT_WINDOW_RIGHT);
            gtktextwindowtype.constant("TOP", (int)GTK_TEXT_WINDOW_TOP);
            gtktextwindowtype.constant("BOTTOM", (int)GTK_TEXT_WINDOW_BOTTOM);


        // GtkWrapMode
        Php::Class<Php::Base> gtkwrapmode("GtkWrapMode");
            gtkwrapmode.constant("NONE", (int)GTK_WRAP_NONE);
            gtkwrapmode.constant("CHAR", (int)GTK_WRAP_CHAR);
            gtkwrapmode.constant("WORD", (int)GTK_WRAP_WORD);
            gtkwrapmode.constant("WORD_CHAR", (int)GTK_WRAP_WORD_CHAR);
        

        // GtkInputHints
        Php::Class<Php::Base> gtkinputhints("GtkInputHints");
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
        Php::Class<Php::Base> gtkinputpurpose("GtkInputPurpose");
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
        Php::Class<Php::Base> gtkdialogflags("GtkDialogFlags");
            gtkdialogflags.constant("MODAL", (int)GTK_DIALOG_MODAL);
            gtkdialogflags.constant("DESTROY_WITH_PARENT", (int)GTK_DIALOG_DESTROY_WITH_PARENT);
            gtkdialogflags.constant("USE_HEADER_BAR", (int)GTK_DIALOG_USE_HEADER_BAR);
        

        // GtkResponseType
        Php::Class<Php::Base> gtkresponsetype("GtkResponseType");
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
        
        // GtkLicense
        Php::Class<Php::Base> gtklicense("GtkLicense");
            gtklicense.constant("UNKNOWN", (int)GTK_LICENSE_UNKNOWN);
            gtklicense.constant("CUSTOM", (int)GTK_LICENSE_CUSTOM);
            gtklicense.constant("GPL_2_0", (int)GTK_LICENSE_GPL_2_0);
            gtklicense.constant("GPL_3_0", (int)GTK_LICENSE_GPL_3_0);
            gtklicense.constant("LGPL_2_1", (int)GTK_LICENSE_LGPL_2_1);
            gtklicense.constant("LGPL_3_0", (int)GTK_LICENSE_LGPL_3_0);
            gtklicense.constant("BSD", (int)GTK_LICENSE_BSD);
            gtklicense.constant("MIT_X11", (int)GTK_LICENSE_MIT_X11);
            gtklicense.constant("ARTISTIC", (int)GTK_LICENSE_ARTISTIC);
            gtklicense.constant("GPL_2_0_ONLY", (int)GTK_LICENSE_GPL_2_0_ONLY);
            gtklicense.constant("GPL_3_0_ONLY", (int)GTK_LICENSE_GPL_3_0_ONLY);
            gtklicense.constant("LGPL_2_1_ONLY", (int)GTK_LICENSE_LGPL_2_1_ONLY);
            gtklicense.constant("LGPL_3_0_ONLY", (int)GTK_LICENSE_LGPL_3_0_ONLY);

        // GtkFileFilterFlags
        Php::Class<Php::Base> gtkfilefilterflags("GtkFileFilterFlags");
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

        // GtkMessageType
        Php::Class<Php::Base> gtkmessagetype("GtkMessageType");
            gtkmessagetype.constant("INFO", (int)GTK_MESSAGE_INFO);
            gtkmessagetype.constant("WARNING", (int)GTK_MESSAGE_WARNING);
            gtkmessagetype.constant("QUESTION", (int)GTK_MESSAGE_QUESTION);
            gtkmessagetype.constant("ERROR", (int)GTK_MESSAGE_ERROR);
            gtkmessagetype.constant("OTHER", (int)GTK_MESSAGE_OTHER);


        // GtkButtonsType
        Php::Class<Php::Base> gtkbuttonstype("GtkButtonsType");
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
        

        // GtkAboutDialog
        Php::Class<GtkAboutDialog_> gtkaboutdialog("GtkAboutDialog");
            gtkaboutdialog.extends(gtkdialog);
            gtkaboutdialog.method<&GtkAboutDialog_::__construct>("__construct");
            gtkaboutdialog.method<&GtkAboutDialog_::get_program_name>("get_program_name");
            gtkaboutdialog.method<&GtkAboutDialog_::set_program_name>("set_program_name");
            gtkaboutdialog.method<&GtkAboutDialog_::get_version>("get_version");
            gtkaboutdialog.method<&GtkAboutDialog_::set_version>("set_version");
            gtkaboutdialog.method<&GtkAboutDialog_::get_copyright>("get_copyright");
            gtkaboutdialog.method<&GtkAboutDialog_::set_copyright>("set_copyright");
            gtkaboutdialog.method<&GtkAboutDialog_::get_comments>("get_comments");
            gtkaboutdialog.method<&GtkAboutDialog_::set_comments>("set_comments");
            gtkaboutdialog.method<&GtkAboutDialog_::get_license>("get_license");
            gtkaboutdialog.method<&GtkAboutDialog_::set_license>("set_license");
            gtkaboutdialog.method<&GtkAboutDialog_::get_wrap_license>("get_wrap_license");
            gtkaboutdialog.method<&GtkAboutDialog_::set_wrap_license>("set_wrap_license");
            gtkaboutdialog.method<&GtkAboutDialog_::get_license_type>("get_license_type");
            gtkaboutdialog.method<&GtkAboutDialog_::set_license_type>("set_license_type");
            gtkaboutdialog.method<&GtkAboutDialog_::get_website>("get_website");
            gtkaboutdialog.method<&GtkAboutDialog_::set_website>("set_website");
            gtkaboutdialog.method<&GtkAboutDialog_::get_website_label>("get_website_label");
            gtkaboutdialog.method<&GtkAboutDialog_::set_website_label>("set_website_label");
            gtkaboutdialog.method<&GtkAboutDialog_::get_authors>("get_authors");
            gtkaboutdialog.method<&GtkAboutDialog_::set_authors>("set_authors");
            gtkaboutdialog.method<&GtkAboutDialog_::get_artists>("get_artists");
            gtkaboutdialog.method<&GtkAboutDialog_::set_artists>("set_artists");
            gtkaboutdialog.method<&GtkAboutDialog_::get_documenters>("get_documenters");
            gtkaboutdialog.method<&GtkAboutDialog_::set_documenters>("set_documenters");
            gtkaboutdialog.method<&GtkAboutDialog_::get_translator_credits>("get_translator_credits");
            gtkaboutdialog.method<&GtkAboutDialog_::set_translator_credits>("set_translator_credits");
            gtkaboutdialog.method<&GtkAboutDialog_::get_logo>("get_logo");
            gtkaboutdialog.method<&GtkAboutDialog_::set_logo>("set_logo");
            gtkaboutdialog.method<&GtkAboutDialog_::get_logo_icon_name>("get_logo_icon_name");
            gtkaboutdialog.method<&GtkAboutDialog_::set_logo_icon_name>("set_logo_icon_name");
            gtkaboutdialog.method<&GtkAboutDialog_::add_credit_section>("add_credit_section");
            gtkaboutdialog.method<&GtkAboutDialog_::gtk_show_about_dialog>("gtk_show_about_dialog");
        
        // GtkPageOrientation
        Php::Class<Php::Base> gtkpageorientation("GtkPageOrientation");
            gtkpageorientation.constant("PORTRAIT", (int)GTK_PAGE_ORIENTATION_PORTRAIT);
            gtkpageorientation.constant("LANDSCAPE", (int)GTK_PAGE_ORIENTATION_LANDSCAPE);
            gtkpageorientation.constant("REVERSE_PORTRAIT", (int)GTK_PAGE_ORIENTATION_REVERSE_PORTRAIT);
            gtkpageorientation.constant("REVERSE_LANDSCAPE", (int)GTK_PAGE_ORIENTATION_REVERSE_LANDSCAPE);


        // GtkPrintDuplex
        Php::Class<Php::Base> gtkprintduplex("GtkPrintDuplex");
            gtkprintduplex.constant("SIMPLEX", (int)GTK_PRINT_DUPLEX_SIMPLEX);
            gtkprintduplex.constant("HORIZONTAL", (int)GTK_PRINT_DUPLEX_HORIZONTAL);
            gtkprintduplex.constant("VERTICAL", (int)GTK_PRINT_DUPLEX_VERTICAL);

        // GtkPrintQuality
        Php::Class<Php::Base> gtkprintquality("GtkPrintQuality");
            gtkprintquality.constant("LOW", (int)GTK_PRINT_QUALITY_LOW);
            gtkprintquality.constant("NORMAL", (int)GTK_PRINT_QUALITY_NORMAL);
            gtkprintquality.constant("HIGH", (int)GTK_PRINT_QUALITY_HIGH);
            gtkprintquality.constant("DRAFT", (int)GTK_PRINT_QUALITY_DRAFT);

        // GtkNumberUpLayout
        Php::Class<Php::Base> gtknumberuplayout("GtkNumberUpLayout");
            gtknumberuplayout.constant("LEFT_TO_RIGHT_TOP_TO_BOTTOM", (int)GTK_NUMBER_UP_LAYOUT_LEFT_TO_RIGHT_TOP_TO_BOTTOM);
            gtknumberuplayout.constant("LEFT_TO_RIGHT_BOTTOM_TO_TOP", (int)GTK_NUMBER_UP_LAYOUT_LEFT_TO_RIGHT_BOTTOM_TO_TOP);
            gtknumberuplayout.constant("RIGHT_TO_LEFT_TOP_TO_BOTTOM", (int)GTK_NUMBER_UP_LAYOUT_RIGHT_TO_LEFT_TOP_TO_BOTTOM);
            gtknumberuplayout.constant("RIGHT_TO_LEFT_BOTTOM_TO_TOP", (int)GTK_NUMBER_UP_LAYOUT_RIGHT_TO_LEFT_BOTTOM_TO_TOP);
            gtknumberuplayout.constant("TOP_TO_BOTTOM_LEFT_TO_RIGHT", (int)GTK_NUMBER_UP_LAYOUT_TOP_TO_BOTTOM_LEFT_TO_RIGHT);
            gtknumberuplayout.constant("TOP_TO_BOTTOM_RIGHT_TO_LEFT", (int)GTK_NUMBER_UP_LAYOUT_TOP_TO_BOTTOM_RIGHT_TO_LEFT);
            gtknumberuplayout.constant("BOTTOM_TO_TOP_LEFT_TO_RIGHT", (int)GTK_NUMBER_UP_LAYOUT_BOTTOM_TO_TOP_LEFT_TO_RIGHT);
            gtknumberuplayout.constant("BOTTOM_TO_TOP_RIGHT_TO_LEFT", (int)GTK_NUMBER_UP_LAYOUT_BOTTOM_TO_TOP_RIGHT_TO_LEFT);


        // GtkPrintPages
        Php::Class<Php::Base> gtkprintpages("GtkPrintPages");
            gtkprintpages.constant("ALL", (int)GTK_PRINT_PAGES_ALL);
            gtkprintpages.constant("CURRENT", (int)GTK_PRINT_PAGES_CURRENT);
            gtkprintpages.constant("RANGES", (int)GTK_PRINT_PAGES_RANGES);
            gtkprintpages.constant("SELECTION", (int)GTK_PRINT_PAGES_SELECTION);
        

        // GtkPageSet
        Php::Class<Php::Base> gtkpageset("GtkPageSet");
            gtkpageset.constant("ALL", (int)GTK_PAGE_SET_ALL);
            gtkpageset.constant("EVEN", (int)GTK_PAGE_SET_EVEN);
            gtkpageset.constant("ODD", (int)GTK_PAGE_SET_ODD);


        // GtkFontChooserDialog
        Php::Class<GtkFontChooserDialog_> gtkfontchooserdialog("GtkFontChooserDialog");
            gtkfontchooserdialog.extends(gtkdialog);
            gtkfontchooserdialog.method<&GtkFontChooserDialog_::__construct>("__construct");
            gtkfontchooserdialog.method<&GtkFontChooserDialog_::get_font_size>("get_font_size");
            gtkfontchooserdialog.method<&GtkFontChooserDialog_::get_font>("get_font");
            gtkfontchooserdialog.method<&GtkFontChooserDialog_::get_preview_text>("get_preview_text");
            gtkfontchooserdialog.method<&GtkFontChooserDialog_::set_preview_text>("set_preview_text");
            gtkfontchooserdialog.method<&GtkFontChooserDialog_::get_show_preview_entry>("get_show_preview_entry");
            gtkfontchooserdialog.method<&GtkFontChooserDialog_::set_show_preview_entry>("set_show_preview_entry");


        // GtkIconSize
        Php::Class<Php::Base> gtkiconsize("GtkIconSize");
            gtkiconsize.constant("INVALID", (int)GTK_ICON_SIZE_INVALID);
            gtkiconsize.constant("MENU", (int)GTK_ICON_SIZE_MENU);
            gtkiconsize.constant("SMALL_TOOLBAR", (int)GTK_ICON_SIZE_SMALL_TOOLBAR);
            gtkiconsize.constant("LARGE_TOOLBAR", (int)GTK_ICON_SIZE_LARGE_TOOLBAR);
            gtkiconsize.constant("BUTTON", (int)GTK_ICON_SIZE_BUTTON);
            gtkiconsize.constant("DND", (int)GTK_ICON_SIZE_DND);
            gtkiconsize.constant("DIALOG", (int)GTK_ICON_SIZE_DIALOG);
        

        // GtkSizeGroupMode
        Php::Class<Php::Base> gtksizegroupmode("GtkSizeGroupMode");
            gtksizegroupmode.constant("NONE", (int)GTK_SIZE_GROUP_NONE);
            gtksizegroupmode.constant("HORIZONTAL", (int)GTK_SIZE_GROUP_HORIZONTAL);
            gtksizegroupmode.constant("VERTICAL", (int)GTK_SIZE_GROUP_VERTICAL);
            gtksizegroupmode.constant("BOTH", (int)GTK_SIZE_GROUP_BOTH);

        // GtkToolbarStyle
        Php::Class<Php::Base> gtktoolbarstyle("GtkToolbarStyle");
            gtktoolbarstyle.constant("ICONS", (int)GTK_TOOLBAR_ICONS);
            gtktoolbarstyle.constant("TEXT", (int)GTK_TOOLBAR_TEXT);
            gtktoolbarstyle.constant("BOTH", (int)GTK_TOOLBAR_BOTH);
            gtktoolbarstyle.constant("BOTH_HORIZ", (int)GTK_TOOLBAR_BOTH_HORIZ);


        // GtkReliefStyle
        Php::Class<Php::Base> gtkreliefstyle("GtkReliefStyle");
            gtkreliefstyle.constant("NORMAL", (int)GTK_RELIEF_NORMAL);
            gtkreliefstyle.constant("HALF", (int)GTK_RELIEF_HALF);
            gtkreliefstyle.constant("NONE", (int)GTK_RELIEF_NONE);


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
        Php::Class<Php::Base> gdkselection("GdkSelection");
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
        

        // GtkListStore
        Php::Class<GtkListStore_> gtkliststore("GtkListStore");
            gtkliststore.extends(gtktreemodel);
            gtkliststore.method<&GtkListStore_::__construct>("__construct");
            gtkliststore.method<&GtkListStore_::set_column_types>("set_column_types");
            gtkliststore.method<&GtkListStore_::set>("set");
            gtkliststore.method<&GtkListStore_::set_valist>("set_valist");
            gtkliststore.method<&GtkListStore_::set_value>("set_value");
            gtkliststore.method<&GtkListStore_::set_valuesv>("set_valuesv");
            gtkliststore.method<&GtkListStore_::remove>("remove");
            gtkliststore.method<&GtkListStore_::insert>("insert");
            gtkliststore.method<&GtkListStore_::insert_before>("insert_before");
            gtkliststore.method<&GtkListStore_::insert_after>("insert_after");
            gtkliststore.method<&GtkListStore_::insert_with_values>("insert_with_values");
            gtkliststore.method<&GtkListStore_::insert_with_valuesv>("insert_with_valuesv");
            gtkliststore.method<&GtkListStore_::prepend>("prepend");
            gtkliststore.method<&GtkListStore_::append>("append");
            gtkliststore.method<&GtkListStore_::clear>("clear");
            gtkliststore.method<&GtkListStore_::iter_is_valid>("iter_is_valid");
            gtkliststore.method<&GtkListStore_::reorder>("reorder");
            gtkliststore.method<&GtkListStore_::swap>("swap");
            gtkliststore.method<&GtkListStore_::move_before>("move_before");
            gtkliststore.method<&GtkListStore_::move_after>("move_after");
        

        
        // GtkSelectionMode
        Php::Class<Php::Base> gtkselectionmode("GtkSelectionMode");
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
        Php::Class<Php::Base> gtkpackdirection("GtkPackDirection");
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


        // GtkStatusbar
        Php::Class<GtkStatusbar_> gtkstatusbar("GtkStatusbar");
            gtkstatusbar.extends(gtkbox);
            gtkstatusbar.method<&GtkStatusbar_::__construct>("__construct");
            gtkstatusbar.method<&GtkStatusbar_::get_context_id>("get_context_id");
            gtkstatusbar.method<&GtkStatusbar_::push>("push");
            gtkstatusbar.method<&GtkStatusbar_::pop>("pop");
            gtkstatusbar.method<&GtkStatusbar_::remove>("remove");
            gtkstatusbar.method<&GtkStatusbar_::remove_all>("remove_all");
            gtkstatusbar.method<&GtkStatusbar_::get_message_area>("get_message_area");


        // GtkListBoxRow
        Php::Class<GtkListBoxRow_> gtklistboxrow("GtkListBoxRow");
            gtklistboxrow.extends(gtkbin);
            gtklistboxrow.method<&GtkListBoxRow_::__construct>("__construct");


        // GtkListBox
        Php::Class<GtkListBox_> gtklistbox("GtkListBox");
            gtklistbox.extends(gtkbin);
            gtklistbox.method<&GtkListBox_::__construct>("__construct");
            gtklistbox.method<&GtkListBox_::prepend>("prepend");
            gtklistbox.method<&GtkListBox_::insert>("insert");
            gtklistbox.method<&GtkListBox_::select_row>("select_row");
            gtklistbox.method<&GtkListBox_::unselect_row>("unselect_row");
            gtklistbox.method<&GtkListBox_::select_all>("select_all");
            gtklistbox.method<&GtkListBox_::unselect_all>("unselect_all");
            gtklistbox.method<&GtkListBox_::get_selected_row>("get_selected_row");
            gtklistbox.method<&GtkListBox_::selected_foreach>("selected_foreach");
            gtklistbox.method<&GtkListBox_::get_selected_rows>("get_selected_rows");
            gtklistbox.method<&GtkListBox_::set_selection_mode>("set_selection_mode");
            gtklistbox.method<&GtkListBox_::get_selection_mode>("get_selection_mode");
            gtklistbox.method<&GtkListBox_::set_activate_on_single_click>("set_activate_on_single_click");
            gtklistbox.method<&GtkListBox_::get_activate_on_single_click>("get_activate_on_single_click");
            gtklistbox.method<&GtkListBox_::get_adjustment>("get_adjustment");
            gtklistbox.method<&GtkListBox_::set_adjustment>("set_adjustment");
            gtklistbox.method<&GtkListBox_::set_placeholder>("set_placeholder");
            gtklistbox.method<&GtkListBox_::get_row_at_index>("get_row_at_index");
            gtklistbox.method<&GtkListBox_::get_row_at_y>("get_row_at_y");
            gtklistbox.method<&GtkListBox_::invalidate_filter>("invalidate_filter");
            gtklistbox.method<&GtkListBox_::invalidate_headers>("invalidate_headers");
            gtklistbox.method<&GtkListBox_::invalidate_sort>("invalidate_sort");
            gtklistbox.method<&GtkListBox_::set_filter_func>("set_filter_func");
            gtklistbox.method<&GtkListBox_::set_header_func>("set_header_func");
            gtklistbox.method<&GtkListBox_::set_sort_func>("set_sort_func");
            gtklistbox.method<&GtkListBox_::drag_highlight_row>("drag_highlight_row");
            gtklistbox.method<&GtkListBox_::drag_unhighlight_row>("drag_unhighlight_row");
            gtklistbox.method<&GtkListBox_::bind_model>("bind_model");
        

        // GtkSensitivityType
        Php::Class<Php::Base> gtksensitivitytype("GtkSensitivityType");
            gtksensitivitytype.constant("AUTO", (int)GTK_SENSITIVITY_AUTO);
            gtksensitivitytype.constant("ON", (int)GTK_SENSITIVITY_ON);
            gtksensitivitytype.constant("OFF", (int)GTK_SENSITIVITY_OFF);
        

        // GtkComboBox
        Php::Class<GtkComboBox_> gtkcombobox("GtkComboBox");
            gtkcombobox.extends(gtkbin);
            gtkcombobox.method<&GtkComboBox_::__construct>("__construct");
            gtkcombobox.method<&GtkComboBox_::new_with_entry>("new_with_entry");
            gtkcombobox.method<&GtkComboBox_::new_with_model>("new_with_model");
            gtkcombobox.method<&GtkComboBox_::new_with_model_and_entry>("new_with_model_and_entry");
            gtkcombobox.method<&GtkComboBox_::new_with_area>("new_with_area");
            gtkcombobox.method<&GtkComboBox_::new_with_area_and_entry>("new_with_area_and_entry");
            gtkcombobox.method<&GtkComboBox_::get_wrap_width>("get_wrap_width");
            gtkcombobox.method<&GtkComboBox_::set_wrap_width>("set_wrap_width");
            gtkcombobox.method<&GtkComboBox_::get_row_span_column>("get_row_span_column");
            gtkcombobox.method<&GtkComboBox_::set_row_span_column>("set_row_span_column");
            gtkcombobox.method<&GtkComboBox_::get_column_span_column>("get_column_span_column");
            gtkcombobox.method<&GtkComboBox_::set_column_span_column>("set_column_span_column");
            gtkcombobox.method<&GtkComboBox_::get_active>("get_active");
            gtkcombobox.method<&GtkComboBox_::set_active>("set_active");
            gtkcombobox.method<&GtkComboBox_::get_active_iter>("get_active_iter");
            gtkcombobox.method<&GtkComboBox_::set_active_iter>("set_active_iter");
            gtkcombobox.method<&GtkComboBox_::get_id_column>("get_id_column");
            gtkcombobox.method<&GtkComboBox_::set_id_column>("set_id_column");
            gtkcombobox.method<&GtkComboBox_::get_active_id>("get_active_id");
            gtkcombobox.method<&GtkComboBox_::set_active_id>("set_active_id");
            gtkcombobox.method<&GtkComboBox_::get_model>("get_model");
            gtkcombobox.method<&GtkComboBox_::set_model>("set_model");
            gtkcombobox.method<&GtkComboBox_::popup_for_device>("popup_for_device");
            gtkcombobox.method<&GtkComboBox_::popup>("popup");
            gtkcombobox.method<&GtkComboBox_::popdown>("popdown");
            gtkcombobox.method<&GtkComboBox_::get_popup_accessible>("get_popup_accessible");
            gtkcombobox.method<&GtkComboBox_::get_row_separator_func>("get_row_separator_func");
            gtkcombobox.method<&GtkComboBox_::set_row_separator_func>("set_row_separator_func");
            gtkcombobox.method<&GtkComboBox_::set_button_sensitivity>("set_button_sensitivity");
            gtkcombobox.method<&GtkComboBox_::get_button_sensitivity>("get_button_sensitivity");
            gtkcombobox.method<&GtkComboBox_::get_has_entry>("get_has_entry");
            gtkcombobox.method<&GtkComboBox_::get_entry_text_column>("get_entry_text_column");
            gtkcombobox.method<&GtkComboBox_::set_entry_text_column>("set_entry_text_column");
            gtkcombobox.method<&GtkComboBox_::get_popup_fixed_width>("get_popup_fixed_width");
            gtkcombobox.method<&GtkComboBox_::set_popup_fixed_width>("set_popup_fixed_width");
            gtkcombobox.method<&GtkComboBox_::pack_start>("pack_start");
            gtkcombobox.method<&GtkComboBox_::pack_end>("pack_end");
            gtkcombobox.method<&GtkComboBox_::reorder>("reorder");
            gtkcombobox.method<&GtkComboBox_::clear>("clear");
            gtkcombobox.method<&GtkComboBox_::add_attribute>("add_attribute");


        // GtkComboBoxText
        Php::Class<GtkComboBoxText_> gtkcomboboxtext("GtkComboBoxText");
            gtkcomboboxtext.extends(gtkcombobox);
            gtkcomboboxtext.method<&GtkComboBoxText_::__construct>("__construct");
            gtkcomboboxtext.method<&GtkComboBoxText_::new_with_entry>("new_with_entry");
            gtkcomboboxtext.method<&GtkComboBoxText_::append>("append");
            gtkcomboboxtext.method<&GtkComboBoxText_::prepend>("prepend");
            gtkcomboboxtext.method<&GtkComboBoxText_::insert>("insert");
            gtkcomboboxtext.method<&GtkComboBoxText_::append_text>("append_text");
            gtkcomboboxtext.method<&GtkComboBoxText_::prepend_text>("prepend_text");
            gtkcomboboxtext.method<&GtkComboBoxText_::insert_text>("insert_text");
            gtkcomboboxtext.method<&GtkComboBoxText_::remove>("remove");
            gtkcomboboxtext.method<&GtkComboBoxText_::remove_all>("remove_all");
            gtkcomboboxtext.method<&GtkComboBoxText_::get_active_text>("get_active_text");


        // GtkAppChooserButton
        Php::Class<GtkAppChooserButton_> gtkappchooserbutton("GtkAppChooserButton");
            gtkappchooserbutton.extends(gtkcombobox);
            gtkappchooserbutton.method<&GtkAppChooserButton_::__construct>("__construct");
            gtkappchooserbutton.method<&GtkAppChooserButton_::append_custom_item>("append_custom_item");
            gtkappchooserbutton.method<&GtkAppChooserButton_::append_separator>("append_separator");
            gtkappchooserbutton.method<&GtkAppChooserButton_::set_active_custom_item>("set_active_custom_item");
            gtkappchooserbutton.method<&GtkAppChooserButton_::get_show_default_item>("get_show_default_item");
            gtkappchooserbutton.method<&GtkAppChooserButton_::set_show_default_item>("set_show_default_item");
            gtkappchooserbutton.method<&GtkAppChooserButton_::get_show_dialog_item>("get_show_dialog_item");
            gtkappchooserbutton.method<&GtkAppChooserButton_::set_show_dialog_item>("set_show_dialog_item");
            gtkappchooserbutton.method<&GtkAppChooserButton_::get_heading>("get_heading");
            gtkappchooserbutton.method<&GtkAppChooserButton_::set_heading>("set_heading");
            gtkappchooserbutton.method<&GtkAppChooserButton_::get_app_info>("get_app_info");


        // GtkBuilder
        Php::Class<GtkBuilder_> gtkbuilder("GtkBuilder");
            gtkbuilder.extends(gobject);
            gtkbuilder.method<&GtkBuilder_::__construct>("__construct");
            gtkbuilder.method<&GtkBuilder_::new_from_file>("new_from_file");
            gtkbuilder.method<&GtkBuilder_::new_from_resource>("new_from_resource");
            gtkbuilder.method<&GtkBuilder_::new_from_string>("new_from_string");
            gtkbuilder.method<&GtkBuilder_::add_callback_symbol>("add_callback_symbol");
            gtkbuilder.method<&GtkBuilder_::add_callback_symbols>("add_callback_symbols");
            gtkbuilder.method<&GtkBuilder_::lookup_callback_symbol>("lookup_callback_symbol");
            gtkbuilder.method<&GtkBuilder_::add_from_file>("add_from_file");
            gtkbuilder.method<&GtkBuilder_::add_from_resource>("add_from_resource");
            gtkbuilder.method<&GtkBuilder_::add_from_string>("add_from_string");
            gtkbuilder.method<&GtkBuilder_::add_objects_from_file>("add_objects_from_file");
            gtkbuilder.method<&GtkBuilder_::add_objects_from_string>("add_objects_from_string");
            gtkbuilder.method<&GtkBuilder_::add_objects_from_resource>("add_objects_from_resource");
            gtkbuilder.method<&GtkBuilder_::extend_with_template>("extend_with_template");
            gtkbuilder.method<&GtkBuilder_::get_object>("get_object");
            gtkbuilder.method<&GtkBuilder_::get_objects>("get_objects");
            gtkbuilder.method<&GtkBuilder_::expose_object>("expose_object");
            gtkbuilder.method<&GtkBuilder_::connect_signals>("connect_signals");
            gtkbuilder.method<&GtkBuilder_::connect_signals_full>("connect_signals_full");
            gtkbuilder.method<&GtkBuilder_::set_translation_domain>("set_translation_domain");
            gtkbuilder.method<&GtkBuilder_::get_translation_domain>("get_translation_domain");
            gtkbuilder.method<&GtkBuilder_::get_application>("get_application");
            gtkbuilder.method<&GtkBuilder_::set_application>("set_application");
            gtkbuilder.method<&GtkBuilder_::get_type_from_name>("get_type_from_name");
            gtkbuilder.method<&GtkBuilder_::value_from_string>("value_from_string");
            gtkbuilder.method<&GtkBuilder_::value_from_string_type>("value_from_string_type");
        

        // GtkBaselinePosition
        Php::Class<Php::Base> gtkbaselineposition("GtkBaselinePosition");
            gtkbaselineposition.constant("TOP", (int)GTK_BASELINE_POSITION_TOP);
            gtkbaselineposition.constant("CENTER", (int)GTK_BASELINE_POSITION_CENTER);
            gtkbaselineposition.constant("BOTTOM", (int)GTK_BASELINE_POSITION_BOTTOM);


        // GtkDeleteType
        Php::Class<Php::Base> gtkdeletetype("GtkDeleteType");
            gtkdeletetype.constant("CHARS", (int)GTK_DELETE_CHARS);
            gtkdeletetype.constant("WORD_ENDS", (int)GTK_DELETE_WORD_ENDS);
            gtkdeletetype.constant("WORDS", (int)GTK_DELETE_WORDS);
            gtkdeletetype.constant("DISPLAY_LINES", (int)GTK_DELETE_DISPLAY_LINES);
            gtkdeletetype.constant("DISPLAY_LINE_ENDS", (int)GTK_DELETE_DISPLAY_LINE_ENDS);
            gtkdeletetype.constant("PARAGRAPH_ENDS", (int)GTK_DELETE_PARAGRAPH_ENDS);
            gtkdeletetype.constant("PARAGRAPHS", (int)GTK_DELETE_PARAGRAPHS);
            gtkdeletetype.constant("WHITESPACE", (int)GTK_DELETE_WHITESPACE);


        // GtkDirectionType
        Php::Class<Php::Base> gtkdirectiontype("GtkDirectionType");
            gtkdirectiontype.constant("TAB_FORWARD", (int)GTK_DIR_TAB_FORWARD);
            gtkdirectiontype.constant("TAB_BACKWARD", (int)GTK_DIR_TAB_BACKWARD);
            gtkdirectiontype.constant("UP", (int)GTK_DIR_UP);
            gtkdirectiontype.constant("DOWN", (int)GTK_DIR_DOWN);
            gtkdirectiontype.constant("LEFT", (int)GTK_DIR_LEFT);
            gtkdirectiontype.constant("RIGHT", (int)GTK_DIR_RIGHT);


        // GtkMovementStep
        Php::Class<Php::Base> gtkmovementstep("GtkMovementStep");
            gtkmovementstep.constant("LOGICAL_POSITIONS", (int)GTK_MOVEMENT_LOGICAL_POSITIONS);
            gtkmovementstep.constant("VISUAL_POSITIONS", (int)GTK_MOVEMENT_VISUAL_POSITIONS);
            gtkmovementstep.constant("WORDS", (int)GTK_MOVEMENT_WORDS);
            gtkmovementstep.constant("DISPLAY_LINES", (int)GTK_MOVEMENT_DISPLAY_LINES);
            gtkmovementstep.constant("DISPLAY_LINE_ENDS", (int)GTK_MOVEMENT_DISPLAY_LINE_ENDS);
            gtkmovementstep.constant("PARAGRAPHS", (int)GTK_MOVEMENT_PARAGRAPHS);
            gtkmovementstep.constant("PARAGRAPH_ENDS", (int)GTK_MOVEMENT_PARAGRAPH_ENDS);
            gtkmovementstep.constant("PAGES", (int)GTK_MOVEMENT_PAGES);
            gtkmovementstep.constant("BUFFER_ENDS", (int)GTK_MOVEMENT_BUFFER_ENDS);
            gtkmovementstep.constant("HORIZONTAL_PAGES", (int)GTK_MOVEMENT_HORIZONTAL_PAGES);


        // GtkScrollStep
        Php::Class<Php::Base> gtkscrollstep("GtkScrollStep");
            gtkscrollstep.constant("STEPS", (int)GTK_SCROLL_STEPS);
            gtkscrollstep.constant("PAGES", (int)GTK_SCROLL_PAGES);
            gtkscrollstep.constant("ENDS", (int)GTK_SCROLL_ENDS);
            gtkscrollstep.constant("HORIZONTAL_STEPS", (int)GTK_SCROLL_HORIZONTAL_STEPS);
            gtkscrollstep.constant("HORIZONTAL_PAGES", (int)GTK_SCROLL_HORIZONTAL_PAGES);
            gtkscrollstep.constant("HORIZONTAL_ENDS", (int)GTK_SCROLL_HORIZONTAL_ENDS);
        
        
        // GtkScrollType
        Php::Class<Php::Base> gtkscrolltype("GtkScrollType");
            gtkscrolltype.constant("NONE", (int)GTK_SCROLL_NONE);
            gtkscrolltype.constant("JUMP", (int)GTK_SCROLL_JUMP);
            gtkscrolltype.constant("STEP_BACKWARD", (int)GTK_SCROLL_STEP_BACKWARD);
            gtkscrolltype.constant("STEP_FORWARD", (int)GTK_SCROLL_STEP_FORWARD);
            gtkscrolltype.constant("PAGE_BACKWARD", (int)GTK_SCROLL_PAGE_BACKWARD);
            gtkscrolltype.constant("PAGE_FORWARD", (int)GTK_SCROLL_PAGE_FORWARD);
            gtkscrolltype.constant("STEP_UP", (int)GTK_SCROLL_STEP_UP);
            gtkscrolltype.constant("STEP_DOWN", (int)GTK_SCROLL_STEP_DOWN);
            gtkscrolltype.constant("PAGE_UP", (int)GTK_SCROLL_PAGE_UP);
            gtkscrolltype.constant("PAGE_DOWN", (int)GTK_SCROLL_PAGE_DOWN);
            gtkscrolltype.constant("STEP_LEFT", (int)GTK_SCROLL_STEP_LEFT);
            gtkscrolltype.constant("STEP_RIGHT", (int)GTK_SCROLL_STEP_RIGHT);
            gtkscrolltype.constant("PAGE_LEFT", (int)GTK_SCROLL_PAGE_LEFT);
            gtkscrolltype.constant("PAGE_RIGHT", (int)GTK_SCROLL_PAGE_RIGHT);
            gtkscrolltype.constant("START", (int)GTK_SCROLL_START);
            gtkscrolltype.constant("END", (int)GTK_SCROLL_END);


        // GtkShadowType
        Php::Class<Php::Base> gtkshadowtype("GtkShadowType");
            gtkshadowtype.constant("NONE", (int)GTK_SHADOW_NONE);
            gtkshadowtype.constant("IN", (int)GTK_SHADOW_IN);
            gtkshadowtype.constant("OUT", (int)GTK_SHADOW_OUT);
            gtkshadowtype.constant("ETCHED_IN", (int)GTK_SHADOW_ETCHED_IN);
            gtkshadowtype.constant("ETCHED_OUT", (int)GTK_SHADOW_ETCHED_OUT);


        // GtkStateFlags
        Php::Class<Php::Base> gtkstateflags("GtkStateFlags");
            gtkstateflags.constant("NORMAL", (int)GTK_STATE_FLAG_NORMAL);
            gtkstateflags.constant("ACTIVE", (int)GTK_STATE_FLAG_ACTIVE);
            gtkstateflags.constant("PRELIGHT", (int)GTK_STATE_FLAG_PRELIGHT);
            gtkstateflags.constant("SELECTED", (int)GTK_STATE_FLAG_SELECTED);
            gtkstateflags.constant("INSENSITIVE", (int)GTK_STATE_FLAG_INSENSITIVE);
            gtkstateflags.constant("INCONSISTENT", (int)GTK_STATE_FLAG_INCONSISTENT);
            gtkstateflags.constant("FOCUSED", (int)GTK_STATE_FLAG_FOCUSED);
            gtkstateflags.constant("BACKDROP", (int)GTK_STATE_FLAG_BACKDROP);
            gtkstateflags.constant("DIR_LTR", (int)GTK_STATE_FLAG_DIR_LTR);
            gtkstateflags.constant("DIR_RTL", (int)GTK_STATE_FLAG_DIR_RTL);
            gtkstateflags.constant("LINK", (int)GTK_STATE_FLAG_LINK);
            gtkstateflags.constant("VISITED", (int)GTK_STATE_FLAG_VISITED);
            gtkstateflags.constant("CHECKED", (int)GTK_STATE_FLAG_CHECKED);
            gtkstateflags.constant("DROP_ACTIVE", (int)GTK_STATE_FLAG_DROP_ACTIVE);
        

        // GtkRevealerTransitionType
        Php::Class<Php::Base> gtkrevealertransitiontype("GtkRevealerTransitionType");
            gtkrevealertransitiontype.constant("NONE", (int)GTK_REVEALER_TRANSITION_TYPE_NONE);
            gtkrevealertransitiontype.constant("CROSSFADE", (int)GTK_REVEALER_TRANSITION_TYPE_CROSSFADE);
            gtkrevealertransitiontype.constant("RIGHT", (int)GTK_REVEALER_TRANSITION_TYPE_SLIDE_RIGHT);
            gtkrevealertransitiontype.constant("LEFT", (int)GTK_REVEALER_TRANSITION_TYPE_SLIDE_LEFT);
            gtkrevealertransitiontype.constant("UP", (int)GTK_REVEALER_TRANSITION_TYPE_SLIDE_UP);
            gtkrevealertransitiontype.constant("DOWN", (int)GTK_REVEALER_TRANSITION_TYPE_SLIDE_DOWN);
        

        // GtkRevealer
        Php::Class<GtkRevealer_> gtkrevealer("GtkRevealer");
            gtkrevealer.extends(gtkbin);
            gtkrevealer.method<&GtkRevealer_::__construct>("__construct");
            gtkrevealer.method<&GtkRevealer_::get_reveal_child>("get_reveal_child");
            gtkrevealer.method<&GtkRevealer_::set_reveal_child>("set_reveal_child");
            gtkrevealer.method<&GtkRevealer_::get_child_revealed>("get_child_revealed");
            gtkrevealer.method<&GtkRevealer_::get_transition_duration>("get_transition_duration");
            gtkrevealer.method<&GtkRevealer_::set_transition_duration>("set_transition_duration");
            gtkrevealer.method<&GtkRevealer_::get_transition_type>("get_transition_type");
            gtkrevealer.method<&GtkRevealer_::set_transition_type>("set_transition_type");

        // GladeApp
        Php::Class<GladeApp_> gladeapp("GladeApp");
            gladeapp.extends(gobject);
            gladeapp.method<&GladeApp_::__construct>("__construct");
            gladeapp.method<&GladeApp_::get>("get");
            gladeapp.method<&GladeApp_::set_window>("set_window");
            gladeapp.method<&GladeApp_::get_window>("get_window");
            gladeapp.method<&GladeApp_::get_clipboard>("get_clipboard");
            gladeapp.method<&GladeApp_::add_project>("add_project");
            gladeapp.method<&GladeApp_::remove_project>("remove_project");
            gladeapp.method<&GladeApp_::get_projects>("get_projects");
            gladeapp.method<&GladeApp_::get_config>("get_config");
            gladeapp.method<&GladeApp_::is_project_loaded>("is_project_loaded");
            gladeapp.method<&GladeApp_::get_project_by_path>("get_project_by_path");
            gladeapp.method<&GladeApp_::config_save>("config_save");
            gladeapp.method<&GladeApp_::set_accel_group>("set_accel_group");
            gladeapp.method<&GladeApp_::get_catalogs_dir>("get_catalogs_dir");
            gladeapp.method<&GladeApp_::get_modules_dir>("get_modules_dir");
            gladeapp.method<&GladeApp_::get_pixmaps_dir>("get_pixmaps_dir");
            gladeapp.method<&GladeApp_::get_locale_dir>("get_locale_dir");
        
        // GladeProject
        Php::Class<GladeProject_> gladeproject("GladeProject");
            gladeproject.extends(gobject);
            gladeproject.method<&GladeProject_::__construct>("__construct");
            gladeproject.method<&GladeProject_::selection_get>("selection_get");

        // GladeWidget
        Php::Class<GladeWidget_> gladewidget("GladeWidget");
            gladewidget.extends(gobject);
            gladewidget.method<&GladeWidget_::__construct>("__construct");

        // GladeDesignView
        Php::Class<GladeDesignView_> gladedesignview("GladeDesignView");
            gladedesignview.extends(gtkbox);
            gladedesignview.method<&GladeDesignView_::__construct>("__construct");
            gladedesignview.method<&GladeDesignView_::get_project>("get_project");
            gladedesignview.method<&GladeDesignView_::get_from_project>("get_from_project");

        // GladeEditor
        Php::Class<GladeEditor_> gladeeditor("GladeEditor");
            gladeeditor.extends(gtkbox);
            gladeeditor.method<&GladeEditor_::__construct>("__construct");
            gladeeditor.method<&GladeEditor_::load_widget>("load_widget");
            gladeeditor.method<&GladeEditor_::query_dialog>("query_dialog");

        // GladePalette
        Php::Class<GladePalette_> gladepalette("GladePalette");
            gladepalette.extends(gtkbox);
            gladepalette.method<&GladePalette_::__construct>("__construct");
            gladepalette.method<&GladePalette_::get_item_appearance>("get_item_appearance");
            gladepalette.method<&GladePalette_::set_item_appearance>("set_item_appearance");
            gladepalette.method<&GladePalette_::get_use_small_item_icons>("get_use_small_item_icons");
            gladepalette.method<&GladePalette_::set_use_small_item_icons>("set_use_small_item_icons");
            gladepalette.method<&GladePalette_::get_show_selector_button>("get_show_selector_button");
            gladepalette.method<&GladePalette_::set_show_selector_button>("set_show_selector_button");


        // GtkFlowBoxChild
        Php::Class<GtkFlowBoxChild_> gtkflowboxchild("GtkFlowBoxChild");
            gtkflowboxchild.extends(gtkbin);
            gtkflowboxchild.method<&GtkFlowBoxChild_::__construct>("__construct");
            gtkflowboxchild.method<&GtkFlowBoxChild_::get_index>("get_index");
            gtkflowboxchild.method<&GtkFlowBoxChild_::is_selected>("is_selected");
            gtkflowboxchild.method<&GtkFlowBoxChild_::changed>("changed");

        // GtkFlowBox
        Php::Class<GtkFlowBox_> gtkflowbox("GtkFlowBox");
            gtkflowbox.extends(gtkcontainer);
            gtkflowbox.method<&GtkFlowBox_::__construct>("__construct");
            gtkflowbox.method<&GtkFlowBox_::insert>("insert");
            gtkflowbox.method<&GtkFlowBox_::get_child_at_index>("get_child_at_index");
            gtkflowbox.method<&GtkFlowBox_::set_hadjustment>("set_hadjustment");
            gtkflowbox.method<&GtkFlowBox_::set_vadjustment>("set_vadjustment");
            gtkflowbox.method<&GtkFlowBox_::set_homogeneous>("set_homogeneous");
            gtkflowbox.method<&GtkFlowBox_::get_homogeneous>("get_homogeneous");
            gtkflowbox.method<&GtkFlowBox_::set_row_spacing>("set_row_spacing");
            gtkflowbox.method<&GtkFlowBox_::get_row_spacing>("get_row_spacing");
            gtkflowbox.method<&GtkFlowBox_::set_column_spacing>("set_column_spacing");
            gtkflowbox.method<&GtkFlowBox_::get_column_spacing>("get_column_spacing");
            gtkflowbox.method<&GtkFlowBox_::set_min_children_per_line>("set_min_children_per_line");
            gtkflowbox.method<&GtkFlowBox_::get_min_children_per_line>("get_min_children_per_line");
            gtkflowbox.method<&GtkFlowBox_::set_max_children_per_line>("set_max_children_per_line");
            gtkflowbox.method<&GtkFlowBox_::get_max_children_per_line>("get_max_children_per_line");
            gtkflowbox.method<&GtkFlowBox_::set_activate_on_single_click>("set_activate_on_single_click");
            gtkflowbox.method<&GtkFlowBox_::get_activate_on_single_click>("get_activate_on_single_click");
            gtkflowbox.method<&GtkFlowBox_::selected_foreach>("selected_foreach");
            gtkflowbox.method<&GtkFlowBox_::get_selected_children>("get_selected_children");
            gtkflowbox.method<&GtkFlowBox_::select_child>("select_child");
            gtkflowbox.method<&GtkFlowBox_::unselect_child>("unselect_child");
            gtkflowbox.method<&GtkFlowBox_::select_all>("select_all");
            gtkflowbox.method<&GtkFlowBox_::unselect_all>("unselect_all");
            gtkflowbox.method<&GtkFlowBox_::set_selection_mode>("set_selection_mode");
            gtkflowbox.method<&GtkFlowBox_::get_selection_mode>("get_selection_mode");
            gtkflowbox.method<&GtkFlowBox_::set_filter_func>("set_filter_func");
            gtkflowbox.method<&GtkFlowBox_::invalidate_filter>("invalidate_filter");
            gtkflowbox.method<&GtkFlowBox_::set_sort_func>("set_sort_func");
            gtkflowbox.method<&GtkFlowBox_::invalidate_sort>("invalidate_sort");
            gtkflowbox.method<&GtkFlowBox_::bind_model>("bind_model");


        // GtkStackTransitionType
        Php::Class<Php::Base> gtkstacktransitiontype("GtkStackTransitionType");
            gtkstacktransitiontype.constant("NONE", (int)GTK_STACK_TRANSITION_TYPE_NONE);
            gtkstacktransitiontype.constant("CROSSFADE", (int)GTK_STACK_TRANSITION_TYPE_CROSSFADE);
            gtkstacktransitiontype.constant("SLIDE_RIGHT", (int)GTK_STACK_TRANSITION_TYPE_SLIDE_RIGHT);
            gtkstacktransitiontype.constant("SLIDE_LEFT", (int)GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT);
            gtkstacktransitiontype.constant("SLIDE_UP", (int)GTK_STACK_TRANSITION_TYPE_SLIDE_UP);
            gtkstacktransitiontype.constant("SLIDE_DOWN", (int)GTK_STACK_TRANSITION_TYPE_SLIDE_DOWN);
            gtkstacktransitiontype.constant("SLIDE_LEFT_RIGHT", (int)GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
            gtkstacktransitiontype.constant("SLIDE_UP_DOWN", (int)GTK_STACK_TRANSITION_TYPE_SLIDE_UP_DOWN);
            gtkstacktransitiontype.constant("OVER_UP", (int)GTK_STACK_TRANSITION_TYPE_OVER_UP);
            gtkstacktransitiontype.constant("OVER_DOWN", (int)GTK_STACK_TRANSITION_TYPE_OVER_DOWN);
            gtkstacktransitiontype.constant("OVER_LEFT", (int)GTK_STACK_TRANSITION_TYPE_OVER_LEFT);
            gtkstacktransitiontype.constant("OVER_RIGHT", (int)GTK_STACK_TRANSITION_TYPE_OVER_RIGHT);
            gtkstacktransitiontype.constant("UNDER_UP", (int)GTK_STACK_TRANSITION_TYPE_UNDER_UP);
            gtkstacktransitiontype.constant("UNDER_DOWN", (int)GTK_STACK_TRANSITION_TYPE_UNDER_DOWN);
            gtkstacktransitiontype.constant("UNDER_LEF", (int)GTK_STACK_TRANSITION_TYPE_UNDER_LEFT);
            gtkstacktransitiontype.constant("UNDER_RIGHT", (int)GTK_STACK_TRANSITION_TYPE_UNDER_RIGHT);
            gtkstacktransitiontype.constant("OVER_UP_DOWN", (int)GTK_STACK_TRANSITION_TYPE_OVER_UP_DOWN);
            gtkstacktransitiontype.constant("OVER_DOWN_UP", (int)GTK_STACK_TRANSITION_TYPE_OVER_DOWN_UP);
            gtkstacktransitiontype.constant("OVER_LEFT_RIGHT", (int)GTK_STACK_TRANSITION_TYPE_OVER_LEFT_RIGHT);
            gtkstacktransitiontype.constant("OVER_RIGHT_LEFT", (int)GTK_STACK_TRANSITION_TYPE_OVER_RIGHT_LEFT);
        
        
        // GtkStack
        Php::Class<GtkStack_> gtkstack("GtkStack");
            gtkstack.extends(gtkcontainer);
            gtkstack.method<&GtkStack_::__construct>("__construct");
            gtkstack.method<&GtkStack_::add_named>("add_named");
            gtkstack.method<&GtkStack_::add_titled>("add_titled");
            gtkstack.method<&GtkStack_::get_child_by_name>("get_child_by_name");
            gtkstack.method<&GtkStack_::set_visible_child>("set_visible_child");
            gtkstack.method<&GtkStack_::get_visible_child>("get_visible_child");
            gtkstack.method<&GtkStack_::set_visible_child_name>("set_visible_child_name");
            gtkstack.method<&GtkStack_::get_visible_child_name>("get_visible_child_name");
            gtkstack.method<&GtkStack_::set_visible_child_full>("set_visible_child_full");
            gtkstack.method<&GtkStack_::set_homogeneous>("set_homogeneous");
            gtkstack.method<&GtkStack_::get_homogeneous>("get_homogeneous");
            gtkstack.method<&GtkStack_::set_hhomogeneous>("set_hhomogeneous");
            gtkstack.method<&GtkStack_::get_hhomogeneous>("get_hhomogeneous");
            gtkstack.method<&GtkStack_::set_vhomogeneous>("set_vhomogeneous");
            gtkstack.method<&GtkStack_::get_vhomogeneous>("get_vhomogeneous");
            gtkstack.method<&GtkStack_::set_transition_duration>("set_transition_duration");
            gtkstack.method<&GtkStack_::get_transition_duration>("get_transition_duration");
            gtkstack.method<&GtkStack_::set_transition_type>("set_transition_type");
            gtkstack.method<&GtkStack_::get_transition_type>("get_transition_type");
            gtkstack.method<&GtkStack_::get_transition_running>("get_transition_running");
            gtkstack.method<&GtkStack_::get_interpolate_size>("get_interpolate_size");
            gtkstack.method<&GtkStack_::set_interpolate_size>("set_interpolate_size");

        // GtkStackSwitcher
        Php::Class<GtkStackSwitcher_> gtkstackswitcher("GtkStackSwitcher");
            gtkstackswitcher.extends(gtkbox);
            gtkstackswitcher.method<&GtkStackSwitcher_::__construct>("__construct");
            gtkstackswitcher.method<&GtkStackSwitcher_::set_stack>("set_stack");
            gtkstackswitcher.method<&GtkStackSwitcher_::get_stack>("get_stack");
            gtkstackswitcher.method<&GtkStackSwitcher_::get_orientation>("get_orientation");
            gtkstackswitcher.method<&GtkStackSwitcher_::set_orientation>("set_orientation");

        // GtkStackSidebar
        Php::Class<GtkStackSidebar_> gtkstacksidebar("GtkStackSidebar");
            gtkstacksidebar.extends(gtkbin);
            gtkstacksidebar.method<&GtkStackSidebar_::__construct>("__construct");
            gtkstacksidebar.method<&GtkStackSidebar_::set_stack>("set_stack");
            gtkstacksidebar.method<&GtkStackSidebar_::get_stack>("get_stack");


        // GtkActionBar
        Php::Class<GtkActionBar_> gtkactionbar("GtkActionBar");
            gtkactionbar.extends(gtkbin);
            gtkactionbar.method<&GtkActionBar_::__construct>("__construct");
            gtkactionbar.method<&GtkActionBar_::pack_start>("pack_start");
            gtkactionbar.method<&GtkActionBar_::pack_end>("pack_end");
            gtkactionbar.method<&GtkActionBar_::get_center_widget>("get_center_widget");
            gtkactionbar.method<&GtkActionBar_::set_center_widget>("set_center_widget");
        

        // GtkHeaderBar
        Php::Class<GtkHeaderBar_> gtkheaderbar("GtkHeaderBar");
            gtkheaderbar.extends(gtkcontainer);
            gtkheaderbar.method<&GtkHeaderBar_::__construct>("__construct");
            gtkheaderbar.method<&GtkHeaderBar_::set_title>("set_title");
            gtkheaderbar.method<&GtkHeaderBar_::get_title>("get_title");
            gtkheaderbar.method<&GtkHeaderBar_::set_subtitle>("set_subtitle");
            gtkheaderbar.method<&GtkHeaderBar_::get_subtitle>("get_subtitle");
            gtkheaderbar.method<&GtkHeaderBar_::set_has_subtitle>("set_has_subtitle");
            gtkheaderbar.method<&GtkHeaderBar_::get_has_subtitle>("get_has_subtitle");
            gtkheaderbar.method<&GtkHeaderBar_::set_custom_title>("set_custom_title");
            gtkheaderbar.method<&GtkHeaderBar_::get_custom_title>("get_custom_title");
            gtkheaderbar.method<&GtkHeaderBar_::pack_start>("pack_start");
            gtkheaderbar.method<&GtkHeaderBar_::pack_end>("pack_end");
            gtkheaderbar.method<&GtkHeaderBar_::set_show_close_button>("set_show_close_button");
            gtkheaderbar.method<&GtkHeaderBar_::get_show_close_button>("get_show_close_button");
            gtkheaderbar.method<&GtkHeaderBar_::set_decoration_layout>("set_decoration_layout");
            gtkheaderbar.method<&GtkHeaderBar_::get_decoration_layout>("get_decoration_layout");


        // GtkOverlay
        Php::Class<GtkOverlay_> gtkoverlay("GtkOverlay");
            gtkoverlay.extends(gtkbin);
            gtkoverlay.method<&GtkOverlay_::__construct>("__construct");
            gtkoverlay.method<&GtkOverlay_::add_overlay>("add_overlay");
            gtkoverlay.method<&GtkOverlay_::reorder_overlay>("reorder_overlay");
            gtkoverlay.method<&GtkOverlay_::get_overlay_pass_through>("get_overlay_pass_through");
            gtkoverlay.method<&GtkOverlay_::set_overlay_pass_through>("set_overlay_pass_through");


        // GtkButtonBoxStyle
        Php::Class<Php::Base> gtkbuttonboxstyle("GtkButtonBoxStyle");
            gtkbuttonboxstyle.constant("SPREAD", (int)GTK_BUTTONBOX_SPREAD);
            gtkbuttonboxstyle.constant("EDGE", (int)GTK_BUTTONBOX_EDGE);
            gtkbuttonboxstyle.constant("START", (int)GTK_BUTTONBOX_START);
            gtkbuttonboxstyle.constant("END", (int)GTK_BUTTONBOX_END);
            gtkbuttonboxstyle.constant("CENTER", (int)GTK_BUTTONBOX_CENTER);
            gtkbuttonboxstyle.constant("EXPAND", (int)GTK_BUTTONBOX_EXPAND);
                

        // GtkButtonBox
        Php::Class<GtkButtonBox_> gtkbuttonbox("GtkButtonBox");
            gtkbuttonbox.extends(gtkbox);
            gtkbuttonbox.method<&GtkButtonBox_::__construct>("__construct");
            gtkbuttonbox.method<&GtkButtonBox_::get_layout>("get_layout");
            gtkbuttonbox.method<&GtkButtonBox_::get_child_secondary>("get_child_secondary");
            gtkbuttonbox.method<&GtkButtonBox_::get_child_non_homogeneous>("get_child_non_homogeneous");
            gtkbuttonbox.method<&GtkButtonBox_::set_layout>("set_layout");
            gtkbuttonbox.method<&GtkButtonBox_::set_child_secondary>("set_child_secondary");
            gtkbuttonbox.method<&GtkButtonBox_::set_child_non_homogeneous>("set_child_non_homogeneous");
        

        // GtkLayout
        Php::Class<GtkLayout_> gtklayout("GtkLayout");
            gtklayout.extends(gtkcontainer);
            gtklayout.method<&GtkLayout_::__construct>("__construct");
            gtklayout.method<&GtkLayout_::put>("put");
            gtklayout.method<&GtkLayout_::move>("move");
            gtklayout.method<&GtkLayout_::set_size>("set_size");
            gtklayout.method<&GtkLayout_::get_size>("get_size");
            gtklayout.method<&GtkLayout_::get_hadjustment>("get_hadjustment");
            gtklayout.method<&GtkLayout_::get_vadjustment>("get_vadjustment");
            gtklayout.method<&GtkLayout_::set_hadjustment>("set_hadjustment");
            gtklayout.method<&GtkLayout_::set_vadjustment>("set_vadjustment");
            gtklayout.method<&GtkLayout_::get_bin_window>("get_bin_window");


        // GtkExpander
        Php::Class<GtkExpander_> gtkexpander("GtkExpander");
            gtkexpander.extends(gtkbin);
            gtkexpander.method<&GtkExpander_::__construct>("__construct");
            gtkexpander.method<&GtkExpander_::new_with_mnemonic>("new_with_mnemonic");
            gtkexpander.method<&GtkExpander_::set_expanded>("set_expanded");
            gtkexpander.method<&GtkExpander_::get_expanded>("get_expanded");
            gtkexpander.method<&GtkExpander_::set_spacing>("set_spacing");
            gtkexpander.method<&GtkExpander_::get_spacing>("get_spacing");
            gtkexpander.method<&GtkExpander_::set_label>("set_label");
            gtkexpander.method<&GtkExpander_::get_label>("get_label");
            gtkexpander.method<&GtkExpander_::set_use_underline>("set_use_underline");
            gtkexpander.method<&GtkExpander_::get_use_underline>("get_use_underline");
            gtkexpander.method<&GtkExpander_::set_use_markup>("set_use_markup");
            gtkexpander.method<&GtkExpander_::get_use_markup>("get_use_markup");
            gtkexpander.method<&GtkExpander_::set_label_widget>("set_label_widget");
            gtkexpander.method<&GtkExpander_::get_label_widget>("get_label_widget");
            gtkexpander.method<&GtkExpander_::set_label_fill>("set_label_fill");
            gtkexpander.method<&GtkExpander_::get_label_fill>("get_label_fill");
            gtkexpander.method<&GtkExpander_::set_resize_toplevel>("set_resize_toplevel");
            gtkexpander.method<&GtkExpander_::get_resize_toplevel>("get_resize_toplevel");
        

        // GtkFrame
        Php::Class<GtkFrame_> gtkframe("GtkFrame");
            gtkframe.extends(gtkbin);
            gtkframe.method<&GtkFrame_::__construct>("__construct");
            gtkframe.method<&GtkFrame_::set_label>("set_label");
            gtkframe.method<&GtkFrame_::set_label_widget>("set_label_widget");
            gtkframe.method<&GtkFrame_::set_label_align>("set_label_align");
            gtkframe.method<&GtkFrame_::set_shadow_type>("set_shadow_type");
            gtkframe.method<&GtkFrame_::get_label>("get_label");
            gtkframe.method<&GtkFrame_::get_label_align>("get_label_align");
            gtkframe.method<&GtkFrame_::get_label_widget>("get_label_widget");
            gtkframe.method<&GtkFrame_::get_shadow_type>("get_shadow_type");
        

        // GtkAspectFrame
        Php::Class<GtkAspectFrame_> gtkaspectframe("GtkAspectFrame");
            gtkaspectframe.extends(gtkframe);
            gtkaspectframe.method<&GtkAspectFrame_::__construct>("__construct");
            gtkaspectframe.method<&GtkAspectFrame_::set>("set");


        // GtkResizeMode
        Php::Class<Php::Base> gtkresizemode("GtkResizeMode");
            gtkresizemode.constant("PARENT", (int)GTK_RESIZE_PARENT);
            gtkresizemode.constant("QUEUE", (int)GTK_RESIZE_QUEUE);
            gtkresizemode.constant("IMMEDIATE", (int)GTK_RESIZE_IMMEDIATE);

        // GtkWidgetPath
        Php::Class<GtkWidgetPath_> gtkwidgetpath("GtkWidgetPath");
            gtkwidgetpath.method<&GtkWidgetPath_::append_type>("append_type");
            gtkwidgetpath.method<&GtkWidgetPath_::append_with_siblings>("append_with_siblings");
            gtkwidgetpath.method<&GtkWidgetPath_::append_for_widget>("append_for_widget");
            gtkwidgetpath.method<&GtkWidgetPath_::copy>("copy");
            gtkwidgetpath.method<&GtkWidgetPath_::ref>("ref");
            gtkwidgetpath.method<&GtkWidgetPath_::unref>("unref");
            gtkwidgetpath.method<&GtkWidgetPath_::free>("free");
            gtkwidgetpath.method<&GtkWidgetPath_::get_object_type>("get_object_type");
            gtkwidgetpath.method<&GtkWidgetPath_::has_parent>("has_parent");
            gtkwidgetpath.method<&GtkWidgetPath_::is_type>("is_type");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_add_class>("iter_add_class");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_add_region>("iter_add_region");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_clear_classes>("iter_clear_classes");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_clear_regions>("iter_clear_regions");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_get_name>("iter_get_name");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_get_object_name>("iter_get_object_name");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_get_object_type>("iter_get_object_type");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_get_siblings>("iter_get_siblings");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_get_sibling_index>("iter_get_sibling_index");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_get_state>("iter_get_state");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_has_class>("iter_has_class");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_has_name>("iter_has_name");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_has_qclass>("iter_has_qclass");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_has_qname>("iter_has_qname");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_has_qregion>("iter_has_qregion");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_has_region>("iter_has_region");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_list_classes>("iter_list_classes");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_list_regions>("iter_list_regions");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_remove_class>("iter_remove_class");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_remove_region>("iter_remove_region");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_set_name>("iter_set_name");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_set_object_name>("iter_set_object_name");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_set_object_type>("iter_set_object_type");
            gtkwidgetpath.method<&GtkWidgetPath_::iter_set_state>("iter_set_state");
            gtkwidgetpath.method<&GtkWidgetPath_::length>("length");
            gtkwidgetpath.method<&GtkWidgetPath_::__construct>("new");
            gtkwidgetpath.method<&GtkWidgetPath_::prepend_type>("prepend_type");
            gtkwidgetpath.method<&GtkWidgetPath_::to_string>("to_string");
        

         // GtkImageType
        Php::Class<Php::Base> gtkimagetype("GtkImageType");
            gtkimagetype.constant("EMPTY", (int)GTK_IMAGE_EMPTY);
            gtkimagetype.constant("PIXBUF", (int)GTK_IMAGE_PIXBUF);
            gtkimagetype.constant("STOCK", (int)GTK_IMAGE_STOCK);
            gtkimagetype.constant("ICON_SET", (int)GTK_IMAGE_ICON_SET);
            gtkimagetype.constant("ANIMATION", (int)GTK_IMAGE_ANIMATION);
            gtkimagetype.constant("ICON_NAME", (int)GTK_IMAGE_ICON_NAME);
            gtkimagetype.constant("GICON", (int)GTK_IMAGE_GICON);
            gtkimagetype.constant("SURFACE", (int)GTK_IMAGE_SURFACE);

        // GtkImage
        Php::Class<GtkImage_> gtkimage("GtkImage");
            gtkimage.extends(gtkmisc);
            gtkimage.method<&GtkImage_::__construct>("__construct");
            gtkimage.method<&GtkImage_::new_from_file>("new_from_file");
            gtkimage.method<&GtkImage_::new_from_icon_set>("new_from_icon_set");
            gtkimage.method<&GtkImage_::get_icon_set>("get_icon_set");
            gtkimage.method<&GtkImage_::get_pixbuf>("get_pixbuf");
            gtkimage.method<&GtkImage_::get_stock>("get_stock");
            gtkimage.method<&GtkImage_::get_animation>("get_animation");
            gtkimage.method<&GtkImage_::get_icon_name>("get_icon_name");
            gtkimage.method<&GtkImage_::get_gicon>("get_gicon");
            gtkimage.method<&GtkImage_::get_storage_type>("get_storage_type");
            gtkimage.method<&GtkImage_::new_from_pixbuf>("new_from_pixbuf");
            gtkimage.method<&GtkImage_::new_from_stock>("new_from_stock");
            gtkimage.method<&GtkImage_::new_from_animation>("new_from_animation");
            gtkimage.method<&GtkImage_::new_from_icon_name>("new_from_icon_name");
            gtkimage.method<&GtkImage_::new_from_gicon>("new_from_gicon");
            gtkimage.method<&GtkImage_::new_from_resource>("new_from_resource");
            gtkimage.method<&GtkImage_::new_from_surface>("new_from_surface");
            gtkimage.method<&GtkImage_::set_from_file>("set_from_file");
            gtkimage.method<&GtkImage_::set_from_icon_set>("set_from_icon_set");
            gtkimage.method<&GtkImage_::set_from_pixbuf>("set_from_pixbuf");
            gtkimage.method<&GtkImage_::set_from_stock>("set_from_stock");
            gtkimage.method<&GtkImage_::set_from_animation>("set_from_animation");
            gtkimage.method<&GtkImage_::set_from_icon_name>("set_from_icon_name");
            gtkimage.method<&GtkImage_::set_from_gicon>("set_from_gicon");
            gtkimage.method<&GtkImage_::set_from_resource>("set_from_resource");
            gtkimage.method<&GtkImage_::set_from_surface>("set_from_surface");
            gtkimage.method<&GtkImage_::clear>("clear");
            gtkimage.method<&GtkImage_::set_pixel_size>("set_pixel_size");
            gtkimage.method<&GtkImage_::get_pixel_size>("get_pixel_size");
        

        // GtkCalendarDisplayOptions
        Php::Class<Php::Base> gtkcalendardisplayoptions("GtkCalendarDisplayOptions");
            gtkcalendardisplayoptions.constant("SHOW_HEADING", (int)GTK_CALENDAR_SHOW_HEADING);
            gtkcalendardisplayoptions.constant("SHOW_DAY_NAMES", (int)GTK_CALENDAR_SHOW_DAY_NAMES);
            gtkcalendardisplayoptions.constant("NO_MONTH_CHANGE", (int)GTK_CALENDAR_NO_MONTH_CHANGE);
            gtkcalendardisplayoptions.constant("SHOW_WEEK_NUMBERS", (int)GTK_CALENDAR_SHOW_WEEK_NUMBERS);
            gtkcalendardisplayoptions.constant("SHOW_DETAILS", (int)GTK_CALENDAR_SHOW_DETAILS);
            

        // GtkCalendar
        Php::Class<GtkCalendar_> gtkcalendar("GtkCalendar");
            gtkcalendar.extends(gtkwidget);
            gtkcalendar.method<&GtkCalendar_::__construct>("__construct");
            gtkcalendar.method<&GtkCalendar_::select_month>("select_month");
            gtkcalendar.method<&GtkCalendar_::select_day>("select_day");
            gtkcalendar.method<&GtkCalendar_::mark_day>("mark_day");
            gtkcalendar.method<&GtkCalendar_::unmark_day>("unmark_day");
            gtkcalendar.method<&GtkCalendar_::get_day_is_marked>("get_day_is_marked");
            gtkcalendar.method<&GtkCalendar_::clear_marks>("clear_marks");
            gtkcalendar.method<&GtkCalendar_::get_display_options>("get_display_options");
            gtkcalendar.method<&GtkCalendar_::set_display_options>("set_display_options");
            gtkcalendar.method<&GtkCalendar_::get_date>("get_date");
            gtkcalendar.method<&GtkCalendar_::set_detail_func>("set_detail_func");
            gtkcalendar.method<&GtkCalendar_::get_detail_width_chars>("get_detail_width_chars");
            gtkcalendar.method<&GtkCalendar_::set_detail_width_chars>("set_detail_width_chars");
            gtkcalendar.method<&GtkCalendar_::get_detail_height_rows>("get_detail_height_rows");
            gtkcalendar.method<&GtkCalendar_::set_detail_height_rows>("set_detail_height_rows");
        

        // GtkSpinner
        Php::Class<GtkSpinner_> gtkspinner("GtkSpinner");
            gtkspinner.extends(gtkwidget);
            gtkspinner.method<&GtkSpinner_::__construct>("__construct");
            gtkspinner.method<&GtkSpinner_::start>("start");
            gtkspinner.method<&GtkSpinner_::stop>("stop");


        // GtkInfoBar
        Php::Class<GtkInfoBar_> gtkinfobar("GtkInfoBar");
            gtkinfobar.extends(gtkbox);
            gtkinfobar.method<&GtkInfoBar_::__construct>("__construct");
            gtkinfobar.method<&GtkInfoBar_::new_with_buttons>("new_with_buttons");
            gtkinfobar.method<&GtkInfoBar_::add_action_widget>("add_action_widget");
            gtkinfobar.method<&GtkInfoBar_::add_button>("add_button");
            gtkinfobar.method<&GtkInfoBar_::add_buttons>("add_buttons");
            gtkinfobar.method<&GtkInfoBar_::set_response_sensitive>("set_response_sensitive");
            gtkinfobar.method<&GtkInfoBar_::set_default_response>("set_default_response");
            gtkinfobar.method<&GtkInfoBar_::response>("response");
            gtkinfobar.method<&GtkInfoBar_::set_message_type>("set_message_type");
            gtkinfobar.method<&GtkInfoBar_::get_message_type>("get_message_type");
            gtkinfobar.method<&GtkInfoBar_::get_action_area>("get_action_area");
            gtkinfobar.method<&GtkInfoBar_::get_content_area>("get_content_area");
            gtkinfobar.method<&GtkInfoBar_::get_show_close_button>("get_show_close_button");
            gtkinfobar.method<&GtkInfoBar_::set_show_close_button>("set_show_close_button");


        // GtkProgressBar
        Php::Class<GtkProgressBar_> gtkprogressbar("GtkProgressBar");
            gtkprogressbar.extends(gtkwidget);
            gtkprogressbar.method<&GtkProgressBar_::__construct>("__construct");
            gtkprogressbar.method<&GtkProgressBar_::pulse>("pulse");
            gtkprogressbar.method<&GtkProgressBar_::set_fraction>("set_fraction");
            gtkprogressbar.method<&GtkProgressBar_::get_fraction>("get_fraction");
            gtkprogressbar.method<&GtkProgressBar_::set_inverted>("set_inverted");
            gtkprogressbar.method<&GtkProgressBar_::get_inverted>("get_inverted");
            gtkprogressbar.method<&GtkProgressBar_::set_show_text>("set_show_text");
            gtkprogressbar.method<&GtkProgressBar_::get_show_text>("get_show_text");
            gtkprogressbar.method<&GtkProgressBar_::set_text>("set_text");
            gtkprogressbar.method<&GtkProgressBar_::get_text>("get_text");
            gtkprogressbar.method<&GtkProgressBar_::set_ellipsize>("set_ellipsize");
            gtkprogressbar.method<&GtkProgressBar_::get_ellipsize>("get_ellipsize");
            gtkprogressbar.method<&GtkProgressBar_::set_pulse_step>("set_pulse_step");
            gtkprogressbar.method<&GtkProgressBar_::get_pulse_step>("get_pulse_step");


        // GtkCssProviderError
        Php::Class<Php::Base> gtkcssprovidererror("GtkCssProviderError");
            gtkcssprovidererror.constant("FAILED", (int)GTK_CSS_PROVIDER_ERROR_FAILED);
            gtkcssprovidererror.constant("SYNTAX", (int)GTK_CSS_PROVIDER_ERROR_SYNTAX);
            gtkcssprovidererror.constant("IMPORT", (int)GTK_CSS_PROVIDER_ERROR_IMPORT);
            gtkcssprovidererror.constant("NAME", (int)GTK_CSS_PROVIDER_ERROR_NAME);
            gtkcssprovidererror.constant("UNKNOWN_VALUE", (int)GTK_CSS_PROVIDER_ERROR_UNKNOWN_VALUE);
            gtkcssprovidererror.constant("DEPRECATED", (int)GTK_CSS_PROVIDER_ERROR_DEPRECATED);
        
        // GtkCssSectionType
        Php::Class<Php::Base> gtkcsssectiontype("GtkCssSectionType");
            gtkcsssectiontype.constant("DOCUMENT", (int)GTK_CSS_SECTION_DOCUMENT);
            gtkcsssectiontype.constant("IMPORT", (int)GTK_CSS_SECTION_IMPORT);
            gtkcsssectiontype.constant("COLOR_DEFINITION", (int)GTK_CSS_SECTION_COLOR_DEFINITION);
            gtkcsssectiontype.constant("BINDING_SET", (int)GTK_CSS_SECTION_BINDING_SET);
            gtkcsssectiontype.constant("RULESET", (int)GTK_CSS_SECTION_RULESET);
            gtkcsssectiontype.constant("SELECTOR", (int)GTK_CSS_SECTION_SELECTOR);
            gtkcsssectiontype.constant("DECLARATION", (int)GTK_CSS_SECTION_DECLARATION);
            gtkcsssectiontype.constant("VALUE", (int)GTK_CSS_SECTION_VALUE);
            gtkcsssectiontype.constant("KEYFRAMES", (int)GTK_CSS_SECTION_KEYFRAMES);

        // GtkCssProvider
        Php::Class<GtkCssProvider_> gtkcssprovider("GtkCssProvider");
            gtkcssprovider.extends(gobject);
            gtkcssprovider.method<&GtkCssProvider_::get_named>("get_named");
            gtkcssprovider.method<&GtkCssProvider_::load_from_data>("load_from_data");
            gtkcssprovider.method<&GtkCssProvider_::load_from_file>("load_from_file");
            gtkcssprovider.method<&GtkCssProvider_::load_from_path>("load_from_path");
            gtkcssprovider.method<&GtkCssProvider_::load_from_resource>("load_from_resource");
            gtkcssprovider.method<&GtkCssProvider_::__construct>("__construct");
            gtkcssprovider.method<&GtkCssProvider_::to_string>("to_string");
            gtkcssprovider.method<&GtkCssProvider_::gtk_css_section_get_end_line>("gtk_css_section_get_end_line");
            gtkcssprovider.method<&GtkCssProvider_::gtk_css_section_get_end_position>("gtk_css_section_get_end_position");
            gtkcssprovider.method<&GtkCssProvider_::gtk_css_section_get_file>("gtk_css_section_get_file");
            gtkcssprovider.method<&GtkCssProvider_::gtk_css_section_get_parent>("gtk_css_section_get_parent");
            gtkcssprovider.method<&GtkCssProvider_::gtk_css_section_get_section_type>("gtk_css_section_get_section_type");
            gtkcssprovider.method<&GtkCssProvider_::gtk_css_section_get_start_line>("gtk_css_section_get_start_line");
            gtkcssprovider.method<&GtkCssProvider_::gtk_css_section_get_start_position>("gtk_css_section_get_start_position");
            gtkcssprovider.method<&GtkCssProvider_::gtk_css_section_ref>("gtk_css_section_ref");
            gtkcssprovider.method<&GtkCssProvider_::gtk_css_section_unref>("gtk_css_section_unref");

        // GtkStyleContext
        Php::Class<GtkStyleContext_> gtkstylecontext("GtkStyleContext");
            gtkstylecontext.extends(gobject);
            gtkstylecontext.method<&GtkStyleContext_::__construct>("__construct");
            gtkstylecontext.method<&GtkStyleContext_::add_provider>("add_provider");
            gtkstylecontext.method<&GtkStyleContext_::add_provider_for_screen>("add_provider_for_screen");
            gtkstylecontext.method<&GtkStyleContext_::get>("get");
            gtkstylecontext.method<&GtkStyleContext_::get_direction>("get_direction");
            gtkstylecontext.method<&GtkStyleContext_::get_junction_sides>("get_junction_sides");
            gtkstylecontext.method<&GtkStyleContext_::get_parent>("get_parent");
            gtkstylecontext.method<&GtkStyleContext_::get_path>("get_path");
            gtkstylecontext.method<&GtkStyleContext_::get_property>("get_property");
            gtkstylecontext.method<&GtkStyleContext_::get_screen>("get_screen");
            gtkstylecontext.method<&GtkStyleContext_::get_frame_clock>("get_frame_clock");
            gtkstylecontext.method<&GtkStyleContext_::get_state>("get_state");
            gtkstylecontext.method<&GtkStyleContext_::get_style>("get_style");
            gtkstylecontext.method<&GtkStyleContext_::get_style_property>("get_style_property");
            gtkstylecontext.method<&GtkStyleContext_::get_style_valist>("get_style_valist");
            gtkstylecontext.method<&GtkStyleContext_::get_valist>("get_valist");
            gtkstylecontext.method<&GtkStyleContext_::get_section>("get_section");
            gtkstylecontext.method<&GtkStyleContext_::get_color>("get_color");
            gtkstylecontext.method<&GtkStyleContext_::get_background_color>("get_background_color");
            gtkstylecontext.method<&GtkStyleContext_::get_border_color>("get_border_color");
            gtkstylecontext.method<&GtkStyleContext_::get_border>("get_border");
            gtkstylecontext.method<&GtkStyleContext_::get_padding>("get_padding");
            gtkstylecontext.method<&GtkStyleContext_::get_margin>("get_margin");
            gtkstylecontext.method<&GtkStyleContext_::get_font>("get_font");
            gtkstylecontext.method<&GtkStyleContext_::invalidate>("invalidate");
            gtkstylecontext.method<&GtkStyleContext_::state_is_running>("state_is_running");
            gtkstylecontext.method<&GtkStyleContext_::lookup_color>("lookup_color");
            gtkstylecontext.method<&GtkStyleContext_::lookup_icon_set>("lookup_icon_set");
            gtkstylecontext.method<&GtkStyleContext_::notify_state_change>("notify_state_change");
            gtkstylecontext.method<&GtkStyleContext_::pop_animatable_region>("pop_animatable_region");
            gtkstylecontext.method<&GtkStyleContext_::push_animatable_region>("push_animatable_region");
            gtkstylecontext.method<&GtkStyleContext_::cancel_animations>("cancel_animations");
            gtkstylecontext.method<&GtkStyleContext_::scroll_animations>("scroll_animations");
            gtkstylecontext.method<&GtkStyleContext_::remove_provider>("remove_provider");
            gtkstylecontext.method<&GtkStyleContext_::remove_provider_for_screen>("remove_provider_for_screen");
            gtkstylecontext.method<&GtkStyleContext_::reset_widgets>("reset_widgets");
            gtkstylecontext.method<&GtkStyleContext_::set_background>("set_background");
            gtkstylecontext.method<&GtkStyleContext_::restore>("restore");
            gtkstylecontext.method<&GtkStyleContext_::save>("save");
            gtkstylecontext.method<&GtkStyleContext_::set_direction>("set_direction");
            gtkstylecontext.method<&GtkStyleContext_::set_junction_sides>("set_junction_sides");
            gtkstylecontext.method<&GtkStyleContext_::set_parent>("set_parent");
            gtkstylecontext.method<&GtkStyleContext_::set_path>("set_path");
            gtkstylecontext.method<&GtkStyleContext_::add_class>("add_class");
            gtkstylecontext.method<&GtkStyleContext_::remove_class>("remove_class");
            gtkstylecontext.method<&GtkStyleContext_::has_class>("has_class");
            gtkstylecontext.method<&GtkStyleContext_::list_classes>("list_classes");
            gtkstylecontext.method<&GtkStyleContext_::add_region>("add_region");
            gtkstylecontext.method<&GtkStyleContext_::remove_region>("remove_region");
            gtkstylecontext.method<&GtkStyleContext_::has_region>("has_region");
            gtkstylecontext.method<&GtkStyleContext_::list_regions>("list_regions");
            gtkstylecontext.method<&GtkStyleContext_::set_screen>("set_screen");
            gtkstylecontext.method<&GtkStyleContext_::set_frame_clock>("set_frame_clock");
            gtkstylecontext.method<&GtkStyleContext_::set_state>("set_state");
            gtkstylecontext.method<&GtkStyleContext_::set_scale>("set_scale");
            gtkstylecontext.method<&GtkStyleContext_::get_scale>("get_scale");
            gtkstylecontext.method<&GtkStyleContext_::to_string>("to_string");
            gtkstylecontext.method<&GtkStyleContext_::gtk_border_new>("gtk_border_new");
            gtkstylecontext.method<&GtkStyleContext_::gtk_border_copy>("gtk_border_copy");
            gtkstylecontext.method<&GtkStyleContext_::gtk_border_free>("gtk_border_free");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_arrow>("gtk_render_arrow");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_background>("gtk_render_background");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_background_get_clip>("gtk_render_background_get_clip");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_check>("gtk_render_check");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_expander>("gtk_render_expander");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_extension>("gtk_render_extension");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_focus>("gtk_render_focus");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_frame>("gtk_render_frame");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_frame_gap>("gtk_render_frame_gap");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_handle>("gtk_render_handle");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_layout>("gtk_render_layout");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_line>("gtk_render_line");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_option>("gtk_render_option");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_slider>("gtk_render_slider");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_activity>("gtk_render_activity");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_icon_pixbuf>("gtk_render_icon_pixbuf");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_icon_surface>("gtk_render_icon_surface");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_icon>("gtk_render_icon");
            gtkstylecontext.method<&GtkStyleContext_::gtk_render_insertion_cursor>("gtk_render_insertion_cursor");

        // GtkRecentChooserError
        Php::Class<Php::Base> gtkrecentchoosererror("GtkRecentChooserError");
            gtkrecentchoosererror.constant("NOT_FOUND", (int)GTK_RECENT_CHOOSER_ERROR_NOT_FOUND);
            gtkrecentchoosererror.constant("INVALID_URI", (int)GTK_RECENT_CHOOSER_ERROR_INVALID_URI);

        // GtkRecentSortType
        Php::Class<Php::Base> gtkrecentsorttype("GtkRecentSortType");
            gtkrecentsorttype.constant("NONE", (int)GTK_RECENT_SORT_NONE);
            gtkrecentsorttype.constant("MRU", (int)GTK_RECENT_SORT_MRU);
            gtkrecentsorttype.constant("LRU", (int)GTK_RECENT_SORT_LRU);
            gtkrecentsorttype.constant("CUSTOM", (int)GTK_RECENT_SORT_CUSTOM);

        // GtkRecentChooserDialog
        Php::Class<GtkRecentChooserDialog_> gtkrecentchooserdialog("GtkRecentChooserDialog");
            gtkrecentchooserdialog.extends(gtkdialog);
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::__construct>("__construct");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::new_for_manager>("new_for_manager");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::set_show_private>("set_show_private");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_show_private>("get_show_private");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::set_show_not_found>("set_show_not_found");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_show_not_found>("get_show_not_found");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::set_show_icons>("set_show_icons");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_show_icons>("get_show_icons");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::set_select_multiple>("set_select_multiple");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_select_multiple>("get_select_multiple");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::set_local_only>("set_local_only");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_local_only>("get_local_only");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::set_limit>("set_limit");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_limit>("get_limit");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::set_show_tips>("set_show_tips");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_show_tips>("get_show_tips");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::set_sort_type>("set_sort_type");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_sort_type>("get_sort_type");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::set_sort_func>("set_sort_func");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::set_current_uri>("set_current_uri");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_current_uri>("get_current_uri");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_current_item>("get_current_item");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::select_uri>("select_uri");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::unselect_uri>("unselect_uri");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::select_all>("select_all");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::unselect_all>("unselect_all");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_items>("get_items");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_uris>("get_uris");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::add_filter>("add_filter");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::remove_filter>("remove_filter");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::list_filters>("list_filters");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::set_filter>("set_filter");
            gtkrecentchooserdialog.method<&GtkRecentChooserDialog_::get_filter>("get_filter");

        // GtkArrowType
        Php::Class<Php::Base> gtkarrowtype("GtkArrowType");
            gtkarrowtype.constant("UP", (int)GTK_ARROW_UP);
            gtkarrowtype.constant("DOWN", (int)GTK_ARROW_DOWN);
            gtkarrowtype.constant("LEFT", (int)GTK_ARROW_LEFT);
            gtkarrowtype.constant("RIGHT", (int)GTK_ARROW_RIGHT);
            gtkarrowtype.constant("NONE", (int)GTK_ARROW_NONE);


#ifdef WITH_MAC_INTEGRATION
        // gtkosxapplication
        Php::Class<GtkosxApplication_> gtkosxapplication("GtkosxApplication");
            //gtkosxapplication.extends(gobject);
            gtkosxapplication.method<&GtkosxApplication_::__construct>("__construct");
            gtkosxapplication.method<&GtkosxApplication_::set_dock_icon_pixbuf>("set_dock_icon_pixbuf");
            gtkosxapplication.method<&GtkosxApplication_::sync_menubar>("sync_menubar");
            gtkosxapplication.method<&GtkosxApplication_::ready>("ready");
            gtkosxapplication.method<&GtkosxApplication_::set_use_quartz_accelerators>("set_use_quartz_accelerators");
            gtkosxapplication.method<&GtkosxApplication_::use_quartz_accelerators>("use_quartz_accelerators");
            gtkosxapplication.method<&GtkosxApplication_::set_menu_bar>("set_menu_bar");
            gtkosxapplication.method<&GtkosxApplication_::insert_app_menu_item>("insert_app_menu_item");
            gtkosxapplication.method<&GtkosxApplication_::set_window_menu>("set_window_menu");
            gtkosxapplication.method<&GtkosxApplication_::set_help_menu>("set_help_menu");
            gtkosxapplication.method<&GtkosxApplication_::set_dock_menu>("set_dock_menu");
            gtkosxapplication.method<&GtkosxApplication_::set_dock_icon_resource>("set_dock_icon_resource");
            gtkosxapplication.method<&GtkosxApplication_::attention_request>("attention_request");
            gtkosxapplication.method<&GtkosxApplication_::cancel_attention_request>("cancel_attention_request");
            gtkosxapplication.method<&GtkosxApplication_::get_bundle_path>("get_bundle_path");
            gtkosxapplication.method<&GtkosxApplication_::get_resource_path>("get_resource_path");
            gtkosxapplication.method<&GtkosxApplication_::get_executable_path>("get_executable_path");
            gtkosxapplication.method<&GtkosxApplication_::get_bundle_id>("get_bundle_id");
            gtkosxapplication.method<&GtkosxApplication_::get_bundle_info>("get_bundle_info");
#endif



#ifdef WITH_LIBWNCK
            Php::Class<WnckScreen_> wnckscreen("WnckScreen");
            wnckscreen.extends(gobject);
            wnckscreen.method<&WnckScreen_::get_default>("get_default");
            wnckscreen.method<&WnckScreen_::get_active_window>("get_active_window");
            wnckscreen.method<&WnckScreen_::get_width>("get_width");
            wnckscreen.method<&WnckScreen_::get_height>("get_height");

            Php::Class<WnckWindow_> wnckwindow("WnckWindow");
            wnckwindow.extends(gobject);
            wnckwindow.method<&WnckWindow_::get_name>("get_name");
            wnckwindow.method<&WnckWindow_::get_icon>("get_icon");
            wnckwindow.method<&WnckWindow_::get_window_type>("get_window_type");
            wnckwindow.method<&WnckWindow_::get_xid>("get_xid");
            wnckwindow.method<&WnckWindow_::get_pid>("get_pid");
            wnckwindow.method<&WnckWindow_::get_class_group>("get_class_group");
            wnckwindow.method<&WnckWindow_::is_active>("is_active");
            wnckwindow.method<&WnckWindow_::activate>("activate");
            wnckwindow.method<&WnckWindow_::minimize>("minimize");
            wnckwindow.method<&WnckWindow_::get_window>("get");
            wnckwindow.method<&WnckWindow_::close>("close");
            wnckwindow.constant("NORMAL", (int)WNCK_WINDOW_NORMAL);
            wnckwindow.constant("DESKTOP", (int)WNCK_WINDOW_DESKTOP);
            wnckwindow.constant("DOCK", (int)WNCK_WINDOW_DOCK);
            wnckwindow.constant("DIALOG", (int)WNCK_WINDOW_DIALOG);
            wnckwindow.constant("TOOLBAR", (int)WNCK_WINDOW_TOOLBAR);
            wnckwindow.constant("MENU", (int)WNCK_WINDOW_MENU);
            wnckwindow.constant("UTILITY", (int)WNCK_WINDOW_UTILITY);
            wnckwindow.constant("SPLASHSCREEN", (int)WNCK_WINDOW_SPLASHSCREEN);

            Php::Class<WnckClassGroup_> wnckclassgroup("WnckClassGroup");
            wnckclassgroup.extends(gobject);
            wnckclassgroup.method<&WnckClassGroup_::get_id>("get_id");
            wnckclassgroup.method<&WnckClassGroup_::get_name>("get_name");
            wnckclassgroup.method<&WnckClassGroup_::get_icon>("get_icon");
            wnckclassgroup.method<&WnckClassGroup_::get_mini_icon>("get_mini_icon");
            wnckclassgroup.method<&WnckClassGroup_::get_windows>("get_windows");
#endif

/**
 * Add classes to extension
 */
        extension.add(std::move(gobject));
        extension.add(std::move(gdk));
        extension.add(std::move(gdkvisual));
        extension.add(std::move(gdkevent));
        extension.add(std::move(gdkeventbutton));
        extension.add(std::move(gdkeventkey));
        extension.add(std::move(gdkeventtype));
        extension.add(std::move(gdkpixbuf));
        extension.add(std::move(gdkdrawable));
        extension.add(std::move(gdkinterptype));
        extension.add(std::move(gdkrgba));
        
        extension.add(std::move(gdkpixbufformat));
        extension.add(std::move(gdkpixbufalphamode));
        extension.add(std::move(gdkmodifiertype));
        extension.add(std::move(gdkcolorspace));
        extension.add(std::move(gdkscreen));
        extension.add(std::move(gdkdisplay));
        extension.add(std::move(gdkmonitor));
        
        extension.add(std::move(gdkwindow));
        extension.add(std::move(gdkbyteorder));
        extension.add(std::move(gdkvisualtype));
        extension.add(std::move(gdkwindowtype));
        extension.add(std::move(gdkwindowwindowclass));
        extension.add(std::move(gdkwindowhints));
        extension.add(std::move(gdkgravity));
        extension.add(std::move(gdkanchorhints));
        extension.add(std::move(gdkwindowedge));
        extension.add(std::move(gdkwindowattributestype));
        extension.add(std::move(gdkfullscreenmode));
        extension.add(std::move(gdkfilterreturn));
        extension.add(std::move(gdkmodifierintent));
        extension.add(std::move(gdkwmdecoration));
        extension.add(std::move(gdkwmfunction));

        extension.add(std::move(gapplication));

        extension.add(std::move(gtk));
        extension.add(std::move(gtkapplication));
        extension.add(std::move(gtkapplicationinhibitflag));
        extension.add(std::move(gtkorientation));
        extension.add(std::move(gtkpolicytype));
        extension.add(std::move(gtkwidget));
        extension.add(std::move(gtkmisc));
        extension.add(std::move(gtkcontainer));
        extension.add(std::move(gtkbox));
        extension.add(std::move(gtkgrid));
        extension.add(std::move(gtkfixed));
        extension.add(std::move(gtkhbox));
        extension.add(std::move(gtkvbox));
        extension.add(std::move(gtkbin));
        extension.add(std::move(gtkeventbox));
        extension.add(std::move(gtkpaned));
        extension.add(std::move(gtkwindow));
        extension.add(std::move(gtkdialog));
        extension.add(std::move(gtkappchooserdialog));
        extension.add(std::move(gtkfilechooserdialog));
        extension.add(std::move(gtkcolorchooserdialog));
        extension.add(std::move(gtkprintsettings));
        
        // extension.add(std::move(gtkpagesetupunixdialog));
        extension.add(std::move(gtkpagesetup));
        extension.add(std::move(gtkpapersize));
        extension.add(std::move(gtkunit));
        extension.add(std::move(gtkpageset));
        extension.add(std::move(gtkprintpages));
        extension.add(std::move(gtknumberuplayout));
        extension.add(std::move(gtkprintquality));
        extension.add(std::move(gtkprintduplex));
        extension.add(std::move(gtkpageorientation));
        extension.add(std::move(gtklicense));
        extension.add(std::move(gtkbutton));
        extension.add(std::move(gtkfontbutton));
        extension.add(std::move(gtkcolorbutton));
        extension.add(std::move(gtktogglebutton));
        extension.add(std::move(gtkcheckbutton));
        extension.add(std::move(gtkradiobutton));
        extension.add(std::move(gtkadjustment));
        extension.add(std::move(gtkscrolledwindow));
        extension.add(std::move(gtkentrybuffer));
        extension.add(std::move(gtkentry));
        extension.add(std::move(gtkentrycompletion));
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
        extension.add(std::move(gtkfilefilter));
        extension.add(std::move(gtkmessagetype));
        extension.add(std::move(gtkbuttonstype));
        extension.add(std::move(gtkmessagedialog));
        extension.add(std::move(gtkaboutdialog));
        extension.add(std::move(gtkfontchooserdialog));
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

        extension.add(std::move(gtkstatusbar));

        extension.add(std::move(gtklistboxrow));
        extension.add(std::move(gtklistbox));

        extension.add(std::move(gtksensitivitytype));
        extension.add(std::move(gtkcombobox));
        extension.add(std::move(gtkcomboboxtext));
        extension.add(std::move(gtkappchooserbutton));

        extension.add(std::move(gtkbuilder));

        extension.add(std::move(gtkbaselineposition));
        extension.add(std::move(gtkdeletetype));
        extension.add(std::move(gtkdirectiontype));
        extension.add(std::move(gtkmovementstep));
        extension.add(std::move(gtkscrollstep));
        extension.add(std::move(gtkscrolltype));
        extension.add(std::move(gtkshadowtype));
        extension.add(std::move(gtkstateflags));

        extension.add(std::move(gtkrevealertransitiontype));
        extension.add(std::move(gtkrevealer));

        extension.add(std::move(gladeapp));
        extension.add(std::move(gladedesignview));
        extension.add(std::move(gladeproject));
        extension.add(std::move(gladeeditor));
        extension.add(std::move(gladepalette));
        extension.add(std::move(gladewidget));

        extension.add(std::move(gtkflowboxchild));
        extension.add(std::move(gtkflowbox));

        extension.add(std::move(gtkstacktransitiontype));
        extension.add(std::move(gtkstack));
        extension.add(std::move(gtkstackswitcher));
        extension.add(std::move(gtkstacksidebar));

        extension.add(std::move(gtkactionbar));
        extension.add(std::move(gtkheaderbar));
        extension.add(std::move(gtkoverlay));

        extension.add(std::move(gtkbuttonboxstyle));
        extension.add(std::move(gtkbuttonbox));

        extension.add(std::move(gtklayout));
        extension.add(std::move(gtkexpander));
        extension.add(std::move(gtkframe));

        extension.add(std::move(gtkaspectframe));

        extension.add(std::move(gtkresizemode));

        extension.add(std::move(gtkwidgetpath));
        
        extension.add(std::move(gtkimagetype));
        extension.add(std::move(gtkimage));

        extension.add(std::move(gtkcalendardisplayoptions));
        extension.add(std::move(gtkcalendar));

        extension.add(std::move(gtkspinner));

        extension.add(std::move(gtkinfobar));

        extension.add(std::move(gtkprogressbar));

        extension.add(std::move(gtkcssprovidererror));
        extension.add(std::move(gtkcsssectiontype));
        extension.add(std::move(gtkcssprovider));
        extension.add(std::move(gtkstylecontext));

        extension.add(std::move(gtkrecentchoosererror));
        extension.add(std::move(gtkrecentsorttype));
        extension.add(std::move(gtkrecentchooserdialog));

        extension.add(std::move(gtkarrowtype));

#ifdef WITH_MAC_INTEGRATION
        extension.add(std::move(gtkosxapplication));
#endif

#ifdef WITH_LIBWNCK
        extension.add(std::move(wnckscreen));
        extension.add(std::move(wnckwindow));
        extension.add(std::move(wnckclassgroup));
#endif



/**
 * GtkSourceView
 */
      // GtkSourceSmartHomeEndType
        Php::Class<Php::Base> gtksourcesmarthomeendtype("GtkSourceSmartHomeEndType");
            gtksourcesmarthomeendtype.constant("DISABLED", (int)GTK_SOURCE_SMART_HOME_END_DISABLED);
            gtksourcesmarthomeendtype.constant("BEFORE", (int)GTK_SOURCE_SMART_HOME_END_BEFORE);
            gtksourcesmarthomeendtype.constant("AFTER", (int)GTK_SOURCE_SMART_HOME_END_AFTER);
            gtksourcesmarthomeendtype.constant("ALWAYS", (int)GTK_SOURCE_SMART_HOME_END_ALWAYS);

        // GtkSourceDrawSpacesFlags
        Php::Class<Php::Base> gtksourcedrawspacesflags("GtkSourceDrawSpacesFlags");
            gtksourcedrawspacesflags.constant("SPACE", (int)GTK_SOURCE_DRAW_SPACES_SPACE);
            gtksourcedrawspacesflags.constant("TAB", (int)GTK_SOURCE_DRAW_SPACES_TAB);
            gtksourcedrawspacesflags.constant("NEWLINE", (int)GTK_SOURCE_DRAW_SPACES_NEWLINE);
            gtksourcedrawspacesflags.constant("NBSP", (int)GTK_SOURCE_DRAW_SPACES_NBSP);
            gtksourcedrawspacesflags.constant("LEADING", (int)GTK_SOURCE_DRAW_SPACES_LEADING);
            gtksourcedrawspacesflags.constant("TEXT", (int)GTK_SOURCE_DRAW_SPACES_TEXT);
            gtksourcedrawspacesflags.constant("TRAILING", (int)GTK_SOURCE_DRAW_SPACES_TRAILING);
            gtksourcedrawspacesflags.constant("ALL", (int)GTK_SOURCE_DRAW_SPACES_ALL);

        // GtkSourceBackgroundPatternType
        Php::Class<Php::Base> gtksourcebackgroundpatterntype("GtkSourceBackgroundPatternType");
            gtksourcebackgroundpatterntype.constant("NONE", (int)GTK_SOURCE_BACKGROUND_PATTERN_TYPE_NONE);
            gtksourcebackgroundpatterntype.constant("GRID", (int)GTK_SOURCE_BACKGROUND_PATTERN_TYPE_GRID);
        
        // GtkSourceView
        Php::Class<GtkSourceView_> gtksourceview("GtkSourceView");
            gtksourceview.extends(gtktextview);
            gtksourceview.method<&GtkSourceView_::__construct>("__construct");
            gtksourceview.method<&GtkSourceView_::new_with_buffer>("new_with_buffer");
            gtksourceview.method<&GtkSourceView_::set_show_line_numbers>("set_show_line_numbers");
            gtksourceview.method<&GtkSourceView_::get_show_line_numbers>("get_show_line_numbers");
            gtksourceview.method<&GtkSourceView_::set_show_right_margin>("set_show_right_margin");
            gtksourceview.method<&GtkSourceView_::get_show_right_margin>("get_show_right_margin");
            gtksourceview.method<&GtkSourceView_::set_right_margin_position>("set_right_margin_position");
            gtksourceview.method<&GtkSourceView_::get_right_margin_position>("get_right_margin_position");
            gtksourceview.method<&GtkSourceView_::set_highlight_current_line>("set_highlight_current_line");
            gtksourceview.method<&GtkSourceView_::get_highlight_current_line>("get_highlight_current_line");
            gtksourceview.method<&GtkSourceView_::set_auto_indent>("set_auto_indent");
            gtksourceview.method<&GtkSourceView_::get_auto_indent>("get_auto_indent");
            gtksourceview.method<&GtkSourceView_::set_indent_on_tab>("set_indent_on_tab");
            gtksourceview.method<&GtkSourceView_::get_indent_on_tab>("get_indent_on_tab");
            gtksourceview.method<&GtkSourceView_::set_tab_width>("set_tab_width");
            gtksourceview.method<&GtkSourceView_::get_tab_width>("get_tab_width");
            gtksourceview.method<&GtkSourceView_::set_indent_width>("set_indent_width");
            gtksourceview.method<&GtkSourceView_::get_indent_width>("get_indent_width");
            gtksourceview.method<&GtkSourceView_::set_insert_spaces_instead_of_tabs>("set_insert_spaces_instead_of_tabs");
            gtksourceview.method<&GtkSourceView_::get_insert_spaces_instead_of_tabs>("get_insert_spaces_instead_of_tabs");
            gtksourceview.method<&GtkSourceView_::indent_lines>("indent_lines");
            gtksourceview.method<&GtkSourceView_::unindent_lines>("unindent_lines");
            gtksourceview.method<&GtkSourceView_::get_visual_column>("get_visual_column");
            gtksourceview.method<&GtkSourceView_::set_smart_backspace>("set_smart_backspace");
            gtksourceview.method<&GtkSourceView_::get_smart_backspace>("get_smart_backspace");
            gtksourceview.method<&GtkSourceView_::set_smart_home_end>("set_smart_home_end");
            gtksourceview.method<&GtkSourceView_::get_smart_home_end>("get_smart_home_end");
            gtksourceview.method<&GtkSourceView_::set_mark_attributes>("set_mark_attributes");
            gtksourceview.method<&GtkSourceView_::get_mark_attributes>("get_mark_attributes");
            gtksourceview.method<&GtkSourceView_::set_show_line_marks>("set_show_line_marks");
            gtksourceview.method<&GtkSourceView_::get_show_line_marks>("get_show_line_marks");
            gtksourceview.method<&GtkSourceView_::set_draw_spaces>("set_draw_spaces");
            gtksourceview.method<&GtkSourceView_::get_draw_spaces>("get_draw_spaces");
            gtksourceview.method<&GtkSourceView_::get_completion>("get_completion");
            gtksourceview.method<&GtkSourceView_::get_gutter>("get_gutter");
            gtksourceview.method<&GtkSourceView_::set_background_pattern>("set_background_pattern");
            gtksourceview.method<&GtkSourceView_::get_background_pattern>("get_background_pattern");

        extension.add(std::move(gtksourcesmarthomeendtype));
        extension.add(std::move(gtksourcedrawspacesflags));
        extension.add(std::move(gtksourcebackgroundpatterntype));
        extension.add(std::move(gtksourceview));
        
        // return the extension
        return extension;
    }
}

Php::Value phpgtk_get_phpvalue(GValue *gvalue) 
{
    switch(g_value_get_gtype(gvalue)) {
        case G_TYPE_STRING:
            return g_value_get_string(gvalue);
            break;
    }

    return -1;
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



void phpgtk_throw_wrong_type(int param, Php::Type type)
{
    char *buffer;
    int len;
    std::string str_type;

    switch(type) {
        case Php::Type::Undefined: str_type.assign("undefined"); break;
        case Php::Type::Null: str_type.assign("Null"); break;
        case Php::Type::False: str_type.assign("False"); break;
        case Php::Type::True: str_type.assign("True"); break;
        case Php::Type::Numeric: str_type.assign("Numeric"); break;
        case Php::Type::Float: str_type.assign("Float"); break;
        case Php::Type::String: str_type.assign("String"); break;
        case Php::Type::Array: str_type.assign("Array"); break;
        case Php::Type::Object: str_type.assign("Object"); break;
        case Php::Type::Resource: str_type.assign("Resource"); break;
        case Php::Type::Reference: str_type.assign("Reference"); break;
        case Php::Type::Constant: str_type.assign("Constant"); break;
        case Php::Type::ConstantAST: str_type.assign("ConstantAST"); break;
        case Php::Type::Bool: str_type.assign("Bool"); break;
        case Php::Type::Callable: str_type.assign("Callable"); break;
    }
    
    // Get len of string
    len = snprintf(NULL, 0, "expects at least %d parameters, %s given", param, str_type.c_str());
    buffer = (char *)malloc((len + 1) * sizeof(char));
    
    // Save into buffer
    snprintf(buffer, len+1, "expects at least %d parameters, %s given", param, str_type.c_str());

    // throw
    throw Php::Exception(buffer);
}