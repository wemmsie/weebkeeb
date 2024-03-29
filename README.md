# weebkeeb
Iris Rev 7 with some fancy layer 2 shenanigans and LED dependencies.

## Features
- Layer 2 with various LED color changes to indicate hidden keys. Helps for the newly initiated to Iris
- Also has some shift shortcuts on L2 to reduce vertical reach and keep all numerical special characters to the "num pad"
- Includes some essential coding symbols on L2 - change to your liking!
- All LED config is based off of LED matrix
- Brightness of LEDs limited for low voltages of direct input into a KVM switch for switching key shortcuts
- Tap dance for caps lock that turns the shift key red as well as TD for layer switching
- Sleep timer set to 10 minutes to avoid burnout (for split keyboards, wake all the LEDs at once by pressing a key on the slave side)
- Keycode shortcuts for a universal password (fight me) and testing out an em dash shortcut (this input also has a slight delay between each character since the input to a kvm switch would not recognize this if only miliseconds apart)
- Em dash with kvm switch friendliness (40ms delay) set on layer 2

Here is a great reference for the LED layout thanks to [kahgoh](https://github.com/kahgoh) based on [this writeup](https://kahdev.hashnode.dev/finding-the-led-indexes-on-the-iris).

![kahgoh_leds](https://cdn.hashnode.com/res/hashnode/image/upload/v1664287501742/hSBclLM6v.png?auto=compress,format&format=webp)
