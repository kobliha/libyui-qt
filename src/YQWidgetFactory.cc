/*---------------------------------------------------------------------\
|                                                                      |
|                      __   __    ____ _____ ____                      |
|                      \ \ / /_ _/ ___|_   _|___ \                     |
|                       \ V / _` \___ \ | |   __) |                    |
|                        | | (_| |___) || |  / __/                     |
|                        |_|\__,_|____/ |_| |_____|                    |
|                                                                      |
|                               core system                            |
|                                                        (C) SuSE GmbH |
\----------------------------------------------------------------------/

  File:         YQWidgetFactory.cc

  Author:       Stefan Hundhammer <sh@suse.de>

/-*/


#include "YQWidgetFactory.h"
#include "YQUI.h"
#include "YUIException.h"
#include "YQPackageSelectorPlugin.h"

#include <string>


using std::string;


YQWidgetFactory::YQWidgetFactory()
    : YWidgetFactory()
{
    // NOP
}

YQWidgetFactory::~YQWidgetFactory()
{
    // NOP
}




//
// Dialogs
//

YQDialog *
YQWidgetFactory::createMainDialog()
{
    return 0; // FIXME: TO DO
}



YQDialog *
YQWidgetFactory::createPopupDialog()
{
    return 0; // FIXME: TO DO
}




//
// Layout Boxes
//

YQLayoutBox *
YQWidgetFactory::createLayoutBox( YWidget * parent, YUIDimension dim )
{
    YQLayoutBox * layoutBox = new YQLayoutBox( parent, dim );
    YUI_CHECK_NEW( layoutBox );

    return layoutBox;
}



//
// Common Leaf Widgets
//

YQPushButton *
YQWidgetFactory::createPushButton( YWidget * parent, const string & label )
{
    YQPushButton * pushButton = new YQPushButton( parent, label );
    YUI_CHECK_NEW( pushButton );

    return pushButton;
}



YQLabel *
YQWidgetFactory::createLabel( YWidget *		parent,
			      const string &	text,
			      bool 		isHeading,
			      bool 		isOutputField )
{
    YQLabel * label = new YQLabel( parent, text, isHeading, isOutputField );
    YUI_CHECK_NEW( label );

    return label;
}



YQInputField *
YQWidgetFactory::createInputField( YWidget * parent, const string & label, bool passwordMode )
{
    YQInputField * inputField = new YQInputField( parent, label, passwordMode );
    YUI_CHECK_NEW( inputField );

    return inputField;
}



YQCheckBox *
YQWidgetFactory::createCheckBox( YWidget * parent, const string & label, bool isChecked )
{
    YQCheckBox * checkBox = new YQCheckBox( parent, label, isChecked );
    YUI_CHECK_NEW( checkBox );

    return checkBox;
}



YQRadioButton *
YQWidgetFactory::createRadioButton( YWidget * parent, const string & label, bool isChecked )
{
    YQRadioButton * radioButton = new YQRadioButton( parent, label, isChecked );
    YUI_CHECK_NEW( radioButton );

    // Register radio button with its button group.
    // This has to be done after all constructors are done so virtual functions
    // can be used.

    if ( radioButton->buttonGroup() )
	radioButton->buttonGroup()->addRadioButton( radioButton );

    return radioButton;
}



YQComboBox *
YQWidgetFactory::createComboBox( YWidget * parent, const string & label, bool editable  )
{
    YQComboBox * comboBox = new YQComboBox( parent, label, editable );
    YUI_CHECK_NEW( comboBox );

    return comboBox;
}



YQSelectionBox *
YQWidgetFactory::createSelectionBox( YWidget * parent, const string & label )
{
    YQSelectionBox * selectionBox = new YQSelectionBox( parent, label );
    YUI_CHECK_NEW( selectionBox );

    return selectionBox;
}



YQTree *
YQWidgetFactory::createTree( YWidget * parent, const string & label )
{
    YQTree * tree = new YQTree( parent, label );
    YUI_CHECK_NEW( tree );

    return tree;
}



YQTable *
YQWidgetFactory::createTable( YWidget * parent, YTableHeader * header )
{
    YQTable * table = new YQTable( parent, header );
    YUI_CHECK_NEW( table );

    return table;
}



YQProgressBar *
YQWidgetFactory::createProgressBar( YWidget * parent, const string & label, int maxValue )
{
    YQProgressBar * progressBar = new YQProgressBar( parent, label, maxValue );
    YUI_CHECK_NEW( progressBar );

    return progressBar;
}



YQRichText *
YQWidgetFactory::createRichText( YWidget * parent, const string & text, bool plainTextMode )
{
    YQRichText * richText = new YQRichText( parent, text, plainTextMode );
    YUI_CHECK_NEW( richText );

    return richText;
}




