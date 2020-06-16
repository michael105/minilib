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
#include "conio.h"
#include "snake.h"

#ifndef VERSION
#define VERSION "1.0.2b"
#endif

//#define DEBUG

#ifdef DEBUG
#define DBG(fmt, args...) fprintf (stderr, fmt, ##args)
#else
#define DBG(fmt, args...)
#endif

/* Default 0.2 sec between snake movement. */
unsigned int usec_delay = DEFAULT_DELAY;

int sigsetup (int signo, void (*callback)(int))
{
   struct sigaction action;

   sigemptyset(&action.sa_mask);
   //sigaddset(&action.sa_mask, signo);
   action.sa_flags = 0;
   action.sa_handler = callback;
   if (SIGALRM == signo)
   {
#ifdef SA_INTERRUPT
      action.sa_flags |= SA_INTERRUPT; /* SunOS 4.x */
#endif
   }
   else
   {
#ifdef SA_RESTART
      action.sa_flags |= SA_RESTART; /* SVR4, 4.4BSD */
#endif
   }
		errno=0;
   int r = sigaction (signo, &action,0);
	 int e = errno;
	 DBG("errno: %d\n",e);
	 DBG("r: %d\n",r);
	 return(r);
}

void volatile sig_handler (int signal __attribute__ ((unused)))
{
   clrscr ();
   DBG("Received signal %d\n", signal);
   exit (WEXITSTATUS(system ("stty sane")));
}

void volatile alarm_handler (int signal __attribute__ ((unused)))
{
   static struct itimerval val;

   DBG("alarm_handler\n");
   if (!signal)
   {
      sigsetup (SIGALRM, alarm_handler);
   }

   val.it_value.tv_sec  = 0;
   val.it_value.tv_usec = usec_delay;

   setitimer (ITIMER_REAL, &val, 0);
}

void show_score (screen_t *screen)
{
   textcolor (LIGHTCYAN);
   gotoxy (3, MAXROW + 2);
   printf ("Level: %05d", screen->level);

   textcolor (YELLOW);
   gotoxy (21, MAXROW + 2);
   printf ("Gold Left: %05d", screen->gold);

   textcolor (LIGHTGREEN);
   gotoxy (43, MAXROW + 2);
   printf ("Score: %05d", screen->score);

   textcolor (LIGHTMAGENTA);
   gotoxy (61, MAXROW + 2);
   printf ("High Score: %05d", screen->high_score);
}

void draw_line (int col, int row)
{
   int i;

   gotoxy (col, row);
   textbackground (LIGHTBLUE);
   textcolor (LIGHTBLUE);

   for (i = 0; i < MAXCOL + 2; i++)
   {
      if (i == 0 || i == MAXCOL + 1)
         printf ("+");
      else
         printf ("-");
   }

   textattr (RESETATTR);
}

/* If level==0 then just move on to the next level
 * if level==1 restart game
 * Otherwise start game at that level. */
