#include <iostream>

using namespace std;

#define file "/proc/cpuinfo"

void cpu_info()
{
	cout << "\nCpu Information : \n";
	string info[7] = {"vendor_id", "model\\ name", 
					 "cache\\ size","cpu\\ cores", 
					 "cpuid\\ level" ,"siblings" , 
					 "address\\ sizes"};

	for(int i = 0; i < 7; i++)
	{
		string cmd = "grep " + info[i] + " " + file + " | awk \'NR==1{print}\'";
		system(cmd.c_str());
	}
}

int main()
{
	cout << "\n Practical 2 \n";
	
	cpu_info();
	system("echo \'\nOS kernel version : \'");
	system("cat /proc/sys/kernel/osrelease");
} 