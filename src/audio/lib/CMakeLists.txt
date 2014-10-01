SET(libaudio_sources
	DSPFilter.h DSPFilter.cpp
	FFT.h FFT.cpp
	File.h File.cpp
	GlobalConfig.h
	Math.h Math.cpp
	SimpleVAD.h SimpleVAD.cpp
	WavReader.h WavReader.cpp
	WavWriter.h WavWriter.cpp
)
ADD_LIBRARY(libaudio ${libaudio_sources})

TARGET_LINK_LIBRARIES(libaudio ${Boost_LIBRARIES}) 