#include "Encoders.hpp"

std::vector<uint8_t> Hemming74::Get_char_to_bits(std::string in_str)
{
	std::vector<uint8_t> number;
	for (size_t i = 0; i < in_str.size(); i++)
	{
		if (in_str[i] == '1' || in_str[i] == '0')
		{
			number.push_back((uint8_t)in_str[i]);
		}
		else
		{
			throw std::string("Не корректный ввод числа. Требуемая форма - двоичная");
		}
		
	}
	if (number.size() % 4 != 0)
	{
		throw std::string("Не корректный ввод чилаю Ввредиче число в 4-х битнном формате");
	}
	return number;
}

std::vector<uint8_t> Hemming74::Gets_p_bits(const std::vector<uint8_t> &data)
{
	std::vector<uint8_t> out_vec;
	out_vec.push_back(data[0] ^ data[2] ^ data[3]);
	out_vec.push_back(data[0] ^ data[1] ^ data[3]);
	out_vec.push_back(data[1] ^ data[2] ^ data[3]);
	return out_vec;
}

void Hemming74::Encode(const std::vector<uint8_t> &data)
{
	int N_4_bits = 0;
	while (N_4_bits < data.size() / 4)
	{

		std::vector<uint8_t> tmp1, tmp_in_data;
		size_t n = 0, k = 0;
		for (size_t i = N_4_bits*4; i < 4 * (N_4_bits+1); i++)
		{
			tmp_in_data.push_back(data[i]);
		}

		tmp1 = Gets_p_bits(tmp_in_data);

		for (size_t i = 0; i < 7; i++)
		{
			if ((i + 1 == 1) || (i + 1 == 2) || (i + 1 == 4))
			{
				result.push_back(tmp1[k]);
				k++;
			}
			else
			{
				result.push_back(tmp_in_data[n]);
				n++;
			}
		}
		N_4_bits++;
		tmp_in_data.clear();
	}
	
}


