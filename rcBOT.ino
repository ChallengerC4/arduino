#include <AFMotor.h>
#include <IRremote.h>


AF_DCMotor m1(1); //sets placement and signal
AF_DCMotor m2(2);

int IRpin = 10; //sets up IR
IRrecv irrecv(IRpin);
decode_results results;

void setup(){
  Serial.begin(9600); //Starts the serial, allowing for debug outputs
  Serial.println("Beginning robot program:");

  irrecv.enableIRIn(); //enables the IR
  
  m1.setSpeed(200); //setup for the Motors
  m2.setSpeed(200);

}
                                                                                                                                                                    
void loop(){
  if(irrecv.decode(&results)){
      Serial.println(results.value, DEC);
      irrecv.resume();   // allows the IR to recieve the next value
  }

  if(results.value == 553536955){ //moves left motor
    results.value = 0;
    Serial.println("Moving left motor");
    m1.run(FORWARD);
  }
  if(results.value == 3622325019){ //stops left motor
    results.value = 0;
    Serial.println("Stopping left motor");
    m1.run(RELEASE);
  }
  if(results.value == 1386468383){ //revs left motor
    results.value = 0;
    Serial.println("Reversing left motor");
    m1.run(BACKWARD);
  }
  if(results.value == 16734885){ //moves right motor
    results.value = 0;
    Serial.println("Moving right motor");
    m2.run(FORWARD);
  }
  if(results.value == 16726215){ //stops right motor
    results.value = 0;
    Serial.println("Stopping right motor");
    m2.run(RELEASE);
  }
  if(results.value == 16716015){ //revs right motor
    results.value = 0;
    Serial.println("Reversing right motor");
    m2.run(BACKWARD);
  }
  if(results.value == 16756815){ //moves both motors
    results.value = 0;
    Serial.println("Moving both motors");
    m1.run(FORWARD);
    m2.run(FORWARD);
  }
  if(results.value == 16750695){ //stops both motors
    results.value = 0;
    Serial.println("Stopping both motors");
    m1.run(RELEASE);
    m2.run(RELEASE);
  }
  if(results.value == 16738455){ //revs both motors
    results.value = 0;
    Serial.println("Reversing both motors");
    m1.run(BACKWARD);
    m2.run(BACKWARD);
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


