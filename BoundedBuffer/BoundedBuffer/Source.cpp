
#include <iostream>      
#include <thread>        
#include <mutex>         
#include <condition_variable>

std::mutex mtx;             // mutex for critical section
std::mutex read;
std::mutex write;
std::mutex Baton;
std::condition_variable cv; // condition variable for critical section  
bool ready = false;         // Tell threads to run
int current = 0;           // current count
const int maxCount = 15;
int fillCount = 0, emptyCount = maxCount;
int bufferArray[maxCount];
							/* Prints the thread id / max number of threads */
void print_num(int num, int max) {

	std::unique_lock<std::mutex> lck(mtx);
	while (num != current || !ready) { cv.wait(lck); }
	current++;
	std::cout << "Thread: ";
	std::cout << num + 1 << " / " << max;
	std::cout << " current count is: ";
	std::cout << current << std::endl;

	/* Notify next threads to check if it is their turn */
	cv.notify_all();
}
void produce(int num)
{
	std::unique_lock<std::mutex> lock(Baton);
	while (!ready||emptyCount==0) { cv.wait(lock); }//checks if the ready bool, or amount in array is less than max or there's empty spots
	if (Baton.try_lock())
	{
		bufferArray[fillCount] = num;
		fillCount++;
		emptyCount--;
		Baton.unlock();
	}
	else
	{

	}
	cv.notify_all();
	std::cout << "finished write: " << fillCount << std::endl;
}

void consume(int num)
{
	std::unique_lock<std::mutex> lock(Baton);
	while (!ready||maxCount==emptyCount) { cv.wait(lock); }//checks if the ready bool, or amount in array is equal to max or there's no empty spots
	if (Baton.try_lock())
	{
		std::cout << "array at: " << fillCount << " is:" << bufferArray[fillCount] << std::endl;
		bufferArray[fillCount] = -1;
		fillCount--;
		emptyCount++;
		Baton.unlock();
	}
	else
	{
		std::cout << "consume :" << num << "failed" << std::endl;
	}
	cv.notify_all();
}
/* Changes ready to true, and begins the threads printing */
void run() {
	std::unique_lock<std::mutex> lck(mtx);
	ready = true;
	cv.notify_all();
}

int main() {

	for (int i = 0; i < maxCount; i++)
	{
		bufferArray[i] = -1;
	}
	int threadnum = 15;
	std::thread produceThreads[15];
	std::thread consumeThreads[15];
	int tempID;
	/* spawn threadnum threads */
	for (int id = 0; id < threadnum; id++)
	{
		//threads[id] = std::thread(print_num, id, threadnum);
		tempID = id;
		produceThreads[tempID] = std::thread(produce, tempID);
		consumeThreads[tempID] = std::thread(consume, tempID);
	}
	std::cout << "\nRunning " << threadnum;
	std::cout << " in parallel: \n" << std::endl;

	run(); // Allows threads to run

		   /* Merge all threads to the main thread */
	for (int id = 0; id < threadnum; id++)
	{
		tempID = id;
		consumeThreads[tempID].join();
	}
	for (int id = threadnum; id > 0; id--)
	{
		tempID = id;
		consumeThreads[tempID].join();
	}

	std::cout << "\nCompleted semaphore example!\n";
	std::cout << std::endl;
	
	return 0;
}