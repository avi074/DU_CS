#include <iostream>

using namespace std;

#define file "/proc/meminfo"

void mem_info()
{
	cout << "\nMemory Information : \n";
	string info[6] = {"MemTotal", "MemFree", 
					 "Buffers","Cached", 
					 "SwapTotal" ,"SwapFree"};
	string cmd;

	for(int i = 0; i < 6; i++)
	{
		cmd = "grep " + info[i] + " " + file + " | awk \'{print}\'";
		system(cmd.c_str());
	}
	cmd = "cat /proc/meminfo | awk \'{if(NR == 1) a = $2; if(NR==2) b = $2} END {print \"MemUsed:\t\", a - b, \"kB\"}\'";
	system(cmd.c_str());
}

void os_info()
{
	cout << "\nOS Information : \n";
	string info[4] = {"ostype", "hostname", 
					 "osrelease","version"};
	for(auto i : info)
	{
		string cmd = "cat /proc/sys/kernel/"+ i + " |awk \'{print \"" + i +" : \", $0}\'";
		system(cmd.c_str());
	}
}

int main()
{
	cout << "\n Practical 3 \n";
	
	mem_info();
	os_info();
} 