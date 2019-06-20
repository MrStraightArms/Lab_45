#include "../../Libraries/Classes/Decoder/Decoders.hpp"
#include "../../Libraries/Classes/Encoder/Encoders.hpp"
#include <gtest/gtest.h>

TEST(_Encoder, encoding)
{
	Encoder *encoder = new Hemming74;
	std::vector<uint8_t> main = {'0','1','1','1','0','1','0','0','1','1','1','0','1','0',};
	std::vector<uint8_t> test = encoder->Get_char_to_bits("10101010");
	encoder->Encode(test);
	ASSERT_TRUE(main == encoder->result);

	delete encoder;
}
TEST(_Encoder, all_zero)
{
	Encoder *encoder = new Hemming74;
	std::vector<uint8_t> main = { '0','0','0','0','0','0','0','0','0','0','0','0','0','0', };
	std::vector<uint8_t> test = encoder->Get_char_to_bits("00000000");
	encoder->Encode(test);
	ASSERT_TRUE(main == encoder->result);

	delete encoder;
}

TEST(_Dencoder, decoding)
{
	Decoder *decoder = new Hemming74_d;
	std::vector<uint8_t> main = { 1,0,1,0,1,0,1,0};
	std::vector<uint8_t> in_test = { 0,1,1,1,0,1,0,0,1,1,1,0,1,0 };
	decoder->Decode(in_test);
	ASSERT_TRUE(main == decoder->result_data);

	delete decoder;
}

TEST(_Dencoder, correct_error_3_bit_10_bit)
{
	Decoder *decoder = new Hemming74_d;
	std::vector<uint8_t> main = {1,0,1,0,1,0,1,0};
	std::vector<uint8_t> in_test = {0,1,0,1,0,1,0,0,1,0,1,0,1,0}; // ќшибка в 3-м и 10-м бите
	decoder->Decode(in_test);
	ASSERT_TRUE(main == decoder->result_data);

	delete decoder;
}

TEST(_Dencoder, all_zero)
{
	Decoder *decoder = new Hemming74_d;
	std::vector<uint8_t> main = { 0,0,0,0,0,0,0,0 };
	std::vector<uint8_t> in_test = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; // ќшибка в 3-м и 10-м бите
	decoder->Decode(in_test);
	ASSERT_TRUE(main == decoder->result_data);

	delete decoder;
}


int main(int argc, char **argv)
{
	setlocale(LC_ALL, "Russian");
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
