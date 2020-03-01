#!/bin/bash
#PBS -q u-short
#PBS -Wgroup_list=gi16
#PBS -l select=1
#PBS -l walltime=02:00:00
#PBS -e error

cd $PBS_O_WORKDIR
. /etc/profile.d/modules.sh

# cat  /sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size 

export OMP_PLACES=threads
export OMP_PROC_BIND=spread

aver=11
eqs="4096"
sizeval="4000"
threadval="1 2 4 8 16 24 32 36"
objarray="a1d1 a1d2 a1d2n a34d64 a34d64n"

matarray=""
matname="../mat_data/${matinput}"

printf "input "
echo "${objarray}"


execarray=""
dir="../"

for obj in $objarray
do
    temp="${dir}${obj}"
    execarray="${execarray}$temp "
done

for c in $threadval
do 
printf "${c} "
export OMP_NUM_THREADS=$c
    for exe in $execarray
    do
        $exe $matname $eqs $aver
        printf " "
    done
    echo
done

rm core.*
