#

![simplinnovation](https://4.bp.blogspot.com/-f7YxPyqHAzY/WJ6VnkvE0SI/AAAAAAAADTQ/0tDQPTrVrtMAFT-q-1-3ktUQT5Il9FGdQCLcB/s350/simpLINnovation1a.png)

# Tamiya Androino 1.0

### __Tamiya Androino 1.0__ is a simple Arduino project to control a DC motor over bluetooth. You can simply control your own Tamiya to go forward, backward and stop, by using Android phone. Watch the video below to see its action, then follow the instructions below to build your own Tamiya Androino!

#

[![Video Lintang Tamiya Androino 1.0](https://img.youtube.com/vi/NeP0aTYB5qU/0.jpg)](https://www.youtube.com/watch?v=NeP0aTYB5qU)

#

### **1. What You Need** :gift:
To build this project, you need the following items:
- 1 Arduino Uno board
- 1 Arduino proto board shield (or any breadboard)
- 1 Motor driver IC L293D
- 1 Bluetooth HC-05 module
- 1 DC motor
- 1 set 4WD Tamiya, just use its chassis, gears & tires.
- some jumper wires
- Arduino IDE ([download here](https://www.arduino.cc/en/Main/Software))
- Blueterm Android App ([download here](https://play.google.com/store/apps/details?id=es.pymasde.blueterm&hl=en) or you can easily get its __.apk__ that I've attached in this repo)

### **2. Schematics** :wrench::hammer:

Gather your parts then follow the schematics below.

![Tamiya Androino 1.0 schematics](https://4.bp.blogspot.com/-f7YxPyqHAzY/WJ6VnkvE0SI/AAAAAAAADTQ/0tDQPTrVrtMAFT-q-1-3ktUQT5Il9FGdQCLcB/s350/simpLINnovation1a.png)

### **3. Sketch** :clipboard:

You need to remove the RX and TX wires from Arduino, before uploading the sketch to your Arduino board. Copy sketch below to your Arduino IDE. Make sure you have chosen the right option for **_Board_** and **_Port_** under **_Tools_** menu, then upload to your Arduino board.

```c++
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
```

### **4. Have Fun!** :joy:
- After uploading process is done, reconnect TX & RX from Bluetooth module to RX & TX on Arduino board then restart it.
- Open Blueterm App, then connect to your Bluetooth module. If the Bluetooth module asks for a password, by default it's __'1234'__ (except you have changed it!).
- Here are the simple rules in Tamiya Androino 1.0 project:
  - It will __stop__ when we send __'0'__
  - It will **go backward** when we send __'1'__
  - It will **go forward** when we send __'2'__

#

#### Lintang Wisesa :love_letter: _lintangwisesa@ymail.com_

[Facebook](https://www.facebook.com/lintangbagus) | 
[Twitter](https://twitter.com/Lintang_Wisesa) |
[Google+](https://plus.google.com/u/0/+LintangWisesa1) |
[Youtube](https://www.youtube.com/user/lintangbagus) | 
:octocat: [GitHub](https://github.com/LintangWisesa) |
[Hackster](https://www.hackster.io/lintangwisesa)

