class DataStream {
    int k;
    int val;
    int count = 0;
public:
    DataStream(int value, int k) {
        this->k = k;
        this-> val = value;
    }
    
    bool consec(int num) {
        if(num==val)    count++;
        else    count = 0;

        return count>=k;
    }
};
