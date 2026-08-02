# Portable GNSS / GPS Display
### What it is
The Display shows a satellite map of your nearby surroundings with an indicator in the center of the device's location. It not only uses GPS satellites but also the european Galileo, BeiDou and some others.
With the UART connections and USB connectors, you can read the position with a phone or a computer.

### How it works
It uses the ublox neo m9n chip with an active antenna and an Esp32-C3 that extracts the position, calculates the tiles to draw on the screen and draws them together with a position mark on the display.
The tiles are stored on sd card slot in the tft display and are pre-downloaded on set sd card for a small area around my home town.

### Finished Module
I finished the PCB assembly. It was difficult to solder the tiny components and especially the SMD parts. Thankfully, with the help of solder flux and a heat gun, I was able to solder everything on the pcb.
The most annoying component was the USB-C connector because the pins are so tiny and would always bridge multiple together.

I downloaded a few tiles where I live and put them on an sd card. I had to censor the map mostly so I don't leak my address. The example image is below.

It's a very nice device but after all, I still use my phone more often than this.


<img src="https://github.com/F45c/portable-gnss-display/blob/bd5720b20900144298abf5cfa251b87a35412e71/images/pcb_finished.png" width=40%>

<img src="https://github.com/F45c/portable-gnss-display/blob/bd5720b20900144298abf5cfa251b87a35412e71/images/pcb_assembled.png" width=40%>

(Redacted display because it shows my home location)

In the center, on the red + symbol is the gps position and on top is the N for north.

<img src="https://github.com/F45c/portable-gnss-display/blob/2e823edb7e2943eeb44d0c3202f759fba3276c8b/images/final_test.png" width=60%>


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


### PCB Design
The first thing to mention is that the 1.8inch display has enough room and isn't blocked by any components. I made sure of that through the entire development process.

![](https://github.com/F45c/portable-gnss-display/blob/22866dbc0da03db641b929112facfabdd26fa9c6/images/pcb.png)

#### Key Aspects of the Design
> minimum track width = 0.3mm, most power traces = 0.5mm
> lots of vias around the Neo and antenna connector shielding from interference
> four mounting holes when I want to screw it onto something
> tried to make it as small as possible
> track from antenna to Neo Pin has 50ohm impedance
> Ground Plane

When routing on the back layer (ground plane), I tried to make short cuts between the tracks so that the ground plane works better and the path of the current is as short as possible.

Here is an example of this where you can see the spacing between the different tracks on the ground plane (blue layer)

![](https://github.com/F45c/portable-gnss-display/blob/52d92e75a1b3be864f21e496f2a593939a8c8e33/images/pcb_gnd_plane.png)

### BOM

| Name | Purpose | Quantity | Total Cost (USD) | Link | Distributor |
|------|---------|----------|-------------------|------|--------------|
| PCB | PCB board | 1 | 5.50 | | JLCPCB |
| Display | 1.8 inch TFT display | 1 | 6.47 | [Link](https://www.amazon.com/Chiffonade-Display-Interface-128x160-Resolution/dp/B0FQJX2SJV/) | Amazon |
| Antenna | GPS Antenna | 1 | 7.99 | [Link](https://www.amazon.com/28dB-High-Active-Antenna-Built/dp/B0C3H6BKHC) | Amazon |
| PCBA | PCB Assembly Parts | 1 | 33.27 | | |
