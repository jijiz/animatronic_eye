i#include <Servo.h>
Servo paupiere_h, mvt_vertical, mvt_horizontal, paupiere_b, mano;

const int trigPin = 7;
const int echoPin = 6;

const int i_paupiere_b_fermee = 35;
const int i_paupiere_b_ouverte = 0; 
const int i_paupiere_h_fermee = i_paupiere_b_ouverte;
const int i_paupiere_h_ouverte = i_paupiere_b_fermee; 
const int i_horizontal_max = 60;
const int i_vertical_max = 60;
const int i_min_movement = 20;
long duration;
int distance;


void setup() {
   // Configuration pins
   paupiere_h.attach(1);
   mvt_vertical.attach(2);
   mvt_horizontal.attach(3);
   paupiere_b.attach(4);
   mano.attach(5);
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
   pinMode(echoPin, INPUT); // Sets the echoPin as an Input

   // Init position
   ouvrir_bas();
   ouvrir_haut();
   vertical_milieu();
   ouvrir_main();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  if (distance < 30) {
    fermer_main();
  }else{
    ouvrir_main();
  }
 
  
  horizontal_random();

  vertical_random();
  
  int i_rand = random(0,13);
  if (i_rand == 1){
    cligner();
  } else if (i_rand == 2){
    cligner();
    delay(50);
    cligner();
  }
  delay(random (200, 330));
}

void ouvrir_main(){
  mano.write(90);
}

void fermer_main(){
  mano.write(0);
}

void horizontal_random(){
mvt_horizontal.write(random(0, i_horizontal_max));
}

void vertical_random(){
mvt_vertical.write(random(0, i_horizontal_max));
}

void horizontal_gauche(){
  mvt_horizontal.write(0);
}

void horizontal_milieu(){
  mvt_horizontal.write(i_horizontal_max/2);
}

void horizontal_droit(){
  mvt_horizontal.write(i_horizontal_max);
}

void vertical_milieu(){
  mvt_vertical.write(i_vertical_max/2);
}

void vertical_bas(){
  mvt_vertical.write(0);
}

void vertical_haut(){
  mvt_vertical.write(i_vertical_max);
}

void fermer_bas(){
  paupiere_b.write(i_paupiere_b_fermee);
}

void fermer_haut(){
  paupiere_h.write(i_paupiere_h_fermee);
}

void fermer(){
  fermer_haut();
  fermer_bas();
}

void ouvrir(){
  ouvrir_haut();
  ouvrir_bas();
}

void cligner(){
  fermer();
  delay(100);
  ouvrir();
}

void ouvrir_bas(){
  paupiere_b.write(i_paupiere_b_ouverte);
}

void ouvrir_haut(){
  paupiere_h.write(i_paupiere_h_ouverte);
}
