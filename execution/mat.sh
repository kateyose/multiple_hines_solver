#!/bin/bash
#PBS -q u-debug
#PBS -Wgroup_list=gi16
#PBS -l select=1
#PBS -l walltime=00:30:00
#PBS -e error

cd $PBS_O_WORKDIR
. /etc/profile.d/modules.sh


export OMP_PLACES=threads
export OMP_NUM_THREADS=36
export OMP_PROC_BIND=spread

aver=11
eqs="4096"
sizeval="100 200 400 1000 2000 4000 10000"


objarray="a34d2n a34d54n a34d64n a44d64n"
execarray=""
dir="../"

for obj in $objarray
do
    temp="${dir}${obj}"
    execarray="${execarray}$temp "
done

printf "input "
echo "${objarray}"

for size in $sizeval
do
    printf "${size} "
    matname="../mat_data/${mattype}_${size}.dat"
    for exe in $execarray
    do
        $exe $matname $eqs $aver
        printf " "
    done
    echo
done

rm core.*
