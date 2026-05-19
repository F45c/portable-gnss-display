# Portable GNSS / GPS Display
### What it is
The Display shows a satellite map of your nearby surroundings with an indicator in the center of the device's location. It not only uses GPS satellites but also the european Galileo, BeiDou and some others.
With the UART connections and USB connectors, you can read the position with a phone or a computer.

### How it works
It uses the ublox neo m9n chip with an active antenna and an Esp32-C3 that extracts the position, calculates the tiles to draw on the screen and draws them together with a position mark on the display.
The tiles are stored on sd card slot in the tft display and are pre-downloaded on set sd card for a small area around my home town.

#### Technical Details
> The Neo M9N can be directly connected via USB-A Connector to an external device
>
>The Esp32 and Neo communicate over UART with baud rate 9600
>
>The Esp32 communicates with the display and sd card over SPI
>
>
>With some jumper pins, you can configure which part of the PCB is powered with what source.
>
>The UART pin headers are for using an external uart connection to read the position or communicate with the Esp32.
>This can also be configured using jumper pins

![](https://github.com/F45c/portable-gnss-display/blob/017a918aa0f894e73ad2aad086077cf378f89c2e/images/pcb_3d_angled.png)

#### Components
> uBlox Neo M9N -> GNSS Receiver
>
> Esp32-C3 -> processor
>
>  1.8 inch TFT Display with SD CARD -> Display
>
> Active Antenna -> better reception
>
> MCP170XT-3302E -> 3.3V Linear Voltage Regulator

<img src="https://github.com/F45c/portable-gnss-display/blob/3ff603ed73bbd4746289c46180ef5f4e9e3512e4/images/display.png" width=45%>


### Why I made this
I wanted to have a device showing my exact location reliably because google maps sometimes doesn't show my location when my phone has bad cellular reception (even with good gps reception).

I also like satellite maps instead of normal street lines maps to better see what's around me and since the satellite images aren't up to date, you can see how the world changed.

It's kind of an extra gadget that doesn't require a phone to work and, as mentioned, runs reliably all the time, can't be hacked etc.

### Schematic

#### Some mentionable parts
> 27 Ω resistors (22+5.1) between D+/D- lines to Neo for full-speed driver
>
> lots of capacitors around LDOs for stable voltage
>
> important bias T at antenna input for active antennas
>
> Neo VDD_USB needs to be pulled down when not in use
>
> Jumper pin configuring happening on the left
>
> Three power source inputs to choose from (USB-A, USB-C, battery)

![](https://github.com/F45c/portable-gnss-display/blob/cbb3217f1e014a167dc5a0e0828ae718b379f3bd/images/schematic.png)

