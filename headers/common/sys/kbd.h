#ifndef sys_kdb_h
#define sys_kbd_h

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
