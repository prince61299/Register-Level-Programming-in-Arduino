// TIMER INPUT COMPARE MODE REGISTER IN ARDUINO
// Register level program for Timer Input Compare Mode.
// This project is design by Prince Kumar Kushwaha.
/*
Steps for designing the code:
-> Enable the Global Interrupt Enable Bit.
-> Enable the required timer interrupt.
-> set Mode of the Timer.
-> Set the Prescaler of the Timer.
-> Start the Timer with Inital value.
-> Seect the Edge of the Capturing.
-> Implement the ISR function.
*/

uint16_t Captured;
void setup() {
  // put your setup code here, to run once:
  // Enable the Global Interrupt Enable Bit.
  sei();

  // Enable the required timer interrupt.
  TIMSK1 |= (1 << ICIE1);  //Enable the Input capture bit of Timer1

  // set Mode of the Timer.
  TCCR1A &= (~(1 << WGM10)) & (~(1 << WGM11));
  TCCR1B &= (~(1 << WGM12)) & (~(1 << WGM13));  //NORMAL MODE

  // Set the Prescaler of the Timer.
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TCCR1B &= (~(1 << CS11));  //PRE = 1024

  // Start the Timer with Inital value.
  TCNT1 = 0;  //INITIAL VALUE

  // Select the Edge of capturing
  TCCR1B |= (1 << ICES1);  //rising edge capturing

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// Implement the ISR function.
ISR(TIMER1_CAPT_vect) {
  Captured = ICR1;
  Serial.println(Captured);
}