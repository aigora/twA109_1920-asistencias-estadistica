int sensorPin2 = 11;    // declaración del sensor interior conectado en el pin 11
int ledPin = 13;        // en el pin 13 se encuentra el LED que nos indica el periodo de calibración 
int sensorValue1 = 0;  // variable que se guarda, proviene del sensor exterior
int sensorValue2 = 0;  // variable que se guarda, proviene del sensor interior
int sensorMax = 0;           // valor máximo del sensor, parte del 0
int c=0;               // contador de personas 

const int EchoPin = 2;
const int TriggerPin = 3;

void setup() {
  // parte de el código que solo se procesa una vez:
  
 pinMode(TriggerPin, OUTPUT);
 pinMode(EchoPin, INPUT)
  
 pinMode(2, INPUT);// declaración del sensor exterior como entrada
 pinMode(11, INPUT);// declaración del sensor interior como entrada
 pinMode(ledpin, OUTPUT);       //declaracion del pin del LED que nos indica el periodo de calibración como salida
 digitalWrite(13, HIGH);    // al inicio del programa este LED aparecerá encendido, indicando que se inicia el periodo de calibración de distancia de los sensores
 Serial.begin(9600);    // configuración de serie
  // calibración durante los primeros 5 segundos desde el inicio del programa
  while (millis() < 5000) {
    sensorValue1 = ping(TriggerPin, EchoPin); // esta calibracion se realiza con  el sensor exterior

    // valor máximo captado por el sensor, se compara con el 0 elegido previamente(sensorMax) y a partir de ahi se reasigna segun lo que capta el sensor
    if (sensorValue1 > sensorMax) 
    {
      sensorMax = sensorValue1;
    }
  }
  // al finalizar la calibración , apagamos el LED del pin 13
  digitalWrite(13, LOW);
}

void loop() {
  // parte del código que se repite en bucle:
  
  int cm = 0;
  cm=ping(TriggerPin, EchoPin);
  //Serial.print("distancia: ");
  //Serial.println(cm);
  delay(500);
   
  sensorValue1 = cm;

  //Serial.println(c); // mostrar en pantalla el contador de personas
  
 if ( sensorValue1 < sensorMax-7)     // toda distancia detectada menor que el máximo de la calibracion con un margen de 7cm lo cuenta como una persona que pasa
  { 
    digitalWrite(13, HIGH);          // encender luz LED   
    Serial.println(1); // Imprime un 1 porque ha detectado que alguien pasa (c lee el uno e incrementa el contador)
    delay(500); //tiempo que se detiene tras pasar una persona
  }
  else
  {
    digitalWrite(13, LOW);           // apagar luz LED
  }
}

int ping (int TriggerPin, int EchoPin)
{
  long duration, distanceCm;
  
  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(4);
  digitalWrite(TriggerPin, LOW);
  
  duration = pulseIn(EchoPin, HIGH);
  distanceCm = duration * 10 / 292 / 2;
    return distanceCm;
}
