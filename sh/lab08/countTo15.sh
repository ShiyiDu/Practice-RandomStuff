#!/bin/bash

counter=0
while(( $counter <= 15 ))
do
	echo $counter
	./setbits.sh $counter
	sleep 1s
	((counter++))
done