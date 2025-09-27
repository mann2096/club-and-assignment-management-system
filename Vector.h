#pragma once
#include<iostream>
using namespace std;

template<typename v>
class Vector{
  private:
  v* arr;
  int current_size;
  int total_size;

  void resize(int new_total_size){
    v* arr2=new v[new_total_size];
    for(int i=0;i<current_size;i++){
      arr2[i]=arr[i];
    }
    delete[] arr;
    arr=arr2;
    total_size=new_total_size;
  }

  public:
  Vector(int size=1){
    total_size=1;
    current_size=0;
    arr=new v[total_size];
  }

  void push_back(v value){
    if(current_size==total_size) resize(total_size*2);
    arr[current_size]=value;
    current_size++;
  }

  void remove(int index){
    if(index<0||index>=current_size){
      cout<<"Element does not exist"<<endl;
    }else{
      for(int i=index+1;i<current_size;i++) arr[i-1]=arr[i];
      current_size--;
    }
  }

  int size()const{
    return current_size;
  }

  v& operator[](int index) const {
    if (index < 0 || index >= current_size) {
        throw out_of_range("Invalid index");
    }
    return arr[index];
}
};
