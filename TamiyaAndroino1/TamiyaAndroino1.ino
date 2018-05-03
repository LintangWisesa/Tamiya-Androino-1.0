int motorPin1 = 3; // pin 2 on L293D
int motorPin2 = 4; // pin 7 on L293D
int enablePin = 5; // pin 1 on L293D
int state;
int flag = 0;
 
void setup() {
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(enablePin, OUTPUT);

    digitalWrite(enablePin, HIGH);
    Serial.begin(9600);
}
 
void loop() {
    if(Serial.available() > 0){     
        state = Serial.read();   
        flag=0;
    }   

    if (state == '0') {
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        if(flag == 0){
            Serial.println("Tamiya Androino STOP");
            flag=1;
        }
    }

    else if (state == '1') {
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        if(flag == 0){
            Serial.println("Tamiya Androino MUNDUR");
            flag=1;
        }
    }

    else if (state == '2') {
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        if(flag == 0){
            Serial.println("Tamiya Androino MAJU");
            flag=1;
        }
    }
}
