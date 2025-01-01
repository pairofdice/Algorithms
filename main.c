#include <stdio.h>

int main( void ) {
	FILE *fp;
	errno_t err;
	char s[1024];
	int linecount = 0;

	err = fopen_s(&fp, "input.txt", "r");
	if (err == 0)
		printf("File 'input.txt' opened succesfully.\n");
	else
		printf("Failed to open 'input.txt'\n");

	while (fgets(s, sizeof s, fp) != NULL)
	{
		printf("%3.d: %s", ++linecount, s);
	}

	if (fp) {

		err = fclose(fp);
		if (err == 0)
			printf("File 'input.txt' closed\n");
		else
			printf("File NOT closed??\n");
		
	}


}
