# HC-12
HC-12 library for Arduino

The HC-12 modules should be connected in the following way. Image is from Tom Heylen.
![alt text](./doc/HC-12_schematic.jpg)

The above schematic shows the transmitter mode setup. To enter the AT command mode,
one should connect the SET pin to ground.

An important future improvement to this code is to implement a proper communication
protocol such as XMODEM or HDLC.
