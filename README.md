dwm - dynamic window manager
============================
dwm is an extremely fast, small, and dynamic window manager for X.


Requirements
------------
In order to build dwm you need the Xlib header files.
Iosevka fonts will come in handy. Otherwise change it to your own taste.

Base changes
------------
Patches are located in the *patches* directory. Other than that, I haven't
touched config files any deeper than setting up base values. 
This dwm build also has script functionality.

Scripts
-------
If you want to know how to use them just read their respective source code.
All of them are carefully documented. The scripts are added to $PATH, so you
can run them from anywhere you want.

Configuration
-------------
First install st and dmenu from the suckless website. Set your desired font
for st. (mine is *iosevka-term.ttc:style=Extended:size=15*)
Once your done, clone this repository and compile it the same way you would
compile st and dmenu. To enable scripts:
```bash
ln -s {repo path here}/scripts/bashrc ~/.bashrc
```
Just remember to back up and remove your own .bashrc.


Beatrice's Theme
----------------
![clean](./preview/clean.png)
![general](./preview/general.png)
![write](./preview/write.png)
![compile](./preview/compile.png)
![browse](./preview/browse.png)
![fun](./preview/fun.png)
