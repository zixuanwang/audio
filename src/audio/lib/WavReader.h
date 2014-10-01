#ifndef WAVREADER_H_
#define WAVREADER_H_

#include <fstream>
#include <string>
#include "GlobalConfig.h"

class WavReader {
public:
	WavReader(const std::string& file);
	~WavReader();
	void read(char* buf, int buf_size, int* filled_size);
	int get_channels();
	int get_bit_per_sample();
private:
	std::ifstream m_in_stream;
	int m_sample_rate;
	short m_channels;
	short m_bit_per_sample;
	int m_size;
	long long m_data_length;
};

#endif /* WAVREADER_H_ */
