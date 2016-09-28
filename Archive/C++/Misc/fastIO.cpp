inline void Scan_f(long long *a)
{
	char c = 0;
	while(c<33)
		c = fgetc_unlocked(stdin);
	//c = getc(stdin);
	*a = 0;
	while(c>33){
		*a = (*a)*10 + c - '0';
		c = fgetc_unlocked(stdin);
		//c = getc(stdin);
	}
}	
// Scan_f(&input);