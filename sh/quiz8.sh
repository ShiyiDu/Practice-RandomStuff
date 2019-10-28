#!/bin/bash

#z=`ls`
#q=$(ls)
#if [ "$z" = "$q" ] ; then echo $? ; fi

#foo=(a b c)
#echo ${foo[2]}$

#q=5
#echo "$q"

#mult () {
#	local sum
#	let "sum=$1*$2"
#	return $sum
#}
#mult 4+3 5+1
#echo $?

#z=3;
#foo() {
#(z=4)
#}
#echo $z

#cd() {
#	return 1
#}
#cd ~
#ls
#echo $?

#test a -gt b
#echo $?
##why?

#what is wrong with the code?
c=0
for z in *; do
	t=`wc -l <$z`
	let "c=$c+$t"
done
echo $c
#
#for z in *; do
#	echo $z
#done