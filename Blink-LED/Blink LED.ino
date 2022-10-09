// LED blinking program
// Register level progam to blink LED
// This progam is design by Prince Kumar Kushwaha 

/*
Step 01: We have to set PB5 (Port B5) pin of ATMEGA328 as OUTPUT
Step 02: Turn ON/ HIGH the port B5
Step 03: Wait of delay
Step 04: Turn OFF/ LOW the PB5
Step 05: Wait of delay

Reamrk: PORT B5 in connected with PIN 13 of Arduino 
*/

void setup() {
  // put your setup code here, to run once:
  DDRB |= ( 1<<DDB5); //Port PB5 as output

}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB |= (1<<PB5); //PB5 = HIGH
  delay(1000); //inbuilt delay of Arduino IDE
  PORTB &= ~(1<<PB5); //PB5 = LOW
  delay(1000);

}
