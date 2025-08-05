//Dharani creations
//Alcohol Detector
const int MQ3=0;
const int Buzzer=8;
const int LED=9;
int value;

void setup() {
  Serial.begin(9600);
  pinMode(MQ3, INPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(Buzzer,LOW);
  digitalWrite(LED,LOW);

}

void loop()
{
  value= analogRead(MQ3);
  Serial.println(value);
  
  if(value>440)
  {
    digitalWrite(Buzzer,HIGH);
    digitalWrite(LED,HIGH);
  }else{
    digitalWrite(Buzzer,LOW);
    digitalWrite(LED,LOW);
  }

  delay (500);
}
