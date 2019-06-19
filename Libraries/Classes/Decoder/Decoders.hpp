#pragma once

#include <vector>
#include <iostream>

class Decoder
{
public:
	virtual void Decode(const std::vector<uint8_t> &data) = 0;
	std::vector<uint8_t> result_data;
};

class Hemming74_d : public Decoder
{
public:
	void Decode(const std::vector<uint8_t> &data);
	std::vector<uint8_t> Gets_p_bits(const std::vector<uint8_t> &data);
	std::vector<std::vector<uint8_t>> Gets_data_p_bits(std::vector<uint8_t> &data);

};