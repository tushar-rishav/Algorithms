#include<bits/stdc++.h>

int GetPrime ( int **primeSet, int upperLimit );
bool *isPrime = 0;

int main ( void )
{
    // The lower limit is 2 by default, and variable bounder is the upper limit
    int *prime, bounder;
    printf ( "Please enter the bounder of the searching range\n" );
    scanf ( "%d", &bounder );
    getchar ();
    isPrime = (bool*)malloc ( (bounder + 1) >> 1 );

    double start = clock ()/(double)CLOCKS_PER_SEC;
    int numberPrimes = GetPrime ( &prime, bounder );
    double end = clock ()/(double)CLOCKS_PER_SEC;

    double interval = end - start;
    printf ( "%f\n", interval );

    int printOut = 0;
    printf ( "Have everything print out ?\n" );
    printf ( "<0> No\n" );
    printf ( "<1> To file\n" );
    printf ( "<2> Display\n" );
    scanf ( "%d", &printOut );

	if ( printOut == 1 )
	{
		FILE *file = fopen ( "Test", "w+" );

		// Print out all the prime number found
		for ( int i = 0; i < numberPrimes; i++ )
		{
			fprintf ( file, "%d ", prime[i] );

		}// End For ( Each found )

		fclose ( file );
	}
	else if ( printOut == 2 )
	{
		// Print out all the prime number found
		for ( int i = 0; i < numberPrimes; i++ )
		{
			printf ( "%d ", prime[i] );

		}// End For ( Each found )

	}// End If

	free ( isPrime );
    free ( prime );
    return 0;

}// End Function

int GetPrime ( int **primeSet, int upperLimit )
{
    // A list use to determine whether the subscript is a prime number
    // And it holds odd numbers only, for example, isPrime[1] means whether 3 is a prime number,
    // isPrime[2] means whether 5 is a prime number
    for ( int i = 0; i <= (upperLimit >> 1); i++ )		// Does not count 0, 1, 2
    {
        isPrime[i] = true;

    }// End For

    // Then we filter out all numbers that is not a prime number
    // When doing this, never takes even numbers into account
    // And there is no need analyze the numbers which are greater than sqrt ( upperLimit )
    // Because those are repeating work
    int end = (int)sqrtf ( upperLimit );
    for ( int i = 3; i <= end; i += 2 )
    {
        if ( isPrime[i >> 1] )
        {
            // When a number is a combination of two or more prime number must
            // Be a composite number
            for ( int composite = 3; i*composite <= upperLimit; composite += 2 )
            {
                isPrime[(i*composite) >> 1] = false;

            }// End For ( Each predictable composite )

        }// End If ( Can be used for fitlering )

    }// End For

	*primeSet = (int*)malloc ( sizeof ( int )*(upperLimit + 1) );
	int *_primeSet = *primeSet;

    // Store back the result in term of a set
    int i, j;
    for ( i = 1, j = 1; j < (upperLimit >> 1); j++ )
    {
        if ( isPrime[j] )
        {
            _primeSet[i] = (j << 1) + 1;
            i++;

        }// End If ( if it is a prime number )

    }// End For

    // Can not forget that 1 + 1 question ^_^
    _primeSet[0] = 2;

    return i;

}// End Function