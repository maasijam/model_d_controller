#include "Controller.h"

/*************************************************************
  Model D App MIDI CONTROLLER

  Controller class
  by Notes and Volts
  www.notesandvolts.com

    
  Modified by maasijam to work with TEENSY LC
 *************************************************************/


//************************************************************
//***SET THE NUMBER OF CONTROLS USED**************************
//************************************************************


//---How many push buttons are connected to a multiplexer?---------
byte NUMBER_MUX_BUTTONS = 5;
//---How many switches are connected to a multiplexer?---------
byte NUMBER_MUX_SWITCHES = 8;
//---How many potentiometers are connected to a multiplexer?--
byte NUMBER_MUX_POTS = 24;

//---How many switches are connected directly to pins?--
byte NUMBER_DIRECT_SWITCHES = 2;
//---How many potentiometers are connected directly to pins?--
byte NUMBER_DIRECT_POTS = 4;


//***ANY MULTIPLEXERS? (74HC4051)************************************
//MUX address pins must be connected to Teensy pins 2,3,4
//*******************************************************************

Mux M1(6, 8, false); //Digital multiplexer on Arduino pin 6
Mux M2(5, 8, false); //Digital multiplexer on Arduino pin 5
Mux M3(A0, 8, true); //Analog multiplexer on Arduino analog pin A0
Mux M4(A1, 8, true); //Analog multiplexer on Arduino analog pin A1
Mux M5(A2, 8, true); //Analog multiplexer on Arduino analog pin A2


//***DEFINE BUTTONS CONNECTED TO MULTIPLEXER*************************
//Button::Button(Mux mux, byte muxpin, byte command, byte value, byte channel, byte debounce)
//** Command parameter 0=NOTE  1=CC  2=Toggle CC **

Button MBU1(M2, 1, 2, 3, 1, 5);
Button MBU2(M2, 0, 2, 9, 1, 5);
Button MBU3(M2, 2, 2, 14, 1, 5);
Button MBU4(M2, 3, 2, 15, 1, 5);
Button MBU5(M2, 4, 2, 20, 1, 5);

//*******************************************************************
//Add multiplexed buttons used to array below like this->  Button *MUXBUTTONS[] {&MBU1, &MBU2, &MBU3, &MBU4, &MBU5, &MBU6.....};
Button *MUXBUTTONS[] {&MBU1, &MBU2, &MBU3, &MBU4, &MBU5};


//***DEFINE SWITCHES CONNECTED TO MULTIPLEXER*************************
//Button::Button(Mux mux, byte muxpin, byte command, byte value, byte channel, byte debounce)
//** Command parameter 0=NOTE  1=CC  2=Toggle CC **

Button MSW1(M1, 0, 1, 21, 1, 5);
Button MSW2(M1, 1, 1, 22, 1, 5);
Button MSW3(M1, 2, 1, 23, 1, 5);
Button MSW4(M1, 3, 1, 24, 1, 5);
Button MSW5(M1, 4, 1, 25, 1, 5);
Button MSW6(M1, 5, 1, 26, 1, 5);
Button MSW7(M1, 6, 1, 27, 1, 5);
Button MSW8(M1, 7, 1, 28, 1, 5);

//*******************************************************************
////Add multiplexed buttons used to array below like this->  Button *MUXBUTTONS[] {&MBU1, &MBU2, &MBU3, &MBU4, &MBU5, &MBU6.....};
Button *MUXSWITCHES[] {&MSW1, &MSW2, &MSW3, &MSW4, &MSW5, &MSW6, &MSW7, &MSW8};

//***DEFINE DIRECTLY CONNECTED SWITCHES*******************************
//Button (Pin Number, Command, CC number, Channel, Debounce Time)
//** Command parameter 0=NOTE  1=CC  2=Toggle CC **

Button SW9(7, 1, 117, 1, 5 );
Button SW10(13, 1, 118, 1, 5 );

//*******************************************************************
//Add buttons used to array below like this->  Button *BUTTONS[] {&BU1, &BU2, &BU3, &BU4, &BU5, &BU6, &BU7, &BU8};
Button *DIRECTSWITCHES[] {&SW9, &SW10};
//****************************************


