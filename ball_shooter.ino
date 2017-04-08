const int trigPin = 2;//sensor
const int echoPin = 4;//sensor

void setup(){
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);// sensor
}
//ultrasonic sensor part
float trigger() {
     float duration;
     pinMode(trigPin, OUTPUT);
     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
     digitalWrite(trigPin, HIGH);
     delayMicroseconds(10);
     digitalWrite(trigPin, LOW);
     pinMode(echoPin, INPUT);
     duration = pulseIn(echoPin, HIGH);
     return(duration);
 

      
}
void loop(){
    long duration, cm;
    duration = trigger();
    inches = duration / 74 / 2;
    cm = (duration/29)/2;
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    delay(1000);
    if(cm>50){
    analogWrite(13,255);
    analogWrite(12,0);
    analogWrite(11,255);
    analogWrite(10,0);   
    
else if(cm>10){
   analogWrite(13,127);
    analogWrite(12,0);
    analogWrite(11,127);
    analogWrite(10,0);
}
else if(cm>30){
   analogWrite(13,63);
    analogWrite(12,0);
    analogWrite(11,63);
    analogWrite(10,0);
}
else {
   analogWrite(13,31);
    analogWrite(12,0);
    analogWrite(11,31);
    analogWrite(10,0);
}
}


