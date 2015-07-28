#define NUMCOLORS       13
#define MODKEY          Mod1Mask
#define MONKEY          Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MONKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MONKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MONKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MONKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
    
static const unsigned int tagspacing = 0;       /* space between tags */
static const unsigned int tagpadding = 1;      /* inner padding of tags */
static const unsigned int taglinepx = 3;        /* height of tag underline */
static const unsigned int systrayspacing = 1;   /* systray spacing */
static const Bool showsystray = True;           /* false means no systray */
static const unsigned int gappx = 0;            /* gaps between windows */
static const unsigned int borderpx = 0;         /* border pixel of windows */
static const unsigned int snap = 32;            /* snap pixel */
static const Bool showbar = True;               /* false means no bar */
static const Bool topbar = True;                /* false means bottom bar */
static const float mfact = 0.50;                /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;                   /* number of clients in master area */
static const Bool resizehints = False;          /* true means respect size hints in tiled resizals */

//static const char font[] = "-*-tamsynmod-medium-r-*-*-14-*-*-*-*-*-*-*"; //-*-terminus-medium-r-*-*-20-*-*-*-*-*-*-*";
//static const char font2[] = "-*-terminus-medium-r-*-*-22-*-*-*-*-*-*-*"; 
/*static const char font[] = "-*-tamsynmod-medium-r-*-*-14-*-*-*-*-*-*-*";*/
static const char font[] = "-*-ohsnap.icons-medium-r-*-*-14-*-*-*-*-*-*-*";
static const char colors[NUMCOLORS][ColLast][13] = {
    /* border    fg         bg */
    { "#2D2D2D", "#FFFFFF", "#2D2D2D" },        /* 01 - regular */
    { "#D64937", "#FFFFFF", "#2D2D2D" },        /* 02 - selected #5E5E9E: xanh, #D64937: do, #349147: green */
    { "#2D2D2D", "#FF99CC", "#2D2D2D" },        /* 03 - urgent */
    { "#2D2D2D", "#666666", "#2D2D2D" },        /* 04 - occupied */
    { "#2D2D2D", "#A82222", "#2D2D2D" },        /* 05 - red */
    { "#2D2D2D", "#6699CC", "#2D2D2D" },        /* 06 - blue 4779b3*/
    { "#2D2D2D", "#349147", "#2D2D2D" },        /* 07 - green */
    { "#2D2D2D", "#666666", "#2D2D2D" },        /* 08 - dark grey */
    { "#2D2D2D", "#DCDCDC", "#2D2D2D" },        /* 09 - light grey */
    { "#2D2D2D", "#D64937", "#2D2D2D" },        /* 0A - orange #4779b3*/
    { "#2D2D2D", "#B86A6A", "#2D2D2D" },        /* 0B - pink */
    { "#2D2D2D", "#FFFFFF", "#2D2D2D" },        /* 0C - white */
    { "#2D2D2D", "#000000", "#2D2D2D" },        /* 0D - black */
};

static const Layout layouts[] = {
    /* symbol   gaps    arrange */
    { "þ",      True,   tile },
    { "ü",      True,   bstack },
    { "ÿ",      False,  monocle },
    { "ý",      False,  NULL },
};

static const Tag tags[] = {
    /* name     layout          mfact   nmaster */
    { "web",    &layouts[0],    -1,     -1 },
    { "term",   &layouts[2],    -1,     -1 },
    { "chat",   &layouts[0],    -1,     -1 },
    { "media",  &layouts[1],    -1,     -1 },
    { "edit",   &layouts[0],    -1,     -1 },
    { "mail",   &layouts[0],    -1,     -1 },
    { "misc",   &layouts[0],    -1,     -1 },
};

static const Rule rules[] = {
    /* class        instance    title       tags mask     isfloating      iscentred       monitor */
   { "Chromium",    NULL,       NULL,       1 << 0,       False,            False,        -1 },
   { "Google-chrome-stable",    NULL,       NULL,         1 << 0,           False,            False,        -1 },
   { "Firefox",     NULL,       NULL,       1 << 0,       False,            False,       -1 },
   { "Terminator",  NULL,       NULL,       1 << 1,       False,            False,       -1 },
   { "Skype",       NULL,       NULL,       1 << 2,       False,            False,       -1 },
   { "Pidgin",      NULL,       NULL,       1 << 2,       False,            False,       -1 },
   { "Pcmanfm",     NULL,       NULL,       1 << 3,       False,            False,       -1 },
   { "Thunar",      NULL,       NULL,       1 << 3,       False,            False,       -1 },
   { "Geany",       NULL,       NULL,       1 << 4,       False,            False,       -1 },
   { "Vlc",         NULL,       NULL,       1 << 6,       False,            False,       -1 },
};

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
/* Brightness keys */
#define KEY_BRIGHTNESS_UP 0x1008ff02
#define KEY_BRIGHTNESS_DOWN 0x1008ff03
static const char *menu[] = { "dmenu_run", "-i", "-fn", font, "-nb", colors[0][ColBG], "-nf", colors[0][ColFG], "-sb", colors[1][ColBG], "-sf", colors[9][ColFG], NULL };
static const char *webb[] = { "chromium", NULL, "Chromium" };
static const char *file[] = { "thunar", NULL, "Thunar" };
static const char *mailcmd[] = { "urxvtc", "-title", "mutt", "-e", "mutt", NULL };
static const char *tmuxcmd[] = { "urxvtc", "-title", "tmux", "-e", "tmux", NULL };
static const char *yt[] = { "urxvtc", "-title", "YouTube" "-e", "youtube-viewer", NULL };
static const char *term[] = { "terminator", NULL, "Terminator"};
static const char *edit[] = { "geany", NULL, "Geany" };
static const char *chat[] = { "skype", NULL, "Skype" };
static const char *mute[] = { "amixer", "-q", "set", "Master", "toggle", NULL };
static const char *volu[] = { "amixer", "-q", "set", "Master", "5%+", "unmute", NULL };
static const char *vold[] = { "amixer", "-q", "set", "Master", "5%-", "unmute", NULL };
static const char *cmdbrightnessup[] = { "light", "-A", "5", NULL };
static const char *cmdbrightnessdown[] = { "light", "-U", "5", NULL };

