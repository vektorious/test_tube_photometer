<p align="center">
<img src="https://github.com/vektorious/test_tube_photometer/blob/master/pictures/tt_logo.png" width="100"/>
<h1 align="center">The Test Tube Photometer</h1>

<h3 align="center">Low-cost hardware setup for measuring light extinction and optical densities</h3>
</p>
<br>

## Welcome!

This will be filled with more information at a later point.
You can find a description on how to build the OLD VERSION of the photometer [here](https://alexanderkutschera.com/2017/12/09/photometer-shopping-list.html).

- [What's this all about?](#background)
- [How can I build my own photometer?](#building-instructions)
- [How can I contribute?](#contributing)
- [Wait, why should I contribute?](#report-issues)
- [Who is behind all this?](#who-is-behind-all-this)

### Background
#### What's a photometer?
Photometers are used to measure light extinction in liquids to analyse their content. They basically shine light through a certain amount of the liquid from one side and measure the light that's left on the other side. Among other things, photometers are used to measure the densities of bacterial cultures on a regular basis. You can determine them by comparing photometer measurements of culture media with (sample value) and without bacteria (blank value). Using physical laws you can then calculate the optical density of your sample.

#### Why a test tube photometer?
Well, I'm a lazy person. In order to measure the optical density of my bacterial cultures I always had to take a sample from them. This usually meant I had to work sterile to avoid contamination of my cultures which is a bit time consuming. That's why I asked myself if there is a way to measure the density directly in the test tube without having to open it. There are already some test tube photometer out there but they are expensive and often require the use of specific test tubes. That's why I started to develop a photometer which I could use with the standard test tubes.

### Assembly instructions

The photometer is designed to be modular. You can add as many measurement cells as you like (well ok. you are limited by the amounts of analog inputs your microcontroller has).

There are two was of building the photometer:

#### 1. Using a breadboard and cables

**Advantage:**
You don't need many special parts apart from the sensor (opt101). Some cables, resistors and a breadboard are required as well.

**Disadvantage:**
The connections are not very stable which could produce reading errors. Wiring the opt101 just with cable is a bit confusing (at least it was for me). Apart from that, the legs of the sensor break easily if you bend them to often and too much.

#### 2. Using PCBs (Arduino Nano HAT and the sensor PCB)

**Advantage:**
All the electronics are easy to put together. The connections are stable and secure. You can quickly add connect more measurement cells.

**Disadvantage:**
Well.. you need the PCBs. But you can easily order them from a PCB manufacturer with the gerber files in this repository. You'll find more info about this in [/hardware/pcb/README]().

Both ways of building the photometer are described [in the instructions folder]().

### Contributing

TODO

### Report issues

TODO

### Who is behind all this?



Please contact me if you have any questions.

<p align="center">
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a> </br>This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
</p>
