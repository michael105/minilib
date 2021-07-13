boot
====


In this directory the bootup onetimetasks are stored.


They are executed sequentially, 
and have to start with S.

Files, starting with another letter, 
are ignored.

In order to start scripts parallel, 
just append the '&' symbol to commands started. 


They are callen by runit's '1' process,
which executes the scripts in this directory,
and waits for the last script in this directory (named S99done.sh) 
to write to the named pipe 'wait.fifo' a single char.

(so process 1 doesn't need to poll any state.
TODO. add a timeout handler)

When there are jobs, which need to be processed
before the next runlevel is started,
and have been started in paralell,
remove S99done.sh (or rename it, to e.g. disabled-S99done.sh)
and write a char to the pipe.

('echo 1 > wait.fifo') is enough.









