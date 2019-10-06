//use <utility> header for pair stl
//Case 1 : Sorting the vector elements on the basis of first element of pairs in ascending order.
sort(vect.begin(), vect.end());


//Case 2:Sorting the vector elements on the basis of second element of pairs in ascending order.
// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
sort(vect.begin(), vect.end(), sortbysec);


//Case 3(a) : Sorting the vector elements on the basis of first element of pairs in descending order.
// Driver function to sort the vector elements by
// first element of pair in descending order
bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}
sort(vect.begin(), vect.end(), sortinrev);
//Case 3(b) : one can directly use this also for case 3
sort(vect.rbegin(), vect.rend());

//case 4:
// Driver function to sort the vector elements by
// second element of pair in descending order
bool sortsecdesc(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.second > b.second);
}
sort(vect.begin(), vect.end(), sortsecdesc);

