#!/bin/bash

for i in {31..35}; do
    j=$(printf "%03d" $i)
    mkdir $j
    cd $j
    and init "$j.cpp"
    cd ..
done