//***DEFINE POTENTIOMETERS CONNECTED TO MULTIPLEXER*******************
//Pot::Pot(Mux mux, byte muxpin, byte command, byte control, byte channel)
//**Command parameter is for future use**

Pot MPO1(M3, 0, 0, 29, 1);
Pot MPO2(M3, 1, 0, 30, 1);
Pot MPO3(M3, 2, 0, 31, 1);
Pot MPO4(M3, 3, 0, 85, 1);
Pot MPO5(M3, 4, 0, 86, 1);
Pot MPO6(M3, 5, 0, 87, 1);
Pot MPO7(M3, 6, 0, 88, 1);
Pot MPO8(M3, 7, 0, 89, 1);
Pot MPO9(M4, 0, 0, 90, 1);
Pot MP10(M4, 1, 0, 102, 1);
Pot MP11(M4, 2, 0, 103, 1);
Pot MP12(M4, 3, 0, 104, 1);
Pot MP13(M4, 4, 0, 105, 1);
Pot MP14(M4, 5, 0, 106, 1);
Pot MP15(M4, 6, 0, 107, 1);
Pot MP16(M4, 7, 0, 108, 1);
Pot MP17(M5, 0, 0, 109, 1);
Pot MP18(M5, 1, 0, 110, 1);
Pot MP19(M5, 2, 0, 111, 1);
Pot MP20(M5, 3, 0, 112, 1);
Pot MP21(M5, 4, 0, 113, 1);
Pot MP22(M5, 5, 0, 114, 1);
Pot MP23(M5, 6, 0, 115, 1);
Pot MP24(M5, 7, 0, 116, 1);

//Add multiplexed pots used to array below like this->  Pot *MUXPOTS[] {&MPO1, &MPO2, &MPO3, &MPO4, &MPO5, &MPO6.....};
Pot *MUXPOTS[] {&MPO1, &MPO2, &MPO3, &MPO4, &MPO5, &MPO6, &MPO7, &MPO8, &MPO9, &MP10, &MP11, &MP12, &MP13, &MP14, &MP15, &MP16, &MP17, &MP18, &MP19, &MP20, &MP21, &MP22, &MP23, &MP24};
//*******************************************************************

//***DEFINE POTENTIOMETERS CONNECTED DIRECTLY TO PINS*******************
//Pot::Pot(byte pin, byte command, byte control, byte channel)
//**Command parameter is for future use**

Pot DPO1(A3, 0, 119, 1);
Pot DPO2(A4, 0, 16, 1);
Pot DPO3(A5, 0, 17, 1);
Pot DPO4(A6, 0, 1, 1);

//*******************************************************************
//Add direct pots used to array below like this->  Pot *DIRECTPOTS[] {&DPO1, &DPO2, &DPO3, &DPO4 ...};
Pot *DIRECTPOTS[] {&DPO1, &DPO2, &DPO3, &DPO4};
//*******************************************************************

const int channel = 1; // MIDI channel

const int ledPin[] = {10,8,12,9,11}; 
 
void setup() {

  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);
  pinMode(ledPin[2], OUTPUT);
  pinMode(ledPin[3], OUTPUT);
  pinMode(ledPin[4], OUTPUT);
  
  digitalWrite(ledPin[0], LOW);
  digitalWrite(ledPin[1], LOW);
  digitalWrite(ledPin[2], LOW);
  digitalWrite(ledPin[3], LOW);
  digitalWrite(ledPin[4], LOW);
  
}

void loop() {
  if (NUMBER_MUX_POTS != 0) updateMuxPots();
  if (NUMBER_DIRECT_POTS != 0) updateDirectPots();
  if (NUMBER_MUX_BUTTONS != 0) updateMuxButtons();
  if (NUMBER_MUX_SWITCHES != 0) updateMuxSwitches();
  if (NUMBER_DIRECT_SWITCHES != 0) updateDirectSwitches();
  while (usbMIDI.read()) {
     // controllers must call .read() to keep the queue clear even if they are not responding to MIDI
  }
}


//***********************************************************************
void updateMuxPots() {
  for (int i = 0; i < NUMBER_MUX_POTS; i = i + 1) {
    MUXPOTS[i]->muxUpdate();
    byte potmessage = MUXPOTS[i]->getValue();
    if (potmessage != 255) {
      usbMIDI.sendControlChange(MUXPOTS[i]->Pcontrol, 127 - potmessage, channel);
    }
  }
}

