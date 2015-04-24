#!/bin/bash

# load .Xresources
xrdb -merge .Xresources

# add in fonts
xset +fp /usr/share/fonts/local
#xset +fp /home/minhnh13/.fonts
xset fp rehash

# set wallpaper
# feh --bg-scale /home/minhnh13/Imgs/wallpaper

$HOME/Scripts/dwm_start
