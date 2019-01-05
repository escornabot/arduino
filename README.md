
# Arduino firmware for Escornabot

[![Travis Build Status](https://travis-ci.org/escornabot/arduino.svg)](https://travis-ci.org/escornabot/arduino)

This is the Arduino firmware to upload to the Escornabot.

__More info about the Escornabot at [escornabot.com][ESC01]__

Please, [open issues here][ISS01] if you find any problem with this firmware. Thank you!

Download the __[last version from here][REL01]



## Instructions


### Compilation and upload with Arduino IDE

1. Install the [Arduino IDE][IDE01] 

2. [Copy the right configuration][CON01] to the Escornabot directory.

3. Follow this [guide compilated by @escornafan][GUI01] (in Spanish).



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



## Branches and releases

Escornabot's repository flows through 2 main branches: 

- [stable][STA01]: well-tested firmware that you usually have to work with.
  Released versions are named with even minor numbers (x.0, x.2, ...).
- [testing][TES01]: new features and minor bugs pending of testing in deep.
  Released versions are named with odd minor numbers (x.1, x.3, ...).

Releases are [published ready to download in zip format][REL01].



<!-- links -->
[BRI01]: https://github.com/escornabot/arduino/releases/tag/v1.2-brivoi
[CON01]: ./config
[ESC01]: http://escornabot.com
[GUI01]: https://pablorubma.cc/como-instalar-la-programacion-arduino-en-mi-escornabot/
[IDE01]: https://www.arduino.cc/en/Main/Software
[ISS01]: https://github.com/escornabot/arduino/issues
[PIO01]: https://platformio.org/install/cli
[REL01]: https://github.com/escornabot/arduino/releases
[STA01]: https://github.com/escornabot/arduino/tree/stable
[TES01]: https://github.com/escornabot/arduino/tree/testing


