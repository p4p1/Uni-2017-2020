#!/bin/bash
# Script to load any lib that are in lib_c repo
# Usage:
# ./load_lib.sh $LIB_NAME
# see dir for existing libs

if [ -z $1 ]; then
	echo "Please provided arg..."
	echo
	echo "Usage:"
	echo "$0 \$LIB_NAME"
fi

LIB_NAME=$1
