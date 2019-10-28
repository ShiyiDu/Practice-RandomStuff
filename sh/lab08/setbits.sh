#!/bin/bash
for i in {0..3}
do
	gpio write $i $(($1 >> $i & 1))
done
#
#gpio write 0 $(($1 & 1))
#gpio write 1 $(($1 << 1 & 1))
#gpio write 2 $(($1 << 2 & 1))
#gpio write 3 $(($1 << 3 & 1))
