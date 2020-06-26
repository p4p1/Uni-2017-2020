#!/usr/bin/python3
# -*- coding: utf-8 -*-
# Made by tristan
# xor.py
# Description:

import sys
import codecs

if len(sys.argv) != 2:
    print("not enought arguments!")
    sys.exit(84)
path = sys.argv[1]
count = 0
with open(path, 'r') as fp:
    while 1:
        data = fp.read()
        if not data:
            break
        count += data.count('\n')
        data = data.strip('\n')
    if count > 2 :
        print("more than 2 line in buffer")
        sys.exit(84)
    fp.close()
with open(path, 'r') as fp:
    line = fp.readlines()
    if len(line[0]) != len(line[1]):
        print("buffers doesn't have the same size")
        sys.exit(84)
    hex_str = line[0]
    hex_int = int(hex_str, 16)
    hex_str1 = line[1]
    hex_int1 = int(hex_str1, 16)
    print(hex(hex_int ^ hex_int1).upper()[2:])
