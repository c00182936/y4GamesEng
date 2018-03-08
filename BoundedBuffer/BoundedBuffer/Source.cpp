
#include <iostream>      
#include <thread>        
#include <mutex>         
#include <condition_variable>

#include <time.h>
class semaphore
{
public:
	semaphore() { value = 0; };
	semaphore(int val) :value(val) {};
	~semaphore() {};
	void dec(int val) { value -= val; };
	void inc(int val) { value += val; };
	bool compare(int val) {
		if (val == value)
		{
			return true;
		}
		return false;
	};
	int value;
private:

};
std::mutex mtx;// 
std::condition_variable cv; // stops the thread from running until ready
bool ready = false;         // Tell threads to run
bool readReady = false;
int current = 0;           // current count
const int maxCount = 15; const int empty=0;
int writeCount = 0, readCount=0, writeFull = 15;//counter and limiter to the amount of reads and writes
int bufferArray[maxCount];
bool readWrite = true;

semaphore counter;

void produce(int num)
{
	std::unique_lock<std::mutex> lock(mtx);
	while (!ready||counter.value>maxCount||writeCount>writeFull) { cv.wait(lock); }//checks if the ready bool, or amount in array is less than max or there's empty spots
	if (writeCount > writeFull)
	{
		std::cout << "write full" << std::endl;
		readReady = true;
	}
	if (readWrite)
	{
		readWrite = false;

		bufferArray[counter.value]=num;
		counter.inc(1);
		readWrite = true;
		writeCount++;
		std::cout << "written at thread: "<<num << std::endl;
	}

	cv.notify_all();

}

void consume(int num)
{
	std::unique_lock<std::mutex> lock(mtx);
	while (!ready || counter.value <= 0||readCount>writeFull) { cv.wait(lock); }//checks if the ready bool, or amount in array is equal to max or there's no empty spots
	if (readCount > writeFull)
	{
		std::cout << "read full" << std::endl;
	}
	if (readWrite)
	{
		readWrite = false;

		std::cout << bufferArray[counter.value]<<std::endl;
		counter.dec(1);
		bufferArray[counter.value] = -1;
		readWrite = true;
		std::cout << "read at thread: " << num << std::endl;
		readCount++;
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
	int threadnum = maxCount;
	std::thread produceThreads[maxCount];
	std::thread consumeThreads[maxCount];
	int tempID;
	/* spawn threadnum threads */
	for (int id = 0; id < threadnum; id++)
	{
		//threads[id] = std::thread(print_num, id, threadnum);
		tempID = id;
		produceThreads[tempID] = std::thread(produce, tempID);
		consumeThreads[tempID] = std::thread(consume, tempID);
	}
	run(); // Allows threads to run
	while (writeCount<writeFull&&readCount<writeFull)//stops the main thread from exiting before the reads and writes are complete
	{

	}
	if (writeCount >= writeFull ||readCount>=writeFull)
	{
		for (int id = 0; id < threadnum; id++)
		{
			tempID = id;
			produceThreads[tempID].join();
			consumeThreads[tempID].join();
		}
	}

//	system("pause");
	return 0;
}