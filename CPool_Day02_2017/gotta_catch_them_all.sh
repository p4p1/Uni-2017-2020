#!/bin/sh

if [ -z "$1" ]; then
    exit 84
fi
grep " $1" | wc -l
