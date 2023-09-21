#include <stdexcept>

template <typename T, size_t dim> class Array {
    private:
        T* Arr;
        size_t grandeur;
    public:
        Array::Array(){ // non initialisé
            Arr = new T[dim];
            grandeur = dim;
        };

        Array::~Array(){

        }

        Array::Array(T tab[]){ // avec initialisation
            Arr = tab;
        };

        Array::Array(T* tab[]){ // avec initialisation
            Arr = tab;
        };

        Array::Array(const Array& a){
            Arr = new T[a.grandeur];
            grandeur = a.grandeur;
            for (size_t i = 0; i < grandeur; i++)
                Arr[i] = a[i];
        };

        Array::Array(Array&& a){
            Arr = a.Arr;
            a.Arr = nullptr;
            grandeur = a.grandeur;
        };

        size_t size(Array tab){
            return tab.grandeur;
        };  //renvoie le size du tableau envoyé

        bool empty(Array tab){
            if (grandeur == 0)
            {
                return true;
            }
            return false;
        }; //vérifie si le tableau est vide

        //operator[], prend la valeur à [x]
        template <typename T>
        T* Array<T>::operator[](int x){
            return *Arr[x];
        };

        //prend la valeur à (x) avec verification
        T* Array::at(int x){
            if (x >= size)
                throw "size exceded";
            return *Arr[x];
        };

        T* Array::front(Array tab){
            return tab[0];
        };//valeur du premier element

        T* Array::back(Array tab){
            return tab[grandeur - 1];
        };//valeur du dernier element 

        void Array::fill(T value, Array tab){
            for (size_t i = 0; i < size; i++)
            {
                tab[i] = value
            }
        };//met la valeur choisi dans chaque cellules du tableau

        void swap(Array tab1, Array tab2){
            if (tab1.grandeur == tab2.grandeur)
            {
                T *tmp[grandeur] = tab1;
                tab1 = tab2;
                tab2 = tmp;
            }
        };//échange les valeurs des deux tableaux

        Array fusion(Array tab1, Array tab2){
            if (tab1 != tab2)
                throw "not compatible types"
            
            Array tab = new Array<typename T, size_t tab1.grandeur + tab2.grandeur>;

        };//fusionne 2 tableaux

        Array subset(Array entry, int start, int length){

        };//retourne un nouveau tableau avec les valeurs entre start et start + length

        Iterator begin(){
            return Iterator();
        };//retourne un iterateur au début du tableau

        const Iterator cbegin(){
            return Iterator();
        };//retourne un iterateur constant au début du tableau

        Iterator end(Array tab){
            return Iterator();
        };//retourne un iterateur a la fin du tableau

        const Iterator cend(Array tab){
            return Iterator();
        };//retourne un iterateur constant a la fin du tableau

        class Iterator{
        public:
            Iterator::Iterator(/* args */){

            };
            Iterator::~Iterator(){

            };
        };        
};