//
// Less Common Leaf Widgets
//

YQIntField *
YQWidgetFactory::createIntField( YWidget * parent, const string & label, int minVal, int maxVal, int initialVal )
{
    YQIntField * intField = new YQIntField( parent, label, minVal, maxVal, initialVal );
    YUI_CHECK_NEW( intField );
    
    return intField;
}



YQMenuButton *
YQWidgetFactory::createMenuButton( YWidget * parent, const string & label )
{
    YQMenuButton * menuButton = new YQMenuButton( parent, label );
    YUI_CHECK_NEW( menuButton );

    return menuButton;
}



YQMultiLineEdit *
YQWidgetFactory::createMultiLineEdit( YWidget * parent, const string & label )
{
    YQMultiLineEdit * multiLineEdit = new YQMultiLineEdit( parent, label );
    YUI_CHECK_NEW( multiLineEdit );

    return multiLineEdit;
}



YQImage *
YQWidgetFactory::createImage( YWidget * parent, const string & imageFileName, bool animated )
{
    YQImage * image = new YQImage( parent, imageFileName, animated );
    YUI_CHECK_NEW( image );

    return image;
}


YQLogView *
YQWidgetFactory::createLogView( YWidget * parent, const string & label, int visibleLines, int storedLines )
{
    YQLogView * logView = new YQLogView( parent, label, visibleLines, storedLines );
    YUI_CHECK_NEW( logView );

    return logView;
}



YQMultiSelectionBox *
YQWidgetFactory::createMultiSelectionBox( YWidget * parent, const string & label )
{
    YQMultiSelectionBox * multiSelectionBox = new YQMultiSelectionBox( parent, label );
    YUI_CHECK_NEW( multiSelectionBox );

    return multiSelectionBox;
}



YQPackageSelector *
YQWidgetFactory::createPackageSelector( YWidget * parent, long modeFlags )
{
    YQUI::ui()->setAutoActivateDialogs( false );

    YQPackageSelectorPlugin * plugin = YQUI::ui()->packageSelectorPlugin();

    if ( plugin )
	return plugin->createPackageSelector( parent, modeFlags );
    else
	return 0;
}


YWidget *
YQWidgetFactory::createPkgSpecial( YWidget * , const string & )
{
    YUI_THROW( YUIUnsupportedWidgetException( "YQPkgSpecial" ) ); // NCurses only
    return 0;
}


//
// Layout Helpers
//

YQSpacing *
YQWidgetFactory::createSpacing( YWidget * parent, YUIDimension dim, bool stretchable, YLayoutSize_t size )
{
    YQSpacing * spacing = new YQSpacing( parent, dim, stretchable, size );
    YUI_CHECK_NEW( spacing );

    return spacing;
}


YQEmpty *
YQWidgetFactory::createEmpty( YWidget * parent )
{
    YQEmpty * empty = new YQEmpty( parent );
    YUI_CHECK_NEW( empty );

    return empty;
}



YQAlignment *
YQWidgetFactory::createAlignment( YWidget *	 parent,
				  YAlignmentType horAlignment,
				  YAlignmentType vertAlignment )
{
    YQAlignment * alignment = new YQAlignment( parent, horAlignment, vertAlignment );
    YUI_CHECK_NEW( alignment );

    return alignment;
}


YQSquash *
YQWidgetFactory::createSquash( YWidget * parent, bool horSquash, bool vertSquash )
{
    YQSquash * squash = new YQSquash( parent, horSquash, vertSquash );
    YUI_CHECK_NEW( squash );

    return squash;
}



YQFrame *
YQWidgetFactory::createFrame( YWidget * parent, const string & label )
{
    YQFrame * frame = new YQFrame( parent, label );
    YUI_CHECK_NEW( frame );

    return frame;
}



YQCheckBoxFrame *
YQWidgetFactory::createCheckBoxFrame( YWidget *	parent, const string & label, bool checked )
{
    YQCheckBoxFrame * checkBoxFrame = new YQCheckBoxFrame( parent, label, checked );
    YUI_CHECK_NEW( checkBoxFrame );

    return checkBoxFrame;
}



YQRadioButtonGroup *
YQWidgetFactory::createRadioButtonGroup( YWidget * parent )
{
    YQRadioButtonGroup * radioButtonGroup = new YQRadioButtonGroup( parent );
    YUI_CHECK_NEW( radioButtonGroup );

    return radioButtonGroup;
}



YQReplacePoint *
YQWidgetFactory::createReplacePoint( YWidget * parent )
{
    YQReplacePoint * replacePoint = new YQReplacePoint( parent );
    YUI_CHECK_NEW( replacePoint );

    return replacePoint;
}


