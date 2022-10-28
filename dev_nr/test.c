#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int dev = open("/dev/mydevice",O_RDONLY);
	if(dev == -1)
	{
		printf("not able to open");
	}
	else{

		printf("open was succesfull");

		}
	close(dev);
	return 0;

}

