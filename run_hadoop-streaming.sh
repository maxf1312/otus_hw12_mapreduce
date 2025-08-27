#!/usr/bin/env bash
set -x

HADOOP_STREAMING_JAR=/opt/hadoop-2.7.4/share/hadoop/tools/lib/hadoop-streaming-2.7.4.jar
OUT_DIR=$2

hdfs dfs -rm -r $OUT_DIR
 
yarn jar $HADOOP_STREAMING_JAR\
	-D mapreduce.job.name=$3\
	-files /mapper,/reducer\
    -mapper '/mapper'\
    -reducer '/reducer'\
    -numReduceTasks 1\
    -input $1\
    -output $OUT_DIR

hdfs dfs -cat $OUT_DIR/part-00000

echo $?
