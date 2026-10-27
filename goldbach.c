/* This is the program for exercise 3 of hw0 */

#include <stdio.h>

int main() {
	int answer; //For number
 	int answer2;//For letter (p or g)

	do {
		printf("Give me a number: "); //Asking user to type a number of their choice
  		unsigned long long int number; // Number is expected to be an integer between 0 and 10 billion
  		answer=scanf("%llu", &number);
		char nextchar=getchar(); //Will check if the character after the number is "." or ","

  		//Checking number//
  		if (answer==EOF) {
    			printf("EOF detected, exiting\n"); //Exiting program due to EOF
    			return 0;
  		}

  		else if (answer!=1 || nextchar=='.' || nextchar==',') { //If number is NOT integer
    			fprintf(stderr, "Invalid input: expected an integer\n");
    			return 1;
  		}

  		else { //If number is integer

    			if (number<0 || number>10000000000ULL) { //If integer number is NOT in right range
      				fprintf(stderr, "Number should be in the range [0, 10000000000]\n");
      				return 1;
    			}

    			else { //If number is correct type and range

				//Asking user to choose how they want to test their number

      				printf("Choose how to test %llu (type 'p' for prime, or 'g' for goldbach): ", number);
      				char test; //Test should be p or g, so a character
      				answer2=scanf(" %c", &test);

      				//Checking test//

      				if (answer2==EOF) {
        				printf("EOF detected, exiting\n"); //Exiting due to EOF
        				return 0;
      				}
      				else if (answer2!=1) { //If test is NOT character
        			fprintf(stderr, "Invalid choice: expected 'p' or 'g'\n");
        			return 1;
      				}
      				else { //If test is a character
        				if (test!='p' && test!='g') { //If test is not p/g
	  				fprintf(stderr, "Invalid choice: expected 'p' or 'g'\n");
          				return 1;
					}
					else { //If test is correct type and letter
	  					if (test=='p') { //If prime is chosen
	    						if (number<2) {
	      							printf("%llu is not prime\n", number); //A positive integer is
								//prime only if number>=2//
							}
	    						else { //If number >=2
	      							unsigned long long int prime=0;
	      								for (unsigned long long int i=2; i*i<=number; i++) {
	        							if (number % i == 0) {
	          								prime+=1; //Amount of times the number can be
							              //divided evenly by numbers from 2 to the root of the number/
	        							}
	      							}
	      							if (prime==0) {
	        							printf("%llu is prime\n", number); //Because it's only
								//divided evenly by 1 and itself//
	      							}
	      							else {
	        							printf("%llu is not prime\n", number); //If prime>0,
					          //chosen number can be divided evenly not just by 1 and itself, so it's not prime
	      							}
	   						}
         					}
	  					else { //If goldbach is chosen
	    						if (number<=2 || number % 2 == 1) {
						//Showing user which numbers can be used for Goldbach conjecture//
	      				printf("Goldbach's conjecture is applicable only to even numbers greater than 2!\n");
	    						}
	    						else { //If given number is even AND >2
	      							unsigned long long int i=2; //1st number of sum (Initializing
										//i using value 2 because 1 is not prime//
	      							unsigned long long int j=number - 2;//2nd number of sum
	      							int found = 0; //Flag for when the sum is found
              								while (i<=j && found==0) {
	      	  								unsigned long long int prime2=0;
								//Using the same technique to check if i is prime
	      	  							for (unsigned long long int num1=2; num1*num1<=i; num1++) {
	      	    								if (i % num1 == 0) {
	      	      							    		prime2+=1;
	            								}
                  							  }
								//If i is prime, check if j is also prime
	       	  							  if (prime2==0) {
	      	     						//Same techique to check if j is prime
									for (unsigned long long int num2=2; num2*num2<=j; num2++) {
	      	      								if (j % num2 == 0) {
	      	        								prime2+=1;
       	      	      								}
      	      	    						           }
      	      	    							   if (prime2==0) { //If j is also prime
                      						           found = 1; //Sum is found
									   //i is the smallest number, so it's printed first
      	      	      							   printf ("%llu = %llu + %llu\n", number, i, j);
      	      	    						           }
      	      	  						          }
                							++i; //Change value for i
                							--j; //Change value for j
									} //End of while
      	    						    } //End of else (if given number is even and >=2)
							} //End of else (if goldbach is chosen)
      					} //End of else (if test is correct type and letter)
     				}//End of else (if test is a character)
    			}//End of else (if number is correct type and range)
  		}//End of else (if number is integer)
	} while (answer!= EOF && answer2!=EOF); //Repeat all of it until answer is EOF (either for 1st or 2nd question)
return 0;
}//End of main
