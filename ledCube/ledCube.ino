/* ledNum and Switcher */
int ledNum = 3;
boolean speedSwitcher = true;  // スイッチャー(trueで加速,falseで減速)
boolean patternSwitcher = true;  //スイッチャー(trueをpattern1,falseでpattern2)

/* gnd */
int gnd[3] = {0, 10, 11};

/* line制御 */
int line1[3] = {1, 2, 3};
int line2[3] = {4, 5, 6};
int line3[3] = {7, 8, 9};
int line[3][3] = {
  {line1[0],line1[1],line1[2]},
  {line2[0],line2[1],line2[2]},
  {line3[0],line3[1],line3[2]}
};

/* delay time */
int fps = 300;

void setup() {
  for(int i = 0; i < ledNum; i++) {
    for(int j = 0; j < ledNum; j++) {
      pinMode(line[i][j], OUTPUT);
    }
    pinMode(gnd[i], OUTPUT);
  }
  
  all();
  delay(1000);

  cls();
  delay(1000);
}

void loop() {  
  cls();
  if(patternSwitcher == true){
    pattern1();
  }
  else{
  pattern2();
  }
  
  if(fps < 50){
    speedSwitcher = false;  //減速切替
    for(int i = 0 ; i < 10 ; i++){  //高速点滅
      all();
      delay(30);
      cls();
      delay(30);
    }
    randomAll();
    floorUp();
    cls();
    delay(50);
    floorDown();
    patternSwitcher = !patternSwitcher;  //パターン切替
  }
  else if(fps == 300){  //加速切替
    speedSwitcher = true;
  }
  
  if(speedSwitcher == true){  //加速処理
    fps -= 50;
  }
  else{  //減速処理
    fps += 50;
  }
  }

/* サイド上昇,中央下降 */
void pattern1() { 
  for(int floor = 0 ; floor < 3 ; floor++){ 
  digitalWrite(gnd[floor], LOW);
    for(int i = 0 ; i < ledNum ; i++){
    digitalWrite(line[0][i], HIGH);
    }
    for(int i = 0 ; i < ledNum ; i++){
    digitalWrite(line[2][i], HIGH);
    }
    delay(fps);
    for(int i = 0 ; i < ledNum ; i++){
    digitalWrite(line[0][i], LOW);
    }
    for(int i = 0 ; i < ledNum ; i++){
    digitalWrite(line[2][i], LOW);
    }
  digitalWrite(gnd[floor], HIGH);
  delay(fps);
  }
  
  for(int floor = 2 ; floor >= 0 ; floor--){
    digitalWrite(gnd[floor], LOW);
    for(int i = 2 ; i >= 0 ; i--){
      digitalWrite(line[1][i], HIGH);
    }
    delay(fps);
    for(int i = 2 ; i >= 0 ; i--){
      digitalWrite(line[1][i], LOW);
    }
    digitalWrite(gnd[floor], HIGH);
    delay(fps);
  }
}

/* pattern1の反転ver */
void pattern2(){
  for(int floor = 2 ; floor >= 0 ; floor--){
  digitalWrite(gnd[floor], LOW);
    for(int i = 2 ; i >= 0 ; i--){
    digitalWrite(line[0][i], HIGH);
    }
    for(int i = 2 ; i >= 0 ; i--){
    digitalWrite(line[2][i], HIGH);
    }
    delay(fps);
    for(int i = 2 ; i >= 0 ; i--){
    digitalWrite(line[0][i], LOW);
    }
    for(int i = 2 ; i >= 0 ; i--){
    digitalWrite(line[2][i], LOW);
    }
  digitalWrite(gnd[floor], HIGH);
  delay(fps);
  }
  
  for(int floor = 0 ; floor < ledNum ; floor++){
    digitalWrite(gnd[floor], LOW);
    for(int i = 0 ; i < ledNum ; i++){
      digitalWrite(line[1][i], HIGH);
    }
    delay(fps);
    for(int i = 0 ; i < ledNum ; i++){
      digitalWrite(line[1][i], LOW);
    }
    digitalWrite(gnd[floor], HIGH);
    delay(fps);
  }
}

