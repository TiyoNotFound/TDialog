/*
    Dialog Style include - TiyoNotFound
    
     Easy to use this include made for intertainment only
     
     Functions
     
     All Dialog Types
     You can use some formats or string in TDialog functions
     
     TDialog_MsgBox(playerid, dialogid, description[]); 
     TDialog_List(playerid, dialogid, description[]); 
     TDialog_Tablist(playerid, dialogid, description[]);
     TDialog_TablistHeaders(playerid, dialogid, description[]);
     TDialog_Input(playerid, dialogid, description[]);
     TDialog_Password(playerid, dialogid, description[]);
     
     // Executor Function
     The dialog is automatically read and execute the dialog.
     TDialog_Show(playerid, dialogid, title[], button1[], button2[]);
     
     // Executor Callback
     Default Dialog callback
     public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])

     // Filterscript uses
     If you are using this include to filterscript try to define #define TDialog_FILTERSCRIPT
     before you including it.

     #define TDialog_FILTERSCRIPT
     #include <TDialog>   
     
     // Gamemode Uses
     If you are using this include to gamemode pwn file try to define #define TDialog_GAMEMODE
     before you including it.
     
     #define TDialog_GAMEMODE
     #include <TDialog>
     
     Enjoy!! - TiyoNotFound
         
*/

#define E_DIALOG_MSGBOX 0
#define E_DIALOG_LIST 1
#define E_DIALOG_TABLIST 2
#define E_DIALOG_TABLISTHEADERS 3
#define E_DIALOG_INPUT 4
#define E_DIALOG_PASSOWRD 5



#define INVALID_DIALOG_TYPES -1

enum E_DIALOGSTYLE_ENUM
{
    TD_DIALOGID,
    TD_DESCRIPTION[1000],
    TD_TYPES  
};
static DialogData[MAX_PLAYERS][E_DIALOGSTYLE_ENUM];


#if defined TDialog_FILTERSCRIPT
	stock TDialog_MsgBox(playerid, dialogid, description[])	
	{
	    format(DialogData[playerid][TD_DESCRIPTION], 1000, description);
	    
	    DialogData[playerid][TD_DIALOGID] = dialogid;
	    DialogData[playerid][TD_TYPES] = E_DIALOG_MSGBOX;
	    return true;
	}
	
	stock TDialog_List(playerid, dialogid, description[])
	{
	    format(DialogData[playerid][TD_DESCRIPTION], 1000, description);
	    
	    DialogData[playerid][TD_DIALOGID] = dialogid;
	    DialogData[playerid][TD_TYPES] = E_DIALOG_LIST;
	    return true;
	}
	
	stock TDialog_Tablist(playerid, dialogid, description[])
	{
	    format(DialogData[playerid][TD_DESCRIPTION], 1000, description);
	    
	    DialogData[playerid][TD_DIALOGID] = dialogid;
	    DialogData[playerid][TD_TYPES] = E_DIALOG_TABLIST;
	    return true;
	}
	
	stock TDialog_TablistHeaders(playerid, dialogid, description[])
	{
	    format(DialogData[playerid][TD_DESCRIPTION], 1000, description);
	    
	    DialogData[playerid][TD_DIALOGID] = dialogid;
	    DialogData[playerid][TD_TYPES] = E_DIALOG_TABLISTHEADERS;
	    return true;
	}
	
	stock TDialog_Input(playerid, dialogid, description[])
	{
	    format(DialogData[playerid][TD_DESCRIPTION], 1000, description);
	    
	    DialogData[playerid][TD_DIALOGID] = dialogid;
	    DialogData[playerid][TD_TYPES] = E_DIALOG_INPUT;
	    return true;
	}
	
	stock TDialog_Password(playerid, dialogid, description[])
	{
	    format(DialogData[playerid][TD_DESCRIPTION], 1000, description);
	    
	    DialogData[playerid][TD_DIALOGID] = dialogid;
	    DialogData[playerid][TD_TYPES] = E_DIALOG_PASSOWRD; 
	    return true;
	}
#endif

#if defined TDialog_GAMEMODE
    stock TDialog_MsgBox(playerid, dialogid, description[])	
	{
	    format(DialogData[playerid][TD_DESCRIPTION], 1000, description);
	    
	    DialogData[playerid][TD_DIALOGID] = dialogid;
	    DialogData[playerid][TD_TYPES] = E_DIALOG_MSGBOX;
	    return true;
	}
	
	stock TDialog_List(playerid, dialogid, description[])
	{
	    format(DialogData[playerid][TD_DESCRIPTION], 1000, description);
	    
	    DialogData[playerid][TD_DIALOGID] = dialogid;
	    DialogData[playerid][TD_TYPES] = E_DIALOG_LIST;
	    return true;
	}
	
	stock TDialog_Tablist(playerid, dialogid, description[])
	{
	    format(DialogData[playerid][TD_DESCRIPTION], 1000, description);
	    
	    DialogData[playerid][TD_DIALOGID] = dialogid;
	    DialogData[playerid][TD_TYPES] = E_DIALOG_TABLIST;
	    return true;
	}
	
	stock TDialog_TablistHeaders(playerid, dialogid, description[])
	{
	    format(DialogData[playerid][TD_DESCRIPTION], 1000, description);
	    
	    DialogData[playerid][TD_DIALOGID] = dialogid;
	    DialogData[playerid][TD_TYPES] = E_DIALOG_TABLISTHEADERS;
	    return true;
	}
	
	stock TDialog_Input(playerid, dialogid, description[])
	{
	    format(DialogData[playerid][TD_DESCRIPTION], 1000, description);
	    
	    DialogData[playerid][TD_DIALOGID] = dialogid;
	    DialogData[playerid][TD_TYPES] = E_DIALOG_INPUT;
	    return true;
	}
	
	stock TDialog_Password(playerid, dialogid, description[])
	{
	    format(DialogData[playerid][TD_DESCRIPTION], 1000, description);
	    
	    DialogData[playerid][TD_DIALOGID] = dialogid;
	    DialogData[playerid][TD_TYPES] = E_DIALOG_PASSOWRD; 
	    return true;
	}
