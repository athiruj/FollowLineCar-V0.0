#include "controller.h"
#include "basicMove.h"

// Define setup //*==================================*/

#define LL 13
#define L 12
#define M 11
#define R 10
#define RR 9

int speedL = 125;
int speedR = 125;

uint8_t detecter(void) {
  return digitalRead(LL) << 4 | digitalRead(L) << 3 | digitalRead(M) << 2 | digitalRead(R) << 1 | digitalRead(RR) << 0 & 0xfffff;
}

/*
  0 0 0 0 0  -  0  *
  0 0 0 0 1  -  1  *
  0 0 0 1 0  -  2   
  0 0 0 1 1  -  3  * 
  0 0 1 0 0  -  4   
  0 0 1 0 1  -  5   
  0 0 1 1 0  -  6   
  0 0 1 1 1  -  7  * 
  0 1 0 0 0  -  8   
  0 1 0 0 1  -  9   
  0 1 0 1 0  -  10  
  0 1 0 1 1  -  11  
  0 1 1 0 0  -  12  
  0 1 1 0 1  -  13  
  0 1 1 1 0  -  14  
  0 1 1 1 1  -  15  
  1 0 0 0 0  -  16 * 
  1 0 0 0 1  -  17  
  1 0 0 1 0  -  18  
  1 0 0 1 1  -  19  
  1 0 1 0 0  -  20  
  1 0 1 0 1  -  21  
  1 0 1 1 0  -  22  
  1 0 1 1 1  -  23  
  1 1 0 0 0  -  24  *
  1 1 0 0 1  -  25  
  1 1 0 1 0  -  26  
  1 1 0 1 1  -  27  
  1 1 1 0 0  -  28  *
  1 1 1 0 1  -  29  
  1 1 1 1 0  -  30  
  1 1 1 1 1  -  31  
*/
void followMe(uint8_t v) {
  if (v == 27) {  // 1 1 0 1 1
    forWard(speedL, speedR);
  }
  if (v == 15 || v == 23) {  // 1 0 1 1 1 , 0 1 1 1 1
    turnLeft(speedL, speedR);
  }
  if (v == 29 || v == 30) {  // 1 1 1 0 1 , 1 1 1 1 0
    turnRight(speedL, speedR);
  }
  backWard(speedL, speedR);
}

bool status = false;
uint8_t counter(uint8_t v, uint8_t count) {
  delay(10);
  if (status && (v == 1 || v == 3 || v == 7 || v == 16 || v == 24 || v == 28)) {
    delay(200);
    Serial.printf("%d: %d\n", v, count);
    status = false;
    return count = count + 1;
  } else if (v == 27 && !status) {
    Serial.printf("Reset\n");
    status = true;
  }
  return count;
}

uint8_t next = 0;
void mission(uint8_t v, char* mission, uint8_t index) {
  if (index < sizeof(mission) / sizeof(mission[0]) && next == index) {
    Serial.println(mission[index]);
    switch (mission[index]) {
      case 'l':
        turnLeft(speedL, speedR);
        next++;
        break;
      case 'r':
        turnRight(speedL, speedR);
        next++;
        break;
      case 'c':
        Serial.println("Catch");
        next++;
        break;
      case 'd':
        next++;
        Serial.println("Drop");
        break;
      default:
        followMe(v);
        break;
    }
  }
  followMe(v);
}
