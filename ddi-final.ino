/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>
#include <MIDI.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = { {'0', '1', '2', '3'}, {'4', '5', '6', '7'}, {'0', '1', '2', '3'}, {'4', '5', '6', '7'} };
byte rowPins[ROWS] = {26, 25, 33, 32}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {27, 14, 12, 13}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

MIDI_CREATE_DEFAULT_INSTANCE();
int canalMIDI = 1;
int notas[] = {48, 49, 51, 53, 54};
int entAnalog[] = {4, 18};
int nroCC[] = {10, 11};
int valorCC[] = {0, 0};

void setup() {
  MIDI.begin(1);
  
  Serial.begin(115200);
}
  
void loop() {
  char customKey = customKeypad.getKey();
  
  if (customKeypad.getState() == 1) {
    if(customKey == '0') {
      MIDI.sendNoteOn(54, 100, canalMIDI);
    } else if(customKey == '1') {
      MIDI.sendNoteOn(60, 100, canalMIDI);
    } else if(customKey == '2') {
      MIDI.sendNoteOn(63, 100, canalMIDI);
    } else if(customKey == '3') {
      MIDI.sendNoteOn(71, 100, canalMIDI);
    } else if(customKey == '4') {
      MIDI.sendNoteOn(80, 100, canalMIDI);
    } else if(customKey == '5') {
      MIDI.sendNoteOn(81, 100, canalMIDI);
    } else if(customKey == '6') {
      MIDI.sendNoteOn(85, 100, canalMIDI);
    }
  }
  
//  valorCC[0] = map (analogRead(entAnalog[0]), 0, 4098, 0, 6);
//  MIDI.sendControlChange(nroCC[0], valorCC[0], canalMIDI);
//
//  valorCC[1] = map (analogRead(entAnalog[1]), 0, 4098, 0, 127);
//  MIDI.sendControlChange(nroCC[1], valorCC[1], canalMIDI);
}
