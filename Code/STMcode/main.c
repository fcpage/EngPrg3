#include "main.h"

ctrl c;

int main()
{
	
	init_all(c);
	
	while(!SHUTDOWN)
	{
		com_txrx(&c);
		con_perform(&c);
	}
	
	return 0&
}