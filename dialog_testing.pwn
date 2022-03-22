#define TDialog_GAMEMODE
#include <TDialog>


#define DIALOG_CONNECT 0

public OnPlayerConnect(playerid)
{
    new str[128], name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name, MAX_PLAYER_NAME);

    format(str, sizeof(str), "Welcome to the server %s", name);
    TDialog_MsgBox(playerid, DIALOG_CONNECT, str);
    TDialog_Show(playerid, DIALOG_CONNECT, "Welcome", "Done", "");
    return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
    if(dialogid == DIALOG_CONNECT)
    {
       if(response) SendClientMessage(playerid, -1, "Welcome to the server!");
    }
    return 1;
}
