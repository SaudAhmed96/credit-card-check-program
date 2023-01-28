#include <cs50.h>
#include <stdio.h>

long get_Number(void);
bool check_Sum(long num);
string card_Check(long num);

int main(void)
{
    //get valid credit card number
    long cardNum = get_Number();
    //Luhn algorithm to provide checksum output
    if(check_Sum(cardNum))
    {
        string cardName = card_Check(cardNum); // wats the carddddddddd
        printf("card is %s \n", cardName);
    }
    else
    {
        printf("INVALID \n");
    }
    //print what type of card it is and if its valid

}


string card_Check(long num)
{
    int count = 0;
    int f;
    int s;

    do
    {
        count ++;
        //printf("%li \n", num);

        s = num % 10;
        num = (num - s)/10;
        if(num >0)
        {
            f = num % 10;
            num = (num - f)/10;
            count++;
        }
    }
    while(num > 0);
    // printf("%i \n", s);
    // printf("%i \n", f);
    // printf("%li \n", num);

    if(count == 16)
    {
        if(f==5)
        {
            if(s>0 && s<6)
            {
                {return "MASTERCARD \n";}
            }

        }
        else if(f==4)
        {
            return "VISA \n";
        }
    }
    else if(count == 13) // s and f flip for odd numbers
    {
        if(s==4)
        {
            return "VISA \n";
        }
    }
    else if(count == 15) // s and f flip for odd numbers
    {
        if(s==3)
        {
            if(f==4 || f==7)
            {
                return "AMEX \n";
            }
        }
    }

    return "INVALID \n";

    //check if count is odd or even
    // if even then s will be the second num and f will be the first
    // if its odd then the s and f will be flipped

}

long get_Number(void)
{
    long x;
    do
    {
        x = get_long("Number: ");
    }
    while(x<1);
    return x;
}

bool check_Sum(long num)
{
    //get all digits from end and totals every other digit according to Luhns Algorithm
    int counter1 = 0;
    int c3 = 0;
    int l, s, q;
    do
    {
        l = num % 10;
        counter1 += l;
        num = (num - l)/10;

        s = num % 10;
        q = s*2;

        if( q-10 >= 0) {
            c3++;
            c3 += q % 10;
        }
        else {c3 += q % 10;}

        num = (num - s)/10;
    }
    while(num > 0);

    int total = counter1 + c3; // if the total modulo 10 is 0 then the credit card number is valid

    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
