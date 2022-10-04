# Game of Life

This is a personal project written in C. I just wanted to use GTK to create GUI for desktop apps.
As I have on old version of MacOsX, I cannot use latest version of GTK and related tools.
I decided to use GTK2 (with Quartz engine to have a look and feel of Apple Aqua Interface).

This app is a C version of the Game Of Life. The only purpose it have is for learning GTK and C programming.

## Installation on Mac OS X 10.9.5

1. Install MacPort 2.7.1
2. Install XCode 6.1.1
3. Install related Command Line Tools : 

```bash
xcode-select --install
```

4. Install GTK2 using MacPort :

```bash
port install xorg-server-legacy
port install gtk2 +quartz
port install gtk-osx-application-gtk2
```

5. Download Aqua theme at [https://www.gnome-look.org/p/1079965](https://www.gnome-look.org/p/1079965)
6. Place downloaded .gz file into **/opt/local/share/themes**
7. Install theme switcher : 

```bash
port install gtk-theme-switch
```

8. Switch theme : 

```bash
/opt/local/bin/switch2
```

By clicking on **preview** you should see the following window : 

[theme preview](images/theme_preview.png)

## Build and run application

```bash
git clone <repository> gameoflife
cd gameoflife/
cmake .
make
./GameOfLife
```
