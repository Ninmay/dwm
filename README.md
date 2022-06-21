dwm - dynamic window manager
============================
dwm is an extremely fast, small, and dynamic window manager for X.


Requirements
------------
In order to build dwm you need the Xlib header files.
Packages: *xorg-server*, *xorg-xinit*.
Iosevka fonts will come in handy. Otherwise change it to your own taste.

Changes and my experience
-------------------------
First basic install, fzf scripts, local bin folder, polishing up the visual
aspect, multiple themes feature. Plan to do: persistent pertags, running
terminal apps more quickly, better hotkeys, full dwm documentation.

Configuration
-------------
It's recommended that you have all installs in *$HOME/Build* folder.
First install st and dmenu from the suckless website. Set your desired font
for st. My config: *iosevka-term.ttc:style=Extended:size=15*, *borderpx = 25*.
Once you're done, clone this repository and compile it the same way you would
compile st and dmenu.
Copy the default xinitrc to your home directory as .xinitrc. It *should*
be in the /etc/X11/xinit/xinitrc. Remove the lines with xterm, xclock and
twm. Then add programs at the end that you would like to run on start up.
My example:
```bash
# wallpaper
~/.fehbg

# dwm
~/Build/dwm/bin/laptop-dwmbar &
sxhkd &
pavucontrol & # My laptop won't play sound without this.
sleep 0.5
killall pavucontrol

# chinese cartoons
fcitx &
```  
It's also best to set via visudo programs you would like to run without sudo.
For example sleep, shutdown, xbacklight (for changing brightness).
```bash
## Uncomment to allow members of group wheel to execute any command
# %wheel ALL=(ALL) ALL

## Same thing without a password
# %wheel ALL=(ALL) NOPASSWD: ALL
nintendo ALL=(ALL) NOPASSWD: /bin/runit-init, /usr/bin/xbacklight, /usr/bin/zzz
```  
To enable scripts (or include any other configs):
```bash
ln -s {repo path here}/scripts/bashrc ~/.bashrc
```
Just remember to back up and remove your own .bashrc. If there are any programs
bash couldn't found, that means you haven't installed them yet. If so, install them.
PS The wallpaper is located in *$REPO/patches/preview* and is named theme.jpg.
Makefile deletes *config.h*, so changes shall go to *config.def.h*.

Themes 
------
**Beatrice**

![write](patch/preview/beatrice-write.jpg)
![compile](patch/preview/beatrice-compile.jpg)
**Maria**

![compile](patch/preview/maria-compile.jpg)
![fun](patch/preview/maria-fun.jpg)
**Alicia**

![general](patch/preview/alicia-general.jpg)
![browse](patch/preview/alicia-browse.jpg)
