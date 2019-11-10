#!/bin/bash

# Author: PES1201700134, Parth Shah
# Date: 10-11-2019

# Runs modinfo on each lsmod from /proc/modules

while read p; do
    modarr=($p)
    echo "name:          " ${modarr[0]}
    echo "size:          " ${modarr[1]}
    echo "instances:     " ${modarr[2]}
    echo "dependancies:  " ${modarr[3]}
    echo "status:        " ${modarr[4]}
    echo "offset:        " ${modarr[5]}

    modinfo ${modarr[0]}
    echo 
done < /proc/modules
