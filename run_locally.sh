#!/bin/sh
BINARY_HOME=./bin
INPUT_HOME=./input
INPUT=${INPUT_HOME}/AB_NYC_2019.csv

#cat ${INPUT} | ${BINARY_HOME}/mapper |  | sort -k1 | ${BINARY_HOME}/reducer > output
cat ${INPUT} | ${BINARY_HOME}/mapper > map_a_out
cat map_a_out | sort -k1 > sort_a_out
cat sort_a_out | ${BINARY_HOME}/reducer > output_a
(cat output_a && cat ${INPUT}) | ${BINARY_HOME}/mapper_d > map_d_out
cat map_d_out | sort -k1 > sort_d_out
cat sort_d_out | ${BINARY_HOME}/reducer_d > output