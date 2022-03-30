#include "des.h"

void	print_log(int round, string key1, string key2, string token)
{
	printf("%10d %10s %10s %10s\n", round, key1.c_str(), key2.c_str(), token.c_str());
}

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
	string	xor_32;
	string	encrypted_key;

	plain64 = get_entire_bit_key(plaintext);
	plain64 = ip_plaintext(plain64);
	set_left_right_key(plain64, plain_left_key, plain_right_key);
	expansion_key = expansion_right_key(plain_right_key);
	des_key = generate_init_key(key, left_key, right_key);
	xor_key = xor_bit48(expansion_key, get_entire_bit_key(des_key));
	sbox_key = get_sbox_key(xor_key);
	sbox_key = get_sbox_permutation(sbox_key);
	xor_32 = xor_bit32(plain_left_key, sbox_key);
	printf("%10s %10s %10s %10s\n", "round", "left", "right", "round key");
	print_log(1, get_bits_to_hexa_bits(plain_left_key), get_bits_to_hexa_bits(plain_right_key), des_key);
	plain_left_key = plain_right_key;
	plain_right_key = xor_32;
	for (int i=2; i<=16; i++)
	{
		des_key = generate_key(left_key, right_key, i);
		print_log(i, get_bits_to_hexa_bits(plain_left_key), get_bits_to_hexa_bits(plain_right_key), des_key);
		expansion_key = expansion_right_key(plain_right_key);
		xor_key = xor_bit48(expansion_key, get_entire_bit_key(des_key));
		sbox_key = get_sbox_key(xor_key);
		sbox_key = get_sbox_permutation(sbox_key);
		xor_32 = xor_bit32(plain_left_key, sbox_key);
		plain_left_key = plain_right_key;
		plain_right_key = xor_32;
	}
	plain64 = plain_right_key + plain_left_key;
	encrypted_key = get_bits_to_hexa_bits(inverse_ip(plain64));
	return (encrypted_key);
}
