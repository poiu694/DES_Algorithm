#include "des.h"

void	print_origin(string plaintext, string key)
{
	printf("---------------------------------------------\n");
	printf("plaint text : %s\n", plaintext.c_str());
	printf("origin key : %s\n", key.c_str());
	printf("---------------------------------------------\n");
}

int	main(int argc, char **argv)
{
	string	encrypt;

	if (argc == 3)
	{
		print_origin(argv[1], argv[2]);
		encrypt = des_algorhtim(argv[1], argv[2]);
		printf("---------------------------------------------\n");
		printf("encrypt : %s\n", encrypt.c_str());
		printf("size : %lu\n", encrypt.length());
		printf("---------------------------------------------\n");
	}
	else
	{
		printf("input error, put the plainText, key both\n");
	}
	return (0);
}
