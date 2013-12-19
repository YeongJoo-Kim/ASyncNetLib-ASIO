#define BOOST_ASIO_HAS_MOVE
#include "AsyncConnection.hpp"

using boost::asio::ip::tcp;
class AsyncConnectionManager : public std::enable_shared_from_this<AsyncConnectionManager>
{
public:
	void begin(AsyncConnect_ptr session)
	{
		mConnections.insert(session);

		session->start();

		
	}

	void stop(AsyncConnect_ptr session)
	{
		session->stop();

		mConnections.erase(session);
		
	}

	void stop_all()
	{
		// ��� connection::stop�� ������
		std::for_each(mConnections.begin(), mConnections.end(), [this](AsyncConnect_ptr connection)
			{
				connection->stop();
			}
		);

		mConnections.clear();
	}
	
	void WriteAll(unsigned char* buffer, unsigned int len)
	{
		std::for_each(mConnections.begin(), mConnections.end(), [this](AsyncConnect_ptr connection)
		{
			//connection->
		}
		);

	}
private:

	std::set<AsyncConnect_ptr> mConnections;
};
