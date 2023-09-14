#include "controller.h"
// #include "basicMove.h"

// Define setup //*==================================*/

#define LL 13
#define L 12
#define M 11
#define R 10
#define RR 9

uint8_t count = 0;

void setup() {
  pinMode(LL, INPUT);
  pinMode(L, INPUT);
  pinMode(M, INPUT);
  pinMode(R, INPUT);
  pinMode(RR, INPUT);
  Serial.begin(9600);
  Serial.println("Serial Start");
}

void loop() {
  uint8_t v = detecter();
  char m[10] = {'l','r','c','d','l','r','d',};
  // followMe(v);
  count = counter(v,count);
  mission(v,m,count);
  // Serial.printf("%d",count);
}
