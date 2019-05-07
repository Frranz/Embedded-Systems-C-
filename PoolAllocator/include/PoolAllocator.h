#ifndef POOL_ALLOCATOR_H
#define POOL_ALLOCATOR_H
#include <cstddef>
#include <cstdint>

#define CREATE(varName, blockCount, blockSize) PoolAllocator<blockSize, blockCount> varName 

class IHeap
{
    public:
        virtual void* Allocate(size_t sizeInBytes) = 0;
        virtual void  Deallocate(void*)            = 0;
        virtual size_t Available()           const = 0;
};

// impelementation


template <size_t blockSize, size_t blockCount>
class PoolAllocator : IHeap{
    public:
        void* Allocate(size_t sizeInBytes) {
            if(sizeInBytes > blockSize) {
                return nullptr;
            }

            for(size_t i = 0; i < blockCount; ++i) {
                if(blocksUsed[i] == false) {
                    blocksUsed[i] = true;
                    ++availableBlocks;
                    return static_cast<void*>(data[i]);
                }
            }

            return nullptr;
        }

        void Deallocate(void* deallocateThis) {

            //check if pointer is nullptr, inside of boundaries of data variable and is at correct blockSize boundary 
            //letztes auf jeden fall nochmal testen!!!!!!!!!!!!!!!!
            if(deallocateThis == nullptr && deallocateThis < data[0] && deallocateThis >= data[blockCount] + blockCount){// && (deallocateThis - data[0]) % blockSize == 0) {
                return;
            }

            size_t deallocIndex = (static_cast<uint8_t*>(deallocateThis) - data[0]) * blockSize;
            for(size_t i = 0; i < 4; ++i) {
                data[deallocIndex][i] = 0;
            }

            --availableBlocks;
        }

        size_t Available() const {
            return availableBlocks;
        }
    private: 
        uint8_t data[blockCount][blockSize]{0};
        bool blocksUsed[blockCount]{false};
        size_t availableBlocks{0};
};
#endif