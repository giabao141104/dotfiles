# system
## Mount/Unmount using dmenu
I made all the icons myself! :)

![mount](https://github.com/giabao141104/dotfiles/blob/master/image/dmenu_mount.jpg)
![unmount](https://github.com/giabao141104/dotfiles/blob/master/image/dmenu_unmount.jpg)

![mounted](https://github.com/giabao141104/dotfiles/blob/master/image/filesystem-mounted.png)
![unmounted](https://github.com/giabao141104/dotfiles/blob/master/image/filesystem-unmounted.png)
![notfound](https://github.com/giabao141104/dotfiles/blob/master/image/filesystem-notfound.png)
## Power
change systemd power state and lock using [slock](https://tools.suckless.org/slock/)

![power](https://github.com/giabao141104/dotfiles/blob/master/image/power.jpg)
# dwm
## statusbar
My dwm statusbar. Font is [sourcecodepro](https://www.archlinux.org/packages/extra/any/adobe-source-code-pro-fonts/), emojis are from [awesome](https://www.archlinux.org/packages/community/any/awesome-terminal-fonts/)

![statusbar](https://github.com/giabao141104/dotfiles/blob/master/dwm/statusbar.png)

List of softwares: ```pacman pulseaudio pamixer speedtest-cli xorg-xsetroot coreutils```

What it displays:
* Download/upload speed, recheck every 10 minutes
* How much space is used in the root partition, package count
* Pulseaudio volume
* Time and date

# Theme
## Firefox
### userChrome.css
My modification of [dpcdpc11's Nord for Firefox](https://www.deviantart.com/dpcdpc11/art/Nord-for-Firefox-837860916).

* Removed urlbar expansion
* Everything round corners
* Added colors for menus
* Changed tabs' colors

It's not finished yet, I'll work on it when I have time.

![userChrome.css](https://github.com/giabao141104/dotfiles/blob/master/firefox/2020-07-23_01-46-16_R.png)

## Gimp
nord theme
![gimp](https://github.com/giabao141104/dotfiles/blob/master/image/gimp.png)

# Extra
## Keybind menu
### Dunst
Script [here](https://github.com/giabao141104/dotfiles/blob/master/bin/dunst-key). You'll have to set dunst's alignment to ```left```.

![dunst-key](https://github.com/giabao141104/dotfiles/blob/master/image/dunst-key.png)
![dunst-key-full](https://github.com/giabao141104/dotfiles/blob/master/image/dunst-key-full.png)
### dmenu
Just pipe the text [file](https://github.com/giabao141104/dotfiles/blob/master/bin/key) to dmenu.

![dmenu-key](https://github.com/giabao141104/dotfiles/blob/master/image/dmenu-key.jpg)
![dmenu-key-full](https://github.com/giabao141104/dotfiles/blob/master/image/dmenu-key-full.jpg)


## prompt
### PS1
![ps1](https://github.com/giabao141104/dotfiles/blob/master/extra/prompt/2020-07-23_23-39-04_A.png)

It display different kaomoji depending on if the command succeeds or fails

![logic](https://github.com/giabao141104/dotfiles/blob/master/extra/prompt/2020-07-23_23-38-43_A.png)
### PS2
![ps2](https://github.com/giabao141104/dotfiles/blob/master/extra/prompt/2020-07-23_23-38-55_A.png)
## Discord mpd rich presence (mpd-pumpko)
![mpd rich presence](https://github.com/giabao141104/dotfiles/blob/master/mpd-rich-presence-discord/2020-07-31_04-18-12_A.png)

I modified [SSStormy's mpd-rich-presence-discord](https://github.com/SSStormy/mpd-rich-presence-discord) to change the large image. Here's how you can do it too!
1. Dependencies ```discord-rpc libmpdclient```
2. Make an [application](https://discord.com/developers/applications)
3. Upload the 3 buttons in the ```mpd-rich-presence-discord/assets/discord/png/``` to Art Assets under the Rich Presence tab. Rename them to ```pause-circle_png play-circle_png refresh-cw_png``` respectively
4. Find a good image and upload it to Art Assets, rename it to ```mpd_large```
5. Change all the AppId in ```mpd-rich-presence-discord/src/main.cpp``` to the one you just made
6. Run build.sh and the executable file should be in ```mpd-rich-presence-discord/release```
