#include "stdafx.h"
#include "Server.h"

// �ܼ� ��Ʈ�� �ڵ鷯�� ȣ���� �Լ�
boost::function0<void> console_ctrl_function;
BOOL WINAPI console_ctrl_handler(DWORD ctrl_type)
{
	switch (ctrl_type)
	{
	case CTRL_C_EVENT:
	case CTRL_BREAK_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_SHUTDOWN_EVENT:
		// �ֿܼ��� ���� ��Ʈ�� Ÿ�� �̺�Ʈ�� ����� ȣ��ȴ�.
		console_ctrl_function();
		return TRUE;
	default:
		return FALSE;
	}
}

int main(int argc, char* argv[])
{

 	Server server;
 
 	try
 	{
 		if (argc != 2)
 		{
 			std::cerr << "Usage: async_tcp_echo_server <port>\n";
 			return 1;
 		}
 
 		
 
 		server.Begin(atoi(argv[1]));
 	}
 	catch (std::exception& e)
 	{
 		std::cerr << "Exception: " << e.what() << "\n";
 	}



	SetConsoleCtrlHandler(console_ctrl_handler, TRUE);

	char ch = 0;
	while(getchar() != 'q')
	{
		//ch = getchar();

		switch (ch)
		{
		case 'a':
			//Server
			break;
		default:
			break;
		}

	}

	return 0;
}
