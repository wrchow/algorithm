// pv015 《程序员面试100题》第15题
// 含有指针成员的类的拷贝

template<typename T> class Array{
public:
    Array(unsigned arraySize):data(0), size(arraySize){
        if(size > 0)
        data = new T[size];
    }
    ~Array(){
        if(data) delete[] data;
    }
    void setValue(unsigned index, const T& value){
        if(index < size)
        data[index] = value;
    }
    T getValue(unsigned index) const{
        if(index < size)
            return data[index];
        else
            return T();
    }
private:
    T* data;
    unsigned size;
};

int main(int argc, char* argv[])
{
    Array<int> A(10);
    Array<int> B(10);
    A = B;
    return 0;
}