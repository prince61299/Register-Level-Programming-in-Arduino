// TIMER OUTPUT COMPARE MODE REGISTER IN ARDUINO
// Register level program for Timer Output Compare Mode.
// This project is design by Prince Kumar Kushwaha.
/*
Steps for designing the code:
-> Enable the Global Interrupt Enable Bit.
-> Enable the required timer interrupt.
-> set Mode of the Timer.
-> Set the Compare Output Mode.
-> Set the Prescaler of the Timer.
-> Start the Timer with Inital value.
-> Load the period for the Timer.
-> Configure the output comapre pin as output.
-> Implement the ISR function.
*/

void setup() {
  // put your setup code here, to run once:
  // Enable the Global Interrupt Enable Bit.
  sei();

  // Enable the required timer interrupt.
  TIMSK1 |= (1 << OCIE1A);

  // set Mode of the Timer.
  TCCR1A &= (~(1 << WGM10)) & (~(1 << WGM11));
  TCCR1B &= (~(1 << WGM12)) & (~(1 << WGM13));  //NORMAL MODE

  // Set the Compare Output Mode.

  TCCR1A |= (1 << COM1A0);
  TCCR1A &= (~(COM1A1));  //TOGGLE

  // Set the Prescaler of the Timer.
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TCCR1B &= (~(1 << CS11));  //PRE = 1024

  // Start the Timer with Inital value.
  TCNT1 = 0;  //INITIAL VALUE

  // Load the period for the Timer.
  OCR1A = 15625;

  // Configure the output comapre pin as output.
  DDRB |= (1 << DDB1);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// Implement the ISR function.
ISR(TIMER1_COMPA_vect) {
  TCNT1 = 0;
  OCR1A = 15625;
}