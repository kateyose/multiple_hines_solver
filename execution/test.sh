#!/bin/bash

export OMP_NUM_THREADS=4
aver=3
eqs="16"

matname="../mat_data/1d_100.dat"
output_flag=1

#objarray="a1d1 a2d1 a1d2 a1d3 a1d4 a1d5 a1d6 a2d1 a2d2 a2d3 a2d4 a2d5 a2d6 a4d1 a4d2 a4d3 a4d4 a4d5 a4d6 a6d1 a6d2 a6d3 a6d4 a6d5 a6d6 a7d4 a7d6"
objarray="a1d1 a1d2 a1d3 a1d4 a1d54 a1d64 a1d58 a1d68 a1d2n a1d54n a1d64n a1d58n a1d68n a2d1 a2d2 a2d3 a2d4 a2d54 a2d64 a2d58 a2d68 a2d2n a2d54n a2d64n a2d58n a2d68n a34d1 a34d2 a34d3 a34d4 a34d54 a34d64 a34d2n a34d54n a34d64n a38d1 a38d2 a38d3 a38d4 a38d58 a38d68 a38d2n a38d58n a38d68n a44d4 a44d64 a44d64n"

execarray=""
dir="../"

for obj in $objarray
do
    temp="${dir}${obj}"
    execarray="${execarray}$temp "
done

dir="./"
outputarray=""
for obj in $objarray
do
    temp="${dir}output_${obj}.txt"
    outputarray="${outputarray}$temp "
done

for exe in $execarray
do
    printf $exe
    $exe $matname $eqs $aver $output_flag
    echo
done

> test_output
for file in $outputarray
do
    printf $file >> test_output
    diff output_a1d1.txt $file >> test_output
    diff output_a1d1.txt $file
done

rm output_a*
