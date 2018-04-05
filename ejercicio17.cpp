#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

using namespace std;

class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  Album(int n);
  bool esta_lleno(void);
  int sobrescomprados(); 
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  
  int *album;
  int *repetidas;
  int n_sobres_comprados;
   
};

void Album::Status(void){
  cout << n_en_album << " "<<n_repetidas << endl;
}

void Album::CompraSobre(int n_en_sobre){
  int lamina;
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;
    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
  }
  n_sobres_comprados++;
}
bool Album::esta_lleno(void){
  if(n_total == n_en_album){
    return true;
  }
  else{
    return false;
  }
}
int Album::sobrescomprados(){
  return n_sobres_comprados;
}

Album::Album(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_repetidas = 0;
  n_en_album = 0 ;
  n_sobres_comprados = 0;
  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}


int main(){
  srand(time(0));
  Album A(660);
  while(A.esta_lleno() != true){
    A.CompraSobre(5);
  }
  cout << "El numero de sobres necesarios para llenar el album es " << " " << A.sobrescomprados()<< endl;
}
