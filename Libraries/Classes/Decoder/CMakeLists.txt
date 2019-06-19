cmake_minimum_required(VERSION 2.8.8)

set(CPP
	Decoders.cpp
	)

set(HPP
	Decoders.hpp
	)

add_library(Decoder STATIC ${CPP} ${HPP})