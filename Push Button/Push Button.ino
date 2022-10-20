// TO USE THE PUSH BUTTON
// Register level program for Push Button
// This project is design by Prince Kumar Kushwaha

/*
Step 01: Connect the PushButton with the Port D (PD2) of the ATMEGA328 ie digitalPin 2 of the Arduino UNO
Step 02: Connect a LED with Pin 13 of Arduino which is Port B5 of ATMEGA328
*/

void setup() {
  // put your setup code here, to run once:

  //make the ledPin as OUTPUT
  DDRB |= (1 << DDB5);  //PB5 = O/P

  //make Port D2 as input
  DDRD &= ~(1 << DDD2);  //PD2 = I/P
}

void loop() {
  // put your main code here, to run repeatedly:
  //condition if button is pressed turn on the led

  if (PIND & (1 << PIND2))
  {
    PORTB |= (1 << PB5);  //turn ON the Port B5 (HIGH)
  }
  else {
    PORTB &= ~(1 << PB5);  //turn OFF the Port B5 (LOW)
  }
}