#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct die{
	int (* throw)(int);	//this is a function pointer!
};

int roll(int faces){
	int num = rand() % faces + 1;
	return num;
}

int loaded_roll(int faces){
	int num1 = rand() % faces + 1;
	int num2 = rand() % faces + 1;
	if (num1 > num2) {
		return num1;
	} else {
		return num2;
	}
}

int main(int argc, char** argv){
	if (argc < 3 || argc > 4) {
		fprintf(stderr, "Invalid arguments.\n");
		exit(EXIT_FAILURE);
	}

	int num_faces = atoi(argv[2]);
	if (num_faces == 0) {
		fprintf(stderr, "Invalid number of faces.\n");
		exit(EXIT_FAILURE);
	}

	struct die myDie;

	if (argc == 4) {
		char * flag = strchr(argv[3], '-');
		char * letter = strchr(argv[3], 'l');
		if (flag == NULL && letter == NULL) {
			fprintf(stderr, "flag not recognized.\n");
			exit(EXIT_FAILURE);
		} else {
			myDie.throw = &loaded_roll;	//assign to function pointer
		}
	} else {
		myDie.throw = &roll;	//assign to function pointer
	}
	
	int num_throws = atoi(argv[1]);

	if (num_throws == 0) {
		fprintf(stderr, "Invalid number of throws.\n");
		exit(EXIT_FAILURE);
	}

	srand(time(0));
	for(int i = 0; i < num_throws; i++){
		int my_num = myDie.throw(num_faces);
		printf("%d ", my_num);
	}
	printf("\n");
}


