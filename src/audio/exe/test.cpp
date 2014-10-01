#include <chrono>
#include <iostream>
#include "audio/lib/FFT.h"

int main(int argc, char* argv[]){
	float a[8] = { 1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f };
	float b[8];
	float c[8];
	for (int i = 0; i < 100000000; ++i){
		FFT::fft(a, b, 8);
		FFT::ifft(b, c, 8);
	}
	return 0;
}