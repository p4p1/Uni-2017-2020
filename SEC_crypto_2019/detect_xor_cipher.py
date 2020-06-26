#!/usr/bin/python3
# -*- coding: utf-8 -*-
# Made by papi
# detect_xor_cipher.py
# Description:

import sys
import codecs

class english_detector():
    def __init__(self):
        self.frequencies = { 'a': .08167, 'b': .01492, 'c': .02782, 'd': .04253,
            'e': .12702, 'f': .02228, 'g': .02015, 'h': .06094,
            'i': .06094, 'j': .00153, 'k': .00772, 'l': .04025,
            'm': .02406, 'n': .06749, 'o': .07507, 'p': .01929,
            'q': .00095, 'r': .05987, 's': .06327, 't': .09056,
            'u': .02758, 'v': .00978, 'w': .02360, 'x': .00150,
            'y': .01974, 'z': .00074 }
        self.best_value = 0
        self.best_char = 0
        self.string_of_best_val = ""
        self.best_line = 0

    def detect(self, string, char, line):
        i = 0
        for ch in string.lower():
            try:
                i += self.frequencies[ch]
            except:
                i += 0
        if i > self.best_value:
            self.best_value = i
            self.best_char = char
            self.string_of_best_val = string
            self.best_line = line
        return i

    def best_string(self):
        return self.string_of_best_val

    def best_score(self):
        return self.best_value

    def best_character(self):
        return self.best_char

    def best_line_no(self):
        return self.best_line

def single_byte_xor(data, line, detector):
    try:
        string = codecs.decode(data.strip('\n'), 'hex')
    except:
        print("Not a hexadecimal string")
        sys.exit(84)
    for i in range(256):
        output = ''
        print ("HERE")
        for char in string:
            output += chr(ord(char) ^ i)
        detector.detect(output, i, line)
    return 0


if __name__ == "__main__":
    if len(sys.argv) == 2:
        with open(sys.argv[1], "r") as fp:
            data_file = fp.read()
            table = data_file.split('\n')
            detector = english_detector()
            for i in range(len(table)):
                single_byte_xor(table[i], i, detector)
            print("%d %x" % detector.best_line(), detector.best_character())
    else:
        print ("ERROR: not enought arguments")
