```
* - Complete
# - Partial
_ - With issue
% - Deprecated
$ - Untested all

_GObject
    ├── GInitiallyUnowned
    │   ├── *GtkWidget
    │   │   ├── *GtkContainer
    │   │   │   ├── *GtkBin
    │   │   │   │   ├── *GtkWindow
    │   │   │   │   │   ├── *GtkDialog
    │   │   │   │   │   │   ├── GtkAboutDialog
    │   │   │   │   │   │   ├── GtkAppChooserDialog
    │   │   │   │   │   │   ├── GtkColorChooserDialog
    │   │   │   │   │   │   ├── GtkColorSelectionDialog
    │   │   │   │   │   │   ├── *GtkFileChooserDialog
    │   │   │   │   │   │   ├── GtkFontChooserDialog
    │   │   │   │   │   │   ├── GtkFontSelectionDialog
    │   │   │   │   │   │   ├── *GtkMessageDialog
    │   │   │   │   │   │   ├── GtkPageSetupUnixDialog
    │   │   │   │   │   │   ├── GtkPrintUnixDialog
    │   │   │   │   │   │   ╰── GtkRecentChooserDialog
    │   │   │   │   │   ├── GtkApplicationWindow
    │   │   │   │   │   ├── GtkAssistant
    │   │   │   │   │   ├── GtkOffscreenWindow
    │   │   │   │   │   ├── GtkPlug
    │   │   │   │   │   ╰── GtkShortcutsWindow
    │   │   │   │   ├── GtkActionBar
    │   │   │   │   ├── GtkAlignment
    │   │   │   │   ├── GtkComboBox
    │   │   │   │   │   ├── GtkAppChooserButton
    │   │   │   │   │   ╰── GtkComboBoxText
    │   │   │   │   ├── GtkFrame
    │   │   │   │   │   ╰── GtkAspectFrame
    │   │   │   │   ├── #GtkButton
    │   │   │   │   │   ├── *GtkToggleButton
    │   │   │   │   │   │   ├── *GtkCheckButton
    │   │   │   │   │   │   │   ╰── *GtkRadioButton
    │   │   │   │   │   │   ╰── GtkMenuButton
    │   │   │   │   │   ├── GtkColorButton
    │   │   │   │   │   ├── GtkFontButton
    │   │   │   │   │   ├── GtkLinkButton
    │   │   │   │   │   ├── GtkLockButton
    │   │   │   │   │   ├── GtkModelButton
    │   │   │   │   │   ╰── GtkScaleButton
    │   │   │   │   │       ╰── GtkVolumeButton
    │   │   │   │   ├── #GtkMenuItem
    │   │   │   │   │   ├── *GtkCheckMenuItem
    │   │   │   │   │   │   ╰── GtkRadioMenuItem
    │   │   │   │   │   ├── %GtkImageMenuItem
    │   │   │   │   │   ├── *GtkSeparatorMenuItem
    │   │   │   │   │   ╰── %GtkTearoffMenuItem
    │   │   │   │   ├── GtkEventBox
    │   │   │   │   ├── GtkExpander
    │   │   │   │   ├── GtkFlowBoxChild
    │   │   │   │   ├── GtkHandleBox
    │   │   │   │   ├── #GtkListBoxRow
    │   │   │   │   ├── *GtkToolItem
    │   │   │   │   │   ├── *GtkToolButton
    │   │   │   │   │   │   ├── GtkMenuToolButton
    │   │   │   │   │   │   ╰── GtkToggleToolButton
    │   │   │   │   │   │       ╰── GtkRadioToolButton
    │   │   │   │   │   ╰── *GtkSeparatorToolItem
    │   │   │   │   ├── GtkOverlay
    │   │   │   │   ├── #GtkScrolledWindow
    │   │   │   │   │   ╰── GtkPlacesSidebar
    │   │   │   │   ├── GtkPopover
    │   │   │   │   │   ╰── GtkPopoverMenu
    │   │   │   │   ├── GtkRevealer
    │   │   │   │   ├── GtkSearchBar
    │   │   │   │   ├── GtkStackSidebar
    │   │   │   │   ╰── GtkViewport
    │   │   │   ├── #GtkBox
    │   │   │   │   ├── GtkAppChooserWidget
    │   │   │   │   ├── GtkButtonBox
    │   │   │   │   │   ├── GtkHButtonBox
    │   │   │   │   │   ╰── GtkVButtonBox
    │   │   │   │   ├── GtkColorChooserWidget
    │   │   │   │   ├── GtkColorSelection
    │   │   │   │   ├── GtkFileChooserButton
    │   │   │   │   ├── GtkFileChooserWidget
    │   │   │   │   ├── GtkFontChooserWidget
    │   │   │   │   ├── GtkFontSelection
    │   │   │   │   ├── *GtkHBox
    │   │   │   │   ├── GtkInfoBar
    │   │   │   │   ├── GtkRecentChooserWidget
    │   │   │   │   ├── GtkShortcutsSection
    │   │   │   │   ├── GtkShortcutsGroup
    │   │   │   │   ├── GtkShortcutsShortcut
    │   │   │   │   ├── GtkStackSwitcher
    │   │   │   │   ├── *GtkStatusbar
    │   │   │   │   ╰── *GtkVBox
    │   │   │   ├── GtkFixed
    │   │   │   ├── GtkFlowBox
    │   │   │   ├── GtkGrid
    │   │   │   ├── GtkHeaderBar
    │   │   │   ├── #GtkPaned
    │   │   │   │   ├── %GtkHPaned
    │   │   │   │   ╰── %GtkVPaned
    │   │   │   ├── GtkIconView
    │   │   │   ├── GtkLayout
    │   │   │   ├── #GtkListBox
    │   │   │   ├── #GtkMenuShell
    │   │   │   │   ├── #GtkMenuBar
    │   │   │   │   ╰── #GtkMenu
    │   │   │   │       ╰── GtkRecentChooserMenu
    │   │   │   ├── #GtkNotebook
    │   │   │   ├── GtkSocket
    │   │   │   ├── GtkStack
    │   │   │   ├── GtkTable
    │   │   │   ├── #GtkTextView (implement GdkWindow)
    │   │   │   ├── *GtkToolbar
    │   │   │   ├── GtkToolItemGroup
    │   │   │   ├── GtkToolPalette
    │   │   │   ╰── #GtkTreeView
    │   │   ├── %GtkMisc
    │   │   │   ├── *GtkLabel
    │   │   │   │   ╰── GtkAccelLabel
    │   │   │   ├── GtkArrow
    │   │   │   ╰── GtkImage
    │   │   ├── GtkCalendar
    │   │   ├── GtkCellView
    │   │   ├── GtkDrawingArea
    │   │   ├── #GtkEntry
    │   │   │   ├── GtkSearchEntry
    │   │   │   ╰── GtkSpinButton
    │   │   ├── GtkGLArea
    │   │   ├── GtkRange
    │   │   │   ├── GtkScale
    │   │   │   │   ├── GtkHScale
    │   │   │   │   ╰── GtkVScale
    │   │   │   ╰── GtkScrollbar
    │   │   │       ├── GtkHScrollbar
    │   │   │       ╰── GtkVScrollbar
    │   │   ├── GtkSeparator
    │   │   │   ├── GtkHSeparator
    │   │   │   ╰── GtkVSeparator
    │   │   ├── GtkHSV
    │   │   ├── GtkInvisible
    │   │   ├── GtkProgressBar
    │   │   ├── GtkSpinner
    │   │   ├── GtkSwitch
    │   │   ╰── GtkLevelBar
    │   ├── #GtkAdjustment
    │   ├── GtkCellArea
    │   │   ╰── GtkCellAreaBox
    │   ├── #GtkCellRenderer
    │   │   ├── #GtkCellRendererText
    │   │   │   ├── GtkCellRendererAccel
    │   │   │   ├── *GtkCellRendererCombo
    │   │   │   ╰── GtkCellRendererSpin
    │   │   ├── *GtkCellRendererPixbuf
    │   │   ├── GtkCellRendererProgress
    │   │   ├── GtkCellRendererSpinner
    │   │   ╰── *GtkCellRendererToggle
    │   ├── *GtkFileFilter
    │   ├── #GtkTreeViewColumn
    │   ╰── GtkRecentFilter
    ├── GtkAccelGroup
    ├── GtkAccelMap
    ├── AtkObject
    │   ╰── GtkAccessible
    ├── GtkAction
    │   ├── GtkToggleAction
    │   │   ╰── GtkRadioAction
    │   ╰── GtkRecentAction
    ├── GtkActionGroup
    ├── GApplication
    │   ╰── GtkApplication
    ├── GtkBuilder
    ├── GtkCellAreaContext
    ├── #GtkClipboard (implement GdkDisplay, GdkAtom)
    ├── GtkCssProvider
    ├── #GtkEntryBuffer
    ├── GtkEntryCompletion
    ├── GtkEventController
    │   ├── GtkEventControllerKey
    │   ├── GtkEventControllerMotion
    │   ├── GtkEventControllerScroll
    │   ├── GtkGesture
    │   │   ├── GtkGestureSingle
    │   │   │   ├── GtkGestureDrag
    │   │   │   │   ╰── GtkGesturePan
    │   │   │   ├── GtkGestureLongPress
    │   │   │   ├── GtkGestureMultiPress
    │   │   │   ├── GtkGestureStylus
    │   │   │   ╰── GtkGestureSwipe
    │   │   ├── GtkGestureRotate
    │   │   ╰── GtkGestureZoom
    │   ╰── GtkPadController
    ├── GtkIconFactory
    ├── GtkIconTheme
    ├── GtkIMContext
    │   ├── GtkIMContextSimple
    │   ╰── GtkIMMulticontext
    ├── #GtkListStore
    ├── GMountOperation
    │   ╰── GtkMountOperation
    ├── GEmblemedIcon
    │   ╰── GtkNumerableIcon
    ├── GtkPageSetup
    ├── GtkPrinter
    ├── GtkPrintContext
    ├── GtkPrintJob
    ├── GtkPrintOperation
    ├── GtkPrintSettings
    ├── GtkRcStyle
    ├── GtkRecentManager
    ├── GtkSettings
    ├── *GtkSizeGroup
    ├── GtkStatusIcon
    ├── GtkStyle
    ├── GtkStyleContext
    ├── #GtkTextBuffer (implement Clipboards, GdkAtom, GdkPixbuf)
    ├── GtkTextChildAnchor
    ├── *GtkTextMark
    ├── _GtkTextTag (Convert GdkEvent)
    ├── GtkTextTagTable
    ├── GtkThemingEngine
    ├── GtkTreeModelFilter
    ├── GtkTreeModelSort
    ├── GtkTreeSelection
    ├── $GtkTreeStore
    ├── GtkUIManager
    ├── GtkWindowGroup
    ├── GtkTooltip
    ╰── GtkPrintBackend
    GInterface
    ├── GtkBuildable
    ├── GtkActionable
    ├── GtkActivatable
    ├── GtkAppChooser
    ├── GtkCellLayout
    ├── GtkCellEditable
    ├── GtkOrientable
    ├── GtkColorChooser
    ├── GtkStyleProvider
    ├── GtkEditable
    ├── #GtkFileChooser
    ├── GtkFontChooser
    ├── GtkScrollable
    ├── #GtkTreeModel
    ├── GtkTreeDragSource
    ├── GtkTreeDragDest
    ├── GtkTreeSortable
    ├── GtkPrintOperationPreview
    ├── GtkRecentChooser
    ╰── GtkToolShell
    GBoxed
    ├── GtkPaperSize
    ├── *GtkTextIter
    ├── GtkSelectionData
    ├── #GtkRequisition
    ├── GtkBorder
    ├── #GtkTreeIter
    ├── GtkCssSection
    ├── GtkTreePath
    ├── GtkIconSet
    ╰── GtkTargetList
   ```
