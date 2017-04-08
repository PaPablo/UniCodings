#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <syscall.h>
#include <sys/wait.h>
#include <unistd.h>

void catch_alarm(int signum){

	printf("La alarma llegó\n");

}



int main(int argc, char const *argv[])
{
	struct itimerval timer;
	timer.it_value.tv_sec = 0;
	timer.it_value.tv_usec = 0;
	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = 0;
	
	signal(SIGALRM, catch_alarm);
	alarm(2);

	setitimer(ITIMER_REAL, &timer, NULL);

	while(1);

	return 0;
}


