#!/bin/sh

find . \( ! -regex '.*/\..*' \) -type f -name "*" | wc -l
