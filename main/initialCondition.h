// 소방수 네오픽셀의 8레벨에 대한 각 부분의 RGB값. 가장 끝의 빛은 0,0,255의 가장 순수한 파란색이며, 
// 나머지 8단계는 R, G 값에 각각 50 / 100/ 150/ 200 정도의 불순값이 들어있다.
// int 타입의 2차원 배열을 사용했으며, 소방수 코드의 for loop 에 사용된다 : main.ino
int waterArr[][3] ={{204, 255, 255}, {102, 255,255}, {51,204, 255},{0, 204, 255},
{0, 153, 255},{0, 102, 255},{0, 51, 204}, {0, 0, 255}};

// building 과 water을 위한 각각의 NeoPixel의 소자 숫자.
// building : 8 x 3 = 24
// water : 8 x 1 = 8
int buildingPixels = 24;
int waterPixels = 8;

// 초기조건으로 주어지는 층번 및 호번.
// 처음에는 최저층의 가운데인 102호에서 시작한다.
// C++ 의 배열 시작값인 0으로 초기화되지 않았고 NeoPixel의 순서에도 어긋나므로 
// 별도로 처리해주는 함수가 필요하다 : function.cpp
int story = 1;
int room = 2;

// 소방수의 초기레벨 : 0
// 소방수의 레벨은 cds 입력에 따라 금새 overriding 되므로 큰 의미는 없다.
int waterLevel = 0;

// Joystick 과  CDS 소자로 부터 받는 아날로그 신호값을 저장하는 변수
int xaxis, yaxis, light;
