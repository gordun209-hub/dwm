/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx = 3; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const unsigned int gappih = 20;  /* horiz inner gap between windows */
static const unsigned int gappiv = 20;  /* vert inner gap between windows */
static const unsigned int gappoh =    20; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov = 20; /* vert outer gap between windows and screen edge */
static int smartgaps =   0; /* 1 means no outer gap when there is only one window */
static const int showbar = 1;     /* 0 means no bar */
static const int topbar = 1;      /* 0 means bottom bar */
static const int user_bh            = 22;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[] = {
    /* System Fonts : */
    "JetBrains Mono:style=Bold:size=12:antialias=true:autohint=true",
    //"Fantasque Sans Mono:style=Bold:size=12:antialias=true:autohint=true",
    //"monospace:style=Bold:size=10:antialias=true:autohint=true"
    /* Emoji & Icon Fonts : */
    "JoyPixels:size=10:antialias=true:autohint=true",
    "Font Awesome 6 Free-Solid-900:pixelsize=20", "fontawesome:pixelsize=14",
    "Font Awesome 6 Free-Regular-400:pixelsize=14",
    "Font Awesome 6 Brands-Regular-400:pixelsize=14",
    "Font Awesome 6 Free Solid:pixelsize=14",
    "Font Awesome 6 Brands:pixelsize=14",
    "Material Design Icons-Regular:pixelsize=20:antialias=true:autohint=true",
    "Sanskrit2003:pixelsize=20:antialias=true:autohint=true",
    /* Nerd Fonts : */
    "JetBrainsMono Nerd Font:style=Bold:size=20:antialias=true:autohint=true",
    //"FantasqueSansMono Nerd
    // Font:style=Bold:size=12:antialias=true:autohint=true", "Roboto Mono for
    // Powerline:pixelsize=14:antialias=true:autohint=true", "SauceCodePro Nerd
    // Font Mono:weight=bold:pixelsize=10:antialias=true:hinting=true",
};

static const char col_1[]       = "#1e222a";
static const char col_2[]       = "#1e222a";
static const char col_3[]       = "#545862";
static const char col_4[]       = "#f64645";
static const char col_cyan[]        = "#6d8dad";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	  [SchemeNorm] = { col_3, col_1, col_2 },
	  [SchemeSel]  = { col_4, col_1, col_4 },
	  [SchemeStatus]  = { col_3, col_1, col_1 }, // Statusbar right {text,background,not used but cannot be empty}
	  [SchemeTagsSel]  = { col_1, col_4, col_4 }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { col_3, col_1, col_1 }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]  = { col_4, col_1, col_4 }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { col_3, col_1, col_1 }, // infobar middle  unselected {text,background,not used but cannot be empty}
};



/* tagging */

static const char *tags[] = { "󰲠","󰲢","󰲤","󰲦","󰲨","󰲪"};
static const unsigned int ulinepad =
    5; /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke =
    2; /* thickness / height of the underline */
static const unsigned int ulinevoffset =
    0; /* how far above the bottom of the bar the line should appear */
static const int ulineall =
    0; /* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
    {"Gimp", NULL, NULL, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, -1},
    {NULL, "spterm", NULL, SPTAG(0), 1, -1},
    {NULL, "spaud", NULL, SPTAG(1), 1, -1},
    {NULL, "spmus", NULL, SPTAG(2), 1, -1},
};

static const float mfact = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT                                                           \
  1 /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"[M]", monocle},
    {"[@]", spiral},
    {"[\\]", dwindle},
    {"H[]", deck},
    {"TTT", bstack},
    {"===", bstackhoriz},
    {"HHH", grid},
    {"###", nrowgrid},
    {"---", horizgrid},
    {":::", gaplessgrid},
    {"|M|", centeredmaster},
    {">M>", centeredfloatingmaster},
    {"><>", NULL}, /* no layout function means floating behavior */
    {NULL, NULL},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

#define STATUSBAR "dwmblocks"

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall = 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"dmenu_run", "-c", "-l",    "20", "-g",
                                 "2",         "-p", "Run :", NULL};
static const char *rofiwcmd[] = {"rofi", "-show", "window", NULL};
static const char *termcmd[] = {"st", NULL};
static const char *tuifmcmd[] = {"st", "-e", "lf", NULL};
static const char *webcmd[] = {"chromium", NULL};

