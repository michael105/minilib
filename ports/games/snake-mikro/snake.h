/* Micro Snake, based on a simple simple snake game by Simon Huggins
 * 
 * Copyright (c) 2003, 2004  Simon Huggins <webmaster@simonhuggins.com>
 * Copyright (c) 2009  Joachim Nilsson <troglobit@gmail.com>
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Original Borland Builder C/C++ snake code available at Simon's home page
 * http://www.simonhuggins.com/courses/cbasics/course_notes/snake.htm
 */

#ifndef __SNAKE_H__
#define __SNAKE_H__

#define GOLD      '$'
#define CACTUS    '*'

#define MAXROW    22
#define MAXCOL    78

#define START_LEN (4 + level)
#define START_COL (MAXCOL / 2 - START_LEN)
#define START_ROW ((MAXROW + 1) / 2)

#define DEFAULT_DELAY 200000
#define DEFAULT_KEYS  {'j', 'l', 'i', 'k', 's', 'd', 'q'}
//#define DEFAULT_KEYS  {'o', 'p', 'a', 'z', 'f', 'j', 'q'}

typedef enum { LEFT=0, RIGHT, UP, DOWN, LEFT_TURN, RIGHT_TURN, QUIT, NUM_KEYS } direction_t;

typedef struct
{
   int row, col;
} snake_segment_t;

typedef struct
{
   unsigned int    speed;
   direction_t     dir;

   int             len;
   snake_segment_t body[100];
} snake_t;

typedef struct
{
   int level;
   int score;
   int high_score;
   int gold;
   int obstacles;

   char grid[MAXROW][MAXCOL];
} screen_t;

#endif /* __SNAKE_H__ */

/**
 * Local Variables:
 *  version-control: t
 *  c-file-style: "ellemtel"
 * End:
 */
