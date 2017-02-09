//
//  main.cpp
//  stlTest
//
//  Created by Sonam Phuntsog on 2/9/17.
//  Copyright © 2017 Sonam Phuntsog. All rights reserved.
//

#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>
#include <stdexcept>
#include <time.h>
#include <numeric>
#include <math.h>
#include <random>
#include <deque>
#include <map>
#include <set>

using namespace std;

template <typename T> void printVector(const vector<T> &vec){
    if(vec.empty())
        cout<< "Vector is empty" <<endl;
    else{
        ostream_iterator< T > output(cout," ");
        copy(vec.begin(), vec.end(), output);
        cout<<endl;
    }
}
template <typename T> void printList(const list<T> &lst){
    if(lst.empty())
        cout<< "List is empty" <<endl;
    else{
        ostream_iterator< T > output(cout," ");
        copy(lst.begin(), lst.end(), output);
        cout<<endl;
    }
}
template <typename k, typename v> void printMultimap(const multimap<k,v> &mm){
    if(mm.empty())
        cout << "Multimap is empty" << '\n';
    else{
        for_each(mm.begin(),mm.end(),[](pair<k, v> m){cout<<" key:"<<m.first<<" val:"<<m.second<<endl;});
    }
}
template <typename k, typename v> void printMap(const map<k,v> &mm){
    if(mm.empty())
        cout << "Map is empty" << '\n';
    else{
        for_each(mm.begin(),mm.end(),[](pair<k, v> m){cout<<" key:"<<m.first<<" val:"<<m.second<<endl;});
    }
}
template <typename T> void printMultiset(const multiset<T> &ms) {
    if(ms.empty())
        cout<<"Multiset is empty"<<endl;
    else{
        ostream_iterator< T > output(cout," ");
        copy(ms.begin(), ms.end(), output);
        cout<<endl;
    }
}
template <typename T> void printSet(const set<T> &s) {
    if(s.empty())
        cout<<"Set is empty"<<endl;
    else{
        ostream_iterator< T > output(cout," ");
        copy(s.begin(), s.end(), output);
        cout<<endl;
    }
}
void Vector(){
    int arr[5] = {1, 2, 3, 4, 5};
    int ar[5] = {100, 200, 300, 400, 500};
    
    vector<int> v(arr,arr + 5);
    printVector(v);
    v.erase(v.end() - 2);
    printVector(v);
    v.insert(v.begin() + 1 ,ar, ar+5);
    printVector(v);
    v.insert(v.begin()+2, 4,3);//insert 3 at v[2] 4 times
    printVector(v);
    cout<<"v is "<<(v.empty()?"empty": "not empty")<<endl;
    v.clear();
    cout<<"v is "<<(v.empty()?"empty": "not empty")<<endl;
    
}
void List(){
    list< double > l;
    double d[] = { 50, 50, 30, 40};
    list< double > ll(d, d+4);
    
    l.push_back(.2);
    l.push_back(1e-3);
    
    printList(l);
    printList(ll);
    
    ll.sort();
    l.sort();
    
    printList(l);
    printList(ll);
    
    ll.splice(ll.end(),l);
    
    printList(l);
    printList(ll);
    
    ll.unique();
    printList(ll);
    
    ll.swap(l);
    
    printList(l);
    printList(ll);
    
    l.remove(50);
    printList(l);
    printList(ll);
    
    ll.assign(l.begin(), l.end());
    
    printList(l);
    printList(ll);
    
}
void Deque(){
    deque <string> d;
    d.push_front("Sonam");
    d.push_front("Dr.");
    d.push_back("Phuntsog");
    for_each(d.begin(), d.end(), [](string s){cout<<s+' ';});
    cout<<endl;
}
void uniformDistribution(){
    vector<int> l;
    time_t sec;
    time(&sec);
    srand((unsigned int)sec);
    const int M = 1e3;
    for(int i = 0; i<M; i++){
        l.push_back(rand()%10 + 1);
    }
    
    vector< int > his;
    his.resize(10,0);
    // for(auto p = l.begin(); p != l.end(); p++){
    //   his[*p - 1]++;
    // }
    for(auto i = 0; i < his.size(); i++){
        his[i] = count(l.begin(), l.end(), i + 1);
    }
    double mue = accumulate(l.begin(),l.end(),(double)0)/M;
    
    double var;
    for(auto p = l.begin(); p != l.end(); p++){
        var += pow((double)*p,2);
    }
    var = var/M- pow(mue,2);
    
    cout<<"size of list is:"<<l.size()<<" std deav:"<<pow(var,0.5)<<" mue:"<<mue<<endl;
    printVector(his);
    
    //printList(l);
}
void normalDistribution(){
    vector<double> l;
    time_t sec;
    time(&sec);
    srand((unsigned int)sec);
    const int M = 1e3;
    
    default_random_engine generator;
    normal_distribution<double> distribution(5.0,2.0);
    for(int i = 0; i<M; i++){
        l.push_back(distribution(generator));
    }
    
    
    vector< int > his;
    his.resize(10,0);
    for(auto p = l.begin(); p != l.end(); p++){
        if ((*p >= 0.0)&&(*p < 10.0)) ++his[int(*p)];
    }
    
    double mue = accumulate(l.begin(),l.end(),(double)0)/M;
    
    double var;
    for(auto p = l.begin(); p != l.end(); p++){
        var += pow((double)*p,2);
    }
    var = var/M- pow(mue,2);
    
    cout<<"size of list is:"<<l.size()<<" std deav:"<<pow(var,0.5)<<" mue:"<<mue<<endl;
    printVector(his);
    //printList(l);
}
void lambda(){
    vector<int> v(10,1);
    vector<int> w(v.size());
    vector<bool> b(10,false);
    transform(v.begin(),v.end(),w.begin(),[](int i){return i*10;});//unary
    //        in start ,in end, out start, apply
    printVector(w);
    transform(v.begin(),v.end(),w.begin(),b.begin(),[](int i,int j) -> bool{return j+i > 2;});
    //        in1 start ,in1 end, in2 start,out start, apply
    
    for_each(b.begin(),b.end(),[](bool i){cout<<i<<' ';});  // printVector(b);
    cout<<endl;
    
}
void Map(){
    typedef multimap< int, double> Mmid;
    Mmid pairs;
    pairs.insert(Mmid::value_type(1, 10.10101));
    pairs.insert(Mmid::value_type(1, 4.4));
    pairs.insert(Mmid::value_type(2, 22.0));
    printMultimap(pairs);
    cout<<"key 1 is "<<(pairs.find(1) != pairs.end()?"in":"not in")<<" pairs"<<endl;
    
    typedef map< int, double> Mid;
    Mid mp;
    mp.insert(Mid::value_type(1, M_PI));
    mp[2] = M_PI * 2;
    printMap(mp);
}
void Set(){
    typedef multiset< string> ms;
    ms students;
    students.insert("mouth");
    students.insert("legs");
    students.insert("thighs");
    students.insert("toung");
    printMultiset(students);
    auto l = students.find("legs");
    pair< ms::const_iterator,ms::const_iterator > p;
    p = students.equal_range("legs");
    cout<<*(p.first)<< ' ' << *(p.second)<<endl;
    
    typedef set< double> s;
    s rollNo;
    rollNo.insert(32);
    rollNo.insert(22);
    double a[] = {M_PI, 2.22, 4.44};
    pair< s::const_iterator, bool> pp;
    pp = rollNo.insert(22);
    
    cout<<boolalpha<<pp.second<<endl;
    cout<<boolalpha<<(rollNo.find(22) != rollNo.end())<<endl;//find if 22 is in rollNo
    printSet(rollNo);
}
int main(int argc, char* argv[]){
    uniformDistribution();
    return 0;
}

