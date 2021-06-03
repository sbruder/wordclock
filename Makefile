CXX = g++

CFLAGS = -std=c++17 -Wall -I. -Iarduino-compat
LDFLAGS =

ifeq ($(DEBUG),1)
	CFLAGS += -g
	LDFLAGS += -O0
else
	LDFLAGS += -s
endif

OBJS = \
	AnimatorFallingStar.o \
	AnimatorNull.o \
	DisplayDriverDump.o \
	MockWordClockScene.o \
	Word.o \
	WordClockScene.o \
	WordFactoryGermanV2Clock.o \
	WordList.o \
	WordingStrategyFranken.o \
	arduino-compat/Arduino.o \
	arduino-compat/Time.o \
	arduino-compat/Timezone.o \
	dump.o

dump: $(OBJS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) -c $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f */*.o *.o dump
