#!/bin/bash

# copy this shell scrip to build directory to generate seed levels 1 - 100
# level 2

for i in {1..100}; do 
	./create $i 2
	sleep 1
done
