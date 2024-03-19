#include <iostream>

using namespace std;

int Rand()
{
 uintptr_t random_address = reinterpret_cast<uintptr_t>(std::malloc(1)); // Allocating memory just to get its address

    // Convert the memory address into an integer which will the random number
   int rand_num = static_cast<unsigned int>(random_address);

    // Free the allocated memory
	free(reinterpret_cast<void*>(random_address));

    return rand_num%100;
}

int main()
{
    int rn = Rand(); //random number
    int en; //entered number
    cout << "\t\t\t\t##### WELCOME TO NUMBER GUESSING GAME #####\t\t\t\t\n\n" << endl;
	cout << "\t\t\t\t                INSTRUCTIONS!              \t\t\t\t\n" << endl;
	cout << "1. Enter your guess for the random number between 0-100 " << endl;
	cout << "2. You'll get a message if the number is too high or too low" << endl;
	cout << "3. Keep entering your guesses according to the feedbacks " << endl;
	cout << "4. You'll get a message when your guess is right \n\n" << endl;	
    again:
    cout << "Enter your guess: " ;
	cin >> en ;
	if (en>rn)
	{
		cout << "The number is too high" << endl;
		goto again;
	}
    else if (en<rn)
    {
    	cout << "The number is too low" << endl;
		goto again;
	}
	else
		cout << "The guess is right!" << endl;
	cout << "\t\t\t\t      ##### THANKS FOR PLAYING! #####       \t\t\t\t\n" << endl;
	
    return 0;
}
