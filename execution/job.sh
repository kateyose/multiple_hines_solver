#!/bin/bash
#PBS -q u-debug
#PBS -Wgroup_list=gi16
#PBS -l select=1
#PBS -l walltime=00:30:00
#PBS -o output
#PBS -e error

#lscpu
#numactl -H
#cat /proc/cpuinfo 

cd $PBS_O_WORKDIR
. /etc/profile.d/modules.sh

# cat  /sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size 


aver=2
eqsarray="4096"
mattypeval="1d bt"
sizeval="4000"
threadval="1 36"

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

#objarray="a1d1 a1d2 a1d3 a1d4 a1d5 a1d6 a2d1 a2d2 a2d3 a2d4 a2d5 a2d6 a4d1 a4d2 a4d3 a4d4 a4d5 a4d6"
objarray="ia34d64n ga34d64n i3a34d64n g3a34d64n"
execarray=""
dir="../"

for obj in $objarray
do
    temp="${dir}${obj}"
    execarray="${execarray}$temp "
done

for eqs in $eqsarray
do
    for matname in $matarray
    do
        for c in $threadval
        do 
        export OMP_PLACES=threads
        export OMP_NUM_THREADS=$c
        export OMP_PROC_BIND=spread
            for exe in $execarray
            do
                printf "${exe} mat ${matname} eqs ${eqs} aver ${aver} threadval ${c} omplaces thread ompprocbind spread\n"
                $exe $matname $eqs $aver 1
            done
        done
    done
done

#printf "simdnuma8  "
#../simd_numa_block_hines_solver $matname $eqs $aver 8
#printf "numa8      "
#../numa_block_hines_solver $matname $eqs $aver 8
#printf "\n"
rm core.*
