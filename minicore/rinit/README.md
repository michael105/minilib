Work in progress, not finished.


A minimal init. 

The small size and using vfork might spare some resources.

readahead has to be implemented by the stages.


(2020/06)
.. finished a first version of init, seems to work fine.

Subject to change.

For now, init starts 
/etc/rinit/1 

and runs and restarts when exiting
/etc/rinit/2

Halt/reboot is /etc/rinit/3

This follows the runit scheme.


on signals SIGINT, Ctrl+Alt+Del (->reboot) and SIGTERM (->shutdown)
/etc/rinit/2 is sent SIGTERM, when not responding SIGKILL,
and after it's termination
/etc/rinit/3 is executed.


For a shutdown do "killall init",
for a reboot "killall -s SIGINT init" (or Ctrl-Alt-Del)

When sent SIGQUIT, the currently running stage is signalled with SIGTERM.
When the currently running stages are either 1 or 2, when the processes exit,
stage 2 is (re)started.

On shutdown, after a timeout of (default, change "WAITTIME" within the source) 
30 seconds past the sent SIGTERM,
the currently running stage is sent a SIGKILL.
When still not responding within 30 seconds, 
it's assumed the process is zombified and stage 3 or
the reboot/halt executed.


The scripts 1,2,3 and the init scripts I'm using, are working, but subject to change.
I'm using a stripped down sh interpreter of busybox.

However, the forks for every executed program on boot seem to have their price.
Albite bootup time is below 1 second. (Notebook Amd Turion 2GHz, built 2005)

I guess I'm going to integrate the minicore tools into the start scripts, 
and rewrite 1 and 2 as C programs. 

The bootscripts aren't tidied, there are some instructions left, 
I fiddled around with syncronization.
Showed up, no sync is needed.
To be more exact, even stage 2 is not really needed.
I leave this at it is for now.
And upload this into the branch devel of minilib,
since it is in development.

