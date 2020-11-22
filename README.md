# Smart-Dustbin-installed-in-Offices-in-IOT

# This is done using nodemcu ESP8266 and ultrasonic sensor HC-SR04 with Arduino IDE
NodeMCU is an open source platform based on ESP8266 which can connect objects and let data transfer using the Wi-Fi protocol. In addition, by providing some of the most important features of microcontrollers such as GPIO, PWM, ADC, and etc, it can solve many of the project’s needs alone.

The general features of this board are as follows:

Easy to use
Programmability with Arduino IDE or IUA languages
Available as an access point or station
practicable in Event-driven API applications
Having an internal antenna
Containing 13 GPIO pins, 10 PWM channels, I2C, SPI, ADC, UART, and 1-Wire


# In order to use Arduino IDE to program the NodeMCU, you have to introduce it to the software at first.

To do this copy the following code and follow the steps below:

http://arduino.esp8266.com/stable/package_esp8266com_index.json

step1. Choose Preferences in the File menu and enter the copied code in Additional Board Manager URLs part. Then press OK.
Step2. Search the word ESP8266 in Boards>boards manager from Tools menu. Then install ESP8266 boards. After complete installation, you will see the INSTALLED label on ESP8266 boards
After these two steps, you can see ESP8266 based boards such as NodeMCU in your Arduino IDE boards list, and you can choose your desired board to upload the code.
# Connecting ultrasonic sensor with ESP8266
The required connection for this program may be :

HC-SR04--> NodeMCU

trig --> D2 of NodeMCU

echo --> D1 of NodeMCU

vcc --> vin of NodeMCU (remember NOT 3v3)

gnd --> gnd of NodeMCU

->measured distance from the sensor gives output in cm unit (0.034 is the cm per uS)

->pulsein : Reads a pulse (either HIGH or LOW) on a pin.For example, if value is HIGH, pulseIn() waits for the pin to go HIGH, starts timing,then waits for the pin to go LOW and stops timing. Returns the length of the pulse in microseconds. 
->pulseIn(echoPin, HIGH) starts counting the number of microseconds until echoPin goes HIGH and stores that in duration.
  It starts and ends on that line, it's what is known as a blocking function. It will really sit there until echoPin goes high and tells you how long it took (unless you specify   a timeout).
  That also means that any delays you have before or after the pulseIn call don't affect it in any way.

duration = pulseIn(ECHO_PIN, HIGH);
distance = (duration/2) / 29.1;  
//We take that duration and divide it by 2 and than by 29.1. We divide by 29.1 because that is the pace of sound (which is 1 / speed of sound) in dry air. So we are saying that for every 29.1 ms sound travels 1 cm
float filled_dist = 42-distance;
float perc = (filled_dist / 42)*100;  // here 42 is height of the bucket
//So note the result is in CM's, not inches

if % level is between 0 to 33 is level of garbage is low
if % level is between 33 to 66 level of garbage is half-full
if % level is between 66 to 100 level of garbage is full and has to be cleared 







