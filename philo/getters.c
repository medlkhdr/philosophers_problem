#include "philos.h"

ssize_t filter(char *string)
{
  int i;
  ssize_t res;

  res = 0;
  i = 0;
  if(string[i] == '-')
  {
    printf("NO NEGATIVE NUMBERS PLEASE!(READ THE SUBJECT)");
    exit(1);
  }
  if(string[i] == '+')
    i++;
  while(string[i] >= '0' && string[i] <= '9')
  {
    res = res * 10 + (string[i] - '0');
    i++;
  }
    if(string[i] != '\0')
  {
    printf("INVALID PARAM\n");
    exit(1);
  }
  return res;
}
