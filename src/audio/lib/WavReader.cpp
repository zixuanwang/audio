#include "WavReader.h"

WavReader::WavReader(const std::string& file){
	m_in_stream.open(file, std::ios::binary);
	if (m_in_stream.good()){
		m_in_stream.seekg(22, m_in_stream.beg);
		m_in_stream.read((char*)&m_channels, sizeof(m_channels));
		m_in_stream.read((char*)&m_sample_rate, sizeof(m_sample_rate));
		m_in_stream.seekg(34, m_in_stream.beg);
		m_in_stream.read((char*)&m_bit_per_sample, sizeof(m_bit_per_sample));
		m_in_stream.seekg(40, m_in_stream.beg);
		m_in_stream.read((char*)&m_size, sizeof(m_size));
		m_in_stream.seekg(0, m_in_stream.end);
		m_data_length = (long long)m_in_stream.tellg();
		m_data_length -= 44;
		m_in_stream.seekg(44, m_in_stream.beg);
	}
}

WavReader::~WavReader(){
	if (m_in_stream.good()){
		m_in_stream.close();
	}
}

void WavReader::read(char* buf, int buf_size, int* filled_size){
	if (m_in_stream.good()){
		if (m_data_length < (long long)buf_size){
			m_in_stream.read(buf, m_data_length);
			*filled_size = (int)m_data_length;
			m_data_length = 0;
		}
		else{
			m_in_stream.read(buf, buf_size);
			m_data_length -= buf_size;
			*filled_size = buf_size;
		}
	}
}

int WavReader::get_channels(){
	return (int)m_channels;
}

int WavReader::get_bit_per_sample(){
	return (int)m_bit_per_sample;
}
