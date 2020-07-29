### coretools



"coretools" is aiming at providing a secure core of basic linux (system V, unix, posix) tools,
linked statically with minilib.

I believe, some basic things can be .. in an Unix system. (I'm going to use the term Unix system - 
albite neither coretools nor minilib are limited to Unix/Linux)

- Readability, and size of basic libraries:
  especially the basic core has absolutely no need to handle this or that case of, for example, unicode
	It should provide just the basic functions. And doesn't need to provide locality functions,
	traslations, andsoon. In consequence, as seen with minilib, the tools can be radically shrinked.
	In consequence as well - I'm not interested in "reading" through the source of the gnulibc.
	It's more theoretical, albite the sources are there; I guess for years noone has read through them, only parts.
	They are just too big. And, if someone would would try to hide some malicious code within, 
	mos possibly it would at least take some time, until recognized.
	It's another thing with minilib - It is not theoretical, reading the sources.

- The core shouldn't be writable - In the case of updating, it can be remounted writable
  Having the basic core tools writable just opens security flaw. Nothing else.
	Besides, it's possible to do some optimizations with a readonly system.

- It should be as small as possible, and provide all necessary tools for basic system administration.


The nice thing about that is, this sums up as a nice, doable and useful project.
There are other projects, doing things with a contending(?) focus.
But they aren't intended as a whole core system, or they aren't focusing at a real basic functionality.
(E.g. toybox isn't intended as system, tinycore can do much more)

Anyways, here are some of the ideas, I'd like to have with coretools:

- init (Obviously)
- readonly
- user administration and databases
- mounting and running systems, also in parallel
- secured space (for e.g., passwords, or notes )
- Data replication and backup utilities


Just now I'm not sure about network functionality.
Setting basic things up like firewalling or the interfaces is a job for the core.
However, doing other tings like eg fileserver or http server, is a job for the system.
And, changing the firewall accordingly to e.g. serve files - is crossing borders.


(2020/05)
Having done some further research - a few things show up.
Network, secure space, different environments can be separated quite nicely
via namespaces.

Init could be realized with a shrinked version of sh.
I'm not sure yet.
But somehow it's far nicer, having always the posibility of looking into the source.
And a shrinked version of busybox sh shows up with around 130kB,
linked statically with musl.

It is some overhead. But. Ok.
The basic system can be realized as squashfs, even compiled into the kernel.
Having a system booted and running can be done within fractions of a second this way,
kernel initialization taking longest.
Therefore, having init written in C could be a gain.
I also thought about a combination of a shell language and C.
Translating basic shell syntax into C isn't that hard,
all rules can be applied automatically by the preprocessor.

It's just the question of having the basic tools for file access, 
execution, forking, andsoon available within C.
'runit' is quite nice in being very simple and plain.

-----
An application level firewall can be realized nicely with iptables and
gid/uid filters.
Best experience I had with a dedicated firewall namespace, running only proxies
for the communication.

-----
The passwords for the logins - I believe it is best,
for a normal desktop system, entering a long and secure password at startup.
The other passwords needed can be layed into the running systems via a aufs/overlayfs mount of /etc,
containg passwd /shadow files, which could also be quite short, or non existent.
As long, as I'm sitting in front of my desktop,
I can assume 
1. noone should be able to login via network,
2. The only password I (probably) like to enter would be the root password,
    to be more exact, a short version of it.

As soon, I'm leaving, letting my desktop running,
I'd like to lock the system in most cases.
Again, without the possibility to login until unlocked.

Unmounting the /etc overlays would be enough to realize that,
could be done with a quite simple daemon.

It's however the question on how to update passwords.

-----

As soon there are network daemons running,
it might be better going with something like kerberos.

Albite - root doesn't need to have a login account at all.

Just at this moment - the core doesn't need network accessibility at all.
Named pipes, access rights set accordingly, are enough for a secure login shell/
communication with the firewall shell / shell for mounting etc, changing init levels, and so on.

-----

Seems to me, I need to readout the temperatures at the root namespace.
I do not get plausible readings in a child namespace.
Albite /proc remounted.













