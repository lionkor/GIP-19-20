#!/bin/bash

rm -v *.01
rm -v *.02
rm -v *.03
rm -v *.04
rm -v *.05
rm -v *.06

cmake -DCMAKE_BUILD_TYPE=Debug .
make -j 9

