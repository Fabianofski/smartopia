int segA = 12;
int segB = 32;
int segC = 18;
int segD = 16;
int segE = 13;
int segF = 14;
int segG = 19;
int segP = 17;

int digit1 = 27;
int digit2 = 26;
int digit3 = 25;
int digit4 = 33;

int digits[4] = {digit1, digit2, digit3, digit4};
int segs[8] = {segA, segB, segC, segD, segE, segF, segG, segP};

byte nums[10][8] = {
  {0,0,0,0,0,0,1,1},
  {1,0,0,1,1,1,1,1},
  {0,0,1,0,0,1,0,1},
  {0,0,0,0,1,1,0,1},
  {1,0,0,1,1,0,0,1},
  {0,1,0,0,1,0,0,1},
  {0,1,0,0,0,0,0,1},
  {0,0,0,1,1,1,1,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,1,0,0,1}
};

void setup() {
  for (int i=0;i<8;i++) pinMode(segs[i], OUTPUT);
  for (int i=0;i<4;i++) pinMode(digits[i], OUTPUT);
}

void showDigit(int num, int digit) {
  for (int i=0;i<4;i++) digitalWrite(digits[i], LOW);
  digitalWrite(digits[digit], HIGH);
  for (int i=0;i<8;i++) digitalWrite(segs[i], nums[num][i]);
  delay(5);
}

void loop() {
  showDigit(0,0);
  showDigit(1,1);
  showDigit(2,2);
  showDigit(3,3);
}

