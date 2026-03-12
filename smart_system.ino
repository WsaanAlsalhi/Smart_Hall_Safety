#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// PIR & Lights
int pirPin = 3;
int lightPin = 4;

// Exit Lights
int exitLights[6] = {6,7,8,9,10,13};

// Color Sensor
int S2 = 11;
int S3 = 12;
int colorOut = A1;

// MQ-2 Smoke
int mq2Pin = A0;
int buzzerPin = 5; // Fire Alarm

int peopleCount = 0;

void setup(){
  Serial.begin(9600);
  dht.begin();

  pinMode(pirPin, INPUT);
  pinMode(lightPin, OUTPUT);

  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(colorOut, INPUT);

  for(int i=0;i<6;i++){
    pinMode(exitLights[i], OUTPUT);
  }

  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
}

void loop(){
  delay(2000);

  // Temperature & Humidity
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if(isnan(temp) || isnan(hum)){
    Serial.println("DHT Sensor Error");
  } else {
    Serial.print("Temperature: "); Serial.print(temp); Serial.println(" C");
    Serial.print("Humidity: "); Serial.print(hum); Serial.println(" %");
  }

  // PIR Motion
  int motion = digitalRead(pirPin);
  if(motion == HIGH){
    Serial.println("Motion Detected: People inside the hall");
    digitalWrite(lightPin,HIGH);
    delay(5000);
    digitalWrite(lightPin,LOW);
  }

  // Color Sensor
  // Blue card = count people
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  int blue = analogRead(colorOut);
  if(blue < 200){
    peopleCount++;
    Serial.print("Blue Card Detected - People Count: ");
    Serial.println(peopleCount);
    delay(2000);
  }

  // Green card = Admin
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  int green = analogRead(colorOut);
  if(green < 200){
    Serial.println("Admin Card Detected - Door Action Skipped");
    delay(3000);
  }

  // MQ-2 Smoke
  int smokeValue = analogRead(mq2Pin);
  Serial.print("Smoke Level: "); Serial.println(smokeValue);
  if(smokeValue > 500){
    Serial.println("Fire Smoke Detected - Alarm ON");

    // Buzzer ON
    digitalWrite(buzzerPin, HIGH);

    // Exit Lights sequential blink
    for(int i=0;i<6;i++){
      digitalWrite(exitLights[i], HIGH);
      delay(300);
      digitalWrite(exitLights[i], LOW);
    }

    // Buzzer OFF
    digitalWrite(buzzerPin, LOW);
  }
}