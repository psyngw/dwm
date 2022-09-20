/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const Bool viewontag         = True;     /* Switch view on tag switch */
// static const char *fonts[]          = { "SauceCodePro Nerd Font Mono:size=12" };
static const char *fonts[]     = {"SauceCodePro Nerd Font Mono:size=12",
                                  "Sarasa UI SC:size=10:antialias=true:autohint=true",
                                  "JoyPixels:size=12:antialias=true:autohint=true"};
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char *altbarcmd        = "$HOME/scripts/dwm/bar.sh"; /* Alternate bar launch command */
static const char dmenufont[]       = "SauceCodePro Nerd Font Mono:size=12";
static char normbgcolor[]           = "#2E3440";
static char normbordercolor[]       = "#3B4252";
static char normfgcolor[]           = "#ECEFF4";
static char selfgcolor[]            = "#D8DEE9";
static char selbordercolor[]        = "#5E81AC";
static char selbgcolor[]            = "#5E81AC";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const unsigned int baralpha = 0xd0;
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int borderalpha = OPAQUE;
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};
// static const char *colors[][3]      = {
// 	/*               fg         bg         border   */
// 	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
// 	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
// 	[SchemeHid]  = { col_cyan,  col_gray1, col_cyan  },
// };
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
// static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };
// static const char *tags[] = { "LocalShell", "Chrome", "Database", "Daily", "Daily", "Daily", "Buffer", "WeChat", "SSH" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                            instance                 title           tags mask    isfloating   isterminal    noswallow  monitor */
  { "Google-chrome",                 "google-chrome",             NULL,               1 << 1,       0,    0,     -1,       -1 },
	{ "navicat",                       "navicat",                   NULL,               1 << 2,       0,    0,     -1,       -1 },
	{ "netease-cloud-music",            NULL,                       NULL,               1 << 4,       0,    0,     -1,       -1 },
	{ "Steam",                          NULL,                       NULL,               1 << 3,       0,    0,     -1,       -1 },
	{ "wechat",                         NULL,                       NULL,               1 << 6,       0,    0,     -1,       -1 },
	{ "qv2ray",                         NULL,                       NULL,               1 << 1,       0,    0,     -1,       -1 },
	{ "Alacritty",                      "Alacritty",                NULL,               1 << 0,       0,    1,      0,       -1 },
  { "st-256color",                    "st-256color",              NULL,                    0,       0,    1,      0,       -1 },
  { "feh",                             "feh",                     NULL,                    0,       0,    0,      0,       -1 },
  { "Surf",                             "surf",                   NULL,                    0,       0,    0,      1,       -1 },
  { NULL,                             NULL,                     "Event Tester",                    0,       0,    0,      1,       -1 },
};
// static const Rule rules[] = {
// 	/* xprop(1):
// 	 *	WM_CLASS(STRING) = instance, class
// 	 *	WM_NAME(STRING) = title
// 	 */
// 	/* class      instance    title       tags mask     isfloating   monitor */
// 	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
// 	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
// };

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#include "layouts.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
// #define MODKEY Mod1Mask
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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
// static const char *termcmd[]  = { "st", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *slockcmd[]  = { "slock", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };
static const char *trayercmd[] = { "/bin/bash", "/home/warren/scripts/tt.sh", NULL };
static const char *mountcmd[] = { "/bin/bash", "/home/warren/scripts/wponedrive.sh", NULL };
static const char *wpchangecmd[] = { "/bin/bash", "/home/warren/scripts/dwm/wp-change.sh", NULL };
static const char *flameshotcmd[] = { "flameshot", "gui", NULL };
static const char *voiceup[] = { "/bin/bash", "/home/warren/scripts/dwm/wp-alsa-up.sh", NULL };
static const char *voicedown[] = { "/bin/bash", "/home/warren/scripts/dwm/wp-alsa-down.sh", NULL };
static const char *voicetoggle[] = { "/bin/bash", "/home/warren/scripts/dwm/wp-alsa-toggle.sh", NULL };
// static const char *voiceup[] = { "amixer", "set", "Master", "5%+", NULL };
// static const char *voicedown[] = { "amixer", "set", "Master", "5%-", NULL };
// static const char *voicetoggle[] = { "amixer", "set", "Master", "toggle", NULL };
static const char *shutdowndwm[] = { "killall", "xinit", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = flameshotcmd } },
	{ MODKEY|ShiftMask,             XK_l,      spawn,          {.v = slockcmd } },
	{ MODKEY,                       XK_F9,     spawn,          {.v = voicedown } },
	{ MODKEY,                       XK_F10,    spawn,          {.v = voiceup } },
	{ MODKEY,                       XK_F11,    spawn,          {.v = voicetoggle } },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_comma,  spawn,          {.v = wpchangecmd } },
	{ MODKEY,                       XK_period, spawn,          {.v = mountcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_i,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_i,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_r,      hidewin,        {0} },
	{ MODKEY|ShiftMask,             XK_r,      restorewin,     {0} },
	// { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	// { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|Mod1Mask,              XK_h,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_l,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_f,      fullscreen,     {0} },
	{ MODKEY|ShiftMask,             XK_z,      spawn,          {.v = trayercmd } },
	// { MODKEY,                       XK_space,  setlayout,      {0} },
	// { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	// { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	// { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	// { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	// { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	// { MODKEY,                       XK_space,  setlayout,      {0} },
	// { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	// { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	// { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	// { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	// { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	// { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	// { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask|Mod1Mask,             XK_q,      spawn,           { .v = shutdowndwm } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
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

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

