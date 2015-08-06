#!/bin/bash

sudo modprobe -r vboxdrv vboxnetadp vboxnetflt
sudo modprobe vboxdrv vboxnetadp vboxnetflt
