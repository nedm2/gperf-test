all:
	g++ -std=c++0x -pthread -o mt_test mt_test.c -Wl,--no-as-needed,-lrt,--as-needed -fopenmp
	LD_PRELOAD="/usr/local/lib/libprofiler.so ../gperf-all-threads/profile_all_threads.so" CPUPROFILE_PER_THREAD_TIMERS=t CPUPROFILE=mt_test.prof ./mt_test
	pprof --gv mt_test mt_test.prof

clean:
	rm -f mt_test mt_test.prof
