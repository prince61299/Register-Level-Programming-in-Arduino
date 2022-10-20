// TO PRINT STRING ON LCD PROGRAM
// Register level program for 16x2 LCD screen
// This project is design by Prince Kumar Kushwaha

/*
Steps for connecting the 16x2 lcd with the Arduino
-> RS (Register Select) Pin with Port B0, digitalPin 8 of Arduino
-> RW (Read Write) Pin with Port B1, digitalPin 9 of Arduino
-> E (Enable) Pin with Port B2, digitalPin 10 of Arduino
-> Connect Data Pin (D0 to D7) with Port D (PD0 to PD7), digitalPin 0 to 7 of Arduino
*/

void setup() {
  // put your setup code here, to run once:
  DDRD = 0xFF; //assign all the port D pins as Output

  //to assign Port B of PB0, PB1, PB2 as output
  DDRB |= (1 << DDB0) | (1 << DDB1) | (1 << DDB2);
  lcd_initialise(); //create a function to initialise the lcd
}

//crete a function to writing data to LCD
void lcd_data(unsigned char data)
{
  PORTD = data;
  PORTB |= (1 << PB0); //RS = 1
  PORTB &= (~(1<<PB1)); //RW = 0
  PORTB |= (1<<PB2); // EN = 1
  _delay_ms(10);
  PORTB &= (~(1<<PB2)); //EN = 0;
}

//create a function to writing instructions 
void lcd_cmd(unsigned char command)
{
  PORTD = command;
  PORTB |= (1 << PB0); //RS = 1
  PORTB &= (~(1<<PB1)); //RW = 0
  PORTB |= (1<<PB2); // EN = 1
  _delay_ms(10);
  PORTB &= (~(1<<PB2)); //EN = 0;
}

//create a function to passing  string of data to LCD
void lcd_string(unsigned char *str, unsigned char length)
{
  char i = 0;
  for(i = 0; i < length; i++)
  {
    lcd_data(str[i]); //use lcd_data function inside a loop for passing string of data
  } 
}

void lcd_initialise()
{
  lcd_cmd(0x38); // set lcd to 16 column and 2 row format
  lcd_cmd(0x60); // auto incrementing the cursor of LCD
  lcd_cmd(0x0C); //display ON cursor OFF
  lcd_cmd(0x01); //clear screen
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd_cmd(0x80);
  lcd_string("Embedded", 8);
  lcd_cmd(0x10);
  lcd_string("SYSTEM", 7);
}
