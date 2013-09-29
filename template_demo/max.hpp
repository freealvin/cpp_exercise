template<typename T>
inline T const& max(T const & a, T const & b)
{
    return a<b?b:a;

}

template <typename T2, typename T1>
inline T2 const max(T1 const & a, T2 const & b)
{

    return a<b?b:a;
}
