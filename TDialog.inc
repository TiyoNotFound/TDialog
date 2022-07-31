/*

    TDialog - v.2.0
    Make dialog easier & efficient.
    
    Functions:
    TDialog_Show(playerid, dialogid, dialog_type, button0[], button1[]) - This will execute dialog to a player.
    TDialog_SetHeader(dialogid, header[], {Float,_}:....) - Thiss will set the header of a dialog.
    TDialog_SetInfo(dialogid, info[], {Float,_}:....);
    
    Replacements:
    DIALOG_STYLE_MSGBOX                     --> TDIALOG_MSG
    DIALOG_STYLE_LIST                              --> TDIALOG_LIST
    DIALOG_STYLE_TABLIST                      --> TDIALOG_TABLIST
    DIALOG_STYLE_TABLIST_HEADERS --> TDIALOG_TABLIST_HEAD
    DIALOG_STYLE_INPUT                          --> TDIALOG_INPUT
    DIALOG_STYLE_PASSWORD               --> TDIALOG_PASS
    
    Special Thanks:
    - Emmet for #emit stuff
    - Zaxx 
    
*/

#define TDIALOG_CAPTION_LENGTH (32 * 2)
#define TDIALOG_INFO_LENGTH (4086)

enum
{
    TDIALOG_MSG,
    TDIALOG_LIST,
    TDIALOG_TABLIST,
    TDIALOG_TABLIST_HEAD,
    TDIALOG_INPUT,
    TDIALOG_PASS
};

enum E_TDIALOG
{
    E_TDIALOG_HEADER[TDIALOG_CAPTION_LENGTH],
    E_TDIALOG_INFO[TDIALOG_INFO_LENGTH]
};
static E_TDDATA[E_TDIALOG];

stock TDialog_Show(playerid, dialogid, dialog_type, button0[], button1[])
{
    
    switch(dialog_type) {
        case TDIALOG_MSG: ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_MSGBOX, E_TDDATA[E_TDIALOG_HEADER], E_TDDATA[E_TDIALOG_INFO], button0, button1);
        case TDIALOG_LIST: ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_LIST, E_TDDATA[E_TDIALOG_HEADER], E_TDDATA[E_TDIALOG_INFO], button0, button1);
        case TDIALOG_TABLIST: ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_TABLIST, E_TDDATA[E_TDIALOG_HEADER], E_TDDATA[E_TDIALOG_INFO], button0, button1);
        case TDIALOG_TABLIST_HEAD: ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_TABLIST_HEADERS, E_TDDATA[E_TDIALOG_HEADER], E_TDDATA[E_TDIALOG_INFO], button0, button1);
        case TDIALOG_INPUT: ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_INPUT, E_TDDATA[E_TDIALOG_HEADER], E_TDDATA[E_TDIALOG_INFO], button0, button1);
        case TDIALOG_PASS: ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE_PASSWORD, E_TDDATA[E_TDIALOG_HEADER], E_TDDATA[E_TDIALOG_INFO], button0, button1);
    }
    E_TDDATA[E_TDIALOG_HEADER][0] = EOS;
    E_TDDATA[E_TDIALOG_INFO][0] = EOS;
    return 1;
}

stock TDialog_SetHeader(const header[], {Float,_}:...)
{
    static 
        string[64],
        args;
    if ((args = numargs()) > 1)
    {
        while(--args >= 1)
		{
			#emit LCTRL 	5
			#emit LOAD.alt 	args
			#emit SHL.C.alt 2
			#emit ADD.C 	12
			#emit ADD
			#emit LOAD.I
			#emit PUSH.pri
		}
        #emit PUSH.S header
		#emit PUSH.C 64
		#emit PUSH.C string

		#emit LOAD.S.pri 8
		#emit CONST.alt 16
		#emit SUB
		#emit PUSH.pri

		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4
		
	    format(E_TDDATA[E_TDIALOG_HEADER], 64, string);
	    #emit RETN
    }
    else format(E_TDDATA[E_TDIALOG_HEADER], 64, header);
    return 1; 
}

stock TDialog_SetInfo(const info[], {Float,_}:...)
{
    static
        string[4096],
        args;
    if((args = numargs()) > 1)
    {
        while(--args >= 1)
		{
			#emit LCTRL 	5
			#emit LOAD.alt 	args
			#emit SHL.C.alt 2
			#emit ADD.C 	12
			#emit ADD
			#emit LOAD.I
			#emit PUSH.pri
		}
        #emit PUSH.S info
		#emit PUSH.C 4096
		#emit PUSH.C string

		#emit LOAD.S.pri 8
		#emit CONST.alt 16
		#emit SUB
		#emit PUSH.pri

		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4
		format(E_TDDATA[E_TDIALOG_INFO], 4096, string);
		#emit RETN
    }
    else format(E_TDDATA[E_TDIALOG_INFO], 4096, info);
    return 1;
}
