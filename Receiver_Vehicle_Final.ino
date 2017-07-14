 #define rfReceivePin A0  //RF Receiver pin = Analog pin 0
 #define buzzerPin 11  //Onboard LED = digital pin 13
 #define lbeam 4
 #define hbeam 7

 unsigned int data = 0;   // variable used to store received data
 const unsigned int upperThreshold = 40;  //upper threshold value
 const unsigned int lowerThreshold = 30;  //lower threshold value

 void setup(){
   pinMode(buzzerPin, OUTPUT);
   pinMode(hbeam, OUTPUT);
   pinMode(lbeam, OUTPUT);
   Serial.begin(9600);
 }

 void loop(){
   analogWrite(buzzerPin, 0);
   data=analogRead(rfReceivePin);    //listen for data on Analog pin 0
   
    if(data>upperThreshold){
     digitalWrite(lbeam,HIGH);   //If a LOW signal is received, turn LED OFF
     digitalWrite(hbeam,LOW);
     analogWrite(buzzerPin, 250);
     Serial.println(data);
     delay(1000);
   }
   
   if(data<lowerThreshold){
     digitalWrite(hbeam, HIGH);   //If a HIGH signal is received, turn LED ON
     digitalWrite(lbeam,LOW);
     analogWrite(buzzerPin, 0);
     Serial.println(data);
     delay(1000);
   }
 }
 
