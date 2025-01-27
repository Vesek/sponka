[Czech README](/README.md)
# sponka
RGB hairclip, built for a flex PCB
### ***very work in progress***
## Components
- CH32V003
	- very low-cost MCU, enough for blinking LEDs
	- i just wanted to learn it
- WS2812B-MINI
	- Smol WS2812B
- TP4057
	- Li-ion charger
	- featured in those Aliexpress special Li-ion charging boards
- DW01A
	- Battery protiection
	- Batteries sometimes have it included, this is for those that don't
## Software
Software is written with [ch32v003fun](https://github.com/cnlohr/ch32v003fun) - an open-source and lightweight stack for the CH32V003 series

### Programming the board
The board has a 3 pin header with SWIO. The chip's manufacturer unfortunately
chose to implement a custom "spin-off" of SWD, so you'll need a compatible programmer.

Apart from the official programmers there are also SW programmers for various MCUs, come of them are mentioned in the README of [ch32v003fun](https://github.com/cnlohr/ch32v003fun).
There are also programmers for the [Flipper Zero](https://github.com/sukvojte/wch_swio_flasher) and [RPi Pico](https://github.com/aappleby/picorvd).

You can find the connection of individual programmers in their README and the SWIO header pinout is written on the bottom of the board.

Software can be compiled and uploaded using:
```bash
make
```
Don't forget to download submodules:
```bash
git submodule update --init
```
