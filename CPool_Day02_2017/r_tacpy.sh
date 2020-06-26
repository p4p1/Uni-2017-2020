#!/bin/sh

if [ -z "$MY_LINE1" ] || [ -z "$MY_LINE2" ]; then
    (>&2 echo "ERROR.. \$MY_LINE environement variables are not defines")
    exit 84
fi

OUTPUT=$(sed '1d;n; d' | cut -d: -f 1 | rev | sort -r |\
    sed -n -e "${MY_LINE1},${MY_LINE2}p" | sed -e :a -e '$!N; s/\n/, /; ta')

echo "${OUTPUT}."
