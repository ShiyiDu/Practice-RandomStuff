#!/bin/bash
pos=-1
forth=1
while(true)
do
	if(($forth == 1));then
		((pos++))
#		echo $pos
		gpio write $pos 1
		if((pos == 3));then
			((forth = 0))
		fi
	elif(($forth == 0));then
		((pos--))
#		echo $pos
		gpio write $pos 1
		if((pos == 0));then
			((forth = 1))
		fi
	fi
	sleep 0.25s
	gpio write $pos 0
done