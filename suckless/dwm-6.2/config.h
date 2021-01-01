#include <X11/XF86keysym.h>

static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 20;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 : no bar
                                                 * 1 : yes bar */
static const int topbar             = 1;        /* 0 : bottom bar
                                                 * 1 : top bar */
static const char *fonts[]          = { "unscii:size=12:antialias=true:autohint=true" };
static const char *colors[][3]      = {
/*                fg        bg        border   */
[SchemeNorm] = { "#eceff4","#4c566a","#2e3440" },
[SchemeSel]  = { "#eceff4","#2e3440","#5e81ac" },
};
static const char *tags[] = { "P", "u", "m", "p", "k", "o" };
/* Tags Collection */
/* Pumpko     { "P", "u", "m", "p", "k", "o" }
 * Arrows     { "←", "↑", "→", "↓", "↕", "↖", "↗", "↘", "↙" }
 * Subscript  { "₁", "₂", "₃", "₄", "₅", "₆", "₇", "₈", "₉" }
 * Dots       { "●", "●", "●", "●", "●", "●", "●", "●", "●" }
 * Japanese   { "一", "二", "三", "四", "五", "六", "七", "八", "九" };*/
static const Rule rules[] = {
/* xprop(1):
 *	WM_CLASS(STRING) = instance, class
 *	WM_NAME(STRING) = title */
/* class      instance    title       tags mask     iscentered   isfloating   isfakefullscreen   monitor */
{ "Gimp",     NULL,       NULL,       0,            0,           0,           0,                 -1 },
{ "firefox",  NULL,       NULL,       1 << 8,       0,           0,           1,                 -1 },
{ "termapp",  NULL,       NULL,       0,            1,           1,           0,                 -1 },
{ "mpv",      NULL,       NULL,       0,            1,           1,           0,                 -1 },
{ "Sxiv",     NULL,       NULL,       0,            1,           1,           0,                 -1 },
{ "Dragon",   NULL,       NULL,       0,            1,           1,           0,                 -1 },
{ "stalonetray",NULL,     NULL,       0,            1,           1,           0,                 -1 },
};

/* layout */
static const float mfact     = 0.5;             /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;               /* number of clients in master area */
static const int resizehints = 0;               /* 0 : don't respect size hints
                                                 * 1 : means respect size hints in tiled resizals */
static const int decorhints  = 1;               /* 1 means respect decoration hints */

#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[ ]",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
        { "[D]",      deck },
        { "|M|",      centeredmaster },
};

