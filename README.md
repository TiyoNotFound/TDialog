# TDialog
TDialog helps scripters organize their scripts and optimize dialogs. It has new features that are not in the normal samp-team dialog. One of the new features is that there is no need to declare a format function to include variables and other strings inside it.

# Installation
Simply install to your project:                  
Include in your code and begin using the library:
```pawn
#include <TDialog>
```

# Functions                      

```pawn
/*
PARAMS:  
header[] - The header of a dialog to show it.
{Float,_}:... - The variable to store the data  
  
RETURNS:  
1 on success, otherwise 0  
*/
TDialog_SetHeader(const header[], {Float,_}:...);

/*
PARAMS:  
info[] - The info of a dialog to show it.
{Float,_}:... - The variable to store the data  
  
RETURNS:  
1 on success, otherwise 0  
*/
TDialog_SetInfo(const info[], {Float,_}:...);

/*
PARAMS:  
playerid - The player to see the dialog.
dialogid - The dialogid to execute.
dialog_type - The dialog type of dialog (TDIALOG_MSG, TDIALOG_LIST, TDIALOG_TABLIST, TDIALOG_TABLIST_HEAD, TDIALOG_INPUT, TDIALOG_PASS)
button0[] - The button0 of a dialog to show it.
button1[] - The button1 of a dialog to show it.
  
RETURNS:  
1 on success, otherwise 0  
*/
TDialog_Show(playerid, dialogid, dialog_type, const button0[], const button1[]);
```
# Usage
```pawn
#include <a_samp>
#include <TDialog>

public OnPlayerConnect(playerid)
{
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, sizeof(name));
    TDialog_SetHeader("%s", name);
    TDialog_SetInfo("Hello there.");
    TDialog_Show(playerid, Test, TDIALOG_MSG, "Ok", ""); 
    return 1;
}
```
# Callbacks
```pawn
TDialogCall:Test(playerid, response, listitem, inputtext[])
{
    // Code
    return 1;
}

# Replacements
```pawn
DIALOG_STYLE_MSGBOX          --> TDIALOG_MSG
DIALOG_STYLE_LIST            --> TDIALOG_LIST
DIALOG_STYLE_TABLIST         --> TDIALOG_TABLIST
DIALOG_STYLE_TABLIST_HEADERS --> TDIALOG_TABLIST_HEAD
DIALOG_STYLE_INPUT           --> TDIALOG_INPUT
DIALOG_STYLE_PASSWORD        --> TDIALOG_PASS
```
