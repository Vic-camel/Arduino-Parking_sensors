#define TRIGPIN 2
#define ECHOPIN 3
unsigned long a;

int red=6;
int blue=9;
int green=10;


float ping(){
    digitalWrite(TRIGPIN,LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGPIN,HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGPIN,LOW);
    return pulseIn(ECHOPIN,HIGH)*0.017;    

}

void setup() {
    Serial.begin(9600);
    pinMode(TRIGPIN,OUTPUT);
    pinMode(ECHOPIN,INPUT);
    
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);

    pinMode(6,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);

}

void loop() {

   
    float mmm = ping();
    Serial.print("now distance: ");
    Serial.print(mmm);
    Serial.print(" cm");
    
    if(mmm >100){
         Serial.println(" ; SAFE");
         while(1){
         float mmm = ping();
         Serial.print("now distance: ");
         Serial.print(mmm);
         Serial.println(" cm");
         digitalWrite(green,HIGH);
         
         if(mmm <100)break;
         }
       
    }


    if(80 < mmm && mmm <= 100){
         Serial.println(" ; Careful ");
         while(1){
         float mmm = ping();
         Serial.print("now distance: ");
         Serial.print(mmm);
         Serial.println(" cm");
         
         digitalWrite(green,HIGH);
         digitalWrite(red,HIGH);
         
         
         tone(12,2000,750);
         delay(150);
         noTone(12);
      
         
         if(100 <mmm || mmm <= 80)break;
         }
    }
    if(30 < mmm && mmm <= 80){

         
         Serial.println(" ; Warning");
         while(1){
         float mmm = ping();
         Serial.print("now distance: ");
         Serial.print(mmm);
         Serial.println(" cm");
         
         digitalWrite(green,HIGH);
         digitalWrite(red,HIGH);
       
           
         tone(12,5000,750);
         delay(50);
         noTone(12);
         
         if(80 <mmm || mmm <= 30 )break;
         }

    }

    if(mmm <= 30){

         unsigned long a=0;
         unsigned long b=0;
         a=millis();
         
         Serial.println(" ; Danger");
         while(1){
         float mmm = ping();
         Serial.print("now distance: ");
         Serial.print(mmm);
         Serial.println(" cm");
         
         digitalWrite(red,HIGH);
         tone(12,8000,750);
         delay(10);
         /*
         if(a-b >1000){
         digitalWrite(red,LOW);
         delay(500);
         noTone(12);
         delay(500);
         b=a;
         }
         /*
         tone(12,8000,750);
         delay(50);
         noTone(12);
         
         a=b;
         */
         
        
         noTone(12);
         
         
         if(mmm > 30)break;
         }

    }

    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    noTone(12);
    
}
