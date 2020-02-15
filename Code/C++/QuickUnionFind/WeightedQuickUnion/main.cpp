/*
* Weighted Quick Union, improvement over naive algorithm
* Space Complexity: O(n)
* Time Complexity: Find O(lg(N))
*                  Union O(lg(N))
*                  Initialization: O(N)
*/

#include <iostream>
#include <assert.h>
using namespace std;

class WeightedQuickUnion
{
public:
    WeightedQuickUnion(int n)
    {
        len = n;
        id = new int[len];
        sz = new int[len];
        /*Note: sz should be initialized to 1 not 0, common mistake*/
        for(int i=0; i <len; i++) {id[i]=i;sz[i]=1;}
    }

    ~WeightedQuickUnion()
    {
        delete [] id;
        delete [] sz;

        id = nullptr;
        sz = nullptr;
    }

    bool connected(int p, int q)
    {
        return root(p) == root(q);
    }

    void Union(int p, int q)
    {
        int pid = root(p);
        int qid = root(q);

        if(sz[pid] >= sz[qid]) {id[qid] = pid;sz[pid]+=sz[qid];}
        else                   {id[pid] = qid;sz[qid]+=sz[pid];}
    }

private:

    int root(int i)
    {
        while(id[i]!=i)i=id[i];
        return i;
    }

    int * id;
    int * sz;
    int len;
};

//Driver function
int main()
{
    WeightedQuickUnion q(10);

    q.Union(4, 3);
    q.Union(6, 5);
    q.Union(0, 5);
    q.Union(1, 7);

    cout<<"\nIs 6,0 connected"<<q.connected(6, 0);
    assert(q.connected(6, 0));

    q.Union(8, 9);
    q.Union(0, 8);
    q.Union(3, 8);

    cout<<"\nIs 6,0 connected"<<q.connected(6, 0);
    assert(q.connected(6, 0));

    cout<<"\nIs 3,8 connected"<<q.connected(3, 8);
    assert(q.connected(3, 8));

    return 0;
}
