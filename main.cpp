#include "des.h"

int	main(int argc, char **argv)
{
	string	encrypt;

	if (argc == 3)
	{
		encrypt = des_algorhtim(argv[1], argv[2]);
		printf("---------------------------------------------\n");
		printf("Plain text  : %10s\n", argv[1]);
		printf("Key         : %10s\n", argv[2]);
		printf("Cipher text : %10s\n", encrypt.c_str());
		printf("Plain text  : %10s\n", get_entire_bit_key(argv[1]).c_str());	
		printf("Key         : %10s\n", get_entire_bit_key(argv[2]).c_str());
		printf("Cipher text : %10s\n", get_entire_bit_key(encrypt).c_str());
		printf("---------------------------------------------\n");
	}
	else
	{
		printf("input error, put the plainText, key both\n");
	}
	return (0);
}
