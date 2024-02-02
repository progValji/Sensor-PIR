class Alarma{
  private:
     int pinBuzzer;

  public:
     Alarma(int pinBuzzer) :pinBuzzer(pinBuzzer){
      pinMode(pinBuzzer,OUTPUT);
     }

     void activarAlarma(){
      tone(pinBuzzer, 440);
     }

     void desactivarAlarma(){
      noTone(pinBuzzer);
     }
};

#define boton 7
Alarma miAlarma(3);
int sensor = 2;

void setup() {
  Serial.begin(9600);
  pinMode(boton,INPUT_PULLUP);
  pinMode(13,OUTPUT);
  pinMode(sensor,INPUT);
  delay(20000);
  Serial.println("Todo listo");
}

void loop() {
  if(digitalRead(sensor) == HIGH){
    digitalWrite(13,HIGH); delay(1000); digitalWrite(13,LOW);

    while(digitalRead(boton) == HIGH){
      miAlarma.activarAlarma();
    }
    miAlarma.desactivarAlarma();
  }
}