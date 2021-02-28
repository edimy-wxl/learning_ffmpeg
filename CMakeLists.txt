cmake_minimum_required(VERSION 3.13)
project(demo)

set(CMAKE_CXX_STANDARD 14)

set(LINK_DIR /home/pi/ffmpeg/ffmpeg-4.3.1/_build/lib)

include_directories(/home/pi/ffmpeg/ffmpeg-4.3.1)
include_directories(./)
link_directories(${LINK_DIR})

set(LIBS libavcodec.so libavutil.so libavdevice.so libavformat.so libavfilter.so libm.so.6 libpthread-2.28.so libswscale.so)

add_executable(ffmpeg ffmpeg.c ffmpeg_opt.c ffmpeg_hw.c ffmpeg_filter.c cmdutils.c)
target_link_libraries(ffmpeg ${LIBS})

add_executable(myff myff.c)
target_link_libraries(myff ${LIBS})