#endif    

#if defined TDialog_FILTERSCRIPT
	stock TDialog_Show(playerid, dialogid, title[], button1[], button2[])
	{
	    if(DialogData[playerid][TD_TYPES] == E_DIALOG_MSGBOX) {
		    ShowPlayerDialog(playerid, 
		    DialogData[playerid][TD_DIALOGID], 
		    DIALOG_STYLE_MSGBOX, title,
		    DialogData[playerid][TD_DESCRIPTION], button1, button2);
		    return 1;
		}
		if(DialogData[playerid][TD_TYPES] == E_DIALOG_LIST) {
		    ShowPlayerDialog(playerid, 
		    DialogData[playerid][TD_DIALOGID], 
		    DIALOG_STYLE_LIST, title,
		    DialogData[playerid][TD_DESCRIPTION], button1, button2);
		    return 1;
		}
		if(DialogData[playerid][TD_TYPES] == E_DIALOG_TABLIST) {
		    ShowPlayerDialog(playerid, 
		    DialogData[playerid][TD_DIALOGID], 
		    DIALOG_STYLE_TABLIST, title,
		    DialogData[playerid][TD_DESCRIPTION], button1, button2);
		    return 1;
		}
		if(DialogData[playerid][TD_TYPES] == E_DIALOG_TABLISTHEADERS) {
		    ShowPlayerDialog(playerid, 
		    DialogData[playerid][TD_DIALOGID], 
		    DIALOG_STYLE_TABLIST_HEADERS, title,
		    DialogData[playerid][TD_DESCRIPTION], button1, button2);
		    return 1;
		}
		if(DialogData[playerid][TD_TYPES] == E_DIALOG_INPUT) {
		    ShowPlayerDialog(playerid, 
		    DialogData[playerid][TD_DIALOGID], 
		    DIALOG_STYLE_INPUT, title,
		    DialogData[playerid][TD_DESCRIPTION], button1, button2);
		    return 1;
		}
		if(DialogData[playerid][TD_TYPES] == E_DIALOG_INPUT) {
		    ShowPlayerDialog(
		    playerid, 
		    DialogData[playerid][TD_DIALOGID], 
		    DIALOG_STYLE_PASSWORD, title,
		    DialogData[playerid][TD_DESCRIPTION], button1, button2);
		    return 1;
		}
	    
	    // Reset Dialog Variable to avoid dialog spoofing
	    DialogData[playerid][TD_TYPES] = INVALID_DIALOG_TYPES;
	    return true;
	}
#endif

#if defined TDialog_GAMEMODE
	stock TDialog_Show(playerid, dialogid, title[], button1[], button2[])
	{
	    if(DialogData[playerid][TD_TYPES] == E_DIALOG_MSGBOX) {
		    ShowPlayerDialog(playerid, 
		    DialogData[playerid][TD_DIALOGID], 
		    DIALOG_STYLE_MSGBOX, title,
		    DialogData[playerid][TD_DESCRIPTION], button1, button2);
		    return 1;
		}
		if(DialogData[playerid][TD_TYPES] == E_DIALOG_LIST) {
		    ShowPlayerDialog(playerid, 
		    DialogData[playerid][TD_DIALOGID], 
		    DIALOG_STYLE_LIST, title,
		    DialogData[playerid][TD_DESCRIPTION], button1, button2);
		    return 1;
		}
		if(DialogData[playerid][TD_TYPES] == E_DIALOG_TABLIST) {
		    ShowPlayerDialog(playerid, 
		    DialogData[playerid][TD_DIALOGID], 
		    DIALOG_STYLE_TABLIST, title,
		    DialogData[playerid][TD_DESCRIPTION], button1, button2);
		    return 1;
		}
		if(DialogData[playerid][TD_TYPES] == E_DIALOG_TABLISTHEADERS) {
		    ShowPlayerDialog(playerid, 
		    DialogData[playerid][TD_DIALOGID], 
		    DIALOG_STYLE_TABLIST_HEADERS, title,
		    DialogData[playerid][TD_DESCRIPTION], button1, button2);
		    return 1;
		}
		if(DialogData[playerid][TD_TYPES] == E_DIALOG_INPUT) {
		    ShowPlayerDialog(playerid, 
		    DialogData[playerid][TD_DIALOGID], 
		    DIALOG_STYLE_INPUT, title,
		    DialogData[playerid][TD_DESCRIPTION], button1, button2);
		    return 1;
		}
		if(DialogData[playerid][TD_TYPES] == E_DIALOG_INPUT) {
		    ShowPlayerDialog(
		    playerid, 
		    DialogData[playerid][TD_DIALOGID], 
		    DIALOG_STYLE_PASSWORD, title,
		    DialogData[playerid][TD_DESCRIPTION], button1, button2);
		    return 1;
		}
	    
	    // Reset Dialog Variable to avoid dialog spoofing
	    DialogData[playerid][TD_TYPES] = INVALID_DIALOG_TYPES;
	    return true;
	}
#endif