#include "des.h"

string	ip_plaintext(string plaintext)
{
	int		index;
	string	ret;

	for (int i=0; i<plaintext.length(); i++)
	{
		index = initialPermutationTable[i];
		ret += plaintext[index - 1];
	}
	return (ret);
}

void	set_left_right_key(string key, string &left_key, string &right_key)
{
	left_key = key.substr(0, 32);
	right_key = key.substr(32, 32);
}

string	expansion_right_key(string key)
{
	int		index;
	string	ret;

	for (int i=0; i<expansionPermutationTable.size(); i++)
	{
		index = expansionPermutationTable[i];
		ret += key[index - 1];
	}
	return (ret);
}

int	get_sbox_value(string token, int index)
{
	int		row;
	int		col;
	string	tk1;
	string	tk2;

	cout << "Token\n" << token << '\n';;
	tk1 = token[0] + token[5];
	tk2 = token[1] + token[2] + token[3] + token[4];
	cout << tk1 << " " << tk2 << '\n';
	row = get_int_bit2(tk1);
	col = get_int_bit4(tk2);
	if (index == 1)
		return (s1[row][col]);
	if (index == 2)
		return (s2[row][col]);
	if (index == 3)
		return (s3[row][col]);
	if (index == 4)
		return (s4[row][col]);
	if (index == 5)
		return (s5[row][col]);
	if (index == 6)
		return (s6[row][col]);
	if (index == 7)
		return (s7[row][col]);
	if (index == 8)
		return (s8[row][col]);
	return (-1);
}

string	get_sbox_key(string key)
{
	string	key1 = key.substr(0, 6);
	string	key2 = key.substr(6, 6);
	string	key3 = key.substr(12, 6);
	string	key4 = key.substr(18, 6);
	string	key5 = key.substr(24, 6);
	string	key6 = key.substr(30, 6);
	string	key7 = key.substr(36, 6);
	string	key8 = key.substr(42, 6);
	string	ret;

	cout << key8 << '\n';
	ret = get_int_to_bits(get_sbox_value(key1, 1));
	ret += get_int_to_bits(get_sbox_value(key2, 2));
	ret += get_int_to_bits(get_sbox_value(key3, 3));
	ret += get_int_to_bits(get_sbox_value(key4, 4));
	ret += get_int_to_bits(get_sbox_value(key5, 5));
	ret += get_int_to_bits(get_sbox_value(key6, 6));
	ret += get_int_to_bits(get_sbox_value(key7, 7));
	ret += get_int_to_bits(get_sbox_value(key8, 8));
	return (ret);
}
