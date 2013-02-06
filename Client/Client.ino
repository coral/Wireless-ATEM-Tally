/*****************
 * Wirless Tally for ATEM
 * Client file
 * authors: coral
 * library and example: kasper skaarhoj
 */

//Define the LED pins
int RED = 7;
int GREEN = 6;
int CAMERA_NUMBER = 1;
void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //fix tally here 
}
