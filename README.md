# 16x arcade button midicontroller

This is a sketch for an midi controller with 16 buttons.
I wrote this for an ardunio uno rev. 3 and 16 sanwa arcade buttons.

NOTE: This sketch sends midi codes over the serial connection over usb. To use it as a midi controller, you have to either use a 'translator' (i used https://projectgus.github.io/hairless-midiserial/) to convert the serial signals into real midi signals or you have to use a custom firmware (http://www.dimitridiakopoulos.com/hiduino.html) for the arduino which converts the signals before sending it.
