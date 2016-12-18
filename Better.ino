#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include "mainPage.h"


const int Load1=16;
const int Load2=15;
const int Load3=14;
const int Load4=12;
const int Load5=13;

ESP8266WebServer server(80);
String L1Status,L2Status,L3Status,L4Status,L5Status,Temperature;
 String IP,Signal,mac;
void handleRoot() {
  String s = MAIN_page;    
  s.replace("@@L1@@", L1Status);
  s.replace("@@L2@@", L2Status);
  s.replace("@@L3@@", L3Status);
  s.replace("@@L4@@", L4Status);
  s.replace("@@L5@@", L5Status);
  s.replace("@@IP@@",IP);
  s.replace("@@Signal@@",Signal);
  s.replace("@@mac@@",mac);
  s.replace("@@TEMP@@", Temperature);
  s+= "<meta name=\"viewport\" content=\"width=device-width, height=device-height\">\r\n";
  server.send(200, "text/html", s);     
}
//=======================================================================
//                    LOAD on setup
//=======================================================================
void handleForm() {
  String t_state = server.arg("submit");
  Temperature = String(analogRead(A0)/10);   

  
  if(t_state=="ON1")
            {
               
                             L1Status="ON";    
                             digitalWrite(Load1, HIGH);
                            
              }
  
  if(t_state=="OFF1")
                 {
                  L1Status="OFF";    
                   digitalWrite(Load1, LOW);      //Load1 Turned off  
                 }
//Change Load-2 State as per request

  if(t_state=="ON2")
                {
                 
                             L2Status="ON";    
                             digitalWrite(Load2, HIGH);
                             
               }
  
  if(t_state=="OFF2")
                  {
                   L2Status="OFF";    
                   digitalWrite(Load2, LOW);      //Load1 Turned off  
                   }
//Change Load-3 State as per request

  if(t_state=="ON3")
                 {
                  
                             L3Status="ON";    
                             digitalWrite(Load3, HIGH);
                           
                       }
  
  if(t_state=="OFF3")
                   {
                    L3Status="OFF";    
                     digitalWrite(Load3, LOW);      //Load1 Turned off  
                     }
//Change Load-4 State as per request

  if(t_state=="ON4")
                 {
                   
                                  L4Status="ON";    
                                  digitalWrite(Load4, HIGH);
                                 
                     }
  
  
  if(t_state=="OFF4")
                {
                   L4Status="OFF";    
                   digitalWrite(Load4, LOW);      //Load1 Turned off  
                 }
                 
  //Change Load-4 State as per request
   if(t_state=="Enable")
                    {
                       L5Status="Enable";   
                       digitalWrite(Load5, HIGH);       //Load1 Turned on
                    }
  
  if(t_state=="Disable")
                   {
                     L5Status="Disable";
                     digitalWrite(Load5, LOW);      //Load1 Turned off  
                   }


  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "Updated-- Press Back Button");  //This Line Keeps It on Same Page
   
  delay(500);
}
//=======================================================================
//                    Power on setup
//=======================================================================

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(Load1, OUTPUT);
  pinMode(Load2, OUTPUT);
  pinMode(Load3, OUTPUT);
  pinMode(Load4, OUTPUT); 
  pinMode(Load5, OUTPUT); 
  IPAddress myIP = WiFi.softAPIP();
  server.on("/", handleRoot);
  server.on("/form", handleForm); 
   server.begin();
} 
void loop(){
  server.handleClient();
   IP= int (WiFi.softAPIP());
   Signal=WiFi.RSSI();
   mac= WiFi.macAddress();
  }
