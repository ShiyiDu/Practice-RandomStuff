#mult () {
#local sum
#let "sum=$1*$2"
#return $sum
#}
#mult 4+3 5+1
#echo $?
#
#Q="heh"
#T="23h"
#P=$Q$T
#echo $P
#!/bin/bash
#
#z=3;
#foo() {
#(z=4)
#}
#echo $z
#
#z=`ls`
#q=$(ls)
#\[ "$z" = "$q" \]; echo $?