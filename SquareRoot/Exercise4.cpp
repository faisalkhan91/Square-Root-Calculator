#include <iostream>
#include "tools.hpp"

using namespace std;

int menuSelection(void);
double getDetails(double& pnumber, double& papprox, double& ptol); // Function to get details
double RecSqrRoot(double pnumber, double papprox, double ptol, int count); // Function to get square root recursively
double IteSqrRoot(double pnumber, double papprox, double ptol);// Function to get square root iteratively

int main()
{
    double number; // Number to be calculated
    double approx; // Approximate value after calculations
    double tol; // Closes you want to get to the answer

    int count = 0; // Count for the number of calls recursive function does
    int select; // Menu choice
    string option; // While loop choice to try again

    banner();

    do{
        select = menuSelection();
        switch(select)
        {
            // Case to run recursive function
            case 1:
                do{
                    cout << "\n\n\t Square root using RECURSIVE function" << endl;

                    getDetails(number, approx, tol); // To get the details
                    approx = RecSqrRoot(number, approx, tol, count); // To get the square root

                    cout << "\nSquare root of " << number << " is " << approx << endl;

                    cout << "\nSquare root using BUILT in function is " << sqrt(number) << endl;

                    cout<<"\n -> Do you want to try again? [Y/N]"; // To ask user if they want to enter another item
                    getline(cin>>ws, option);

                    }while(option == "Y" || option == "y" || option == "Yes");
                break;
            // Case to run Iterative function
            case 2:
                do{
                    cout << "\n\n\t Square root using IITERATIVE function" << endl;

                    getDetails(number, approx, tol); // To get the details
                    approx = IteSqrRoot(number, approx, tol); // To get the square root

                    cout << "\nSquare root of " << number << " is " << approx << endl;

                    cout << "\nSquare root using BUILT in function is " << sqrt(number) << endl;

                    cout<<"\n -> Do you want to try again? [Y/N]"; // To ask user if they want to enter another item
                    getline(cin>>ws, option);

                    }while(option == "Y" || option == "y" || option == "Yes");
                break;
            // Case to compare Iterative and Recursive functions
            case 3:
                do{
                    double tapprox;
                    cout << "\n\n\t Square root Comparison between RECURSIVE and IITERATIVE functions" << endl;

                    getDetails(number, approx, tol); // To get the details

                    tapprox = RecSqrRoot(number, approx, tol, count); // To get the square root
                    cout << "\n - Recursive Square root of " << number << " is " << tapprox << endl << endl;

                    tapprox = IteSqrRoot(number, approx, tol); // To get the square root
                    cout << "\n - Iterative Square root of " << number << " is " << tapprox << endl;

                    cout << "\nSquare root using BUILT in function is " << sqrt(number) << endl;

                    cout<<"\n -> Do you want to try again? [Y/N]"; // To ask user if they want to enter another item
                    getline(cin>>ws, option);

                    }while(option == "Y" || option == "y" || option == "Yes");
                break;
            // Case to display a message and quit the program.
            case 4:
                cout<<"\nGood Bye!!!"<<endl;
                break;

            default:
                cout << "Error: Invalid selection. Please try again!" << endl;
        }
    }while(select !=4);

    bye();

    return 0;
}

int menuSelection(void)
// Function: Displays Preconditions for the program and the Switch case menu.
// Precondition: Initializes select.
// Postcondition: Return users choice.
{
    int select;

    cout << "\t Square root calculator \n" << endl;
    // Preconditions for the program
    cout << "*** Limitations on parameters: " << endl;
    cout << "- Number should be a positive real number and not 0(Calculations are using normalized values)" << endl;
    cout << "- Approx should be greater than 0 (or you don't get a solution)" << endl;
    cout << "- Tolerance should be between 0 and 1 (else this leads to indefinite recursions)" << endl << endl;
    // Menu choices
    cout << " MENU OPTIONS " << endl;
    cout << "1. Calculate square root recursively" << endl;
    cout << "2. Calculate square root Iteratively" << endl;
    cout << "3. Square root comparison between Recursive and Iterative functions" << endl;
    cout << "4. Quit" << endl;
    cout << "Select:_";
    cin >> select;

    return select;
}

double getDetails(double& pnumber, double& papprox, double& ptol)
// Function: To get the details to and check if they are within parameter limits
// Precondition: To initialize number, approx and tol. Check if they are within parameter limits.
// Postcondition: To display the entered details and pass entered values by reference.
{
    int flag = 1;

    // Input loop to ask user to enter details and repeat if they do not adhere to parameter limitations.
    do
    {
        cout << "\n\nEnter the number for which square root is to be calculated: " << endl;
        cin >> pnumber;

        cout << "What is the approximate square root value for the number? " << endl;
        cin >> papprox;

        cout << "Please set a tolerance for the square root calculations: " << endl;
        cin >> ptol;

        // Error correction Code
        if (pnumber <= 0 || papprox <= 0 || ptol <= 0 || ptol >= 1)
        {
            cout << "\nError: Parameters exceeding the limitations!" << endl << "Please try again. :)" << endl;
            flag = 1;
        }
        else
            flag = 0;

    }while(flag == 1);

    cout << "\nCalculating square root of " << pnumber << " with a tolerance of " << ptol;
    cout << " . The approximate value entered is : " << papprox << endl << endl;

    return 0;
}

double RecSqrRoot(double pnumber, double papprox, double ptol, int count)
// Function : To calculate the square root of a real number Recursively.
// Precondition : Number should be a positive real number and not 0.
//                Approx should be greater than 0. Tolerance should be between 0 and 1.
// Postcondition : To return the calculated value and and display count.
{
    if (fabs((pow(papprox, 2) - pnumber)) <= ptol)
    {
        cout << "Number of recursive calls to get the solution is " << count << endl;
        return papprox;
    }
    else if (fabs((pow(papprox, 2) - pnumber)) > ptol)
    {
        count ++;
        return RecSqrRoot(pnumber, ((pow(papprox, 2) + pnumber)/(2*papprox)), ptol, count); // Calling function Recursively
    }
}

double IteSqrRoot(double pnumber, double papprox, double ptol)
// Function : To calculate the square root of a real number Iteratively.
// Precondition : Number should be a positive real number and not 0.
//                Approx should be greater than 0. Tolerance should be between 0 and 1.
// Postcondition : To return the calculated value and and display count.
{
    int count = 0; // Count the number of time loop executes

    //Loop to calculate the square root iteratively
    while (fabs((pow(papprox, 2) - pnumber)) > ptol)
    {
        papprox = ((pow(papprox, 2) + pnumber)/(2*papprox));

        count++;

        if (fabs((pow(papprox, 2) - pnumber)) <= ptol)
        {
            break;
        }
    }

    cout << "Number of Iterations needed to get the solution is " << count << endl;

    return papprox;
}
