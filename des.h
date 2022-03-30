#ifndef DES_H
# define DES_H

# include <cstring>
# include <iostream>
# include <algorithm>
# include <bitset>
# include <sstream>

# include "constant.h"

using namespace std;

string	des_algorhtim(string plaintext, string key);

string	generate_init_key(string key, string &left_key, string &right_key);
string	generate_key(string &left_key, string &right_key, int round);

string	get_ip_plaintext(string plaintext);
string	get_bit_hex_alphabet(char ch);

string	get_bits_to_hexa_bits(string bits);
string	get_entire_bit_key(string key);
string	get_key56_by_permutation_table(string key64);
string	get_key48_by_permutation_table(string key56);
void	shift_left_count(string &key, int count);

string	ip_plaintext(string plaintext);
void	set_left_right_key(string key, string &left_key, string &right_key);
string	expansion_right_key(string key);

string	xor_bit36(string key1, string key2);
string	xor_bit48(string key1, string key2);
string	get_sbox_key(string key);
int	get_int_bit2(string bit);
int	get_int_bit4(string bit);
string	get_int_to_bits(int num);

#endif
