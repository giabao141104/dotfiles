# Update
Screenshot because I like this [unscii](http://pelulamu.net/unscii/) font (and just bought a 1080p monitor)
![Update 19/08/2020](image/unscii-1080p-update.png)

# system
## Mount/Unmount using dmenu
I made all the icons myself! :)

![mount](image/dmenu_mount.jpg)
![unmount](image/dmenu_unmount.jpg)

![mounted](image/filesystem-mounted.png)
![unmounted](image/filesystem-unmounted.png)
![notfound](image/filesystem-notfound.png)
## Power
change systemd power state and lock using [slock](https://tools.suckless.org/slock/)

![power](image/power.jpg)
# dwm
## statusbar
My dwm statusbar. Font is [sourcecodepro](https://www.archlinux.org/packages/extra/any/adobe-source-code-pro-fonts/), emojis are from [awesome](https://www.archlinux.org/packages/community/any/awesome-terminal-fonts/)

![statusbar](dwm/statusbar.png)

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
![userChrome.css](firefox/2020-07-23_01-46-16_R.png)
### stylus
#### Wikipedia
[udscbt](https://github.com/udscbt-wsx/udscbt-userstyles) inspired stylesheet for wikipedia with nord theme! Still working on this.

![wikipedia-article](firefox/stylus/wikipedia-article.png)

## Gimp
nord theme
![gimp](image/gimp.png)

# Extra
## Keybind menu
### Dunst
Script [here](bin/dunst-key). You'll have to set dunst's alignment to ```left```.

![dunst-key](image/dunst-key.png)
![dunst-key-full](image/dunst-key-full.png)
### dmenu
Just pipe the text [file](bin/key) to dmenu.

![dmenu-key](image/dmenu-key.jpg)
![dmenu-key-full](image/dmenu-key-full.jpg)


## prompt
### PS1
![ps1](extra/prompt/2020-07-23_23-39-04_A.png)

It display different kaomoji depending on if the command succeeds or fails

![logic](extra/prompt/2020-07-23_23-38-43_A.png)
### PS2
![ps2](extra/prompt/2020-07-23_23-38-55_A.png)
## Discord mpd rich presence (mpd-pumpko)
![mpd rich presence](mpd-rich-presence-discord/2020-07-31_04-18-12_A.png)

I modified [SSStormy's mpd-rich-presence-discord](https://github.com/SSStormy/mpd-rich-presence-discord) to change the large image. Here's how you can do it too!
1. Dependencies ```discord-rpc libmpdclient```
2. Make an [application](https://discord.com/developers/applications)
3. Upload the 3 buttons in the ```mpd-rich-presence-discord/assets/discord/png/``` to Art Assets under the Rich Presence tab. Rename them to ```pause-circle_png play-circle_png refresh-cw_png``` respectively
4. Find a good image and upload it to Art Assets, rename to ```mpd_large```
5. Change all the AppId in ```mpd-rich-presence-discord/src/main.cpp``` to the one you just made
6. Run build.sh and the executable file should be in ```mpd-rich-presence-discord/release```
