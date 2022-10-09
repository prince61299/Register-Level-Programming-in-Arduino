// Counting 0 to 9 on Seven segment display program
// Register level progam for seven segment display (common cathode)
// This progam is design by Prince Kumar Kushwaha

/*
Step 01: Connect the Pin of seven segment with Port D (PD)
PD0 - DigitalPin 0 (Rx)
PD1 - DigitalPin 1 (Tx)
PD2 - DigitalPin 2
PD3 - DigitalPin 3 (PWM)
PD4 - DigitalPin 4
PD5 - DigitalPin 5 (PWM)
PD6 - DigitalPin 6 (PWM)
PD7 - DigitalPin 7
Step 02: Make all port of Port D as OUTPUT
Step 03: Write Progam logic to print number
*/

void setup() {
  // put your setup code here, to run once:
  DDRD = 0xFF;  //port D of all pin as OUTPUT
}
//assign the charcter in hexa decimal from 0 to 9
unsigned char _7SEGMENT[10] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x6F }, i = 0;

void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < 10; i++) {
    PORTD = _7SEGMENT[i];
    delay(1000);  //delay of 1sec
  }
}