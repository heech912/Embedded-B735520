#include <Adafruit_NeoPixel.h>
#include "functions.h"
#include "initialCondition.h"


Adafruit_NeoPixel building(buildingPixels, 13, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel water(waterPixels, 12, NEO_GRB + NEO_KHZ800);


void setup() {
Serial.begin(9600);
  building.begin();
  water.begin();
}

void loop() {
building.clear();
water.clear();
  light = analogRead(A2);
  xaxis = analogRead(A4);
  yaxis = analogRead(A5);
  room += move(xaxis);
  story += move(yaxis);
  building.setPixelColor(
    getCurrentPosition(setVerticalBoundary(story), setHorizontalBoundary(room)),
    building.Color(204,153, 0)
  );
  for (int j = 0; j < light / 50 ; j++){
    water.setPixelColor(
      j,
      water.Color(waterArr[j][0], waterArr[j][1], waterArr[j][2])
    );
  }
  Serial.println(light);

building.show();
water.show();
delay(100);
}
