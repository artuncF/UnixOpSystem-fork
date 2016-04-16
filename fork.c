#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>


int main()
{
    int layer=0;
    int right_child;
    int	left_child;
	while((layer++)<=3)
	{
		left_child=fork();
		if(left_child< 0)
		{
            printf("Error occured while process was being produced. Getting out in a second...");
            sleep(1);
            exit(-1);
		}
		else if (left_child== 0)
		{
			printf("Sol cocuk katman: %d, PID: %d, Annem: %d\n", layer-1, getpid(), getppid());
			break;
		}
		else right_child=fork();

		if(right_child < 0)
		{
            printf("Error occured while process was being produced. Getting out in a second...");
            sleep(1);
            exit(-1);
		}
		else if (right_child == 0)
		{
			if(layer-1==3) printf("Sag cocuk katman: %d, PID: %d, Annem: %d\n", layer-1, getpid(), getppid());
			continue;
		}
		else
		{
			printf("Anne katman: %d, PID: %d, Sag Cocuk: %d, Sol Cocuk: %d\n", layer-1, getpid(),right_child,left_child);
			wait(NULL);
			wait(NULL);   			break;
		}
	}
	return 0;
}

