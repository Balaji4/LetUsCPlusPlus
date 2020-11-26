/* Skeleton example of embedded SQL in C */
#include <stdio.h>
#include <stdlib.h>
/* Include communications area */
struct sqla
{
char sqlaid[8];
long sqlabc;
long sqlcode;
 struct
  {
  short sqlerrml;
  char sqlerrmc[70];
  }sqlerrm;
char sqlerrp[8];
long sqlerrd[6];
char sqlwarn[8];
char sqlext[8];
};
EXEC SQL INCLUDE sqlca
int main ()
{
EXEC SQL BEGIN DECLARE SECTION
char Lname[16];
char SSN[10];
EXEC SQL END DECLARE SECTION
EXEC SQL CONNECT 'company';
if (sqlca.sqlcode < 0) exit(-1);
printf("Enter SSN: ");
scanf("%s", SSN);

EXEC SQL SELECT Lname FROM Employee
WHERE SSN = :SSN;
switch (sqlca.sqlcode)
{
case 0: printf("Last name is %s.\n", Lname);
break;
case 100: printf("No last name for %s.\n", SSN);
break;
default: printf("SQL error %d.\n",sqlca.sqlcode);
}
return(0);
EXEC SQL DISCONNECT;
}


