
# Changelog

## v1.4.3 (Dec 15, 2017)

Fixed bugs:
- 3-wires keypad not working correctly (reported by Pedro García Pombo).

## v1.4.2 (Oct 28, 2017)

New features:
- EscornaCPU 2.12 configuration file.

## v1.4.1 (Jan 6, 2017)

New features:
- Travis CI is checking pushed code and badge is informing about sanity.
- Refactoring of branches and explained the release numbers in README.
- Nano is set as the default environment in Platformio.

## v1.4.0 (Dec 12, 2016)

New features:
- Standard configurations ready-to-go by board version (see /config folder).
- Instructions to compile and upload with PlatformIO (in README.md).
- Escornabot's greeting preloaded (power on and press the 'Go' button).
- Turn degrees configurable in the abstract Engine class.

## v1.3.3 (Oct 25, 2016)

New features:
- Bluetooth and buttons do not exclude each other as input interface.

## v1.3.2 (Aug 2, 2016)

New features:
- Configuration File to compile with PlatformIO.

Fixed bugs:
- Bluetooth event generation.
- RTTL interpreter default values.

## v1.3.1 (Jun 19, 2016)

New features:
- Leds in keypad are supported.
- Different audio tones by button.
- Enable buzzer by default.
- Default configuration for the [board v2.10](https://github.com/escornabot/electronics/tree/master/Escorna_CPU_2_1) (important: __keypad pin is A7__ instead A4)

Fixed bugs:
- Preprocessor directives reviewed to enable/disable features.
- MoveExecuting event informs the previous move.
- Turn off all LEDs on cancelled program
- RTTL melodies reviewed.

