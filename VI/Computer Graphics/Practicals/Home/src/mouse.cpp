// C++ program to display Mouse
// pointer in Graphics Mode
#include <bits/stdc++.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdio.h>

using namespace std;

union REGS in, out;

// Function to display the mouse
// pointer
void showMouse()
{
	// Set service AX = 1 for
	// displaying mouse
    in.x.ax = 1;
	int86(0X33, &in, &out);
}

// Function to initialize the mouse
// pointer
int initMouse()
{
	// Set service AX = 0 for
	// detecting mouse
	in.x.ax = 0;
	int86(0x33, &in, &out);

	return out.x.ax;
}

// Driver Code
void main()
{
	int status, gd = DETECT, gm;
    cleardevice();

	initgraph(&gd, &gm, "C:\\MinGW\\lib\\libbgi.a");

	// Get the status of mouse pointer
	status = initMouse();

	// Check if mouse is available or not
	if (status == 0)
		cout << "Mouse support not"
			<< " available.\n";
	else {
		cout << "Display mouse";
		showMouse();
	}

	getch();

	// Close the graphics
	closegraph();
}
