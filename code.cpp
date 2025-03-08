#define enA 10 // Enable1 L298 Pin enA
#define in1 9  // Motor1 L298 Pin in1
#define in2 8  // Motor1 L298 Pin in2
#define in3 7  // Motor2 L298 Pin in3
#define in4 6  // Motor2 L298 Pin in4
#define enB 5  // Enable2 L298 Pin enB
#define ir_R A0 // Right IR sensor
#define ir_F A1 // Front IR sensor
#define ir_L A2 // Left IR sensor
#define flameSensor A3 // Flame sensor
#define servoPin A4 // Servo pin
#define pump A5  // Pump control pin
#define BUZZER_PIN 3 // Pin for buzzer
#define LED_PIN 4    // Pin for LED indicator

#include <Servo.h>
Servo servo;
int Speed = 160; // Motor speed (0 to 255)
const int FLAME_THRESHOLD = 300; // Adjust based on sensor calibration
bool flameDetected = false;

void setup() {
    Serial.begin(9600);
    
    pinMode(ir_R, INPUT);
    pinMode(ir_F, INPUT);
    pinMode(ir_L, INPUT);
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(servoPin, OUTPUT);
    pinMode(pump, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED_PIN, OUTPUT);
    
    servo.attach(servoPin);
    servo.write(90);
    
    analogWrite(enA, Speed);
    analogWrite(enB, Speed);
}

void loop() {
    int s1 = analogRead(ir_R);
    int s2 = analogRead(ir_F);
    int s3 = analogRead(ir_L);
    int flameValue = analogRead(flameSensor);
    
    Serial.print("IR_R: "); Serial.print(s1);
    Serial.print("\tIR_F: "); Serial.print(s2);
    Serial.print("\tIR_L: "); Serial.print(s3);
    Serial.print("\tFlame: "); Serial.println(flameValue);
    
    if (flameValue > FLAME_THRESHOLD) {
        if (!flameDetected) {
            flameDetected = true;
            triggerAlarm();
        }
    } else {
        if (flameDetected) {
            flameDetected = false;
            resetAlarm();
        }
    }
    
    if (s1 < 250) {
        moveRight();
    } else if (s2 < 350) {
        moveBackward();
    } else if (s3 < 250) {
        moveLeft();
    } else {
        moveForward();
    }
    delay(10);
}

void triggerAlarm() {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(pump, HIGH);
}

void resetAlarm() {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(pump, LOW);
}

void moveForward() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void moveBackward() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void moveRight() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void moveLeft() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void stopMovement() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
