#include <stdlib.h>

#include "MockWordClockScene.h"

WordList MockWordClockScene::getWords(time_t time) {
  if (initialised) {
    minute ++;

    if (minute >= 60) {
      minute = 0;
      hour ++;
    }

    if (hour >= 24) {
      hour = 0;
      exit(0);
    }
  } else {
    initialised = true;
  }

  return wordingStrategy->wordsForTime(hour, minute);
}

uint8_t MockWordClockScene::getDotsCount(time_t time) {
  return minute % 5;
}
