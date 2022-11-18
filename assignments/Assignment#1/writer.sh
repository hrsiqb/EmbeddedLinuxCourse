#!/bin/sh
filePath=$1
str=$2
numArg=$#

if [ $numArg -ne 2 ]
then
    echo "ERROR: Invalid Number of Arguments."
    echo "Total number of arguments should be 2."
    echo "The order of the arguments should be:"
    echo "  1)File Directory Path"
    echo "  2)String to be written in the specified directory path"
else
    echo "${str}" > $filePath

fi