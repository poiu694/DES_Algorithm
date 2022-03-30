#include "des.h"

string des_algorhtim(string plaintext, string key)
{
	string	plain_left_key;
	string	plain_right_key;
	string	expansion_key;
	string	xor_key;
	string	plain64;
	string	left_key;
	string	right_key;
	string	des_key;
	string	sbox_key;

	plain64 = get_entire_bit_key(plaintext);
	set_left_right_key(plain64, plain_left_key, plain_right_key);
	expansion_key = expansion_right_key(plain_right_key);
	des_key = generate_init_key(key, left_key, right_key);
	xor_key = xor_bit48(expansion_key, get_entire_bit_key(des_key));
	sbox_key = get_sbox_key(xor_key);
	cout << sbox_key << '\n';
	for (int i=2; i<=16; i++)
	{
		des_key = generate_key(left_key, right_key, i);	
	}
	return (des_key);
}
