





/*
The program below takes in the users info and calculates their taxes for the year 2022
        -in the funtions youll notice that there are a lot of printf() lines, those are for testing/debugging if any changes are to be made in the future

Enter 539,871 to reach all tax brackets for 'single'
Enter 647,851 to reach all tax brackets for 'married jointly'
Enter 539,901 to reach all tax brackets for 'head of household'

*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//current years tax rate for single people, these are for the year 2022


void firstTax (float income, float *first, float *totalTaxPaid); //these functions are for single filing status
void secondTax (float income, float *second, float *totalTaxPaid);
void thirdTax (float income, float *third, float *totalTaxPaid);
void fourthTax (float income, float *fourth, float *totalTaxPaid);
void fifthTax (float income, float *fifth, float *totalTaxPaid);
void sixthTax (float income, float *sixth, float *totalTaxPaid);
void seventhTax (float income, float *seventh, float *sixth, float *totalTaxPaid);



void married_firstTax(float income, float *first, float *totalTaxPaid);//these functions are for married status
void married_secondTax (float income, float *second, float *totalTaxPaid);
void married_thirdTax (float income, float *third, float *totalTaxPaid);
void married_fourthTax (float income, float *fourth, float *totalTaxPaid);
void married_fifthTax (float income, float *fifth, float *totalTaxPaid);
void married_sixthTax (float income, float *sixth, float *totalTaxPaid);
void married_seventhTax (float income, float *seventh, float *sixth, float *totalTaxPaid);



void head_firstTax(float income, float *first, float *totalTaxPaid);//these functions are for head of household status
void head_secondTax (float income, float *second, float *totalTaxPaid);
void head_thirdTax (float income, float *third, float *totalTaxPaid);
void head_fourthTax (float income, float *fourth, float *totalTaxPaid);
void head_fifthTax (float income, float *fifth, float *totalTaxPaid);
void head_sixthTax (float income, float *sixth, float *totalTaxPaid);
void head_seventhTax (float income, float *seventh, float *sixth, float *totalTaxPaid);




int main()
{
  
    float income, first, second, third, fourth, fifth, sixth, seventh, totalTaxPaid = 0;//variables  
    char* fillingStatus[3] = {"Single", "Married Jointly", "Head of HouseHold\n"};  //stores array for option of status
    char choice_str[20]; // Buffer to store user input as a string
    int valid_choice = 0; // Variable to track if the user entered a valid choice

  
while (!valid_choice) //loops until user enters correct answer
{
    printf("How will you filing your taxes this year?\nType out what your filling status would be\n");
    for (int i = 0; i < 3; i++)       //loop to printout options in array 
    {
      printf("%d. %s\n", i + 1, fillingStatus[i]);  //NTS:arrays start at 0 not 1 so +1
    }
    fgets(choice_str, sizeof(choice_str), stdin); // Read user input as a string.....
                                                //(what to read, the size of it, just always use stdin for now)
                                                
    size_t len = strlen(choice_str);// Removes newline character
    if (len > 0 && choice_str[len - 1] == '\n') 
    {
        choice_str[len - 1] = '\0';
    }

    for (size_t i = 0; i < len; i++)     // Changes string to lowercase just to make things easier for code
    {
        choice_str[i] = tolower(choice_str[i]);
    }
//****************************  single path    ************************************************************************************
    if (strcmp(choice_str, "single") == 0)     // Compare the input string and determine the path based on it
    {
            printf("You chose to file as single, what is your income?\n");
            printf ("Enter your income: ");
            scanf ("%f", &income);
            
            
        
            firstTax (income, &first, &totalTaxPaid);//calls function to start calculating tax
           if (income >= 10275)		//checks to see if program keeps going or not
            {
                income -= 10275;		//eliminating the money that has already been taxed
              //printf ("Income being processed for next tax bracket(2nd) = %.2f\n", first);

            }
           else
            {
                printf ("Your income was taxed, you reached the First Bracket\n");
                printf("Total tax paid: %.2f\n", totalTaxPaid);

                return 0;			//user didnt fit into next tax bracket so program ends
            }


            secondTax (income, &second, &totalTaxPaid);
            if (income >= 31500)
            {
            income -= 31500;
            //printf ("income being proccessed for next tax bracket(3rd) = %.2f\n",second);

            }
            else
            {
                  printf ("Your income was taxed, you reached the Second Bracket\n");
                  printf("Total tax paid: %.2f\n", totalTaxPaid);

                  return 0;
            }


            thirdTax (income, &third, &totalTaxPaid);
            if (income >= 47300)
            {
            income -= 47300;
            //printf ("income being proccessed for next tax bracket(4th) = %.2f\n", third);

            }
            else
            {
                  printf ("Your income was taxed, you reached the Third Bracket\n");
                  printf("Total tax paid: %.2f\n", totalTaxPaid);

                  return 0;
            }


            fourthTax (income, &fourth, &totalTaxPaid);
            if (income >= 80945)
            {
                income -= 80945;
              //printf ("income being processed for next tax bracket(5th) = %.2f\n",fourth);
            }
            else
            {
                  printf ("your income was taxed, you reached the Fourth Bracket\n");
                  printf("Total tax paid: %.2f\n", totalTaxPaid);
                  return 0;
            }


            fifthTax (income, &fifth, &totalTaxPaid);
            if (income >= 45900)
            {
                  income -= 45900;
                  //printf ("income being proccessed for next tax bracket(6th) = %.2f\n",fifth);

            }
            else
            {
                  printf ("Your income was taxed, you reached the Fifth Bracket\n");
                  printf("Total tax paid: %.2f\n", totalTaxPaid);
                  return 0;
            }


            sixthTax (income, &sixth, &totalTaxPaid);
            if (income >= 323950)
            {
                  income -= 323950;
            }
            else
            {
                   printf ("Your income was taxed, you reached the Sixth Bracket\n");
                   printf("Total tax paid: %.2f\n", totalTaxPaid);
                   return 0;
            }
    
    
            seventhTax(income ,&seventh, &sixth, &totalTaxPaid);
            printf("Total tax paid: %.2f\n", totalTaxPaid);

            return 0;
        
            } 
            
//****************************  Married jointly path    *************************************************************************
    else if (strcmp(choice_str, "married jointly") == 0) 
    {
        printf("You chose to file as Married Jointly ,what is your income?\n");
        printf ("Enter your income: ");
        scanf ("%f", &income);
            
        
            married_firstTax (income, &first, &totalTaxPaid);//calls function to start calculating tax
           if (income >= 20550)		//checks to see if program keeps going or not
            {
                income -= 20550;		//eliminating the money that has already been taxed
              //printf ("Income being processed for next tax bracket(2nd) = %.2f\n", first);

            }
           else
            {
                printf ("Your income was taxed, you reached the First Bracket\n");
                printf("Total tax paid: %.2f\n", totalTaxPaid);

                return 0;			//user didnt fit into next tax bracket so program ends
            }


            married_secondTax (income, &second, &totalTaxPaid);
            if (income >= 63000)
            {
            income -= 63000;
            //printf ("income being proccessed for next tax bracket(3rd) = %.2f\n",second);

            }
            else
            {
                  printf ("Your income was taxed, you reached the Second Bracket\n");
                  printf("Total tax paid: %.2f\n", totalTaxPaid);

                  return 0;
            }


            married_thirdTax (income, &third, &totalTaxPaid);
            if (income >= 94600)
            {
            income -= 94600;
            //printf ("income being proccessed for next tax bracket(4th) = %.2f\n", third);

            }
            else
            {
                  printf ("Your income was taxed, you reached the Third Bracket\n");
                  printf("Total tax paid: %.2f\n", totalTaxPaid);

                  return 0;
            }


            married_fourthTax (income, &fourth, &totalTaxPaid);
            if (income >= 161950)
            {
                income -= 161950;
              //printf ("income being processed for next tax bracket(5th) = %.2f\n",fourth);
            }
            else
            {
                  printf ("your income was taxed, you reached the Fourth Bracket\n");
                  printf("Total tax paid: %.2f\n", totalTaxPaid);
                  return 0;
            }


            married_fifthTax (income, &fifth, &totalTaxPaid);
            if (income >= 91800)
            {
                  income -= 91800;
                  //printf ("income being proccessed for next tax bracket(6th) = %.2f\n",fifth);

            }
            else
            {
                  printf ("Your income was taxed, you reached the Fifth Bracket\n");
                  printf("Total tax paid: %.2f\n", totalTaxPaid);
                  return 0;
                  return 0;
            }


            married_sixthTax (income, &sixth, &totalTaxPaid);
            if (income >= 215950)
            {
                  income -= 215950;
            }
            else
            {
                   printf ("Your income was taxed, you reached the Sixth Bracket\n");
                   printf("Total tax paid: %.2f\n", totalTaxPaid);
                   return 0;
            }
    
    
            married_seventhTax(income ,&seventh, &sixth, &totalTaxPaid);
            printf("Total tax paid: %.2f\n", totalTaxPaid);
        
        
        return 0;
    } 
//****************************  Head of household path    *********************************************************************
    else if (strcmp(choice_str, "head of household") == 0) 
    {
        printf("You chose to file as Head of Household ,what is your income?\n");
        printf ("Enter your income: ");
        scanf ("%f", &income);
            
        
            head_firstTax (income, &first, &totalTaxPaid);//calls function to start calculating tax
           if (income >= 14650)		//checks to see if program keeps going or not
            {
                income -= 14650;		//eliminating the money that has already been taxed
              //printf ("Income being processed for next tax bracket(2nd) = %.2f\n", first);

            }
           else
            {
                printf ("Your income was taxed, you reached the First Bracket\n");
                printf("Total tax paid: %.2f\n", totalTaxPaid);

                return 0;			//user didnt fit into next tax bracket so program ends
            }


            head_secondTax (income, &second, &totalTaxPaid);
            if (income >= 41250)
            {
            income -= 41250;
            //printf ("income being proccessed for next tax bracket(3rd) = %.2f\n",second);

            }
            else
            {
                  printf ("Your income was taxed, you reached the Second Bracket\n");
                  printf("Total tax paid: %.2f\n", totalTaxPaid);

                  return 0;
            }


            head_thirdTax (income, &third, &totalTaxPaid);
            if (income >= 33150)
            {
            income -= 33150;
            //printf ("income being proccessed for next tax bracket(4th) = %.2f\n", third);

            }
            else
            {
                  printf ("Your income was taxed, you reached the Third Bracket\n");
                  printf("Total tax paid: %.2f\n", totalTaxPaid);

                  return 0;
            }


            head_fourthTax (income, &fourth, &totalTaxPaid);
            if (income >= 81000)
            {
                income -= 81000;
              //printf ("income being processed for next tax bracket(5th) = %.2f\n",fourth);
            }
            else
            {
                  printf ("your income was taxed, you reached the Fourth Bracket\n");
                  printf("Total tax paid: %.2f\n", totalTaxPaid);
                  return 0;
            }


            head_fifthTax (income, &fifth, &totalTaxPaid);
            if (income >= 45900)
            {
                  income -= 45900;
                  //printf ("income being proccessed for next tax bracket(6th) = %.2f\n",fifth);

            }
            else
            {
                  printf ("Your income was taxed, you reached the Fifth Bracket\n");
                  printf("Total tax paid: %.2f\n", totalTaxPaid);
                  return 0;
            }


            head_sixthTax (income, &sixth, &totalTaxPaid);
            if (income >= 323950)
            {
                  income -= 323950;
            }
            else
            {
                   printf ("Your income was taxed, you reached the Sixth Bracket\n");
                   printf("Total tax paid: %.2f\n", totalTaxPaid);
                   return 0;
            }
    
    
            head_seventhTax(income ,&seventh, &sixth, &totalTaxPaid);
            printf("Total tax paid: %.2f\n", totalTaxPaid);
        


        
        
        
        return 0;
    } 
    
    else 
    {
        printf("Invalid choice\n");
        // Code for handling invalid choices goes here, if needed
    }
  
  


}



  return 0;
}


//**************************************    'single' functions    ***************************************************************
void firstTax (float income, float *first, float *totalTaxPaid)
{
  float firstBracket;
  if (income >= 10275)
    {
      *first = income - 10275;	//separates the money that wont be affected by this tax
      if (*first > 10275)
	{
//	  printf ("Income not affected by first tax bracket: %.2f\n", *first);
	}
      income -= *first;		//removed money thats already being tax 
//      printf ("Money being processed for first tax bracket = %.2f\n", income);
      firstBracket = income * 0.10;//money going to IRS
//      printf ("Uncle Sams Cut(10percent) = %.2f\n", firstBracket);
      *totalTaxPaid += firstBracket; // Add firstBracket to totalTaxPaid
    }
  else  //if the user didnt have enough money to go on to the next bracket it just taxes what they have
    {
      firstBracket = income * 0.10;
//      printf ("Uncle Sams Cut = %.2f\n", firstBracket);
      *totalTaxPaid += firstBracket;
      if (income >= 31500)
	  {
	  *first = income - firstBracket;
//	  printf("After the first tax bracket was completed, your new income balance is = %.2f\n",*first);
	  }
      else
	  {
//	  printf("No more money left to be taxed, youve reached the first tax bracket(10percent)\n");
	    
	  }
    }
}

void secondTax (float income, float *second, float *totalTaxPaid)
{
  float secondBracket;
  if (income >= 31500)
    {
      *second = income - 31500;
//      printf ("Income not affected by 2nd tax bracket: %.2f\n", *second);
      income -= *second;
//      printf ("Money being processed for second tax bracket = %.2f\n", income);
      secondBracket = income * 0.12;
//      printf ("Uncle Sams Cut (12percent) =  %.2f\n", secondBracket);
      *totalTaxPaid += secondBracket;//total taxes paid so far
    }
  else
    {
      secondBracket = income * 0.12;
//      printf ("Uncle Sams Cut = %.2f\n", secondBracket);
      *totalTaxPaid += secondBracket;

      if (income >= 47300)	//checks to see if its able to go to next tax bracket
	{
	  *second = income - secondBracket;
//	  printf("After the second tax bracket was completed, your new income balance is: %.2f\n",*second);
	}
      else
	{
//	  printf("No more money left to be taxed, youve reached the second tax bracket(12percent)\n");
	}

    }
}

void thirdTax (float income, float *third, float *totalTaxPaid)
{
  float thirdBracket;
  if (income >= 47300)
    {
      *third = income - 47300;
//      printf ("Income not affected by 3rd tax bracket: %.2f\n", *third);
      income -= *third;
//      printf ("Money being processed for third tax bracket = %.2f\n", income);
      thirdBracket = income * 0.22;
//      printf ("Uncle Sams Cut (22 percent) = %.2f\n", thirdBracket);
      *totalTaxPaid += thirdBracket;

    }
  else
    {
      thirdBracket = income * 0.22;
//      printf ("Uncle Sams Cut = %.2f\n", thirdBracket);
      *totalTaxPaid += thirdBracket;

      if (income >= 80945)	// checks to see if it's able to go onto the next tax bracket
	{
	  *third = income - thirdBracket;
//	  printf("After the third tax bracket was completed, your new income balance is: %.2f\n",*third);
	}
      else
	{
//	  printf("No more money left to be taxed, you reached the third tax bracket (22 percent).\n");
	}
    }
}

void fourthTax (float income, float *fourth, float *totalTaxPaid)	//works until here
{
  float fourthBracket;
  if (income >= 80945)
    {
      *fourth = income - 80945;
//      printf ("Income not affected by 4th tax bracket: %.2f\n", *fourth);
      income -= *fourth;
//      printf ("Money being processed for fourth tax bracket = %.2f\n", income);
      fourthBracket = income * 0.24;
//      printf ("Uncle Sams Cut (24 percent) = %.2f\n", fourthBracket);
      *totalTaxPaid += fourthBracket;

    }
  else
    {
      fourthBracket = income * 0.24;
//      printf ("Uncle Sams Cut = %.2f\n", fourthBracket);
      *totalTaxPaid += fourthBracket;
      if (income >= 45900)	// checks to see if it's able to go onto the next tax bracket
	{
	  *fourth = income - fourthBracket;
//	  printf("After the fourth tax bracket was completed, your new income balance is: %.2f\n",*fourth);
	}
      else
	{
//	  printf("No more money left to be taxed, you reached the fourth tax bracket (24 percent).\n");
	}
    }
}

void fifthTax (float income, float *fifth, float *totalTaxPaid)
{
  float fifthBracket;
  if (income >= 45900)
    {
      *fifth = income - 45900;
//      printf ("Income not affected by fifth tax bracket: %.2f\n", *fifth);
      income -= *fifth;
//      printf ("Money being processed for fifth tax bracket = %.2f\n", income);
      fifthBracket = income * 0.32;
//      printf ("Uncle Sams Cut (32percent) =  %.2f\n", fifthBracket);
      *totalTaxPaid += fifthBracket;

    }
  else
    {
      fifthBracket = income * 0.32;
//      printf ("Uncle Sams Cut = %.2f\n", fifthBracket);
      *totalTaxPaid += fifthBracket;

      if (income >= 323950)	//checks to see if its able to go to next tax bracket
	{
	  *fifth = income - fifthBracket;
//	  printf("After the fifth tax bracket was completed, your new income balance is: %.2f\n",*fifth);
	}
      else
	{
//	  printf("No more money left to be taxed, youve reached the fifth tax bracket(32percent)\n");
	}

    }
}

void sixthTax (float income, float *sixth, float *totalTaxPaid)
{
  float sixthBracket;
  if (income >= 323950)
    {
      *sixth = income - 323950;
//      printf ("Income not affected by sixth tax bracket: %.2f\n", *sixth);
      income -= *sixth;
//      printf ("Money being processed for sixth tax bracket = %.2f\n", income);
      sixthBracket = income * 0.35;
//      printf ("Uncle Sams Cut (35percent) =  %.2f\n", sixthBracket);
      *totalTaxPaid += sixthBracket;

    }
  else
    {
      sixthBracket = income * 0.35;
//      printf ("Uncle Sams Cut = %.2f\n", sixthBracket);
      *totalTaxPaid += sixthBracket;

      if (income >= 1)	//all money from here is taxed for next bracket
	{
	  *sixth = income - sixthBracket;
//	  printf("After the sixth tax bracket was completed, your new income balance is: %.2f\n",*sixth);
	}
      else
	{
//	  printf("No more money left to be taxed, youve reached the sixth tax bracket(35percent)\n");
	}

    }
}



void seventhTax (float income, float *seventh, float *sixth, float *totalTaxPaid)
{
  float seventhBracket;
      *seventh = income - *sixth ;//- 323950;
      //printf ("Income not affected by next tax bracket: %.2f...... there isnt another tax bracket\n", *seventh);
      income -= *seventh;
//      printf ("Money that hasnt been affected by all previous brackets = %.2f\n", income);
      seventhBracket = income * 0.37;
//      printf ("Uncle Sams Cut (37percent) =  %.2f\n", seventhBracket);
      *totalTaxPaid += seventhBracket;
//      printf("Youve reached the final tax bracket(7th), all the money that made it to here will be taxed at 37 percent\n");
      printf("your income was taxed, you reached the Seventh Bracket\n");

      
}       // last of the single functions
      
  
  
  
  
  
//****************************************  'married jointly' functions    **************************************************************************
void married_firstTax(float income, float *first, float *totalTaxPaid) //start of the married functions 
{
    float firstBracket;
  if (income >= 20550)
    {
      *first = income - 20550;	//separates the money that wont be affected by this tax
      if (*first > 20550)
	{
//	  printf ("Income not affected by first tax bracket: %.2f\n", *first);
	}
      income -= *first;		//removed money thats already being tax 
//      printf ("Money being processed for first tax bracket = %.2f\n", income);
      firstBracket = income * 0.10;//money going to IRS
//      printf ("Uncle Sams Cut(10percent) = %.2f\n", firstBracket);
      *totalTaxPaid += firstBracket; // Add firstBracket to totalTaxPaid
    }
  else                                                  //if the user didnt have enough money to go on to the next bracket it just taxes what they have
    {
      firstBracket = income * 0.10;
//      printf ("Uncle Sams Cut = %.2f\n", firstBracket);
      *totalTaxPaid += firstBracket;
      if (income >= 63000)
	  {
	  *first = income - firstBracket;
//	  printf("After the first tax bracket was completed, your new income balance is = %.2f\n",*first);
	  }
      else
	  {
//	  printf("No more money left to be taxed, youve reached the first tax bracket(10percent)\n");
	    
	  }
    }
}


void married_secondTax (float income, float *second, float *totalTaxPaid)
{
    float secondBracket;
  if (income >= 63000)
    {
      *second = income - 63000;
//      printf ("Income not affected by 2nd tax bracket: %.2f\n", *second);
      income -= *second;
//      printf ("Money being processed for second tax bracket = %.2f\n", income);
      secondBracket = income * 0.12;
//      printf ("Uncle Sams Cut (12percent) =  %.2f\n", secondBracket);
      *totalTaxPaid += secondBracket;//total taxes paid so far
    }
  else
    {
      secondBracket = income * 0.12;
//      printf ("Uncle Sams Cut = %.2f\n", secondBracket);
      *totalTaxPaid += secondBracket;

      if (income >= 94600)	//checks to see if its able to go to next tax bracket
	{
	  *second = income - secondBracket;
//	  printf("After the second tax bracket was completed, your new income balance is: %.2f\n",*second);
	}
      else
	{
//	  printf("No more money left to be taxed, youve reached the second tax bracket(12percent)\n");
	}

    }
}


void married_thirdTax (float income, float *third, float *totalTaxPaid)
{
    float thirdBracket;
  if (income >= 94600)
    {
      *third = income - 94600;
//      printf ("Income not affected by 3rd tax bracket: %.2f\n", *third);
      income -= *third;
//      printf ("Money being processed for third tax bracket = %.2f\n", income);
      thirdBracket = income * 0.22;
//      printf ("Uncle Sams Cut (22 percent) = %.2f\n", thirdBracket);
      *totalTaxPaid += thirdBracket;

    }
  else
    {
      thirdBracket = income * 0.22;
//      printf ("Uncle Sams Cut = %.2f\n", thirdBracket);
      *totalTaxPaid += thirdBracket;

      if (income >= 161950)	// checks to see if it's able to go onto the next tax bracket
	{
	  *third = income - thirdBracket;
//	  printf("After the third tax bracket was completed, your new income balance is: %.2f\n",*third);
	}
      else
	{
//	  printf("No more money left to be taxed, you reached the third tax bracket (22 percent).\n");
	}
    }
}


void married_fourthTax (float income, float *fourth, float *totalTaxPaid)
{
    float fourthBracket;
  if (income >= 161950)
    {
      *fourth = income - 161950;
//      printf ("Income not affected by 4th tax bracket: %.2f\n", *fourth);
      income -= *fourth;
//      printf ("Money being processed for fourth tax bracket = %.2f\n", income);
      fourthBracket = income * 0.24;
//      printf ("Uncle Sams Cut (24 percent) = %.2f\n", fourthBracket);
      *totalTaxPaid += fourthBracket;

    }
  else
    {
      fourthBracket = income * 0.24;
//      printf ("Uncle Sams Cut = %.2f\n", fourthBracket);
      *totalTaxPaid += fourthBracket;
      if (income >= 91800)	// checks to see if it's able to go onto the next tax bracket
	{
	  *fourth = income - fourthBracket;
//	  printf("After the fourth tax bracket was completed, your new income balance is: %.2f\n",*fourth);
	}
      else
	{
//	  printf("No more money left to be taxed, you reached the fourth tax bracket (24 percent).\n");
	}
    }
}


void married_fifthTax (float income, float *fifth, float *totalTaxPaid)
{
    float fifthBracket;
  if (income >= 91800)
    {
      *fifth = income - 91800;
//      printf ("Income not affected by fifth tax bracket: %.2f\n", *fifth);
      income -= *fifth;
//      printf ("Money being processed for fifth tax bracket = %.2f\n", income);
      fifthBracket = income * 0.32;
//      printf ("Uncle Sams Cut (32percent) =  %.2f\n", fifthBracket);
      *totalTaxPaid += fifthBracket;

    }
  else
    {
      fifthBracket = income * 0.32;
//      printf ("Uncle Sams Cut = %.2f\n", fifthBracket);
      *totalTaxPaid += fifthBracket;

      if (income >= 215950)	//checks to see if its able to go to next tax bracket
	{
	  *fifth = income - fifthBracket;
//	  printf("After the fifth tax bracket was completed, your new income balance is: %.2f\n",*fifth);
	}
      else
	{
//	  printf("No more money left to be taxed, youve reached the fifth tax bracket(32percent)\n");
	}

    }
}


void married_sixthTax (float income, float *sixth, float *totalTaxPaid)
{
    float sixthBracket;
  if (income >= 215950)
    {
      *sixth = income - 215950;
//      printf ("Income not affected by sixth tax bracket: %.2f\n", *sixth);
      income -= *sixth;
//      printf ("Money being processed for sixth tax bracket = %.2f\n", income);
      sixthBracket = income * 0.35;
//      printf ("Uncle Sams Cut (35percent) =  %.2f\n", sixthBracket);
      *totalTaxPaid += sixthBracket;

    }
  else
    {
      sixthBracket = income * 0.35;
//      printf ("Uncle Sams Cut = %.2f\n", sixthBracket);
      *totalTaxPaid += sixthBracket;

      if (income >= 1)	//checks to see if its able to go to next tax bracket
	{
	  *sixth = income - sixthBracket;
//	  printf("After the sixth tax bracket was completed, your new income balance is: %.2f\n",*sixth);
	}
      else
	{
//	  printf("No more money left to be taxed, youve reached the sixth tax bracket(35percent)\n");
	}

    }
}


void married_seventhTax (float income, float *seventh, float *sixth, float *totalTaxPaid)
{
    float seventhBracket;
      *seventh = income - *sixth ;//- 323950;
      //printf ("Income not affected by next tax bracket: %.2f...... there isnt another tax bracket\n", *seventh);
      income -= *seventh;
//      printf ("Money that hasnt been affected by all previous brackets = %.2f\n", income);
      seventhBracket = income * 0.37;
//      printf ("Uncle Sams Cut (37percent) =  %.2f\n", seventhBracket);
      *totalTaxPaid += seventhBracket;
      printf("Youve reached the final tax bracket(7th), all the money that made it to here will be taxed at 37 percent\n");
      printf("your income was taxed, you reached the Seventh Bracket\n");
}






//**********************    'Head of Household' functions    *******************************************************************

void head_firstTax(float income, float *first, float *totalTaxPaid)
{
    float firstBracket;
  if (income >= 14650)
    {
      *first = income - 14650;	//separates the money that wont be affected by this tax
      if (*first > 14650)
	{
//	  printf ("Income not affected by first tax bracket: %.2f\n", *first);
	}
      income -= *first;		//removed money thats already being tax 
//      printf ("Money being processed for first tax bracket = %.2f\n", income);
      firstBracket = income * 0.10;//money going to IRS
//      printf ("Uncle Sams Cut(10percent) = %.2f\n", firstBracket);
      *totalTaxPaid += firstBracket; // Add firstBracket to totalTaxPaid
    }
  else  //if the user didnt have enough money to go on to the next bracket it just taxes what they have
    {
      firstBracket = income * 0.10;
//      printf ("Uncle Sams Cut = %.2f\n", firstBracket);
      *totalTaxPaid += firstBracket;
      if (income >= 41250)
	  {
	  *first = income - firstBracket;
//	  printf("After the first tax bracket was completed, your new income balance is = %.2f\n",*first);
	  }
      else
	  {
//	  printf("No more money left to be taxed, youve reached the first tax bracket(10percent)\n");
	    
	  }
    }
}



void head_secondTax (float income, float *second, float *totalTaxPaid)
{
    float secondBracket;
  if (income >= 41250)
    {
      *second = income - 41250;
//      printf ("Income not affected by 2nd tax bracket: %.2f\n", *second);
      income -= *second;
//      printf ("Money being processed for second tax bracket = %.2f\n", income);
      secondBracket = income * 0.12;
//      printf ("Uncle Sams Cut (12percent) =  %.2f\n", secondBracket);
      *totalTaxPaid += secondBracket;//total taxes paid so far
    }
  else
    {
      secondBracket = income * 0.12;
//      printf ("Uncle Sams Cut = %.2f\n", secondBracket);
      *totalTaxPaid += secondBracket;

      if (income >= 33150)	//checks to see if its able to go to next tax bracket
	{
	  *second = income - secondBracket;
//	  printf("After the second tax bracket was completed, your new income balance is: %.2f\n",*second);
	}
      else
	{
//	  printf("No more money left to be taxed, youve reached the second tax bracket(12percent)\n");
	}

    }
}



void head_thirdTax (float income, float *third, float *totalTaxPaid)
{
    float thirdBracket;
  if (income >= 33150)
    {
      *third = income - 33150;
//      printf ("Income not affected by 3rd tax bracket: %.2f\n", *third);
      income -= *third;
//      printf ("Money being processed for third tax bracket = %.2f\n", income);
      thirdBracket = income * 0.22;
//      printf ("Uncle Sams Cut (22 percent) = %.2f\n", thirdBracket);
      *totalTaxPaid += thirdBracket;

    }
  else
    {
      thirdBracket = income * 0.22;
//      printf ("Uncle Sams Cut = %.2f\n", thirdBracket);
      *totalTaxPaid += thirdBracket;

      if (income >= 81000)	// checks to see if it's able to go onto the next tax bracket
	{
	  *third = income - thirdBracket;
//	  printf("After the third tax bracket was completed, your new income balance is: %.2f\n",*third);
	}
      else
	{
//	  printf("No more money left to be taxed, you reached the third tax bracket (22 percent).\n");
	}
    }
    
}


void head_fourthTax (float income, float *fourth, float *totalTaxPaid)
{
    float fourthBracket;
  if (income >= 81000)
    {
      *fourth = income - 81000;
//      printf ("Income not affected by 4th tax bracket: %.2f\n", *fourth);
      income -= *fourth;
//      printf ("Money being processed for fourth tax bracket = %.2f\n", income);
      fourthBracket = income * 0.24;
//      printf ("Uncle Sams Cut (24 percent) = %.2f\n", fourthBracket);
      *totalTaxPaid += fourthBracket;

    }
  else
    {
      fourthBracket = income * 0.24;
//      printf ("Uncle Sams Cut = %.2f\n", fourthBracket);
      *totalTaxPaid += fourthBracket;
      if (income >= 45900)	// checks to see if it's able to go onto the next tax bracket
	{
	  *fourth = income - fourthBracket;
//	  printf("After the fourth tax bracket was completed, your new income balance is: %.2f\n",*fourth);
	}
      else
	{
//	  printf("No more money left to be taxed, you reached the fourth tax bracket (24 percent).\n");
	}
    }
    
}


void head_fifthTax (float income, float *fifth, float *totalTaxPaid)
{
    float fifthBracket;
  if (income >= 45900)
    {
      *fifth = income - 45900;
//      printf ("Income not affected by fifth tax bracket: %.2f\n", *fifth);
      income -= *fifth;
//      printf ("Money being processed for fifth tax bracket = %.2f\n", income);//45900
      fifthBracket = income * 0.32;
//      printf ("Uncle Sams Cut (32percent) =  %.2f\n", fifthBracket);//14688
      *totalTaxPaid += fifthBracket;

    }
  else
    {
      fifthBracket = income * 0.32;
//      printf ("Uncle Sams Cut = %.2f\n", fifthBracket);
      *totalTaxPaid += fifthBracket;

      if (income >= 323950)	//checks to see if its able to go to next tax bracket
	{
	  *fifth = income - fifthBracket;
//	  printf("After the fifth tax bracket was completed, your new income balance is: %.2f\n",*fifth);
	}
      else
	{
//	  printf("No more money left to be taxed, youve reached the fifth tax bracket(32percent)\n");
	}

    }
}



void head_sixthTax (float income, float *sixth, float *totalTaxPaid)
{

    float sixthBracket;
  if (income >= 323950)
    {
      *sixth = income - 323950;
//      printf ("Income not affected by sixth tax bracket: %.2f\n", *sixth);
      income -= *sixth;
//      printf ("Money being processed for sixth tax bracket = %.2f\n", income);
      sixthBracket = income * 0.35;
//      printf ("Uncle Sams Cut (35percent) =  %.2f\n", sixthBracket);
      *totalTaxPaid += sixthBracket;

    }
  else
    {
      sixthBracket = income * 0.35;
//      printf ("Uncle Sams Cut = %.2f\n", sixthBracket);
      *totalTaxPaid += sixthBracket;

      if (income >= 1)	//checks to see if its able to go to next tax bracket
	{
	  *sixth = income - sixthBracket;
//	  printf("After the sixth tax bracket was completed, your new income balance is: %.2f\n",*sixth);
	}
  
      else
	{
//	  printf("No more money left to be taxed, youve reached the sixth tax bracket(35percent)\n");
	}

    }
}


void head_seventhTax (float income, float *seventh, float *sixth, float *totalTaxPaid)
{
    float seventhBracket;
      *seventh = income - *sixth ;//- 323950;
//      printf ("Income not affected by next tax bracket: %.2f...... there isnt another tax bracket\n", *seventh);
      income -= *seventh;
//      printf ("Money that hasnt been affected by all previous brackets = %.2f\n", income);
      seventhBracket = income * 0.37;
//      printf ("Uncle Sams Cut (37percent) =  %.2f\n", seventhBracket);
      *totalTaxPaid += seventhBracket;
//      printf("Youve reached the final tax bracket(7th), all the money that made it to here will be taxed at 37 percent\n");
      printf("your income was taxed, you reached the Seventh Bracket\n");
    
}

