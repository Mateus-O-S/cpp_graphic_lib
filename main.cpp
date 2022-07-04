#include "window.cpp"
#include <iostream>
#include <thread>

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR args, int ncmd) {
    thread client ([&hInstance, &hPrev, &args, &ncmd](){Wmain(hInstance, hPrev, args, ncmd);});
}