static Key keys[] = {
    // Apps
    {MODKEY,             XK_Return,    spawn,        {.v = termcmd}},
    {MODKEY,             XK_d,         spawn,        {.v = dmenucmd}},
    {MODKEY,             XK_w,         spawn,        {.v = webcmd}},
    {MODKEY,             XK_e,         spawn,        {.v = tuifmcmd}},
    {MODKEY|ShiftMask,   XK_d,         spawn,        {.v = rofiwcmd}},
    {MODKEY|ShiftMask,   XK_space,     togglefloating,{0}},
    {ControlMask,        XK_comma,     cyclelayout,  {.i = +1}},
    {ControlMask,        XK_period,    cyclelayout,  {.i = -1}},
    {MODKEY,             XK_t,         setlayout,    {.v = &layouts[0]}},
    {MODKEY,             XK_f,         togglefullscr,{0}},
    {MODKEY,             XK_b,         togglebar,    {0}},
    {MODKEY|ShiftMask,   XK_Tab,       zoom,         {0}},
    {MODKEY,             XK_h,         setmfact,     {.f = -0.05}},
    {MODKEY,             XK_l,         setmfact,     {.f = +0.05}},
    {MODKEY|ControlMask, XK_v,         incnmaster,   {.i = +1}},
    {MODKEY|ControlMask, XK_h,         incnmaster,   {.i = -1}},
    {MODKEY,             XK_q,         killclient,   {0}},
    {MODKEY,             XK_j,         focusstack,   {.i = +1}},
    {MODKEY,             XK_k,         focusstack,   {.i = -1}},
    {MODKEY|ShiftMask,   XK_q,         quit,         {0}},
    {MODKEY,             XK_comma,     focusmon,     {.i = -1}},
    {MODKEY,             XK_period,    focusmon,     {.i = +1}},
    {MODKEY|ShiftMask,   XK_comma,     tagmon,       {.i = -1}},
    {MODKEY|ShiftMask,   XK_period,    tagmon,       {.i = +1}},
    {MODKEY,             XK_p,         togglescratch,{.ui = 0}},
    {MODKEY,             XK_s,         togglescratch,{.ui = 1}},
    {MODKEY,             XK_m,         togglescratch,{.ui = 2}},
    {MODKEY|Mod1Mask,    XK_u,         incrgaps,     {.i = +1}},
    {MODKEY|Mod1Mask|ShiftMask, XK_u,  incrgaps,     {.i = -1}},
    {MODKEY|Mod1Mask, XK_i,            incrigaps,    {.i = +1}},
    {MODKEY|Mod1Mask|ShiftMask, XK_i,incrigaps,      {.i = -1}},
    {MODKEY|Mod1Mask,           XK_o,incrogaps,      {.i = +1}},
    {MODKEY|Mod1Mask|ShiftMask, XK_o,incrogaps,      {.i = -1}},
    {MODKEY|Mod1Mask, XK_6,            incrihgaps,   {.i = +1}},
    {MODKEY|Mod1Mask|ShiftMask, XK_6,incrihgaps,     {.i = -1}},
    {MODKEY|Mod1Mask, XK_7,            incrivgaps,   {.i = +1}},
    {MODKEY|Mod1Mask|ShiftMask, XK_7,incrivgaps,     {.i = -1}},
    {MODKEY|Mod1Mask, XK_8,            incrohgaps,   {.i = +1}},
    {MODKEY|Mod1Mask|ShiftMask, XK_8,incrohgaps,     {.i = -1}},
    {MODKEY|Mod1Mask, XK_9,            incrovgaps,   {.i = +1}},
    {MODKEY|Mod1Mask|ShiftMask, XK_9,incrovgaps,     {.i = -1}},
    {MODKEY|Mod1Mask, XK_0,            togglegaps,   {0}},
    {MODKEY|Mod1Mask|ShiftMask, XK_0,defaultgaps,    {0}},
    {MODKEY|ControlMask|ShiftMask,XK_q,quit,         {1}},
    TAGKEYS(XK_1, 0)
    TAGKEYS(XK_2, 1)
    TAGKEYS(XK_3, 2)
    TAGKEYS(XK_4, 3)
    TAGKEYS(XK_5, 4) 
    TAGKEYS(XK_6, 5)
    TAGKEYS(XK_7, 6)
    TAGKEYS(XK_8, 7)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },//
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
};
