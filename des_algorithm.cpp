#include "des.h"

void	print_origin(string plaintext, string key)
{
	printf("---------------------------------------------\n");
	printf("plaint text : %s\n", plaintext.c_str());
	printf("origin key : %s\n", key.c_str());
	printf("---------------------------------------------\n");
}

string des_algorhtim(string plaintext, string key)
{
	string	left_key;
	string	right_key;
	string	des_key;

	print_origin(plaintext, key);
	des_key = generate_init_key(key, left_key, right_key);
	printf("====================%d======================\n", 1);
	printf("key : %10s\n",des_key.c_str());
	printf("============================================\n");
	for (int i=2; i<=16; i++)
	{
		printf("====================%d======================\n", i);
		des_key = generate_key(left_key, right_key, i);	
		printf("key : %10s\n",des_key.c_str());
		printf("============================================\n");
	}
	return (des_key);
}
