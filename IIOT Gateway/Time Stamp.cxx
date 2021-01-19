// execute time functions

#include<stdio.h>  
#include<stdlib.h>
#include<time.h>

int main()
{

time_t rawtime;
struct tm* timeinfo;
time(&rawtime);    
timeinfo=localtime(&rawtime); 

printf("%d-%02d-%d %02d:%02d:%02d \n",timeinfo->tm_year+1900,timeinfo->tm_mday,timeinfo->tm_mon+1,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec);

}
