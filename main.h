#ifndef _PHPGTK_H_
#define _PHPGTK_H_

    #include <phpcpp.h>
    #include <iostream>
    #include <gtk/gtk.h>

    #include "src/GObject.h"

    #include "src/Gdk.h"
    #include "src/GdkEvent.h"
    #include "src/GdkEventButton.h"
    #include "src/GdkPixbuf.h"

    #include "src/GdkPixbufFormat.h"
    #include "src/GdkPixbufAlphaMode.h"
    #include "src/GdkColorspace.h"

    #include "src/Gtk.h"
    #include "src/GtkWidget.h"
    #include "src/GtkEntry.h"
    #include "src/GtkContainer.h"
    
    #include "src/GtkBox.h"
    #include "src/GtkGrid.h"
    #include "src/GtkHBox.h"
    #include "src/GtkVBox.h"
    #include "src/GtkBin.h"
    
    #include "src/GtkWindow.h"
    #include "src/GtkButton.h"
    #include "src/GtkToggleButton.h"
    #include "src/GtkCheckButton.h"

    #include "src/GtkAdjustment.h"
    #include "src/GtkScrolledWindow.h"
    #include "src/GtkPolicyType.h"

    #include "src/GtkOrientation.h"
    #include "src/GtkPaned.h"

    #include "src/GtkTreeView.h"
    #include "src/GtkTreeViewColumn.h"

    #include "src/GtkNotebook.h"
    
    #include "src/GtkCellRenderer.h"
    #include "src/GtkCellRendererText.h"
    #include "src/GtkCellRendererToggle.h"
    #include "src/GtkCellRendererPixbuf.h"

    #include "src/GtkSortType.h"
    #include "src/GtkTreeModel.h"
    #include "src/GtkListStore.h"
    #include "src/GtkTreeModelFlags.h"
    #include "src/GtkTreeIter.h"

    #include "src/GtkEntryBuffer.h"
    
    #include "src/GtkPositionType.h"
    #include "src/GtkPackType.h"
    #include "src/GtkJustification.h"

    #include "src/GtkLabel.h"

    #include "src/GtkTextIter.h"
    #include "src/GtkTextBuffer.h"

    #include "src/GtkTextView.h"

    #include "src/GtkTextTag.h"
    #include "src/GtkTextWindowType.h"
    #include "src/GtkInputHints.h"
    #include "src/GtkWrapMode.h"
    #include "src/GtkInputPurpose.h"
    #include "src/GtkTextMark.h"

    #include "src/GtkDialogFlags.h"

    #include "src/GtkResponseType.h"
    #include "src/GtkDialog.h"

    #include "src/GtkFileChooser.h"
    #include "src/GtkFileChooserDialog.h"
    #include "src/GtkFileChooserAction.h"
    #include "src/GtkFileFilterFlags.h"
    #include "src/GtkFileFilter.h"
    #include "src/GtkFileFilterInfo.h"

    #include "src/GtkMessageType.h"
    #include "src/GtkButtonsType.h"

    #include "src/GtkMessageDialog.h"

    #include "src/GtkIconSize.h"

    #include "src/GtkSizeGroupMode.h"
    #include "src/GtkToolbarStyle.h"
    #include "src/GtkReliefStyle.h"

    #include "src/GtkSizeGroup.h"

    #include "src/GtkToolbar.h"

    #include "src/GtkToolItem.h"
    #include "src/GtkToolButton.h"
    #include "src/GtkSeparatorToolItem.h"

    #include "src/GtkTextTagTable.h"

    #include "src/GdkSelection.h"

    #include "src/GtkClipboard.h"

    #include "src/GtkTreeStore.h"
    #include "src/GtkSelectionMode.h"
    #include "src/GtkTreeSelection.h"
    
    #include "src/GtkMenuShell.h"
    #include "src/GtkPackDirection.h"
    #include "src/GtkMenuBar.h"
    #include "src/GtkMenu.h"
    #include "src/GtkMenuItem.h"
    #include "src/GtkSeparatorMenuItem.h"
    #include "src/GtkCheckMenuItem.h"

    #include "src/GtkStatusbar.h"

    #include "src/GtkListBoxRow.h"
    #include "src/GtkListBox.h"
    
    #include "src/GtkSensitivityType.h"
    #include "src/GtkComboBox.h"

    #include "src/GtkBuilder.h"

    #include "src/GtkBaselinePosition.h"
    #include "src/GtkDeleteType.h"
    #include "src/GtkDirectionType.h"
    #include "src/GtkMovementStep.h"
    #include "src/GtkScrollStep.h"
    #include "src/GtkScrollType.h"
    #include "src/GtkShadowType.h"
    #include "src/GtkStateFlags.h"

    #include "src/GtkRevealerTransitionType.h"
    #include "src/GtkRevealer.h"


    #include "src/GladeProject.h"
    #include "src/GladeDesignView.h"
    #include "src/GladeEditor.h"
    #include "src/GladePalette.h"


    

    GValue phpgtk_get_gvalue(Php::Value phpgtk_value, GType type_column);

#endif