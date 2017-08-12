#ifndef MYHASH_H_
#define MYHASH_H_

class HashItem{
    public:
        HashItem(int k,int v):key(k),val(v){}
        const int& GetKey(){
            return key;
        }
        const int& GetVal(){
            return val;
        }
    private:
        int key;
        int val;
};

class HashTable{

    private:
        static const int SIZE = 256;
        HashItem **table;
    public:
        HashTable(){
            table = new HashItem*[SIZE]();
        }
        void set(){
            int idx = key%SIZE;
            while(table[idx] && table[idx]->GetKey() != key){
                idx = (idx+1)%SIZE;
            }
            if(table[idx]){
                delete table[idx];
            }
            table[idx] = new HashItem(key,val);
        }
        const int get(key){
            int idx = key%SIZE;
            while(table[idx] && table[idx]->getkey() != key)
                idx = (idx+1)%SIZE;
            return table[idx]?table[idx]->GetVal : -1;   //这里需要判断key不存在的情况
        }
        ~HashTable(){
            for(int i=0;i<SIZE;i++){
                if(table[i]){
                    delete table[i];
                }
            }
            delete[] table;
        }
};
#endif
