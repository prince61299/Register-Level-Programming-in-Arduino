// TIMER INTERRUPT REGISTER IN ARDUINO
// Register level program for Timer Interrupt Register.
// This project is design by Prince Kumar Kushwaha
/*
Steps for designing the code
-> Enable the Global Interrupt Enable Bit.
-> Enable the Required Timer Interrupt.
-> Set Mode of the Timer.
-> Set the Prescaler for the Timer.
-> Set the Period for the Timer.
-> Implement the Interrupt Handler Function.
*/

void setup() {
  // put your setup code here, to run once:
  DDRB |= (1<<DDB5); //PB5 = OUTPUT

  // Enable the Global Interrupt Enable Bit.
  sei();

  // Enable the Required Timer Interrupt.
  TIMSK1 |= (1<<TOIE1);

  // Set Mode of Timer
  TCCR1A &= (~(1<<WGM10)) & (~(1<<WGM11));
  TCCR1B &= (~(1<<WGM12)) & (~(1<<WGM13));

  // Set the Prescaler for the Timer.
  TCCR1B |= (1<<CS12) | (1<<CS10);
  TCCR1B &= (~(1<<CS11));

  // Set the Period for the Timer.
  TCNT1 = 49910; //1 sec.

}

void loop() {
  // put your main code here, to run repeatedly:

}

// Implement the Interrupt Handler Function.
ISR(TIMER1_OVF_vect) {
  PORTB ^= (1<<PB5);
  TCNT1 = 49910;
}
