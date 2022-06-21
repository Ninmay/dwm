/**
 * @file
 * This is Maria's colorscheme for dwm to use.
 * 
 * @date 2022 
 */

#ifndef __PALLETE_H__
#define __PALLETE_H__

static const char col_letter1[]     = "#bbbbbb";
static const char col_letter2[]     = "#eeeeee";
static const char col_background[]  = "#1b1a15";
static const char col_foreground[]  = "#312d2e"; // maria_hat
static const char col_black[]       = "#000000";
static const char col_border[]      = "#4a543c"; // doll_eyes 
static const char *colors[][3]      = {
	/*               fg           bg               border       */
	[SchemeNorm] = { col_letter1, col_background,  col_black     },
	[SchemeSel]  = { col_letter2, col_foreground,  col_border    },
};

#endif /* __PALLETE_H__ */
