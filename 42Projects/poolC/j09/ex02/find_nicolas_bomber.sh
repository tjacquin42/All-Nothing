#!/bin/sh
cat $1 | grep -i 'nicolas\tbomber' | cut -f 3 | grep '[0-9]'
