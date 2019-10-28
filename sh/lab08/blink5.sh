#!/bin/bash

for timer in {0..4}
do
	for pin in {0..3}
	do
		gpio write $pin 1
	done
#	timer 1 sec
	sleep 1s
	for pin in {0..3}
	do
		gpio write $pin 0
	done
	sleep 1s
#	time 1 sec
done