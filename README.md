# Arduino-Sample-Code-for-CFAF800480E0-050SC-A1
This is the Seeeduino / Arduino Demonstration code for the FTDI / Bridgetek FT813 based CFAF800480E0-050SC-A1 using the CFA10098 breakout / audio adapter.

This code is somewhat inspired by the code in FTDI's AN_275:
http://brtchip.com/wp-content/uploads/Support/Documentation/Application_Notes/ICs/EVE/AN_275_FT800_Example_with_Arduino.pdf
As could be expected, it turned out to be a nearly total re-write.

My primary intention is to make the code as un-obtuse and as clear as possible. The secondary goal is to make the code small and efficient as all embedded code should be.

This code is not a library, it is an example and demonstration project. As such it depends on only the Arduino uSD and SPI libraries. All other code is clearly included.

To configure the code, you can edit the section at the top of CFA10100_defines.has

No uSD (Micro SD card) is needed to do the basic demo.

You can connect a uSD card -- use digital 10 as the chip select -- to have a more colorful demo. The files for the uSD card are in the uSD_files folder.

2019-04-19
Brent A. Crosby
Crystalfontz America, Inc.
https://www.crystalfontz.com/
