#include<stdio.h>
#include<string.h>
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}


void test_arg(int argc,char **argv){

	int i;
	for(i=1; i<argc; i++){
		printf("%d %s\n", i, argv[i]);
	}
}


int main(int argc,char ** argv){

	test_arg(argc, argv);
	
	char *argv2[5];
	argv2[0] = "ignored";
	argv2[1] = "-reverseHost";
	argv2[2] = "localhost";
	argv2[3] = "-reversePort";
	argv2[4] = "5500";


	test_arg(5, argv2);

	char *argv3[] = { "ignored", "-reverseHost", "localhost", "-reversePort", "5500"};
	
	int len3;
	GET_ARRAY_LEN(argv3, len3); 
	test_arg(len3, argv3);

	return 0;
	
}
