// chat_client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "chat_client.h"
#include <afxsock.h>

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
            CSocket client;

            // Initialize socket
            client.Create();

            // Connect to server
            client.Connect(_T("127.0.0.1"), 12345); // _T is using to convert string to Cstring

            // Initialize variables
            char msg[100];
            int len = 0;

            // Start chatting
            while (true)
            {
                // Client chat first
                cout << "client says: " << endl;
                gets_s(msg);
                len = strlen(msg);

                // Send msg to server
                client.Send(&len, sizeof(int), 0); //send length of msg to reciever first, receiver prepare buff for storing
                client.Send(msg, len, 0);

                // receive msg from server
                client.Receive(&len, sizeof(int), 0); //send length of msg to reciever first, reciever prepare buff for storing

                // Create a buffer to store msg
                char* temp = new char[len + 1];
                client.Receive(temp, len, 0);
                temp[len] = '\0'; // end of string

                // print msg
                cout << "Server said: " << temp << endl;

                if ((strcmp(temp, "pp") == 0) || (strcmp(temp, "bye") == 0))
                {
                    // notified server for terminating
                    msg[0] = 'p';
                    msg[1] = 'p';
                    len = 2;
                    client.Send(&len, sizeof(int), 0);
                    client.Send(msg, 2, 0);
                    break;
                }

                delete temp;
                
            }
            client.Close();

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
