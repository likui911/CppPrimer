template <class T>
int compare(const T &a, const T &b)
{
    return a > b ? 1 : -1;
}

int main()
{
    //char[3] vs char[6]
    //compare("hi", "world"); //no matching function for call compare
    compare("dad", "bad");
    return 0;
}