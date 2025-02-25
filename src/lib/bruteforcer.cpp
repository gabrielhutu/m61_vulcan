#include "bruteforcer.hpp"

template <typename Worker, typename... Args>
m61::BruteForcer<Worker, Args...>::BruteForcer(Worker _worker, Args... _workerArgs) {
    
}

template <typename Worker, typename... Args>
m61::BruteForcer<Worker, Args...>::~BruteForcer() {
    // Cleanup code here
}