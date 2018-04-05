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
  bool laminaesta(int lamina);
  
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  
  int *album;
  int *repetidas;
  int n_sobres_comprados;
   
};
void sepuedecambiarlamina(Album x, Album y, int lamina);


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
bool Album::laminaesta(int lamina){
  if(album[lamina] ==1){
    return true;
  }
  else{
    return false;
  }
}
void sepuedecambiarlamina(Album x, Album y, int lamina){
  bool repetidax = x.laminaesta(lamina);
  bool repetiday = y.laminaesta(lamina);
  if(repetidax == false && repetiday == true){
    cout << "es posible intercambiar lamina" << endl;
  }
  if(repetidax == true && repetiday == false){
    cout << "es posible intercambiar lamina" << endl;
  }
  else{
    cout << "no es posible intercambiar la lamina" << endl; 
  }
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
  Album B(660);
  int lamina = 3;
  while(A.esta_lleno() != true && B.esta_lleno() != true){
    A.CompraSobre(5);
    B.CompraSobre(5);
    sepuedecambiarlamina(A,B,lamina);
    
  }
  cout << "El numero de sobres necesarios para llenar el album es " << " " << A.sobrescomprados()<< endl;
}
