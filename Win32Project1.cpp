#pragma comment(linker,"/NODEFAULTLIB")
#pragma comment(linker,"/ENTRY:WinMain")
#include <windows.h>
#include "resource.h"




static unsigned long int next = 1;


//Dialog Procedure

BOOL CALLBACK DialogProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);

int inn(char * x);
int mrand(void);

void msrand(unsigned int seed);

int WINAPI WinMain(HINSTANCE hInstance,

	HINSTANCE hPrevInstance,

	LPSTR lpszCmdLine,

	int nCmdShow)

{

	

	DialogBoxParam(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_ABOUTBOX), NULL, (DLGPROC)DialogProc, 0);

	return 0;

}

BOOL CALLBACK DialogProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)

{


	char inn_n[13] = { 0 };


	switch (Message)

	{

	case WM_INITDIALOG:

		msrand(GetTickCount());

		return TRUE;

	case WM_COMMAND:

		switch (LOWORD(wParam))

		{

		case IDC_BUTTON1:


			inn(inn_n);
			SetDlgItemText(hWnd, IDC_EDIT1, inn_n);
			break;

		case IDCANCEL:

			break;

		}

		break;

	case WM_CLOSE:

		EndDialog(hWnd, 0);

		break;

	}

	return FALSE;

}

int inn(char * x)
{
	int inn[12];
	char  intstr[13];
	for (int i = 0; i < 10; inn[i] = mrand() % 10, i++);
	int n2 = ((7 * inn[0] + 2 * inn[1] + 4 * inn[2] + 10 * inn[3] + 3 * inn[4] + 5 * inn[5] + 9 * inn[6] + 4 * inn[7] + 6 * inn[8] + 8 * inn[9]) % 11) % 10;
	int n1 = ((3 * inn[0] + 7 * inn[1] + 2 * inn[2] + 4 * inn[3] + 10 * inn[4] + 3 * inn[5] + 5 * inn[6] + 9 * inn[7] + 4 * inn[8] + 6 * inn[9] + n2 * 8) % 11) % 10;
	inn[10] = n2;
	inn[11] = n1;

	for (int ii = 0; ii < 12; ii++)
	{
		intstr[ii] = '0' + inn[ii];
	}
	intstr[12] = 0;
	lstrcpy(x, intstr);
	return 0;
}

int mrand(void) // RAND_MAX assumed to be 32767
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

void msrand(unsigned int seed)
{
	next = seed;
}
