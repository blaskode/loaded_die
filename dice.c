#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct die{
	int (* throw)();	//this is a function pointer!
};

int roll(){
	int num = rand() % 6 + 1;
	return num;
}

int loaded_roll(){
	int num1 = rand() % 6 + 1;
	int num2 = rand() % 6 + 1;
	if (num1 > num2) {
		return num1;
	} else {
		return num2;
	}
}

int main(void){
	srand(time(0));

	/*Create a non-loaded die*/
	struct die myDie;
	myDie.throw = &roll;

	/*Creates a loaded die*/
	struct die myLoadedDie;
	myLoadedDie.throw = &loaded_roll;

	/*Roll each die*/
	int my_num = myDie.throw();
	int my_loaded_num = myLoadedDie.throw();

	printf("%d\n", my_num);
	printf("%d\n", my_loaded_num);
}