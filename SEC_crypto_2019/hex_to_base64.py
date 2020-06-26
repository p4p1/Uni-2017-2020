#!/usr/bin/python3
# -*- coding: utf-8 -*-
# Made by papi
# hex_to_base64.py
# Description:

import codecs
import sys

if len(sys.argv) != 2:
    print("not enought arguments!")
    sys.exit(84)
path = sys.argv[1]
try:
    with open(path, 'r') as fp:
        data = fp.read()
        data = data.strip('\n')
        if len(data) % 2:
            print("?")
            sys.exit(0)
        b64 = codecs.encode(codecs.decode(data, 'hex'), 'base64')
        for ch in b64:
            if chr(ch) == '\n':
                continue
            sys.stdout.write(chr(ch))
        sys.stdout.write('\n')
except:
    print ("You don't have the permissions")
    sys.exit(84)
