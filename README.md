# Self-made icons
![note](icon/note.png) ![play](icon/play.png) ![screenshot](icon/screenshot.png) ![stop](icon/stop.png) ![toggle](icon/toggle.png) ![usbgreen](icon/usbgreen.png) ![usb](icon/usb.png) ![usbred](icon/usbred.png) ![voldown](icon/voldown.png) ![volmute](icon/volmute.png) ![volunmute](icon/volunmute.png) ![volup](icon/volup.png)

# scripts
## Mount/Unmount using dmenu

![mount](scripts/mounting-menu/dmenu-mount.png)![unmount](scripts/mounting-menu/dmenu-unmount.png)

![mounted](scripts/mounting-menu/filesystem-mounted.png)![unmounted](scripts/mounting-menu/filesystem-unmounted.png)![notfound](scripts/mounting-menu/filesystem-notfound.png)
## Power
change systemd power state and lock using [slock](https://tools.suckless.org/slock/)

![power](scripts/power/power.png)

# dwm
## statusbar
My dwm statusbar. Font is [unscii](http://pelulamu.net/unscii/).

![statusbar](dwm/dwmbar.png)
![statusbar-status2d](dwm/dwmbar-color.png)

Dependencies: ```pacman pulseaudio pamixer speedtest-cli xorg-xsetroot coreutils```

What it displays:
* Download/upload speed, recheck every 10 minutes
* How much space is used in the root partition, package count
* Pulseaudio volume
* Time and date

## Keybind menu
1) Using dmenu or dunst
Just pipe the text [file](scripts/key) to dmenu or [file](key-dunst) to dunst
If you want dunst to display it correctly, change these in dunstrc: alignment to ``left``, line-height to ``0``

![dmenu-key](scripts/dmenu-key/dmenu-key.png)
![dmenu-key-full](scripts/dmenu-key/dmenu-key-full.png)
![dunst-key](scripts/dmenu-key/dunst-key.png)
![dunst-key-full](scripts/dmenu-key/dunst-key-full.png)

2) Using dmenu but more practical
![keymap](scripts/keymap/map.png)


## prompt
### PS1
![PS1](scripts/prompt/PS1.png)

It display different kaomoji depending on if the command succeeds or fails

![PS1-logic](scripts/prompt/PS1-logic.png)
### PS2
![PS2](scripts/prompt/PS2.png)

# Theme
## Firefox
### userChrome.css
My modification of [dpcdpc11's Nord for Firefox](https://www.deviantart.com/dpcdpc11/art/Nord-for-Firefox-837860916).

* Removed urlbar expansion
* Everything round corners
* Added colors for menus
* Changed tabs' colors

It's not finished yet, I'll work on it when I have time.
![userChrome](firefox/userChrome.png)
### stylus
#### Wikipedia
[udscbt](https://github.com/udscbt-wsx/udscbt-userstyles) inspired stylesheet for wikipedia with nord theme! Still working on this.

![wikipedia](firefox/stylus/wikipedia.png)

## Gimp
nord theme
![gimp](image/gimp.png)
