#!/bin/bash

make
echo 100 | ./1d > ../mat_data/1d_100.dat
echo 200 | ./1d > ../mat_data/1d_200.dat
echo 300 | ./1d > ../mat_data/1d_300.dat
echo 400 | ./1d > ../mat_data/1d_400.dat
echo 500 | ./1d > ../mat_data/1d_500.dat
echo 800 | ./1d > ../mat_data/1d_800.dat
echo 1000 | ./1d > ../mat_data/1d_1000.dat
echo 2000 | ./1d > ../mat_data/1d_2000.dat
echo 3000 | ./1d > ../mat_data/1d_3000.dat
echo 4000 | ./1d > ../mat_data/1d_4000.dat
echo 5000 | ./1d > ../mat_data/1d_5000.dat
echo 8000 | ./1d > ../mat_data/1d_8000.dat
echo 10000 | ./1d > ../mat_data/1d_10000.dat
echo "making 1d"

echo 100 | ./bt > ../mat_data/bt_100.dat
echo 200 | ./bt > ../mat_data/bt_200.dat
echo 300 | ./bt > ../mat_data/bt_300.dat
echo 400 | ./bt > ../mat_data/bt_400.dat
echo 500 | ./bt > ../mat_data/bt_500.dat
echo 800 | ./bt > ../mat_data/bt_800.dat
echo 1000 | ./bt > ../mat_data/bt_1000.dat
echo 2000 | ./bt > ../mat_data/bt_2000.dat
echo 3000 | ./bt > ../mat_data/bt_3000.dat
echo 4000 | ./bt > ../mat_data/bt_4000.dat
echo 5000 | ./bt > ../mat_data/bt_5000.dat
echo 8000 | ./bt > ../mat_data/bt_8000.dat
echo 10000 | ./bt > ../mat_data/bt_10000.dat
echo "making bt"

echo 100 | ./bt_dfs > ../mat_data/bt_dfs_100.dat
echo 200 | ./bt_dfs > ../mat_data/bt_dfs_200.dat
echo 300 | ./bt_dfs > ../mat_data/bt_dfs_300.dat
echo 400 | ./bt_dfs > ../mat_data/bt_dfs_400.dat
echo 500 | ./bt_dfs > ../mat_data/bt_dfs_500.dat
echo 800 | ./bt_dfs > ../mat_data/bt_dfs_800.dat
echo 1000 | ./bt_dfs > ../mat_data/bt_dfs_1000.dat
echo 2000 | ./bt_dfs > ../mat_data/bt_dfs_2000.dat
echo 3000 | ./bt_dfs > ../mat_data/bt_dfs_3000.dat
echo 4000 | ./bt_dfs > ../mat_data/bt_dfs_4000.dat
echo 5000 | ./bt_dfs > ../mat_data/bt_dfs_5000.dat
echo 8000 | ./bt_dfs > ../mat_data/bt_dfs_8000.dat
echo 10000 | ./bt_dfs > ../mat_data/bt_dfs_10000.dat
echo "making bt_dfs"

echo 100 | ./star > ../mat_data/star_100.dat
echo 200 | ./star > ../mat_data/star_200.dat
echo 300 | ./star > ../mat_data/star_300.dat
echo 400 | ./star > ../mat_data/star_400.dat
echo 500 | ./star > ../mat_data/star_500.dat
echo 800 | ./star > ../mat_data/star_800.dat
echo 1000 | ./star > ../mat_data/star_1000.dat
echo 2000 | ./star > ../mat_data/star_2000.dat
echo 3000 | ./star > ../mat_data/star_3000.dat
echo 4000 | ./star > ../mat_data/star_4000.dat
echo 5000 | ./star > ../mat_data/star_5000.dat
echo 8000 | ./star > ../mat_data/star_8000.dat
echo 10000 | ./star > ../mat_data/star_10000.dat
echo "making star"

