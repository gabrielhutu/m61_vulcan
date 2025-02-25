#include <iostream> 
#include <liburing.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string>
#include <stdexcept>




int main(int argc, char** argv) {

    struct io_uring ring;
    struct io_uring_sqe* sqe; 
    struct io_uring_cqe* cqe;

    io_uring_queue_init(1, &ring, 0);

    sqe = io_uring_get_sqe(&ring);

    // open file descriptor
    int fd = open("../test_data/test.txt", O_RDONLY | O_CLOEXEC);

    // Get file info
    struct stat st; 
    fstat(fd, &st);
    off_t file_size = st.st_size;

    char* buffer = static_cast<char*>(malloc(4096));


    io_uring_prep_read(sqe, fd, buffer, file_size, 0); 
    sqe->flags |= IOSQE_ASYNC;
    io_uring_submit(&ring);

    // Check if the operation is done and if not keep peeking for completion
    io_uring_peek_cqe(&ring, &cqe);
    while (!cqe) {
        std::cout << "Processing..." << std::endl;
        io_uring_peek_cqe(&ring, &cqe);
    }
    
    std::cout << buffer << std::endl; 
}