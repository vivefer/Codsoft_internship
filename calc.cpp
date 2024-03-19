#include <iostream>

using namespace std;

double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);

int main()
{
    char operation;
    double num1, num2;

    while (true) 
	{
        cout << "Enter the operation you want to perform (+, -, *, /) or 'q' to quit: ";
        cin >> operation;

        if (operation == 'q' || operation == 'Q')
            break;

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (operation) 
		{
            case '+':
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case '-':
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case '*':
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case '/':
                cout << "Result: " << divide(num1, num2) << endl;
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    }

    cout << "Exiting the calculator program." << endl;

    return 0;
}

double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    if (y != 0)
        return x / y;
    else {
        cout << "Error! Division by zero." << endl;
        return 0;
    }
}
