/****Hash Table****/
/*哈希表采用数组存储，哈希函数构造和处理冲突的方法是除留余数法+开放定址法*/

#include <iostream>
using namespace std;

#define tablesize 10
typedef int HashTable[tablesize];
//hash function initialization way
void Initial_HashTable(HashTable &ht)
{
    for (int i = 0; i < tablesize; i++)
        ht[i] = 0;
}
//search hashtable function
int Search_HashTable(HashTable &ht,int key)
{
    int address = key%tablesize;
    int compare = 0;
    while (compare < tablesize&&ht[address] != key&&ht[address] != 0)
    {
        compare++;
        address = (address+1)%tablesize;
    }
    if (compare == 10 || ht[address] == 0)
        cout << "can not find elem" << endl;
    return address;
}

//insert hashtable function
int Insert_HashTable(HashTable &ht,int key)
{
    int res = Search_HashTable(ht,key);
    if (ht[res] == 0)
    {
        ht[res] = key;
        return 1;
    }
    return 0;
}
//test function
int main()
{
    int data[8] = { 25,36,39,47,20,58,16,35 };
    HashTable ht;

    //initialization.
    Initial_HashTable(ht);

    //insert datas.
    for (int i = 0; i < 8; i++)
        cout << Insert_HashTable(ht, data[i]) << "  ";
    cout << endl;

    //search.
    cout << "25 : " << Search_HashTable(ht, 25) << endl;
    cout << "35 : " << Search_HashTable(ht, 35) << endl;
    cout << "145 : " << Search_HashTable(ht, 145) << endl;
    system("pause");
    return 0;
}
