
#include "basicMove.h"

// Define setup //*==================================*/

#define L_F 13 // Left Motor 1st Pin
#define L_S 14 // Left Motor 2nd Pin
#define L_PWM 15 // Left Motor PWM Pin
#define R_F 16 // Right Motor 1st Pin
#define R_S 17 // Right Motor 2nd Pin
#define R_PWM 18 // Right Motor PWM Pin

 // Basic Move //*==================================*/

void forWard(int speedL, int speedR)
{
    Serial.println("Forward");
    // set front left Motor f
    digitalWrite(L_F, HIGH);
    digitalWrite(L_S, LOW);
    digitalWrite(L_PWM, speedL);

    // set front right motor s
    digitalWrite(R_F, HIGH);
    digitalWrite(R_S, LOW);
    digitalWrite(R_PWM, speedR);
}

void backWard(int speedL, int speedR)
{
    // Serial.println("Backward");
   // set front left Motor f
    digitalWrite(L_F, LOW);
    digitalWrite(L_S, HIGH);
    digitalWrite(L_PWM, speedL);

    // set front right motor s
    digitalWrite(R_F, LOW);
    digitalWrite(R_S, HIGH);
    digitalWrite(R_PWM, speedR);
}

void turnLeft(int speedL, int speedR)
{
    Serial.println("Turn Left");
   // set front left Motor f
    digitalWrite(L_F, HIGH);
    digitalWrite(L_S, LOW);
    digitalWrite(L_PWM, speedL/2);

    // set front right motor s
    digitalWrite(R_F, HIGH);
    digitalWrite(R_S, LOW);
    digitalWrite(R_PWM, speedR);
}

void turnRight(int speedL, int speedR)
{
    Serial.println("Turn Right");
  // set front left Motor f
    digitalWrite(L_F, HIGH);
    digitalWrite(L_S, LOW);
    digitalWrite(L_PWM, speedL);

    // set front right motor s
    digitalWrite(R_F, HIGH);
    digitalWrite(R_S, LOW);
    digitalWrite(R_PWM, speedR/2);
}

void spinLeft(int speedL, int speedR)
{
    Serial.println("Spin Left");
    // set front left Motor f
    digitalWrite(L_F, LOW);
    digitalWrite(L_S, HIGH);
    digitalWrite(L_PWM, speedL);

    // set front right motor s
    digitalWrite(R_F, HIGH);
    digitalWrite(R_S, LOW);
    digitalWrite(R_PWM, speedR);
}

void spinRight(int speedL, int speedR)
{
    Serial.println("Spin Right");
    // set front left Motor f
    digitalWrite(L_F, HIGH);
    digitalWrite(L_S, LOW);
    digitalWrite(L_PWM, speedL);

    // set front right motor s
    digitalWrite(R_F, LOW);
    digitalWrite(R_S, HIGH);
    digitalWrite(R_PWM, speedR);
}