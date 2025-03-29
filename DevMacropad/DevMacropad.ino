#include "DigiKeyboard.h"

#define PIN_A 5
#define PIN_B 2
#define PIN_C 1
#define PIN_D 0

void startDebug(void);
void stepOver(void);
void stepInto(void);
void stepOut(void);

unsigned long task;
bool previousState_a;
bool previousState_b;
bool previousState_c;
bool previousState_d;

// the setup routine runs once when you press reset:
void setup() 
{                
  // initialize pins (buttons)
  pinMode(PIN_A, INPUT_PULLUP);
  pinMode(PIN_B, INPUT_PULLUP);
  pinMode(PIN_C, INPUT_PULLUP);
  pinMode(PIN_D, INPUT_PULLUP); 

  DigiKeyboard.sendKeyStroke(0);
  
  task = millis() + 1;
  previousState_a = HIGH;
  previousState_b = HIGH;
  previousState_c = HIGH;
  previousState_d = HIGH;
}

void loop() 
{
  if(millis() >= task)
  {
    task++;
    bool state_a = digitalRead(PIN_A);
    bool state_b = digitalRead(PIN_B);
    bool state_c = digitalRead(PIN_C);
    bool state_d = digitalRead(PIN_D);

    if(state_a == LOW && previousState_a == HIGH)
    {
      stepOver();
    }
    if(state_b == LOW && previousState_b == HIGH)
    {
      startDebug();
    }
    if(state_c == LOW && previousState_c == HIGH) 
    {
      stepOut();
    }
    if(state_d == LOW && previousState_d == HIGH) 
    {
      stepInto();
    }

    previousState_a = state_a;
    previousState_b = state_b;
    previousState_c = state_c;
    previousState_d = state_d;
  }
}

void startDebug(void)
{
  DigiKeyboard.sendKeyStroke(KEY_F5); 
}

void stepOver(void)
{
    DigiKeyboard.sendKeyStroke(KEY_F10); 
}

void stepInto(void)
{
  DigiKeyboard.sendKeyStroke(KEY_F11); 
}

void stepOut(void)
{
  DigiKeyboard.sendKeyStroke(KEY_F11, MOD_SHIFT_LEFT);
}


