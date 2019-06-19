cmake_minimum_required(VERSION 2.8.8)

set(CPP
	Encoders.cpp
	)

set(HPP
	Encoders.hpp
	)

add_library(Encoder STATIC ${CPP} ${HPP})