echo 100 | ./center1d   2 > ../mat_data/center1d2_100.dat
echo 200 | ./center1d   2 > ../mat_data/center1d2_200.dat
echo 300 | ./center1d   2 > ../mat_data/center1d2_300.dat
echo 400 | ./center1d   2 > ../mat_data/center1d2_400.dat
echo 500 | ./center1d   2 > ../mat_data/center1d2_500.dat
echo 800 | ./center1d   2 > ../mat_data/center1d2_800.dat
echo 1000 | ./center1d  2 > ../mat_data/center1d2_1000.dat
echo 2000 | ./center1d  2 > ../mat_data/center1d2_2000.dat
echo 3000 | ./center1d  2 > ../mat_data/center1d2_3000.dat
echo 4000 | ./center1d  2 > ../mat_data/center1d2_4000.dat
echo 5000 | ./center1d  2 > ../mat_data/center1d2_5000.dat
echo 8000 | ./center1d  2 > ../mat_data/center1d2_8000.dat
echo 10000 | ./center1d 2 > ../mat_data/center1d2_10000.dat
echo "making center1d"

echo 100 | ./center1d   3 > ../mat_data/center1d3_100.dat
echo 200 | ./center1d   3 > ../mat_data/center1d3_200.dat
echo 300 | ./center1d   3 > ../mat_data/center1d3_300.dat
echo 400 | ./center1d   3 > ../mat_data/center1d3_400.dat
echo 500 | ./center1d   3 > ../mat_data/center1d3_500.dat
echo 800 | ./center1d   3 > ../mat_data/center1d3_800.dat
echo 1000 | ./center1d  3 > ../mat_data/center1d3_1000.dat
echo 2000 | ./center1d  3 > ../mat_data/center1d3_2000.dat
echo 3000 | ./center1d  3 > ../mat_data/center1d3_3000.dat
echo 4000 | ./center1d  3 > ../mat_data/center1d3_4000.dat
echo 5000 | ./center1d  3 > ../mat_data/center1d3_5000.dat
echo 8000 | ./center1d  3 > ../mat_data/center1d3_8000.dat
echo 10000 | ./center1d 3 > ../mat_data/center1d3_10000.dat
echo "making center1d"

echo 100 | ./center1ddfs   2 > ../mat_data/center1d2dfs_100.dat
echo 200 | ./center1ddfs   2 > ../mat_data/center1d2dfs_200.dat
echo 300 | ./center1ddfs   2 > ../mat_data/center1d2dfs_300.dat
echo 400 | ./center1ddfs   2 > ../mat_data/center1d2dfs_400.dat
echo 500 | ./center1ddfs   2 > ../mat_data/center1d2dfs_500.dat
echo 800 | ./center1ddfs   2 > ../mat_data/center1d2dfs_800.dat
echo 1000 | ./center1ddfs  2 > ../mat_data/center1d2dfs_1000.dat
echo 2000 | ./center1ddfs  2 > ../mat_data/center1d2dfs_2000.dat
echo 3000 | ./center1ddfs  2 > ../mat_data/center1d2dfs_3000.dat
echo 4000 | ./center1ddfs  2 > ../mat_data/center1d2dfs_4000.dat
echo 5000 | ./center1ddfs  2 > ../mat_data/center1d2dfs_5000.dat
echo 8000 | ./center1ddfs  2 > ../mat_data/center1d2dfs_8000.dat
echo 10000 | ./center1ddfs 2 > ../mat_data/center1d2dfs_10000.dat
echo "making center1ddfs"

echo 100 | ./center1ddfs   3 > ../mat_data/center1d3dfs_100.dat
echo 200 | ./center1ddfs   3 > ../mat_data/center1d3dfs_200.dat
echo 300 | ./center1ddfs   3 > ../mat_data/center1d3dfs_300.dat
echo 400 | ./center1ddfs   3 > ../mat_data/center1d3dfs_400.dat
echo 500 | ./center1ddfs   3 > ../mat_data/center1d3dfs_500.dat
echo 800 | ./center1ddfs   3 > ../mat_data/center1d3dfs_800.dat
echo 1000 | ./center1ddfs  3 > ../mat_data/center1d3dfs_1000.dat
echo 2000 | ./center1ddfs  3 > ../mat_data/center1d3dfs_2000.dat
echo 3000 | ./center1ddfs  3 > ../mat_data/center1d3dfs_3000.dat
echo 4000 | ./center1ddfs  3 > ../mat_data/center1d3dfs_4000.dat
echo 5000 | ./center1ddfs  3 > ../mat_data/center1d3dfs_5000.dat
echo 8000 | ./center1ddfs  3 > ../mat_data/center1d3dfs_8000.dat
echo 10000 | ./center1ddfs 3 > ../mat_data/center1d3dfs_10000.dat
echo "making center1ddfs"
