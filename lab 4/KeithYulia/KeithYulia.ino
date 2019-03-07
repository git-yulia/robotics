/*
    Lab 4 - Light race
    February 28, 2019 
    Julia Maliauka, Keith Skinner
 */

#include <seeed_pwm.h>
#include <Hercules_dfs.h>
#include <Ultrasonic.h>
#include <Time.h> 

const long freqLeftForward = 10000;
const long freqRightForward = 8400;

const long freqLeftTurn = 10000;
const long freqRightTurn = 10000;

const int forwardPower = 60;
const int rightAngleTurnDelay = 640;
const int rightAngleTurnPower = 30;

const char Forward = DIRF;
const char Backward = DIRR;

const int ULTRASONIC_PIN = 11;

int analogPin = A1;
int lightSensorValue = 0; 

namespace brian 
{

    void begin()
    {

        PWM.init();
        PWM.setPwm(9, 0, freqLeftForward);
        PWM.setPwm(10, 0, freqRightForward);

        pinMode(PINCS, OUTPUT);
        pinMode(PINM1F, OUTPUT);
        pinMode(PINM1R, OUTPUT);
        pinMode(PINM2F, OUTPUT);
        pinMode(PINM2R, OUTPUT);
        
        digitalWrite(PINCS, LOW);
        digitalWrite(PINM1F, LOW);
        digitalWrite(PINM1R, LOW);
        digitalWrite(PINM2F, LOW);
        digitalWrite(PINM2R, LOW);
    }

    void stop_left() 
    {
        PWM.setPwm(9, 0, freqLeftForward);
        digitalWrite(PINM1F, LOW);
        digitalWrite(PINM1R, LOW);
    }

    void stop_right()
    {
        PWM.setPwm(10, 0, freqRightForward);
        digitalWrite(PINM2F, LOW);
        digitalWrite(PINM2R, LOW);
    }

    void stop_both(int pause = 0)
    {
        stop_left();
        stop_right();
        delay(pause);
    }

    void move_left(char dir, char speed, long freq)
    {
        PWM.setPwm(9, speed, freq);
        ALLMOSON;
        if(dir == DIRF)
        {
            digitalWrite(PINM1F, HIGH);
            digitalWrite(PINM1R, LOW);
        }
        else
        {
            digitalWrite(PINM1F, LOW);
            digitalWrite(PINM1R, HIGH);
        }
    }

    void move_right(char dir, char speed, long freq)
    {
        PWM.setPwm(10, speed, freq);
        ALLMOSON;
        if(dir == DIRF)
        {
            digitalWrite(PINM2F, HIGH);
            digitalWrite(PINM2R, LOW);
        }
        else
        {
            digitalWrite(PINM2F, LOW);
            digitalWrite(PINM2R, HIGH);
        }
    }

    void move_forward(char speed = forwardPower)
    {
        move_right(Forward, speed, freqRightForward);
        move_left(Forward, speed, freqLeftForward);
    }

    void move_backward(char speed = forwardPower)
    {
        move_right(Backward, speed, freqRightForward);
        move_left(Backward, speed, freqLeftForward);
    }

    void turn_counter_clockwise(char speed = rightAngleTurnPower)
    {
        move_right(Forward, speed, freqRightTurn);
        move_left(Backward, speed, freqLeftTurn);
    }

    void turn_clockwise(char speed = rightAngleTurnPower)
    {
        move_right(Backward, speed, freqRightTurn);
        move_left(Forward, speed, freqLeftTurn);
    }

    double getRadarValue()
    {
        constexpr int _pin = ULTRASONIC_PIN;
        pinMode(_pin, OUTPUT);
        digitalWrite(_pin, LOW);
        delayMicroseconds(2);
        digitalWrite(_pin, HIGH);
        delayMicroseconds(5);
        digitalWrite(_pin,LOW);
        pinMode(_pin,INPUT);
        long duration = pulseIn(_pin,HIGH);
        double range = duration/29.0/2.0;
        return range;
    }

    double getClampedRadarValue(double clamp)
    {
        double value = getRadarValue();
        return value > clamp ? clamp : value;
    }

    double read_radar()
    {
        double total = 0;
        for (int i=0; i<5; ++i){
            total += getClampedRadarValue(100.0);
            delay(50);
        }
        total /= 5.0;
        Serial.println(total);
        return total;
    }

    int read_light()
    {
        int light = 1024 - analogRead(analogPin);
        Serial.print("Light: ");
        Serial.println(light);
        return light;
    }
}

void brianDoThings()
{
    /// At this point Brian is either going straight or has not 

    // IF THIS BREAKS ITS BECAUSE HIS THING IS LOOSE 
    /* 
    double RangeInCentimeters = brian::read_radar();
    if (RangeInCentimeters < 20) {
        brian::stop_both();
        delay(2500);
        brian::move_clockwise();
        delay(rightAngleTurnDelay);
        brian::stop_both();
        delay(2500);

        // check if brian did not accidentally turn into the wall
        delay(100); 
        RangeInCentimeters = brian::read_radar();
        if (RangeInCentimeters < 15) {
            brian::stop_both();
            Serial.print("TURNING BRIAN AGAIN");
            brian::move_clockwise();
            delay(rightAngleTurnDelay);
            brian::stop_both();
            delay(300);

            Serial.print(RangeInCentimeters);//0~400cm
            Serial.println(" cm");
        }
    }
    brian::move_forward();
    delay(250); 
    */

   // input range is 0 - 1023
   // subtracting 1024 inverts the signal

   delay(100);

    // step 1: spin brian in a circle
    int fullCircle = 4*rightAngleTurnDelay - 100;
    int maxValue = 0;
    time_t maxValueTime = millis();
    time_t start = millis();
    time_t current_time = start;
    brian::turn_clockwise();
    while (current_time < start + fullCircle) {
        int lightSensorValue = brian::read_light();
        Serial.println(lightSensorValue);
        if (lightSensorValue > maxValue) {
            maxValue = lightSensorValue;
            maxValueTime = millis();
        }
        delay(100);
        current_time = millis();
    }
    brian::stop_both();
    delay(500);
    Serial.println(maxValue);
    time_t deltaTime =  maxValueTime - start;
    brian::turn_clockwise();
    delay(deltaTime);
    delay(200);

    // step 2: moth mode 

    Serial.print("Start: ");
    Serial.println(start);
    Serial.print("maxValueTime: ");
    Serial.println(maxValueTime);
    Serial.print("deltaTime: ");
    Serial.println(deltaTime);
    Serial.print("maxValue: ");
    Serial.println(maxValue);
}

void setup()
{
    brian::begin();
    //Serial.println(lightSensorValue);
    Serial.begin(9600);

}

void loop()
{
    bool stop = false;
    while (!stop) {
        brianDoThings();
        brian::stop_both();
        brian::move_forward();

        delay(500);

        if (brian::read_light() > 700) {
            while (brian::read_radar() > 15) {
                brian::move_forward();
            } 
            stop = true;
            brian::stop_both();
        }   
    }
}
