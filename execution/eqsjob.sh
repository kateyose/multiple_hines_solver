qsub -o output_eqs_1d.txt -v matinput='1d_4000.dat' eqs.sh
qsub -o output_eqs_bt.txt -v matinput='bt_4000.dat' eqs.sh 
qsub -o output_eqs_bt_dfs.txt -v matinput='bt_dfs_4000.dat' eqs.sh 
qsub -o output_eqs_0012.txt -v matinput='0012.dat' eqs.sh 

qsub -o output_eqs_star.txt -v matinput='star_4000.dat' eqs.sh
qsub -o output_eqs_center1d2.txt -v matinput='center1d2_4000.dat' eqs.sh 
qsub -o output_eqs_center1d3.txt -v matinput='center1d3_4000.dat' eqs.sh 
qsub -o output_eqs_center1d2dfs.txt -v matinput='center1d2dfs_4000.dat' eqs.sh 
qsub -o output_eqs_center1d3dfs.txt -v matinput='center1d3dfs_4000.dat' eqs.sh 
