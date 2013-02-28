#define VERSION "1.00a0"

int CAMERA = 1;
int GREEN = 10;
int RED = 12;


void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  // look for a capital D over the serial port and ring the bell if found
  if (Serial.available() > 0) {
    int input = Serial.read() - '0';
    if (input == CAMERA || input == CAMERA+3) {
     
      if(input >= 1 && input <= 3) {
        if(input == CAMERA){
          digitalWrite(RED, HIGH);
        } else {
          digitalWrite(RED, LOW);
        }
      }
      
      if(input >= 4 && input <= 6) {
        if(input == CAMERA + 3){
          digitalWrite(GREEN, HIGH);
        } else {
          digitalWrite(GREEN, LOW);
        }
      }
    } else {
      if(input >= 1 && input <= 3) {
        digitalWrite(RED, LOW);
      }
      
      if(input >= 4 && input <= 6) {
        digitalWrite(GREEN, LOW);
      }
    }
    
  }
}
