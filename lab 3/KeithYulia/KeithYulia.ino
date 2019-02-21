/*
Lab 3 
Valentine's Day 
Julia Maliauka, Keith Skinner
 */

#include <seeed_pwm.h>
#include <Hercules_dfs.h>
#include <Ultrasonic.h>

const long freqLeftForward = 10000;
const long freqRightForward = 7800;

const int forwardPower = 20;
const int rightAngleTurnDelay = 294;
const int rightAngleTurnPower = 60;

const char Forward = DIRF;
const char Backward = DIRR;

const int ULTRASONIC_PIN = 11;


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

    void stop_both()
    {
        stop_left();
        stop_right();
    }

    void move_left(char dir, char speed)
    {
        PWM.setPwm(9, speed, freqLeftForward);
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

    void move_right(char dir, char speed)
    {
        PWM.setPwm(10, speed, freqRightForward);
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
        move_right(Forward, speed);
        move_left(Forward, speed);
    }

    void move_backward(char speed = forwardPower)
    {
        move_right(Backward, speed);
        move_left(Backward, speed);
    }

    void move_counter_clockwise(char speed = rightAngleTurnPower)
    {
        move_right(Forward, speed);
        move_left(Backward, speed);
    }

    void move_clockwise(char speed = rightAngleTurnPower)
    {
        move_right(Backward, speed);
        move_left(Forward, speed);
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
}



void setup()
{
    brian::begin();
    Serial.begin(9600);
}

void rot(int t)
{
    Serial.println("Hi");
    brian::move_clockwise(60);
    delay(t);
    brian::stop_both();
    delay(3000);
}

void loop()
{
    double dist = brian::read_radar();

    brian::move_forward();
    auto tea = millis();
    while (dist > 10  &&  millis() <= tea + 400)
        dist = brian::read_radar();
    brian::stop_both();
    delay(200);

    brian::move_counter_clockwise();
    delay(rightAngleTurnDelay);
    brian::stop_both();
    delay(200);

    double dist1 = brian::read_radar();
    Serial.print("Distance 1: ");
    Serial.println(dist1);

    brian::move_counter_clockwise();
    delay(rightAngleTurnDelay);
    brian::stop_both();
    delay(200);
    brian::move_counter_clockwise();
    delay(rightAngleTurnDelay);
    brian::stop_both();
    delay(200);

    double dist2 = brian::read_radar();
    Serial.print("Distance 2: ");
    Serial.println(dist2);
    
    brian::move_counter_clockwise();
    delay(rightAngleTurnDelay);
    brian::stop_both();
    delay(200);

    double delta = abs(dist1 - dist2);
    Serial.print("Delta: ");
    Serial.println(delta);

    brian::stop_both();
    delay(2000);
}

//TODO: Make brian move forward even straighter.
//TODO: Make brian accelerate smoother.
