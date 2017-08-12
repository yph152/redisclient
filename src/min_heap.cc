#include "../include/min_heap.h"
#include <time.h>
#include <netinet/in.h>

time_heap::time_heap(int cap):capacity_( cap ),cur_size_( 0 ){
    array = new heap_timer*[capacity];
    if ( !array_ ){
        return;
    }
    for(int i=0;i<capacity_;++i){
        array_[i] = NULL;
    }
}
time_heap::time_heap(heap_timer** init_array,int size,int capacity)
    :cur_size_( size ),capacity_( capacity ){
        if ( capacity_ < size ){
            return;
        }
        array_ = new heap_timer*[capacity_];
        if ( !array_ ){
            return;
        }
        for(int i=0;i<capacity_;++i){
            array_[i] = NULL;
        }
        if (size != 0){
            for(int i=0;i<size;++i){
                array_[i] = init_array[i];
            }
            for(int i=(cur_size_ - 1)/2;i>=0;--i){
                percolate_down(i);
            }
        }
}
time_heap::~timer_heap(){
    for(int i=0;i<cur_size_;++i){
        delete array_[i];
    }
    delete []array_;
}
void time_heap::add_timer(heap_timer* timer){
    if ( !timer ){
        return;
    }
    if (cur_size_ >= capacity_){
        resize();
    }
    int hole = cur_size_++;
    int parent = 0;
    for(;hole>0;hole=parent){
        parent = (hole-1)/2;
        if (array_[parent]->expire_ <= timer->expire_){
            break;
        }
        array_[hole] = array_[parent];
    }
    array_[hole] = timer;
}
void time_heap::del_timer(heap_timer* timer){
    if( !timer ){
        return;
    }
    timer->cb_func_ = NULL;
}
void time_heap::add_time::time_heap* top(){
    if( empty() ) {
            return NULL;
    }
    return array_[0];
}

void time_heap::pop_timer(){
    if ( empty() ){
        return;
    }
    if ( array_[0] ){
        delete array_[0];
        array_[0] = array_[--cur_size_];
        percolate_down(0);
    }
}

void time_heap::tick(){
    heap_timer* tmp = array_[0];
    time_t cur = time(NULL);
    while( !empty() ){
        if ( !tmp ){
            break;
        }
        if(tmp->expire_ > cur){
            break;
        }
        if( array_[0]->cb_func_ ){
            array_[0]->cb_func_(array_[0]->user_data);
        }
        pop_timer();
        tmp = array_[0];
    }
}
bool time_heap::empty(){
    return cur_size_ == 0;
}

void time_heap::percolate_down(int hole){
    heap_timer* temp = array_[hole];
    int child = 0;
    for(;((hole*2+1) <= (cur_size_-1));hole=child){
        child = hole*2+1;
        if( (child < (cur_size_-1)) && (array_[child+1]->expire_ < array_[child]->expire_) ){
            ++child;
        }
        if( array_[child]->expire_ < temp->expire_ ){
            array_[hole] = array_[child];
        }else{
            break;
        }
    }
    array_[hold] = temp;
}

void time_heap::resize(){
    heap_timer** temp = new heap_timer*[2*capacity_];
    for(int i=0;i<2*capacity_;++i){
        temp[i] = NULL;
    }
    if ( !temp ){
        return;
    }
    capacity_ = 2*capacity_;
    for(int i=0;i<cur_size_;++i){
        temp[i] = array_[i];
    }
    delete []array_;
    array_ = temp;
}
