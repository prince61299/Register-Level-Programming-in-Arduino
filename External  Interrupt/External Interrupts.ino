// EXTERNAL INTRRUPTS PROGRAM FOR ARDUINO
// Register level program for External interrupts
// This project is design by Prince Kumar Kushwaha
/*
Steps for design the Program:
-> Enable the GIE (Global Enterrupts Enable) bit.
-> Enable the required external interrupts for the corresponding.
-> Set the Edge Select for External interrupts.
-> Implement the interrupt handler.*/

void setup() {
  // put your setup code here, to run once:
  DDRB |= (1<<DDB5); //  PB5 = O/P

  //Enanble the GIE 
  SREG |= (1<<7);

  //We can also use the inbuit function for the set the SREG register.
  sei();

  //Enable the required External Interrups from the corresponding register.
  EIMSK |= (1<<INT0) | (1<<INT1);

  //Set the edge select external interrupt
  EICRA |= (1<<ISC10) | (1<<ISC11) | (1<<ISC00) | (1<<ISC01);

}

void loop() {
  // put your main code here, to run repeatedly:

}

//IMPLEMENT THE INTERRUPT HANDLER
ISR(INT0_vect) {
  PORTB |= (1<<PB5);
}

ISR(INT1_vect){
  PORTB &= ~(1<<PB5);
}