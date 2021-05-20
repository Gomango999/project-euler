#!/bin/bash

for i in {26..30}; do
    j=$(printf "%03d" $i)
    mkdir $j
    cd $j
    and init "$j.cpp"
    cd ..
done
