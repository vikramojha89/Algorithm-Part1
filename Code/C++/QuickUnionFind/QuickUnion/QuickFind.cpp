/*
* Naive Method, also known as Quick Find algorithm
* Space Complexity: O(n)
* Time Complexity: Find O(1)
*                  Union O(n^2)
*/

#include <iostream>
using namespace std;

class QuickUnionFind
{
public:

    QuickUnionFind(int n):len(n)
    {
        try{
            id = new int[len];
            for(int i=0; i<len ; i++) id[i]=i;
        }catch(bad_alloc& ex){
            cout<<"OOPs!...Insufficient Memory";
        }
    }

    ~QuickUnionFind()
    {
        delete[] id;
        id = nullptr;
    }

    /* to check if to nodes are connected*/
    bool connected(int p, int q)
    {
        return id[p] == id[q];
    }

    void Union(int p, int q)
    {
        int pid = id[p];
        int qid = id[q];

        for(int i=0; i < len; i++)
            if(id[i] == pid) id[i] = qid;
    }

private:
    int * id;
    int len;
};

//Driver Function
int main()
{
    QuickUnionFind q(10);

    q.Union(0, 5);
    q.Union(5, 6);

    cout<<"\nIs 1 connected to 6 "<<q.connected(1, 6);

    q.Union(1, 6);

    cout<<"\nIs 1 connected to 6 "<<q.connected(1, 6);

    q.Union(2, 6);

    cout<<"\nIs 0 connected to 6 "<<q.connected(9, 6);
    return 0;
}
