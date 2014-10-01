#ifndef DSPFILTER_H_
#define DSPFILTER_H_

#include "GlobalConfig.h"
class DSPFilter
{
public:
	DSPFilter();
	~DSPFilter();
	/// filters using FFT.
	static void low_pass_fft(float spectrum[TWO_FRAME_SIZE], float pass_freq, float stop_freq);
	static void high_pass_fft(float spectrum[TWO_FRAME_SIZE], float pass_freq, float stop_freq);
	static void band_pass_fft(float spectrum[TWO_FRAME_SIZE], float low_stop_freq, float low_pass_freq, float high_pass_freq, float high_stop_freq);

};

#endif /* DSPFILTER_H_ */
