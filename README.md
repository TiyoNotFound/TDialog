# TDialog
Simple dialog usage and functions.
This is created for entertainment and testing a 
framework.

# Features
Script Features:
  • Simple to use                
  • Allign your code                       
  • Can use all types of cmd processor                    
  • Can add formats or strings

# Functions
All different types of dialog
```
TDialog_MsgBox(playerid, dialogid, description[]);
TDialog_List(playerid, dialogid, description[]);
TDialog_Tablist(playerid, dialogid, description[]);
TDialog_TablistHeaders(playerid, dialogid, description[]);
TDialog_Input(playerid, dialogid, description[]);
TDialog_Password(playerid, dialogid, description[]);
```

Executor Functions
```
TDialog_Show(playerid, dialogid, title[], button1[], button2[]);
```
Executor Callback
```
public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    return 1;
}
```
# Usage
Filterscript Use
```
#define TDialog_FILTERSCRIPT
#include <TDialog>


```
Gamemode Use
```
#define TDialog_GAMEMODE
#include <TDialog>
```


# Credits
  • SA-MP Team