static Key keys[] = {
    { MONKEY,           XK_p,       spawn,          {.v = menu } },
    { MONKEY,           XK_F10,     spawn,          {.v = mute } },
    { MONKEY,           XK_F11,     spawn,          {.v = vold } },
    { MONKEY,           XK_F12,     spawn,          {.v = volu } },
    { MONKEY,           XK_F6,      spawn,          {.v = cmdbrightnessup } },
    { MONKEY,           XK_F5,      spawn,          {.v = cmdbrightnessdown } },

    { MONKEY|ShiftMask, XK_w,       runorraise,          {.v = webb } },
    { MONKEY|ShiftMask, XK_Return,  spawn,     {.v = term } },
    { MONKEY|ShiftMask, XK_f,       runorraise,     {.v = file } },
    { MONKEY|ShiftMask, XK_s,       runorraise,     {.v = chat } },
    { MONKEY|ShiftMask, XK_t,       runorraise,     {.v = tmuxcmd } },
    { MONKEY|ShiftMask, XK_m,       runorraise,     {.v = mailcmd } },
    { MONKEY|ShiftMask, XK_y,       runorraise,     {.v = yt } },

//    { MONKEY|ShiftMask, XK_z,       runorraise,     {.v = fz } },
    { MONKEY|ShiftMask, XK_e,       runorraise,     {.v = edit } },
    { MONKEY|ShiftMask, XK_q,       quit,           {0} },
    { MONKEY|ShiftMask, XK_b,       togglebar,      {0} },
    { MONKEY|ShiftMask, XK_c,       killclient,     {0} },
    { MONKEY,           XK_Return,  zoom,           {0} },
    { MODKEY,           XK_Tab,     view,           {0} },
    { MONKEY|ControlMask,           XK_f, togglefloating, {0} },
    { MONKEY,           XK_space,   setlayout,      {0} },
    { MONKEY,           XK_t,       setlayout,      {.v = &layouts[0] } },
    { MONKEY,           XK_b,       setlayout,      {.v = &layouts[1] } },
    { MONKEY,           XK_m,       setlayout,      {.v = &layouts[2] } },
    { MONKEY,           XK_f,       setlayout,      {.v = &layouts[3] } },
    { MONKEY,           XK_j,       focusstack,     {.i = +1 } },
    { MONKEY,           XK_k,       focusstack,     {.i = -1 } },
    { MONKEY,           XK_h,       setmfact,       {.f = -0.05 } },
    { MONKEY,           XK_l,       setmfact,       {.f = +0.05 } },
    { MONKEY,           XK_equal,   incnmaster,     {.i = +1 } },
    { MONKEY,           XK_minus,   incnmaster,     {.i = -1 } },
    { MONKEY,           XK_Down,    focusstack,     {.i = +1 } },
    { MONKEY,           XK_Up,      focusstack,     {.i = -1 } },
    { MONKEY,           XK_0,       view,           {.ui = ~0 } },
    { MONKEY|ShiftMask, XK_0,       tag,            {.ui = ~0 } },
    { MONKEY,           XK_comma,   focusmon,       {.i = -1 } },
    { MONKEY,           XK_period,  focusmon,       {.i = +1 } },
    { MONKEY|ShiftMask, XK_comma,   tagmon,         {.i = -1 } },
    { MONKEY|ShiftMask, XK_period,  tagmon,         {.i = +1 } },
    { MONKEY,                       XK_Left,   cycle,          {.i = -1 } },
    { MONKEY,                       XK_Right,  cycle,          {.i = +1 } },
    { MONKEY|ControlMask,           XK_Left,   tagcycle,       {.i = -1 } },
    { MONKEY|ControlMask,           XK_Right,  tagcycle,       {.i = +1 } },
    { MONKEY|ControlMask,           XK_j,      pushdown,       {0} },                                                                                      
    { MONKEY|ControlMask,           XK_k,      pushup,         {0} },
    { MONKEY|ControlMask,           XK_q,      quit,           {0} },
    TAGKEYS(            XK_1,       0)
    TAGKEYS(            XK_2,       1)
    TAGKEYS(            XK_3,       2)
    TAGKEYS(            XK_4,       3)
    TAGKEYS(            XK_5,       4)
    TAGKEYS(            XK_6,       5)
};

static Button buttons[] = {
    { ClkLtSymbol,      0,          Button1,        setlayout,      {0} },
    { ClkClientWin,     MONKEY,     Button1,        movemouse,      {0} },
    { ClkClientWin,     MONKEY,     Button2,        togglefloating, {0} },
    { ClkClientWin,     MONKEY,     Button3,        resizemouse,    {0} },
    { ClkTagBar,        0,          Button1,        view,           {0} },
    { ClkTagBar,        0,          Button3,        toggleview,     {0} },
    { ClkTagBar,        MONKEY,     Button1,        tag,            {0} },
    { ClkTagBar,        MONKEY,     Button3,        toggletag,      {0} },
};
