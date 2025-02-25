#pragma once

namespace m61 {

    template <typename Worker, typename... Args>
    class BruteForcer {
        
        private: 

        public: 
        BruteForcer(Worker _worker, Args... _workerArgs); 
        ~BruteForcer()

    };
}