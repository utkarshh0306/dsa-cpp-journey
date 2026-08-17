#include<iostream>
#include<list>
#include<iterator>
using namespace std;
void print(list<int> ll){
    list<int> :: iterator itr;

    for(itr=ll.begin() ; itr!=ll.end() ; itr++){
        cout<<(*itr)<<" -> ";
    }
    cout<<"NULL"<<endl;
}
int main(){
    list<int> ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    print(ll);

    cout<<ll.size()<<endl;
    cout<<"Head is "<<ll.front()<<endl;
    return 0;

}