/*
* Thank you to mrfancypants for research and preliminary Python code for ATTXXXXXXX networks.
*/

#define ATT_PSK_LEN 13
#include <stdint.h>

static const char CHARSET[] = "abcdefghijkmnpqrstuvwxyz23456789#%+=?";

char *genpass589(uint32_t x) {

	char *psk = malloc(ATT_PSK_LEN + 1);

	uint64_t one = x * 465661287.5245797; // thank you mrfancypants for finding this number
	uint64_t two = one;
	int i;

	for (i = 0; i < 6; i++) {
		int key1 = CHARSET[two % 37];
		two /= 37;
		int key2 = 50 + (two % 8);
		two /= 37;
		psk[(10 - (i * 2)) + 1] = key1;
		psk[(10 - (i * 2))] = key2;
	}
	return psk;
}

// nvg599 password algorithm
/*void genpass599(unsigned x, unsigned char *buf) {
	static const char CHARSET[] = "abcdefghijkmnpqrstuvwxyz23456789#%+=?";
	buf[12] = 0; // create buffer for password

	fnn = (double) (x * ((1l << 32) + 2));
	for (i = 1; i < PW_LENGTH; i++, fnn /= 37) {
		buf[PW_LENGTH - i - 1] = CHARSET[fnn % 37];
	}
}*/
