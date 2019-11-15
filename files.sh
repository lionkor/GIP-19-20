#!/bin/bash
# creates GIP.files file for QtCreator

echo "generating \"GIP.files\"..."

find . -name "*.cpp" -or -name "*.h" | grep -iv "cmake" >GIP.files

echo "done."
