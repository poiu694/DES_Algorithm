#include "des.h"

string	xor_bit48(string key1, string key2)
{
	bitset<48>	output;
	bitset<48>	bits1(key1);
	bitset<48>	bits2(key2);

	output = bits1 ^ bits2;
	return (output.to_string());
}

string	xor_bit32(string key1, string key2)
{
	bitset<32>	output;
	bitset<32>	bits1(key1);
	bitset<32>	bits2(key2);

	output = bits1 ^ bits2;
	return (output.to_string());
}

string	get_int_to_bits(int num)
{
	switch(num)
	{
		case 0:
			return ("0000");
		case 1:
			return ("0001");
		case 2:
			return ("0010");
		case 3:
			return ("0011");
		case 4:
			return ("0100");
		case 5:
			return ("0101");
		case 6:
			return ("0110");
		case 7:
			return ("0111");
		case 8:
			return ("1000");
		case 9:
			return ("1001");
		case 10:
			return ("1010");
		case 11:
			return ("1011");
		case 12:
			return ("1100");
		case 13:
			return ("1101");
		case 14:
			return ("1110");
		case 15:
			return ("1111");
	}
	return ("null");
}

int	get_int_bit2(string bit)
{
	bitset<2>	bits(bit);

	return ((int)bits.to_ulong());
}

int	get_int_bit4(string bit)
{
	bitset<4>	bits(bit);

	return ((int)bits.to_ulong());
}


string	get_bit_hex_alphabet(char ch)
{
	if (ch == 'A')
		return ("1010");
	if (ch == 'B')
		return ("1011");
	if (ch == 'C')
		return ("1100");
	if (ch == 'D')
		return ("1101");
	if (ch == 'E')
		return ("1110");
	if (ch == 'F')
		return ("1111");
	return (NULL);
}

string	get_bits_to_hexa_bits(string bits)
{
	string				hexa_bits;
	stringstream	ss;
	bitset<4>			temp_bits;

	for (int i=0; i<bits.length(); i+=4)
	{
		temp_bits = bitset<4>(bits.substr(i, 4));
		ss << hex << uppercase << temp_bits.to_ulong();
		hexa_bits += ss.str();
		ss.str("");
	}
	return (hexa_bits);
}