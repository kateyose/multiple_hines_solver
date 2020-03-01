#!/bin/bash
#PBS -q u-short
#PBS -Wgroup_list=gi16
#PBS -l select=1
#PBS -l walltime=02:00:00
#PBS -e error


cd $PBS_O_WORKDIR
. /etc/profile.d/modules.sh

export OMP_PLACES=threads
export OMP_NUM_THREADS=36
export OMP_PROC_BIND=spread

aver=11
#eqsarray="4096"
eqs="4096"

objarray="a1d1 a1d2 a1d3 a1d4 a1d54 a1d64 a1d58 a1d68 a1d2n a1d54n a1d64n a1d58n a1d68n a2d1 a2d2 a2d3 a2d4 a2d54 a2d64 a2d58 a2d68 a2d2n a2d54n a2d64n a2d58n a2d68n a34d1 a34d2 a34d3 a34d4 a34d54 a34d64 a34d2n a34d54n a34d64n a38d1 a38d2 a38d3 a38d4 a38d58 a38d68 a38d2n a38d58n a38d68n a44d4 a44d64 a44d64n" 

execarray=""
matname="../mat_data/${matinput}"


dir="../"

for obj in $objarray
do
    printf "${obj} "
    exe="${dir}${obj}"
    $exe $matname $eqs $aver
    echo
done

rm core.*
