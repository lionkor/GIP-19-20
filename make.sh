#!/bin/bash

clear
cmake -DCMAKE_BUILD_TYPE=Debug .
make $1 -j 9 

