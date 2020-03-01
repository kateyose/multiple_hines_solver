#qsub -o output_mat_1d.txt -v mattype='1d' mat.sh
#qsub -o output_mat_bt.txt -v mattype='bt' mat.sh
#qsub -o output_mat_bt_dfs.txt -v mattype='bt_dfs' mat.sh 
qsub -o output_mat_star.txt -v mattype='star' mat.sh 
qsub -o output_mat_center1d2.txt -v mattype='center1d2' mat.sh 
qsub -o output_mat_center1d3.txt -v mattype='center1d3' mat.sh 
qsub -o output_mat_center1d2dfs.txt -v mattype='center1d2dfs' mat.sh 
qsub -o output_mat_center1d3dfs.txt -v mattype='center1d3dfs' mat.sh 
