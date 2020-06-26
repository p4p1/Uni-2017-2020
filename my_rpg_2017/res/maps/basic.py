#!/usr/bin/python
# -*- coding: utf-8 -*-
# Made by Leo smith
# basic.py
# Description:

import os, sys
import struct

'''
Tile format:
    x, y, type

Types:
    1 - grass
    2 - dirt
    3 - maison
'''

'''
Header format:
    int magic;
    char name[20];      // 20 = name_size;
    unsigned int size;
'''


FILE_NAME="basic.map"
HEADER_MAGIC_NO=4386298
map_data=""
#   loop to go 47 by 47b to have tile
#   place a city somewhere in the center
#   place player
tiles_position=[100, 100, 12]

for x in xrange(0, 500):
    for y in xrange(0, 500):
        tiles_position.append(x * 47)
        tiles_position.append(y * 47)
        if y % 2 and x % 2:
            tiles_position.append(6)
        else:
            tiles_position.append(5)


WIDTH=500
HEIGHT=500

fp = open(FILE_NAME, 'wb')
# Set the header
map_data += struct.pack('<i', 4386298)
map_data += FILE_NAME[:FILE_NAME.find('.')]
for i in xrange(0, (20 - len(FILE_NAME[:FILE_NAME.find('.')]))):
    map_data += struct.pack('c', '\x00')
map_data += struct.pack('<I', len(tiles_position))
map_data += struct.pack('<I', WIDTH)
map_data += struct.pack('<I', HEIGHT)
for i in tiles_position:
    map_data += struct.pack('<i', i)
fp.write(map_data)
fp.close()

