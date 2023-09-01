#include<iostream>
#include<stack>
using namespace std;
void reversesentence(string s){

stack<string>st;
for(int i=0;i<s.size();i++){

    string word="";
    while(s[i]!=' ' && i<s.size()){
        word.push_back(s[i]);
        i++;
    }
    st.push(word);
}
while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}cout<<endl;
}

int main(){
string s= "Hey how are you doing@";
 reversesentence(s);
 return 0;
}