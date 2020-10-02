// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "Project1.h"
#include <afxsock.h>
#include <string.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int main()
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(nullptr);

	if (hModule != nullptr)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
		{
			// TODO: code your application's behavior here.
			wprintf(L"Fatal Error: MFC initialization failed\n");
			nRetCode = 1;
		}
		else
		{
			// TODO: code your application's behavior here.
			// Declare using socket in window
			AfxSocketInit(NULL);

			// Socket client
			CSocket client, server;

			// Initialize socket with port 12345
			server.Create(12345);

			// Listen from client
			server.Listen();

			cout << "Waiting for client!" << endl;

			if (server.Accept(client))
			{
				cout << "Client connected!" << endl;
			}

			// Initialize variables
			int len = 0;
			char msg[100];

			// Start chatting
			while (true)
			{
				// Receive msg from client
				client.Receive(&len, sizeof(int), 0); //send length of msg to reciever first, reciever prepare buff for storing

				// Create a buffer to store msg
				char* temp = new char[len + 1];
				client.Receive(temp, len, 0);

				temp[len] = '\0'; // end of string

				// print msg
				cout << "Client said: " << temp << endl;

				if ((strcmp(temp, "pp") == 0) || (strcmp(temp, "bye") == 0))
				{
					// notified client terminated
					msg[0] = 'p';
					msg[1] = 'p';
					len = 2;
					client.Send(&len, sizeof(int), 0);
					client.Send(msg, 2, 0);
					break;
				}

				delete temp;

				// send msg to client
				cout << "server says: " << endl;
				gets_s(msg);
				len = strlen(msg);

				client.Send(&len, sizeof(int), 0);
				client.Send(msg, len, 0);
				
			}
			client.Close();
			server.Close();
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		wprintf(L"Fatal Error: GetModuleHandle failed\n");
		nRetCode = 1;
	}

	return nRetCode;
}
