// INTERFACING OF RELAY WITH ARDUINO
// Register level program for Relay
// This project is design by Prince Kumar Kushwaha
/*
We make a circuits when if you pressed the button the Relay ON and if you release the button then Relay will OFF.
Steps for connecting the relay with Arduino
-> Connect the Relay with digitalPin 8 of Arduino i.e.; PB0 (Port B) of ATMEGA328
-> Switch will coonect with digitalPin 7 of the Arduino i.e.; PD7 (Port D) of ATMEGA328
*/

void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << DDB0);  //PB0 = OUTPUT
  DDRB &= (1 << DDR7);  //PD7 = INPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  if (PIND & (1 << PIND7)) {
    PORTB |= (1 << PB0);  //True
  } else {
    PORTB &= ~(1 << PB0);  //False
  }
}
