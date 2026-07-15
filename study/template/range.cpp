template <typename T>
T rangeMax(T begin, T end){
    if(begin == end) return end; //空区间 返回end
    T max = begin;
    for(T it = begin;it != end;++it){
        if( *it >(*max)){
            max = it;
        }    
    }
    return max;
}

