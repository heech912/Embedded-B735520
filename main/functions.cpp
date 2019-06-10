// story 값과 room 값을 받아서 Neopixel에 출력해야할 index로 바꿔주는 함수.
// story와 room에 저장되는 값은 인간에게 익숙한 값이므로,
// 설계한 NeoPixel의 index 구조에 맞는 값으로 변환해야
// 의도한 대로 출력할 수 있다.
// 인간에게 익숙한 story 값과 room 값은 Serial Monitor에 출력한다던지
// 인간에게 익숙한 인터페이스 출력값으로 사용할 수 있다.

int getCurrentPosition(int story, int room){
  return (3 - room) * 8 + (story -1);
}



// JoyStick에서 받은 Analog Input을 이용해
// Drone을 이동할지 말지 결정하는 함수.
// 900과 100은 설계자의 의도에 따라 설정한 임계값이다.
// 민감도가 이정도의 값에 대해 자연스러웠음을 관측했다.
// JoyStick은 상하와 좌우(X와 Y축)에 대해 대칭적이므로
// Vertical Movement와 Horizontal Movement에 대해 서로 다른 함수를 만들 필요가 없다.

int move(int axis){
  if(axis > 900){return 1;}
  if(axis < 100){return -1;}
  else {return 0;}
}



// Drone의 Story와 room값이 8개층와 3개호실을 벗어나지 않도록
// 경계를 정해주는 함수. int move() 함수와 다르게
// 가로와 세로의 경계 임계값이 다르므로 서로다른 함수를 만들었다.
// 이와 다르게, setBoundary(int value, bool isVertical) 정도의 하나의 함수로 만들어서
// isVertical 값에 따라 경계값을 다르게 해서 하나의 함수로 작성할 수도 있을 것이다.

int setVerticalBoundary(int story){
  if (story > 8) {return 8;}
  if (story < 1) {return 1;}
  else {return story;}
}
int setHorizontalBoundary(int room){
  if (room > 3) {return 3;}
  if (room < 1 ) {return 1;}
  else {return room;}
}
