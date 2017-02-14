#!/bin/sh
var=$(ifconfig | grep inet\ | cut -d "n" -f2 | cut -d "t" -f2 | cut -d " " -f2)
if test -z "$var"
then
	echo -e "Je suis perdu!\n"
else
	echo $var | tr ' ' '\n'
fi
