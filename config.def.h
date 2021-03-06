/* See LICENSE file for copyright and license details. */

/* libraries */
#include <X11/XF86keysym.h>
#include "palette.h"

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const int startwithgaps[]    = {1, 0, 0, 1};	/* 1 means gaps are used by default, this can be customized for each tag */
static const int startwithbar[]     = {1, 0, 1, 1};	/* 1 means gaps are used by default, this can be customized for each tag */
static const unsigned int gappx[]   = {55};   /* default gap between windows in pixels, this can be customized for each tag */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "iosevka-medium.ttc:style=Extended:size=12" };
static const char dmenufont[]       = "iosevka-medium.ttc:style=Extended:size=12";

/* tagging */
static const char *tags[] = { "総", "筆", "網", "遊" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.65; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* second entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};
static const Layout *startwithlayout[] = {
  &layouts[1],
  &layouts[2],
  &layouts[2],
  &layouts[0],
};	/* 1 means gaps are used by default, this can be customized for each tag */

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_background, "-nf", col_letter1, "-sb", col_foreground, "-sf", col_letter2, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *webcmd[]   = { "brave", NULL };
static const char *mailcmd[]  = { "thunderbird", NULL };
static const char *filecmd[]  = { "st", "-e", "ranger", NULL };

/* sound and brightness */
static const char *mutecmd[]    = { "pactl", "set-sink-mute", "0", "toggle", NULL };
static const char *volupcmd[]   = { "pactl", "set-sink-volume", "0", "+5%", NULL };
static const char *voldowncmd[] = { "pactl", "set-sink-volume", "0", "-5%", NULL };
static const char *brupcmd[]    = { "sudo", "xbacklight", "-inc", "10", NULL };
static const char *brdowncmd[]  = { "sudo", "xbacklight", "-dec", "10", NULL };

/* screen capture */
static const char *sprscrcmd[]   = { "screenshot-sel", NULL };
static const char *prscrcmd[]    = { "screenshot", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd  } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd   } },
	{ MODKEY|ShiftMask,             XK_b,      spawn,          {.v = webcmd    } },
	{ MODKEY|ShiftMask,             XK_m,      spawn,          {.v = mailcmd   } },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = filecmd   } },
	{ ShiftMask,                    XK_Print,  spawn,          {.v = sprscrcmd } },
	{ 0,                            XK_Print,  spawn,          {.v = prscrcmd  } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -5 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +5 } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = GAP_TOGGLE} },
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
	/* sound and brightness */
	{ 0, 				XF86XK_AudioMute, spawn, {.v = mutecmd } },
	{ 0, 				XF86XK_AudioLowerVolume, spawn, {.v = voldowncmd } },
	{ 0, 				XF86XK_AudioRaiseVolume, spawn, {.v = volupcmd } },
	{ 0, 				XF86XK_MonBrightnessUp, spawn, {.v = brupcmd} },
	{ 0, 				XF86XK_MonBrightnessDown, spawn, {.v = brdowncmd} },
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
