# Soldering USB Connectors

_Time spent: 1h_

As my components arrived, I started soldering the big parts first so that I don't blow the tiny capacitors away with the heat gun if I were to do it the other way around.

Firstly, I tried soldering the USB-C connector with a soldering iron which got really messy because of the small pins of the connector. So I watched some youtube tutorials on how to solder smd components correctly where I learned some new techniques. In the end, I used solder paste and a heat gun and had to fix it a couple times until it looked good und a lens.

<img src="https://github.com/F45c/portable-gnss-display/blob/9f769c3e9a5f7be0c1e2a3b845c04577a4089eec/images/ucb_c_connector.png" width=30% />

For the USB-A connector, I had to use a lot of solder paste to fill the shielding pin holes but except that, this component was easy to solder.


# Finishing PCB Assembly

_Time spent: 1.5h_

The next big part was the NEO M8N to solder to the PCB. I used the heat gun with solder paste and it took a few tries to get every pin connected. Next were the pin headers for UART and power configuration and the pin sockets for the display. For these components, it worked well to solder them with the soldering iron. The resistors and capacitors were more difficult because the iron would sometimes hold on to them and pull them off again. The linear voltage regulators are also SMD components but their pins are much easier to solder. For the U.Fl (antenna) connector, I again used an hot air gun requiring only a little retries.

At the end, I connected power to the board and measured some places and the voltage flew correctly.

<img src="https://github.com/F45c/portable-gnss-display/blob/9f769c3e9a5f7be0c1e2a3b845c04577a4089eec/images/pcb_finished.png" width=40% />

# Testing the final build

_Time spent: 0.33h_

I downloaded a few tiles where I live and put them on the sd card. I used the google satellite images API with zoom level 15. After like 15min in line of sight to the sky, the neo m8n finished downloading the current satellite positions and got the first fix.

Below is an example image of the map with my position but I had to censor most of the map so that I don't leak my address. The tiles are centered on my position being displayed by the + symbol. On top, there is the N for north direction of the map.

<img src="https://github.com/F45c/portable-gnss-display/blob/9f769c3e9a5f7be0c1e2a3b845c04577a4089eec/images/final_test.png" width=80% />
