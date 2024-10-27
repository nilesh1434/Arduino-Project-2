// Nilesh Jain - 653929943
// Lab 2 - Input and Output - counting in binary
// This code is supposed to blink 3 LED lights with the maximum number of combinations (here in this case it is 7)
// Youtube link - https://youtu.be/mqPyIRJIpOY

// all 2 buttons
int Button1 = 2;
int Button2 = 3;

// checks if Buttons are pressed or not
int read1 = LOW;
int read2 = LOW;

// all 3 LEDs
int LED1 = 8;
int LED2 = 9;
int LED3 = 10;

// checks if LED is on or off
bool ledOn1 = false;
bool ledOn2 = false;

int ButtonValue = 0;
int index  = 0;


void setup() {
  // inputs
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);

  // outputs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // checks for buttons pressed
  read1 = digitalRead(Button1);
  read2 = digitalRead(Button2);

  // LEDs are off
  ledOn1 = false;
  ledOn2 = false;

  // button 1
  if (read1 != LOW) {
    index--;
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    
    while (!ledOn2) {
      if (digitalRead(Button1) == LOW)
        ledOn2 = true;
    }
  }

  // button 2
  if (read2 != LOW) {
    index++;
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    
    while (!ledOn1) {
      if (digitalRead(Button2) == LOW)
        ledOn1 = true;
    }
  }

  // updates the button value to new index value
  ButtonValue = index;

  if (index == 8) {
    ButtonValue = 0;
    index = 0;
  } else if (index == -1) {
    ButtonValue = 7;
    index = 7;
  }

  // check for LED3 remainder of 4
  int count4th = ButtonValue / 4;
   if (count4th == 1) {
    digitalWrite(LED3, HIGH);
    ButtonValue %= 4;
    Serial.println("4");
  }

  // check for LED2 remainder of 2
  int count2nd = ButtonValue / 2;
  if (count2nd == 1) {
    digitalWrite(LED2, HIGH);
    ButtonValue %= 2;
    Serial.println("2");
  }

  // check for LED 1 remainder of 1
  int count1st = ButtonValue / 1;
  if (count1st == 1) {
    digitalWrite(LED1, HIGH);
    ButtonValue %= 1;
    Serial.println("1");
  }
  
}
