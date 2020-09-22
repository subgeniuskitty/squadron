Overview
========

Squadron is an open source game engine compatible with Wing Commander 1 & 2
game files. It is written in C89 with an eye toward portability to a wide
variety of platforms. See PORTING for more details.

In order to use Squadron you must own a copy of Wing Commander. No data files
are bundled with this repository.


Status
======

Work in progress.


Instructions
============

These instructions are for FreeBSD, the primary development platform.  Rather
than attempt to handle all platforms, the `Makefile` was kept simple with the
intent that the user can easily grok its actions and adapt them.

User configurable options are contained in `src/common/mk.conf`. Edit this file
to set an installation path and provide suitable paths to header and library
files for SDL2. Once this configuration is complete, build from the `src/`
directory with `make all`.  Additional targets `make clean`, `make install` and
`make uninstall` are provided for convenience. Remember to add the installation
directory to your `$PATH`.

Squadron requires that the user own a copy of Wing Commander and that the
installed data files be accessible somewhere in the filesystem. For example, if
your data files for Wing Commander 1 are located at
`/usr/local/wing_commander/WC/GAMEDAT`, pass the path to the base of the Wing
Commander install as the only command line option, like this:

	wc1 /usr/local/wing_commander/

Squadron expects the data files to have their original names and directory
structure.


Porting
=======

In addition to being written in plain C89, Squadron uses shims to decouple the
core game engine from platform specific considerations. Files prefixed with
`filetype_`, `interface_` and `io_` are platform specific and must be replaced
with new code when porting.

The `filetype_` files are responsible for reading in game data files and
passing the information to the core game engine as a struct. As long as you can
create this struct and populate it with appropriate data, the specific form in
which the target platform stores permanent data is irrelevant.

The `io_` files are responsible for all I/O, including video output and
keyboard/joystick/mouse input. For example, the core game engine includes its
own renderer, requiring only that the target platform provide a function which
accepts and displays a series of bitmaps. The intent is to provide a program
which can easily be ported to full PCs running Windows or Unix, as well as
embedded platforms running embedded OSes like NuttX or bare metal.

Finally, the `interface_` files are responsible for tying together all the
platform specific details. All access by the core game engine passes through
these files. Data formats expected by the engine, like the game data struct,
are documented in these files.

Don't forget to update the `README.md` files with new instructions for new
platforms.
