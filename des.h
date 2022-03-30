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

string	get_ip_plaintext(string plaintext)

#endif
