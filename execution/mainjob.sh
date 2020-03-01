qsub -o output_main_1d.txt -v matinput='1d_4000.dat' main.sh
qsub -o output_main_bt.txt -v matinput='bt_4000.dat' main.sh 
qsub -o output_main_bt_dfs.txt -v matinput='bt_dfs_4000.dat' main.sh 
qsub -o output_main_center1d2.txt -v matinput='center1d2_4000.dat' main.sh 
qsub -o output_main_star.txt -v matinput='star_4000.dat' main.sh 
qsub -o output_main_0012.txt -v matinput='0012.dat' main.sh 
