#include <boost/filesystem.hpp>
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include "aquila/global.h"
#include "aquila/source/SignalSource.h"
#include "aquila/source/generator/SineGenerator.h"
#include "aquila/transform/Mfcc.h"
#include "audio/lib/FFT.h"
#include "audio/lib/File.h"
#include "audio/lib/SimpleVAD.h"
#include "audio/lib/WavReader.h"

void compute_mfcc(const std::string& directory, const std::string& output){
	std::vector<std::string> file_vector;
	File::get_files(file_vector, directory, true, ".wav");
	std::ofstream out_stream(output);
	for (size_t i = 0; i < file_vector.size(); ++i){
		std::cout << "processing " << file_vector[i] << "..." << std::endl;
		FFT fft;
		SimpleVAD vad;
		WavReader reader(file_vector[i]);
		double time = 0.0;
		char buf[TWO_FRAME_SIZE];
		short* buf_ptr = (short*)buf;
		int buf_size = TWO_FRAME_SIZE;
		float input[FRAME_SIZE];
		float spectrum[TWO_FRAME_SIZE];
		while (true){
			int buf_filled = 0;
			reader.read(buf, buf_size, &buf_filled);
			if (buf_filled < buf_size){
				break;
			}
			for (int i = 0; i < FRAME_SIZE; ++i){
				input[i] = (float)buf_ptr[i] / SHRT_MAX;
			}
			fft.analyze(input, spectrum);
			float energy = 0.f;
			for (int i = 6; i < 236; ++i){
				energy += spectrum[i] * spectrum[i] + spectrum[TWO_FRAME_SIZE - i] * spectrum[TWO_FRAME_SIZE - i];
			}
			bool voice = vad.classify(time, energy);
			time += 0.016;
			// compute MFCC
			Aquila::Mfcc mfcc(FRAME_SIZE);
			Aquila::SignalSource mfcc_input(input, FRAME_SIZE, SAMPLE_RATE);
			std::vector<double> value_vector = mfcc.calculate(mfcc_input);
			if (voice){
				std::copy(value_vector.begin(), value_vector.end(), std::ostream_iterator<double>(out_stream, " "));
				out_stream << std::endl;
			}
		}
	}
}


int main(int argc, char* argv[]){
	compute_mfcc("E:\\data\\audio\\massagedData\\original", "E:\\data\\audio\\massagedData\\original\\mfcc.txt");
	return 0;
}