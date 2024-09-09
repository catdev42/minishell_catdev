#!/usr/bin/bash

while [ 1 ]; do
    cd ~/Work
    DATE=$(date +"%Y-%m-%d-%H-%M")
    tar -cf $DATE.tar CHECK 
    mv $DATE.tar /home/myakoven/backup
    echo "backed up"
    sleep 180
done