# QMK Firmware for KBDPAD MK2


## Flash Guide

1. Hold `ESC` and plug the board in
2. Clear EEPROM in QMK Toolbox
3. Flash the firmware

### Or use QMK CLI to flash
`qmk compile -kb kbdfans/kbdpad/mk2 -km shigure -j 32`

`qmk flash -kb kbdfans/kbdpad/mk2 -km shigure -j 32`