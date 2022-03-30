#include "des.h"

int	main(int argc, char **argv)
{
	string	encrypt;

	if (argc == 3)
	{
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
