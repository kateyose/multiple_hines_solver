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
eqsarray="128 256 512 1024 2048 4096 8192 16384"


objarray="a34d2n a34d54n a34d64n a44d64n"
execarray=""
matname="../mat_data/${matinput}"

printf "input "
echo "${objarray}"

dir="../"
for obj in $objarray
do
    temp="${dir}${obj}"
    execarray="${execarray}$temp "
done

for eqs in $eqsarray
do
    printf "${eqs} "
    for exe in $execarray
    do
        $exe $matname $eqs $aver
        printf " "
    done
    echo
done

rm core.*
