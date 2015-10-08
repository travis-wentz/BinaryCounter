/*
  Travis Wentz
  Lights up diodes to count in binary
 */

void setup() {                
  for(int pin = 6; pin < 14; pin++)
    pinMode(pin, OUTPUT);             //sets all the pins being used to output
}

void loop(){
  for (int i = 0; i < 256; i++){    //loops through the actual number to be displayed
    for (int j = 0; j < 8; j++){    //loops through the diodes that display the current number
      if((i >> j) & 1)              //takes the current number, bit shifts to the least sig digit, then the next least and so on
        digitalWrite(j + 6, HIGH);  //if it's a 1, the diode turns on
      else
        digitalWrite(j + 6, LOW);   //else it doesn't
    }
    delay(100);                     //1/10th of a second delay between each num displayed
  }
  dance();
}

//now make the lights do a victory dance!
void dance(){
  for(int x = 6; x < 14; x++){
    digitalWrite(x, HIGH);
  }
  for(int y = 0; y < 4; y++){
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    delay(100);
    digitalWrite(8, LOW);
    digitalWrite(11, LOW);
    delay(100);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    delay(100);
    digitalWrite(8, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(13, LOW);
    delay(100);
    digitalWrite(7, HIGH);
    digitalWrite(12, HIGH);
    delay(100);
    digitalWrite(6, HIGH);
    digitalWrite(13, HIGH);
  }
  delay(3000);
}


