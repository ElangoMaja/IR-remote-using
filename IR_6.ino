#include <IRremoteESP8266.h>
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);           
decode_results results; 
int ledPin_1=16;
int ledPin_2=15;
//int ledPin_i=13;
//int ledPin_u=12;
//int ledPin_y=5;
//int ledPin_t=4;
int ledState_1= 0;
int ledState_2= 0;
//int ledState_i= 0;
//int ledState_u= 0;
//int ledState_y= 0;
//int ledState_t= 0;
int i=0;
void setup()  
{ pinMode(ledPin_1, OUTPUT);
  pinMode(ledPin_2, OUTPUT);
  /*pinMode(ledPin_i, OUTPUT);
  pinMode(ledPin_u, OUTPUT);
  pinMode(ledPin_y, OUTPUT);
  pinMode(ledPin_t, OUTPUT);

  */digitalWrite(ledPin_1, LOW);
  digitalWrite(ledPin_2, LOW);
  /*digitalWrite(ledPin_i, LOW);
  digitalWrite(ledPin_u, LOW);
  digitalWrite(ledPin_y, LOW);
  digitalWrite(ledPin_t, LOW);
  */Serial.begin(9600);
  irrecv.enableIRIn(); 

}
void loop()  
{
  if (irrecv.decode(&results)) 
  {
    translateIR(); 
    irrecv.resume(); 
  }  
}
void translateIR() 
{
 switch(results.value)
 {

  case 0xF16E011F:  if(ledState_1==0){ //if the LED is off, It will turn on
          Serial.println("Turns ON the LED Selected");
          digitalWrite(ledPin_1, HIGH);  //sets the LED on
          ledState_1=1;                  //updates the LED state
        }
        else{
          Serial.println("Turns OFF the LED Selected"); //else: the LED is on, It will turn off
          digitalWrite(ledPin_1, LOW);   //sets the LED off
          ledState_1=0;                  //updates the LED state
        }   ;break;
        case 0x4913289B:  if(ledState_2==0){ //if the LED is off, It will turn on
          Serial.println("Turns ON the LED Selected");
          digitalWrite(ledPin_2, HIGH);  //sets the LED on
          ledState_2=1;                  //updates the LED state
        }
        else{
          Serial.println("Turns OFF the LED Selected"); //else: the LED is on, It will turn off
          digitalWrite(ledPin_2, LOW);   //sets the LED off
          ledState_2=0;                  //updates the LED state
        }   ;
       /* case 0x835150FB:  if(ledState_i==0){ //if the LED is off, It will turn on
          Serial.println("Turns ON the LED Selected");
          digitalWrite(ledPin_i, HIGH);  //sets the LED on
          ledState_i=1;                  //updates the LED state
        }
        else{
          Serial.println("Turns OFF the LED Selected"); //else: the LED is on, It will turn off
          digitalWrite(ledPin_i, LOW);   //sets the LED off
          ledState_i=0;                  //updates the LED state
        }   ;
        case 0x8E45A9BF:  if(ledState_u==0){ //if the LED is off, It will turn on
          Serial.println("Turns ON the LED Selected");
          digitalWrite(ledPin_u, HIGH);  //sets the LED on
          ledState_u=1;                  //updates the LED state
        }
        else{
          Serial.println("Turns OFF the LED Selected"); //else: the LED is on, It will turn off
          digitalWrite(ledPin_u, LOW);   //sets the LED off
          ledState_u=0;                  //updates the LED state
        }   ;
        case 0x3C76279B:  if(ledState_y==0){ //if the LED is off, It will turn on
          Serial.println("Turns ON the LED Selected");
          digitalWrite(ledPin_y, HIGH);  //sets the LED on
          ledState_y=1;                  //updates the LED state
        }
        else{
          Serial.println("Turns OFF the LED Selected"); //else: the LED is on, It will turn off
          digitalWrite(ledPin_y, LOW);   //sets the LED off
          ledState_y=0;                  //updates the LED state
        }   ;
        case 0xA83875F:  if(ledState_t==0){ //if the LED is off, It will turn on
          Serial.println("Turns ON the LED Selected");
          digitalWrite(ledPin_t, HIGH);  //sets the LED on
          ledState_t=1;                  //updates the LED state
        }
        else{
          Serial.println("Turns OFF the LED Selected"); //else: the LED is on, It will turn off
          digitalWrite(ledPin_t, LOW);   //sets the LED off
          ledState_t=0;                  //updates the LED state
        }   ;
         */
  default: 
    Serial.println(" other button   ");
  }

  delay(500); 

}

