/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Iosevka Fixed Slab:size=8:style=Medium Extended" };
static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { "#cdd6f4", "#1e1e2e", "#45475a" },
    [SchemeSel]  = { "#ffffff", "#89b4fa", "#89b4fa" },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class        instance    title       tags mask     isfloating   monitor */
    { "KeePassXC",  NULL,       NULL,       0,            1,           -1 },
    { "Otpclient",  NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
};

/* key definitions */
#define M Mod4Mask
#define A Mod1Mask
#define S ShiftMask
#define C ControlMask
#define TAGKEYS(KEY,TAG) \
    { M,        KEY,    view,           {.ui = 1 << TAG} }, \
    { M|C,      KEY,    toggleview,     {.ui = 1 << TAG} }, \
    { M|S,      KEY,    tag,            {.ui = 1 << TAG} }, \
    { M|C|S,    KEY,    toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const Key keys[] = {
    /* modifier     key             function            argument */
    /* window controls */
    { M,            XK_b,           togglebar,          {0} },
    { M,            XK_j,           focusstack,         {.i = +1 } },
    { M,            XK_k,           focusstack,         {.i = -1 } },
    { M,            XK_o,           incnmaster,         {.i = +1 } },
    { M|S,          XK_o,           incnmaster,         {.i = -1 } },
    { M,            XK_h,           setmfact,           {.f = -0.05} },
    { M,            XK_l,           setmfact,           {.f = +0.05} },
    { M,            XK_space,       zoom,               {0} },
    { M,            XK_Tab,         view,               {0} },
    { M|S,          XK_q,           killclient,         {0} },
    /* layout controls */
    { M,            XK_t,           setlayout,          {.v = &layouts[0]} },
    { M,            XK_f,           setlayout,          {.v = &layouts[1]} },
    { M|S,          XK_t,           setlayout,          {.v = &layouts[2]} },
    { M|S,          XK_space,       togglefloating,     {0} },
    /* monitor controls */
    { M,            XK_period,      focusmon,           {.i = +1 } },
    { M|S,          XK_period,      focusmon,           {.i = -1 } },
    { M,            XK_comma,       tagmon,             {.i = +1 } },
    { M|S,          XK_comma,       tagmon,             {.i = -1 } },
    /* tag controls */
    { M,            XK_0,           view,               {.ui = ~0 } },
    { M|S,          XK_0,           tag,                {.ui = ~0 } },
    TAGKEYS(        XK_1,                               0)
    TAGKEYS(        XK_2,                               1)
    TAGKEYS(        XK_3,                               2)
    TAGKEYS(        XK_4,                               3)
    TAGKEYS(        XK_5,                               4)
    TAGKEYS(        XK_6,                               5)
    TAGKEYS(        XK_7,                               6)
    TAGKEYS(        XK_8,                               7)
    TAGKEYS(        XK_9,                               8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkClientWin,         M,              Button1,        movemouse,      {0} },
    { ClkClientWin,         M,              Button2,        togglefloating, {0} },
    { ClkClientWin,         M,              Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
};
