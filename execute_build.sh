#!/bin/bash

hash=$(git log --pretty=format:'%h' -n 1)
clean=""
if [ "$#" -ne 1 ]; then
	clean=" clean"
	make clean
fi

start=`date +%s`
make mode=DEBUG
end=`date +%s`
current_time=date
runtime=$((end-start))
current=$(date)
echo "$hash,$clean Debug build commenced on $current: time elapsed $runtime seconds" >> log/buildlog/build_time.log
