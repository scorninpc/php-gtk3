#ifndef _PHPGTK_MAIN_H_
#define _PHPGTK_MAIN_H_

    #include <phpcpp.h>
    #include <iostream>
    #include <gtk/gtk.h>
    #include <gtksourceview/gtksource.h>

    #include "php-gtk.h"

    #include "src/GObject.h"

// ENUMS
    #include "src/GdkByteOrder.h"
    #include "src/GdkVisualType.h"

    #include "src/GtkWidgetHelpType.h"
    #include "src/GtkTextDirection.h"
    #include "src/GtkSizeRequestMode.h"
    #include "src/GtkAlign.h"
    #include "src/GtkBorderStyle.h"
    #include "src/GtkJunctionSides.h"
    #include "src/GtkRegionFlags.h"
    #include "src/GtkStyleContextPrintFlags.h"

    #include "src/GdkWindowType.h"
    #include "src/GdkWindowWindowClass.h"
    #include "src/GdkWindowHints.h"
    #include "src/GdkGravity.h"
    #include "src/GdkAnchorHints.h"
    #include "src/GdkWindowEdge.h"
    #include "src/GdkModifierIntent.h"
    #include "src/GdkWindowAttributesType.h"
    #include "src/GdkFullscreenMode.h"
    #include "src/GdkFilterReturn.h"
    #include "src/GdkWMDecoration.h"
    #include "src/GdkWMFunction.h"

    
    // GDK
    #include "src/GtkCssProviderError.h"
    #include "src/GtkCssSectionType.h"
    #include "src/GtkCssProvider.h"
    #include "src/GtkStyleContext.h"


    #include "src/Gdk.h"
    #include "src/GdkEvent.h"
    #include "src/GdkEventButton.h"
    #include "src/GdkPixbuf.h"

    #include "src/GdkWindow.h"

    #include "src/GdkVisual.h"
    
    #include "src/GdkRGBA.h"

    #include "src/GdkPixbufFormat.h"
    #include "src/GdkPixbufAlphaMode.h"
    #include "src/GdkColorspace.h"

    // GTK
    #include "src/Gtk.h"
    #include "src/GtkWidget.h"
    #include "src/GtkEntry.h"
    #include "src/GtkContainer.h"
    
    #include "src/GtkBox.h"
    #include "src/GtkGrid.h"
    #include "src/GtkHBox.h"
    #include "src/GtkVBox.h"
    #include "src/GtkBin.h"

    #include "src/GtkMisc.h"
    
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
    #include "src/GtkLicense.h"

    #include "src/GtkResponseType.h"
    #include "src/GtkDialog.h"
    #include "src/GtkAboutDialog.h"
    #include "src/GtkAppChooserDialog.h"
    #include "src/GtkColorChooserDialog.h"
    #include "src/GtkFontChooserDialog.h"

    // #include "src/GtkPageSetupUnixDialog.h"
    #include "src/GtkPrintSettings.h"

    #include "src/GtkPageOrientation.h"
    #include "src/GtkPrintDuplex.h"
    #include "src/GtkPrintQuality.h"
    #include "src/GtkNumberUpLayout.h"
    #include "src/GtkPrintPages.h"
    #include "src/GtkPageSet.h"
    #include "src/GtkUnit.h"
    
    #include "src/GtkPaperSize.h"
    #include "src/GtkPageSetup.h"

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
    #include "src/GtkComboBoxText.h"
    #include "src/GtkAppChooserButton.h"

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

    #include "src/GtkFlowBoxChild.h"
    #include "src/GtkFlowBox.h"
    
    #include "src/GtkStackTransitionType.h"
    #include "src/GtkStack.h"
    #include "src/GtkStackSwitcher.h"
    #include "src/GtkStackSidebar.h"

    #include "src/GtkActionBar.h"
    #include "src/GtkHeaderBar.h"
    #include "src/GtkOverlay.h"

    #include "src/GtkButtonBoxStyle.h"
    #include "src/GtkButtonBox.h"
    
    #include "src/GtkLayout.h"
    #include "src/GtkExpander.h"

    #include "src/GtkFrame.h"
    #include "src/GtkAspectFrame.h"
    
    #include "src/GtkResizeMode.h"
    #include "src/GtkWidgetPath.h"

    #include "src/GtkImageType.h"
    #include "src/GtkImage.h"

    #include "src/GtkCalendarDisplayOptions.h"
    #include "src/GtkCalendar.h"

    #include "src/GtkSpinner.h"

    #include "src/GtkInfoBar.h"

    #include "src/GtkProgressBar.h"

    #include "src/GtkRecentSortType.h"
    #include "src/GtkRecentChooserError.h"
    #include "src/GtkRecentChooserDialog.h"

    #include "src/GtkArrowType.h"
    // #include "src/GtkMenuButton.h"

    
    #include "src/GtkSourceSmartHomeEndType.h"
    #include "src/GtkSourceDrawSpacesFlags.h"
    #include "src/GtkSourceBackgroundPatternType.h"
    #include "src/GtkSourceView.h"
    
    

    GValue phpgtk_get_gvalue(Php::Value phpgtk_value, GType type_column);
    void phpgtk_throw_wrong_type(int param, Php::Type type);

#endif