#!/bin/bash
#PBS -q u-debug
#PBS -Wgroup_list=gi16
#PBS -l select=1
#PBS -l walltime=00:30:00
#PBS -o outputmat1d
#PBS -e error

#lscpu
#numactl -H
#cat /proc/cpuinfo 

cd $PBS_O_WORKDIR
. /etc/profile.d/modules.sh

# cat  /sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size 


aver=21
eqsarray="4096"
#mattypeval="1d bt bt_dfs"
mattypeval="1d"
sizeval="100 200 400 1000 2000 4000 10000"
threadval="36"

dir="../mat_data/"
matarray=""
for size in $sizeval
do
    for mattype in $mattypeval
    do
        temp="${dir}${mattype}_${size}.dat"
        matarray="${matarray}$temp "
    done
done

#swc="../mat_data/0012.dat"
#matarray="${matarray} $swc"

objarray="a2d2 a2d5 a2d6 a7d6"
execarray=""
dir="../"

printf "output "
echo "${objarray}"

for obj in $objarray
do
    temp="${dir}${obj}"
    execarray="${execarray}$temp "
done

for eqs in $eqsarray
do
    printf "${eqs} "
    for matname in $matarray
    do
        for c in $threadval
        do 
        export OMP_PLACES=threads
        export OMP_NUM_THREADS=$c
        export OMP_PROC_BIND=spread
            for exe in $execarray
            do
                $exe $matname $eqs $aver
                printf " "
            done
            echo
        done
    done
done

rm core.*
