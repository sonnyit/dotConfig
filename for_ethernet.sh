#!/bin/bash

sudo ip link set dev enp2s0 up
sudo dhcpcd enp2s0
