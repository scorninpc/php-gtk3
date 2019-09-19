#ifndef _PHPGTK_MAIN_H_
#define _PHPGTK_MAIN_H_

    #include <phpcpp.h>
    #include <iostream>
    #include <gtk/gtk.h>
    #include <gtksourceview/gtksource.h>

    #include "php-gtk.h"

    #include "src/GObject.h"

// ENUMS


    
    // GDK
    #include "src/GtkCssProvider.h"
    #include "src/GtkStyleContext.h"


    #include "src/Gdk.h"
    #include "src/GdkEvent.h"
    #include "src/GdkEventButton.h"
    #include "src/GdkEventKey.h"
    #include "src/GdkPixbuf.h"

    #include "src/GdkWindow.h"

    #include "src/GdkVisual.h"
    
    #include "src/GdkRGBA.h"

    #include "src/GdkPixbufFormat.h"

    // GTK
    #include "src/Gtk.h"
    #include "src/GtkWidget.h"
    #include "src/GtkEntry.h"
    #include "src/GtkEntryCompletion.h"
    #include "src/GtkContainer.h"
    
    #include "src/GtkBox.h"
    #include "src/GtkGrid.h"
    #include "src/GtkFixed.h"
    #include "src/GtkHBox.h"
    #include "src/GtkVBox.h"
    #include "src/GtkBin.h"

    #include "src/GtkWindow.h"
    #include "src/GtkButton.h"
    #include "src/GtkColorButton.h"
    #include "src/GtkFontButton.h"
    #include "src/GtkToggleButton.h"
    #include "src/GtkCheckButton.h"

    #include "src/GtkAdjustment.h"
    #include "src/GtkScrolledWindow.h"

    #include "src/GtkPaned.h"

    #include "src/GtkTreeView.h"
    #include "src/GtkTreeViewColumn.h"

    #include "src/GtkNotebook.h"
    
    #include "src/GtkCellRenderer.h"
    #include "src/GtkCellRendererText.h"
    #include "src/GtkCellRendererToggle.h"
    #include "src/GtkCellRendererPixbuf.h"

    #include "src/GtkTreeModel.h"
    #include "src/GtkListStore.h"
    #include "src/GtkTreeIter.h"

    #include "src/GtkEntryBuffer.h"
    

    #include "src/GtkLabel.h"

    #include "src/GtkTextIter.h"
    #include "src/GtkTextBuffer.h"

    #include "src/GtkTextView.h"

    #include "src/GtkTextTag.h"
    #include "src/GtkTextMark.h"

    #include "src/GtkDialog.h"
    #include "src/GtkAboutDialog.h"
    #include "src/GtkAppChooserDialog.h"
    #include "src/GtkColorChooserDialog.h"
    #include "src/GtkFontChooserDialog.h"

    // #include "src/GtkPageSetupUnixDialog.h"
    #include "src/GtkPrintSettings.h"

    
    #include "src/GtkPaperSize.h"
    #include "src/GtkPageSetup.h"

    #include "src/GtkFileChooser.h"
    #include "src/GtkFileChooserDialog.h"
    #include "src/GtkFileFilter.h"


    #include "src/GtkMessageDialog.h"



    #include "src/GtkSizeGroup.h"

    #include "src/GtkToolbar.h"

    #include "src/GtkToolItem.h"
    #include "src/GtkMisc.h"
    #include "src/GtkToolButton.h"
    #include "src/GtkSeparatorToolItem.h"

    #include "src/GtkTextTagTable.h"

    #include "src/GtkClipboard.h"

    #include "src/GtkTreeStore.h"
    #include "src/GtkTreeSelection.h"
    
    #include "src/GtkListStore.h"

    #include "src/GtkMenuShell.h"
    #include "src/GtkMenuBar.h"
    #include "src/GtkMenu.h"
    #include "src/GtkMenuItem.h"
    #include "src/GtkSeparatorMenuItem.h"
    #include "src/GtkCheckMenuItem.h"

    #include "src/GtkStatusbar.h"

    #include "src/GtkListBoxRow.h"
    #include "src/GtkListBox.h"
    
    #include "src/GtkComboBox.h"
    #include "src/GtkComboBoxText.h"
    #include "src/GtkAppChooserButton.h"

    #include "src/GtkBuilder.h"

    #include "src/GtkRevealer.h"


    #include "src/GladeProject.h"
    #include "src/GladeApp.h"
    #include "src/GladeDesignView.h"
    #include "src/GladeEditor.h"
    #include "src/GladePalette.h"
    #include "src/GladeWidget.h"

    #include "src/GtkFlowBoxChild.h"
    #include "src/GtkFlowBox.h"
    
    #include "src/GtkStack.h"
    #include "src/GtkStackSwitcher.h"
    #include "src/GtkStackSidebar.h"

    #include "src/GtkActionBar.h"
    #include "src/GtkHeaderBar.h"
    #include "src/GtkOverlay.h"

    #include "src/GtkButtonBox.h"
    
    #include "src/GtkLayout.h"
    #include "src/GtkExpander.h"

    #include "src/GtkFrame.h"
    #include "src/GtkAspectFrame.h"
    
    #include "src/GtkWidgetPath.h"

    #include "src/GtkImage.h"

    #include "src/GtkCalendar.h"

    #include "src/GtkSpinner.h"

    #include "src/GtkInfoBar.h"

    #include "src/GtkProgressBar.h"

    #include "src/GtkRecentChooserDialog.h"


#ifdef WITH_GTKSOURCEVIEW
    #include "src/GtkSourceView.h"
#endif
    

    GValue phpgtk_get_gvalue(Php::Value phpgtk_value, GType type_column);
    void phpgtk_throw_wrong_type(int param, Php::Type type);

#endif