#ifndef MIN_HEAP_H_
#define MIN_HEAP_H_

#include <netinet/in.h>
#include <time.h>

#define BUFFER_SIZE   64

class heap_timer;   /* 前向声明*/

struct client_data{
    sockaddr_in address_;
    int sockfd_;
    char buf_[BUFFER_SIZE];
    heap_timer* timer_;
};

/* 定时器类*/

class heap_timer{
    public:
        heap_timer(int delay){
            expire_ = time( NULL ) + delay;
        }
    public:
        time_t expire_;
        void (*cb_func_)(client_data*);
        client_data* user_data_;
};

/* 时间堆类 */
class time_heap{
    public:
        /* 构造函数之一，初始化一个大小为cap的空堆*/
        time_heap(int cap);
        /* 构造函数之二，用已有的数组来初始化*/
        time_heap( heap_timer** init_array,int size,int capacity);
        ~time_heap();
    public:
        void add_timer(heap_timer* timer);
        void del_timer(heap_timer* timer);
        const heap_timer* top();
        void pop_timer();
        void tick();
        bool empty();
    private:
        void precolate(int hole);
        void resize(); 
    private:
        head_timer** array_;  /*堆数组*/
        int capacity_;     /*堆数组的容量*/
        int cur_size_;    /*堆数组当前包含的个数*/
};

#endif