//***********************************************************************
void updateDirectPots() {
  for (int i = 0; i < NUMBER_DIRECT_POTS; i = i + 1) {
    byte potmessage = DIRECTPOTS[i]->getValue();
    if (potmessage != 255) {
      usbMIDI.sendControlChange(DIRECTPOTS[i]->Pcontrol, 127 - potmessage, channel);
    }
  }
}

//*******************************************************************
void updateMuxButtons() {

  // Cycle through Mux Button array
  for (int i = 0; i < NUMBER_MUX_BUTTONS; i = i + 1) {

    MUXBUTTONS[i]->muxUpdate();
    byte message = MUXBUTTONS[i]->getValue();

    //  Button is pressed
    if (message == 0) {
      switch (MUXBUTTONS[i]->Bcommand) {
        case 2: //Toggle
          if (MUXBUTTONS[i]->Btoggle == 0) {
            MUXBUTTONS[i]->Btoggle = 1;
            digitalWrite(ledPin[i], HIGH);
            usbMIDI.sendControlChange(MUXBUTTONS[i]->Bvalue, 127, channel);
          }
          else if (MUXBUTTONS[i]->Btoggle == 1) {
            MUXBUTTONS[i]->Btoggle = 0;
            digitalWrite(ledPin[i], LOW);
            usbMIDI.sendControlChange(MUXBUTTONS[i]->Bvalue, 0, channel);
          }
          break;
      }
    }
  }
}

//*******************************************************************
void updateMuxSwitches() {

  // Cycle through Mux Button array
  for (int i = 0; i < NUMBER_MUX_SWITCHES; i = i + 1) {

    MUXSWITCHES[i]->muxUpdate();
    byte message = MUXSWITCHES[i]->getValue();

    //  Button is pressed
    if (message == 0) {
      switch (MUXSWITCHES[i]->Bcommand) {
        case 1: //CC
            if(MUXSWITCHES[i]->Bvalue == 24 || MUXSWITCHES[i]->Bvalue == 25) {
              usbMIDI.sendControlChange(MUXSWITCHES[i]->Bvalue, 0, channel);
            } else {
             usbMIDI.sendControlChange(MUXSWITCHES[i]->Bvalue, 127, channel);
            }
          break;
      }
    }
    //  Button is not pressed
    if (message == 1) {
      switch (MUXSWITCHES[i]->Bcommand) {
        case 1:
          if(MUXSWITCHES[i]->Bvalue == 24 || MUXSWITCHES[i]->Bvalue == 25) {
              usbMIDI.sendControlChange(MUXSWITCHES[i]->Bvalue, 127, channel);
            } else {
              usbMIDI.sendControlChange(MUXSWITCHES[i]->Bvalue, 0, channel);
            }
          break;
      }
    }
  }
}


//*******************************************************************
void updateDirectSwitches() {

  // Cycle through Direct Switches array
  for (int i = 0; i < NUMBER_DIRECT_SWITCHES; i = i + 1) {

    byte message = DIRECTSWITCHES[i]->getValue();

    //  Button is pressed
    if (message == 0) {
      switch (DIRECTSWITCHES[i]->Bcommand) {
        case 1: //CC
            if(DIRECTSWITCHES[i]->Bvalue == 24 || DIRECTSWITCHES[i]->Bvalue == 25) {
              usbMIDI.sendControlChange(DIRECTSWITCHES[i]->Bvalue, 0, channel);
            } else {
             usbMIDI.sendControlChange(DIRECTSWITCHES[i]->Bvalue, 127, channel);
            }
          break;
      }
    }
    //  Button is not pressed
    if (message == 1) {
      switch (DIRECTSWITCHES[i]->Bcommand) {
        case 1:
          if(DIRECTSWITCHES[i]->Bvalue == 24 || DIRECTSWITCHES[i]->Bvalue == 25) {
              usbMIDI.sendControlChange(DIRECTSWITCHES[i]->Bvalue, 127, channel);
            } else {
              usbMIDI.sendControlChange(DIRECTSWITCHES[i]->Bvalue, 0, channel);
            }
          break;
      }
    }
  }
}
