
# Arduino firmware for Escornabot

[![Travis Build Status](https://travis-ci.org/escornabot/arduino.svg)](https://travis-ci.org/escornabot/arduino)

This is the Arduino firmware to upload to the Escornabot.

__More info about the Escornabot at [escornabot.com][ESC01]__

Please, [open issues here][ISS01] if you find any problem with this firmware. Thank you!

Download the __[last version from here](https://github.com/escornabot/arduino/releases/latest)__

## Instructions

### Full guide

To configure and load the firmware, please, follow the [official guide][GUI01].

### Compilation and upload with PlatformIO

You only need to install [PlatformIO CLI][PIO01]:

    pip install -U platformio

There is a project file _platformio.ini_ to compile and upload escornabot
firmware to the Atmel AVR platform + Arduino framework for Arduino Nano and
Arduino Micro boards.

#### Arduino Nano

    # compile firmware and upload firmware to an Arduino Nano:
    pio run -e nano -t upload

#### Arduino Micro

    # compile firmware and upload firmware to an Arduino Micro:
    pio run -e micro -t upload

#### More boards

Please, send us new configurations if you test Escornabot in another board :)



<!-- links -->
[BRI01]: https://github.com/escornabot/arduino/releases/tag/v1.2-brivoi
[ESC01]: http://escornabot.com
[GUI01]: http://escornabot.com/web/en/content/configure-and-load-firmware
[ISS01]: https://github.com/escornabot/arduino/issues
[PIO01]: http://platformio.org/get-started/cli
[PLA01]: https://github.com/escornabot/arduino/releases/tag/v1.1-placidus
[VER201606]: https://github.com/escornabot/arduino/releases/tag/v1.3.1
[VER201608]: https://github.com/escornabot/arduino/releases/tag/v1.3.2


