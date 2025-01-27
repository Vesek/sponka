[English README](/README_en.md)
# sponka
RGB sponka na vlasy, postavená na flex PCB
### ***velice work in progress***
## Komponenty
- CH32V003
	- velice low-cost MCU, dostatečné na ovládání LED
	- chtěl jsem se s ním naučit
- WS2812B-MINI
	- Menší verze WS2812B
- TP4057
	- Nabíječ baterie s ochranou
	- můžete znát z většiny Li-ion nabíjecích desek z Aliexpressu
- DW01A
	- Ochrana samotné baterie
	- Některé baterie mají vestavěné, pro ostatní je zde
## Software
Software je napsaný s vývojovým prostředím [ch32v003fun](https://github.com/cnlohr/ch32v003fun) - open-source a lightweight stack pro programování těchto čipů

### Programování desky
Na desce jsou vyvedeny 3 piny pro SWIO. Výrobce čipu se bohužel rozhodl zavést
nestandardní "spin-off" SWD, takže potřebujete kompatibilní programátor.

Mimo oficiálního programátoru existují i SW programátory na různé MCU, některé lze najít v README [ch32v003fun](https://github.com/cnlohr/ch32v003fun),
existují ale i verze pro [Flipper Zero](https://github.com/sukvojte/wch_swio_flasher)a [RPi Pico](https://github.com/aappleby/picorvd).

Zapojení jednotlivých programátorů můžete najít v jejich README a
pinout SWIO je napsaný na spodní straně desky.

Software zkompilujete a nahrajete pomocí:
```bash
make
```
Nezapoměňte před tím stáhnout submoduly:
```bash
git submodule update --init
```
