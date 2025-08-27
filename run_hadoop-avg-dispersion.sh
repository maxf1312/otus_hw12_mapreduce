#!/usr/bin/env bash
set -x

HDFS_INPUT_DIR=/user/hw12

hdfs dfs -cp file:///$1  $HDFS_INPUT_DIR/$1 
/run_hadoop-streaming.sh $HDFS_INPUT_DIR/$1 $2 $3 /mapper /reducer 

hdfs dfs -cp $OUT_DIR/part-00000 file:///output_a
(cat /output_a && cat $1) > $1_a

hdfs dfs -cp file:///$1_a  $HDFS_INPUT_DIR/$1_a 
/run_hadoop-streaming.sh $HDFS_INPUT_DIR/$1_a $2 $3 /mapper_d /reducer_d 
