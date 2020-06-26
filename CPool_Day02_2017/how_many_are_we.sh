#!/bin/sh

if [ -z "$1" ]; then
    cut -d\; -f 1 | wc -l
else
    cut -d\; -f 3 | grep -i $1 | wc -l
fi
