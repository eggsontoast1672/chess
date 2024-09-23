# Chess

This is my go at implementing the game of Chess. My plan is to turn it into a
UCI frontend similar to programs like En Croissant or Nibbler. The program is
written in Rust, as the U.S. government intended, I guess.

## Usage

run: sudo apt update; sudo apt install libgl-dev libxcursor-dev libxi-dev libxinerama-dev libxrandr-dev

A good old fashioned `cargo run` from the root of the project will get you up
and running in a jiffy.

As far as dependencies go, the crate will compile Raylib, so you need all of
those dependencies. You need the development files for xcursor, xinput,
xinerama, and xrandr, as well as the OpenGL header files. On Ubuntu, the
command is the following:

```
$ sudo apt install libgl-dev libxcursor-dev libxi-dev libxinerama-dev libxrandr-dev
```

If you're not on Ubuntu, I have faith in you that you'll figure it out.

Here's one thing to note: I'm using Raylib on the frontend for all of the
rendering. The one problem that I have with Raylib is that it can't (easily)
render SVG images, so I wrote a script in the `assets` directory that converts
all of the SVG images to PNG's. You shouldn't need to run the script since the
PNG files should already be there, but in case you want to generate the assets
yourself, all you need is ImageMagick.

## Credits

- Pieces: By Cburnett - Own work, CC BY-SA 3.0,
  https://commons.wikimedia.org/wiki/Category:SVG_chess_pieces