void floorUp(){
  for(int roopCnt = 0 ; roopCnt < 2 ; roopCnt++){
    for(int i = 0 ; i < ledNum ; i++) {
      digitalWrite(gnd[i], LOW);
      for(int j = 0 ; j < ledNum ; j++){ 
        for(int k = 0 ; k < ledNum ; k++){
          digitalWrite(line[j][k], HIGH);
        }
      }
      delay(200);
      digitalWrite(gnd[i], HIGH);
    }
  }
}

void floorDown(){
  for(int roopCnt = 0 ; roopCnt < 2 ; roopCnt++){
    for(int i = 2 ; i >= 0 ; i--) {
      digitalWrite(gnd[i], LOW);
      for(int j = 0 ; j < ledNum ; j++){ 
        for(int k = 0 ; k < ledNum ; k++){
          digitalWrite(line[j][k], HIGH);
        }
      }
      delay(200);
      digitalWrite(gnd[i], HIGH);
    }
  }
}

void randomAll() {
  for(int roopCnt = 0 ; roopCnt < 10 ; roopCnt++){
    for(int i = 0 ; i < ledNum ; i++){
      digitalWrite(gnd[i], LOW);
      digitalWrite(line[random(0,3)][random(0,3)], HIGH);
      digitalWrite(line[random(0,3)][random(0,3)], HIGH);
      delay(100);
      digitalWrite(line[random(0,3)][random(0,3)], LOW);
      digitalWrite(line[random(0,3)][random(0,3)], LOW);
      digitalWrite(line[random(0,3)][random(0,3)], LOW);
      digitalWrite(line[random(0,3)][random(0,3)], LOW);
      digitalWrite(gnd[i], HIGH);
    }
  }
}

void fill(){
  for(int i = 0 ; i < ledNum ; i++){
    digitalWrite(line[1][i], HIGH);
  }
  digitalWrite(gnd[0], LOW);
  delay(200);
  cls();
  delay(200);
  
  for(int i = 0 ; i < ledNum ; i++){
    for(int j = 0 ; j < ledNum ; j++){
      digitalWrite(line[i][j], HIGH);
    }
  }
  digitalWrite(gnd[0], LOW);
  delay(200);
  cls();
  delay(200);
  
  for(int i = 0 ; i < ledNum ; i++){
    digitalWrite(line[1][i], HIGH);
  }
  digitalWrite(gnd[0], LOW);
  digitalWrite(gnd[1], LOW);
  delay(200);
  cls();
  delay(200);
  
  for(int i = 0 ; i < ledNum ; i++){
    for(int j = 0 ; j < ledNum ; j++){
      digitalWrite(line[i][j], HIGH);
    }
  }
  digitalWrite(gnd[0], LOW);
  digitalWrite(gnd[1], LOW);
  delay(200);
  cls();
  delay(200);
  
  for(int i = 0 ; i < ledNum ; i++){
    digitalWrite(line[1][i], HIGH);
  }
  digitalWrite(gnd[0], LOW);
  digitalWrite(gnd[1], LOW);
  digitalWrite(gnd[2], LOW);
  delay(200);
  cls();
  delay(200);
  
  for(int i = 0 ; i < ledNum ; i++){
    for(int j = 0 ; j < ledNum ; j++){
      digitalWrite(line[i][j], HIGH);
    }
  }
  digitalWrite(gnd[0], LOW);
  digitalWrite(gnd[1], LOW);
  digitalWrite(gnd[2], LOW);
  delay(200);
  cls();
  delay(200);
}
    
/* 全点灯 */
void all() {
  for(int i = 0; i < ledNum; i++) {
    for(int j = 0; j < ledNum; j++) {
      digitalWrite(line[i][j], HIGH);
    }
    digitalWrite(gnd[i], LOW);
  }
}

/* 全消灯 */
void cls() {
  for(int i = 0; i < ledNum; i++) {
    for(int j = 0; j < ledNum; j++) {
      digitalWrite(line[i][j], LOW);
    }
    digitalWrite(gnd[i], HIGH);
  }
}
  
