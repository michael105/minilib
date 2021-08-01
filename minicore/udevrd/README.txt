
 udevrd
========


Work in progress - it's a backup copy. (2021/02)
Atm about to clean the structure.
Harder then writing this thing..

--------


A slim resource friendly udevd daemon. 

Generically implemented, the daemon could be used to watch all sorts of directories
recursively and change owner, group, access rights, create links,
or execute actions on file creation or deletion.

Less than 12kB linked statically with minilib.
Uses the inotify interface.



Supports: 

	changing device access rights, group and owner on startup and device creation

	execution of commands on device creation and removal, optional with a different uid/gid

	optional logging to the kernel printbuf, logfile or stderr

	colorized output

	utilizes inotify and vfork

	pattern matching for the device rules



About:
 
  The udevrd daemon supervises the /dev directory.
	Access rights, owner and group of the devices are set according to patterns,
	given in a config file.
	In addition, symbolic links can be created,
	and commands can be executed on device creation and removal.
	(e.g. mount a usbstick when inserted)

	Since this process in the normal usecase runs for the whole uptime,
	a slim udevrd has it's advantages. 
	(I'm wondering whether I'll be able to fit a whole unix system without kernel into 
	a x86 cpu's L1 cache..)

	It would be possible to compile the daemon with minilib to not use any
	dynamic allocations. (Albite the dynamic memory usage might stay in the normal
	usecase below one pagesize of 4kB)



Usage:
	
	udevrd [-c config] [-e] [-B]
		
		The udev daemon

		-c 'config': use an alternative config file (default: /etc/udevrd.conf.bin)
		-e : Use an into udevrd itself embedded config file
		-d : debug output to stdout
		-B : daemonize and go into background



	udevrd-update.sh [inputfile] [outputfile]
	  
		Update the binary config file [outputfile] (default: /etc/udevrd.conf.bin)
		from the settings found in [inputfile] (default /etc/udevrd.conf)
		and trigger udevrd to reload its config.
		
		uid's and gid's are translated to its numerical presentation, in order
		to save a few kilobytes for udevrd and to prevent the need to have a
		passwd and group file accessible to udevrd.

		Therefore the configuration file has to be compiled for every system
		with different users and groups again.



	udevrd-appendconfig.sh [inputfile] [udevrd-path]

		(Optional)

		Embedd the binary configfile (default /etc/udevrd.conf.bin)
		in the udevrd daemon (default /sbin/udevrd)
		Either the argument -e to udevrd triggers loading the embedded
		configuration, or udevrd tries to resort onto the embedd configuration
		when he cannot load the supplied (-c) config file, 
		or the file /etc/udevrd.conf.bin doesn't exist.



Configuration:
		
		The configuration is done with the configuration file udevrd.conf.
		This is a simple shell script; the supplied example is documented.

		When the binary configuration is compiled with udevrd-update.sh,
		the config file is sourced with sh.
		It is possible to source from this script other configuration files,
		test for different systems, and so on.

		The devices are matched with the "match" function of minilib.
		Essentially, it is a simple expression engine, which matches straight
		from left to right. 
		Wildcards: 
			* match any count of chars 
			+ match 1 or more chars 
			? match one char
			\d digit 
			\D no digit 

		Please have a look into the reference of minilib for further 
		documentation on 'match'.

		Signal udevrd with SIGUSR1 to reload the configuration file,
		or with SIGUSR2 to load the configuration embedded into udevrd itself.
		(`killall -SIGUSR1 udevrd`)



Compilation:

		`make`
		(within the minilib project hierarchy)

		`make install`





-------------------------------------------------------------------------------

Copyright (C) 2021 Michael (misc) Myer.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


Based on minilib,
Copyright (c) 2012-2021, Michael (misc) Myer
(misc.myer@zoho.com, www.github.com/michael105)
Donations welcome: Please contact me.
All rights reserved.
The licensing terms of minilib are in the file LICENSE.minilib.
(Opensource, free to use with attribution)