/************/
/* Bindings */
/************/
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
  /*apps*/
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-c", "-i", "-l", "1", NULL };
static const char *termcmd[]  = { "tabbed", "-cf", "-r", "2", "st", "-w", """", NULL };
static const char *ncmpcpp[]  = { "st", "-c", "termapp", "-g", "100x25", "-e", "ncmpcpp", NULL };
static const char *pulsemixer[] = { "st", "-c", "termapp", "-g", "100x25", "-e", "pulsemixer", NULL };
static const char *nnn[]  = { "st", "-c", "termapp", "-g", "100x25", "-e", "nnn", "-C", NULL };
static const char *rss[]  = { "st", "-c", "termapp", "-g", "100x25", "-e", "newsboat", "-r", "-u", "~/.config/newsboat/urls", "-C", "~/.config/newsboat/config", "-c", "~/.config/newsboat/cache", NULL };
static const char *cal[]  = { "st", "-c", "termapp", "-g", "100x25", "-e", "calcurse", NULL };
static const char *sdcv[]  = { "st", "-c", "termapp", "-g", "100x25", "-e", "sdcv", "--color", NULL };
static const char *trackma[]  = { "st", "-c", "termapp", "-g", "100x25", "-e", "trackma-curses", NULL };
static const char *calc[]  = { "st", "-c", "termapp", "-g", "100x25", "-e", "calc", NULL };
static const char *project[]  = { "st", "-c", "termapp", "-g", "100x25", "-e", "nvim", "/home/pumpko/document/project/project.wiki", NULL };

#include "movestack.c" /*movestack*/
#include "shiftview.c" /*shiftview*/
static Key keys[] = {
	/* modifier                     key        function        argument */
	
        /* Applications */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("st -c termapp -g 100x25") },
	{ MODKEY,                       XK_t,      spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_m,      spawn,          {.v = ncmpcpp } },
	{ MODKEY,                       XK_a,      spawn,          {.v = pulsemixer } },
	{ MODKEY,                       XK_f,      spawn,          {.v = nnn } },
	{ MODKEY,                       XK_r,      spawn,          {.v = rss } },
	{ MODKEY,                       XK_c,      spawn,          {.v = cal } },
	{ MODKEY,                       XK_d,      spawn,          {.v = sdcv } },
        { MODKEY,                       XK_n,      spawn,          {.v = trackma } },
	{ 0,               XF86XK_Calculator,      spawn,          {.v = calc } },
        { MODKEY,                       XK_o,      spawn,          {.v = project } },
        { MODKEY,                       XK_q,      spawn,          SHCMD("~/.bin/motivation") },

	{ MODKEY,                       XK_s,      spawn,          SHCMD("~/.bin/key") },
	{ 0,                         XK_Menu,      spawn,          SHCMD("~/.bin/menu") },
	{ MODKEY,                       XK_w,      spawn,          SHCMD("~/.bin/bookmark") },
	{ MODKEY,                  XK_Escape,      spawn,          SHCMD("~/.bin/power") },
	{ MODKEY,                      XK_F1,      spawn,          SHCMD("~/.bin/dmenu_mount") },
	{ MODKEY|ShiftMask,            XK_F1,      spawn,          SHCMD("~/.bin/dmenu_umount") },
        { 0,                 XF86XK_Explorer,      spawn,          SHCMD("~/.bin/monitorpreset") },
	/* Pulseaudio Control */
	{ 0,                XF86XK_AudioMute,      spawn,          SHCMD("~/.bin/vol-mute") },
	{ 0,         XF86XK_AudioRaiseVolume,      spawn,          SHCMD("~/.bin/vol-up") },
	{ 0,         XF86XK_AudioLowerVolume,      spawn,          SHCMD("~/.bin/vol-down") },
        /* MPD Control */
	{ 0,                XF86XK_AudioNext,      spawn,          SHCMD("~/.bin/mpcnext") },
	{ 0,                XF86XK_AudioPrev,      spawn,          SHCMD("~/.bin/mpcprev") },
	{ 0,                XF86XK_AudioPlay,      spawn,          SHCMD("~/.bin/mpctoggle") },
	{ 0,                XF86XK_AudioStop,      spawn,          SHCMD("~/.bin/mpcstop") },
	{ 0,                    XF86XK_Tools,      spawn,          SHCMD("~/.bin/mpcshow ; ~/.bin/killbar") },
	{ ShiftMask, XF86XK_AudioRaiseVolume,      spawn,          SHCMD("~/.bin/mpc-up") },
	{ ShiftMask, XF86XK_AudioLowerVolume,      spawn,          SHCMD("~/.bin/mpc-down") }, 
        /* Utilities */
	{ 0,                        XK_Print,      spawn,          SHCMD("~/.bin/screencaptureroot") },
	{ ControlMask,              XK_Print,      spawn,          SHCMD("~/.bin/screencapturearea") },
	{ MODKEY|ShiftMask,             XK_c,      spawn,          SHCMD("~/.bin/colorpicker") },
	/* dwm */	
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = -1 } },
        { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
        { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
        { MODKEY|ShiftMask,             XK_l,      shiftview,      {.i = +1 } },
        { MODKEY|ShiftMask,             XK_h,      shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
        { MODKEY|ShiftMask,             XK_equal,  incrgaps,       {.i = +5 } },
        { MODKEY,                       XK_minus,  incrgaps,       {.i = -5 } },
        { MODKEY|ControlMask,           XK_i,      incrigaps,      {.i = +5 } },
        { MODKEY|ControlMask|ShiftMask, XK_i,      incrigaps,      {.i = -5 } },
        { MODKEY|ControlMask,           XK_o,      incrogaps,      {.i = +5 } },
        { MODKEY|ControlMask|ShiftMask, XK_o,      incrogaps,      {.i = -5 } },
        { MODKEY|ControlMask,           XK_7,      incrihgaps,     {.i = +5 } },
        { MODKEY|ControlMask|ShiftMask, XK_7,      incrihgaps,     {.i = -5 } },
        { MODKEY|ControlMask,           XK_8,      incrivgaps,     {.i = +5 } },
        { MODKEY|ControlMask|ShiftMask, XK_8,      incrivgaps,     {.i = -5 } },
        { MODKEY|ControlMask,           XK_9,      incrohgaps,     {.i = +5 } },
        { MODKEY|ControlMask|ShiftMask, XK_9,      incrohgaps,     {.i = -5 } },
        { MODKEY|ControlMask,           XK_0,      incrovgaps,     {.i = +5 } },
        { MODKEY|ControlMask|ShiftMask, XK_0,      incrovgaps,     {.i = -5 } },
        { MODKEY,                       XK_grave,  togglegaps,     {0} },
        { MODKEY|ControlMask|ShiftMask, XK_grave,  defaultgaps,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_e,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
        { MODKEY|ShiftMask,             XK_d,      setlayout,      {.v = &layouts[3]} },
        { MODKEY|ShiftMask,             XK_u,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  togglefloating, {0} },
        { MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
        { MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
        { MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
        { MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
        { MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
        { MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
        { MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
        { MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_grave,  view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_grave,  tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_r,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      spawn,          SHCMD("killall xinit") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          SHCMD("tray") },
	{ ClkStatusText,        0,              Button3,        spawn,          SHCMD("~/.bin/killbar") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
        { ClkRootWin,           0,              Button3,        spawn,          SHCMD("~/.bin/menu") },
};
