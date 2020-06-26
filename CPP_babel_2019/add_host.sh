#!/bin/bash

sudo tunctl
sudo ifconfig tap0 up
sudo ifconfig tap0 127.0.0.2 up
