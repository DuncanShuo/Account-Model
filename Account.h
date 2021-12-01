// Definition of Account class.
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

class Account
{
public:
   Account( double ); // constructor initializes balance
   virtual void credit( double ); // add an amount to the account balance
   virtual bool debit( double ); // subtract an amount from the account balance
   void setBalance( double ); // sets the account balance
   double getBalance(bool print = true); // return the account balance
   virtual string getClass();
   virtual void callInterest();
private:
   double balance; // data member that stores the balance
};

class CheckingAccount : public Account
{
public:
   // constructor initializes balance and transaction fee
   CheckingAccount( double, double );

   void credit( double ); // redefined credit function
   bool debit( double ); // redefined debit function
   string getClass();
private:
   double transactionFee; // fee charged per transaction

   // utility function to charge fee
   void chargeFee();
};

class SavingsAccount : public Account
{
public:
   // constructor initializes balance and interest rate
   SavingsAccount( double, double );

   bool debit(double);
   double calculateInterest(); // determine interest owed
   string getClass();
   void callInterest();
private:
   double interestRate; // interest rate (percentage) earned by account
};

#endif

/**************************************************************************
 * (C) Copyright 1992-2011 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/