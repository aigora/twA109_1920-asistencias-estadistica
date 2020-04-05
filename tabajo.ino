int sensorPin1 = A0;    // select the input pin for the sensor
int sensorPin2 = A1;    // select the input pin for the sensor
int ledPin = 13;        // pin al LED que nos indica el periodo de calibración de los sensores esta sucediendo
int sensorValue1 = 0;  // variable que se guarda, proviene del sensor exterior
int sensorValue2 = 0;  // variable que se guarda, proviene del sensor interior
int sensorMin = 1023;        // valor mínimo del sensor 
int sensorMax = 0;           // valor máximo del sensor

void setup() {
  // parte de el código que solo se procesa una vez:
 pinMode(sensorPin1, INPUT);
 pinMode(sensorPin2, INPUT);
 pinMode(13, OUTPUT); //declaracion del pin del LED que nos indica el periodo de calibración
 digitalWrite(13, HIGH); // al inicio del programa este LED aparecerá encendido, indicando que se inicia el periodo de calibración de distancia de los sensores
  // calibración durante los primeros 5 segundos desde el inicio del programa
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin1); // esta calibracion se realiza con  el sensor exterior

    // valor máximo captado por el sensor
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // valor mínimo captado por el sensor
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  // al finalizar la calibración , apagamos el LED del pin 13
  digitalWrite(13, LOW);

}


void loop() {
  // parte del código que se repite en bucle:
  sensorValue = analogRead(sensorPin1);
  
    // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);

  // el LED se ilumina conforme a la calibración captada previamente
  analogWrite(ledPin, sensorValue);

  

}
