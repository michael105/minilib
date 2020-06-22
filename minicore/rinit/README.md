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



on signals SIGINT, Ctrl+Alt+Del (->reboot) and SIGTERM (->shutdown)
/etc/rinit/2 is sent SIGTERM, when not responding SIGKILL,
and after it's termination
/etc/rinit/3 is executed.

This follows the runit scheme.

Anyways, for a shutdown do "killall init",
for a reboot "killall -s SIGINT init"

The scripts 1,2,3 and the init scripts I'm using, are working, but subject to change.
I'm using a stripped down sh interpreter of busybox.

However, the forks for every executed program on boot seem to have their price.
Albite bootup time is below 1 second.

I guess I'm going to integrate the minicore tools into the start scripts, 
and rewrite 1 and 2 as C programs. 

The bootscripts aren't tidied, there are some instructions left, I tried for syncronization.
Showed up, no sync is needed.
To be more exact, even stage 2 is not really needed.


