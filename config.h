/* See LICENSE file for copyright and license details. */

/* appearance */
/* static const char font[]            = "Sans 8";*/
/* static const char font[]            = "century gothic 11";*/
static const char font[]            = "M+ 1c light 11";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#2199ee";
static const char selbgcolor[]      = "#2199ee";
static const char selfgcolor[]      = "#000000";
static const unsigned int borderpx  = 8;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool statusmarkup      = True;     /* True means use pango markup in status message */

/* tagging */
static const char *tags[] = { "1:web", "2:Term", "3:files", "4:Gvim", "5:Emacs", "6", "7:Gimp", "8:Inkscape", "9:Office" };

static const Rule rules[] = {
	/* class        instance    title       tags mask     isfloating   monitor */
	{ "Gimp",              NULL,       NULL,       1 << 6,       False,       -1 },
	{ "Inkscape",          NULL,       NULL,       1 << 7,       False,       -1 },
	{ "Terminator",        NULL,       NULL,       1 << 1,       False,       -1 },
	{ "Transmission-gtk",  NULL,       NULL,       1 << 5,       False,       -1 },
	{ "Uget-gtk",          NULL,       NULL,       1 << 5,       False,       -1 },
	{ "chromium-browser",  NULL,       NULL,       1 << 3,       False,       -1 },
	{ "Emacs",             NULL,       NULL,       1 << 4,       False,       -1 },
	{ "Gvim",              NULL,       NULL,       1 << 3,       False,       -1 },
	{ "mplayer2",          NULL,       NULL,       1 << 8,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTMODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      toggleview,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      view,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
/* static const char *dmenucmd[] = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };*/
static const char *rofiruncmd[] = { "rofi", "-show", "run", NULL };
static const char *termcmd[]  = { "uxterm", NULL };
/* runorraise programs */
static const char *emacs[]      = { "emacs", NULL, NULL, NULL, "Emacs" };
static const char *browser[]    = { "iceweasel", NULL, NULL, NULL,  "Iceweasel" };
static const char *terminator[] = { "terminator", NULL, NULL, NULL,  "Terminator" };

static Key keys[] = {
	/* modifier                     key        function        argument */
	/*{ ALTMODKEY,                    XK_p,      spawn,          {.v = dmenucmd } },*/
	{ 0,                            XK_Print,  spawn,    SHCMD("exec scrot -q 90 -t 25 '%Y-%m-%d-%H-%M-%S.png' -e 'mv $f ~/.scrots'") }, 
	{ ALTMODKEY,                    XK_m,      setlayout,      {.v = &layouts[2]} },
	{ ALTMODKEY,                    XK_p,      spawn,          {.v = rofiruncmd } },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
        { MODKEY,                       XK_b,      runorraise,     {.v = browser } },
        { MODKEY,                       XK_m,      runorraise,     {.v = emacs } },
        { MODKEY,                       XK_n,      runorraise,     {.v = terminator } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	/* mapping the letter key 'o' to easily toggle the terminator tag */
	TAGKEYS(                        XK_o,                      1)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        toggleview,           {0} },
	{ ClkTagBar,            0,              Button3,        view,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

