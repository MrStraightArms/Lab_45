#include "Decoders.hpp"

std::vector<uint8_t> Hemming74_d::Gets_p_bits(const std::vector<uint8_t> &data)
{
	std::vector<uint8_t> out_vec;
	out_vec.push_back(data[0] ^ data[2] ^ data[3]);
	out_vec.push_back(data[0] ^ data[1] ^ data[3]);
	out_vec.push_back(data[1] ^ data[2] ^ data[3]);
	return out_vec;
}

std::vector<std::vector<uint8_t>> Hemming74_d::Gets_data_p_bits(std::vector<uint8_t> &data)
{
	std::vector<std::vector<uint8_t>> out;
	std::vector<uint8_t> data_bits;
	for (size_t i = 0; i < 7; i++)
	{
		if ((i != 0) && (i != 1) && (i != 3))
		{
			data_bits.push_back(data[i]);
		}
	}
	out.push_back(data_bits);
	out.push_back(Gets_p_bits(data_bits));
	return out;
}

void Hemming74_d::Decode(const std::vector<uint8_t> &data)
{
	uint8_t N_4_bits = 0; // Переменная количества септ бит и переменная позиции ошибки 
	std::vector<std::vector<uint8_t>> data_and_p_bits; // тут будем хранит ьвектор данных и вектор избыточных бит
	std::vector<uint8_t> tmp_in_data, in_data_p_bits; // вектор в котором хранится текущая септа входных бит
	int pos_error, tmp_pos_err;
	while (N_4_bits < data.size() / 7) // пока не прошли все септы входных данных
	{
		pos_error = 0;
		tmp_pos_err = 0;

		for (size_t i = N_4_bits * 7; i < 7 * (N_4_bits + 1); i++) // скопировали в временный вектор первые 7 бит 
			tmp_in_data.push_back(data[i]);


		data_and_p_bits = Gets_data_p_bits(tmp_in_data); // получили векторы данных и избыточных бит

		in_data_p_bits.push_back(data[0]);
		in_data_p_bits.push_back(data[1]);
		in_data_p_bits.push_back(data[3]);

		for (size_t i = 0; i < 3; i++)
		{
			tmp_pos_err = (int)(data_and_p_bits[1][i] == in_data_p_bits[i]) ? 0 * pow(2, i) : 1 * pow(2, i);
			pos_error = pos_error  + tmp_pos_err;
		}
			  // Получаем позицию ошибки
			

		if (pos_error != 0) // если она есть
		{
			tmp_in_data[pos_error-1] = !tmp_in_data[pos_error-1]; // инвертируем ошибочный бит

			data_and_p_bits = Gets_data_p_bits(tmp_in_data); // заново получаем ветор исправленных данных и вектор избыточных (второй нам больше не нужен)
	
		}
		for (size_t i = 0; i < 4; i++)
			result_data.push_back(data_and_p_bits[0][i]); // Заполняем результат

		N_4_bits++;
		tmp_in_data.clear();
		data_and_p_bits.clear();
		in_data_p_bits.clear();
	}
}