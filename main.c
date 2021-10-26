#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char command[50];

   strcpy(command, "/bin/python /Adi_OS/init.py" );
   system(command);

   return(0);
} 