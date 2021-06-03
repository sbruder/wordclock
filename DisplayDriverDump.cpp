#include <cmath>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "DisplayDriverDump.h"

namespace fs = std::filesystem;

const int WIDTH = 11;
const int HEIGHT = 10;

bool displayMatrixState[HEIGHT+2][WIDTH+2];
uint8_t minuteState = 0;

uint32_t dumpFileCounter = 0;

const fs::path baseDir("dump_images");

void DisplayDriverDump::setup() {
    if (fs::exists(baseDir)) {
        std::cerr << "File or directory ‘dump_images’ already exists.\n";
        exit(0);
    }
    if (!fs::create_directory(baseDir)) {
        std::cerr << "Could not create directory ‘dump_images’.\n";
        exit(0);
    }
}

int DisplayDriverDump::width() {
    return WIDTH;
}

int DisplayDriverDump::height() {
    return HEIGHT;
}

void DisplayDriverDump::setDots(uint8_t count, uint32_t color) {
    minuteState = count;

    displayMatrixState[0][0] = minuteState > 0;
    displayMatrixState[0][WIDTH+1] = minuteState > 1;
    displayMatrixState[HEIGHT+1][WIDTH+1] = minuteState > 2;
    displayMatrixState[HEIGHT+1][0] = minuteState > 3;
}

uint32_t DisplayDriverDump::getPixel(uint8_t x, uint8_t y) {
    return displayMatrixState[y+1][x+1] * (pow(2, 24) - 1);
}

void DisplayDriverDump::setPixel(uint8_t x, uint8_t y, uint32_t color) {
    displayMatrixState[y+1][x+1] = color > 0;
}

void DisplayDriverDump::show() {
    std::ostringstream dumpFileName;
    dumpFileName << std::setfill('0') << std::setw(6) << dumpFileCounter << ".pbm";
    fs::path dumpFilePath (dumpFileName.str());
    fs::path dumpPath = baseDir / dumpFilePath;

    std::cout << "Dumping file " << dumpPath << "…\n";
    std::ofstream file { dumpPath };
    file << "P1\n" << WIDTH+2 << " " << HEIGHT+2 << "\n";
    for (int row=0; row<HEIGHT+2; row++) {
        for (int col=0; col<WIDTH+2; col++) {
            file << (displayMatrixState[row][col] ? "0" : "1");
        }
        file << "\n";
    }
    dumpFileCounter++;
}
