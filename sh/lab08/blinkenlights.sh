#!/bin/bash

while((1))
do
	./setbits.sh $(($RANDOM % 16))
	sleep 0.25s
done