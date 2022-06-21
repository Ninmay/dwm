/**
 * @file
 * This is the Maria's colorscheme for dwm to use.
 * 
 * @date 2022 
 */

#ifndef __PALLETE_H__
#define __PALLETE_H__

static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_black[]       = "#000000";
static const char col_background[]  = "#1b1a15";
static const char col_doll_eyes[]   = "#4a543c";
static const char col_maria_hat[]   = "#312d2e";
static const char *colors[][3]      = {
	/*               fg         bg               border       */
	[SchemeNorm] = { col_gray3, col_background,  col_black     },
	[SchemeSel]  = { col_gray4, col_maria_hat,   col_doll_eyes },
};

#endif /* __PALLETE_H__ */
