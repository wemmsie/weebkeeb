# weebkeeb
Iris Rev 7 with some fancy layer 2 shenanigans and LED dependencies.

## Features
- Layer 2 with various LED color changes to indicate hidden keys. Helps for the newly initiated to Iris
- This layer 2 also has some shift shortcuts to reduce vertical reach and keep all numerical special characters to the layer 2 num pad
- Includes some essential coding symbols on L2 - change to your liking!
- All LED config is based off of LED matrix
- Brightness of LEDs limited for low voltages of direct input into a KVM switch for switching key shortcuts
- Tap dance for caps lock that turns the shift key red as well as TD for layer switching
- Sleep timer set to 10 minutes to avoid burnout (for split keyboards, wake all the LEDs at once by pressing a key on the slave side)
- Keycode shortcuts for a universal password (fight me) and testing out an em dash shortcut (this input also has a slight delay between each character since the input to a kvm switch would not recognize this if only miliseconds apart)

Here is a great reference for the LED layout thanks to [kahgoh](https://github.com/kahgoh) based on [this writeup](https://kahdev.hashnode.dev/finding-the-led-indexes-on-the-iris).

![kahgoh_leds](https://cdn.hashnode.com/res/hashnode/image/upload/v1664287501742/hSBclLM6v.png?auto=compress,format&format=webp)

**NOTE:** Not able to be compiled with current code set until em dash bits get fixed. Update planned 7/14/23.
