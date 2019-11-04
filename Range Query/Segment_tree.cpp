/**Author : Vivek Bhardwaj
 *          Segment Trees
 **/

#include<bits/stdc++.h>
using namespace std;

void build_tree(vector<int> &s_tree,vector<int> &arr,int vertex,int l,int r){
    if(l==r){
        s_tree[vertex]=arr[l];
    } else{
        build_tree(s_tree,arr,2*vertex,l,(l+r)/2);
        build_tree(s_tree,arr,2*vertex+1,(l+r)/2+1,r);
        s_tree[vertex]=s_tree[2*vertex]+s_tree[2*vertex+1];
    }
}


//Give l=0 and r=arr.size()-1 for initial call and index =1 so as to start call from root
int sum(vector<int> &s_tree,int index,int ql,int qr,int l,int r){
    if(ql>r||qr<l) return 0;
    else if(ql<=l&&qr>=r) return s_tree[index];
    else{
        return sum(s_tree,2*index,ql,qr,l,(l+r)/2)+sum(s_tree,2*index+1,ql,qr,(l+r)/2+1,r);
    }

}

void update(vector<int> &s_tree,int index,int q,int val,int l,int r){
    s_tree[index]+=val;
    if(l==r) return;
    if(q>(l+r)/2) update(s_tree,2*(index)+1,q,val,(l+r)/2+1,r); //if the index to be updated is on right call update query on right segment
    else update(s_tree,2*(index),q,val,l,(l+r)/2);            //if the index to be updated is on left call update query on left segment
}


int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    vector<int> s_tree(4*(int)arr.size());
    build_tree(s_tree,arr,1,0,(int)arr.size()-1);
    for(int i=1;s_tree[i]!=0;i++) cout<<s_tree[i]<<" ";
    
    /*                                36
                                    (10+26)
                        10             |             26
                      (7+3)                        (11+15)
                3       |       7      |      11      |        15
              (1+2)           (3+4)          (5+6)            (7+8)
    Arr->   1   |   2   |   3   |   4  |  5    |   6  |     7   |    8

    */
    cout<<"\n"<<sum(s_tree,1,2,4,0,7)<<"\n";
    update(s_tree,1,4,9,0,(int)arr.size()-1);   //increase the value of 4th index(5th element) by 9;
    for(int i=1;s_tree[i]!=0;i++) cout<<s_tree[i]<<" ";
}