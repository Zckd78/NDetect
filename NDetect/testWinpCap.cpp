// testWinpCap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <pcap.h>
#include <thread> // library necessary for threads 




int count = 0;

void countBackground()
{
	std::cout << "Hello Concurrent World\n";
	while (count < 100)
	{
		Sleep(10);
		std::cout << "Thread 1 Count: " << count << std::endl;
		count++;
	}

}
void display()
{
	while (count != 100)
	{
		std::cout << "thread 2 Count: " << count << std::endl;
	}
		
}

int main()
{
	std::thread t(countBackground);
	std::thread t2(display);
	t2.join();
	t.join();




	pcap_if_t * allAdapters; //a pointer to a string giving a name for the device to pass to pcap_open_live() 
	pcap_if_t * adapter;
	char errorBuffer[PCAP_ERRBUF_SIZE];
	int i = 0; // flag that will check if winPcap is installed

	/* Retrieve the device list from the local machine */
	if (pcap_findalldevs_ex((char*)PCAP_SRC_IF_STRING, NULL, &allAdapters, errorBuffer) == -1)
	{
		fprintf(stderr, "Error in pcap_findalldevs_ex: %s \n", errorBuffer);
		exit(1); //If this is 0 or EXIT_SUCCESS, it indicates success.
	}

	// print the list
	for (adapter = allAdapters; adapter != NULL; adapter = adapter->next)
	{
		printf("%d. %s", ++i, adapter->name);
		if (adapter->description)
			printf(" (%s)\n", adapter->description);
		else
			printf(" (No description available)\n");
	}

	if (i == 0)
	{
		printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
		//return;
	}



	/* We don't need any more the device list. Free it */
	pcap_freealldevs(allAdapters);
	return 0;
}
