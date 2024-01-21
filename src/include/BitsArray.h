#ifndef BITSARRAY_H
#define BITSARRAY_H

class BitsArray {
    public:
        BitsArray(int size);
        int getArraySize();
        int* getArray();
        bool BitsArray::addUrlToArray(std::string url);
        void BitsArray::h1(std::string url);
        void BitsArray::h2(std::string url);
        bool BitsArray::isBlackListed(std::string url);
        std::size_t BitsArray::hashUrl(std::string url, std::string key);

    private:
        int size;
        int* array;
};

#endif