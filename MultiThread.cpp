#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex locker;
int countProduct = 0;

void producerProc()
{
	while (true)
	{
		locker.lock();
		countProduct += (1 + rand() % 10);
		cout << "Producer process:" << countProduct << endl;
		locker.unlock();
		this_thread::sleep_for(chrono::microseconds(rand() % 2000));
		//locker.unlock();
	}
	
}
void consumerProc()
{
	while (true)
	{
		locker.lock();
		countProduct -= (1 + rand() % 10);
		cout << "Consumer process:" << countProduct << endl;
		locker.unlock();
		this_thread::sleep_for(chrono::microseconds(rand() % 2000));
		//locker.unlock();
	}
	
}
int main()
{
	thread producerThread(producerProc);
	thread consumerThread(consumerProc);
	producerThread.join();
	consumerThread.join();
	return 0;
}