/*
* Naive Method, also known as Quick Union algorithm
* Space Complexity: O(n)
* Time Complexity: Find O(n)
*                  Union O(n)
*/

#include <iostream>
#include <assert.h>
using namespace std;


class QuickUnion
{
public:
    QuickUnion(int n):len(n)
    {
        id = new int[n];
        for(int i=0; i<len; i++) id[i]=i;
    }

    ~QuickUnion()
    {
        delete [] id;
        id = nullptr;
    }

    /* to check if nodes are connected */
    bool connected(int p, int q)
    {
        int pid = root(p);
        int qid = root(q);

        return pid == qid;
    }

    void Union(int p, int q)
    {
        int pid = root(p);
        int qid = root(q);

        id[pid] = qid;
    }
private:
    int root(int i)
    {
        while(id[i] != i) i = id[i];
        return i;
    }

    int *id;
    int len;
};

//Driver function
int main()
{
    QuickUnion q(10);

    cout<<"\nConnect 0, 1"; q.Union(0, 1);
    cout<<"\nConnect 2, 3"; q.Union(2, 3);

    cout<<"\nIs 0, 3 connected : "<<q.connected(0, 3);
    assert(q.connected(0, 3)==false);
    cout<<"\nIs 2, 3 connected : "<<q.connected(2, 3);
    assert(q.connected(2, 3)==true);

    cout<<"\nConnect 5, 9 : "; q.Union(5,9);
    cout<<"\nConnect 7, 9 : "; q.Union(5,9);
    cout<<"\nConnect 0, 5 : "; q.Union(0, 5);

    cout<<"\nIs 9, 0 connected : "<<q.connected(9, 0);
    assert(q.connected(9, 0)==true);

    return 0;
}
