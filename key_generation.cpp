#include "des.h"

using namespace std;

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

string	get_entire_bit_key(string key)
{
	const char	*c_key = key.c_str();
	bitset<4>		bit4;
	string			ret;

	ret = "";
	for (int i=0; i<key.length(); i++)
	{
		bit4 = bitset<4>(c_key[i]);
		if (c_key[i] == 'A' || c_key[i] == 'B' || c_key[i] == 'C'
				|| c_key[i] == 'D' || c_key[i] == 'E' || c_key[i] == 'F')
			ret += get_bit_hex_alphabet(c_key[i]);
		else
			ret += bit4.to_string();
	}
	return (ret);
}

string	get_key56_by_permutation_table(string key64)
{
	int			index;
	string	key56;

	for (int i=0; i<parityBitDropTable.size(); i++)
	{
		index = (int) parityBitDropTable[i];
		key56 += key64[index - 1];
	}
	return (key56);
}

string	get_key48_by_permutation_table(string key56)
{
	int			index;
	string	key48;

	for (int i=0; i<keyCompressionTable.size(); i++)
	{
		index = (int) keyCompressionTable[i];
		key48 += key56[index - 1];
	}
	return (key48);
}

void	shift_left_count(string &key, int count)
{
	if (key.length() < count)
	{
		printf("ERROR COUNT\n");
		return ;
	}
	rotate(key.begin(), key.begin() + count, key.end());
}

string	generate_init_key(string key, string &left_key, string &right_key)
{
	string	key64;
	string	key56;
	string	key48;

	key64 = get_entire_bit_key(key);
	key56 = get_key56_by_permutation_table(key64);
	left_key = key56.substr(0, 28);
	right_key = key56.substr(28, 28);
	shift_left_count(left_key, 1);
	shift_left_count(right_key, 1);
	key56 = left_key + right_key;
	key48 = get_key48_by_permutation_table(key56);
	return (get_bits_to_hexa_bits(key48));
}

string	generate_key(string &left_key, string &right_key, int round)
{
	string	key48;
	string	key56;
	
	if (round == 2 || round == 9 || round == 16)
	{
		shift_left_count(left_key, 1);
		shift_left_count(right_key, 1);
	}
	else
	{
		shift_left_count(left_key, 2);
		shift_left_count(right_key, 2);
	}
	key56 = left_key + right_key;
	key48 = get_key48_by_permutation_table(key56);
	return (get_bits_to_hexa_bits(key48));
}
