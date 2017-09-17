#include <vector>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void thread_func() {
    //ProfilerRegisterThread();
    int size = 100000;
    vector<int> V(size);
    for(int i = 0; i < 100000; i++) {
        V.erase(V.begin() + (rand() % size));
        V.insert(V.begin() + (rand() % size), rand() % 10);
    }
}

void thread_func2() {
    //ProfilerRegisterThread();
    int size = 100000;
    vector<int> V(size);
    for(int i = 0; i < 100000; i++) {
        V.erase(V.begin() + (rand() % size));
        V.insert(V.begin() + (rand() % size), rand() % 10);
    }
}

int main() {
    srand(1234);
    thread t1(thread_func);
    thread t2(thread_func2);
    t1.join();
    t2.join();
    //milliseconds before = duration_cast< milliseconds >
    //    ( system_clock::now().time_since_epoch());
    //int size = 300000;
    //vector<int> V[2] = {vector<int>(size), vector<int>(size)};
    //#pragma omp parallel for 
    //for(int j = 0; j < 2; j++) {
    //    for(int i = 0; i < 100000; i++) {
    //        V[j].erase( V[j].begin() + (rand() % size));
    //        V[j].insert(V[j].begin() + (rand() % size), rand() % 10);
    //    }
    //}
    //milliseconds after = duration_cast< milliseconds >
    //    ( system_clock::now().time_since_epoch());
    //cout << (after - before).count() << endl;

    return 0;
}
