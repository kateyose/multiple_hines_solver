#qsub -o output_openmp_1d.txt -v matinput='1d_4000.dat' openmp.sh
#qsub -o output_openmp_bt.txt -v matinput='bt_4000.dat' openmp.sh 
#qsub -o output_openmp_bt_dfs.txt -v matinput='bt_dfs_4000.dat' openmp.sh 
#qsub -o output_openmp_0012.txt -v matinput='0012.dat' openmp.sh 

qsub -o output_openmp_star.txt -v matinput='star_4000.dat' openmp.sh
qsub -o output_openmp_center1d2.txt -v matinput='center1d2_4000.dat' openmp.sh 
qsub -o output_openmp_center1d3.txt -v matinput='center1d3_4000.dat' openmp.sh 
qsub -o output_openmp_center1d2dfs.txt -v matinput='center1d2dfs_4000.dat' openmp.sh 
qsub -o output_openmp_center1d3dfs.txt -v matinput='center1d3dfs_4000.dat' openmp.sh 
