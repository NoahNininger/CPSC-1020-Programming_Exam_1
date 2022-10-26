#include <iostream>
// return true if n is odd otherwise return false
bool isOdd(int n)
{
    if ((n % 2) != 0)
        { return true; }
    else
        { return false; }
}

// return the number of elements in the 3n+1 sequence of n
int len3nplus1(int n)
{
    int count = 1;

    do
    {
        if (isOdd(n) == true)       // preforms 3n+1 if number is odd
        {
            n = 3 * n + 1;
            count = count + 1;
        }
        else                        // divides number by 2 if number is odd
        {
            n = n / 2;
            count = count + 1;
        }
    } while (n != 1);               // loops until n = 1

    return count;
}

// returns the sum of the 3n+1 sequence
int sumSeq3nPlus1(int n)
{
    int sum = n;

    do
    {
        if (isOdd(n) == true)       // preforms 3n+1 if number is odd
        {
            n = 3 * n + 1;
            sum = sum + n;
        }
        else                        // divides number by 2 if number is odd
        {
            n = n / 2;
            sum = sum + n;
        }
    } while (n != 1);               // loops until n = 1

    return sum;
}

// returns the number in the range from 1 to max that has the longest 3n+1 sequence; if there is more than 1, return the first one. 
int longestSequence(int max)
{
    int baseMax = 1;    // sets the base max to the sequence of 1 (which is 1)
    int longest;

    for (int i = 1; i <= max; ++i)      // loops until i is equal to max
    {
        if (len3nplus1(i) > baseMax)    // if longest sequence is greater than the base max
            { 
                baseMax = len3nplus1(i);
                longest = i;
            }
        else if (len3nplus1(i) == baseMax)      // sets the longest sequence to the first longest if there are 2 of the same length
            {
                baseMax = len3nplus1(i);
                longest = baseMax;
            }
    }

    return longest;
}

int main()      // takes input from user and prints results
{
    int userInput, num, max;

    std::cout << "Choose one of the following" << std::endl
              << "--------------------------------------------------" << std::endl
              << "1 - Find the length & sum of a 3N+1 sequence" << std::endl
              << "2 - Find the largest sequence from a list of 1-N" << std::endl;

    std::cin >> userInput;

    switch (userInput)
    {
        case 1:
            std::cout << std::endl << "3N+1" << std::endl
              << "------------------------------------" << std::endl
              << "Enter a number to sub for N: ";
            std::cin >> num;

            std::cout << "Length: " << len3nplus1(num) << std::endl
                      << "Sum: " << sumSeq3nPlus1(num) << std::endl;
            break;
        case 2:
            std::cout << std::endl << "Enter the maximum number for a list that counts up from 1: ";
            std::cin >> max;

            std::cout << "Largest Sequence: " << longestSequence(max) << std::endl;
            break;
    }

    return 0;
}