void setup_level (screen_t *screen, snake_t *snake, int level)
{
   int i, row, col;

   srand ((unsigned int)time (NULL));

   /* Initialize on (re)start */
   if (1 == level)
   {
      screen->score = 0;
      screen->obstacles = 4;
      screen->level = 1;
      snake->speed = 14;
      snake->dir = RIGHT;
   }
   else
   {
      screen->score += screen->level * 1000;
      screen->obstacles += 2;
      screen->level++;          /* add to obstacles */

      if ((screen->level % 5 == 0) && (snake->speed > 1))
      {
         snake->speed--;        /* increase snake->speed every 5 levels */
      }
   }

   /* Set up global variables for new level */
   screen->gold = 0;
   snake->len = level + 4;
   usec_delay = DEFAULT_DELAY - level * 10000;

   /* Fill grid with blanks */
   for (row = 0; row < MAXROW; row++)
   {
      for (col = 0; col < MAXCOL; col++)
      {
         screen->grid[row][col] = ' ';
      }
   }

   /* Fill grid with objects */
   for (i = 0; i < screen->obstacles * 2; i++)
   {
      /* Find free space to place an object on. */
      do
      {
         row = rand () % MAXROW;
         col = rand () % MAXCOL;
      }
      while (screen->grid[row][col] != ' ');

      if (i < screen->obstacles)
      {
         screen->grid[row][col] = CACTUS;
      }
      else
      {
         screen->gold++;
         screen->grid[row][col] = GOLD;
      }
   }

   /* Create snake array of length snake->len */
   for (i = 0; i < snake->len; i++)
   {
      snake->body[i].row = START_ROW;
      snake->body[i].col = snake->dir == LEFT ? START_COL - i : START_COL + i;
   }

   /* Draw playing board */
   clrscr();
   draw_line (1, 1);

   for (row = 0; row < MAXROW; row++)
   {
      gotoxy (1, row + 2);

      textcolor (LIGHTBLUE);
      textbackground (LIGHTBLUE);
      printf ("|");
      textattr (RESETATTR);

      textcolor (WHITE);
      for (col = 0; col < MAXCOL; col++)
      {
         printf ("%c", screen->grid[row][col]);
      }

      textcolor (LIGHTBLUE);
      textbackground (LIGHTBLUE);
      printf ("|");
      textattr (RESETATTR);
   }

   draw_line (1, MAXROW + 2);

   show_score (screen);

   textcolor (LIGHTRED);
   //gotoxy (3, 1);
   //printf ("h:Help");
   gotoxy (30, 1);
   printf ("[ Micro Snake v%s ]", VERSION);
}

void move (snake_t *snake, char keys[], char key)
{
   int i;
   direction_t prev = snake->dir;

   if (key == keys[RIGHT])
   {
      snake->dir = RIGHT;
   }
   else if (key == keys[LEFT])
   {
      snake->dir = LEFT;
   }
   else if (key == keys[UP])
   {
      snake->dir = UP;
   }
   else if (key == keys[DOWN])
   {
      snake->dir = DOWN;
   }
   else if (key == keys[LEFT_TURN])
   {
      switch (prev)
      {
         case LEFT:
            snake->dir = DOWN;
            break;

         case RIGHT:
            snake->dir = UP;
            break;

         case UP:
            snake->dir = LEFT;
            break;

         case DOWN:
            snake->dir = RIGHT;
            break;

         default:
            break;
      }
   }
   else if (key == keys[RIGHT_TURN])
   {
      switch (prev)
      {
         case LEFT:
            snake->dir = UP;
            break;

         case RIGHT:
            snake->dir = DOWN;
            break;

         case UP:
            snake->dir = RIGHT;
            break;

         case DOWN:
            snake->dir = LEFT;
            break;

         default:
            break;
      }
   }

   switch (snake->dir)
   {
      case LEFT:
         snake->body[snake->len].row = snake->body[snake->len - 1].row;
         snake->body[snake->len].col = snake->body[snake->len - 1].col - 1;
         break;

      case RIGHT:
         snake->body[snake->len].row = snake->body[snake->len - 1].row;
         snake->body[snake->len].col = snake->body[snake->len - 1].col + 1;
         break;

      case UP:
         snake->body[snake->len].row = snake->body[snake->len - 1].row - 1;
         snake->body[snake->len].col = snake->body[snake->len - 1].col;
         break;

      case DOWN:
         snake->body[snake->len].row = snake->body[snake->len - 1].row + 1;
         snake->body[snake->len].col = snake->body[snake->len - 1].col;
         break;

      default:
         /* NOP */
         break;
   }

   /* Blank last segment of snake */
   textattr (RESETATTR);
   gotoxy (snake->body[0].col + 1, snake->body[0].row + 1);
   puts (" ");

   /* ... and remove it from the array */
   for (i = 1; i <= snake->len; i++)
   {
      snake->body[i - 1] = snake->body[i];
   }

   /* Display snake in yellow */
   textbackground (YELLOW);
   for (i = 0; i < snake->len; i++)
   {
      gotoxy (snake->body[i].col + 1, snake->body[i].row + 1);
      puts (" ");
   }
   textattr (RESETATTR);
#ifdef DEBUG
   gotoxy (71, 1);
   printf ("(%02d,%02d)", snake->body[snake->len - 1].col, snake->body[snake->len - 1].row);
#endif
}

