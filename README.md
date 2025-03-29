# Evil Macropad
ATtiny85 based macro keypad 

(AKA digistump/digispark)

## Required software

- Arduino IDE (1.x only, tested with 1.8)
- Digistump AVR boards in Arduino, [working board repository link](https://raw.githubusercontent.com/digistump/arduino-boards-index/master/package_digistump_index.json)
- Digistump drivers, in repo for Windows (tested with Windows 11)

The original Digistump site is gone, and Arduino IDE 2.X support is practically gone! Expect some struggles.

## Un-eviled Macropad

A quick example for VS Code (Dev Macropad) was added to the repo.

| Dev | key | mapping |
| ----------- | ----------- | ----------- |
|  |  | Debug |
| Step over | Step into | Step out |

## Example keyboard shortcuts

These usually work "everywhere".
- Save: Ctrl+S - DigiKeyboard.sendKeyStroke(KEY_S, MOD_CONTROL_LEFT);
- Cut: Ctrl+X - DigiKeyboard.sendKeyStroke(KEY_X, MOD_CONTROL_LEFT);
- Copy: Ctrl+C - DigiKeyboard.sendKeyStroke(KEY_C, MOD_CONTROL_LEFT);
- Paste: Ctrl+V - DigiKeyboard.sendKeyStroke(KEY_V, MOD_CONTROL_LEFT);
- Close window: Alt+F4 - DigiKeyboard.sendKeyStroke(KEY_F4, MOD_ALT_LEFT);

### Teams
- Accept video call: Ctrl+Shift+A - DigiKeyboard.sendKeyStroke(KEY_A, MOD_SHIFT_LEFT | MOD_ALT_LEFT);
- Accept audio call: Ctrl+Shift+S - DigiKeyboard.sendKeyStroke(KEY_S, MOD_SHIFT_LEFT | MOD_ALT_LEFT);
- Decline call Ctrl+Shift+D - DigiKeyboard.sendKeyStroke(KEY_D, MOD_SHIFT_LEFT | MOD_ALT_LEFT);
- Toggle mute Ctrl+Shift+M - DigiKeyboard.sendKeyStroke(KEY_M, MOD_SHIFT_LEFT | MOD_ALT_LEFT);
- Start screen share session Ctrl+Shift+E - DigiKeyboard.sendKeyStroke(KEY_E, MOD_SHIFT_LEFT | MOD_ALT_LEFT);
- Toggle video Ctrl+Shift+O - DigiKeyboard.sendKeyStroke(KEY_O, MOD_SHIFT_LEFT | MOD_ALT_LEFT);
- Toggle background blur Ctrl+Shift+P - DigiKeyboard.sendKeyStroke(KEY_P, MOD_SHIFT_LEFT | MOD_ALT_LEFT);

### Zoom
- Toggle video: Alt+V - DigiKeyboard.sendKeyStroke(KEY_V, MOD_ALT_LEFT);
- Toggle mute: Alt+A - DigiKeyboard.sendKeyStroke(KEY_A, MOD_ALT_LEFT);
- Toggle mute for everyone except host: Alt+M - DigiKeyboard.sendKeyStroke(KEY_M, MOD_ALT_LEFT);
- Pause screen share: Alt+T - DigiKeyboard.sendKeyStroke(KEY_T, MOD_ALT_LEFT);
- Start/stop recording: Alt+R - DigiKeyboard.sendKeyStroke(KEY_R, MOD_ALT_LEFT);