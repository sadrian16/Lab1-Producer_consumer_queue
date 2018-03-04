#include <iostream>
#include <thread>
#include <mutex>
#include <queue>

using namespace std;

mutex mx;
queue<int> coada;
bool finished = false;
int i;

void producator(int n){
    while(!finished){
        mx.lock();
        for(i=0;i<5;i++)
        {
            coada.push(i);
            cout<<"Elementul "<<i<<" Se adauga incoada"<<endl;

        }
        finished=true;
        mx.unlock();
    }
}

void consumator(){
    while(!finished){
        mx.lock();
        while(!coada.empty()){
            cout<<"Se scoate elementul "<<coada.front()<<endl;
            coada.pop();
        }
        finished=true;
        mx.unlock();
        cout<<"Coada este goala"<<endl;
    }
}

int main() {
	thread fir1(producator,5);
	thread fir2(consumator);
	fir1.join();
	fir2.join();
	cout<<"Executia s-a terminat!"<<endl;
}
