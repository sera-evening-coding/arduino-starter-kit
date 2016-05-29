const int sensorPin = A0;
const float baselineTemp = 24.0;

void setup () {
  Serial.begin(9600); //opens a serial port
  
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber,OUTPUT); // initializing the pins
    digitalWrite(pinNumber,LOW); // setting them to off
  }
}

void loop () {
  // reads the temperature
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value ");
  Serial.print(sensorVal);
  
  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // convert voltage to temperature in celcius  
  float temperature = (voltage - 0.5) * 100;
  Serial.print(", degrees: ");
  Serial.print(temperature);
  
  if(temperature < baselineTemp + 2){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  } else if(temperature >= baselineTemp + 2 &&
    temperature < baselineTemp + 4) {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  } else if(temperature >= baselineTemp + 4 &&
    temperature < baselineTemp + 6) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
  } else if(temperature >= baselineTemp + 6) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }
    
  Serial.print("\n");
  delay(500);
}
