int getCurrentPosition(int story, int room){
  return (3 - room) * 8 + (story -1);
}

int move(int axis){
  if(axis > 900){return 1;}
  if(axis < 100){return -1;}
  else {return 0;}
}

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
