int sensorPin1 = A0;    // select the input pin for the sensor
int sensorPin2 = A1;    // select the input pin for the sensor
int sensorValue1 = 0;  // variable que se guarda, proviene del sensor exterior
int sensorValue2 = 0;  // variable que se guarda, proviene del sensor interior

void setup() {
  // parte de el código que solo se procesa una vez:
 pinMode(sensorPin1, INPUT);
 pinMode(sensorPin2, INPUT);
}


void loop() {
  // parte del código que se repite en bucle:
  sensorValue = analogRead(sensorPin1);
  sensorValue = analogRead(sensorPin2);

  

}
