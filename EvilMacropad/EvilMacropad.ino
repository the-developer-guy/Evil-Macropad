#include "DigiKeyboard.h"

#include "key_definitions.h"

#define PIN_A 5
#define PIN_B 2
#define PIN_C 1
#define PIN_D 0

#define EVIL_A
#define EVIL_B
#define EVIL_C
#define EVIL_D

// chance: 1/x
#define EVIL_A_CHANCE 1000
#define EVIL_B_CHANCE 1000
#define EVIL_C_CHANCE 1000
#define EVIL_D_CHANCE 1000


void keyPressA(void);
void keyPressB(void);
void keyPressC(void);
void keyPressD(void);

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
      keyPressA();
    }
    if(state_b == LOW && previousState_b == HIGH)
    {
      keyPressB();
    }
    if(state_c == LOW && previousState_c == HIGH) 
    {
      keyPressC();
    }
    if(state_d == LOW && previousState_d == HIGH) 
    {
      keyPressD();
    }

    previousState_a = state_a;
    previousState_b = state_b;
    previousState_c = state_c;
    previousState_d = state_d;
  }
}

void keyPressA(void)
{
  DigiKeyboard.sendKeyStroke(KEY_A);
}

void keyPressB(void)
{
  DigiKeyboard.sendKeyStroke(KEY_V , MOD_CONTROL_LEFT);
}

void keyPressC(void)
{
  DigiKeyboard.sendKeyStroke(KEY_L , MOD_GUI_LEFT);
}

void keyPressD(void)
{
  DigiKeyboard.sendKeyStroke(KEY_DEL , MOD_CONTROL_LEFT | MOD_ALT_LEFT);
