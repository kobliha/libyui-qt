/*---------------------------------------------------------------------\
|								       |
|		       __   __	  ____ _____ ____		       |
|		       \ \ / /_ _/ ___|_   _|___ \		       |
|			\ V / _` \___ \ | |   __) |		       |
|			 | | (_| |___) || |  / __/		       |
|			 |_|\__,_|____/ |_| |_____|		       |
|								       |
|				core system			       |
|							 (C) SuSE GmbH |
\----------------------------------------------------------------------/

  File:	      YQRichText.h

  Author:     Stefan Hundhammer <sh@suse.de>

/-*/


#ifndef YQRichText_h
#define YQRichText_h

#include <qvbox.h>
#include <qtextbrowser.h>
#include "YRichText.h"

using std::string;


class YQTextBrowser;

class YQRichText : public QVBox, public YRichText
{
    Q_OBJECT

public:

    /**
     * Constructor.
     **/
    YQRichText( YWidget * 	parent,
		const string &	text,
		bool		plainTextMode = false );

    /**
     * Destructor.
     **/
    virtual ~YQRichText();

    /**
     * Change the text content of the RichText widget.
     *
     * Reimplemented from YRichText.
     **/
    virtual void setValue( const string & newValue );

    /**
     * Set this RichText widget's "plain text" mode on or off.
     *
     * Reimplemented from YRichText.
     **/
    virtual void setPlainTextMode( bool on = true );

    /**
     * Set this RichText widget's "auto scroll down" mode on or off.
     *
     * Reimplemented from YRichText.
     **/
    virtual void setAutoScrollDown( bool on = true );
    
    /**
     * Preferred width of the widget.
     *
     * Reimplemented from YWidget.
     **/
    virtual int preferredWidth();

    /**
     * Preferred height of the widget.
     *
     * Reimplemented from YWidget.
     **/
    virtual int preferredHeight();

    /**
     * Set the new size of the widget.
     *
     * Reimplemented from YWidget.
     **/
    virtual void setSize( int newWidth, int newHeight );

    /**
     * Set enabled/disabled state.
     *
     * Reimplemented from YWidget.
     **/
    virtual void setEnabled( bool enabled );

    /**
     * Accept the keyboard focus.
     *
     * Reimplemented from YWidget.
     **/
    virtual bool setKeyboardFocus();

    /**
     * Event filter.
     *
     * Reimplemented from QWidget.
     **/
    virtual bool eventFilter( QObject * obj, QEvent * ev );

    /**
     * Returns 'true' if the current text of this RichText widget contains
     * hyperlinks.
     **/
    bool haveHyperLinks();


protected slots:

    /**
     * Notification that a hyperlink is clicked.
     **/
    void linkClicked( const QString & url );


protected:

    YQTextBrowser *	_textBrowser;
};


/**
 * Helper class - needed to have the benefits of both QVBox as the base class
 * for YQRichText so uniform margins can be implemented (outside, not inside
 * the scroll window as QTextBrowser normally does it) and QTextBrowser's
 * featurs (enable hyperlinks) without removing the text each time the user
 * clicks.
 *
 * This class is required only to overwrite setSource().
 **/
class YQTextBrowser: public QTextBrowser
{
    Q_OBJECT


public:

    /**
     * Constructor
     **/
    YQTextBrowser( QWidget * parent = 0 ):
	QTextBrowser( parent ) {}

public slots:

    /**
     * Get the document pointed to by a hyperlink.
     *
     * Reimplemented from QTextBrowser to avoid having an empty text each time
     * the user clicks on a hyperlink.
     **/
    virtual void setSource( const QString & name ) {}
};


#endif // YQRichText_h