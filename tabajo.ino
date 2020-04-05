int sensorPin1 = A0;    // select the input pin for the sensor
int sensorPin2 = A1;    // select the input pin for the sensor
int ledPin = 13;        // pin al LED que nos indica el periodo de calibración de los sensores esta sucediendo
int sensorValue1 = 0;  // variable que se guarda, proviene del sensor exterior
int sensorValue2 = 0;  // variable que se guarda, proviene del sensor interior
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;           // maximum sensor value

void setup() {
  // parte de el código que solo se procesa una vez:
 pinMode(sensorPin1, INPUT);
 pinMode(sensorPin2, INPUT);
 pinMode(13, OUTPUT); //declaracion del pin del LED que nos indica el periodo de calibración
 digitalWrite(13, HIGH); // al inicio del programa este LED aparecerá encendido, indicando que se inicia el periodo de calibración de distancia de los sensores
  // calibración durante los primeros 5 segundos desde el inicio del programa
  while (millis() < 5000) {
    sensorValue1 = analogRead(sensorPin1); // esta calibracion se realiza con  el sensor exterior

    // record the maximum sensor value
    if (sensorValue1 > sensorMax) 
    {
      sensorMax = sensorValue1;
    }

    // record the minimum sensor value
    if (sensorValue1 < sensorMin) 
    {
      sensorMin = sensorValue1;
    }
  }

  // al finalizar la calibración , apagamos el LED del pin 13
  digitalWrite(13, LOW);
}


void loop() {
  // parte del código que se repite en bucle:
  sensorValue1 = analogRead(sensorPin1);
  
  Serial.println(sensorValue1);
   
    
  // apply the calibration to the sensor reading
  sensorValue1 = map(sensorValue1, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue1 = constrain(sensorValue1, 0, 255);

  // fade the LED using the calibrated value:
  analogWrite(ledPin, sensorValue1);

  
} 

