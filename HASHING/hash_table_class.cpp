#include<iostream>
#include<vector>
#include<unordered_map>
#include<ctime>
#include<cstdlib>
using namespace std;          // your universe...

int samplehash(string& s){
    int hashprime=997;
    int suml=0;
    for(int i=0;i<s.size();i++){
        suml+=int(s[i]);
    }
    return suml%(hashprime);
}
string generateRandomString(int length=10){                                                           // Elegence!!!!
    const char  alphanum[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string result;
    for(int i=0;i<length;++i){
        result+=alphanum[rand() % (sizeof(alphanum)-1)];                       // rand() generates a random function....

    }
    return result;
}
class HashFunctionTester{
    private:
        vector<string> randomStrings;
        int (*hashfunc)(string &);                                  // Function pointer......
    public:
        HashFunctionTester(int (*func)(string& ) , int numStrings= 10): hashfunc(func){            // This is how to pass a function..!!!!!!
           // hashfunc=func;
            for(int i=0;i<numStrings;++i){
                randomStrings.push_back(generateRandomString());
            }
        }
        void testUniformity(){                                            // clever!!!!
            unordered_map<int,int> hashCounts;
        for(int i=0;i<randomStrings.size();i++){
            string s=randomStrings[i];
            int hashValue=hashfunc(s);
            hashCounts[hashValue]++;
        }
        double averagecount=double(randomStrings.size())/double(hashCounts.size());
        cout<<"Average count per bucket is: "<<averagecount<<endl;
        }
};
int main(){
 HashFunctionTester(&samplehash).testUniformity();                           // Passing  of  a function.....
return 0;
}
