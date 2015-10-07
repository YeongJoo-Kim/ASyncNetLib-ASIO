// SyncServerSvr.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include <SDKDDKVer.h>
#include "stdafx.h"
#include <iostream>
#include "ASyncTcpServer/ASyncTcpServer.h"

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/convenience.hpp>


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
	/*
	std::shared_ptr<boost::asio::io_service>	mIo = std::shared_ptr<boost::asio::io_service>(new boost::asio::io_service());
	std::shared_ptr<void>						mIoWork = std::shared_ptr<boost::asio::io_service::work>(new boost::asio::io_service::work(*mIo));

	SyncServer sync(*mIo, 20000);

	sync.start();


	//cout << "press any key..." << endl;
	//getchar();
	mIo->run();

	mIo->stop();


	return 0;
	*/


	std::shared_ptr<boost::asio::io_service>	mIo = std::shared_ptr<boost::asio::io_service>(new boost::asio::io_service());
	std::shared_ptr<void>						mIoWork = std::shared_ptr<boost::asio::io_service::work>(new boost::asio::io_service::work(*mIo));

	
	
	ASyncTcpServer server(*mIo, 20000);

	try
	{
#if 0
		if (argc != 2)
		{
			std::cerr << "Usage: async_tcp_echo_server <port>\n";
			return 1;
		}
		server.Begin(atoi(argv[1]));
#else
		server.Begin();
#endif




	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	boost::thread thread(boost::bind(&boost::asio::io_service::run, mIo));

	//mIo->run();

	//SetConsoleCtrlHandler(console_ctrl_handler, TRUE);

	char ch = 0;
	while (getchar() != 'q')
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

	mIo->stop();
	thread.join();
	return 0;
}



#if 0
// SyncServerSvr.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include <SDKDDKVer.h>
#include "stdafx.h"
#include <iostream>
#include "SyncServer/SyncServer.h"

int main()
{
	std::shared_ptr<boost::asio::io_service>	mIo = std::shared_ptr<boost::asio::io_service>(new boost::asio::io_service());
	std::shared_ptr<void>						mIoWork = std::shared_ptr<boost::asio::io_service::work>(new boost::asio::io_service::work(*mIo));

	SyncServer sync(*mIo, 20000);

	sync.start();


	//cout << "press any key..." << endl;
	//getchar();
	mIo->run();

	mIo->stop();


    return 0;
}
#endif

