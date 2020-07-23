#include <X11/XF86keysym.h>
/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "dwm:size=10" };
static const char col_nord_night1[] = "#2e3440";
static const char col_nord_night2[] = "#3b4252";
static const char col_nord_night3[] = "#434c5e";
static const char col_nord_night4[] = "#4c566a";
static const char col_nord_snow1[]  = "#d8dee9";
static const char col_nord_snow2[]  = "#e5e9f0";
static const char col_nord_snow3[]  = "#eceff4";
static const char col_nord_frost1[] = "#8fbcbb";
static const char col_nord_frost2[] = "#88c0d0";
static const char col_nord_frost3[] = "#81a1c1";
static const char col_nord_frost4[] = "#5e81ac";
static const char col_nord_aurora1[]= "#bf616a";
static const char col_nord_aurora2[]= "#d08770";
static const char col_nord_aurora3[]= "#ebcb8b";
static const char col_nord_aurora4[]= "#a3be8c";
static const char col_nord_aurora5[]= "#b48ead";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_nord_snow3,col_nord_night4,col_nord_night1 },
	[SchemeSel]  = { col_nord_snow3,col_nord_night1,col_nord_frost4 },
};

/* tagging */
static const char *tags[] = { "P", "u", "m", "p", "k", "o" };

/*******************/
/* Tags Collection */
/*******************/
/* Arrows     { "←", "↑", "→", "↓", "↕", "↖", "↗", "↘", "↙" };*/
/* Subscript  { "₁", "₂", "₃", "₄", "₅", "₆", "₇", "₈", "₉" };*/
/* Dots       { "●", "●", "●", "●", "●", "●", "●", "●", "●" };*/
/* Japanese   { "一", "二", "三", "四", "五", "六", "七", "八", "九" };*/

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
        /* class      instance    title       tags mask     iscentered   isfloating   monitor */
        { "Gimp",     NULL,       NULL,       0,            0,           0,           -1 },
        { "firefox",  NULL,       NULL,       1 << 8,       0,           0,           -1 },
	{ "termapp",  NULL,       NULL,       0,            1,           1,           -1 },
	{ "mpv",      NULL,       NULL,       0,            1,           1,           -1 },
	{ "Sxiv",     NULL,       NULL,       0,            1,           1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "tabbed", "-cf", "-r", "2", "st", "-w", """", NULL };
static const char *ncmpcpp[]  = { "st", "-c", "termapp", "-g", "100x25", "-e", "ncmpcpp", NULL };
static const char *pulsemixer[] = { "st", "-c", "termapp", "-g", "100x25", "-e", "pulsemixer", NULL };
static const char *nnn[]  = { "st", "-c", "termapp", "-g", "100x25", "-e", "nnn", NULL };
static const char *rss[]  = { "st", "-c", "termapp", "-g", "100x25", "-e", "newsboat", NULL };
static const char *cal[]  = { "st", "-c", "termapp", "-g", "100x25", "-e", "calcurse", NULL };
	/* Screen Capture */
static const char *scrcaproot[] = { "screencaptureroot", NULL };
static const char *scrcaparea[] = { "screencapturearea", NULL };
	/* Pulseaudio Control */
static const char *audiomute[]  = { "vol-mute", NULL };
static const char *audioraise[] = { "vol-up", NULL };
static const char *audiolower[] = { "vol-down", NULL };
        /* MPD Control */
static const char *mpcnext[] = { "mpcnext", NULL };
static const char *mpcprev[] = { "mpcprev", NULL };
static const char *mpctoggle[] = { "mpc", "toggle", NULL };
static const char *mpcstop[] = { "mpc", "stop", NULL };
static const char *mpcshow[] = { "mpcshow", NULL };

static const char *killx[] = { "killall", "xinit", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	
        /* Applications */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_t,      spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_m,      spawn,          {.v = ncmpcpp } },
	{ MODKEY,                       XK_a,      spawn,          {.v = pulsemixer } },
	{ MODKEY,                       XK_f,      spawn,          {.v = nnn } },
	{ MODKEY,                       XK_r,      spawn,          {.v = rss } },
	{ MODKEY,                       XK_c,      spawn,          {.v = cal } },
	/* Pulseaudio Control */
	{ 0,                XF86XK_AudioMute,      spawn,          {.v = audiomute } },
	{ 0,         XF86XK_AudioRaiseVolume,      spawn,          {.v = audioraise } },
	{ 0,         XF86XK_AudioLowerVolume,      spawn,          {.v = audiolower } },
        /* MPD Control */
	{ 0,                XF86XK_AudioNext,      spawn,          {.v = mpcnext } },
	{ 0,                XF86XK_AudioPrev,      spawn,          {.v = mpcprev } },
	{ 0,                XF86XK_AudioPlay,      spawn,          {.v = mpctoggle } },
	{ 0,                XF86XK_AudioStop,      spawn,          {.v = mpcstop } },
	{ 0,                    XF86XK_Tools,      spawn,          {.v = mpcshow } },
        /* Utilities */
	{ 0,                        XK_Print,      spawn,          {.v = scrcaproot } },
	{ ControlMask,              XK_Print,      spawn,          {.v = scrcaparea } },
	/* dwm Control */	
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_e,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
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
	{ MODKEY,                       XK_q,      spawn,          {.v = killx } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
