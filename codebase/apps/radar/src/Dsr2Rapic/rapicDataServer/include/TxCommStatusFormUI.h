
//////////////////////////////////////////////////////////////
//
// Header file for TxCommStatusFormUI
//
//    This file is generated by RapidApp 1.2
//
//    This class implements the user interface portion of a class
//    Normally it is not used directly.
//    Instead the subclass, TxCommStatusForm is instantiated
//
//    To extend or alter the behavior of this class, you should
//    modify the TxCommStatusForm files
//
//    Restrict changes to those sections between
//    the "//--- Start/End editable code block" markers
//
//    This will allow RapidApp to integrate changes more easily
//
//    This class is a ViewKit user interface "component".
//    For more information on how components are used, see the
//    "ViewKit Programmers' Manual", and the RapidApp
//    User's Guide.
//
//////////////////////////////////////////////////////////////
#ifndef TXCOMMSTATUSFORMUI_H
#define TXCOMMSTATUSFORMUI_H
#include <Vk/VkComponent.h>


//---- Start editable code block: headers and declarations


//---- End editable code block: headers and declarations


class TxCommStatusFormUI : public VkComponent
{ 

  public:

    TxCommStatusFormUI ( const char *, Widget );
    TxCommStatusFormUI ( const char * );
    ~TxCommStatusFormUI();
    void create ( Widget );
    const char *  className();

    //---- Start editable code block: TxCommStatusForm public


    //---- End editable code block: TxCommStatusForm public


  protected:


    // Widgets created by this class

    Widget  _connStatusLabel1;
    Widget  _connToLabel1;
    Widget  _connTypeLabel1;
    Widget  _currReqLabel1;
    Widget  _deviceDescriptionLabel1;
    Widget  _expectAckToggle;
    Widget  _failTimeLabel1;
    Widget  _forceReconnButton;
    Widget  _label31;
    Widget  _label36;
    Widget  _label37;
    Widget  _label42;
    Widget  _label45;
    Widget  _label46;
    Widget  _rowcolumn3;
    Widget  _rowcolumn4;
    Widget  _rowcolumn5;
    Widget  _scrolledWindow9;
    Widget  _suppressTxAlertsToggle1;
    Widget  _txCommStatusForm2;
    Widget  _txDevFilterList;
    Widget  _txEnabledToggle;


    // These virtual functions are called from the private callbacks (below)
    // Intended to be overriden in derived classes to define actions

    virtual void suppressFutureAlertsChanged ( Widget, XtPointer );
    virtual void uifEnabledChanged ( Widget, XtPointer );
    virtual void uifExpectAckChanged ( Widget, XtPointer );
    virtual void uifForceReconnect ( Widget, XtPointer );

    //---- Start editable code block: TxCommStatusForm protected


    //---- End editable code block: TxCommStatusForm protected


  private: 

    // Array of default resources

    static String      _defaultTxCommStatusFormUIResources[];


    // Callbacks to interface with Motif

    static void suppressFutureAlertsChangedCallback ( Widget, XtPointer, XtPointer );
    static void uifEnabledChangedCallback ( Widget, XtPointer, XtPointer );
    static void uifExpectAckChangedCallback ( Widget, XtPointer, XtPointer );
    static void uifForceReconnectCallback ( Widget, XtPointer, XtPointer );

    //---- Start editable code block: TxCommStatusForm private


    //---- End editable code block: TxCommStatusForm private
};
//---- Start editable code block: End of generated code


//---- End editable code block: End of generated code

#endif
