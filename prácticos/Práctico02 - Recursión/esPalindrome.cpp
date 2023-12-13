
bool esPalindrome(char * frase, uint largo) {
	return esPalindromeAux(frase, 0, largo-1);
}

bool esPalindromeAux(char * frase, uint inf, uint sup) {
	bool aux;
	if(inf >= sup) {
		aux = true;
	} else if (frase[inf] != frase[sup]) {
		aux = false;
	} else {
		aux = esPalindromeAux( frase, inf+1, sup-1);
	}
}

bool esPalindromeAux(char * frase, uint inf, uint sup) {
	return inf>=sup || (frase[inf] == frase[sup] && esPalindromeAux(frase,inf+1, sup-1));
}