int collide_walls (snake_t *snake)
{
   snake_segment_t *head = &snake->body[snake->len - 1];

   if ((head->row > MAXROW) || (head->row < 1) ||
       (head->col > MAXCOL) || (head->col < 1))
   {
      DBG("Wall collision.\n");
      return 1;
   }

   return 0;
}

int collide_object (snake_t *snake, screen_t *screen, char object)
{
   snake_segment_t *head = &snake->body[snake->len - 1];

   if (screen->grid[head->row - 1][head->col - 1] == object)
   {
      DBG("Object '%c' collision.\n", object);
      return 1;
   }

   return 0;
}

int collide_self (snake_t *snake)
{
   int i;
   snake_segment_t *head = &snake->body[snake->len - 1];

   for (i = 0; i < snake->len - 1; i++)
   {
      snake_segment_t *body = &snake->body[i];

      if (head->row == body->row && head->col == body->col)
      {
         DBG("Self collision.\n");
         return 1;
      }
   }

   return 0;
}

int collision (snake_t *snake, screen_t *screen)
{
   return collide_walls (snake) ||
      collide_object (snake, screen, CACTUS) ||
      collide_self (snake);
}

int eat_gold (snake_t *snake, screen_t *screen)
{
   snake_segment_t *head = &snake->body[snake->len - 1];

   /* We're called after collide_object() so we know it's
    * a piece of gold at this position.  Eat it up! */
   screen->grid[head->row - 1][head->col - 1] = ' ';

   screen->gold--;
   screen->score += snake->len * screen->obstacles;
   snake->len++;

   if (screen->score > screen->high_score)
   {
      screen->high_score = screen->score; /* New high score! */
   }

   return screen->gold;
}

int main (void)
{
   char keypress;
   snake_t snake;
   screen_t screen;
   char keys[NUM_KEYS] = DEFAULT_KEYS;

   if (WEXITSTATUS(system ("stty cbreak -echo stop u")))
   {
      fprintf (stderr, "Failed setting up the screen, is 'stty' missing?\n");
      return 1;
   }

	 DBG("1\n");
   sigsetup (SIGINT, sig_handler);
   sigsetup (SIGHUP, sig_handler);
   sigsetup (SIGTERM, sig_handler);
	 DBG("2\n");
   /* Call it once to initialize the timer. */
   alarm_handler (0);
	 DBG("3\n");


   do
   {
      setup_level (&screen, &snake, 1);

      do
      {
         keypress = (char)getchar ();

         /* Move the snake one position. */
         move (&snake, keys, keypress);

         /* keeps cursor flashing in one place instead of following snake */
         gotoxy (1, 1);

         if (collision (&snake, &screen))
         {
            keypress = keys[QUIT];
            break;
         }
         else if (collide_object (&snake, &screen, GOLD))
         {
            /* If no gold left after consuming this one... */
            if (!eat_gold (&snake, &screen))
            {
               /* ... then go to next level. */
               setup_level (&screen, &snake, 0);
            }

            show_score (&screen);
         }
      }
      while (keypress != keys[QUIT]);

      show_score (&screen);

      gotoxy (32, 6);
      textcolor (LIGHTRED);
      printf ("-G A M E  O V E R-");

      gotoxy (32, 9);
      textcolor (YELLOW);
      printf ("Another Game (y/n)? ");

      do
      {
         keypress = getchar ();
      }
      while ((keypress != 'y') && (keypress != 'n'));
   }
   while (keypress == 'y');

   clrscr ();

   return WEXITSTATUS(system ("stty sane"));
}


/**
 * Local Variables:
 *  version-control: t
 *  c-file-style: "ellemtel"
 * End:
 */
