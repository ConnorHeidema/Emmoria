#!/bin/bash
hash=$(git log --pretty=format:'%h' -n 1)
make clean
start=`date +%s`
make mode=DEBUG
end=`date +%s`
current_time=date
runtime=$((end-start))
current=$(date)
echo "$hash, Debug build commenced on $current: time elapsed $runtime seconds" >> log/buildlog/build_time.log
