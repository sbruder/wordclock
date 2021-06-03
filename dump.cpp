#include "MockWordClockScene.h"

#include "DisplayDriverDump.h"

#include "AnimatorNull.h"
#include "AnimatorIncremental.h"
#include "AnimatorFallingStar.h"

#include "WordFactoryGermanV2Clock.h"
#include "WordFactorySchwabenClock.h"
#include "WordFactoryFrankenClock.h"
#include "WordFactorySwedishClock.h"
#include "WordFactoryBayernClock.h"
#include "WordFactoryRoadaburchClock.h"

#include "WordingStrategyStesie.h"
#include "WordingStrategyEnglish.h"
#include "WordingStrategyFranken.h"
#include "WordingStrategyWest.h"
#include "WordingStrategySchwaben.h"
#include "WordingStrategySwedish.h"
#include "WordingStrategyBayern.h"
#include "WordingStrategyRoadaburch.h"

DisplayDriverDump driver;
WordFactoryGermanV2Clock wordFactory;
WordingStrategyFranken strategy(&wordFactory);

FallingStarAnimator animator(&driver);
//NullAnimator animator(&driver);

MockWordClockScene wordClockScene( &animator, &strategy );

int main() {
    driver.setup();
    while (true) {
        wordClockScene.loop();
    }
    return 0;
}
