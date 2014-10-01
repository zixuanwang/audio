ADD_EXECUTABLE(test test.cpp)
ADD_EXECUTABLE(compute_feature compute_feature.cpp)

TARGET_LINK_LIBRARIES(test libaudio)
TARGET_LINK_LIBRARIES(compute_feature libaudio C:/aquila/build/Debug/Aquila.lib C:/aquila/build/lib/Debug/Ooura_fft.lib)