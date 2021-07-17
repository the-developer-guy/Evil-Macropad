#include "DigiKeyboard.h"

#define KEY_DEL 76
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(5, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP); 

  DigiKeyboard.sendKeyStroke(0);
  
  // DigiKeyboard.sendKeyStroke(KEY_V , MOD_CONTROL_LEFT); 
  // DigiKeyboard.sendKeyStroke(KEY_L , MOD_GUI_LEFT);
  // DigiKeyboard.sendKeyStroke(KEY_DEL , MOD_CONTROL_LEFT | MOD_ALT_LEFT);
}
// the loop routine runs over and over again forever:
void loop() {
  if(digitalRead(5) == LOW) DigiKeyboard.sendKeyStroke(KEY_A);
  if(digitalRead(2) == LOW) DigiKeyboard.sendKeyStroke(KEY_B);
  if(digitalRead(1) == LOW) DigiKeyboard.sendKeyStroke(KEY_C);
  if(digitalRead(0) == LOW) DigiKeyboard.sendKeyStroke(KEY_D);
  delay(1000);               // wait for a second
}
