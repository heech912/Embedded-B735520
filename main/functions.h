// main.ino에서 사용되는 함수들의 헤더파일.
// c/c++ 언어에서 자체적으로 제공되는 모듈 시스템인 헤더파일이다.
// 함수의 내용은 functions.cpp에 자세히 나와있다. 

// 현재 층과 방의 값을 받아서, neoPixel에 출력해야할 index를 반환하는 함수
int getCurrentPosition(int story, int room);

// Joystick의 axis값을 받아서 drone의 좌표를 재설정하는 함수.
int move(int axis);

// 층과 방의 경계를 정하는 함수.
int setVerticalBoundary(int story);
int setHorizontalBoundary(int room);
