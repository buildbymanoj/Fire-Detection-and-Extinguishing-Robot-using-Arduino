#define enA 10 // Enable1 L298 Pin enA
#define in1 9  // Motor1 L298 Pin in1
#define in2 8  // Motor1 L298 Pin in2
#define in3 7  // Motor2 L298 Pin in3
#define in4 6  // Motor2 L298 Pin in4
#define enB 5  // Enable2 L298 Pin enB
#define ir_R A0
#define ir_F A1
#define ir_L A2
#define servo 3
#define pump A5

int Speed = 160; // Duty Cycle 0 to 255 Enable for Motor Speed
int s1, s2, s3;

void setup() {
  Serial.begin(9600); // Start serial communication at 9600bps
  pinMode(ir_R, INPUT); pinMode(ir_F, INPUT); pinMode(ir_L, INPUT);
  pinMode(enA, OUTPUT); pinMode(in1, OUTPUT); pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT); pinMode(in4, OUTPUT); pinMode(enB, OUTPUT);
  pinMode(servo, OUTPUT); pinMode(pump, OUTPUT);

  for (int angle = 90; angle <= 140; angle += 5) servoPulse(servo, angle);
  for (int angle = 140; angle >= 40; angle -= 5) servoPulse(servo, angle);
  for (int angle = 40; angle <= 95; angle += 5) servoPulse(servo, angle);

  analogWrite(enA, Speed); analogWrite(enB, Speed);
  delay(500);
}

void loop() {
  s1 = analogRead(ir_R);
   s2 = analogRead(ir_F); 
   s3 = analogRead(ir_L);

  Serial.print(s1);
   Serial.print("\t"); 
   Serial.print(s2); 
   Serial.print("\t");
    Serial.println(s3);
    
  delay(50);

  if(s2 < 200) {
    Stop(); 
    digitalWrite(pump, 0);
    for(int angle = 90; angle >= 40; angle -= 3) servoPulse(servo, angle);
    for(int angle = 40; angle <= 90; angle += 3) servoPulse(servo, angle);
  } else if(s1 < 100) {
    Stop(); 
    digitalWrite(pump, 0);
    for(int angle = 90; angle <= 140; angle += 3) servoPulse(servo, angle);
    for(int angle = 140; angle >= 40; angle -= 3) servoPulse(servo, angle);
    for(int angle = 40; angle <= 90; angle += 3) servoPulse(servo, angle);
  } else if(s3 < 100) {
    Stop();
     digitalWrite(pump, 0);
    for(int angle = 90; angle <= 140; angle += 3) servoPulse(servo, angle);
    for(int angle = 140; angle >= 90; angle -= 3) servoPulse(servo, angle);
  } else if(s1 >= 101 && s1 <=800 ) {
    digitalWrite(pump, 1);
     forword();
     delay(100);
    turnRight(); 
    delay(200); 
  } else if(s2 >= 201 && s2 <= 800) {
    digitalWrite(pump, 1);
     forword();
  } else if(s3 >= 101 && s3 <= 800) {
    digitalWrite(pump, 1);
     forword(); 
     delay(100); 
     turnLeft(); 
     delay(200);
  } else {
    digitalWrite(pump, 1);
     Stop();
  }
  delay(10);
}

void servoPulse(int pin, int angle) {
  int pwm = (angle * 11) + 500;
  digitalWrite(pin, HIGH); delayMicroseconds(pwm); digitalWrite(pin, LOW);
  delay(50);
}

void forword() {
  digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW);
}

void backword() {
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
   digitalWrite(in4, HIGH);
}

void turnRight() {
  digitalWrite(in1, LOW); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW);
}

void turnLeft() {
  digitalWrite(in1, HIGH); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); 
  digitalWrite(in4, LOW);
}

void Stop() {
  digitalWrite(in1, LOW); 
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); 
  digitalWrite(in4, LOW);
}
