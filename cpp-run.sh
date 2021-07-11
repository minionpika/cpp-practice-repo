#!/bin/sh
# run any cpp file like ./cpp-run.sh filename

FILENAME=$1
echo "compiling and running $FILENAME"
echo "-------------------------------"
#g++ -o current $FILENAME
g++ -Wall -g -std=c++17 -o current $FILENAME
chmod +x ./current
./current
