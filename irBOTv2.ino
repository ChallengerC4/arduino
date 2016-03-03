#include <IRremote.h>

int leftR = 6; // Right motor control 1 connected to pin 6
int leftF = 9; // Right motor control 2 connected to pin 9
int rightF = 10; // Left motor control 1 connected to pin 10
int rightR = 11; // Left motor control 2 connected to pin 11

int IRpin = 10; //sets up IR
IRrecv irrecv(IRpin);
decode_results results;

void setup(){
  Serial.begin(9600); //Starts the serial, allowing for debug outputs
  Serial.println("Beginning robot program:");
  irrecv.enableIRIn(); //enables the IR
  pinMode(leftR, OUTPUT);
  pinMode(leftF, OUTPUT);
  pinMode(rightR, OUTPUT);
  pinMode(rightF, OUTPUT);
}
                                                                                                                                                                    
void loop(){
  if(irrecv.decode(&results)){
      Serial.println(results.value, DEC);
      irrecv.resume();   // allows the IR to recieve the next value
  }

  if(results.value == 553536955){ //moves left motor
    results.value = 0;
    Serial.println("Moving left motor");
    analogWrite(leftF, 200);
    digitalWrite(leftR, LOW);
  }
  if(results.value == 3622325019){ //stops left motor
    results.value = 0;
    Serial.println("Stopping left motor");
    digitalWrite(leftF,LOW);
    digitalWrite(leftR, LOW);
  }
  if(results.value == 1386468383){ //revs left motor
    results.value = 0;
    Serial.println("Reversing left motor");
    digitalWrite(leftF, LOW);
    analogWrite(leftR, 200);
  }
  if(results.value == 16734885){ //moves right motor
    results.value = 0;
    Serial.println("Moving right motor");
    analogWrite(rightF, 200);
    digitalWrite(rightR, LOW);
  }
  if(results.value == 16726215){ //stops right motor
    results.value = 0;
    Serial.println("Stopping right motor");
    digitalWrite(rightF, LOW);
    digitalWrite(rightR, LOW);
  }
  if(results.value == 16716015){ //revs right motor
    results.value = 0;
    Serial.println("Reversing right motor");
    analogWrite(leftR, 200);
    digitalWrite(leftF, LOW);
  }
  if(results.value == 16756815){ //moves both motors
    results.value = 0;
    Serial.println("Moving both motors");
    analogWrite(leftF, 200);
    analogWrite(rightF, 200);
    digitalWrite(leftR, LOW);
    digitalWrite(rightR, LOW);
  }
  if(results.value == 16750695){ //stops both motors
    results.value = 0;
    Serial.println("Stopping both motors");
    digitalWrite(leftF, LOW);
    digitalWrite(leftR, LOW);
    digitalWrite(rightR, LOW);
    digitalWrite(rightF, LOW);
  }
  if(results.value == 16738455){ //revs both motors
    results.value = 0;
    Serial.println("Reversing both motors");
    analogWrite(leftR, 200);
    analogWrite(rightR, 200);
    digitalWrite(rightF, LOW);
    digitalWrite(leftF, LOW);
  }
}

//POWR=16753245 MODE=16736925 MUTE=16769565
//PLAY=16720605 BACK=16712445 FWRD=16761405
//EQZR=16769055 MNUS=16754775 PLUS=16748655
//ZERO=16738455 SWCH=16750695 U/SD=16756815
//OONE=16724175 TTWO=16718055 THRE=16743045
//FOUR=16716015 FIVE=16726215 SSIX=16734885
//SEVN=16728765 EIGH=16730805 NINE=16732845

//BEFORE= 4294967295
