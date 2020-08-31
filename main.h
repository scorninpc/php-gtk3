#ifndef _PHPGTK_MAIN_H_
#define _PHPGTK_MAIN_H_

	#include <phpcpp.h>
	#include <iostream>
	#include <gtk/gtk.h>
	#include <gtksourceview/gtksource.h>

	// PHP-GTK
	#include "php-gtk.h"

	// G
	#include "src/G/GApplication.h"
	#include "src/G/GObject.h"

	// GDK
	#include "src/Gdk/Gdk.h"
	#include "src/Gdk/GdkEvent.h"
	#include "src/Gdk/GdkEventButton.h"
	#include "src/Gdk/GdkEventKey.h"
	#include "src/Gdk/GdkPixbuf.h"
	#include "src/Gdk/GdkDrawable.h"
	#include "src/Gdk/GdkWindow.h"
	#include "src/Gdk/GdkVisual.h"
	#include "src/Gdk/GdkRGBA.h"
	#include "src/Gdk/GdkPixbufFormat.h"
	#include "src/Gdk/GdkScreen.h"

	// GTK
	#include "src/Gtk/Gtk.h"
	#include "src/Gtk/GtkApplication.h"
	#include "src/Gtk/GtkWidget.h"
	#include "src/Gtk/GtkEntry.h"
	#include "src/Gtk/GtkEntryCompletion.h"
	#include "src/Gtk/GtkContainer.h"
	#include "src/Gtk/GtkCssProvider.h"
	#include "src/Gtk/GtkStyleContext.h"
	#include "src/Gtk/GtkBox.h"
	#include "src/Gtk/GtkGrid.h"
	#include "src/Gtk/GtkFixed.h"
	#include "src/Gtk/GtkHBox.h"
	#include "src/Gtk/GtkVBox.h"
	#include "src/Gtk/GtkBin.h"
	#include "src/Gtk/GtkWindow.h"
	#include "src/Gtk/GtkButton.h"
	#include "src/Gtk/GtkColorButton.h"
	#include "src/Gtk/GtkFontButton.h"
	#include "src/Gtk/GtkToggleButton.h"
	#include "src/Gtk/GtkCheckButton.h"
	#include "src/Gtk/GtkRadioButton.h"
	#include "src/Gtk/GtkAdjustment.h"
	#include "src/Gtk/GtkScrolledWindow.h"
	#include "src/Gtk/GtkPaned.h"
	#include "src/Gtk/GtkTreeView.h"
	#include "src/Gtk/GtkTreeViewColumn.h"
	#include "src/Gtk/GtkNotebook.h"
	#include "src/Gtk/GtkCellRenderer.h"
	#include "src/Gtk/GtkCellRendererText.h"
	#include "src/Gtk/GtkCellRendererToggle.h"
	#include "src/Gtk/GtkCellRendererPixbuf.h"
	#include "src/Gtk/GtkTreeModel.h"
	#include "src/Gtk/GtkListStore.h"
	#include "src/Gtk/GtkTreeIter.h"
	#include "src/Gtk/GtkEntryBuffer.h"
	#include "src/Gtk/GtkLabel.h"
	#include "src/Gtk/GtkTextIter.h"
	#include "src/Gtk/GtkTextBuffer.h"
	#include "src/Gtk/GtkTextView.h"
	#include "src/Gtk/GtkTextTag.h"
	#include "src/Gtk/GtkTextMark.h"
	#include "src/Gtk/GtkDialog.h"
	#include "src/Gtk/GtkAboutDialog.h"
	#include "src/Gtk/GtkAppChooserDialog.h"
	#include "src/Gtk/GtkColorChooserDialog.h"
	#include "src/Gtk/GtkFontChooserDialog.h"
//	#include "src/Gtk/GtkPageSetupUnixDialog.h"
	#include "src/Gtk/GtkPrintSettings.h"
	#include "src/Gtk/GtkPaperSize.h"
	#include "src/Gtk/GtkPageSetup.h"
	#include "src/Gtk/GtkFileChooser.h"
	#include "src/Gtk/GtkFileChooserDialog.h"
	#include "src/Gtk/GtkFileFilter.h"
	#include "src/Gtk/GtkMessageDialog.h"
	#include "src/Gtk/GtkSizeGroup.h"
	#include "src/Gtk/GtkToolbar.h"
	#include "src/Gtk/GtkToolItem.h"
	#include "src/Gtk/GtkMisc.h"
	#include "src/Gtk/GtkToolButton.h"
	#include "src/Gtk/GtkSeparatorToolItem.h"
	#include "src/Gtk/GtkTextTagTable.h"
	#include "src/Gtk/GtkClipboard.h"
	#include "src/Gtk/GtkTreeStore.h"
	#include "src/Gtk/GtkTreeSelection.h"
	#include "src/Gtk/GtkListStore.h"
	#include "src/Gtk/GtkMenuShell.h"
	#include "src/Gtk/GtkMenuBar.h"
	#include "src/Gtk/GtkMenu.h"
	#include "src/Gtk/GtkMenuItem.h"
	#include "src/Gtk/GtkSeparatorMenuItem.h"
	#include "src/Gtk/GtkCheckMenuItem.h"
	#include "src/Gtk/GtkStatusbar.h"
	#include "src/Gtk/GtkListBoxRow.h"
	#include "src/Gtk/GtkListBox.h"
	#include "src/Gtk/GtkComboBox.h"
	#include "src/Gtk/GtkComboBoxText.h"
	#include "src/Gtk/GtkAppChooserButton.h"
	#include "src/Gtk/GtkBuilder.h"
	#include "src/Gtk/GtkRevealer.h"
	#include "src/Gtk/GtkFlowBoxChild.h"
	#include "src/Gtk/GtkFlowBox.h"
	#include "src/Gtk/GtkStack.h"
	#include "src/Gtk/GtkStackSwitcher.h"
	#include "src/Gtk/GtkStackSidebar.h"
	#include "src/Gtk/GtkActionBar.h"
	#include "src/Gtk/GtkHeaderBar.h"
	#include "src/Gtk/GtkOverlay.h"
	#include "src/Gtk/GtkButtonBox.h"
	#include "src/Gtk/GtkLayout.h"
	#include "src/Gtk/GtkExpander.h"
	#include "src/Gtk/GtkFrame.h"
	#include "src/Gtk/GtkAspectFrame.h"
	#include "src/Gtk/GtkWidgetPath.h"
	#include "src/Gtk/GtkImage.h"
	#include "src/Gtk/GtkCalendar.h"
	#include "src/Gtk/GtkSpinner.h"
	#include "src/Gtk/GtkInfoBar.h"
	#include "src/Gtk/GtkProgressBar.h"
	#include "src/Gtk/GtkRecentChooserDialog.h"

	// GtkSourceView
	#include "src/GtkSourceView/GtkSourceView.h"

	// Glade
	#include "src/Glade/GladeProject.h"
	#include "src/Glade/GladeApp.h"
	#include "src/Glade/GladeDesignView.h"
	#include "src/Glade/GladeEditor.h"
	#include "src/Glade/GladePalette.h"
	#include "src/Glade/GladeWidget.h"

#ifdef WITH_MAC_INTEGRATION
	// GtkosxApplication
	#include "src/Gtk/GtkosxApplication.h"
#endif

	// Self methods
	GValue phpgtk_get_gvalue(Php::Value phpgtk_value, GType type_column);
	Php::Value phpgtk_get_phpvalue(GValue *gvalue);
	void phpgtk_throw_wrong_type(int param, Php::Type type);

#endif