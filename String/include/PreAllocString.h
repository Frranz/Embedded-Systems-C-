#include <cstddef>

template <size_t Stringsize>
class PreAllocString{
public:
    operator const char *() const;
    operator const void *() const;

    const char & operator [] (const int idx);

    size_t GetLength() const;

    constexpr size_t SizeOf();

    void Empty();

    PreAllocString& operator =(char rhs);
    PreAllocString& operator =(const char * rhs);
    PreAllocString& operator =(char * const rhs);

    PreAllocString& operator +=(char rhs);
    PreAllocString& operator +=(char const * rhs);

    void AddFormat(const char* format,...);
    void AddWhiteSpace();

private:
    char myString[Stringsize];
};
