#include <Adafruit_NeoPixel.h> // NeoPixel을 사용하기 위해 include 한 라이브러리.
#include "functions.h"         // 자체적으로 만든 functions 파일에 대한 import
#include "initialCondition.h"  // 초기설정 값을 별도로 분리해둔 initialCondition 파일에 대한 import


Adafruit_NeoPixel building(buildingPixels, 13, NEO_GRB + NEO_KHZ800); // NeoPixel 인스턴스. 빌딩에서 드론의 위치를 제어
Adafruit_NeoPixel water(waterPixels, 12, NEO_GRB + NEO_KHZ800);       // NeoPixel 인스턴스. 소방수의 레벨을 제어


void setup() {
Serial.begin(9600); // 디버깅을 위한 시리얼 모니터의 초기설정
  building.begin(); // building 인스턴스의 초기화
  water.begin();    // water 인스턴스의 초기화
}

void loop() {
building.clear();  // 매 루프마다 building들의 이전 상태를 지워주는 함수. 없으면 누적된다. 경로를 표시하고자 한다면 제거해야하는 코드
water.clear();     // 매 루프마다 water들의 이전 상태를 지워주는 함수. 없으면 누적된다. 측정된 최고레벨을 표시하고자 한다면 제거해야하는 코드
  light = analogRead(A2); // cds 센서가 읽은 빛 신호의 세기를 저장하는 변수. analogRead으로 매 loop마다 측정한다.
  xaxis = analogRead(A4); // Joystick의 x위치값을 저장하는 변수. analogRead로 매 loop마다 측정한다. 0~1023까지의 값
  yaxis = analogRead(A5); // Joystick의 x위치값을 저장하는 변수. analogRead로 매 loop마다 측정한다. 0~1023까지의 값
  room += move(xaxis);   // move 함수로 읽어드린 xaxis값에 따라 현재 room 값을 증감시켜 저장하는 코드
  story += move(yaxis);  // move 함수로 읽어드린 yaxis값에 따라 현재 story 값을 증감시켜 저장하는 코드
  
  // building 인스턴스의 setPixelColor 메서드로 각 index에 따른 발광소자의 빛 값을 세팅하는 코드
  // 현재 story 및 room값에 대해, setVerticalBoundary 및 setHorizontalBoundary 함수로 경계조건을 만족하는지 체크하고,
  // 유효한 story값과 room값을 getCurrentPosition 함수의 매개변수로 넘겨서 드론을 위치시키고자 하는 index값을 반환해
  // R204, G153, B0의 노란색 불빛으로 드론의 위치를 NeoPixel에 출력하는 코드
  building.setPixelColor( 
    getCurrentPosition(setVerticalBoundary(story), setHorizontalBoundary(room)), 
    building.Color(204,153, 0)
  );
  
  // water 인스턴스의 setPixelColor 메서드로 각 index에 따른 발광소자의 빛 값을 세팅하는 코드
  // for loop 문을 통해 어느 레벨까지 소방수를 출력할 것인지를 결정하는데,
  // for loop의 두번째 인자인 조건문에서 iterating 변수 j값이 입력받은 light값의 50으로 나눈 몫보다 작을 때 까지 시행
  // 따라서, 400이상의 출력값에 대해서는 동일하게 8레벨의 최대출력을 진행
  // waterArr에 저장된 파랑색 그라데이션 배열이 출력되어 시각적 효과를 높임
  for (int j = 0; j < light / 50 ; j++){
    water.setPixelColor(
      j,
      water.Color(waterArr[j][0], waterArr[j][1], waterArr[j][2])
    );
  }
  Serial.println(light); // Serial 모니터에 현재 입력받은 light값을 출력시킴. 디버깅용

building.show(); // building 인스턴스에 현재 배정된 발광 좌표와 RGB값을 하드웨어로 전달해 출력시키는 함수
water.show();    // water 인스턴스에 현재 배정된 발광 좌표와 RGB값을 하드웨어로 전달해 출력시키는 함수
delay(100); // loop가 하드웨어 딜레이보다 더 빠르게 작동해 에러가 나지 않도록 적절한 delay를 설계. 100 ms 정도가 자연스러움
}
