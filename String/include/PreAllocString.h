class PreAllocString{
    operator const char *() const;
    operator const void *() const;

    const char & operator [] (const int idx);

    size_t GetLength() const;

    constexp size_t SizeOf();

    void Empty();

    PreAllocString& operator =(char rhs);
    PreAllocString& operator =(const char * rhs);
    PreAllocString& operator =(char * const rhs);

    PreAllocString& operator +=(char rhs);
    PreAllocString& operator +=(char const * rhs);

    void AddFormat(const char* format,...);
    void AddWhiteSpace();
}
