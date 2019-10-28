#!/bin/bash

for pin in {0..3}
do
	gpio mode $pin out
done