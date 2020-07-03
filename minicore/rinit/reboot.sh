#!/bin/sh
sudo reboot
ps axl | sed -nE '/etc.rinit.2/{/sed/q;p;s/[[:digit:]]*\s*[[:digit:]]*\s*([[:digit:]]*).*/sudo kill -9 \1/e}'
