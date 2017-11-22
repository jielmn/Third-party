#include <stdio.h>  
#include <time.h>  

#include "event2\event.h"  
#include "event2\event_struct.h"  
#include "event2\util.h"  


struct timeval lasttime;
typedef struct
{
	struct event *pevent;
	void *otherargs;
} event_arg_t;

void timeout_cb1(evutil_socket_t fd, short event, void *arg)
{
	struct timeval newtime, difference;
	event_arg_t *parg = (event_arg_t*)arg;
	struct event *timeout_ev = parg->pevent;
	int handle = *(int *)parg->otherargs;
	double elapsed;

	evutil_gettimeofday(&newtime, NULL);
	evutil_timersub(&newtime, &lasttime, &difference);
	elapsed = difference.tv_sec + (difference.tv_usec / 1.0e6);

	printf("timeout called at %d: %.3f s elapsed event=%d arg.handle=%d.\n", (int)newtime.tv_sec, elapsed, event, handle);

	//看看如果在一个事件处理中延时会出现什么情况  
	//Sleep(6000);  
}
void timeout_cb2(evutil_socket_t fd, short event, void *arg)
{
	struct timeval newtime, difference;
	event_arg_t *parg = (event_arg_t*)arg;
	struct event *timeout_ev = parg->pevent;
	int handle = *(int *)parg->otherargs;
	double elapsed;

	evutil_gettimeofday(&newtime, NULL);
	evutil_timersub(&newtime, &lasttime, &difference);
	elapsed = difference.tv_sec + (difference.tv_usec / 1.0e6);

	printf("timeout called at %d: %.3f s elapsed event=%d arg.handle=%d.\n", (int)newtime.tv_sec, elapsed, event, handle);

}

int testlibevent_timer(void)
{
	event_arg_t timeout_arg1, timeout_arg2;
	struct event timeout_ev1, timeout_ev2;
	struct timeval tv;
	struct event_base *base;
	int flags;
	int handle1 = 2;
	int handle2 = 3;
	timeout_arg1.pevent = &timeout_ev1;
	timeout_arg1.otherargs = (void *)&handle1;
	timeout_arg2.pevent = &timeout_ev2;
	timeout_arg2.otherargs = (void *)&handle2;


	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	wVersionRequested = MAKEWORD(2, 2);

	err = WSAStartup(wVersionRequested, &wsaData);

	flags = EV_PERSIST;     //  EV_PERSIST or 0  
	//flags = 0;

							/* Initalize the event library */
	base = event_base_new();

	/* Initalize one event */
	event_assign(&timeout_ev1, base, -1, flags, timeout_cb1, (void*)&timeout_arg1);
	event_assign(&timeout_ev2, base, -1, flags, timeout_cb2, (void*)&timeout_arg2);

	evutil_timerclear(&tv);
	tv.tv_sec = handle1;
	event_add(&timeout_ev1, &tv);
	tv.tv_sec = handle2;
	event_add(&timeout_ev2, &tv);

	evutil_gettimeofday(&lasttime, NULL);

	event_base_dispatch(base);

	return (0);
}

int main() {
	testlibevent_timer();
	return 0;
}