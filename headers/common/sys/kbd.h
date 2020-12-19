#ifndef sys_kdb_h
#define sys_kbd_h

#define PIO_FONTRESET   0x4B6D	/* reset to default font */

#define GIO_CMAP	0x4B70	/* gets colour palette on VGA+ */
#define PIO_CMAP	0x4B71	/* sets colour palette on VGA+ */

#define KIOCSOUND	0x4B2F	/* start sound generation (0 for off) */
#define KDMKTONE	0x4B30	/* generate tone */

#define KDGETLED	0x4B31	/* return current led state */
#define KDSETLED	0x4B32	/* set led state [lights, not flags] */
#define LED_SCR		0x01	/* scroll lock led */
#define LED_CAP		0x04	/* caps lock led */
#define LED_NUM		0x02	/* num lock led */

#define KDGKBTYPE	0x4B33	/* get keyboard type */
#define KB_84		0x01
#define KB_101		0x02 	/* this is what we always answer */
#define KB_OTHER	0x03

#define KDADDIO		0x4B34	/* add i/o port as valid */
#define KDDELIO		0x4B35	/* del i/o port as valid */
#define KDENABIO	0x4B36	/* enable i/o to video board */
#define KDDISABIO	0x4B37	/* disable i/o to video board */

#define KDSETMODE	0x4B3A	/* set text/graphics mode */
#define KD_TEXT		0x00
#define KD_GRAPHICS	0x01
#define KD_TEXT0	0x02	/* obsolete */
#define KD_TEXT1	0x03	/* obsolete */
#define KDGETMODE	0x4B3B	/* get current mode */

#define KDMAPDISP	0x4B3C	/* map display into address space */
#define KDUNMAPDISP	0x4B3D	/* unmap display from address space */



#define UNI_DIRECT_BASE 0xF000	/* start of Direct Font Region */
#define UNI_DIRECT_MASK 0x01FF	/* Direct Font Region bitmask */

#define K_RAW		0x00
#define K_XLATE		0x01
#define K_MEDIUMRAW	0x02
#define K_UNICODE	0x03
#define KDGKBMODE	0x4B44	/* gets current keyboard mode */
#define KDSKBMODE	0x4B45	/* sets current keyboard mode */

#define K_METABIT	0x03
#define K_ESCPREFIX	0x04
#define KDGKBMETA	0x4B62	/* gets meta key handling mode */
#define KDSKBMETA	0x4B63	/* sets meta key handling mode */

#define K_SCROLLLOCK	0x01
#define K_CAPSLOCK	0x02
#define K_NUMLOCK	0x04
#define KDGKBLED	0x4B64	/* get led flags (not lights) */
#define KDSKBLED	0x4B65	/* set led flags (not lights) */






#endif
