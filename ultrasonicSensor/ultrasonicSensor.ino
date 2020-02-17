/*
    This sketch demonstrates how to set up a simple HTTP-like server.
    The server will set a GPIO pin depending on the request
      http://server_ip/gpio/0 will set the GPIO2 low,
      http://server_ip/gpio/1 will set the GPIO2 high
    server_ip is the IP address of the ESP8266 module, will be
    printed to Serial when the module is connected.
*/

const int trigPin = 30;
const int echoPin = 31;

const int trigPinback = 33;
const int echoPinback = 32;

long duration;
int distance;

long durationback;
int distanceback;

void setup() 
{
  Serial.begin(9600);
  delay(1000);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input

  pinMode(trigPinback, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinback, INPUT);  // Sets the echoPin as an Input
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);

  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  distance= duration*0.034/2;
  
  Serial.print("Distance: "); 
  Serial.println(distance);

  digitalWrite(trigPinback, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPinback, HIGH);
  delayMicroseconds(2);
  
  digitalWrite(trigPinback, LOW);
 
  durationback = pulseIn(echoPinback, HIGH);
  
  distanceback=durationback*0.034/2;
  
  Serial.print("Distance back: "); 
  Serial.println(distanceback);
  
  delay(1000);
}
