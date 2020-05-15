int sensorPin1 = 2;    // declaración del sensor exterior conectado en el analógico 0
int sensorPin2 = 11;    // declaración del sensor interior conectado en el analógico 1
int ledPin = 13;        // en el pin 13 se encuentra el LED que nos indica el periodo de calibración 
int sensorValue1 = 0;  // variable que se guarda, proviene del sensor exterior
int sensorValue2 = 0;  // variable que se guarda, proviene del sensor interior
int sensorMax = 0;           // valor máximo del sensor, parte del 0
int c=0;               // contador de personas 
const int ButtonPin = 2;

void setup() {
  // parte de el código que solo se procesa una vez:
 pinMode(2, INPUT);// declaración del sensor exterior como entrada
 pinMode(11, INPUT);// declaración del sensor interior como entrada
 pinMode(13, OUTPUT);       //declaracion del pin del LED que nos indica el periodo de calibración como salida
 digitalWrite(13, HIGH);    // al inicio del programa este LED aparecerá encendido, indicando que se inicia el periodo de calibración de distancia de los sensores
  
  // calibración durante los primeros 5 segundos desde el inicio del programa
  while (millis() < 5000) {
    sensorValue1 = analogRead(sensorPin1); // esta calibracion se realiza con  el sensor exterior

    // valor máximo captado por el sensor, se compara con el 0 elegido previamente(sensorMax) y a partir de ahi se reasigna segun lo que capta el sensor
    if (sensorValue1 > sensorMax) 
    {
      sensorMax = sensorValue1;
    }
  }

  // al finalizar la calibración , apagamos el LED del pin 13
  digitalWrite(13, LOW);
 
  Serial.begin(9600);
 pinMode(ButtonPin, INPUT);

}


void loop() {
  // parte del código que se repite en bucle:
  sensorValue1 = analogRead(sensorPin1);

  Serial.println(c); // mostrar en pantalla el contador de personas
  
 if ( sensorValue1 < sensorMax-50)     // toda distancia detectada menor que el máximo de la calibracion con un margen de 50 mm lo cuenta como una persona que pasa
  { 
    digitalWrite(13, HIGH);          // encender luz LED   
    c++; // incremento del contador
    delay(500); //tiempo que se detiene tras pasar una persona
  }
  else
  {
    digitalWrite(13, LOW);           // apagar luz LED
  }
}  
  char dato;
 dato = digitalRead(ButtonPin); //lectura digital de pin
 //Configurado con resistencia de pull-up 0=Pulsado
 if (dato == LOW)
 {
 Serial.println("Pulsado");
 }
  delay (200);
} 
