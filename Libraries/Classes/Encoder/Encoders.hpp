#pragma once

#include <vector>
#include <iostream>


class Encoder
{
public:
	virtual void Encode(const std::vector<uint8_t> &data) = 0; // Функция кодирваония, на входе вектор uint8_t чисел, которые кодируем
	virtual std::vector<uint8_t> Get_char_to_bits(std::string in_str) = 0; // Функция преобразования символов (которые по идее ввдим в консоли) в uint8_t числа. На входе строка string
	std::vector<uint8_t> result;
};

class Hemming74 : public Encoder
{
public:
	std::vector<uint8_t> Get_char_to_bits(std::string in_str);
	void Encode(const std::vector<uint8_t> &data);
	std::vector<uint8_t> Gets_p_bits(const std::vector<uint8_t> &data); // Функция получения проверочных бит, на входе вектор uint8_t чисел.
};