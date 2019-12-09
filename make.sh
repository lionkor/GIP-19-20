#!/bin/bash

clear
cmake -DCMAKE_BUILD_TYPE=Debug .
# run "./make.sh all" to build all, or e.g. "./make.sh 06.01" to only build 06.01
make $1 -j 9 

